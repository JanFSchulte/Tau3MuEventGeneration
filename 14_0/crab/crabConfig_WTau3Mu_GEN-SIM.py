from CRABClient.UserUtilities import config
config = config()

config.General.requestName     = 'WTau3Mu_Pythia8_v2'
config.General.workArea        = 'crab'
config.General.transferOutputs = True
config.General.transferLogs    = False
config.JobType.maxMemoryMB = 3500
config.JobType.pluginName  = 'PrivateMC'
config.JobType.psetName    = 'WTau3Mu_GEN_SIM_cfg.py'
config.Data.splitting   = 'EventBased'
config.Data.unitsPerJob = 25
config.Data.totalUnits  = 200000
config.Data.outLFNDirBase = '/store/user/jschulte/'
config.JobType.outputFiles  = ['WTau3Mu_GEN_SIM.root']
config.Data.publication = True
config.Data.outputPrimaryDataset = 'WTau3Mu_14TeV_Pythia8'
config.Data.outputDatasetTag     = 'Phase2Spring24GS-140X_mcRun4_realistic_v4_v2'
config.JobType.allowUndistributedCMSSW=True
config.section_("Site")
config.Site.storageSite = 'T2_US_Purdue'
# this is needed in order to prevent jobs overflowing to blacklisted sites
config.section_("Debug")
config.Debug.extraJDL = ['+CMS_ALLOW_OVERFLOW=False']
