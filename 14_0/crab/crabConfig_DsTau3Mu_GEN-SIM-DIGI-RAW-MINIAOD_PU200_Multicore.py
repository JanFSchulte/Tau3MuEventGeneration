from CRABClient.UserUtilities import config
config = config()

config.General.requestName     = 'DsTau3Mu_GEN_SIM_DIGI_RAW_MINIAOD_PU200_v3'
config.General.workArea        = 'crab'
config.General.transferOutputs = True
config.General.transferLogs    = False
config.JobType.maxMemoryMB = 7500
config.JobType.numCores = 4
config.JobType.pluginName  = 'Analysis'
config.JobType.psetName    = 'XTau3Mu_GEN_SIM_DIGI_RAW_MINIAOD_Multicore_cfg.py'
config.Data.inputDataset = "/DSTau3Mu_14TeV_Pythia8/jschulte-Phase2Spring24DIGI-PU200_140X_mcRun4_realistic_v4_v3-1a788cd8a86e543c96b68a3e23c99965/USER"
config.Data.inputDBS = "phys03"
config.Data.splitting   = 'FileBased'
config.Data.unitsPerJob = 1
config.Data.totalUnits  = 8000
config.Data.ignoreLocality   = True
config.Data.outLFNDirBase = '/store/user/jschulte/'
config.JobType.outputFiles  = ['XTau3Mu_GEN_SIM_DIGI_RAW_MINIAOD.root']
#config.JobType.maxJobRuntimeMin = 2880
config.Data.publication = True
config.Data.outputDatasetTag     = 'Phase2Spring24DIGIRECOMiniAOD-PU200_140X_mcRun4_realistic_v4_v3'
config.JobType.allowUndistributedCMSSW=True
config.section_("Site")
config.Site.storageSite = 'T2_US_Purdue'
config.Site.whitelist = ['T2_US_*']
# this is needed in order to prevent jobs overflowing to blacklisted sites
config.section_("Debug")
config.Debug.extraJDL = ['+CMS_ALLOW_OVERFLOW=False']
