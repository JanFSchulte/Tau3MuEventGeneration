
//-ap #include "Configuration/CSA06Skimming/interface/MCParticleTripletFilter.h"

#include "GeneratorInterface/GenFilters/plugins/MCParticleTripletFilter.h"
#include "GeneratorInterface/GenFilters/plugins/MCFilterZboostHelper.h"

#include "SimDataFormats/GeneratorProducts/interface/HepMCProduct.h"
#include <iostream>

using namespace edm;
using namespace std;


MCParticleTripletFilter::MCParticleTripletFilter(const edm::ParameterSet& iConfig) :
token_(consumes<edm::HepMCProduct>(edm::InputTag(iConfig.getUntrackedParameter("moduleLabel",std::string("generator")),"unsmeared"))),
betaBoost(iConfig.getUntrackedParameter("BetaBoost",0.))
{
   //here do whatever other initialization is needed
   vector<int> defpid1;
   defpid1.push_back(0);
   particleID1 = iConfig.getUntrackedParameter< vector<int> >("ParticleID1",defpid1);
   vector<int> defpid2;
   defpid2.push_back(0);
   particleID2 = iConfig.getUntrackedParameter< vector<int> >("ParticleID2",defpid2);
   vector<int> defpid3;
   defpid3.push_back(0);
   particleID3 = iConfig.getUntrackedParameter< vector<int> >("ParticleID3",defpid2);
   vector<double> defptmin;   
   defptmin.push_back(0.);
   ptMin = iConfig.getUntrackedParameter< vector<double> >("MinPt", defptmin);
   vector<double> defpmin;
   defpmin.push_back(0.);
   pMin = iConfig.getUntrackedParameter< vector<double> >("MinP", defpmin);

   vector<double> defetamin;
   defetamin.push_back(-10.);
   etaMin = iConfig.getUntrackedParameter< vector<double> >("MinEta", defetamin);
   vector<double> defetamax ;
   defetamax.push_back(10.);
   etaMax = iConfig.getUntrackedParameter< vector<double> >("MaxEta", defetamax);
   vector<int> defstat ;
   defstat.push_back(0);
   status = iConfig.getUntrackedParameter< vector<int> >("Status", defstat);
   
   
    // check for correct size
    if (ptMin.size() != 3
	|| pMin.size() != 3
	|| etaMin.size() != 3 
	|| etaMax.size() != 3 
	|| status.size() != 3 ) {
      cout << "WARNING: MCParticleTripletFilter : size of some vectors not matching with 3!!" << endl;
    }
    
    // if ptMin size smaller than 2, fill up further with defaults
    if (3 > ptMin.size() ){
       vector<double> defptmin2 ;
       for (unsigned int i = 0; i < 3; i++){ defptmin2.push_back(0.);}
       ptMin = defptmin2;   
    } 
    // if pMin size smaller than 2, fill up further with defaults
    if (3 > pMin.size() ){
       vector<double> defpmin2 ;
       for (unsigned int i = 0; i < 3; i++){ defpmin2.push_back(0.);}
       pMin = defpmin2;
    }
    // if etaMin size smaller than 2, fill up further with defaults
    if (3 > etaMin.size() ){
       vector<double> defetamin2 ;
       for (unsigned int i = 0; i < 3; i++){ defetamin2.push_back(-10.);}
       etaMin = defetamin2;   
    } 
    // if etaMax size smaller than 2, fill up further with defaults
    if (3 > etaMax.size() ){
       vector<double> defetamax2 ;
       for (unsigned int i = 0; i < 3; i++){ defetamax2.push_back(10.);}
       etaMax = defetamax2;   
    }     
    // if status size smaller than 2, fill up further with defaults
    if (3 > status.size() ){
       vector<int> defstat2 ;
       for (unsigned int i = 0; i < 3; i++){ defstat2.push_back(0);}
       status = defstat2;   
    } 

}


MCParticleTripletFilter::~MCParticleTripletFilter()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


