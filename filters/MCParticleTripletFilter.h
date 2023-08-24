#ifndef MCParticleTripletFilter_h
#define MCParticleTripletFilter_h
// -*- C++ -*-
//
// Package:    MCParticleTripletFilter
// Class:      MCParticleTripletFilter
// 
/* 

 Description: filter events based on the Pythia particle information

 Implementation: inherits from generic EDFilter
     
*/
//
// Original Author:  Fabian Stoeckli
//         Created:  Mon Sept 11 10:57:54 CET 2006
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/global/EDFilter.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"


//
// class decleration
//
namespace edm {
  class HepMCProduct;
}

class MCParticleTripletFilter : public edm::global::EDFilter<> {
   public:
      explicit MCParticleTripletFilter(const edm::ParameterSet&);
      ~MCParticleTripletFilter() override;


      bool filter(edm::StreamID, edm::Event&, const edm::EventSetup&) const override;
   private:
      // ----------memeber function----------------------
       int charge(int Id) const;

      // ----------member data ---------------------------
      
       const edm::EDGetTokenT<edm::HepMCProduct> token_;
       std::vector<int> particleID1;
       std::vector<int> particleID2;
       std::vector<int> particleID3;
       std::vector<double> ptMin;
       std::vector<double> pMin;
       std::vector<double> etaMin;  
       std::vector<double> etaMax;
       std::vector<int> status;
       const double betaBoost;
       
};
#endif
