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

Production in 12_3_6, matching latest Phase-II development samples (as of August 2022), needed for HLT studies within CMSSW

```
git clone https://github.com/JanFSchulte/Tau3MuEventGeneration
cmsrel CMSSW_12_3_6
cd CMSSW_12_3_6/src
cp ../../Tau3MuEventGeneration/12_3/DsTau3Mu_GEN-SIM_cfg.py .
cp ../../Tau3MuEventGeneration/12_3/DsTau3Mu-GEN-SIM-DIGI-RAW_cfg.py .
cmsRun DsTau3Mu_GEN-SIM_cfg.py
cmsRun DsTau3Mu-GEN-SIM-DIGI-RAW_cfg.py

```

## Note on Generator filter and  PU settings

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