// ------------ method called to skim the data  ------------
bool MCParticleTripletFilter::filter(edm::StreamID, edm::Event& iEvent, const edm::EventSetup& iSetup) const
{
   using namespace edm;
   Handle<HepMCProduct> evt;
   iEvent.getByToken(token_, evt);

   const HepMC::GenEvent * myGenEvent = evt->GetEvent();
   for(unsigned int j=0; j<particleID1.size(); ++j) {
	std::cout << particleID1[j] << std::endl;
   }
    for(unsigned int j=0; j<particleID2.size(); ++j) {
	std::cout << particleID2[j] << std::endl;
   }
   for(unsigned int j=0; j<particleID3.size(); ++j) {
	std::cout << particleID3[j] << std::endl;
   }

   for (int i = 0; i < 3; i++){
	std::cout << ptMin[i] << " " << pMin[i] << " " << etaMin[i] << " " << etaMax[i] << " " <<  status[i] << std::endl;
   }
  
   int nPass1 = 0; 
   int nPass2 = 0; 
   int nPass3 = 0; 
   for ( HepMC::GenEvent::particle_const_iterator p = myGenEvent->particles_begin();
	 p != myGenEvent->particles_end(); ++p ) {
     
     // check for type A conditions
     bool gottypeAID = false;
     for(unsigned int j=0; j<particleID1.size(); ++j) {
       if(abs((*p)->pdg_id()) == abs(particleID1[j]) || particleID1[j] == 0) {
	 gottypeAID = true;
	 break;
       }
     }
     if(gottypeAID) {
       HepMC::FourVector mom = MCFilterZboostHelper::zboost((*p)->momentum(),betaBoost);
  //     std::cout << "--------------------------------" << std::endl;
  //     std::cout << mom.perp() << std::endl;
  //     std::cout << mom.rho() << std::endl;
  //     std::cout << mom.eta() << std::endl;
       if ( mom.perp() > ptMin[0] && mom.rho() > pMin[0] && mom.eta() > etaMin[0] 
	    && mom.eta() < etaMax[0] && ((*p)->status() == status[0] || status[0] == 0)) {
            nPass1++;
       }
     }
     
     // check for type B conditions
     
     bool gottypeBID = false;
     for(unsigned int j=0; j<particleID2.size(); ++j) {
       if(abs((*p)->pdg_id()) == abs(particleID2[j]) || particleID2[j] == 0) {
	 gottypeBID = true;
	 break;
       }
     }
     if(gottypeBID) {
       HepMC::FourVector mom = MCFilterZboostHelper::zboost((*p)->momentum(),betaBoost);
       if ( mom.perp() > ptMin[1] && mom.rho() > pMin[1] && mom.eta() > etaMin[1] 
	    && mom.eta() < etaMax[1] && ((*p)->status() == status[1] || status[1] == 0)) { 
	    nPass2++;
     }
   }
      // check for type C conditions
     
     bool gottypeCID = false;
     for(unsigned int j=0; j<particleID3.size(); ++j) {
       if(abs((*p)->pdg_id()) == abs(particleID3[j]) || particleID3[j] == 0) {
	 gottypeCID = true;
	 break;
       }
     }
     if(gottypeCID) {
       HepMC::FourVector mom = MCFilterZboostHelper::zboost((*p)->momentum(),betaBoost);
       if ( mom.perp() > ptMin[2] && mom.rho() > pMin[2] && mom.eta() > etaMin[2] 
	    && mom.eta() < etaMax[2] && ((*p)->status() == status[2] || status[2] == 0)) { 
	    nPass3++;
     }
   }
 }
 bool pass = (nPass1 > 0) && (nPass2 > 1) && (nPass3 > 2);
 return pass;
    
}

int MCParticleTripletFilter::charge(int Id) const {

  
  //...Purpose: to give three times the charge for a particle/parton.

  //      ID     = particle ID
  //      hepchg = particle charge times 3

  int kqa,kq1,kq2,kq3,kqj,irt,kqx,kqn;
  int hepchg;


  constexpr const int ichg[109]={-1,2,-1,2,-1,2,-1,2,0,0,-3,0,-3,0,-3,0,
-3,0,0,0,0,0,0,3,0,0,0,0,0,0,3,0,3,6,0,0,3,6,0,0,-1,2,-1,2,-1,2,0,0,0,0,
-3,0,-3,0,-3,0,0,0,0,0,-1,2,-1,2,-1,2,0,0,0,0,
-3,0,-3,0,-3,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


  //...Initial values. Simple case of direct readout.
  hepchg=0;
  kqa=abs(Id);
  kqn=kqa/1000000000%10;
  kqx=kqa/1000000%10;
  kq3=kqa/1000%10;
  kq2=kqa/100%10;
  kq1=kqa/10%10;
  kqj=kqa%10;
  irt=kqa%10000;

  //...illegal or ion
  //...set ion charge to zero - not enough information
  if(kqa==0 || kqa >= 10000000) {

    if(kqn==1) {hepchg=0;}
  }
  //... direct translation
  else if(kqa<=100) {hepchg = ichg[kqa-1];}
  //... KS and KL (and undefined)
  else if(kqj == 0) {hepchg = 0;}
  //C... direct translation
  else if(kqx>0 && irt<100)
    {
      hepchg = ichg[irt-1];
      if(kqa==1000017 || kqa==1000018) {hepchg = 0;}
      if(kqa==1000034 || kqa==1000052) {hepchg = 0;}
      if(kqa==1000053 || kqa==1000054) {hepchg = 0;}
      if(kqa==5100061 || kqa==5100062) {hepchg = 6;}
    }
  //...Construction from quark content for heavy meson, diquark, baryon.
  //...Mesons.
  else if(kq3==0)
    {
      hepchg = ichg[kq2-1]-ichg[kq1-1];
      //...Strange or beauty mesons.
      if((kq2==3) || (kq2==5)) {hepchg = ichg[kq1-1]-ichg[kq2-1];}
    }
  else if(kq1 == 0) {
    //...Diquarks.
    hepchg = ichg[kq3-1] + ichg[kq2-1];
  }

  else{
    //...Baryons
    hepchg = ichg[kq3-1]+ichg[kq2-1]+ichg[kq1-1];
  }

  //... fix sign of charge
  if(Id<0 && hepchg!=0) {hepchg = -1*hepchg;}

  // cout << hepchg<< endl;
  return hepchg;
}
