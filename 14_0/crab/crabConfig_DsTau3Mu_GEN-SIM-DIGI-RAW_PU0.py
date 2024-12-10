from CRABClient.UserUtilities import config
config = config()

config.General.requestName     = 'DsTau3Mu_GEN_SIM_DIGI_RAW_PU0_v2'
config.General.workArea        = 'crab'
config.General.transferOutputs = True
config.General.transferLogs    = False
config.JobType.maxMemoryMB = 5000
config.JobType.pluginName  = 'Analysis'
config.JobType.psetName    = 'XTau3Mu_GEN_SIM_DIGI_RAW_cfg.py'
config.Data.inputDataset = "/DSTau3Mu_14TeV_Pythia8/jschulte-Phase2Spring24GS-140X_mcRun4_realistic_v4_v2-bdd9b85d72d8de2f2845a754a02736df/USER"
config.Data.inputDBS = "phys03"
config.Data.splitting   = 'FileBased'
config.Data.unitsPerJob = 1
config.Data.totalUnits  = 8000
config.Data.ignoreLocality   = True
config.Data.outLFNDirBase = '/store/user/jschulte/'
config.JobType.outputFiles  = ['XTau3Mu_GEN_SIM_DIGI_RAW.root']
#config.JobType.maxJobRuntimeMin = 2880
config.Data.publication = True
config.Data.outputDatasetTag     = 'Phase2Spring24DIGI-noPU_140X_mcRun4_realistic_v4_v2'
config.JobType.allowUndistributedCMSSW=True
config.section_("Site")
config.Site.storageSite = 'T2_US_Purdue'
config.Site.whitelist = ['T2_US_*']
# this is needed in order to prevent jobs overflowing to blacklisted sites
config.section_("Debug")
config.Debug.extraJDL = ['+CMS_ALLOW_OVERFLOW=False']
