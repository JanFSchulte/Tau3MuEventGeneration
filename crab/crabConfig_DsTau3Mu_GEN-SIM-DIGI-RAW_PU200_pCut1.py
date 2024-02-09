from CRABClient.UserUtilities import config
config = config()

config.General.requestName     = 'DsTau3Mu_GEN-SIM-DIGI-RAW_PU200'
config.General.workArea        = 'crab'
config.General.transferOutputs = True
config.General.transferLogs    = False
config.JobType.maxMemoryMB = 5000
config.JobType.pluginName  = 'Analysis'
config.JobType.psetName    = 'DsTau3Mu_GEN-SIM-DIGI-RAW_PU200_PUValid_cfg.py'
config.Data.inputDataset = "/DSTau3Mu_pCut1_14TeV_Pythia8/jschulte-Phase2Fall22DRMiniAOD-PU200_125X_mcRun4_realistic_v2_GEN-SIM-DIG-v2-ce62614374ba660ed86316621fc04690/USER"
config.Data.inputDBS = "phys03"
config.Data.splitting   = 'FileBased'
config.Data.unitsPerJob = 1
config.Data.totalUnits  = 8000
config.Data.ignoreLocality   = True
config.Data.outLFNDirBase = '/store/user/jschulte/'
config.JobType.outputFiles  = ['DsTau3Mu-GEN-SIM-DIGI-RAW_PUValid.root']
#config.JobType.maxJobRuntimeMin = 2880
config.Data.publication = True
config.Data.outputDatasetTag     = 'Phase2Fall22DRMiniAOD-PU200_125X_mcRun4_realistic_v2_GEN-SIM-DIGI-RAW-v2'
config.JobType.allowUndistributedCMSSW=True
config.section_("Site")
config.Site.storageSite = 'T2_US_Purdue'
config.Site.whitelist = ['T2_US_*']
# this is needed in order to prevent jobs overflowing to blacklisted sites
config.section_("Debug")
config.Debug.extraJDL = ['+CMS_ALLOW_OVERFLOW=False']
