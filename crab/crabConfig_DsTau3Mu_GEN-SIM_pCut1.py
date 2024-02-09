from CRABClient.UserUtilities import config
config = config()

config.General.requestName     = 'DSTau3Mu_pCut1_Pythia8_part1'
config.General.workArea        = 'crab'
config.General.transferOutputs = True
config.General.transferLogs    = False
config.JobType.maxMemoryMB = 3500
config.JobType.pluginName  = 'PrivateMC'
config.JobType.psetName    = 'DsTau3Mu_GEN-SIM_PU0_cfg.py'
config.Data.splitting   = 'EventBased'
config.Data.unitsPerJob = 25000
config.Data.totalUnits  = 200000000
config.Data.outLFNDirBase = '/store/user/jschulte/'
config.JobType.outputFiles  = ['DsTau3Mu-GEN-SIM.root']
config.Data.publication = True
config.Data.outputPrimaryDataset = 'DSTau3Mu_pCut1_14TeV_Pythia8'
config.Data.outputDatasetTag     = 'Phase2Fall22DRMiniAOD_125X_mcRun4_realistic_v2_GEN-SIM-v2'
config.JobType.allowUndistributedCMSSW=True
config.section_("Site")
config.Site.storageSite = 'T2_US_Purdue'
# this is needed in order to prevent jobs overflowing to blacklisted sites
config.section_("Debug")
config.Debug.extraJDL = ['+CMS_ALLOW_OVERFLOW=False']
