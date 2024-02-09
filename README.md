# Tau3MuEventGeneration
Tools for event generation for the Tau3Mu GNN development

##Instructions for 10_4_X (PU200):

Production in 10_4_X, matching currently used samples (as of August 2022) need to be performed in two separate releases for the GEN-SIM and DIGI steps

for GEN-SIM:

```
git clone https://github.com/JanFSchulte/Tau3MuEventGeneration
cmsrel CMSSW_10_4_0_mtd1
cd CMSSW_10_4_0_mtd1/src
cp ../../Tau3MuEventGeneration/10_4/DsTau3Mu_GEN-SIM_cfg.py .
cmsRun DsTau3Mu_GEN-SIM_cfg.py
```

for DIGI:

```
git clone https://github.com/JanFSchulte/Tau3MuEventGeneration
cmsrel CMSSW_10_4_0_mtd5
cd CMSSW_10_4_0_mtd5/src
cp ../../Tau3MuEventGeneration/10_4/DsTau3Mu-GEN-SIM-DIGI-RAW_cfg.py .
cmsRun DsTau3Mu-GEN-SIM-DIGI-RAW_cfg.py
```

##Instructions for 12_3_X (PU200):

Production in 12_3_6, matching Phase-II development samples as of August 2022 (OUTDATED)

```
git clone https://github.com/JanFSchulte/Tau3MuEventGeneration
cmsrel CMSSW_12_3_6
cd CMSSW_12_3_6/src
cp ../../Tau3MuEventGeneration/12_3/DsTau3Mu_GEN-SIM_cfg.py .
cp ../../Tau3MuEventGeneration/12_3/DsTau3Mu-GEN-SIM-DIGI-RAW_cfg.py .
cmsRun DsTau3Mu_GEN-SIM_cfg.py
cmsRun DsTau3Mu-GEN-SIM-DIGI-RAW_cfg.py

```

##Instructions for 12_5_2_patch1 (PU0 or PU200):

Production in 12_5_2_patch1, matching latest Phase-II development samples. GEN-SIM and DIGI-RAW steps have to be run separately unfortunately.

```
git clone https://github.com/JanFSchulte/Tau3MuEventGeneration
cmsrel CMSSW_12_5_2_patch1
cd CMSSW_12_5_2_patch1/src
git cms-addpkg GeneratorInterface/GenFilters
cp ../../Tau3MuEventGeneration/filters/* GeneratorInterface/GenFilters/plugins
scram b -j 8
cp ../../Tau3MuEventGeneration/12_5/DsTau3Mu_GEN-SIM_PU0_cfg.py .
cmsRun DsTau3Mu_GEN-SIM_PU0_cfg.py
#for PU 0
cp ../../Tau3MuEventGeneration/12_5/DsTau3Mu_GEN-SIM-DIGI-RAW_PU0_cfg.py .
cmsRun DsTau3Mu_GEN-SIM-DIGI-RAW_PU0_cfg.py
#for PU 200
cp ../../Tau3MuEventGeneration/12_5/DsTau3Mu_GEN-SIM-DIGI-RAW_PU200_cfg.py .
cmsRun DsTau3Mu_GEN-SIM-DIGI-RAW_PU200_cfg.py

```
##Instructions for 13_3_0_patch3 (PU0 or PU200):

Production in 13_3_0_patch3, matching Osvaldo's development setup for the EMTF emulator. GEN-SIM and DIGI-RAW steps have to be run separately unfortunately.

```
git clone https://github.com/JanFSchulte/Tau3MuEventGeneration
cmsrel CMSSW_13_3_0_patch3
cd CMSSW_13_3_0_patch3/src
git cms-addpkg GeneratorInterface/GenFilters
cp ../../Tau3MuEventGeneration/models/data L1Trigger/L1TMuonEndCapPhase2/
cp -r  ../../
scram b -j 8
cp ../../Tau3MuEventGeneration/13_3/DsTau3Mu_GEN-SIM_PU0_cfg.py .
cmsRun DsTau3Mu_GEN-SIM_PU0_cfg.py
#for PU 0
cp ../../Tau3MuEventGeneration/13_3/DsTau3Mu_GEN-SIM-DIGI-RAW_PU0_cfg.py .
cmsRun DsTau3Mu_GEN-SIM-DIGI-RAW_PU0_cfg.py
#for PU 200
cp ../../Tau3MuEventGeneration/13_3/DsTau3Mu_GEN-SIM-DIGI-RAW_PU200_cfg.py .
cmsRun DsTau3Mu_GEN-SIM-DIGI-RAW_PU200_cfg.py

```


##MC sample production via CRAB:

To produce the ntuples used for GNN training, GEN-SIM-DIGI-RAW datatier is needed

CRAB configs can be found in the CRAB subfolder and can be adjusted for the production at hand 

## Note on Generator filter and  PU settings:

Gnerator cuts on the muons can be changed by adjusting the filter configuraton in the lines

```
process.MuFilter = cms.EDFilter("MCParticlePairFilter",
    MaxEta = cms.untracked.vdouble(3.0, 3.0),
    MinEta = cms.untracked.vdouble(-3.0, -3.0),
    MinP = cms.untracked.vdouble(0, 0),
    ParticleID1 = cms.untracked.vint32(13),
    ParticleID2 = cms.untracked.vint32(13)
)
```
in the GEN-SIM configs

Pileup is added in the DIGI step and is diced according to the Poisson distributuon. The mean of the PU distribution can be changed by adjusting the line

`process.mix.input.nbPileupEvents.averageNumber = cms.double(200.000000)`

in DsTau3Mu-GEN-SIM-DIGI-RAW_cfg.py
