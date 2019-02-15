#include "syscallswow64.gen.hpp"

#define FDP_MODULE "syscallswow64"
#include "log.hpp"
#include "monitor.hpp"

namespace
{
	constexpr bool g_debug = false;
}

struct monitor::syscallswow64::Data
{
    Data(core::Core& core, std::string module);

    using Breakpoints = std::vector<core::Breakpoint>;
    core::Core& core;
    std::string module;
    Breakpoints breakpoints;

    std::vector<on_NtAcceptConnectPort_fn>                                observers_NtAcceptConnectPort;
    std::vector<on_ZwAccessCheckAndAuditAlarm_fn>                         observers_ZwAccessCheckAndAuditAlarm;
    std::vector<on_NtAccessCheckByTypeAndAuditAlarm_fn>                   observers_NtAccessCheckByTypeAndAuditAlarm;
    std::vector<on_NtAccessCheckByType_fn>                                observers_NtAccessCheckByType;
    std::vector<on_ZwAccessCheckByTypeResultListAndAuditAlarmByHandle_fn> observers_ZwAccessCheckByTypeResultListAndAuditAlarmByHandle;
    std::vector<on_NtAccessCheckByTypeResultListAndAuditAlarm_fn>         observers_NtAccessCheckByTypeResultListAndAuditAlarm;
    std::vector<on_NtAccessCheckByTypeResultList_fn>                      observers_NtAccessCheckByTypeResultList;
    std::vector<on_NtAccessCheck_fn>                                      observers_NtAccessCheck;
    std::vector<on_NtAddAtom_fn>                                          observers_NtAddAtom;
    std::vector<on_ZwAddBootEntry_fn>                                     observers_ZwAddBootEntry;
    std::vector<on_NtAddDriverEntry_fn>                                   observers_NtAddDriverEntry;
    std::vector<on_ZwAdjustGroupsToken_fn>                                observers_ZwAdjustGroupsToken;
    std::vector<on_ZwAdjustPrivilegesToken_fn>                            observers_ZwAdjustPrivilegesToken;
    std::vector<on_NtAlertResumeThread_fn>                                observers_NtAlertResumeThread;
    std::vector<on_NtAlertThread_fn>                                      observers_NtAlertThread;
    std::vector<on_ZwAllocateLocallyUniqueId_fn>                          observers_ZwAllocateLocallyUniqueId;
    std::vector<on_NtAllocateReserveObject_fn>                            observers_NtAllocateReserveObject;
    std::vector<on_NtAllocateUserPhysicalPages_fn>                        observers_NtAllocateUserPhysicalPages;
    std::vector<on_NtAllocateUuids_fn>                                    observers_NtAllocateUuids;
    std::vector<on_NtAllocateVirtualMemory_fn>                            observers_NtAllocateVirtualMemory;
    std::vector<on_NtAlpcAcceptConnectPort_fn>                            observers_NtAlpcAcceptConnectPort;
    std::vector<on_ZwAlpcCancelMessage_fn>                                observers_ZwAlpcCancelMessage;
    std::vector<on_ZwAlpcConnectPort_fn>                                  observers_ZwAlpcConnectPort;
    std::vector<on_ZwAlpcCreatePort_fn>                                   observers_ZwAlpcCreatePort;
    std::vector<on_NtAlpcCreatePortSection_fn>                            observers_NtAlpcCreatePortSection;
    std::vector<on_ZwAlpcCreateResourceReserve_fn>                        observers_ZwAlpcCreateResourceReserve;
    std::vector<on_ZwAlpcCreateSectionView_fn>                            observers_ZwAlpcCreateSectionView;
    std::vector<on_ZwAlpcCreateSecurityContext_fn>                        observers_ZwAlpcCreateSecurityContext;
    std::vector<on_ZwAlpcDeletePortSection_fn>                            observers_ZwAlpcDeletePortSection;
    std::vector<on_NtAlpcDeleteResourceReserve_fn>                        observers_NtAlpcDeleteResourceReserve;
    std::vector<on_NtAlpcDeleteSectionView_fn>                            observers_NtAlpcDeleteSectionView;
    std::vector<on_NtAlpcDeleteSecurityContext_fn>                        observers_NtAlpcDeleteSecurityContext;
    std::vector<on_NtAlpcDisconnectPort_fn>                               observers_NtAlpcDisconnectPort;
    std::vector<on_ZwAlpcImpersonateClientOfPort_fn>                      observers_ZwAlpcImpersonateClientOfPort;
    std::vector<on_ZwAlpcOpenSenderProcess_fn>                            observers_ZwAlpcOpenSenderProcess;
    std::vector<on_ZwAlpcOpenSenderThread_fn>                             observers_ZwAlpcOpenSenderThread;
    std::vector<on_ZwAlpcQueryInformation_fn>                             observers_ZwAlpcQueryInformation;
    std::vector<on_ZwAlpcQueryInformationMessage_fn>                      observers_ZwAlpcQueryInformationMessage;
    std::vector<on_NtAlpcRevokeSecurityContext_fn>                        observers_NtAlpcRevokeSecurityContext;
    std::vector<on_NtAlpcSendWaitReceivePort_fn>                          observers_NtAlpcSendWaitReceivePort;
    std::vector<on_NtAlpcSetInformation_fn>                               observers_NtAlpcSetInformation;
    std::vector<on_NtApphelpCacheControl_fn>                              observers_NtApphelpCacheControl;
    std::vector<on_ZwAreMappedFilesTheSame_fn>                            observers_ZwAreMappedFilesTheSame;
    std::vector<on_ZwAssignProcessToJobObject_fn>                         observers_ZwAssignProcessToJobObject;
    std::vector<on_ZwCallbackReturn_fn>                                   observers_ZwCallbackReturn;
    std::vector<on_NtCancelIoFileEx_fn>                                   observers_NtCancelIoFileEx;
    std::vector<on_ZwCancelIoFile_fn>                                     observers_ZwCancelIoFile;
    std::vector<on_NtCancelSynchronousIoFile_fn>                          observers_NtCancelSynchronousIoFile;
    std::vector<on_ZwCancelTimer_fn>                                      observers_ZwCancelTimer;
    std::vector<on_NtClearEvent_fn>                                       observers_NtClearEvent;
    std::vector<on_NtClose_fn>                                            observers_NtClose;
    std::vector<on_ZwCloseObjectAuditAlarm_fn>                            observers_ZwCloseObjectAuditAlarm;
    std::vector<on_ZwCommitComplete_fn>                                   observers_ZwCommitComplete;
    std::vector<on_NtCommitEnlistment_fn>                                 observers_NtCommitEnlistment;
    std::vector<on_NtCommitTransaction_fn>                                observers_NtCommitTransaction;
    std::vector<on_NtCompactKeys_fn>                                      observers_NtCompactKeys;
    std::vector<on_ZwCompareTokens_fn>                                    observers_ZwCompareTokens;
    std::vector<on_NtCompleteConnectPort_fn>                              observers_NtCompleteConnectPort;
    std::vector<on_ZwCompressKey_fn>                                      observers_ZwCompressKey;
    std::vector<on_NtConnectPort_fn>                                      observers_NtConnectPort;
    std::vector<on_ZwContinue_fn>                                         observers_ZwContinue;
    std::vector<on_ZwCreateDebugObject_fn>                                observers_ZwCreateDebugObject;
    std::vector<on_ZwCreateDirectoryObject_fn>                            observers_ZwCreateDirectoryObject;
    std::vector<on_ZwCreateEnlistment_fn>                                 observers_ZwCreateEnlistment;
    std::vector<on_NtCreateEvent_fn>                                      observers_NtCreateEvent;
    std::vector<on_NtCreateEventPair_fn>                                  observers_NtCreateEventPair;
    std::vector<on_NtCreateFile_fn>                                       observers_NtCreateFile;
    std::vector<on_NtCreateIoCompletion_fn>                               observers_NtCreateIoCompletion;
    std::vector<on_ZwCreateJobObject_fn>                                  observers_ZwCreateJobObject;
    std::vector<on_NtCreateJobSet_fn>                                     observers_NtCreateJobSet;
    std::vector<on_ZwCreateKeyedEvent_fn>                                 observers_ZwCreateKeyedEvent;
    std::vector<on_ZwCreateKey_fn>                                        observers_ZwCreateKey;
    std::vector<on_NtCreateKeyTransacted_fn>                              observers_NtCreateKeyTransacted;
    std::vector<on_ZwCreateMailslotFile_fn>                               observers_ZwCreateMailslotFile;
    std::vector<on_ZwCreateMutant_fn>                                     observers_ZwCreateMutant;
    std::vector<on_ZwCreateNamedPipeFile_fn>                              observers_ZwCreateNamedPipeFile;
    std::vector<on_NtCreatePagingFile_fn>                                 observers_NtCreatePagingFile;
    std::vector<on_ZwCreatePort_fn>                                       observers_ZwCreatePort;
    std::vector<on_NtCreatePrivateNamespace_fn>                           observers_NtCreatePrivateNamespace;
    std::vector<on_ZwCreateProcessEx_fn>                                  observers_ZwCreateProcessEx;
    std::vector<on_ZwCreateProcess_fn>                                    observers_ZwCreateProcess;
    std::vector<on_NtCreateProfileEx_fn>                                  observers_NtCreateProfileEx;
    std::vector<on_ZwCreateProfile_fn>                                    observers_ZwCreateProfile;
    std::vector<on_ZwCreateResourceManager_fn>                            observers_ZwCreateResourceManager;
    std::vector<on_NtCreateSection_fn>                                    observers_NtCreateSection;
    std::vector<on_NtCreateSemaphore_fn>                                  observers_NtCreateSemaphore;
    std::vector<on_ZwCreateSymbolicLinkObject_fn>                         observers_ZwCreateSymbolicLinkObject;
    std::vector<on_NtCreateThreadEx_fn>                                   observers_NtCreateThreadEx;
    std::vector<on_NtCreateThread_fn>                                     observers_NtCreateThread;
    std::vector<on_ZwCreateTimer_fn>                                      observers_ZwCreateTimer;
    std::vector<on_NtCreateToken_fn>                                      observers_NtCreateToken;
    std::vector<on_ZwCreateTransactionManager_fn>                         observers_ZwCreateTransactionManager;
    std::vector<on_NtCreateTransaction_fn>                                observers_NtCreateTransaction;
    std::vector<on_NtCreateUserProcess_fn>                                observers_NtCreateUserProcess;
    std::vector<on_ZwCreateWaitablePort_fn>                               observers_ZwCreateWaitablePort;
    std::vector<on_NtCreateWorkerFactory_fn>                              observers_NtCreateWorkerFactory;
    std::vector<on_NtDebugActiveProcess_fn>                               observers_NtDebugActiveProcess;
    std::vector<on_ZwDebugContinue_fn>                                    observers_ZwDebugContinue;
    std::vector<on_ZwDelayExecution_fn>                                   observers_ZwDelayExecution;
    std::vector<on_ZwDeleteAtom_fn>                                       observers_ZwDeleteAtom;
    std::vector<on_NtDeleteBootEntry_fn>                                  observers_NtDeleteBootEntry;
    std::vector<on_ZwDeleteDriverEntry_fn>                                observers_ZwDeleteDriverEntry;
    std::vector<on_NtDeleteFile_fn>                                       observers_NtDeleteFile;
    std::vector<on_ZwDeleteKey_fn>                                        observers_ZwDeleteKey;
    std::vector<on_NtDeleteObjectAuditAlarm_fn>                           observers_NtDeleteObjectAuditAlarm;
    std::vector<on_NtDeletePrivateNamespace_fn>                           observers_NtDeletePrivateNamespace;
    std::vector<on_NtDeleteValueKey_fn>                                   observers_NtDeleteValueKey;
    std::vector<on_ZwDeviceIoControlFile_fn>                              observers_ZwDeviceIoControlFile;
    std::vector<on_NtDisplayString_fn>                                    observers_NtDisplayString;
    std::vector<on_ZwDrawText_fn>                                         observers_ZwDrawText;
    std::vector<on_ZwDuplicateObject_fn>                                  observers_ZwDuplicateObject;
    std::vector<on_NtDuplicateToken_fn>                                   observers_NtDuplicateToken;
    std::vector<on_ZwEnumerateBootEntries_fn>                             observers_ZwEnumerateBootEntries;
    std::vector<on_NtEnumerateDriverEntries_fn>                           observers_NtEnumerateDriverEntries;
    std::vector<on_ZwEnumerateKey_fn>                                     observers_ZwEnumerateKey;
    std::vector<on_ZwEnumerateSystemEnvironmentValuesEx_fn>               observers_ZwEnumerateSystemEnvironmentValuesEx;
    std::vector<on_ZwEnumerateTransactionObject_fn>                       observers_ZwEnumerateTransactionObject;
    std::vector<on_NtEnumerateValueKey_fn>                                observers_NtEnumerateValueKey;
    std::vector<on_ZwExtendSection_fn>                                    observers_ZwExtendSection;
    std::vector<on_NtFilterToken_fn>                                      observers_NtFilterToken;
    std::vector<on_NtFindAtom_fn>                                         observers_NtFindAtom;
    std::vector<on_ZwFlushBuffersFile_fn>                                 observers_ZwFlushBuffersFile;
    std::vector<on_ZwFlushInstallUILanguage_fn>                           observers_ZwFlushInstallUILanguage;
    std::vector<on_ZwFlushInstructionCache_fn>                            observers_ZwFlushInstructionCache;
    std::vector<on_NtFlushKey_fn>                                         observers_NtFlushKey;
    std::vector<on_ZwFlushVirtualMemory_fn>                               observers_ZwFlushVirtualMemory;
    std::vector<on_NtFreeUserPhysicalPages_fn>                            observers_NtFreeUserPhysicalPages;
    std::vector<on_NtFreeVirtualMemory_fn>                                observers_NtFreeVirtualMemory;
    std::vector<on_NtFreezeRegistry_fn>                                   observers_NtFreezeRegistry;
    std::vector<on_ZwFreezeTransactions_fn>                               observers_ZwFreezeTransactions;
    std::vector<on_NtFsControlFile_fn>                                    observers_NtFsControlFile;
    std::vector<on_NtGetContextThread_fn>                                 observers_NtGetContextThread;
    std::vector<on_NtGetDevicePowerState_fn>                              observers_NtGetDevicePowerState;
    std::vector<on_NtGetMUIRegistryInfo_fn>                               observers_NtGetMUIRegistryInfo;
    std::vector<on_ZwGetNextProcess_fn>                                   observers_ZwGetNextProcess;
    std::vector<on_ZwGetNextThread_fn>                                    observers_ZwGetNextThread;
    std::vector<on_NtGetNlsSectionPtr_fn>                                 observers_NtGetNlsSectionPtr;
    std::vector<on_ZwGetNotificationResourceManager_fn>                   observers_ZwGetNotificationResourceManager;
    std::vector<on_NtGetWriteWatch_fn>                                    observers_NtGetWriteWatch;
    std::vector<on_NtImpersonateAnonymousToken_fn>                        observers_NtImpersonateAnonymousToken;
    std::vector<on_ZwImpersonateClientOfPort_fn>                          observers_ZwImpersonateClientOfPort;
    std::vector<on_ZwImpersonateThread_fn>                                observers_ZwImpersonateThread;
    std::vector<on_NtInitializeNlsFiles_fn>                               observers_NtInitializeNlsFiles;
    std::vector<on_ZwInitializeRegistry_fn>                               observers_ZwInitializeRegistry;
    std::vector<on_NtInitiatePowerAction_fn>                              observers_NtInitiatePowerAction;
    std::vector<on_ZwIsProcessInJob_fn>                                   observers_ZwIsProcessInJob;
    std::vector<on_ZwListenPort_fn>                                       observers_ZwListenPort;
    std::vector<on_NtLoadDriver_fn>                                       observers_NtLoadDriver;
    std::vector<on_NtLoadKey2_fn>                                         observers_NtLoadKey2;
    std::vector<on_NtLoadKeyEx_fn>                                        observers_NtLoadKeyEx;
    std::vector<on_NtLoadKey_fn>                                          observers_NtLoadKey;
    std::vector<on_NtLockFile_fn>                                         observers_NtLockFile;
    std::vector<on_ZwLockProductActivationKeys_fn>                        observers_ZwLockProductActivationKeys;
    std::vector<on_NtLockRegistryKey_fn>                                  observers_NtLockRegistryKey;
    std::vector<on_ZwLockVirtualMemory_fn>                                observers_ZwLockVirtualMemory;
    std::vector<on_ZwMakePermanentObject_fn>                              observers_ZwMakePermanentObject;
    std::vector<on_NtMakeTemporaryObject_fn>                              observers_NtMakeTemporaryObject;
    std::vector<on_ZwMapCMFModule_fn>                                     observers_ZwMapCMFModule;
    std::vector<on_NtMapUserPhysicalPages_fn>                             observers_NtMapUserPhysicalPages;
    std::vector<on_ZwMapUserPhysicalPagesScatter_fn>                      observers_ZwMapUserPhysicalPagesScatter;
    std::vector<on_ZwMapViewOfSection_fn>                                 observers_ZwMapViewOfSection;
    std::vector<on_NtModifyBootEntry_fn>                                  observers_NtModifyBootEntry;
    std::vector<on_ZwModifyDriverEntry_fn>                                observers_ZwModifyDriverEntry;
    std::vector<on_NtNotifyChangeDirectoryFile_fn>                        observers_NtNotifyChangeDirectoryFile;
    std::vector<on_NtNotifyChangeKey_fn>                                  observers_NtNotifyChangeKey;
    std::vector<on_NtNotifyChangeMultipleKeys_fn>                         observers_NtNotifyChangeMultipleKeys;
    std::vector<on_NtNotifyChangeSession_fn>                              observers_NtNotifyChangeSession;
    std::vector<on_ZwOpenDirectoryObject_fn>                              observers_ZwOpenDirectoryObject;
    std::vector<on_ZwOpenEnlistment_fn>                                   observers_ZwOpenEnlistment;
    std::vector<on_NtOpenEvent_fn>                                        observers_NtOpenEvent;
    std::vector<on_NtOpenEventPair_fn>                                    observers_NtOpenEventPair;
    std::vector<on_NtOpenFile_fn>                                         observers_NtOpenFile;
    std::vector<on_ZwOpenIoCompletion_fn>                                 observers_ZwOpenIoCompletion;
    std::vector<on_ZwOpenJobObject_fn>                                    observers_ZwOpenJobObject;
    std::vector<on_NtOpenKeyedEvent_fn>                                   observers_NtOpenKeyedEvent;
    std::vector<on_ZwOpenKeyEx_fn>                                        observers_ZwOpenKeyEx;
    std::vector<on_ZwOpenKey_fn>                                          observers_ZwOpenKey;
    std::vector<on_NtOpenKeyTransactedEx_fn>                              observers_NtOpenKeyTransactedEx;
    std::vector<on_NtOpenKeyTransacted_fn>                                observers_NtOpenKeyTransacted;
    std::vector<on_NtOpenMutant_fn>                                       observers_NtOpenMutant;
    std::vector<on_ZwOpenObjectAuditAlarm_fn>                             observers_ZwOpenObjectAuditAlarm;
    std::vector<on_NtOpenPrivateNamespace_fn>                             observers_NtOpenPrivateNamespace;
    std::vector<on_ZwOpenProcess_fn>                                      observers_ZwOpenProcess;
    std::vector<on_ZwOpenProcessTokenEx_fn>                               observers_ZwOpenProcessTokenEx;
    std::vector<on_ZwOpenProcessToken_fn>                                 observers_ZwOpenProcessToken;
    std::vector<on_ZwOpenResourceManager_fn>                              observers_ZwOpenResourceManager;
    std::vector<on_NtOpenSection_fn>                                      observers_NtOpenSection;
    std::vector<on_NtOpenSemaphore_fn>                                    observers_NtOpenSemaphore;
    std::vector<on_NtOpenSession_fn>                                      observers_NtOpenSession;
    std::vector<on_NtOpenSymbolicLinkObject_fn>                           observers_NtOpenSymbolicLinkObject;
    std::vector<on_ZwOpenThread_fn>                                       observers_ZwOpenThread;
    std::vector<on_NtOpenThreadTokenEx_fn>                                observers_NtOpenThreadTokenEx;
    std::vector<on_NtOpenThreadToken_fn>                                  observers_NtOpenThreadToken;
    std::vector<on_ZwOpenTimer_fn>                                        observers_ZwOpenTimer;
    std::vector<on_ZwOpenTransactionManager_fn>                           observers_ZwOpenTransactionManager;
    std::vector<on_ZwOpenTransaction_fn>                                  observers_ZwOpenTransaction;
    std::vector<on_NtPlugPlayControl_fn>                                  observers_NtPlugPlayControl;
    std::vector<on_ZwPowerInformation_fn>                                 observers_ZwPowerInformation;
    std::vector<on_NtPrepareComplete_fn>                                  observers_NtPrepareComplete;
    std::vector<on_ZwPrepareEnlistment_fn>                                observers_ZwPrepareEnlistment;
    std::vector<on_ZwPrePrepareComplete_fn>                               observers_ZwPrePrepareComplete;
    std::vector<on_NtPrePrepareEnlistment_fn>                             observers_NtPrePrepareEnlistment;
    std::vector<on_ZwPrivilegeCheck_fn>                                   observers_ZwPrivilegeCheck;
    std::vector<on_NtPrivilegedServiceAuditAlarm_fn>                      observers_NtPrivilegedServiceAuditAlarm;
    std::vector<on_ZwPrivilegeObjectAuditAlarm_fn>                        observers_ZwPrivilegeObjectAuditAlarm;
    std::vector<on_NtPropagationComplete_fn>                              observers_NtPropagationComplete;
    std::vector<on_ZwPropagationFailed_fn>                                observers_ZwPropagationFailed;
    std::vector<on_ZwProtectVirtualMemory_fn>                             observers_ZwProtectVirtualMemory;
    std::vector<on_ZwPulseEvent_fn>                                       observers_ZwPulseEvent;
    std::vector<on_ZwQueryAttributesFile_fn>                              observers_ZwQueryAttributesFile;
    std::vector<on_ZwQueryBootEntryOrder_fn>                              observers_ZwQueryBootEntryOrder;
    std::vector<on_ZwQueryBootOptions_fn>                                 observers_ZwQueryBootOptions;
    std::vector<on_NtQueryDebugFilterState_fn>                            observers_NtQueryDebugFilterState;
    std::vector<on_NtQueryDefaultLocale_fn>                               observers_NtQueryDefaultLocale;
    std::vector<on_ZwQueryDefaultUILanguage_fn>                           observers_ZwQueryDefaultUILanguage;
    std::vector<on_ZwQueryDirectoryFile_fn>                               observers_ZwQueryDirectoryFile;
    std::vector<on_ZwQueryDirectoryObject_fn>                             observers_ZwQueryDirectoryObject;
    std::vector<on_NtQueryDriverEntryOrder_fn>                            observers_NtQueryDriverEntryOrder;
    std::vector<on_ZwQueryEaFile_fn>                                      observers_ZwQueryEaFile;
    std::vector<on_NtQueryEvent_fn>                                       observers_NtQueryEvent;
    std::vector<on_ZwQueryFullAttributesFile_fn>                          observers_ZwQueryFullAttributesFile;
    std::vector<on_NtQueryInformationAtom_fn>                             observers_NtQueryInformationAtom;
    std::vector<on_ZwQueryInformationEnlistment_fn>                       observers_ZwQueryInformationEnlistment;
    std::vector<on_ZwQueryInformationFile_fn>                             observers_ZwQueryInformationFile;
    std::vector<on_ZwQueryInformationJobObject_fn>                        observers_ZwQueryInformationJobObject;
    std::vector<on_ZwQueryInformationPort_fn>                             observers_ZwQueryInformationPort;
    std::vector<on_ZwQueryInformationProcess_fn>                          observers_ZwQueryInformationProcess;
    std::vector<on_ZwQueryInformationResourceManager_fn>                  observers_ZwQueryInformationResourceManager;
    std::vector<on_NtQueryInformationThread_fn>                           observers_NtQueryInformationThread;
    std::vector<on_ZwQueryInformationToken_fn>                            observers_ZwQueryInformationToken;
    std::vector<on_ZwQueryInformationTransaction_fn>                      observers_ZwQueryInformationTransaction;
    std::vector<on_NtQueryInformationTransactionManager_fn>               observers_NtQueryInformationTransactionManager;
    std::vector<on_ZwQueryInformationWorkerFactory_fn>                    observers_ZwQueryInformationWorkerFactory;
    std::vector<on_NtQueryInstallUILanguage_fn>                           observers_NtQueryInstallUILanguage;
    std::vector<on_NtQueryIntervalProfile_fn>                             observers_NtQueryIntervalProfile;
    std::vector<on_NtQueryIoCompletion_fn>                                observers_NtQueryIoCompletion;
    std::vector<on_ZwQueryKey_fn>                                         observers_ZwQueryKey;
    std::vector<on_NtQueryLicenseValue_fn>                                observers_NtQueryLicenseValue;
    std::vector<on_NtQueryMultipleValueKey_fn>                            observers_NtQueryMultipleValueKey;
    std::vector<on_NtQueryMutant_fn>                                      observers_NtQueryMutant;
    std::vector<on_NtQueryObject_fn>                                      observers_NtQueryObject;
    std::vector<on_NtQueryOpenSubKeysEx_fn>                               observers_NtQueryOpenSubKeysEx;
    std::vector<on_NtQueryOpenSubKeys_fn>                                 observers_NtQueryOpenSubKeys;
    std::vector<on_NtQueryPerformanceCounter_fn>                          observers_NtQueryPerformanceCounter;
    std::vector<on_ZwQueryQuotaInformationFile_fn>                        observers_ZwQueryQuotaInformationFile;
    std::vector<on_ZwQuerySection_fn>                                     observers_ZwQuerySection;
    std::vector<on_ZwQuerySecurityAttributesToken_fn>                     observers_ZwQuerySecurityAttributesToken;
    std::vector<on_NtQuerySecurityObject_fn>                              observers_NtQuerySecurityObject;
    std::vector<on_ZwQuerySemaphore_fn>                                   observers_ZwQuerySemaphore;
    std::vector<on_ZwQuerySymbolicLinkObject_fn>                          observers_ZwQuerySymbolicLinkObject;
    std::vector<on_ZwQuerySystemEnvironmentValueEx_fn>                    observers_ZwQuerySystemEnvironmentValueEx;
    std::vector<on_ZwQuerySystemEnvironmentValue_fn>                      observers_ZwQuerySystemEnvironmentValue;
    std::vector<on_ZwQuerySystemInformationEx_fn>                         observers_ZwQuerySystemInformationEx;
    std::vector<on_NtQuerySystemInformation_fn>                           observers_NtQuerySystemInformation;
    std::vector<on_NtQuerySystemTime_fn>                                  observers_NtQuerySystemTime;
    std::vector<on_ZwQueryTimer_fn>                                       observers_ZwQueryTimer;
    std::vector<on_NtQueryTimerResolution_fn>                             observers_NtQueryTimerResolution;
    std::vector<on_ZwQueryValueKey_fn>                                    observers_ZwQueryValueKey;
    std::vector<on_NtQueryVirtualMemory_fn>                               observers_NtQueryVirtualMemory;
    std::vector<on_NtQueryVolumeInformationFile_fn>                       observers_NtQueryVolumeInformationFile;
    std::vector<on_NtQueueApcThreadEx_fn>                                 observers_NtQueueApcThreadEx;
    std::vector<on_NtQueueApcThread_fn>                                   observers_NtQueueApcThread;
    std::vector<on_ZwRaiseException_fn>                                   observers_ZwRaiseException;
    std::vector<on_ZwRaiseHardError_fn>                                   observers_ZwRaiseHardError;
    std::vector<on_NtReadFile_fn>                                         observers_NtReadFile;
    std::vector<on_NtReadFileScatter_fn>                                  observers_NtReadFileScatter;
    std::vector<on_ZwReadOnlyEnlistment_fn>                               observers_ZwReadOnlyEnlistment;
    std::vector<on_ZwReadRequestData_fn>                                  observers_ZwReadRequestData;
    std::vector<on_NtReadVirtualMemory_fn>                                observers_NtReadVirtualMemory;
    std::vector<on_NtRecoverEnlistment_fn>                                observers_NtRecoverEnlistment;
    std::vector<on_NtRecoverResourceManager_fn>                           observers_NtRecoverResourceManager;
    std::vector<on_ZwRecoverTransactionManager_fn>                        observers_ZwRecoverTransactionManager;
    std::vector<on_ZwRegisterProtocolAddressInformation_fn>               observers_ZwRegisterProtocolAddressInformation;
    std::vector<on_ZwRegisterThreadTerminatePort_fn>                      observers_ZwRegisterThreadTerminatePort;
    std::vector<on_NtReleaseKeyedEvent_fn>                                observers_NtReleaseKeyedEvent;
    std::vector<on_ZwReleaseMutant_fn>                                    observers_ZwReleaseMutant;
    std::vector<on_NtReleaseSemaphore_fn>                                 observers_NtReleaseSemaphore;
    std::vector<on_ZwReleaseWorkerFactoryWorker_fn>                       observers_ZwReleaseWorkerFactoryWorker;
    std::vector<on_ZwRemoveIoCompletionEx_fn>                             observers_ZwRemoveIoCompletionEx;
    std::vector<on_ZwRemoveIoCompletion_fn>                               observers_ZwRemoveIoCompletion;
    std::vector<on_ZwRemoveProcessDebug_fn>                               observers_ZwRemoveProcessDebug;
    std::vector<on_ZwRenameKey_fn>                                        observers_ZwRenameKey;
    std::vector<on_NtRenameTransactionManager_fn>                         observers_NtRenameTransactionManager;
    std::vector<on_ZwReplaceKey_fn>                                       observers_ZwReplaceKey;
    std::vector<on_NtReplacePartitionUnit_fn>                             observers_NtReplacePartitionUnit;
    std::vector<on_ZwReplyPort_fn>                                        observers_ZwReplyPort;
    std::vector<on_NtReplyWaitReceivePortEx_fn>                           observers_NtReplyWaitReceivePortEx;
    std::vector<on_NtReplyWaitReceivePort_fn>                             observers_NtReplyWaitReceivePort;
    std::vector<on_NtReplyWaitReplyPort_fn>                               observers_NtReplyWaitReplyPort;
    std::vector<on_ZwRequestPort_fn>                                      observers_ZwRequestPort;
    std::vector<on_NtRequestWaitReplyPort_fn>                             observers_NtRequestWaitReplyPort;
    std::vector<on_NtResetEvent_fn>                                       observers_NtResetEvent;
    std::vector<on_ZwResetWriteWatch_fn>                                  observers_ZwResetWriteWatch;
    std::vector<on_NtRestoreKey_fn>                                       observers_NtRestoreKey;
    std::vector<on_ZwResumeProcess_fn>                                    observers_ZwResumeProcess;
    std::vector<on_ZwResumeThread_fn>                                     observers_ZwResumeThread;
    std::vector<on_ZwRollbackComplete_fn>                                 observers_ZwRollbackComplete;
    std::vector<on_NtRollbackEnlistment_fn>                               observers_NtRollbackEnlistment;
    std::vector<on_NtRollbackTransaction_fn>                              observers_NtRollbackTransaction;
    std::vector<on_NtRollforwardTransactionManager_fn>                    observers_NtRollforwardTransactionManager;
    std::vector<on_NtSaveKeyEx_fn>                                        observers_NtSaveKeyEx;
    std::vector<on_NtSaveKey_fn>                                          observers_NtSaveKey;
    std::vector<on_NtSaveMergedKeys_fn>                                   observers_NtSaveMergedKeys;
    std::vector<on_NtSecureConnectPort_fn>                                observers_NtSecureConnectPort;
    std::vector<on_ZwSetBootEntryOrder_fn>                                observers_ZwSetBootEntryOrder;
    std::vector<on_ZwSetBootOptions_fn>                                   observers_ZwSetBootOptions;
    std::vector<on_ZwSetContextThread_fn>                                 observers_ZwSetContextThread;
    std::vector<on_NtSetDebugFilterState_fn>                              observers_NtSetDebugFilterState;
    std::vector<on_NtSetDefaultHardErrorPort_fn>                          observers_NtSetDefaultHardErrorPort;
    std::vector<on_NtSetDefaultLocale_fn>                                 observers_NtSetDefaultLocale;
    std::vector<on_ZwSetDefaultUILanguage_fn>                             observers_ZwSetDefaultUILanguage;
    std::vector<on_NtSetDriverEntryOrder_fn>                              observers_NtSetDriverEntryOrder;
    std::vector<on_ZwSetEaFile_fn>                                        observers_ZwSetEaFile;
    std::vector<on_NtSetEventBoostPriority_fn>                            observers_NtSetEventBoostPriority;
    std::vector<on_NtSetEvent_fn>                                         observers_NtSetEvent;
    std::vector<on_NtSetHighEventPair_fn>                                 observers_NtSetHighEventPair;
    std::vector<on_NtSetHighWaitLowEventPair_fn>                          observers_NtSetHighWaitLowEventPair;
    std::vector<on_ZwSetInformationDebugObject_fn>                        observers_ZwSetInformationDebugObject;
    std::vector<on_NtSetInformationEnlistment_fn>                         observers_NtSetInformationEnlistment;
    std::vector<on_ZwSetInformationFile_fn>                               observers_ZwSetInformationFile;
    std::vector<on_ZwSetInformationJobObject_fn>                          observers_ZwSetInformationJobObject;
    std::vector<on_ZwSetInformationKey_fn>                                observers_ZwSetInformationKey;
    std::vector<on_ZwSetInformationObject_fn>                             observers_ZwSetInformationObject;
    std::vector<on_ZwSetInformationProcess_fn>                            observers_ZwSetInformationProcess;
    std::vector<on_ZwSetInformationResourceManager_fn>                    observers_ZwSetInformationResourceManager;
    std::vector<on_ZwSetInformationThread_fn>                             observers_ZwSetInformationThread;
    std::vector<on_ZwSetInformationToken_fn>                              observers_ZwSetInformationToken;
    std::vector<on_ZwSetInformationTransaction_fn>                        observers_ZwSetInformationTransaction;
    std::vector<on_ZwSetInformationTransactionManager_fn>                 observers_ZwSetInformationTransactionManager;
    std::vector<on_ZwSetInformationWorkerFactory_fn>                      observers_ZwSetInformationWorkerFactory;
    std::vector<on_NtSetIntervalProfile_fn>                               observers_NtSetIntervalProfile;
    std::vector<on_NtSetIoCompletionEx_fn>                                observers_NtSetIoCompletionEx;
    std::vector<on_NtSetIoCompletion_fn>                                  observers_NtSetIoCompletion;
    std::vector<on_ZwSetLdtEntries_fn>                                    observers_ZwSetLdtEntries;
    std::vector<on_ZwSetLowEventPair_fn>                                  observers_ZwSetLowEventPair;
    std::vector<on_ZwSetLowWaitHighEventPair_fn>                          observers_ZwSetLowWaitHighEventPair;
    std::vector<on_ZwSetQuotaInformationFile_fn>                          observers_ZwSetQuotaInformationFile;
    std::vector<on_NtSetSecurityObject_fn>                                observers_NtSetSecurityObject;
    std::vector<on_ZwSetSystemEnvironmentValueEx_fn>                      observers_ZwSetSystemEnvironmentValueEx;
    std::vector<on_ZwSetSystemEnvironmentValue_fn>                        observers_ZwSetSystemEnvironmentValue;
    std::vector<on_ZwSetSystemInformation_fn>                             observers_ZwSetSystemInformation;
    std::vector<on_ZwSetSystemPowerState_fn>                              observers_ZwSetSystemPowerState;
    std::vector<on_ZwSetSystemTime_fn>                                    observers_ZwSetSystemTime;
    std::vector<on_ZwSetThreadExecutionState_fn>                          observers_ZwSetThreadExecutionState;
    std::vector<on_ZwSetTimerEx_fn>                                       observers_ZwSetTimerEx;
    std::vector<on_ZwSetTimer_fn>                                         observers_ZwSetTimer;
    std::vector<on_NtSetTimerResolution_fn>                               observers_NtSetTimerResolution;
    std::vector<on_ZwSetUuidSeed_fn>                                      observers_ZwSetUuidSeed;
    std::vector<on_ZwSetValueKey_fn>                                      observers_ZwSetValueKey;
    std::vector<on_NtSetVolumeInformationFile_fn>                         observers_NtSetVolumeInformationFile;
    std::vector<on_ZwShutdownSystem_fn>                                   observers_ZwShutdownSystem;
    std::vector<on_NtShutdownWorkerFactory_fn>                            observers_NtShutdownWorkerFactory;
    std::vector<on_ZwSignalAndWaitForSingleObject_fn>                     observers_ZwSignalAndWaitForSingleObject;
    std::vector<on_ZwSinglePhaseReject_fn>                                observers_ZwSinglePhaseReject;
    std::vector<on_NtStartProfile_fn>                                     observers_NtStartProfile;
    std::vector<on_ZwStopProfile_fn>                                      observers_ZwStopProfile;
    std::vector<on_ZwSuspendProcess_fn>                                   observers_ZwSuspendProcess;
    std::vector<on_ZwSuspendThread_fn>                                    observers_ZwSuspendThread;
    std::vector<on_NtSystemDebugControl_fn>                               observers_NtSystemDebugControl;
    std::vector<on_ZwTerminateJobObject_fn>                               observers_ZwTerminateJobObject;
    std::vector<on_ZwTerminateProcess_fn>                                 observers_ZwTerminateProcess;
    std::vector<on_ZwTerminateThread_fn>                                  observers_ZwTerminateThread;
    std::vector<on_ZwTraceControl_fn>                                     observers_ZwTraceControl;
    std::vector<on_NtTraceEvent_fn>                                       observers_NtTraceEvent;
    std::vector<on_NtTranslateFilePath_fn>                                observers_NtTranslateFilePath;
    std::vector<on_ZwUnloadDriver_fn>                                     observers_ZwUnloadDriver;
    std::vector<on_ZwUnloadKey2_fn>                                       observers_ZwUnloadKey2;
    std::vector<on_ZwUnloadKeyEx_fn>                                      observers_ZwUnloadKeyEx;
    std::vector<on_NtUnloadKey_fn>                                        observers_NtUnloadKey;
    std::vector<on_ZwUnlockFile_fn>                                       observers_ZwUnlockFile;
    std::vector<on_NtUnlockVirtualMemory_fn>                              observers_NtUnlockVirtualMemory;
    std::vector<on_NtUnmapViewOfSection_fn>                               observers_NtUnmapViewOfSection;
    std::vector<on_NtVdmControl_fn>                                       observers_NtVdmControl;
    std::vector<on_NtWaitForDebugEvent_fn>                                observers_NtWaitForDebugEvent;
    std::vector<on_NtWaitForKeyedEvent_fn>                                observers_NtWaitForKeyedEvent;
    std::vector<on_NtWaitForMultipleObjects32_fn>                         observers_NtWaitForMultipleObjects32;
    std::vector<on_NtWaitForMultipleObjects_fn>                           observers_NtWaitForMultipleObjects;
    std::vector<on_ZwWaitForSingleObject_fn>                              observers_ZwWaitForSingleObject;
    std::vector<on_NtWaitForWorkViaWorkerFactory_fn>                      observers_NtWaitForWorkViaWorkerFactory;
    std::vector<on_ZwWaitHighEventPair_fn>                                observers_ZwWaitHighEventPair;
    std::vector<on_NtWaitLowEventPair_fn>                                 observers_NtWaitLowEventPair;
    std::vector<on_NtWorkerFactoryWorkerReady_fn>                         observers_NtWorkerFactoryWorkerReady;
    std::vector<on_NtWriteFileGather_fn>                                  observers_NtWriteFileGather;
    std::vector<on_NtWriteFile_fn>                                        observers_NtWriteFile;
    std::vector<on_NtWriteRequestData_fn>                                 observers_NtWriteRequestData;
    std::vector<on_NtWriteVirtualMemory_fn>                               observers_NtWriteVirtualMemory;
    std::vector<on_NtDisableLastKnownGood_fn>                             observers_NtDisableLastKnownGood;
    std::vector<on_NtEnableLastKnownGood_fn>                              observers_NtEnableLastKnownGood;
    std::vector<on_ZwFlushProcessWriteBuffers_fn>                         observers_ZwFlushProcessWriteBuffers;
    std::vector<on_NtFlushWriteBuffer_fn>                                 observers_NtFlushWriteBuffer;
    std::vector<on_NtGetCurrentProcessorNumber_fn>                        observers_NtGetCurrentProcessorNumber;
    std::vector<on_NtIsSystemResumeAutomatic_fn>                          observers_NtIsSystemResumeAutomatic;
    std::vector<on_ZwIsUILanguageComitted_fn>                             observers_ZwIsUILanguageComitted;
    std::vector<on_ZwQueryPortInformationProcess_fn>                      observers_ZwQueryPortInformationProcess;
    std::vector<on_NtSerializeBoot_fn>                                    observers_NtSerializeBoot;
    std::vector<on_NtTestAlert_fn>                                        observers_NtTestAlert;
    std::vector<on_ZwThawRegistry_fn>                                     observers_ZwThawRegistry;
    std::vector<on_NtThawTransactions_fn>                                 observers_NtThawTransactions;
    std::vector<on_ZwUmsThreadYield_fn>                                   observers_ZwUmsThreadYield;
    std::vector<on_ZwYieldExecution_fn>                                   observers_ZwYieldExecution;
};

monitor::syscallswow64::Data::Data(core::Core& core, std::string module)
    : core(core)
    , module(std::move(module))
{
}

monitor::syscallswow64::syscallswow64(core::Core& core, std::string module)
    : d_(std::make_unique<Data>(core, std::move(module)))
{
}

monitor::syscallswow64::~syscallswow64() = default;

namespace
{
    using Data = monitor::syscallswow64::Data;

    static core::Breakpoint register_callback(Data& d, proc_t proc, const char* name, const monitor::syscallswow64::on_call_fn& on_call)
    {
        const auto addr = d.core.sym.symbol(d.module, name);
        if(!addr)
            FAIL(nullptr, "unable to find symbole {}!{}", d.module.data(), name);

        return d.core.state.set_breakpoint(*addr, proc, on_call);
    }

    static bool register_callback_with(Data& d, proc_t proc, const char* name, void (*callback)(Data&))
    {
        const auto dptr = &d;
        const auto bp = register_callback(d, proc, name, [=]
        {
            callback(*dptr);
        });
        if(!bp)
            return false;

        d.breakpoints.emplace_back(bp);
        return true;
    }

    template <typename T>
    static T arg(core::Core& core, size_t i)
    {
        const auto arg = monitor::get_arg_by_index(core, i);
        if(!arg)
            return {};

        return wntdll::cast_to<T>(*arg);
    }

    static void on_NtAcceptConnectPort(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle        = arg<wntdll::PHANDLE>(d.core, 0);
        const auto PortContext       = arg<wntdll::PVOID>(d.core, 1);
        const auto ConnectionRequest = arg<wntdll::PPORT_MESSAGE>(d.core, 2);
        const auto AcceptConnection  = arg<wntdll::BOOLEAN>(d.core, 3);
        const auto ServerView        = arg<wntdll::PPORT_VIEW>(d.core, 4);
        const auto ClientView        = arg<wntdll::PREMOTE_PORT_VIEW>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtAcceptConnectPort(PortHandle:{:#x}, PortContext:{:#x}, ConnectionRequest:{:#x}, AcceptConnection:{:#x}, ServerView:{:#x}, ClientView:{:#x})", PortHandle, PortContext, ConnectionRequest, AcceptConnection, ServerView, ClientView));

        for(const auto& it : d.observers_NtAcceptConnectPort)
            it(PortHandle, PortContext, ConnectionRequest, AcceptConnection, ServerView, ClientView);
    }

    static void on_ZwAccessCheckAndAuditAlarm(monitor::syscallswow64::Data& d)
    {
        const auto SubsystemName      = arg<wntdll::PUNICODE_STRING>(d.core, 0);
        const auto HandleId           = arg<wntdll::PVOID>(d.core, 1);
        const auto ObjectTypeName     = arg<wntdll::PUNICODE_STRING>(d.core, 2);
        const auto ObjectName         = arg<wntdll::PUNICODE_STRING>(d.core, 3);
        const auto SecurityDescriptor = arg<wntdll::PSECURITY_DESCRIPTOR>(d.core, 4);
        const auto DesiredAccess      = arg<wntdll::ACCESS_MASK>(d.core, 5);
        const auto GenericMapping     = arg<wntdll::PGENERIC_MAPPING>(d.core, 6);
        const auto ObjectCreation     = arg<wntdll::BOOLEAN>(d.core, 7);
        const auto GrantedAccess      = arg<wntdll::PACCESS_MASK>(d.core, 8);
        const auto AccessStatus       = arg<wntdll::PNTSTATUS>(d.core, 9);
        const auto GenerateOnClose    = arg<wntdll::PBOOLEAN>(d.core, 10);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwAccessCheckAndAuditAlarm(SubsystemName:{:#x}, HandleId:{:#x}, ObjectTypeName:{:#x}, ObjectName:{:#x}, SecurityDescriptor:{:#x}, DesiredAccess:{:#x}, GenericMapping:{:#x}, ObjectCreation:{:#x}, GrantedAccess:{:#x}, AccessStatus:{:#x}, GenerateOnClose:{:#x})", SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, GenerateOnClose));

        for(const auto& it : d.observers_ZwAccessCheckAndAuditAlarm)
            it(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, GenerateOnClose);
    }

    static void on_NtAccessCheckByTypeAndAuditAlarm(monitor::syscallswow64::Data& d)
    {
        const auto SubsystemName        = arg<wntdll::PUNICODE_STRING>(d.core, 0);
        const auto HandleId             = arg<wntdll::PVOID>(d.core, 1);
        const auto ObjectTypeName       = arg<wntdll::PUNICODE_STRING>(d.core, 2);
        const auto ObjectName           = arg<wntdll::PUNICODE_STRING>(d.core, 3);
        const auto SecurityDescriptor   = arg<wntdll::PSECURITY_DESCRIPTOR>(d.core, 4);
        const auto PrincipalSelfSid     = arg<wntdll::PSID>(d.core, 5);
        const auto DesiredAccess        = arg<wntdll::ACCESS_MASK>(d.core, 6);
        const auto AuditType            = arg<wntdll::AUDIT_EVENT_TYPE>(d.core, 7);
        const auto Flags                = arg<wntdll::ULONG>(d.core, 8);
        const auto ObjectTypeList       = arg<wntdll::POBJECT_TYPE_LIST>(d.core, 9);
        const auto ObjectTypeListLength = arg<wntdll::ULONG>(d.core, 10);
        const auto GenericMapping       = arg<wntdll::PGENERIC_MAPPING>(d.core, 11);
        const auto ObjectCreation       = arg<wntdll::BOOLEAN>(d.core, 12);
        const auto GrantedAccess        = arg<wntdll::PACCESS_MASK>(d.core, 13);
        const auto AccessStatus         = arg<wntdll::PNTSTATUS>(d.core, 14);
        const auto GenerateOnClose      = arg<wntdll::PBOOLEAN>(d.core, 15);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtAccessCheckByTypeAndAuditAlarm(SubsystemName:{:#x}, HandleId:{:#x}, ObjectTypeName:{:#x}, ObjectName:{:#x}, SecurityDescriptor:{:#x}, PrincipalSelfSid:{:#x}, DesiredAccess:{:#x}, AuditType:{:#x}, Flags:{:#x}, ObjectTypeList:{:#x}, ObjectTypeListLength:{:#x}, GenericMapping:{:#x}, ObjectCreation:{:#x}, GrantedAccess:{:#x}, AccessStatus:{:#x}, GenerateOnClose:{:#x})", SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, PrincipalSelfSid, DesiredAccess, AuditType, Flags, ObjectTypeList, ObjectTypeListLength, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, GenerateOnClose));

        for(const auto& it : d.observers_NtAccessCheckByTypeAndAuditAlarm)
            it(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, PrincipalSelfSid, DesiredAccess, AuditType, Flags, ObjectTypeList, ObjectTypeListLength, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, GenerateOnClose);
    }

    static void on_NtAccessCheckByType(monitor::syscallswow64::Data& d)
    {
        const auto SecurityDescriptor   = arg<wntdll::PSECURITY_DESCRIPTOR>(d.core, 0);
        const auto PrincipalSelfSid     = arg<wntdll::PSID>(d.core, 1);
        const auto ClientToken          = arg<wntdll::HANDLE>(d.core, 2);
        const auto DesiredAccess        = arg<wntdll::ACCESS_MASK>(d.core, 3);
        const auto ObjectTypeList       = arg<wntdll::POBJECT_TYPE_LIST>(d.core, 4);
        const auto ObjectTypeListLength = arg<wntdll::ULONG>(d.core, 5);
        const auto GenericMapping       = arg<wntdll::PGENERIC_MAPPING>(d.core, 6);
        const auto PrivilegeSet         = arg<wntdll::PPRIVILEGE_SET>(d.core, 7);
        const auto PrivilegeSetLength   = arg<wntdll::PULONG>(d.core, 8);
        const auto GrantedAccess        = arg<wntdll::PACCESS_MASK>(d.core, 9);
        const auto AccessStatus         = arg<wntdll::PNTSTATUS>(d.core, 10);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtAccessCheckByType(SecurityDescriptor:{:#x}, PrincipalSelfSid:{:#x}, ClientToken:{:#x}, DesiredAccess:{:#x}, ObjectTypeList:{:#x}, ObjectTypeListLength:{:#x}, GenericMapping:{:#x}, PrivilegeSet:{:#x}, PrivilegeSetLength:{:#x}, GrantedAccess:{:#x}, AccessStatus:{:#x})", SecurityDescriptor, PrincipalSelfSid, ClientToken, DesiredAccess, ObjectTypeList, ObjectTypeListLength, GenericMapping, PrivilegeSet, PrivilegeSetLength, GrantedAccess, AccessStatus));

        for(const auto& it : d.observers_NtAccessCheckByType)
            it(SecurityDescriptor, PrincipalSelfSid, ClientToken, DesiredAccess, ObjectTypeList, ObjectTypeListLength, GenericMapping, PrivilegeSet, PrivilegeSetLength, GrantedAccess, AccessStatus);
    }

    static void on_ZwAccessCheckByTypeResultListAndAuditAlarmByHandle(monitor::syscallswow64::Data& d)
    {
        const auto SubsystemName        = arg<wntdll::PUNICODE_STRING>(d.core, 0);
        const auto HandleId             = arg<wntdll::PVOID>(d.core, 1);
        const auto ClientToken          = arg<wntdll::HANDLE>(d.core, 2);
        const auto ObjectTypeName       = arg<wntdll::PUNICODE_STRING>(d.core, 3);
        const auto ObjectName           = arg<wntdll::PUNICODE_STRING>(d.core, 4);
        const auto SecurityDescriptor   = arg<wntdll::PSECURITY_DESCRIPTOR>(d.core, 5);
        const auto PrincipalSelfSid     = arg<wntdll::PSID>(d.core, 6);
        const auto DesiredAccess        = arg<wntdll::ACCESS_MASK>(d.core, 7);
        const auto AuditType            = arg<wntdll::AUDIT_EVENT_TYPE>(d.core, 8);
        const auto Flags                = arg<wntdll::ULONG>(d.core, 9);
        const auto ObjectTypeList       = arg<wntdll::POBJECT_TYPE_LIST>(d.core, 10);
        const auto ObjectTypeListLength = arg<wntdll::ULONG>(d.core, 11);
        const auto GenericMapping       = arg<wntdll::PGENERIC_MAPPING>(d.core, 12);
        const auto ObjectCreation       = arg<wntdll::BOOLEAN>(d.core, 13);
        const auto GrantedAccess        = arg<wntdll::PACCESS_MASK>(d.core, 14);
        const auto AccessStatus         = arg<wntdll::PNTSTATUS>(d.core, 15);
        const auto GenerateOnClose      = arg<wntdll::PBOOLEAN>(d.core, 16);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwAccessCheckByTypeResultListAndAuditAlarmByHandle(SubsystemName:{:#x}, HandleId:{:#x}, ClientToken:{:#x}, ObjectTypeName:{:#x}, ObjectName:{:#x}, SecurityDescriptor:{:#x}, PrincipalSelfSid:{:#x}, DesiredAccess:{:#x}, AuditType:{:#x}, Flags:{:#x}, ObjectTypeList:{:#x}, ObjectTypeListLength:{:#x}, GenericMapping:{:#x}, ObjectCreation:{:#x}, GrantedAccess:{:#x}, AccessStatus:{:#x}, GenerateOnClose:{:#x})", SubsystemName, HandleId, ClientToken, ObjectTypeName, ObjectName, SecurityDescriptor, PrincipalSelfSid, DesiredAccess, AuditType, Flags, ObjectTypeList, ObjectTypeListLength, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, GenerateOnClose));

        for(const auto& it : d.observers_ZwAccessCheckByTypeResultListAndAuditAlarmByHandle)
            it(SubsystemName, HandleId, ClientToken, ObjectTypeName, ObjectName, SecurityDescriptor, PrincipalSelfSid, DesiredAccess, AuditType, Flags, ObjectTypeList, ObjectTypeListLength, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, GenerateOnClose);
    }

    static void on_NtAccessCheckByTypeResultListAndAuditAlarm(monitor::syscallswow64::Data& d)
    {
        const auto SubsystemName        = arg<wntdll::PUNICODE_STRING>(d.core, 0);
        const auto HandleId             = arg<wntdll::PVOID>(d.core, 1);
        const auto ObjectTypeName       = arg<wntdll::PUNICODE_STRING>(d.core, 2);
        const auto ObjectName           = arg<wntdll::PUNICODE_STRING>(d.core, 3);
        const auto SecurityDescriptor   = arg<wntdll::PSECURITY_DESCRIPTOR>(d.core, 4);
        const auto PrincipalSelfSid     = arg<wntdll::PSID>(d.core, 5);
        const auto DesiredAccess        = arg<wntdll::ACCESS_MASK>(d.core, 6);
        const auto AuditType            = arg<wntdll::AUDIT_EVENT_TYPE>(d.core, 7);
        const auto Flags                = arg<wntdll::ULONG>(d.core, 8);
        const auto ObjectTypeList       = arg<wntdll::POBJECT_TYPE_LIST>(d.core, 9);
        const auto ObjectTypeListLength = arg<wntdll::ULONG>(d.core, 10);
        const auto GenericMapping       = arg<wntdll::PGENERIC_MAPPING>(d.core, 11);
        const auto ObjectCreation       = arg<wntdll::BOOLEAN>(d.core, 12);
        const auto GrantedAccess        = arg<wntdll::PACCESS_MASK>(d.core, 13);
        const auto AccessStatus         = arg<wntdll::PNTSTATUS>(d.core, 14);
        const auto GenerateOnClose      = arg<wntdll::PBOOLEAN>(d.core, 15);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtAccessCheckByTypeResultListAndAuditAlarm(SubsystemName:{:#x}, HandleId:{:#x}, ObjectTypeName:{:#x}, ObjectName:{:#x}, SecurityDescriptor:{:#x}, PrincipalSelfSid:{:#x}, DesiredAccess:{:#x}, AuditType:{:#x}, Flags:{:#x}, ObjectTypeList:{:#x}, ObjectTypeListLength:{:#x}, GenericMapping:{:#x}, ObjectCreation:{:#x}, GrantedAccess:{:#x}, AccessStatus:{:#x}, GenerateOnClose:{:#x})", SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, PrincipalSelfSid, DesiredAccess, AuditType, Flags, ObjectTypeList, ObjectTypeListLength, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, GenerateOnClose));

        for(const auto& it : d.observers_NtAccessCheckByTypeResultListAndAuditAlarm)
            it(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, PrincipalSelfSid, DesiredAccess, AuditType, Flags, ObjectTypeList, ObjectTypeListLength, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, GenerateOnClose);
    }

    static void on_NtAccessCheckByTypeResultList(monitor::syscallswow64::Data& d)
    {
        const auto SecurityDescriptor   = arg<wntdll::PSECURITY_DESCRIPTOR>(d.core, 0);
        const auto PrincipalSelfSid     = arg<wntdll::PSID>(d.core, 1);
        const auto ClientToken          = arg<wntdll::HANDLE>(d.core, 2);
        const auto DesiredAccess        = arg<wntdll::ACCESS_MASK>(d.core, 3);
        const auto ObjectTypeList       = arg<wntdll::POBJECT_TYPE_LIST>(d.core, 4);
        const auto ObjectTypeListLength = arg<wntdll::ULONG>(d.core, 5);
        const auto GenericMapping       = arg<wntdll::PGENERIC_MAPPING>(d.core, 6);
        const auto PrivilegeSet         = arg<wntdll::PPRIVILEGE_SET>(d.core, 7);
        const auto PrivilegeSetLength   = arg<wntdll::PULONG>(d.core, 8);
        const auto GrantedAccess        = arg<wntdll::PACCESS_MASK>(d.core, 9);
        const auto AccessStatus         = arg<wntdll::PNTSTATUS>(d.core, 10);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtAccessCheckByTypeResultList(SecurityDescriptor:{:#x}, PrincipalSelfSid:{:#x}, ClientToken:{:#x}, DesiredAccess:{:#x}, ObjectTypeList:{:#x}, ObjectTypeListLength:{:#x}, GenericMapping:{:#x}, PrivilegeSet:{:#x}, PrivilegeSetLength:{:#x}, GrantedAccess:{:#x}, AccessStatus:{:#x})", SecurityDescriptor, PrincipalSelfSid, ClientToken, DesiredAccess, ObjectTypeList, ObjectTypeListLength, GenericMapping, PrivilegeSet, PrivilegeSetLength, GrantedAccess, AccessStatus));

        for(const auto& it : d.observers_NtAccessCheckByTypeResultList)
            it(SecurityDescriptor, PrincipalSelfSid, ClientToken, DesiredAccess, ObjectTypeList, ObjectTypeListLength, GenericMapping, PrivilegeSet, PrivilegeSetLength, GrantedAccess, AccessStatus);
    }

    static void on_NtAccessCheck(monitor::syscallswow64::Data& d)
    {
        const auto SecurityDescriptor = arg<wntdll::PSECURITY_DESCRIPTOR>(d.core, 0);
        const auto ClientToken        = arg<wntdll::HANDLE>(d.core, 1);
        const auto DesiredAccess      = arg<wntdll::ACCESS_MASK>(d.core, 2);
        const auto GenericMapping     = arg<wntdll::PGENERIC_MAPPING>(d.core, 3);
        const auto PrivilegeSet       = arg<wntdll::PPRIVILEGE_SET>(d.core, 4);
        const auto PrivilegeSetLength = arg<wntdll::PULONG>(d.core, 5);
        const auto GrantedAccess      = arg<wntdll::PACCESS_MASK>(d.core, 6);
        const auto AccessStatus       = arg<wntdll::PNTSTATUS>(d.core, 7);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtAccessCheck(SecurityDescriptor:{:#x}, ClientToken:{:#x}, DesiredAccess:{:#x}, GenericMapping:{:#x}, PrivilegeSet:{:#x}, PrivilegeSetLength:{:#x}, GrantedAccess:{:#x}, AccessStatus:{:#x})", SecurityDescriptor, ClientToken, DesiredAccess, GenericMapping, PrivilegeSet, PrivilegeSetLength, GrantedAccess, AccessStatus));

        for(const auto& it : d.observers_NtAccessCheck)
            it(SecurityDescriptor, ClientToken, DesiredAccess, GenericMapping, PrivilegeSet, PrivilegeSetLength, GrantedAccess, AccessStatus);
    }

    static void on_NtAddAtom(monitor::syscallswow64::Data& d)
    {
        const auto AtomName = arg<wntdll::PWSTR>(d.core, 0);
        const auto Length   = arg<wntdll::ULONG>(d.core, 1);
        const auto Atom     = arg<wntdll::PRTL_ATOM>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtAddAtom(AtomName:{:#x}, Length:{:#x}, Atom:{:#x})", AtomName, Length, Atom));

        for(const auto& it : d.observers_NtAddAtom)
            it(AtomName, Length, Atom);
    }

    static void on_ZwAddBootEntry(monitor::syscallswow64::Data& d)
    {
        const auto BootEntry = arg<wntdll::PBOOT_ENTRY>(d.core, 0);
        const auto Id        = arg<wntdll::PULONG>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwAddBootEntry(BootEntry:{:#x}, Id:{:#x})", BootEntry, Id));

        for(const auto& it : d.observers_ZwAddBootEntry)
            it(BootEntry, Id);
    }

    static void on_NtAddDriverEntry(monitor::syscallswow64::Data& d)
    {
        const auto DriverEntry = arg<wntdll::PEFI_DRIVER_ENTRY>(d.core, 0);
        const auto Id          = arg<wntdll::PULONG>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtAddDriverEntry(DriverEntry:{:#x}, Id:{:#x})", DriverEntry, Id));

        for(const auto& it : d.observers_NtAddDriverEntry)
            it(DriverEntry, Id);
    }

    static void on_ZwAdjustGroupsToken(monitor::syscallswow64::Data& d)
    {
        const auto TokenHandle    = arg<wntdll::HANDLE>(d.core, 0);
        const auto ResetToDefault = arg<wntdll::BOOLEAN>(d.core, 1);
        const auto NewState       = arg<wntdll::PTOKEN_GROUPS>(d.core, 2);
        const auto BufferLength   = arg<wntdll::ULONG>(d.core, 3);
        const auto PreviousState  = arg<wntdll::PTOKEN_GROUPS>(d.core, 4);
        const auto ReturnLength   = arg<wntdll::PULONG>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwAdjustGroupsToken(TokenHandle:{:#x}, ResetToDefault:{:#x}, NewState:{:#x}, BufferLength:{:#x}, PreviousState:{:#x}, ReturnLength:{:#x})", TokenHandle, ResetToDefault, NewState, BufferLength, PreviousState, ReturnLength));

        for(const auto& it : d.observers_ZwAdjustGroupsToken)
            it(TokenHandle, ResetToDefault, NewState, BufferLength, PreviousState, ReturnLength);
    }

    static void on_ZwAdjustPrivilegesToken(monitor::syscallswow64::Data& d)
    {
        const auto TokenHandle          = arg<wntdll::HANDLE>(d.core, 0);
        const auto DisableAllPrivileges = arg<wntdll::BOOLEAN>(d.core, 1);
        const auto NewState             = arg<wntdll::PTOKEN_PRIVILEGES>(d.core, 2);
        const auto BufferLength         = arg<wntdll::ULONG>(d.core, 3);
        const auto PreviousState        = arg<wntdll::PTOKEN_PRIVILEGES>(d.core, 4);
        const auto ReturnLength         = arg<wntdll::PULONG>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwAdjustPrivilegesToken(TokenHandle:{:#x}, DisableAllPrivileges:{:#x}, NewState:{:#x}, BufferLength:{:#x}, PreviousState:{:#x}, ReturnLength:{:#x})", TokenHandle, DisableAllPrivileges, NewState, BufferLength, PreviousState, ReturnLength));

        for(const auto& it : d.observers_ZwAdjustPrivilegesToken)
            it(TokenHandle, DisableAllPrivileges, NewState, BufferLength, PreviousState, ReturnLength);
    }

    static void on_NtAlertResumeThread(monitor::syscallswow64::Data& d)
    {
        const auto ThreadHandle         = arg<wntdll::HANDLE>(d.core, 0);
        const auto PreviousSuspendCount = arg<wntdll::PULONG>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtAlertResumeThread(ThreadHandle:{:#x}, PreviousSuspendCount:{:#x})", ThreadHandle, PreviousSuspendCount));

        for(const auto& it : d.observers_NtAlertResumeThread)
            it(ThreadHandle, PreviousSuspendCount);
    }

    static void on_NtAlertThread(monitor::syscallswow64::Data& d)
    {
        const auto ThreadHandle = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtAlertThread(ThreadHandle:{:#x})", ThreadHandle));

        for(const auto& it : d.observers_NtAlertThread)
            it(ThreadHandle);
    }

    static void on_ZwAllocateLocallyUniqueId(monitor::syscallswow64::Data& d)
    {
        const auto Luid = arg<wntdll::PLUID>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwAllocateLocallyUniqueId(Luid:{:#x})", Luid));

        for(const auto& it : d.observers_ZwAllocateLocallyUniqueId)
            it(Luid);
    }

    static void on_NtAllocateReserveObject(monitor::syscallswow64::Data& d)
    {
        const auto MemoryReserveHandle = arg<wntdll::PHANDLE>(d.core, 0);
        const auto ObjectAttributes    = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 1);
        const auto Type                = arg<wntdll::MEMORY_RESERVE_TYPE>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtAllocateReserveObject(MemoryReserveHandle:{:#x}, ObjectAttributes:{:#x}, Type:{:#x})", MemoryReserveHandle, ObjectAttributes, Type));

        for(const auto& it : d.observers_NtAllocateReserveObject)
            it(MemoryReserveHandle, ObjectAttributes, Type);
    }

    static void on_NtAllocateUserPhysicalPages(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto NumberOfPages = arg<wntdll::PULONG_PTR>(d.core, 1);
        const auto UserPfnArra   = arg<wntdll::PULONG_PTR>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtAllocateUserPhysicalPages(ProcessHandle:{:#x}, NumberOfPages:{:#x}, UserPfnArra:{:#x})", ProcessHandle, NumberOfPages, UserPfnArra));

        for(const auto& it : d.observers_NtAllocateUserPhysicalPages)
            it(ProcessHandle, NumberOfPages, UserPfnArra);
    }

    static void on_NtAllocateUuids(monitor::syscallswow64::Data& d)
    {
        const auto Time     = arg<wntdll::PULARGE_INTEGER>(d.core, 0);
        const auto Range    = arg<wntdll::PULONG>(d.core, 1);
        const auto Sequence = arg<wntdll::PULONG>(d.core, 2);
        const auto Seed     = arg<wntdll::PCHAR>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtAllocateUuids(Time:{:#x}, Range:{:#x}, Sequence:{:#x}, Seed:{:#x})", Time, Range, Sequence, Seed));

        for(const auto& it : d.observers_NtAllocateUuids)
            it(Time, Range, Sequence, Seed);
    }

    static void on_NtAllocateVirtualMemory(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle   = arg<wntdll::HANDLE>(d.core, 0);
        const auto STARBaseAddress = arg<wntdll::PVOID>(d.core, 1);
        const auto ZeroBits        = arg<wntdll::ULONG_PTR>(d.core, 2);
        const auto RegionSize      = arg<wntdll::PSIZE_T>(d.core, 3);
        const auto AllocationType  = arg<wntdll::ULONG>(d.core, 4);
        const auto Protect         = arg<wntdll::ULONG>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtAllocateVirtualMemory(ProcessHandle:{:#x}, STARBaseAddress:{:#x}, ZeroBits:{:#x}, RegionSize:{:#x}, AllocationType:{:#x}, Protect:{:#x})", ProcessHandle, STARBaseAddress, ZeroBits, RegionSize, AllocationType, Protect));

        for(const auto& it : d.observers_NtAllocateVirtualMemory)
            it(ProcessHandle, STARBaseAddress, ZeroBits, RegionSize, AllocationType, Protect);
    }

    static void on_NtAlpcAcceptConnectPort(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle                  = arg<wntdll::PHANDLE>(d.core, 0);
        const auto ConnectionPortHandle        = arg<wntdll::HANDLE>(d.core, 1);
        const auto Flags                       = arg<wntdll::ULONG>(d.core, 2);
        const auto ObjectAttributes            = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 3);
        const auto PortAttributes              = arg<wntdll::PALPC_PORT_ATTRIBUTES>(d.core, 4);
        const auto PortContext                 = arg<wntdll::PVOID>(d.core, 5);
        const auto ConnectionRequest           = arg<wntdll::PPORT_MESSAGE>(d.core, 6);
        const auto ConnectionMessageAttributes = arg<wntdll::PALPC_MESSAGE_ATTRIBUTES>(d.core, 7);
        const auto AcceptConnection            = arg<wntdll::BOOLEAN>(d.core, 8);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtAlpcAcceptConnectPort(PortHandle:{:#x}, ConnectionPortHandle:{:#x}, Flags:{:#x}, ObjectAttributes:{:#x}, PortAttributes:{:#x}, PortContext:{:#x}, ConnectionRequest:{:#x}, ConnectionMessageAttributes:{:#x}, AcceptConnection:{:#x})", PortHandle, ConnectionPortHandle, Flags, ObjectAttributes, PortAttributes, PortContext, ConnectionRequest, ConnectionMessageAttributes, AcceptConnection));

        for(const auto& it : d.observers_NtAlpcAcceptConnectPort)
            it(PortHandle, ConnectionPortHandle, Flags, ObjectAttributes, PortAttributes, PortContext, ConnectionRequest, ConnectionMessageAttributes, AcceptConnection);
    }

    static void on_ZwAlpcCancelMessage(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle     = arg<wntdll::HANDLE>(d.core, 0);
        const auto Flags          = arg<wntdll::ULONG>(d.core, 1);
        const auto MessageContext = arg<wntdll::PALPC_CONTEXT_ATTR>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwAlpcCancelMessage(PortHandle:{:#x}, Flags:{:#x}, MessageContext:{:#x})", PortHandle, Flags, MessageContext));

        for(const auto& it : d.observers_ZwAlpcCancelMessage)
            it(PortHandle, Flags, MessageContext);
    }

    static void on_ZwAlpcConnectPort(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle           = arg<wntdll::PHANDLE>(d.core, 0);
        const auto PortName             = arg<wntdll::PUNICODE_STRING>(d.core, 1);
        const auto ObjectAttributes     = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto PortAttributes       = arg<wntdll::PALPC_PORT_ATTRIBUTES>(d.core, 3);
        const auto Flags                = arg<wntdll::ULONG>(d.core, 4);
        const auto RequiredServerSid    = arg<wntdll::PSID>(d.core, 5);
        const auto ConnectionMessage    = arg<wntdll::PPORT_MESSAGE>(d.core, 6);
        const auto BufferLength         = arg<wntdll::PULONG>(d.core, 7);
        const auto OutMessageAttributes = arg<wntdll::PALPC_MESSAGE_ATTRIBUTES>(d.core, 8);
        const auto InMessageAttributes  = arg<wntdll::PALPC_MESSAGE_ATTRIBUTES>(d.core, 9);
        const auto Timeout              = arg<wntdll::PLARGE_INTEGER>(d.core, 10);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwAlpcConnectPort(PortHandle:{:#x}, PortName:{:#x}, ObjectAttributes:{:#x}, PortAttributes:{:#x}, Flags:{:#x}, RequiredServerSid:{:#x}, ConnectionMessage:{:#x}, BufferLength:{:#x}, OutMessageAttributes:{:#x}, InMessageAttributes:{:#x}, Timeout:{:#x})", PortHandle, PortName, ObjectAttributes, PortAttributes, Flags, RequiredServerSid, ConnectionMessage, BufferLength, OutMessageAttributes, InMessageAttributes, Timeout));

        for(const auto& it : d.observers_ZwAlpcConnectPort)
            it(PortHandle, PortName, ObjectAttributes, PortAttributes, Flags, RequiredServerSid, ConnectionMessage, BufferLength, OutMessageAttributes, InMessageAttributes, Timeout);
    }

    static void on_ZwAlpcCreatePort(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle       = arg<wntdll::PHANDLE>(d.core, 0);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 1);
        const auto PortAttributes   = arg<wntdll::PALPC_PORT_ATTRIBUTES>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwAlpcCreatePort(PortHandle:{:#x}, ObjectAttributes:{:#x}, PortAttributes:{:#x})", PortHandle, ObjectAttributes, PortAttributes));

        for(const auto& it : d.observers_ZwAlpcCreatePort)
            it(PortHandle, ObjectAttributes, PortAttributes);
    }

    static void on_NtAlpcCreatePortSection(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle        = arg<wntdll::HANDLE>(d.core, 0);
        const auto Flags             = arg<wntdll::ULONG>(d.core, 1);
        const auto SectionHandle     = arg<wntdll::HANDLE>(d.core, 2);
        const auto SectionSize       = arg<wntdll::SIZE_T>(d.core, 3);
        const auto AlpcSectionHandle = arg<wntdll::PALPC_HANDLE>(d.core, 4);
        const auto ActualSectionSize = arg<wntdll::PSIZE_T>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtAlpcCreatePortSection(PortHandle:{:#x}, Flags:{:#x}, SectionHandle:{:#x}, SectionSize:{:#x}, AlpcSectionHandle:{:#x}, ActualSectionSize:{:#x})", PortHandle, Flags, SectionHandle, SectionSize, AlpcSectionHandle, ActualSectionSize));

        for(const auto& it : d.observers_NtAlpcCreatePortSection)
            it(PortHandle, Flags, SectionHandle, SectionSize, AlpcSectionHandle, ActualSectionSize);
    }

    static void on_ZwAlpcCreateResourceReserve(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle  = arg<wntdll::HANDLE>(d.core, 0);
        const auto Flags       = arg<wntdll::ULONG>(d.core, 1);
        const auto MessageSize = arg<wntdll::SIZE_T>(d.core, 2);
        const auto ResourceId  = arg<wntdll::PALPC_HANDLE>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwAlpcCreateResourceReserve(PortHandle:{:#x}, Flags:{:#x}, MessageSize:{:#x}, ResourceId:{:#x})", PortHandle, Flags, MessageSize, ResourceId));

        for(const auto& it : d.observers_ZwAlpcCreateResourceReserve)
            it(PortHandle, Flags, MessageSize, ResourceId);
    }

    static void on_ZwAlpcCreateSectionView(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle     = arg<wntdll::HANDLE>(d.core, 0);
        const auto Flags          = arg<wntdll::ULONG>(d.core, 1);
        const auto ViewAttributes = arg<wntdll::PALPC_DATA_VIEW_ATTR>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwAlpcCreateSectionView(PortHandle:{:#x}, Flags:{:#x}, ViewAttributes:{:#x})", PortHandle, Flags, ViewAttributes));

        for(const auto& it : d.observers_ZwAlpcCreateSectionView)
            it(PortHandle, Flags, ViewAttributes);
    }

    static void on_ZwAlpcCreateSecurityContext(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle        = arg<wntdll::HANDLE>(d.core, 0);
        const auto Flags             = arg<wntdll::ULONG>(d.core, 1);
        const auto SecurityAttribute = arg<wntdll::PALPC_SECURITY_ATTR>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwAlpcCreateSecurityContext(PortHandle:{:#x}, Flags:{:#x}, SecurityAttribute:{:#x})", PortHandle, Flags, SecurityAttribute));

        for(const auto& it : d.observers_ZwAlpcCreateSecurityContext)
            it(PortHandle, Flags, SecurityAttribute);
    }

    static void on_ZwAlpcDeletePortSection(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle    = arg<wntdll::HANDLE>(d.core, 0);
        const auto Flags         = arg<wntdll::ULONG>(d.core, 1);
        const auto SectionHandle = arg<wntdll::ALPC_HANDLE>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwAlpcDeletePortSection(PortHandle:{:#x}, Flags:{:#x}, SectionHandle:{:#x})", PortHandle, Flags, SectionHandle));

        for(const auto& it : d.observers_ZwAlpcDeletePortSection)
            it(PortHandle, Flags, SectionHandle);
    }

    static void on_NtAlpcDeleteResourceReserve(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto Flags      = arg<wntdll::ULONG>(d.core, 1);
        const auto ResourceId = arg<wntdll::ALPC_HANDLE>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtAlpcDeleteResourceReserve(PortHandle:{:#x}, Flags:{:#x}, ResourceId:{:#x})", PortHandle, Flags, ResourceId));

        for(const auto& it : d.observers_NtAlpcDeleteResourceReserve)
            it(PortHandle, Flags, ResourceId);
    }

    static void on_NtAlpcDeleteSectionView(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto Flags      = arg<wntdll::ULONG>(d.core, 1);
        const auto ViewBase   = arg<wntdll::PVOID>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtAlpcDeleteSectionView(PortHandle:{:#x}, Flags:{:#x}, ViewBase:{:#x})", PortHandle, Flags, ViewBase));

        for(const auto& it : d.observers_NtAlpcDeleteSectionView)
            it(PortHandle, Flags, ViewBase);
    }

    static void on_NtAlpcDeleteSecurityContext(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle    = arg<wntdll::HANDLE>(d.core, 0);
        const auto Flags         = arg<wntdll::ULONG>(d.core, 1);
        const auto ContextHandle = arg<wntdll::ALPC_HANDLE>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtAlpcDeleteSecurityContext(PortHandle:{:#x}, Flags:{:#x}, ContextHandle:{:#x})", PortHandle, Flags, ContextHandle));

        for(const auto& it : d.observers_NtAlpcDeleteSecurityContext)
            it(PortHandle, Flags, ContextHandle);
    }

    static void on_NtAlpcDisconnectPort(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto Flags      = arg<wntdll::ULONG>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtAlpcDisconnectPort(PortHandle:{:#x}, Flags:{:#x})", PortHandle, Flags));

        for(const auto& it : d.observers_NtAlpcDisconnectPort)
            it(PortHandle, Flags);
    }

    static void on_ZwAlpcImpersonateClientOfPort(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle  = arg<wntdll::HANDLE>(d.core, 0);
        const auto PortMessage = arg<wntdll::PPORT_MESSAGE>(d.core, 1);
        const auto Reserved    = arg<wntdll::PVOID>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwAlpcImpersonateClientOfPort(PortHandle:{:#x}, PortMessage:{:#x}, Reserved:{:#x})", PortHandle, PortMessage, Reserved));

        for(const auto& it : d.observers_ZwAlpcImpersonateClientOfPort)
            it(PortHandle, PortMessage, Reserved);
    }

    static void on_ZwAlpcOpenSenderProcess(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle    = arg<wntdll::PHANDLE>(d.core, 0);
        const auto PortHandle       = arg<wntdll::HANDLE>(d.core, 1);
        const auto PortMessage      = arg<wntdll::PPORT_MESSAGE>(d.core, 2);
        const auto Flags            = arg<wntdll::ULONG>(d.core, 3);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 4);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwAlpcOpenSenderProcess(ProcessHandle:{:#x}, PortHandle:{:#x}, PortMessage:{:#x}, Flags:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x})", ProcessHandle, PortHandle, PortMessage, Flags, DesiredAccess, ObjectAttributes));

        for(const auto& it : d.observers_ZwAlpcOpenSenderProcess)
            it(ProcessHandle, PortHandle, PortMessage, Flags, DesiredAccess, ObjectAttributes);
    }

    static void on_ZwAlpcOpenSenderThread(monitor::syscallswow64::Data& d)
    {
        const auto ThreadHandle     = arg<wntdll::PHANDLE>(d.core, 0);
        const auto PortHandle       = arg<wntdll::HANDLE>(d.core, 1);
        const auto PortMessage      = arg<wntdll::PPORT_MESSAGE>(d.core, 2);
        const auto Flags            = arg<wntdll::ULONG>(d.core, 3);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 4);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwAlpcOpenSenderThread(ThreadHandle:{:#x}, PortHandle:{:#x}, PortMessage:{:#x}, Flags:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x})", ThreadHandle, PortHandle, PortMessage, Flags, DesiredAccess, ObjectAttributes));

        for(const auto& it : d.observers_ZwAlpcOpenSenderThread)
            it(ThreadHandle, PortHandle, PortMessage, Flags, DesiredAccess, ObjectAttributes);
    }

    static void on_ZwAlpcQueryInformation(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle           = arg<wntdll::HANDLE>(d.core, 0);
        const auto PortInformationClass = arg<wntdll::ALPC_PORT_INFORMATION_CLASS>(d.core, 1);
        const auto PortInformation      = arg<wntdll::PVOID>(d.core, 2);
        const auto Length               = arg<wntdll::ULONG>(d.core, 3);
        const auto ReturnLength         = arg<wntdll::PULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwAlpcQueryInformation(PortHandle:{:#x}, PortInformationClass:{:#x}, PortInformation:{:#x}, Length:{:#x}, ReturnLength:{:#x})", PortHandle, PortInformationClass, PortInformation, Length, ReturnLength));

        for(const auto& it : d.observers_ZwAlpcQueryInformation)
            it(PortHandle, PortInformationClass, PortInformation, Length, ReturnLength);
    }

    static void on_ZwAlpcQueryInformationMessage(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle              = arg<wntdll::HANDLE>(d.core, 0);
        const auto PortMessage             = arg<wntdll::PPORT_MESSAGE>(d.core, 1);
        const auto MessageInformationClass = arg<wntdll::ALPC_MESSAGE_INFORMATION_CLASS>(d.core, 2);
        const auto MessageInformation      = arg<wntdll::PVOID>(d.core, 3);
        const auto Length                  = arg<wntdll::ULONG>(d.core, 4);
        const auto ReturnLength            = arg<wntdll::PULONG>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwAlpcQueryInformationMessage(PortHandle:{:#x}, PortMessage:{:#x}, MessageInformationClass:{:#x}, MessageInformation:{:#x}, Length:{:#x}, ReturnLength:{:#x})", PortHandle, PortMessage, MessageInformationClass, MessageInformation, Length, ReturnLength));

        for(const auto& it : d.observers_ZwAlpcQueryInformationMessage)
            it(PortHandle, PortMessage, MessageInformationClass, MessageInformation, Length, ReturnLength);
    }

    static void on_NtAlpcRevokeSecurityContext(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle    = arg<wntdll::HANDLE>(d.core, 0);
        const auto Flags         = arg<wntdll::ULONG>(d.core, 1);
        const auto ContextHandle = arg<wntdll::ALPC_HANDLE>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtAlpcRevokeSecurityContext(PortHandle:{:#x}, Flags:{:#x}, ContextHandle:{:#x})", PortHandle, Flags, ContextHandle));

        for(const auto& it : d.observers_NtAlpcRevokeSecurityContext)
            it(PortHandle, Flags, ContextHandle);
    }

    static void on_NtAlpcSendWaitReceivePort(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle               = arg<wntdll::HANDLE>(d.core, 0);
        const auto Flags                    = arg<wntdll::ULONG>(d.core, 1);
        const auto SendMessage              = arg<wntdll::PPORT_MESSAGE>(d.core, 2);
        const auto SendMessageAttributes    = arg<wntdll::PALPC_MESSAGE_ATTRIBUTES>(d.core, 3);
        const auto ReceiveMessage           = arg<wntdll::PPORT_MESSAGE>(d.core, 4);
        const auto BufferLength             = arg<wntdll::PULONG>(d.core, 5);
        const auto ReceiveMessageAttributes = arg<wntdll::PALPC_MESSAGE_ATTRIBUTES>(d.core, 6);
        const auto Timeout                  = arg<wntdll::PLARGE_INTEGER>(d.core, 7);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtAlpcSendWaitReceivePort(PortHandle:{:#x}, Flags:{:#x}, SendMessage:{:#x}, SendMessageAttributes:{:#x}, ReceiveMessage:{:#x}, BufferLength:{:#x}, ReceiveMessageAttributes:{:#x}, Timeout:{:#x})", PortHandle, Flags, SendMessage, SendMessageAttributes, ReceiveMessage, BufferLength, ReceiveMessageAttributes, Timeout));

        for(const auto& it : d.observers_NtAlpcSendWaitReceivePort)
            it(PortHandle, Flags, SendMessage, SendMessageAttributes, ReceiveMessage, BufferLength, ReceiveMessageAttributes, Timeout);
    }

    static void on_NtAlpcSetInformation(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle           = arg<wntdll::HANDLE>(d.core, 0);
        const auto PortInformationClass = arg<wntdll::ALPC_PORT_INFORMATION_CLASS>(d.core, 1);
        const auto PortInformation      = arg<wntdll::PVOID>(d.core, 2);
        const auto Length               = arg<wntdll::ULONG>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtAlpcSetInformation(PortHandle:{:#x}, PortInformationClass:{:#x}, PortInformation:{:#x}, Length:{:#x})", PortHandle, PortInformationClass, PortInformation, Length));

        for(const auto& it : d.observers_NtAlpcSetInformation)
            it(PortHandle, PortInformationClass, PortInformation, Length);
    }

    static void on_NtApphelpCacheControl(monitor::syscallswow64::Data& d)
    {
        const auto type = arg<wntdll::APPHELPCOMMAND>(d.core, 0);
        const auto buf  = arg<wntdll::PVOID>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtApphelpCacheControl(type:{:#x}, buf:{:#x})", type, buf));

        for(const auto& it : d.observers_NtApphelpCacheControl)
            it(type, buf);
    }

    static void on_ZwAreMappedFilesTheSame(monitor::syscallswow64::Data& d)
    {
        const auto File1MappedAsAnImage = arg<wntdll::PVOID>(d.core, 0);
        const auto File2MappedAsFile    = arg<wntdll::PVOID>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwAreMappedFilesTheSame(File1MappedAsAnImage:{:#x}, File2MappedAsFile:{:#x})", File1MappedAsAnImage, File2MappedAsFile));

        for(const auto& it : d.observers_ZwAreMappedFilesTheSame)
            it(File1MappedAsAnImage, File2MappedAsFile);
    }

    static void on_ZwAssignProcessToJobObject(monitor::syscallswow64::Data& d)
    {
        const auto JobHandle     = arg<wntdll::HANDLE>(d.core, 0);
        const auto ProcessHandle = arg<wntdll::HANDLE>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwAssignProcessToJobObject(JobHandle:{:#x}, ProcessHandle:{:#x})", JobHandle, ProcessHandle));

        for(const auto& it : d.observers_ZwAssignProcessToJobObject)
            it(JobHandle, ProcessHandle);
    }

    static void on_ZwCallbackReturn(monitor::syscallswow64::Data& d)
    {
        const auto OutputBuffer = arg<wntdll::PVOID>(d.core, 0);
        const auto OutputLength = arg<wntdll::ULONG>(d.core, 1);
        const auto Status       = arg<wntdll::NTSTATUS>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwCallbackReturn(OutputBuffer:{:#x}, OutputLength:{:#x}, Status:{:#x})", OutputBuffer, OutputLength, Status));

        for(const auto& it : d.observers_ZwCallbackReturn)
            it(OutputBuffer, OutputLength, Status);
    }

    static void on_NtCancelIoFileEx(monitor::syscallswow64::Data& d)
    {
        const auto FileHandle        = arg<wntdll::HANDLE>(d.core, 0);
        const auto IoRequestToCancel = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 1);
        const auto IoStatusBlock     = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtCancelIoFileEx(FileHandle:{:#x}, IoRequestToCancel:{:#x}, IoStatusBlock:{:#x})", FileHandle, IoRequestToCancel, IoStatusBlock));

        for(const auto& it : d.observers_NtCancelIoFileEx)
            it(FileHandle, IoRequestToCancel, IoStatusBlock);
    }

    static void on_ZwCancelIoFile(monitor::syscallswow64::Data& d)
    {
        const auto FileHandle    = arg<wntdll::HANDLE>(d.core, 0);
        const auto IoStatusBlock = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwCancelIoFile(FileHandle:{:#x}, IoStatusBlock:{:#x})", FileHandle, IoStatusBlock));

        for(const auto& it : d.observers_ZwCancelIoFile)
            it(FileHandle, IoStatusBlock);
    }

    static void on_NtCancelSynchronousIoFile(monitor::syscallswow64::Data& d)
    {
        const auto ThreadHandle      = arg<wntdll::HANDLE>(d.core, 0);
        const auto IoRequestToCancel = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 1);
        const auto IoStatusBlock     = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtCancelSynchronousIoFile(ThreadHandle:{:#x}, IoRequestToCancel:{:#x}, IoStatusBlock:{:#x})", ThreadHandle, IoRequestToCancel, IoStatusBlock));

        for(const auto& it : d.observers_NtCancelSynchronousIoFile)
            it(ThreadHandle, IoRequestToCancel, IoStatusBlock);
    }

    static void on_ZwCancelTimer(monitor::syscallswow64::Data& d)
    {
        const auto TimerHandle  = arg<wntdll::HANDLE>(d.core, 0);
        const auto CurrentState = arg<wntdll::PBOOLEAN>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwCancelTimer(TimerHandle:{:#x}, CurrentState:{:#x})", TimerHandle, CurrentState));

        for(const auto& it : d.observers_ZwCancelTimer)
            it(TimerHandle, CurrentState);
    }

    static void on_NtClearEvent(monitor::syscallswow64::Data& d)
    {
        const auto EventHandle = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtClearEvent(EventHandle:{:#x})", EventHandle));

        for(const auto& it : d.observers_NtClearEvent)
            it(EventHandle);
    }

    static void on_NtClose(monitor::syscallswow64::Data& d)
    {
        const auto Handle = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtClose(Handle:{:#x})", Handle));

        for(const auto& it : d.observers_NtClose)
            it(Handle);
    }

    static void on_ZwCloseObjectAuditAlarm(monitor::syscallswow64::Data& d)
    {
        const auto SubsystemName   = arg<wntdll::PUNICODE_STRING>(d.core, 0);
        const auto HandleId        = arg<wntdll::PVOID>(d.core, 1);
        const auto GenerateOnClose = arg<wntdll::BOOLEAN>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwCloseObjectAuditAlarm(SubsystemName:{:#x}, HandleId:{:#x}, GenerateOnClose:{:#x})", SubsystemName, HandleId, GenerateOnClose));

        for(const auto& it : d.observers_ZwCloseObjectAuditAlarm)
            it(SubsystemName, HandleId, GenerateOnClose);
    }

    static void on_ZwCommitComplete(monitor::syscallswow64::Data& d)
    {
        const auto EnlistmentHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto TmVirtualClock   = arg<wntdll::PLARGE_INTEGER>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwCommitComplete(EnlistmentHandle:{:#x}, TmVirtualClock:{:#x})", EnlistmentHandle, TmVirtualClock));

        for(const auto& it : d.observers_ZwCommitComplete)
            it(EnlistmentHandle, TmVirtualClock);
    }

    static void on_NtCommitEnlistment(monitor::syscallswow64::Data& d)
    {
        const auto EnlistmentHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto TmVirtualClock   = arg<wntdll::PLARGE_INTEGER>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtCommitEnlistment(EnlistmentHandle:{:#x}, TmVirtualClock:{:#x})", EnlistmentHandle, TmVirtualClock));

        for(const auto& it : d.observers_NtCommitEnlistment)
            it(EnlistmentHandle, TmVirtualClock);
    }

    static void on_NtCommitTransaction(monitor::syscallswow64::Data& d)
    {
        const auto TransactionHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto Wait              = arg<wntdll::BOOLEAN>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtCommitTransaction(TransactionHandle:{:#x}, Wait:{:#x})", TransactionHandle, Wait));

        for(const auto& it : d.observers_NtCommitTransaction)
            it(TransactionHandle, Wait);
    }

    static void on_NtCompactKeys(monitor::syscallswow64::Data& d)
    {
        const auto Count    = arg<wntdll::ULONG>(d.core, 0);
        const auto KeyArray = arg<wntdll::HANDLE>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtCompactKeys(Count:{:#x}, KeyArray:{:#x})", Count, KeyArray));

        for(const auto& it : d.observers_NtCompactKeys)
            it(Count, KeyArray);
    }

    static void on_ZwCompareTokens(monitor::syscallswow64::Data& d)
    {
        const auto FirstTokenHandle  = arg<wntdll::HANDLE>(d.core, 0);
        const auto SecondTokenHandle = arg<wntdll::HANDLE>(d.core, 1);
        const auto Equal             = arg<wntdll::PBOOLEAN>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwCompareTokens(FirstTokenHandle:{:#x}, SecondTokenHandle:{:#x}, Equal:{:#x})", FirstTokenHandle, SecondTokenHandle, Equal));

        for(const auto& it : d.observers_ZwCompareTokens)
            it(FirstTokenHandle, SecondTokenHandle, Equal);
    }

    static void on_NtCompleteConnectPort(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtCompleteConnectPort(PortHandle:{:#x})", PortHandle));

        for(const auto& it : d.observers_NtCompleteConnectPort)
            it(PortHandle);
    }

    static void on_ZwCompressKey(monitor::syscallswow64::Data& d)
    {
        const auto Key = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwCompressKey(Key:{:#x})", Key));

        for(const auto& it : d.observers_ZwCompressKey)
            it(Key);
    }

    static void on_NtConnectPort(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle                  = arg<wntdll::PHANDLE>(d.core, 0);
        const auto PortName                    = arg<wntdll::PUNICODE_STRING>(d.core, 1);
        const auto SecurityQos                 = arg<wntdll::PSECURITY_QUALITY_OF_SERVICE>(d.core, 2);
        const auto ClientView                  = arg<wntdll::PPORT_VIEW>(d.core, 3);
        const auto ServerView                  = arg<wntdll::PREMOTE_PORT_VIEW>(d.core, 4);
        const auto MaxMessageLength            = arg<wntdll::PULONG>(d.core, 5);
        const auto ConnectionInformation       = arg<wntdll::PVOID>(d.core, 6);
        const auto ConnectionInformationLength = arg<wntdll::PULONG>(d.core, 7);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtConnectPort(PortHandle:{:#x}, PortName:{:#x}, SecurityQos:{:#x}, ClientView:{:#x}, ServerView:{:#x}, MaxMessageLength:{:#x}, ConnectionInformation:{:#x}, ConnectionInformationLength:{:#x})", PortHandle, PortName, SecurityQos, ClientView, ServerView, MaxMessageLength, ConnectionInformation, ConnectionInformationLength));

        for(const auto& it : d.observers_NtConnectPort)
            it(PortHandle, PortName, SecurityQos, ClientView, ServerView, MaxMessageLength, ConnectionInformation, ConnectionInformationLength);
    }

    static void on_ZwContinue(monitor::syscallswow64::Data& d)
    {
        const auto ContextRecord = arg<wntdll::PCONTEXT>(d.core, 0);
        const auto TestAlert     = arg<wntdll::BOOLEAN>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwContinue(ContextRecord:{:#x}, TestAlert:{:#x})", ContextRecord, TestAlert));

        for(const auto& it : d.observers_ZwContinue)
            it(ContextRecord, TestAlert);
    }

    static void on_ZwCreateDebugObject(monitor::syscallswow64::Data& d)
    {
        const auto DebugObjectHandle = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess     = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes  = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto Flags             = arg<wntdll::ULONG>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwCreateDebugObject(DebugObjectHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, Flags:{:#x})", DebugObjectHandle, DesiredAccess, ObjectAttributes, Flags));

        for(const auto& it : d.observers_ZwCreateDebugObject)
            it(DebugObjectHandle, DesiredAccess, ObjectAttributes, Flags);
    }

    static void on_ZwCreateDirectoryObject(monitor::syscallswow64::Data& d)
    {
        const auto DirectoryHandle  = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwCreateDirectoryObject(DirectoryHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x})", DirectoryHandle, DesiredAccess, ObjectAttributes));

        for(const auto& it : d.observers_ZwCreateDirectoryObject)
            it(DirectoryHandle, DesiredAccess, ObjectAttributes);
    }

    static void on_ZwCreateEnlistment(monitor::syscallswow64::Data& d)
    {
        const auto EnlistmentHandle      = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess         = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ResourceManagerHandle = arg<wntdll::HANDLE>(d.core, 2);
        const auto TransactionHandle     = arg<wntdll::HANDLE>(d.core, 3);
        const auto ObjectAttributes      = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 4);
        const auto CreateOptions         = arg<wntdll::ULONG>(d.core, 5);
        const auto NotificationMask      = arg<wntdll::NOTIFICATION_MASK>(d.core, 6);
        const auto EnlistmentKey         = arg<wntdll::PVOID>(d.core, 7);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwCreateEnlistment(EnlistmentHandle:{:#x}, DesiredAccess:{:#x}, ResourceManagerHandle:{:#x}, TransactionHandle:{:#x}, ObjectAttributes:{:#x}, CreateOptions:{:#x}, NotificationMask:{:#x}, EnlistmentKey:{:#x})", EnlistmentHandle, DesiredAccess, ResourceManagerHandle, TransactionHandle, ObjectAttributes, CreateOptions, NotificationMask, EnlistmentKey));

        for(const auto& it : d.observers_ZwCreateEnlistment)
            it(EnlistmentHandle, DesiredAccess, ResourceManagerHandle, TransactionHandle, ObjectAttributes, CreateOptions, NotificationMask, EnlistmentKey);
    }

    static void on_NtCreateEvent(monitor::syscallswow64::Data& d)
    {
        const auto EventHandle      = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto EventType        = arg<wntdll::EVENT_TYPE>(d.core, 3);
        const auto InitialState     = arg<wntdll::BOOLEAN>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtCreateEvent(EventHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, EventType:{:#x}, InitialState:{:#x})", EventHandle, DesiredAccess, ObjectAttributes, EventType, InitialState));

        for(const auto& it : d.observers_NtCreateEvent)
            it(EventHandle, DesiredAccess, ObjectAttributes, EventType, InitialState);
    }

    static void on_NtCreateEventPair(monitor::syscallswow64::Data& d)
    {
        const auto EventPairHandle  = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtCreateEventPair(EventPairHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x})", EventPairHandle, DesiredAccess, ObjectAttributes));

        for(const auto& it : d.observers_NtCreateEventPair)
            it(EventPairHandle, DesiredAccess, ObjectAttributes);
    }

    static void on_NtCreateFile(monitor::syscallswow64::Data& d)
    {
        const auto FileHandle        = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess     = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes  = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto IoStatusBlock     = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 3);
        const auto AllocationSize    = arg<wntdll::PLARGE_INTEGER>(d.core, 4);
        const auto FileAttributes    = arg<wntdll::ULONG>(d.core, 5);
        const auto ShareAccess       = arg<wntdll::ULONG>(d.core, 6);
        const auto CreateDisposition = arg<wntdll::ULONG>(d.core, 7);
        const auto CreateOptions     = arg<wntdll::ULONG>(d.core, 8);
        const auto EaBuffer          = arg<wntdll::PVOID>(d.core, 9);
        const auto EaLength          = arg<wntdll::ULONG>(d.core, 10);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtCreateFile(FileHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, IoStatusBlock:{:#x}, AllocationSize:{:#x}, FileAttributes:{:#x}, ShareAccess:{:#x}, CreateDisposition:{:#x}, CreateOptions:{:#x}, EaBuffer:{:#x}, EaLength:{:#x})", FileHandle, DesiredAccess, ObjectAttributes, IoStatusBlock, AllocationSize, FileAttributes, ShareAccess, CreateDisposition, CreateOptions, EaBuffer, EaLength));

        for(const auto& it : d.observers_NtCreateFile)
            it(FileHandle, DesiredAccess, ObjectAttributes, IoStatusBlock, AllocationSize, FileAttributes, ShareAccess, CreateDisposition, CreateOptions, EaBuffer, EaLength);
    }

    static void on_NtCreateIoCompletion(monitor::syscallswow64::Data& d)
    {
        const auto IoCompletionHandle = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess      = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes   = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto Count              = arg<wntdll::ULONG>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtCreateIoCompletion(IoCompletionHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, Count:{:#x})", IoCompletionHandle, DesiredAccess, ObjectAttributes, Count));

        for(const auto& it : d.observers_NtCreateIoCompletion)
            it(IoCompletionHandle, DesiredAccess, ObjectAttributes, Count);
    }

    static void on_ZwCreateJobObject(monitor::syscallswow64::Data& d)
    {
        const auto JobHandle        = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwCreateJobObject(JobHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x})", JobHandle, DesiredAccess, ObjectAttributes));

        for(const auto& it : d.observers_ZwCreateJobObject)
            it(JobHandle, DesiredAccess, ObjectAttributes);
    }

    static void on_NtCreateJobSet(monitor::syscallswow64::Data& d)
    {
        const auto NumJob     = arg<wntdll::ULONG>(d.core, 0);
        const auto UserJobSet = arg<wntdll::PJOB_SET_ARRAY>(d.core, 1);
        const auto Flags      = arg<wntdll::ULONG>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtCreateJobSet(NumJob:{:#x}, UserJobSet:{:#x}, Flags:{:#x})", NumJob, UserJobSet, Flags));

        for(const auto& it : d.observers_NtCreateJobSet)
            it(NumJob, UserJobSet, Flags);
    }

    static void on_ZwCreateKeyedEvent(monitor::syscallswow64::Data& d)
    {
        const auto KeyedEventHandle = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto Flags            = arg<wntdll::ULONG>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwCreateKeyedEvent(KeyedEventHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, Flags:{:#x})", KeyedEventHandle, DesiredAccess, ObjectAttributes, Flags));

        for(const auto& it : d.observers_ZwCreateKeyedEvent)
            it(KeyedEventHandle, DesiredAccess, ObjectAttributes, Flags);
    }

    static void on_ZwCreateKey(monitor::syscallswow64::Data& d)
    {
        const auto KeyHandle        = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto TitleIndex       = arg<wntdll::ULONG>(d.core, 3);
        const auto Class            = arg<wntdll::PUNICODE_STRING>(d.core, 4);
        const auto CreateOptions    = arg<wntdll::ULONG>(d.core, 5);
        const auto Disposition      = arg<wntdll::PULONG>(d.core, 6);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwCreateKey(KeyHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, TitleIndex:{:#x}, Class:{:#x}, CreateOptions:{:#x}, Disposition:{:#x})", KeyHandle, DesiredAccess, ObjectAttributes, TitleIndex, Class, CreateOptions, Disposition));

        for(const auto& it : d.observers_ZwCreateKey)
            it(KeyHandle, DesiredAccess, ObjectAttributes, TitleIndex, Class, CreateOptions, Disposition);
    }

    static void on_NtCreateKeyTransacted(monitor::syscallswow64::Data& d)
    {
        const auto KeyHandle         = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess     = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes  = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto TitleIndex        = arg<wntdll::ULONG>(d.core, 3);
        const auto Class             = arg<wntdll::PUNICODE_STRING>(d.core, 4);
        const auto CreateOptions     = arg<wntdll::ULONG>(d.core, 5);
        const auto TransactionHandle = arg<wntdll::HANDLE>(d.core, 6);
        const auto Disposition       = arg<wntdll::PULONG>(d.core, 7);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtCreateKeyTransacted(KeyHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, TitleIndex:{:#x}, Class:{:#x}, CreateOptions:{:#x}, TransactionHandle:{:#x}, Disposition:{:#x})", KeyHandle, DesiredAccess, ObjectAttributes, TitleIndex, Class, CreateOptions, TransactionHandle, Disposition));

        for(const auto& it : d.observers_NtCreateKeyTransacted)
            it(KeyHandle, DesiredAccess, ObjectAttributes, TitleIndex, Class, CreateOptions, TransactionHandle, Disposition);
    }

    static void on_ZwCreateMailslotFile(monitor::syscallswow64::Data& d)
    {
        const auto FileHandle         = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess      = arg<wntdll::ULONG>(d.core, 1);
        const auto ObjectAttributes   = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto IoStatusBlock      = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 3);
        const auto CreateOptions      = arg<wntdll::ULONG>(d.core, 4);
        const auto MailslotQuota      = arg<wntdll::ULONG>(d.core, 5);
        const auto MaximumMessageSize = arg<wntdll::ULONG>(d.core, 6);
        const auto ReadTimeout        = arg<wntdll::PLARGE_INTEGER>(d.core, 7);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwCreateMailslotFile(FileHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, IoStatusBlock:{:#x}, CreateOptions:{:#x}, MailslotQuota:{:#x}, MaximumMessageSize:{:#x}, ReadTimeout:{:#x})", FileHandle, DesiredAccess, ObjectAttributes, IoStatusBlock, CreateOptions, MailslotQuota, MaximumMessageSize, ReadTimeout));

        for(const auto& it : d.observers_ZwCreateMailslotFile)
            it(FileHandle, DesiredAccess, ObjectAttributes, IoStatusBlock, CreateOptions, MailslotQuota, MaximumMessageSize, ReadTimeout);
    }

    static void on_ZwCreateMutant(monitor::syscallswow64::Data& d)
    {
        const auto MutantHandle     = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto InitialOwner     = arg<wntdll::BOOLEAN>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwCreateMutant(MutantHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, InitialOwner:{:#x})", MutantHandle, DesiredAccess, ObjectAttributes, InitialOwner));

        for(const auto& it : d.observers_ZwCreateMutant)
            it(MutantHandle, DesiredAccess, ObjectAttributes, InitialOwner);
    }

    static void on_ZwCreateNamedPipeFile(monitor::syscallswow64::Data& d)
    {
        const auto FileHandle        = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess     = arg<wntdll::ULONG>(d.core, 1);
        const auto ObjectAttributes  = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto IoStatusBlock     = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 3);
        const auto ShareAccess       = arg<wntdll::ULONG>(d.core, 4);
        const auto CreateDisposition = arg<wntdll::ULONG>(d.core, 5);
        const auto CreateOptions     = arg<wntdll::ULONG>(d.core, 6);
        const auto NamedPipeType     = arg<wntdll::ULONG>(d.core, 7);
        const auto ReadMode          = arg<wntdll::ULONG>(d.core, 8);
        const auto CompletionMode    = arg<wntdll::ULONG>(d.core, 9);
        const auto MaximumInstances  = arg<wntdll::ULONG>(d.core, 10);
        const auto InboundQuota      = arg<wntdll::ULONG>(d.core, 11);
        const auto OutboundQuota     = arg<wntdll::ULONG>(d.core, 12);
        const auto DefaultTimeout    = arg<wntdll::PLARGE_INTEGER>(d.core, 13);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwCreateNamedPipeFile(FileHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, IoStatusBlock:{:#x}, ShareAccess:{:#x}, CreateDisposition:{:#x}, CreateOptions:{:#x}, NamedPipeType:{:#x}, ReadMode:{:#x}, CompletionMode:{:#x}, MaximumInstances:{:#x}, InboundQuota:{:#x}, OutboundQuota:{:#x}, DefaultTimeout:{:#x})", FileHandle, DesiredAccess, ObjectAttributes, IoStatusBlock, ShareAccess, CreateDisposition, CreateOptions, NamedPipeType, ReadMode, CompletionMode, MaximumInstances, InboundQuota, OutboundQuota, DefaultTimeout));

        for(const auto& it : d.observers_ZwCreateNamedPipeFile)
            it(FileHandle, DesiredAccess, ObjectAttributes, IoStatusBlock, ShareAccess, CreateDisposition, CreateOptions, NamedPipeType, ReadMode, CompletionMode, MaximumInstances, InboundQuota, OutboundQuota, DefaultTimeout);
    }

    static void on_NtCreatePagingFile(monitor::syscallswow64::Data& d)
    {
        const auto PageFileName = arg<wntdll::PUNICODE_STRING>(d.core, 0);
        const auto MinimumSize  = arg<wntdll::PLARGE_INTEGER>(d.core, 1);
        const auto MaximumSize  = arg<wntdll::PLARGE_INTEGER>(d.core, 2);
        const auto Priority     = arg<wntdll::ULONG>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtCreatePagingFile(PageFileName:{:#x}, MinimumSize:{:#x}, MaximumSize:{:#x}, Priority:{:#x})", PageFileName, MinimumSize, MaximumSize, Priority));

        for(const auto& it : d.observers_NtCreatePagingFile)
            it(PageFileName, MinimumSize, MaximumSize, Priority);
    }

    static void on_ZwCreatePort(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle              = arg<wntdll::PHANDLE>(d.core, 0);
        const auto ObjectAttributes        = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 1);
        const auto MaxConnectionInfoLength = arg<wntdll::ULONG>(d.core, 2);
        const auto MaxMessageLength        = arg<wntdll::ULONG>(d.core, 3);
        const auto MaxPoolUsage            = arg<wntdll::ULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwCreatePort(PortHandle:{:#x}, ObjectAttributes:{:#x}, MaxConnectionInfoLength:{:#x}, MaxMessageLength:{:#x}, MaxPoolUsage:{:#x})", PortHandle, ObjectAttributes, MaxConnectionInfoLength, MaxMessageLength, MaxPoolUsage));

        for(const auto& it : d.observers_ZwCreatePort)
            it(PortHandle, ObjectAttributes, MaxConnectionInfoLength, MaxMessageLength, MaxPoolUsage);
    }

    static void on_NtCreatePrivateNamespace(monitor::syscallswow64::Data& d)
    {
        const auto NamespaceHandle    = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess      = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes   = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto BoundaryDescriptor = arg<wntdll::PVOID>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtCreatePrivateNamespace(NamespaceHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, BoundaryDescriptor:{:#x})", NamespaceHandle, DesiredAccess, ObjectAttributes, BoundaryDescriptor));

        for(const auto& it : d.observers_NtCreatePrivateNamespace)
            it(NamespaceHandle, DesiredAccess, ObjectAttributes, BoundaryDescriptor);
    }

    static void on_ZwCreateProcessEx(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle    = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto ParentProcess    = arg<wntdll::HANDLE>(d.core, 3);
        const auto Flags            = arg<wntdll::ULONG>(d.core, 4);
        const auto SectionHandle    = arg<wntdll::HANDLE>(d.core, 5);
        const auto DebugPort        = arg<wntdll::HANDLE>(d.core, 6);
        const auto ExceptionPort    = arg<wntdll::HANDLE>(d.core, 7);
        const auto JobMemberLevel   = arg<wntdll::ULONG>(d.core, 8);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwCreateProcessEx(ProcessHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, ParentProcess:{:#x}, Flags:{:#x}, SectionHandle:{:#x}, DebugPort:{:#x}, ExceptionPort:{:#x}, JobMemberLevel:{:#x})", ProcessHandle, DesiredAccess, ObjectAttributes, ParentProcess, Flags, SectionHandle, DebugPort, ExceptionPort, JobMemberLevel));

        for(const auto& it : d.observers_ZwCreateProcessEx)
            it(ProcessHandle, DesiredAccess, ObjectAttributes, ParentProcess, Flags, SectionHandle, DebugPort, ExceptionPort, JobMemberLevel);
    }

    static void on_ZwCreateProcess(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle      = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess      = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes   = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto ParentProcess      = arg<wntdll::HANDLE>(d.core, 3);
        const auto InheritObjectTable = arg<wntdll::BOOLEAN>(d.core, 4);
        const auto SectionHandle      = arg<wntdll::HANDLE>(d.core, 5);
        const auto DebugPort          = arg<wntdll::HANDLE>(d.core, 6);
        const auto ExceptionPort      = arg<wntdll::HANDLE>(d.core, 7);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwCreateProcess(ProcessHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, ParentProcess:{:#x}, InheritObjectTable:{:#x}, SectionHandle:{:#x}, DebugPort:{:#x}, ExceptionPort:{:#x})", ProcessHandle, DesiredAccess, ObjectAttributes, ParentProcess, InheritObjectTable, SectionHandle, DebugPort, ExceptionPort));

        for(const auto& it : d.observers_ZwCreateProcess)
            it(ProcessHandle, DesiredAccess, ObjectAttributes, ParentProcess, InheritObjectTable, SectionHandle, DebugPort, ExceptionPort);
    }

    static void on_NtCreateProfileEx(monitor::syscallswow64::Data& d)
    {
        const auto ProfileHandle      = arg<wntdll::PHANDLE>(d.core, 0);
        const auto Process            = arg<wntdll::HANDLE>(d.core, 1);
        const auto ProfileBase        = arg<wntdll::PVOID>(d.core, 2);
        const auto ProfileSize        = arg<wntdll::SIZE_T>(d.core, 3);
        const auto BucketSize         = arg<wntdll::ULONG>(d.core, 4);
        const auto Buffer             = arg<wntdll::PULONG>(d.core, 5);
        const auto BufferSize         = arg<wntdll::ULONG>(d.core, 6);
        const auto ProfileSource      = arg<wntdll::KPROFILE_SOURCE>(d.core, 7);
        const auto GroupAffinityCount = arg<wntdll::ULONG>(d.core, 8);
        const auto GroupAffinity      = arg<wntdll::PGROUP_AFFINITY>(d.core, 9);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtCreateProfileEx(ProfileHandle:{:#x}, Process:{:#x}, ProfileBase:{:#x}, ProfileSize:{:#x}, BucketSize:{:#x}, Buffer:{:#x}, BufferSize:{:#x}, ProfileSource:{:#x}, GroupAffinityCount:{:#x}, GroupAffinity:{:#x})", ProfileHandle, Process, ProfileBase, ProfileSize, BucketSize, Buffer, BufferSize, ProfileSource, GroupAffinityCount, GroupAffinity));

        for(const auto& it : d.observers_NtCreateProfileEx)
            it(ProfileHandle, Process, ProfileBase, ProfileSize, BucketSize, Buffer, BufferSize, ProfileSource, GroupAffinityCount, GroupAffinity);
    }

    static void on_ZwCreateProfile(monitor::syscallswow64::Data& d)
    {
        const auto ProfileHandle = arg<wntdll::PHANDLE>(d.core, 0);
        const auto Process       = arg<wntdll::HANDLE>(d.core, 1);
        const auto RangeBase     = arg<wntdll::PVOID>(d.core, 2);
        const auto RangeSize     = arg<wntdll::SIZE_T>(d.core, 3);
        const auto BucketSize    = arg<wntdll::ULONG>(d.core, 4);
        const auto Buffer        = arg<wntdll::PULONG>(d.core, 5);
        const auto BufferSize    = arg<wntdll::ULONG>(d.core, 6);
        const auto ProfileSource = arg<wntdll::KPROFILE_SOURCE>(d.core, 7);
        const auto Affinity      = arg<wntdll::KAFFINITY>(d.core, 8);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwCreateProfile(ProfileHandle:{:#x}, Process:{:#x}, RangeBase:{:#x}, RangeSize:{:#x}, BucketSize:{:#x}, Buffer:{:#x}, BufferSize:{:#x}, ProfileSource:{:#x}, Affinity:{:#x})", ProfileHandle, Process, RangeBase, RangeSize, BucketSize, Buffer, BufferSize, ProfileSource, Affinity));

        for(const auto& it : d.observers_ZwCreateProfile)
            it(ProfileHandle, Process, RangeBase, RangeSize, BucketSize, Buffer, BufferSize, ProfileSource, Affinity);
    }

    static void on_ZwCreateResourceManager(monitor::syscallswow64::Data& d)
    {
        const auto ResourceManagerHandle = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess         = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto TmHandle              = arg<wntdll::HANDLE>(d.core, 2);
        const auto RmGuid                = arg<wntdll::LPGUID>(d.core, 3);
        const auto ObjectAttributes      = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 4);
        const auto CreateOptions         = arg<wntdll::ULONG>(d.core, 5);
        const auto Description           = arg<wntdll::PUNICODE_STRING>(d.core, 6);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwCreateResourceManager(ResourceManagerHandle:{:#x}, DesiredAccess:{:#x}, TmHandle:{:#x}, RmGuid:{:#x}, ObjectAttributes:{:#x}, CreateOptions:{:#x}, Description:{:#x})", ResourceManagerHandle, DesiredAccess, TmHandle, RmGuid, ObjectAttributes, CreateOptions, Description));

        for(const auto& it : d.observers_ZwCreateResourceManager)
            it(ResourceManagerHandle, DesiredAccess, TmHandle, RmGuid, ObjectAttributes, CreateOptions, Description);
    }

    static void on_NtCreateSection(monitor::syscallswow64::Data& d)
    {
        const auto SectionHandle         = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess         = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes      = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto MaximumSize           = arg<wntdll::PLARGE_INTEGER>(d.core, 3);
        const auto SectionPageProtection = arg<wntdll::ULONG>(d.core, 4);
        const auto AllocationAttributes  = arg<wntdll::ULONG>(d.core, 5);
        const auto FileHandle            = arg<wntdll::HANDLE>(d.core, 6);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtCreateSection(SectionHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, MaximumSize:{:#x}, SectionPageProtection:{:#x}, AllocationAttributes:{:#x}, FileHandle:{:#x})", SectionHandle, DesiredAccess, ObjectAttributes, MaximumSize, SectionPageProtection, AllocationAttributes, FileHandle));

        for(const auto& it : d.observers_NtCreateSection)
            it(SectionHandle, DesiredAccess, ObjectAttributes, MaximumSize, SectionPageProtection, AllocationAttributes, FileHandle);
    }

    static void on_NtCreateSemaphore(monitor::syscallswow64::Data& d)
    {
        const auto SemaphoreHandle  = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto InitialCount     = arg<wntdll::LONG>(d.core, 3);
        const auto MaximumCount     = arg<wntdll::LONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtCreateSemaphore(SemaphoreHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, InitialCount:{:#x}, MaximumCount:{:#x})", SemaphoreHandle, DesiredAccess, ObjectAttributes, InitialCount, MaximumCount));

        for(const auto& it : d.observers_NtCreateSemaphore)
            it(SemaphoreHandle, DesiredAccess, ObjectAttributes, InitialCount, MaximumCount);
    }

    static void on_ZwCreateSymbolicLinkObject(monitor::syscallswow64::Data& d)
    {
        const auto LinkHandle       = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto LinkTarget       = arg<wntdll::PUNICODE_STRING>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwCreateSymbolicLinkObject(LinkHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, LinkTarget:{:#x})", LinkHandle, DesiredAccess, ObjectAttributes, LinkTarget));

        for(const auto& it : d.observers_ZwCreateSymbolicLinkObject)
            it(LinkHandle, DesiredAccess, ObjectAttributes, LinkTarget);
    }

    static void on_NtCreateThreadEx(monitor::syscallswow64::Data& d)
    {
        const auto ThreadHandle     = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto ProcessHandle    = arg<wntdll::HANDLE>(d.core, 3);
        const auto StartRoutine     = arg<wntdll::PVOID>(d.core, 4);
        const auto Argument         = arg<wntdll::PVOID>(d.core, 5);
        const auto CreateFlags      = arg<wntdll::ULONG>(d.core, 6);
        const auto ZeroBits         = arg<wntdll::ULONG_PTR>(d.core, 7);
        const auto StackSize        = arg<wntdll::SIZE_T>(d.core, 8);
        const auto MaximumStackSize = arg<wntdll::SIZE_T>(d.core, 9);
        const auto AttributeList    = arg<wntdll::PPS_ATTRIBUTE_LIST>(d.core, 10);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtCreateThreadEx(ThreadHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, ProcessHandle:{:#x}, StartRoutine:{:#x}, Argument:{:#x}, CreateFlags:{:#x}, ZeroBits:{:#x}, StackSize:{:#x}, MaximumStackSize:{:#x}, AttributeList:{:#x})", ThreadHandle, DesiredAccess, ObjectAttributes, ProcessHandle, StartRoutine, Argument, CreateFlags, ZeroBits, StackSize, MaximumStackSize, AttributeList));

        for(const auto& it : d.observers_NtCreateThreadEx)
            it(ThreadHandle, DesiredAccess, ObjectAttributes, ProcessHandle, StartRoutine, Argument, CreateFlags, ZeroBits, StackSize, MaximumStackSize, AttributeList);
    }

    static void on_NtCreateThread(monitor::syscallswow64::Data& d)
    {
        const auto ThreadHandle     = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto ProcessHandle    = arg<wntdll::HANDLE>(d.core, 3);
        const auto ClientId         = arg<wntdll::PCLIENT_ID>(d.core, 4);
        const auto ThreadContext    = arg<wntdll::PCONTEXT>(d.core, 5);
        const auto InitialTeb       = arg<wntdll::PINITIAL_TEB>(d.core, 6);
        const auto CreateSuspended  = arg<wntdll::BOOLEAN>(d.core, 7);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtCreateThread(ThreadHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, ProcessHandle:{:#x}, ClientId:{:#x}, ThreadContext:{:#x}, InitialTeb:{:#x}, CreateSuspended:{:#x})", ThreadHandle, DesiredAccess, ObjectAttributes, ProcessHandle, ClientId, ThreadContext, InitialTeb, CreateSuspended));

        for(const auto& it : d.observers_NtCreateThread)
            it(ThreadHandle, DesiredAccess, ObjectAttributes, ProcessHandle, ClientId, ThreadContext, InitialTeb, CreateSuspended);
    }

    static void on_ZwCreateTimer(monitor::syscallswow64::Data& d)
    {
        const auto TimerHandle      = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto TimerType        = arg<wntdll::TIMER_TYPE>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwCreateTimer(TimerHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, TimerType:{:#x})", TimerHandle, DesiredAccess, ObjectAttributes, TimerType));

        for(const auto& it : d.observers_ZwCreateTimer)
            it(TimerHandle, DesiredAccess, ObjectAttributes, TimerType);
    }

    static void on_NtCreateToken(monitor::syscallswow64::Data& d)
    {
        const auto TokenHandle      = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto TokenType        = arg<wntdll::TOKEN_TYPE>(d.core, 3);
        const auto AuthenticationId = arg<wntdll::PLUID>(d.core, 4);
        const auto ExpirationTime   = arg<wntdll::PLARGE_INTEGER>(d.core, 5);
        const auto User             = arg<wntdll::PTOKEN_USER>(d.core, 6);
        const auto Groups           = arg<wntdll::PTOKEN_GROUPS>(d.core, 7);
        const auto Privileges       = arg<wntdll::PTOKEN_PRIVILEGES>(d.core, 8);
        const auto Owner            = arg<wntdll::PTOKEN_OWNER>(d.core, 9);
        const auto PrimaryGroup     = arg<wntdll::PTOKEN_PRIMARY_GROUP>(d.core, 10);
        const auto DefaultDacl      = arg<wntdll::PTOKEN_DEFAULT_DACL>(d.core, 11);
        const auto TokenSource      = arg<wntdll::PTOKEN_SOURCE>(d.core, 12);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtCreateToken(TokenHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, TokenType:{:#x}, AuthenticationId:{:#x}, ExpirationTime:{:#x}, User:{:#x}, Groups:{:#x}, Privileges:{:#x}, Owner:{:#x}, PrimaryGroup:{:#x}, DefaultDacl:{:#x}, TokenSource:{:#x})", TokenHandle, DesiredAccess, ObjectAttributes, TokenType, AuthenticationId, ExpirationTime, User, Groups, Privileges, Owner, PrimaryGroup, DefaultDacl, TokenSource));

        for(const auto& it : d.observers_NtCreateToken)
            it(TokenHandle, DesiredAccess, ObjectAttributes, TokenType, AuthenticationId, ExpirationTime, User, Groups, Privileges, Owner, PrimaryGroup, DefaultDacl, TokenSource);
    }

    static void on_ZwCreateTransactionManager(monitor::syscallswow64::Data& d)
    {
        const auto TmHandle         = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto LogFileName      = arg<wntdll::PUNICODE_STRING>(d.core, 3);
        const auto CreateOptions    = arg<wntdll::ULONG>(d.core, 4);
        const auto CommitStrength   = arg<wntdll::ULONG>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwCreateTransactionManager(TmHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, LogFileName:{:#x}, CreateOptions:{:#x}, CommitStrength:{:#x})", TmHandle, DesiredAccess, ObjectAttributes, LogFileName, CreateOptions, CommitStrength));

        for(const auto& it : d.observers_ZwCreateTransactionManager)
            it(TmHandle, DesiredAccess, ObjectAttributes, LogFileName, CreateOptions, CommitStrength);
    }

    static void on_NtCreateTransaction(monitor::syscallswow64::Data& d)
    {
        const auto TransactionHandle = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess     = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes  = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto Uow               = arg<wntdll::LPGUID>(d.core, 3);
        const auto TmHandle          = arg<wntdll::HANDLE>(d.core, 4);
        const auto CreateOptions     = arg<wntdll::ULONG>(d.core, 5);
        const auto IsolationLevel    = arg<wntdll::ULONG>(d.core, 6);
        const auto IsolationFlags    = arg<wntdll::ULONG>(d.core, 7);
        const auto Timeout           = arg<wntdll::PLARGE_INTEGER>(d.core, 8);
        const auto Description       = arg<wntdll::PUNICODE_STRING>(d.core, 9);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtCreateTransaction(TransactionHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, Uow:{:#x}, TmHandle:{:#x}, CreateOptions:{:#x}, IsolationLevel:{:#x}, IsolationFlags:{:#x}, Timeout:{:#x}, Description:{:#x})", TransactionHandle, DesiredAccess, ObjectAttributes, Uow, TmHandle, CreateOptions, IsolationLevel, IsolationFlags, Timeout, Description));

        for(const auto& it : d.observers_NtCreateTransaction)
            it(TransactionHandle, DesiredAccess, ObjectAttributes, Uow, TmHandle, CreateOptions, IsolationLevel, IsolationFlags, Timeout, Description);
    }

    static void on_NtCreateUserProcess(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle           = arg<wntdll::PHANDLE>(d.core, 0);
        const auto ThreadHandle            = arg<wntdll::PHANDLE>(d.core, 1);
        const auto ProcessDesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 2);
        const auto ThreadDesiredAccess     = arg<wntdll::ACCESS_MASK>(d.core, 3);
        const auto ProcessObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 4);
        const auto ThreadObjectAttributes  = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 5);
        const auto ProcessFlags            = arg<wntdll::ULONG>(d.core, 6);
        const auto ThreadFlags             = arg<wntdll::ULONG>(d.core, 7);
        const auto ProcessParameters       = arg<wntdll::PRTL_USER_PROCESS_PARAMETERS>(d.core, 8);
        const auto CreateInfo              = arg<wntdll::PPROCESS_CREATE_INFO>(d.core, 9);
        const auto AttributeList           = arg<wntdll::PPROCESS_ATTRIBUTE_LIST>(d.core, 10);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtCreateUserProcess(ProcessHandle:{:#x}, ThreadHandle:{:#x}, ProcessDesiredAccess:{:#x}, ThreadDesiredAccess:{:#x}, ProcessObjectAttributes:{:#x}, ThreadObjectAttributes:{:#x}, ProcessFlags:{:#x}, ThreadFlags:{:#x}, ProcessParameters:{:#x}, CreateInfo:{:#x}, AttributeList:{:#x})", ProcessHandle, ThreadHandle, ProcessDesiredAccess, ThreadDesiredAccess, ProcessObjectAttributes, ThreadObjectAttributes, ProcessFlags, ThreadFlags, ProcessParameters, CreateInfo, AttributeList));

        for(const auto& it : d.observers_NtCreateUserProcess)
            it(ProcessHandle, ThreadHandle, ProcessDesiredAccess, ThreadDesiredAccess, ProcessObjectAttributes, ThreadObjectAttributes, ProcessFlags, ThreadFlags, ProcessParameters, CreateInfo, AttributeList);
    }

    static void on_ZwCreateWaitablePort(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle              = arg<wntdll::PHANDLE>(d.core, 0);
        const auto ObjectAttributes        = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 1);
        const auto MaxConnectionInfoLength = arg<wntdll::ULONG>(d.core, 2);
        const auto MaxMessageLength        = arg<wntdll::ULONG>(d.core, 3);
        const auto MaxPoolUsage            = arg<wntdll::ULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwCreateWaitablePort(PortHandle:{:#x}, ObjectAttributes:{:#x}, MaxConnectionInfoLength:{:#x}, MaxMessageLength:{:#x}, MaxPoolUsage:{:#x})", PortHandle, ObjectAttributes, MaxConnectionInfoLength, MaxMessageLength, MaxPoolUsage));

        for(const auto& it : d.observers_ZwCreateWaitablePort)
            it(PortHandle, ObjectAttributes, MaxConnectionInfoLength, MaxMessageLength, MaxPoolUsage);
    }

    static void on_NtCreateWorkerFactory(monitor::syscallswow64::Data& d)
    {
        const auto WorkerFactoryHandleReturn = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess             = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes          = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto CompletionPortHandle      = arg<wntdll::HANDLE>(d.core, 3);
        const auto WorkerProcessHandle       = arg<wntdll::HANDLE>(d.core, 4);
        const auto StartRoutine              = arg<wntdll::PVOID>(d.core, 5);
        const auto StartParameter            = arg<wntdll::PVOID>(d.core, 6);
        const auto MaxThreadCount            = arg<wntdll::ULONG>(d.core, 7);
        const auto StackReserve              = arg<wntdll::SIZE_T>(d.core, 8);
        const auto StackCommit               = arg<wntdll::SIZE_T>(d.core, 9);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtCreateWorkerFactory(WorkerFactoryHandleReturn:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, CompletionPortHandle:{:#x}, WorkerProcessHandle:{:#x}, StartRoutine:{:#x}, StartParameter:{:#x}, MaxThreadCount:{:#x}, StackReserve:{:#x}, StackCommit:{:#x})", WorkerFactoryHandleReturn, DesiredAccess, ObjectAttributes, CompletionPortHandle, WorkerProcessHandle, StartRoutine, StartParameter, MaxThreadCount, StackReserve, StackCommit));

        for(const auto& it : d.observers_NtCreateWorkerFactory)
            it(WorkerFactoryHandleReturn, DesiredAccess, ObjectAttributes, CompletionPortHandle, WorkerProcessHandle, StartRoutine, StartParameter, MaxThreadCount, StackReserve, StackCommit);
    }

    static void on_NtDebugActiveProcess(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle     = arg<wntdll::HANDLE>(d.core, 0);
        const auto DebugObjectHandle = arg<wntdll::HANDLE>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtDebugActiveProcess(ProcessHandle:{:#x}, DebugObjectHandle:{:#x})", ProcessHandle, DebugObjectHandle));

        for(const auto& it : d.observers_NtDebugActiveProcess)
            it(ProcessHandle, DebugObjectHandle);
    }

    static void on_ZwDebugContinue(monitor::syscallswow64::Data& d)
    {
        const auto DebugObjectHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto ClientId          = arg<wntdll::PCLIENT_ID>(d.core, 1);
        const auto ContinueStatus    = arg<wntdll::NTSTATUS>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwDebugContinue(DebugObjectHandle:{:#x}, ClientId:{:#x}, ContinueStatus:{:#x})", DebugObjectHandle, ClientId, ContinueStatus));

        for(const auto& it : d.observers_ZwDebugContinue)
            it(DebugObjectHandle, ClientId, ContinueStatus);
    }

    static void on_ZwDelayExecution(monitor::syscallswow64::Data& d)
    {
        const auto Alertable     = arg<wntdll::BOOLEAN>(d.core, 0);
        const auto DelayInterval = arg<wntdll::PLARGE_INTEGER>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwDelayExecution(Alertable:{:#x}, DelayInterval:{:#x})", Alertable, DelayInterval));

        for(const auto& it : d.observers_ZwDelayExecution)
            it(Alertable, DelayInterval);
    }

    static void on_ZwDeleteAtom(monitor::syscallswow64::Data& d)
    {
        const auto Atom = arg<wntdll::RTL_ATOM>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwDeleteAtom(Atom:{:#x})", Atom));

        for(const auto& it : d.observers_ZwDeleteAtom)
            it(Atom);
    }

    static void on_NtDeleteBootEntry(monitor::syscallswow64::Data& d)
    {
        const auto Id = arg<wntdll::ULONG>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtDeleteBootEntry(Id:{:#x})", Id));

        for(const auto& it : d.observers_NtDeleteBootEntry)
            it(Id);
    }

    static void on_ZwDeleteDriverEntry(monitor::syscallswow64::Data& d)
    {
        const auto Id = arg<wntdll::ULONG>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwDeleteDriverEntry(Id:{:#x})", Id));

        for(const auto& it : d.observers_ZwDeleteDriverEntry)
            it(Id);
    }

    static void on_NtDeleteFile(monitor::syscallswow64::Data& d)
    {
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtDeleteFile(ObjectAttributes:{:#x})", ObjectAttributes));

        for(const auto& it : d.observers_NtDeleteFile)
            it(ObjectAttributes);
    }

    static void on_ZwDeleteKey(monitor::syscallswow64::Data& d)
    {
        const auto KeyHandle = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwDeleteKey(KeyHandle:{:#x})", KeyHandle));

        for(const auto& it : d.observers_ZwDeleteKey)
            it(KeyHandle);
    }

    static void on_NtDeleteObjectAuditAlarm(monitor::syscallswow64::Data& d)
    {
        const auto SubsystemName   = arg<wntdll::PUNICODE_STRING>(d.core, 0);
        const auto HandleId        = arg<wntdll::PVOID>(d.core, 1);
        const auto GenerateOnClose = arg<wntdll::BOOLEAN>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtDeleteObjectAuditAlarm(SubsystemName:{:#x}, HandleId:{:#x}, GenerateOnClose:{:#x})", SubsystemName, HandleId, GenerateOnClose));

        for(const auto& it : d.observers_NtDeleteObjectAuditAlarm)
            it(SubsystemName, HandleId, GenerateOnClose);
    }

    static void on_NtDeletePrivateNamespace(monitor::syscallswow64::Data& d)
    {
        const auto NamespaceHandle = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtDeletePrivateNamespace(NamespaceHandle:{:#x})", NamespaceHandle));

        for(const auto& it : d.observers_NtDeletePrivateNamespace)
            it(NamespaceHandle);
    }

    static void on_NtDeleteValueKey(monitor::syscallswow64::Data& d)
    {
        const auto KeyHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto ValueName = arg<wntdll::PUNICODE_STRING>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtDeleteValueKey(KeyHandle:{:#x}, ValueName:{:#x})", KeyHandle, ValueName));

        for(const auto& it : d.observers_NtDeleteValueKey)
            it(KeyHandle, ValueName);
    }

    static void on_ZwDeviceIoControlFile(monitor::syscallswow64::Data& d)
    {
        const auto FileHandle         = arg<wntdll::HANDLE>(d.core, 0);
        const auto Event              = arg<wntdll::HANDLE>(d.core, 1);
        const auto ApcRoutine         = arg<wntdll::PIO_APC_ROUTINE>(d.core, 2);
        const auto ApcContext         = arg<wntdll::PVOID>(d.core, 3);
        const auto IoStatusBlock      = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 4);
        const auto IoControlCode      = arg<wntdll::ULONG>(d.core, 5);
        const auto InputBuffer        = arg<wntdll::PVOID>(d.core, 6);
        const auto InputBufferLength  = arg<wntdll::ULONG>(d.core, 7);
        const auto OutputBuffer       = arg<wntdll::PVOID>(d.core, 8);
        const auto OutputBufferLength = arg<wntdll::ULONG>(d.core, 9);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwDeviceIoControlFile(FileHandle:{:#x}, Event:{:#x}, ApcRoutine:{:#x}, ApcContext:{:#x}, IoStatusBlock:{:#x}, IoControlCode:{:#x}, InputBuffer:{:#x}, InputBufferLength:{:#x}, OutputBuffer:{:#x}, OutputBufferLength:{:#x})", FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, IoControlCode, InputBuffer, InputBufferLength, OutputBuffer, OutputBufferLength));

        for(const auto& it : d.observers_ZwDeviceIoControlFile)
            it(FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, IoControlCode, InputBuffer, InputBufferLength, OutputBuffer, OutputBufferLength);
    }

    static void on_NtDisplayString(monitor::syscallswow64::Data& d)
    {
        const auto String = arg<wntdll::PUNICODE_STRING>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtDisplayString(String:{:#x})", String));

        for(const auto& it : d.observers_NtDisplayString)
            it(String);
    }

    static void on_ZwDrawText(monitor::syscallswow64::Data& d)
    {
        const auto Text = arg<wntdll::PUNICODE_STRING>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwDrawText(Text:{:#x})", Text));

        for(const auto& it : d.observers_ZwDrawText)
            it(Text);
    }

    static void on_ZwDuplicateObject(monitor::syscallswow64::Data& d)
    {
        const auto SourceProcessHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto SourceHandle        = arg<wntdll::HANDLE>(d.core, 1);
        const auto TargetProcessHandle = arg<wntdll::HANDLE>(d.core, 2);
        const auto TargetHandle        = arg<wntdll::PHANDLE>(d.core, 3);
        const auto DesiredAccess       = arg<wntdll::ACCESS_MASK>(d.core, 4);
        const auto HandleAttributes    = arg<wntdll::ULONG>(d.core, 5);
        const auto Options             = arg<wntdll::ULONG>(d.core, 6);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwDuplicateObject(SourceProcessHandle:{:#x}, SourceHandle:{:#x}, TargetProcessHandle:{:#x}, TargetHandle:{:#x}, DesiredAccess:{:#x}, HandleAttributes:{:#x}, Options:{:#x})", SourceProcessHandle, SourceHandle, TargetProcessHandle, TargetHandle, DesiredAccess, HandleAttributes, Options));

        for(const auto& it : d.observers_ZwDuplicateObject)
            it(SourceProcessHandle, SourceHandle, TargetProcessHandle, TargetHandle, DesiredAccess, HandleAttributes, Options);
    }

    static void on_NtDuplicateToken(monitor::syscallswow64::Data& d)
    {
        const auto ExistingTokenHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto DesiredAccess       = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes    = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto EffectiveOnly       = arg<wntdll::BOOLEAN>(d.core, 3);
        const auto TokenType           = arg<wntdll::TOKEN_TYPE>(d.core, 4);
        const auto NewTokenHandle      = arg<wntdll::PHANDLE>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtDuplicateToken(ExistingTokenHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, EffectiveOnly:{:#x}, TokenType:{:#x}, NewTokenHandle:{:#x})", ExistingTokenHandle, DesiredAccess, ObjectAttributes, EffectiveOnly, TokenType, NewTokenHandle));

        for(const auto& it : d.observers_NtDuplicateToken)
            it(ExistingTokenHandle, DesiredAccess, ObjectAttributes, EffectiveOnly, TokenType, NewTokenHandle);
    }

    static void on_ZwEnumerateBootEntries(monitor::syscallswow64::Data& d)
    {
        const auto Buffer       = arg<wntdll::PVOID>(d.core, 0);
        const auto BufferLength = arg<wntdll::PULONG>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwEnumerateBootEntries(Buffer:{:#x}, BufferLength:{:#x})", Buffer, BufferLength));

        for(const auto& it : d.observers_ZwEnumerateBootEntries)
            it(Buffer, BufferLength);
    }

    static void on_NtEnumerateDriverEntries(monitor::syscallswow64::Data& d)
    {
        const auto Buffer       = arg<wntdll::PVOID>(d.core, 0);
        const auto BufferLength = arg<wntdll::PULONG>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtEnumerateDriverEntries(Buffer:{:#x}, BufferLength:{:#x})", Buffer, BufferLength));

        for(const auto& it : d.observers_NtEnumerateDriverEntries)
            it(Buffer, BufferLength);
    }

    static void on_ZwEnumerateKey(monitor::syscallswow64::Data& d)
    {
        const auto KeyHandle           = arg<wntdll::HANDLE>(d.core, 0);
        const auto Index               = arg<wntdll::ULONG>(d.core, 1);
        const auto KeyInformationClass = arg<wntdll::KEY_INFORMATION_CLASS>(d.core, 2);
        const auto KeyInformation      = arg<wntdll::PVOID>(d.core, 3);
        const auto Length              = arg<wntdll::ULONG>(d.core, 4);
        const auto ResultLength        = arg<wntdll::PULONG>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwEnumerateKey(KeyHandle:{:#x}, Index:{:#x}, KeyInformationClass:{:#x}, KeyInformation:{:#x}, Length:{:#x}, ResultLength:{:#x})", KeyHandle, Index, KeyInformationClass, KeyInformation, Length, ResultLength));

        for(const auto& it : d.observers_ZwEnumerateKey)
            it(KeyHandle, Index, KeyInformationClass, KeyInformation, Length, ResultLength);
    }

    static void on_ZwEnumerateSystemEnvironmentValuesEx(monitor::syscallswow64::Data& d)
    {
        const auto InformationClass = arg<wntdll::ULONG>(d.core, 0);
        const auto Buffer           = arg<wntdll::PVOID>(d.core, 1);
        const auto BufferLength     = arg<wntdll::PULONG>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwEnumerateSystemEnvironmentValuesEx(InformationClass:{:#x}, Buffer:{:#x}, BufferLength:{:#x})", InformationClass, Buffer, BufferLength));

        for(const auto& it : d.observers_ZwEnumerateSystemEnvironmentValuesEx)
            it(InformationClass, Buffer, BufferLength);
    }

    static void on_ZwEnumerateTransactionObject(monitor::syscallswow64::Data& d)
    {
        const auto RootObjectHandle   = arg<wntdll::HANDLE>(d.core, 0);
        const auto QueryType          = arg<wntdll::KTMOBJECT_TYPE>(d.core, 1);
        const auto ObjectCursor       = arg<wntdll::PKTMOBJECT_CURSOR>(d.core, 2);
        const auto ObjectCursorLength = arg<wntdll::ULONG>(d.core, 3);
        const auto ReturnLength       = arg<wntdll::PULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwEnumerateTransactionObject(RootObjectHandle:{:#x}, QueryType:{:#x}, ObjectCursor:{:#x}, ObjectCursorLength:{:#x}, ReturnLength:{:#x})", RootObjectHandle, QueryType, ObjectCursor, ObjectCursorLength, ReturnLength));

        for(const auto& it : d.observers_ZwEnumerateTransactionObject)
            it(RootObjectHandle, QueryType, ObjectCursor, ObjectCursorLength, ReturnLength);
    }

    static void on_NtEnumerateValueKey(monitor::syscallswow64::Data& d)
    {
        const auto KeyHandle                = arg<wntdll::HANDLE>(d.core, 0);
        const auto Index                    = arg<wntdll::ULONG>(d.core, 1);
        const auto KeyValueInformationClass = arg<wntdll::KEY_VALUE_INFORMATION_CLASS>(d.core, 2);
        const auto KeyValueInformation      = arg<wntdll::PVOID>(d.core, 3);
        const auto Length                   = arg<wntdll::ULONG>(d.core, 4);
        const auto ResultLength             = arg<wntdll::PULONG>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtEnumerateValueKey(KeyHandle:{:#x}, Index:{:#x}, KeyValueInformationClass:{:#x}, KeyValueInformation:{:#x}, Length:{:#x}, ResultLength:{:#x})", KeyHandle, Index, KeyValueInformationClass, KeyValueInformation, Length, ResultLength));

        for(const auto& it : d.observers_NtEnumerateValueKey)
            it(KeyHandle, Index, KeyValueInformationClass, KeyValueInformation, Length, ResultLength);
    }

    static void on_ZwExtendSection(monitor::syscallswow64::Data& d)
    {
        const auto SectionHandle  = arg<wntdll::HANDLE>(d.core, 0);
        const auto NewSectionSize = arg<wntdll::PLARGE_INTEGER>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwExtendSection(SectionHandle:{:#x}, NewSectionSize:{:#x})", SectionHandle, NewSectionSize));

        for(const auto& it : d.observers_ZwExtendSection)
            it(SectionHandle, NewSectionSize);
    }

    static void on_NtFilterToken(monitor::syscallswow64::Data& d)
    {
        const auto ExistingTokenHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto Flags               = arg<wntdll::ULONG>(d.core, 1);
        const auto SidsToDisable       = arg<wntdll::PTOKEN_GROUPS>(d.core, 2);
        const auto PrivilegesToDelete  = arg<wntdll::PTOKEN_PRIVILEGES>(d.core, 3);
        const auto RestrictedSids      = arg<wntdll::PTOKEN_GROUPS>(d.core, 4);
        const auto NewTokenHandle      = arg<wntdll::PHANDLE>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtFilterToken(ExistingTokenHandle:{:#x}, Flags:{:#x}, SidsToDisable:{:#x}, PrivilegesToDelete:{:#x}, RestrictedSids:{:#x}, NewTokenHandle:{:#x})", ExistingTokenHandle, Flags, SidsToDisable, PrivilegesToDelete, RestrictedSids, NewTokenHandle));

        for(const auto& it : d.observers_NtFilterToken)
            it(ExistingTokenHandle, Flags, SidsToDisable, PrivilegesToDelete, RestrictedSids, NewTokenHandle);
    }

    static void on_NtFindAtom(monitor::syscallswow64::Data& d)
    {
        const auto AtomName = arg<wntdll::PWSTR>(d.core, 0);
        const auto Length   = arg<wntdll::ULONG>(d.core, 1);
        const auto Atom     = arg<wntdll::PRTL_ATOM>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtFindAtom(AtomName:{:#x}, Length:{:#x}, Atom:{:#x})", AtomName, Length, Atom));

        for(const auto& it : d.observers_NtFindAtom)
            it(AtomName, Length, Atom);
    }

    static void on_ZwFlushBuffersFile(monitor::syscallswow64::Data& d)
    {
        const auto FileHandle    = arg<wntdll::HANDLE>(d.core, 0);
        const auto IoStatusBlock = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwFlushBuffersFile(FileHandle:{:#x}, IoStatusBlock:{:#x})", FileHandle, IoStatusBlock));

        for(const auto& it : d.observers_ZwFlushBuffersFile)
            it(FileHandle, IoStatusBlock);
    }

    static void on_ZwFlushInstallUILanguage(monitor::syscallswow64::Data& d)
    {
        const auto InstallUILanguage = arg<wntdll::LANGID>(d.core, 0);
        const auto SetComittedFlag   = arg<wntdll::ULONG>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwFlushInstallUILanguage(InstallUILanguage:{:#x}, SetComittedFlag:{:#x})", InstallUILanguage, SetComittedFlag));

        for(const auto& it : d.observers_ZwFlushInstallUILanguage)
            it(InstallUILanguage, SetComittedFlag);
    }

    static void on_ZwFlushInstructionCache(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto BaseAddress   = arg<wntdll::PVOID>(d.core, 1);
        const auto Length        = arg<wntdll::SIZE_T>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwFlushInstructionCache(ProcessHandle:{:#x}, BaseAddress:{:#x}, Length:{:#x})", ProcessHandle, BaseAddress, Length));

        for(const auto& it : d.observers_ZwFlushInstructionCache)
            it(ProcessHandle, BaseAddress, Length);
    }

    static void on_NtFlushKey(monitor::syscallswow64::Data& d)
    {
        const auto KeyHandle = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtFlushKey(KeyHandle:{:#x})", KeyHandle));

        for(const auto& it : d.observers_NtFlushKey)
            it(KeyHandle);
    }

    static void on_ZwFlushVirtualMemory(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle   = arg<wntdll::HANDLE>(d.core, 0);
        const auto STARBaseAddress = arg<wntdll::PVOID>(d.core, 1);
        const auto RegionSize      = arg<wntdll::PSIZE_T>(d.core, 2);
        const auto IoStatus        = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwFlushVirtualMemory(ProcessHandle:{:#x}, STARBaseAddress:{:#x}, RegionSize:{:#x}, IoStatus:{:#x})", ProcessHandle, STARBaseAddress, RegionSize, IoStatus));

        for(const auto& it : d.observers_ZwFlushVirtualMemory)
            it(ProcessHandle, STARBaseAddress, RegionSize, IoStatus);
    }

    static void on_NtFreeUserPhysicalPages(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto NumberOfPages = arg<wntdll::PULONG_PTR>(d.core, 1);
        const auto UserPfnArra   = arg<wntdll::PULONG_PTR>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtFreeUserPhysicalPages(ProcessHandle:{:#x}, NumberOfPages:{:#x}, UserPfnArra:{:#x})", ProcessHandle, NumberOfPages, UserPfnArra));

        for(const auto& it : d.observers_NtFreeUserPhysicalPages)
            it(ProcessHandle, NumberOfPages, UserPfnArra);
    }

    static void on_NtFreeVirtualMemory(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle   = arg<wntdll::HANDLE>(d.core, 0);
        const auto STARBaseAddress = arg<wntdll::PVOID>(d.core, 1);
        const auto RegionSize      = arg<wntdll::PSIZE_T>(d.core, 2);
        const auto FreeType        = arg<wntdll::ULONG>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtFreeVirtualMemory(ProcessHandle:{:#x}, STARBaseAddress:{:#x}, RegionSize:{:#x}, FreeType:{:#x})", ProcessHandle, STARBaseAddress, RegionSize, FreeType));

        for(const auto& it : d.observers_NtFreeVirtualMemory)
            it(ProcessHandle, STARBaseAddress, RegionSize, FreeType);
    }

    static void on_NtFreezeRegistry(monitor::syscallswow64::Data& d)
    {
        const auto TimeOutInSeconds = arg<wntdll::ULONG>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtFreezeRegistry(TimeOutInSeconds:{:#x})", TimeOutInSeconds));

        for(const auto& it : d.observers_NtFreezeRegistry)
            it(TimeOutInSeconds);
    }

    static void on_ZwFreezeTransactions(monitor::syscallswow64::Data& d)
    {
        const auto FreezeTimeout = arg<wntdll::PLARGE_INTEGER>(d.core, 0);
        const auto ThawTimeout   = arg<wntdll::PLARGE_INTEGER>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwFreezeTransactions(FreezeTimeout:{:#x}, ThawTimeout:{:#x})", FreezeTimeout, ThawTimeout));

        for(const auto& it : d.observers_ZwFreezeTransactions)
            it(FreezeTimeout, ThawTimeout);
    }

    static void on_NtFsControlFile(monitor::syscallswow64::Data& d)
    {
        const auto FileHandle         = arg<wntdll::HANDLE>(d.core, 0);
        const auto Event              = arg<wntdll::HANDLE>(d.core, 1);
        const auto ApcRoutine         = arg<wntdll::PIO_APC_ROUTINE>(d.core, 2);
        const auto ApcContext         = arg<wntdll::PVOID>(d.core, 3);
        const auto IoStatusBlock      = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 4);
        const auto IoControlCode      = arg<wntdll::ULONG>(d.core, 5);
        const auto InputBuffer        = arg<wntdll::PVOID>(d.core, 6);
        const auto InputBufferLength  = arg<wntdll::ULONG>(d.core, 7);
        const auto OutputBuffer       = arg<wntdll::PVOID>(d.core, 8);
        const auto OutputBufferLength = arg<wntdll::ULONG>(d.core, 9);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtFsControlFile(FileHandle:{:#x}, Event:{:#x}, ApcRoutine:{:#x}, ApcContext:{:#x}, IoStatusBlock:{:#x}, IoControlCode:{:#x}, InputBuffer:{:#x}, InputBufferLength:{:#x}, OutputBuffer:{:#x}, OutputBufferLength:{:#x})", FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, IoControlCode, InputBuffer, InputBufferLength, OutputBuffer, OutputBufferLength));

        for(const auto& it : d.observers_NtFsControlFile)
            it(FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, IoControlCode, InputBuffer, InputBufferLength, OutputBuffer, OutputBufferLength);
    }

    static void on_NtGetContextThread(monitor::syscallswow64::Data& d)
    {
        const auto ThreadHandle  = arg<wntdll::HANDLE>(d.core, 0);
        const auto ThreadContext = arg<wntdll::PCONTEXT>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtGetContextThread(ThreadHandle:{:#x}, ThreadContext:{:#x})", ThreadHandle, ThreadContext));

        for(const auto& it : d.observers_NtGetContextThread)
            it(ThreadHandle, ThreadContext);
    }

    static void on_NtGetDevicePowerState(monitor::syscallswow64::Data& d)
    {
        const auto Device    = arg<wntdll::HANDLE>(d.core, 0);
        const auto STARState = arg<wntdll::DEVICE_POWER_STATE>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtGetDevicePowerState(Device:{:#x}, STARState:{:#x})", Device, STARState));

        for(const auto& it : d.observers_NtGetDevicePowerState)
            it(Device, STARState);
    }

    static void on_NtGetMUIRegistryInfo(monitor::syscallswow64::Data& d)
    {
        const auto Flags    = arg<wntdll::ULONG>(d.core, 0);
        const auto DataSize = arg<wntdll::PULONG>(d.core, 1);
        const auto Data     = arg<wntdll::PVOID>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtGetMUIRegistryInfo(Flags:{:#x}, DataSize:{:#x}, Data:{:#x})", Flags, DataSize, Data));

        for(const auto& it : d.observers_NtGetMUIRegistryInfo)
            it(Flags, DataSize, Data);
    }

    static void on_ZwGetNextProcess(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle    = arg<wntdll::HANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto HandleAttributes = arg<wntdll::ULONG>(d.core, 2);
        const auto Flags            = arg<wntdll::ULONG>(d.core, 3);
        const auto NewProcessHandle = arg<wntdll::PHANDLE>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwGetNextProcess(ProcessHandle:{:#x}, DesiredAccess:{:#x}, HandleAttributes:{:#x}, Flags:{:#x}, NewProcessHandle:{:#x})", ProcessHandle, DesiredAccess, HandleAttributes, Flags, NewProcessHandle));

        for(const auto& it : d.observers_ZwGetNextProcess)
            it(ProcessHandle, DesiredAccess, HandleAttributes, Flags, NewProcessHandle);
    }

    static void on_ZwGetNextThread(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle    = arg<wntdll::HANDLE>(d.core, 0);
        const auto ThreadHandle     = arg<wntdll::HANDLE>(d.core, 1);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 2);
        const auto HandleAttributes = arg<wntdll::ULONG>(d.core, 3);
        const auto Flags            = arg<wntdll::ULONG>(d.core, 4);
        const auto NewThreadHandle  = arg<wntdll::PHANDLE>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwGetNextThread(ProcessHandle:{:#x}, ThreadHandle:{:#x}, DesiredAccess:{:#x}, HandleAttributes:{:#x}, Flags:{:#x}, NewThreadHandle:{:#x})", ProcessHandle, ThreadHandle, DesiredAccess, HandleAttributes, Flags, NewThreadHandle));

        for(const auto& it : d.observers_ZwGetNextThread)
            it(ProcessHandle, ThreadHandle, DesiredAccess, HandleAttributes, Flags, NewThreadHandle);
    }

    static void on_NtGetNlsSectionPtr(monitor::syscallswow64::Data& d)
    {
        const auto SectionType        = arg<wntdll::ULONG>(d.core, 0);
        const auto SectionData        = arg<wntdll::ULONG>(d.core, 1);
        const auto ContextData        = arg<wntdll::PVOID>(d.core, 2);
        const auto STARSectionPointer = arg<wntdll::PVOID>(d.core, 3);
        const auto SectionSize        = arg<wntdll::PULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtGetNlsSectionPtr(SectionType:{:#x}, SectionData:{:#x}, ContextData:{:#x}, STARSectionPointer:{:#x}, SectionSize:{:#x})", SectionType, SectionData, ContextData, STARSectionPointer, SectionSize));

        for(const auto& it : d.observers_NtGetNlsSectionPtr)
            it(SectionType, SectionData, ContextData, STARSectionPointer, SectionSize);
    }

    static void on_ZwGetNotificationResourceManager(monitor::syscallswow64::Data& d)
    {
        const auto ResourceManagerHandle   = arg<wntdll::HANDLE>(d.core, 0);
        const auto TransactionNotification = arg<wntdll::PTRANSACTION_NOTIFICATION>(d.core, 1);
        const auto NotificationLength      = arg<wntdll::ULONG>(d.core, 2);
        const auto Timeout                 = arg<wntdll::PLARGE_INTEGER>(d.core, 3);
        const auto ReturnLength            = arg<wntdll::PULONG>(d.core, 4);
        const auto Asynchronous            = arg<wntdll::ULONG>(d.core, 5);
        const auto AsynchronousContext     = arg<wntdll::ULONG_PTR>(d.core, 6);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwGetNotificationResourceManager(ResourceManagerHandle:{:#x}, TransactionNotification:{:#x}, NotificationLength:{:#x}, Timeout:{:#x}, ReturnLength:{:#x}, Asynchronous:{:#x}, AsynchronousContext:{:#x})", ResourceManagerHandle, TransactionNotification, NotificationLength, Timeout, ReturnLength, Asynchronous, AsynchronousContext));

        for(const auto& it : d.observers_ZwGetNotificationResourceManager)
            it(ResourceManagerHandle, TransactionNotification, NotificationLength, Timeout, ReturnLength, Asynchronous, AsynchronousContext);
    }

    static void on_NtGetWriteWatch(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle             = arg<wntdll::HANDLE>(d.core, 0);
        const auto Flags                     = arg<wntdll::ULONG>(d.core, 1);
        const auto BaseAddress               = arg<wntdll::PVOID>(d.core, 2);
        const auto RegionSize                = arg<wntdll::SIZE_T>(d.core, 3);
        const auto STARUserAddressArray      = arg<wntdll::PVOID>(d.core, 4);
        const auto EntriesInUserAddressArray = arg<wntdll::PULONG_PTR>(d.core, 5);
        const auto Granularity               = arg<wntdll::PULONG>(d.core, 6);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtGetWriteWatch(ProcessHandle:{:#x}, Flags:{:#x}, BaseAddress:{:#x}, RegionSize:{:#x}, STARUserAddressArray:{:#x}, EntriesInUserAddressArray:{:#x}, Granularity:{:#x})", ProcessHandle, Flags, BaseAddress, RegionSize, STARUserAddressArray, EntriesInUserAddressArray, Granularity));

        for(const auto& it : d.observers_NtGetWriteWatch)
            it(ProcessHandle, Flags, BaseAddress, RegionSize, STARUserAddressArray, EntriesInUserAddressArray, Granularity);
    }

    static void on_NtImpersonateAnonymousToken(monitor::syscallswow64::Data& d)
    {
        const auto ThreadHandle = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtImpersonateAnonymousToken(ThreadHandle:{:#x})", ThreadHandle));

        for(const auto& it : d.observers_NtImpersonateAnonymousToken)
            it(ThreadHandle);
    }

    static void on_ZwImpersonateClientOfPort(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto Message    = arg<wntdll::PPORT_MESSAGE>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwImpersonateClientOfPort(PortHandle:{:#x}, Message:{:#x})", PortHandle, Message));

        for(const auto& it : d.observers_ZwImpersonateClientOfPort)
            it(PortHandle, Message);
    }

    static void on_ZwImpersonateThread(monitor::syscallswow64::Data& d)
    {
        const auto ServerThreadHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto ClientThreadHandle = arg<wntdll::HANDLE>(d.core, 1);
        const auto SecurityQos        = arg<wntdll::PSECURITY_QUALITY_OF_SERVICE>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwImpersonateThread(ServerThreadHandle:{:#x}, ClientThreadHandle:{:#x}, SecurityQos:{:#x})", ServerThreadHandle, ClientThreadHandle, SecurityQos));

        for(const auto& it : d.observers_ZwImpersonateThread)
            it(ServerThreadHandle, ClientThreadHandle, SecurityQos);
    }

    static void on_NtInitializeNlsFiles(monitor::syscallswow64::Data& d)
    {
        const auto STARBaseAddress        = arg<wntdll::PVOID>(d.core, 0);
        const auto DefaultLocaleId        = arg<wntdll::PLCID>(d.core, 1);
        const auto DefaultCasingTableSize = arg<wntdll::PLARGE_INTEGER>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtInitializeNlsFiles(STARBaseAddress:{:#x}, DefaultLocaleId:{:#x}, DefaultCasingTableSize:{:#x})", STARBaseAddress, DefaultLocaleId, DefaultCasingTableSize));

        for(const auto& it : d.observers_NtInitializeNlsFiles)
            it(STARBaseAddress, DefaultLocaleId, DefaultCasingTableSize);
    }

    static void on_ZwInitializeRegistry(monitor::syscallswow64::Data& d)
    {
        const auto BootCondition = arg<wntdll::USHORT>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwInitializeRegistry(BootCondition:{:#x})", BootCondition));

        for(const auto& it : d.observers_ZwInitializeRegistry)
            it(BootCondition);
    }

    static void on_NtInitiatePowerAction(monitor::syscallswow64::Data& d)
    {
        const auto SystemAction   = arg<wntdll::POWER_ACTION>(d.core, 0);
        const auto MinSystemState = arg<wntdll::SYSTEM_POWER_STATE>(d.core, 1);
        const auto Flags          = arg<wntdll::ULONG>(d.core, 2);
        const auto Asynchronous   = arg<wntdll::BOOLEAN>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtInitiatePowerAction(SystemAction:{:#x}, MinSystemState:{:#x}, Flags:{:#x}, Asynchronous:{:#x})", SystemAction, MinSystemState, Flags, Asynchronous));

        for(const auto& it : d.observers_NtInitiatePowerAction)
            it(SystemAction, MinSystemState, Flags, Asynchronous);
    }

    static void on_ZwIsProcessInJob(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto JobHandle     = arg<wntdll::HANDLE>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwIsProcessInJob(ProcessHandle:{:#x}, JobHandle:{:#x})", ProcessHandle, JobHandle));

        for(const auto& it : d.observers_ZwIsProcessInJob)
            it(ProcessHandle, JobHandle);
    }

    static void on_ZwListenPort(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle        = arg<wntdll::HANDLE>(d.core, 0);
        const auto ConnectionRequest = arg<wntdll::PPORT_MESSAGE>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwListenPort(PortHandle:{:#x}, ConnectionRequest:{:#x})", PortHandle, ConnectionRequest));

        for(const auto& it : d.observers_ZwListenPort)
            it(PortHandle, ConnectionRequest);
    }

    static void on_NtLoadDriver(monitor::syscallswow64::Data& d)
    {
        const auto DriverServiceName = arg<wntdll::PUNICODE_STRING>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtLoadDriver(DriverServiceName:{:#x})", DriverServiceName));

        for(const auto& it : d.observers_NtLoadDriver)
            it(DriverServiceName);
    }

    static void on_NtLoadKey2(monitor::syscallswow64::Data& d)
    {
        const auto TargetKey  = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 0);
        const auto SourceFile = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 1);
        const auto Flags      = arg<wntdll::ULONG>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtLoadKey2(TargetKey:{:#x}, SourceFile:{:#x}, Flags:{:#x})", TargetKey, SourceFile, Flags));

        for(const auto& it : d.observers_NtLoadKey2)
            it(TargetKey, SourceFile, Flags);
    }

    static void on_NtLoadKeyEx(monitor::syscallswow64::Data& d)
    {
        const auto TargetKey         = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 0);
        const auto SourceFile        = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 1);
        const auto Flags             = arg<wntdll::ULONG>(d.core, 2);
        const auto TrustClassKey     = arg<wntdll::HANDLE>(d.core, 3);
        const auto Reserved          = arg<wntdll::PVOID>(d.core, 4);
        const auto ObjectContext     = arg<wntdll::PVOID>(d.core, 5);
        const auto CallbackReserverd = arg<wntdll::PVOID>(d.core, 6);
        const auto IoStatusBlock     = arg<wntdll::PVOID>(d.core, 7);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtLoadKeyEx(TargetKey:{:#x}, SourceFile:{:#x}, Flags:{:#x}, TrustClassKey:{:#x}, Reserved:{:#x}, ObjectContext:{:#x}, CallbackReserverd:{:#x}, IoStatusBlock:{:#x})", TargetKey, SourceFile, Flags, TrustClassKey, Reserved, ObjectContext, CallbackReserverd, IoStatusBlock));

        for(const auto& it : d.observers_NtLoadKeyEx)
            it(TargetKey, SourceFile, Flags, TrustClassKey, Reserved, ObjectContext, CallbackReserverd, IoStatusBlock);
    }

    static void on_NtLoadKey(monitor::syscallswow64::Data& d)
    {
        const auto TargetKey  = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 0);
        const auto SourceFile = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtLoadKey(TargetKey:{:#x}, SourceFile:{:#x})", TargetKey, SourceFile));

        for(const auto& it : d.observers_NtLoadKey)
            it(TargetKey, SourceFile);
    }

    static void on_NtLockFile(monitor::syscallswow64::Data& d)
    {
        const auto FileHandle      = arg<wntdll::HANDLE>(d.core, 0);
        const auto Event           = arg<wntdll::HANDLE>(d.core, 1);
        const auto ApcRoutine      = arg<wntdll::PIO_APC_ROUTINE>(d.core, 2);
        const auto ApcContext      = arg<wntdll::PVOID>(d.core, 3);
        const auto IoStatusBlock   = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 4);
        const auto ByteOffset      = arg<wntdll::PLARGE_INTEGER>(d.core, 5);
        const auto Length          = arg<wntdll::PLARGE_INTEGER>(d.core, 6);
        const auto Key             = arg<wntdll::ULONG>(d.core, 7);
        const auto FailImmediately = arg<wntdll::BOOLEAN>(d.core, 8);
        const auto ExclusiveLock   = arg<wntdll::BOOLEAN>(d.core, 9);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtLockFile(FileHandle:{:#x}, Event:{:#x}, ApcRoutine:{:#x}, ApcContext:{:#x}, IoStatusBlock:{:#x}, ByteOffset:{:#x}, Length:{:#x}, Key:{:#x}, FailImmediately:{:#x}, ExclusiveLock:{:#x})", FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, ByteOffset, Length, Key, FailImmediately, ExclusiveLock));

        for(const auto& it : d.observers_NtLockFile)
            it(FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, ByteOffset, Length, Key, FailImmediately, ExclusiveLock);
    }

    static void on_ZwLockProductActivationKeys(monitor::syscallswow64::Data& d)
    {
        const auto STARpPrivateVer = arg<wntdll::ULONG>(d.core, 0);
        const auto STARpSafeMode   = arg<wntdll::ULONG>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwLockProductActivationKeys(STARpPrivateVer:{:#x}, STARpSafeMode:{:#x})", STARpPrivateVer, STARpSafeMode));

        for(const auto& it : d.observers_ZwLockProductActivationKeys)
            it(STARpPrivateVer, STARpSafeMode);
    }

    static void on_NtLockRegistryKey(monitor::syscallswow64::Data& d)
    {
        const auto KeyHandle = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtLockRegistryKey(KeyHandle:{:#x})", KeyHandle));

        for(const auto& it : d.observers_NtLockRegistryKey)
            it(KeyHandle);
    }

    static void on_ZwLockVirtualMemory(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle   = arg<wntdll::HANDLE>(d.core, 0);
        const auto STARBaseAddress = arg<wntdll::PVOID>(d.core, 1);
        const auto RegionSize      = arg<wntdll::PSIZE_T>(d.core, 2);
        const auto MapType         = arg<wntdll::ULONG>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwLockVirtualMemory(ProcessHandle:{:#x}, STARBaseAddress:{:#x}, RegionSize:{:#x}, MapType:{:#x})", ProcessHandle, STARBaseAddress, RegionSize, MapType));

        for(const auto& it : d.observers_ZwLockVirtualMemory)
            it(ProcessHandle, STARBaseAddress, RegionSize, MapType);
    }

    static void on_ZwMakePermanentObject(monitor::syscallswow64::Data& d)
    {
        const auto Handle = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwMakePermanentObject(Handle:{:#x})", Handle));

        for(const auto& it : d.observers_ZwMakePermanentObject)
            it(Handle);
    }

    static void on_NtMakeTemporaryObject(monitor::syscallswow64::Data& d)
    {
        const auto Handle = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtMakeTemporaryObject(Handle:{:#x})", Handle));

        for(const auto& it : d.observers_NtMakeTemporaryObject)
            it(Handle);
    }

    static void on_ZwMapCMFModule(monitor::syscallswow64::Data& d)
    {
        const auto What            = arg<wntdll::ULONG>(d.core, 0);
        const auto Index           = arg<wntdll::ULONG>(d.core, 1);
        const auto CacheIndexOut   = arg<wntdll::PULONG>(d.core, 2);
        const auto CacheFlagsOut   = arg<wntdll::PULONG>(d.core, 3);
        const auto ViewSizeOut     = arg<wntdll::PULONG>(d.core, 4);
        const auto STARBaseAddress = arg<wntdll::PVOID>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwMapCMFModule(What:{:#x}, Index:{:#x}, CacheIndexOut:{:#x}, CacheFlagsOut:{:#x}, ViewSizeOut:{:#x}, STARBaseAddress:{:#x})", What, Index, CacheIndexOut, CacheFlagsOut, ViewSizeOut, STARBaseAddress));

        for(const auto& it : d.observers_ZwMapCMFModule)
            it(What, Index, CacheIndexOut, CacheFlagsOut, ViewSizeOut, STARBaseAddress);
    }

    static void on_NtMapUserPhysicalPages(monitor::syscallswow64::Data& d)
    {
        const auto VirtualAddress = arg<wntdll::PVOID>(d.core, 0);
        const auto NumberOfPages  = arg<wntdll::ULONG_PTR>(d.core, 1);
        const auto UserPfnArra    = arg<wntdll::PULONG_PTR>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtMapUserPhysicalPages(VirtualAddress:{:#x}, NumberOfPages:{:#x}, UserPfnArra:{:#x})", VirtualAddress, NumberOfPages, UserPfnArra));

        for(const auto& it : d.observers_NtMapUserPhysicalPages)
            it(VirtualAddress, NumberOfPages, UserPfnArra);
    }

    static void on_ZwMapUserPhysicalPagesScatter(monitor::syscallswow64::Data& d)
    {
        const auto STARVirtualAddresses = arg<wntdll::PVOID>(d.core, 0);
        const auto NumberOfPages        = arg<wntdll::ULONG_PTR>(d.core, 1);
        const auto UserPfnArray         = arg<wntdll::PULONG_PTR>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwMapUserPhysicalPagesScatter(STARVirtualAddresses:{:#x}, NumberOfPages:{:#x}, UserPfnArray:{:#x})", STARVirtualAddresses, NumberOfPages, UserPfnArray));

        for(const auto& it : d.observers_ZwMapUserPhysicalPagesScatter)
            it(STARVirtualAddresses, NumberOfPages, UserPfnArray);
    }

    static void on_ZwMapViewOfSection(monitor::syscallswow64::Data& d)
    {
        const auto SectionHandle      = arg<wntdll::HANDLE>(d.core, 0);
        const auto ProcessHandle      = arg<wntdll::HANDLE>(d.core, 1);
        const auto STARBaseAddress    = arg<wntdll::PVOID>(d.core, 2);
        const auto ZeroBits           = arg<wntdll::ULONG_PTR>(d.core, 3);
        const auto CommitSize         = arg<wntdll::SIZE_T>(d.core, 4);
        const auto SectionOffset      = arg<wntdll::PLARGE_INTEGER>(d.core, 5);
        const auto ViewSize           = arg<wntdll::PSIZE_T>(d.core, 6);
        const auto InheritDisposition = arg<wntdll::SECTION_INHERIT>(d.core, 7);
        const auto AllocationType     = arg<wntdll::ULONG>(d.core, 8);
        const auto Win32Protect       = arg<wntdll::WIN32_PROTECTION_MASK>(d.core, 9);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwMapViewOfSection(SectionHandle:{:#x}, ProcessHandle:{:#x}, STARBaseAddress:{:#x}, ZeroBits:{:#x}, CommitSize:{:#x}, SectionOffset:{:#x}, ViewSize:{:#x}, InheritDisposition:{:#x}, AllocationType:{:#x}, Win32Protect:{:#x})", SectionHandle, ProcessHandle, STARBaseAddress, ZeroBits, CommitSize, SectionOffset, ViewSize, InheritDisposition, AllocationType, Win32Protect));

        for(const auto& it : d.observers_ZwMapViewOfSection)
            it(SectionHandle, ProcessHandle, STARBaseAddress, ZeroBits, CommitSize, SectionOffset, ViewSize, InheritDisposition, AllocationType, Win32Protect);
    }

    static void on_NtModifyBootEntry(monitor::syscallswow64::Data& d)
    {
        const auto BootEntry = arg<wntdll::PBOOT_ENTRY>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtModifyBootEntry(BootEntry:{:#x})", BootEntry));

        for(const auto& it : d.observers_NtModifyBootEntry)
            it(BootEntry);
    }

    static void on_ZwModifyDriverEntry(monitor::syscallswow64::Data& d)
    {
        const auto DriverEntry = arg<wntdll::PEFI_DRIVER_ENTRY>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwModifyDriverEntry(DriverEntry:{:#x})", DriverEntry));

        for(const auto& it : d.observers_ZwModifyDriverEntry)
            it(DriverEntry);
    }

    static void on_NtNotifyChangeDirectoryFile(monitor::syscallswow64::Data& d)
    {
        const auto FileHandle       = arg<wntdll::HANDLE>(d.core, 0);
        const auto Event            = arg<wntdll::HANDLE>(d.core, 1);
        const auto ApcRoutine       = arg<wntdll::PIO_APC_ROUTINE>(d.core, 2);
        const auto ApcContext       = arg<wntdll::PVOID>(d.core, 3);
        const auto IoStatusBlock    = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 4);
        const auto Buffer           = arg<wntdll::PVOID>(d.core, 5);
        const auto Length           = arg<wntdll::ULONG>(d.core, 6);
        const auto CompletionFilter = arg<wntdll::ULONG>(d.core, 7);
        const auto WatchTree        = arg<wntdll::BOOLEAN>(d.core, 8);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtNotifyChangeDirectoryFile(FileHandle:{:#x}, Event:{:#x}, ApcRoutine:{:#x}, ApcContext:{:#x}, IoStatusBlock:{:#x}, Buffer:{:#x}, Length:{:#x}, CompletionFilter:{:#x}, WatchTree:{:#x})", FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, Buffer, Length, CompletionFilter, WatchTree));

        for(const auto& it : d.observers_NtNotifyChangeDirectoryFile)
            it(FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, Buffer, Length, CompletionFilter, WatchTree);
    }

    static void on_NtNotifyChangeKey(monitor::syscallswow64::Data& d)
    {
        const auto KeyHandle        = arg<wntdll::HANDLE>(d.core, 0);
        const auto Event            = arg<wntdll::HANDLE>(d.core, 1);
        const auto ApcRoutine       = arg<wntdll::PIO_APC_ROUTINE>(d.core, 2);
        const auto ApcContext       = arg<wntdll::PVOID>(d.core, 3);
        const auto IoStatusBlock    = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 4);
        const auto CompletionFilter = arg<wntdll::ULONG>(d.core, 5);
        const auto WatchTree        = arg<wntdll::BOOLEAN>(d.core, 6);
        const auto Buffer           = arg<wntdll::PVOID>(d.core, 7);
        const auto BufferSize       = arg<wntdll::ULONG>(d.core, 8);
        const auto Asynchronous     = arg<wntdll::BOOLEAN>(d.core, 9);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtNotifyChangeKey(KeyHandle:{:#x}, Event:{:#x}, ApcRoutine:{:#x}, ApcContext:{:#x}, IoStatusBlock:{:#x}, CompletionFilter:{:#x}, WatchTree:{:#x}, Buffer:{:#x}, BufferSize:{:#x}, Asynchronous:{:#x})", KeyHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, CompletionFilter, WatchTree, Buffer, BufferSize, Asynchronous));

        for(const auto& it : d.observers_NtNotifyChangeKey)
            it(KeyHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, CompletionFilter, WatchTree, Buffer, BufferSize, Asynchronous);
    }

    static void on_NtNotifyChangeMultipleKeys(monitor::syscallswow64::Data& d)
    {
        const auto MasterKeyHandle  = arg<wntdll::HANDLE>(d.core, 0);
        const auto Count            = arg<wntdll::ULONG>(d.core, 1);
        const auto SlaveObjects     = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto Event            = arg<wntdll::HANDLE>(d.core, 3);
        const auto ApcRoutine       = arg<wntdll::PIO_APC_ROUTINE>(d.core, 4);
        const auto ApcContext       = arg<wntdll::PVOID>(d.core, 5);
        const auto IoStatusBlock    = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 6);
        const auto CompletionFilter = arg<wntdll::ULONG>(d.core, 7);
        const auto WatchTree        = arg<wntdll::BOOLEAN>(d.core, 8);
        const auto Buffer           = arg<wntdll::PVOID>(d.core, 9);
        const auto BufferSize       = arg<wntdll::ULONG>(d.core, 10);
        const auto Asynchronous     = arg<wntdll::BOOLEAN>(d.core, 11);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtNotifyChangeMultipleKeys(MasterKeyHandle:{:#x}, Count:{:#x}, SlaveObjects:{:#x}, Event:{:#x}, ApcRoutine:{:#x}, ApcContext:{:#x}, IoStatusBlock:{:#x}, CompletionFilter:{:#x}, WatchTree:{:#x}, Buffer:{:#x}, BufferSize:{:#x}, Asynchronous:{:#x})", MasterKeyHandle, Count, SlaveObjects, Event, ApcRoutine, ApcContext, IoStatusBlock, CompletionFilter, WatchTree, Buffer, BufferSize, Asynchronous));

        for(const auto& it : d.observers_NtNotifyChangeMultipleKeys)
            it(MasterKeyHandle, Count, SlaveObjects, Event, ApcRoutine, ApcContext, IoStatusBlock, CompletionFilter, WatchTree, Buffer, BufferSize, Asynchronous);
    }

    static void on_NtNotifyChangeSession(monitor::syscallswow64::Data& d)
    {
        const auto Session         = arg<wntdll::HANDLE>(d.core, 0);
        const auto IoStateSequence = arg<wntdll::ULONG>(d.core, 1);
        const auto Reserved        = arg<wntdll::PVOID>(d.core, 2);
        const auto Action          = arg<wntdll::ULONG>(d.core, 3);
        const auto IoState         = arg<wntdll::IO_SESSION_STATE>(d.core, 4);
        const auto IoState2        = arg<wntdll::IO_SESSION_STATE>(d.core, 5);
        const auto Buffer          = arg<wntdll::PVOID>(d.core, 6);
        const auto BufferSize      = arg<wntdll::ULONG>(d.core, 7);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtNotifyChangeSession(Session:{:#x}, IoStateSequence:{:#x}, Reserved:{:#x}, Action:{:#x}, IoState:{:#x}, IoState2:{:#x}, Buffer:{:#x}, BufferSize:{:#x})", Session, IoStateSequence, Reserved, Action, IoState, IoState2, Buffer, BufferSize));

        for(const auto& it : d.observers_NtNotifyChangeSession)
            it(Session, IoStateSequence, Reserved, Action, IoState, IoState2, Buffer, BufferSize);
    }

    static void on_ZwOpenDirectoryObject(monitor::syscallswow64::Data& d)
    {
        const auto DirectoryHandle  = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwOpenDirectoryObject(DirectoryHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x})", DirectoryHandle, DesiredAccess, ObjectAttributes));

        for(const auto& it : d.observers_ZwOpenDirectoryObject)
            it(DirectoryHandle, DesiredAccess, ObjectAttributes);
    }

    static void on_ZwOpenEnlistment(monitor::syscallswow64::Data& d)
    {
        const auto EnlistmentHandle      = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess         = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ResourceManagerHandle = arg<wntdll::HANDLE>(d.core, 2);
        const auto EnlistmentGuid        = arg<wntdll::LPGUID>(d.core, 3);
        const auto ObjectAttributes      = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwOpenEnlistment(EnlistmentHandle:{:#x}, DesiredAccess:{:#x}, ResourceManagerHandle:{:#x}, EnlistmentGuid:{:#x}, ObjectAttributes:{:#x})", EnlistmentHandle, DesiredAccess, ResourceManagerHandle, EnlistmentGuid, ObjectAttributes));

        for(const auto& it : d.observers_ZwOpenEnlistment)
            it(EnlistmentHandle, DesiredAccess, ResourceManagerHandle, EnlistmentGuid, ObjectAttributes);
    }

    static void on_NtOpenEvent(monitor::syscallswow64::Data& d)
    {
        const auto EventHandle      = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtOpenEvent(EventHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x})", EventHandle, DesiredAccess, ObjectAttributes));

        for(const auto& it : d.observers_NtOpenEvent)
            it(EventHandle, DesiredAccess, ObjectAttributes);
    }

    static void on_NtOpenEventPair(monitor::syscallswow64::Data& d)
    {
        const auto EventPairHandle  = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtOpenEventPair(EventPairHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x})", EventPairHandle, DesiredAccess, ObjectAttributes));

        for(const auto& it : d.observers_NtOpenEventPair)
            it(EventPairHandle, DesiredAccess, ObjectAttributes);
    }

    static void on_NtOpenFile(monitor::syscallswow64::Data& d)
    {
        const auto FileHandle       = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto IoStatusBlock    = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 3);
        const auto ShareAccess      = arg<wntdll::ULONG>(d.core, 4);
        const auto OpenOptions      = arg<wntdll::ULONG>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtOpenFile(FileHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, IoStatusBlock:{:#x}, ShareAccess:{:#x}, OpenOptions:{:#x})", FileHandle, DesiredAccess, ObjectAttributes, IoStatusBlock, ShareAccess, OpenOptions));

        for(const auto& it : d.observers_NtOpenFile)
            it(FileHandle, DesiredAccess, ObjectAttributes, IoStatusBlock, ShareAccess, OpenOptions);
    }

    static void on_ZwOpenIoCompletion(monitor::syscallswow64::Data& d)
    {
        const auto IoCompletionHandle = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess      = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes   = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwOpenIoCompletion(IoCompletionHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x})", IoCompletionHandle, DesiredAccess, ObjectAttributes));

        for(const auto& it : d.observers_ZwOpenIoCompletion)
            it(IoCompletionHandle, DesiredAccess, ObjectAttributes);
    }

    static void on_ZwOpenJobObject(monitor::syscallswow64::Data& d)
    {
        const auto JobHandle        = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwOpenJobObject(JobHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x})", JobHandle, DesiredAccess, ObjectAttributes));

        for(const auto& it : d.observers_ZwOpenJobObject)
            it(JobHandle, DesiredAccess, ObjectAttributes);
    }

    static void on_NtOpenKeyedEvent(monitor::syscallswow64::Data& d)
    {
        const auto KeyedEventHandle = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtOpenKeyedEvent(KeyedEventHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x})", KeyedEventHandle, DesiredAccess, ObjectAttributes));

        for(const auto& it : d.observers_NtOpenKeyedEvent)
            it(KeyedEventHandle, DesiredAccess, ObjectAttributes);
    }

    static void on_ZwOpenKeyEx(monitor::syscallswow64::Data& d)
    {
        const auto KeyHandle        = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto OpenOptions      = arg<wntdll::ULONG>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwOpenKeyEx(KeyHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, OpenOptions:{:#x})", KeyHandle, DesiredAccess, ObjectAttributes, OpenOptions));

        for(const auto& it : d.observers_ZwOpenKeyEx)
            it(KeyHandle, DesiredAccess, ObjectAttributes, OpenOptions);
    }

    static void on_ZwOpenKey(monitor::syscallswow64::Data& d)
    {
        const auto KeyHandle        = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwOpenKey(KeyHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x})", KeyHandle, DesiredAccess, ObjectAttributes));

        for(const auto& it : d.observers_ZwOpenKey)
            it(KeyHandle, DesiredAccess, ObjectAttributes);
    }

    static void on_NtOpenKeyTransactedEx(monitor::syscallswow64::Data& d)
    {
        const auto KeyHandle         = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess     = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes  = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto OpenOptions       = arg<wntdll::ULONG>(d.core, 3);
        const auto TransactionHandle = arg<wntdll::HANDLE>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtOpenKeyTransactedEx(KeyHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, OpenOptions:{:#x}, TransactionHandle:{:#x})", KeyHandle, DesiredAccess, ObjectAttributes, OpenOptions, TransactionHandle));

        for(const auto& it : d.observers_NtOpenKeyTransactedEx)
            it(KeyHandle, DesiredAccess, ObjectAttributes, OpenOptions, TransactionHandle);
    }

    static void on_NtOpenKeyTransacted(monitor::syscallswow64::Data& d)
    {
        const auto KeyHandle         = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess     = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes  = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto TransactionHandle = arg<wntdll::HANDLE>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtOpenKeyTransacted(KeyHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, TransactionHandle:{:#x})", KeyHandle, DesiredAccess, ObjectAttributes, TransactionHandle));

        for(const auto& it : d.observers_NtOpenKeyTransacted)
            it(KeyHandle, DesiredAccess, ObjectAttributes, TransactionHandle);
    }

    static void on_NtOpenMutant(monitor::syscallswow64::Data& d)
    {
        const auto MutantHandle     = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtOpenMutant(MutantHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x})", MutantHandle, DesiredAccess, ObjectAttributes));

        for(const auto& it : d.observers_NtOpenMutant)
            it(MutantHandle, DesiredAccess, ObjectAttributes);
    }

    static void on_ZwOpenObjectAuditAlarm(monitor::syscallswow64::Data& d)
    {
        const auto SubsystemName      = arg<wntdll::PUNICODE_STRING>(d.core, 0);
        const auto HandleId           = arg<wntdll::PVOID>(d.core, 1);
        const auto ObjectTypeName     = arg<wntdll::PUNICODE_STRING>(d.core, 2);
        const auto ObjectName         = arg<wntdll::PUNICODE_STRING>(d.core, 3);
        const auto SecurityDescriptor = arg<wntdll::PSECURITY_DESCRIPTOR>(d.core, 4);
        const auto ClientToken        = arg<wntdll::HANDLE>(d.core, 5);
        const auto DesiredAccess      = arg<wntdll::ACCESS_MASK>(d.core, 6);
        const auto GrantedAccess      = arg<wntdll::ACCESS_MASK>(d.core, 7);
        const auto Privileges         = arg<wntdll::PPRIVILEGE_SET>(d.core, 8);
        const auto ObjectCreation     = arg<wntdll::BOOLEAN>(d.core, 9);
        const auto AccessGranted      = arg<wntdll::BOOLEAN>(d.core, 10);
        const auto GenerateOnClose    = arg<wntdll::PBOOLEAN>(d.core, 11);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwOpenObjectAuditAlarm(SubsystemName:{:#x}, HandleId:{:#x}, ObjectTypeName:{:#x}, ObjectName:{:#x}, SecurityDescriptor:{:#x}, ClientToken:{:#x}, DesiredAccess:{:#x}, GrantedAccess:{:#x}, Privileges:{:#x}, ObjectCreation:{:#x}, AccessGranted:{:#x}, GenerateOnClose:{:#x})", SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess, Privileges, ObjectCreation, AccessGranted, GenerateOnClose));

        for(const auto& it : d.observers_ZwOpenObjectAuditAlarm)
            it(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess, Privileges, ObjectCreation, AccessGranted, GenerateOnClose);
    }

    static void on_NtOpenPrivateNamespace(monitor::syscallswow64::Data& d)
    {
        const auto NamespaceHandle    = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess      = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes   = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto BoundaryDescriptor = arg<wntdll::PVOID>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtOpenPrivateNamespace(NamespaceHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, BoundaryDescriptor:{:#x})", NamespaceHandle, DesiredAccess, ObjectAttributes, BoundaryDescriptor));

        for(const auto& it : d.observers_NtOpenPrivateNamespace)
            it(NamespaceHandle, DesiredAccess, ObjectAttributes, BoundaryDescriptor);
    }

    static void on_ZwOpenProcess(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle    = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto ClientId         = arg<wntdll::PCLIENT_ID>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwOpenProcess(ProcessHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, ClientId:{:#x})", ProcessHandle, DesiredAccess, ObjectAttributes, ClientId));

        for(const auto& it : d.observers_ZwOpenProcess)
            it(ProcessHandle, DesiredAccess, ObjectAttributes, ClientId);
    }

    static void on_ZwOpenProcessTokenEx(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle    = arg<wntdll::HANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto HandleAttributes = arg<wntdll::ULONG>(d.core, 2);
        const auto TokenHandle      = arg<wntdll::PHANDLE>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwOpenProcessTokenEx(ProcessHandle:{:#x}, DesiredAccess:{:#x}, HandleAttributes:{:#x}, TokenHandle:{:#x})", ProcessHandle, DesiredAccess, HandleAttributes, TokenHandle));

        for(const auto& it : d.observers_ZwOpenProcessTokenEx)
            it(ProcessHandle, DesiredAccess, HandleAttributes, TokenHandle);
    }

    static void on_ZwOpenProcessToken(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto DesiredAccess = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto TokenHandle   = arg<wntdll::PHANDLE>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwOpenProcessToken(ProcessHandle:{:#x}, DesiredAccess:{:#x}, TokenHandle:{:#x})", ProcessHandle, DesiredAccess, TokenHandle));

        for(const auto& it : d.observers_ZwOpenProcessToken)
            it(ProcessHandle, DesiredAccess, TokenHandle);
    }

    static void on_ZwOpenResourceManager(monitor::syscallswow64::Data& d)
    {
        const auto ResourceManagerHandle = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess         = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto TmHandle              = arg<wntdll::HANDLE>(d.core, 2);
        const auto ResourceManagerGuid   = arg<wntdll::LPGUID>(d.core, 3);
        const auto ObjectAttributes      = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwOpenResourceManager(ResourceManagerHandle:{:#x}, DesiredAccess:{:#x}, TmHandle:{:#x}, ResourceManagerGuid:{:#x}, ObjectAttributes:{:#x})", ResourceManagerHandle, DesiredAccess, TmHandle, ResourceManagerGuid, ObjectAttributes));

        for(const auto& it : d.observers_ZwOpenResourceManager)
            it(ResourceManagerHandle, DesiredAccess, TmHandle, ResourceManagerGuid, ObjectAttributes);
    }

    static void on_NtOpenSection(monitor::syscallswow64::Data& d)
    {
        const auto SectionHandle    = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtOpenSection(SectionHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x})", SectionHandle, DesiredAccess, ObjectAttributes));

        for(const auto& it : d.observers_NtOpenSection)
            it(SectionHandle, DesiredAccess, ObjectAttributes);
    }

    static void on_NtOpenSemaphore(monitor::syscallswow64::Data& d)
    {
        const auto SemaphoreHandle  = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtOpenSemaphore(SemaphoreHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x})", SemaphoreHandle, DesiredAccess, ObjectAttributes));

        for(const auto& it : d.observers_NtOpenSemaphore)
            it(SemaphoreHandle, DesiredAccess, ObjectAttributes);
    }

    static void on_NtOpenSession(monitor::syscallswow64::Data& d)
    {
        const auto SessionHandle    = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtOpenSession(SessionHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x})", SessionHandle, DesiredAccess, ObjectAttributes));

        for(const auto& it : d.observers_NtOpenSession)
            it(SessionHandle, DesiredAccess, ObjectAttributes);
    }

    static void on_NtOpenSymbolicLinkObject(monitor::syscallswow64::Data& d)
    {
        const auto LinkHandle       = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtOpenSymbolicLinkObject(LinkHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x})", LinkHandle, DesiredAccess, ObjectAttributes));

        for(const auto& it : d.observers_NtOpenSymbolicLinkObject)
            it(LinkHandle, DesiredAccess, ObjectAttributes);
    }

    static void on_ZwOpenThread(monitor::syscallswow64::Data& d)
    {
        const auto ThreadHandle     = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto ClientId         = arg<wntdll::PCLIENT_ID>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwOpenThread(ThreadHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, ClientId:{:#x})", ThreadHandle, DesiredAccess, ObjectAttributes, ClientId));

        for(const auto& it : d.observers_ZwOpenThread)
            it(ThreadHandle, DesiredAccess, ObjectAttributes, ClientId);
    }

    static void on_NtOpenThreadTokenEx(monitor::syscallswow64::Data& d)
    {
        const auto ThreadHandle     = arg<wntdll::HANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto OpenAsSelf       = arg<wntdll::BOOLEAN>(d.core, 2);
        const auto HandleAttributes = arg<wntdll::ULONG>(d.core, 3);
        const auto TokenHandle      = arg<wntdll::PHANDLE>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtOpenThreadTokenEx(ThreadHandle:{:#x}, DesiredAccess:{:#x}, OpenAsSelf:{:#x}, HandleAttributes:{:#x}, TokenHandle:{:#x})", ThreadHandle, DesiredAccess, OpenAsSelf, HandleAttributes, TokenHandle));

        for(const auto& it : d.observers_NtOpenThreadTokenEx)
            it(ThreadHandle, DesiredAccess, OpenAsSelf, HandleAttributes, TokenHandle);
    }

    static void on_NtOpenThreadToken(monitor::syscallswow64::Data& d)
    {
        const auto ThreadHandle  = arg<wntdll::HANDLE>(d.core, 0);
        const auto DesiredAccess = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto OpenAsSelf    = arg<wntdll::BOOLEAN>(d.core, 2);
        const auto TokenHandle   = arg<wntdll::PHANDLE>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtOpenThreadToken(ThreadHandle:{:#x}, DesiredAccess:{:#x}, OpenAsSelf:{:#x}, TokenHandle:{:#x})", ThreadHandle, DesiredAccess, OpenAsSelf, TokenHandle));

        for(const auto& it : d.observers_NtOpenThreadToken)
            it(ThreadHandle, DesiredAccess, OpenAsSelf, TokenHandle);
    }

    static void on_ZwOpenTimer(monitor::syscallswow64::Data& d)
    {
        const auto TimerHandle      = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwOpenTimer(TimerHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x})", TimerHandle, DesiredAccess, ObjectAttributes));

        for(const auto& it : d.observers_ZwOpenTimer)
            it(TimerHandle, DesiredAccess, ObjectAttributes);
    }

    static void on_ZwOpenTransactionManager(monitor::syscallswow64::Data& d)
    {
        const auto TmHandle         = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess    = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto LogFileName      = arg<wntdll::PUNICODE_STRING>(d.core, 3);
        const auto TmIdentity       = arg<wntdll::LPGUID>(d.core, 4);
        const auto OpenOptions      = arg<wntdll::ULONG>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwOpenTransactionManager(TmHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, LogFileName:{:#x}, TmIdentity:{:#x}, OpenOptions:{:#x})", TmHandle, DesiredAccess, ObjectAttributes, LogFileName, TmIdentity, OpenOptions));

        for(const auto& it : d.observers_ZwOpenTransactionManager)
            it(TmHandle, DesiredAccess, ObjectAttributes, LogFileName, TmIdentity, OpenOptions);
    }

    static void on_ZwOpenTransaction(monitor::syscallswow64::Data& d)
    {
        const auto TransactionHandle = arg<wntdll::PHANDLE>(d.core, 0);
        const auto DesiredAccess     = arg<wntdll::ACCESS_MASK>(d.core, 1);
        const auto ObjectAttributes  = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);
        const auto Uow               = arg<wntdll::LPGUID>(d.core, 3);
        const auto TmHandle          = arg<wntdll::HANDLE>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwOpenTransaction(TransactionHandle:{:#x}, DesiredAccess:{:#x}, ObjectAttributes:{:#x}, Uow:{:#x}, TmHandle:{:#x})", TransactionHandle, DesiredAccess, ObjectAttributes, Uow, TmHandle));

        for(const auto& it : d.observers_ZwOpenTransaction)
            it(TransactionHandle, DesiredAccess, ObjectAttributes, Uow, TmHandle);
    }

    static void on_NtPlugPlayControl(monitor::syscallswow64::Data& d)
    {
        const auto PnPControlClass      = arg<wntdll::PLUGPLAY_CONTROL_CLASS>(d.core, 0);
        const auto PnPControlData       = arg<wntdll::PVOID>(d.core, 1);
        const auto PnPControlDataLength = arg<wntdll::ULONG>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtPlugPlayControl(PnPControlClass:{:#x}, PnPControlData:{:#x}, PnPControlDataLength:{:#x})", PnPControlClass, PnPControlData, PnPControlDataLength));

        for(const auto& it : d.observers_NtPlugPlayControl)
            it(PnPControlClass, PnPControlData, PnPControlDataLength);
    }

    static void on_ZwPowerInformation(monitor::syscallswow64::Data& d)
    {
        const auto InformationLevel   = arg<wntdll::POWER_INFORMATION_LEVEL>(d.core, 0);
        const auto InputBuffer        = arg<wntdll::PVOID>(d.core, 1);
        const auto InputBufferLength  = arg<wntdll::ULONG>(d.core, 2);
        const auto OutputBuffer       = arg<wntdll::PVOID>(d.core, 3);
        const auto OutputBufferLength = arg<wntdll::ULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwPowerInformation(InformationLevel:{:#x}, InputBuffer:{:#x}, InputBufferLength:{:#x}, OutputBuffer:{:#x}, OutputBufferLength:{:#x})", InformationLevel, InputBuffer, InputBufferLength, OutputBuffer, OutputBufferLength));

        for(const auto& it : d.observers_ZwPowerInformation)
            it(InformationLevel, InputBuffer, InputBufferLength, OutputBuffer, OutputBufferLength);
    }

    static void on_NtPrepareComplete(monitor::syscallswow64::Data& d)
    {
        const auto EnlistmentHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto TmVirtualClock   = arg<wntdll::PLARGE_INTEGER>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtPrepareComplete(EnlistmentHandle:{:#x}, TmVirtualClock:{:#x})", EnlistmentHandle, TmVirtualClock));

        for(const auto& it : d.observers_NtPrepareComplete)
            it(EnlistmentHandle, TmVirtualClock);
    }

    static void on_ZwPrepareEnlistment(monitor::syscallswow64::Data& d)
    {
        const auto EnlistmentHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto TmVirtualClock   = arg<wntdll::PLARGE_INTEGER>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwPrepareEnlistment(EnlistmentHandle:{:#x}, TmVirtualClock:{:#x})", EnlistmentHandle, TmVirtualClock));

        for(const auto& it : d.observers_ZwPrepareEnlistment)
            it(EnlistmentHandle, TmVirtualClock);
    }

    static void on_ZwPrePrepareComplete(monitor::syscallswow64::Data& d)
    {
        const auto EnlistmentHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto TmVirtualClock   = arg<wntdll::PLARGE_INTEGER>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwPrePrepareComplete(EnlistmentHandle:{:#x}, TmVirtualClock:{:#x})", EnlistmentHandle, TmVirtualClock));

        for(const auto& it : d.observers_ZwPrePrepareComplete)
            it(EnlistmentHandle, TmVirtualClock);
    }

    static void on_NtPrePrepareEnlistment(monitor::syscallswow64::Data& d)
    {
        const auto EnlistmentHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto TmVirtualClock   = arg<wntdll::PLARGE_INTEGER>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtPrePrepareEnlistment(EnlistmentHandle:{:#x}, TmVirtualClock:{:#x})", EnlistmentHandle, TmVirtualClock));

        for(const auto& it : d.observers_NtPrePrepareEnlistment)
            it(EnlistmentHandle, TmVirtualClock);
    }

    static void on_ZwPrivilegeCheck(monitor::syscallswow64::Data& d)
    {
        const auto ClientToken        = arg<wntdll::HANDLE>(d.core, 0);
        const auto RequiredPrivileges = arg<wntdll::PPRIVILEGE_SET>(d.core, 1);
        const auto Result             = arg<wntdll::PBOOLEAN>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwPrivilegeCheck(ClientToken:{:#x}, RequiredPrivileges:{:#x}, Result:{:#x})", ClientToken, RequiredPrivileges, Result));

        for(const auto& it : d.observers_ZwPrivilegeCheck)
            it(ClientToken, RequiredPrivileges, Result);
    }

    static void on_NtPrivilegedServiceAuditAlarm(monitor::syscallswow64::Data& d)
    {
        const auto SubsystemName = arg<wntdll::PUNICODE_STRING>(d.core, 0);
        const auto ServiceName   = arg<wntdll::PUNICODE_STRING>(d.core, 1);
        const auto ClientToken   = arg<wntdll::HANDLE>(d.core, 2);
        const auto Privileges    = arg<wntdll::PPRIVILEGE_SET>(d.core, 3);
        const auto AccessGranted = arg<wntdll::BOOLEAN>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtPrivilegedServiceAuditAlarm(SubsystemName:{:#x}, ServiceName:{:#x}, ClientToken:{:#x}, Privileges:{:#x}, AccessGranted:{:#x})", SubsystemName, ServiceName, ClientToken, Privileges, AccessGranted));

        for(const auto& it : d.observers_NtPrivilegedServiceAuditAlarm)
            it(SubsystemName, ServiceName, ClientToken, Privileges, AccessGranted);
    }

    static void on_ZwPrivilegeObjectAuditAlarm(monitor::syscallswow64::Data& d)
    {
        const auto SubsystemName = arg<wntdll::PUNICODE_STRING>(d.core, 0);
        const auto HandleId      = arg<wntdll::PVOID>(d.core, 1);
        const auto ClientToken   = arg<wntdll::HANDLE>(d.core, 2);
        const auto DesiredAccess = arg<wntdll::ACCESS_MASK>(d.core, 3);
        const auto Privileges    = arg<wntdll::PPRIVILEGE_SET>(d.core, 4);
        const auto AccessGranted = arg<wntdll::BOOLEAN>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwPrivilegeObjectAuditAlarm(SubsystemName:{:#x}, HandleId:{:#x}, ClientToken:{:#x}, DesiredAccess:{:#x}, Privileges:{:#x}, AccessGranted:{:#x})", SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, AccessGranted));

        for(const auto& it : d.observers_ZwPrivilegeObjectAuditAlarm)
            it(SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, AccessGranted);
    }

    static void on_NtPropagationComplete(monitor::syscallswow64::Data& d)
    {
        const auto ResourceManagerHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto RequestCookie         = arg<wntdll::ULONG>(d.core, 1);
        const auto BufferLength          = arg<wntdll::ULONG>(d.core, 2);
        const auto Buffer                = arg<wntdll::PVOID>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtPropagationComplete(ResourceManagerHandle:{:#x}, RequestCookie:{:#x}, BufferLength:{:#x}, Buffer:{:#x})", ResourceManagerHandle, RequestCookie, BufferLength, Buffer));

        for(const auto& it : d.observers_NtPropagationComplete)
            it(ResourceManagerHandle, RequestCookie, BufferLength, Buffer);
    }

    static void on_ZwPropagationFailed(monitor::syscallswow64::Data& d)
    {
        const auto ResourceManagerHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto RequestCookie         = arg<wntdll::ULONG>(d.core, 1);
        const auto PropStatus            = arg<wntdll::NTSTATUS>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwPropagationFailed(ResourceManagerHandle:{:#x}, RequestCookie:{:#x}, PropStatus:{:#x})", ResourceManagerHandle, RequestCookie, PropStatus));

        for(const auto& it : d.observers_ZwPropagationFailed)
            it(ResourceManagerHandle, RequestCookie, PropStatus);
    }

    static void on_ZwProtectVirtualMemory(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle   = arg<wntdll::HANDLE>(d.core, 0);
        const auto STARBaseAddress = arg<wntdll::PVOID>(d.core, 1);
        const auto RegionSize      = arg<wntdll::PSIZE_T>(d.core, 2);
        const auto NewProtectWin32 = arg<wntdll::WIN32_PROTECTION_MASK>(d.core, 3);
        const auto OldProtect      = arg<wntdll::PULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwProtectVirtualMemory(ProcessHandle:{:#x}, STARBaseAddress:{:#x}, RegionSize:{:#x}, NewProtectWin32:{:#x}, OldProtect:{:#x})", ProcessHandle, STARBaseAddress, RegionSize, NewProtectWin32, OldProtect));

        for(const auto& it : d.observers_ZwProtectVirtualMemory)
            it(ProcessHandle, STARBaseAddress, RegionSize, NewProtectWin32, OldProtect);
    }

    static void on_ZwPulseEvent(monitor::syscallswow64::Data& d)
    {
        const auto EventHandle   = arg<wntdll::HANDLE>(d.core, 0);
        const auto PreviousState = arg<wntdll::PLONG>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwPulseEvent(EventHandle:{:#x}, PreviousState:{:#x})", EventHandle, PreviousState));

        for(const auto& it : d.observers_ZwPulseEvent)
            it(EventHandle, PreviousState);
    }

    static void on_ZwQueryAttributesFile(monitor::syscallswow64::Data& d)
    {
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 0);
        const auto FileInformation  = arg<wntdll::PFILE_BASIC_INFORMATION>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQueryAttributesFile(ObjectAttributes:{:#x}, FileInformation:{:#x})", ObjectAttributes, FileInformation));

        for(const auto& it : d.observers_ZwQueryAttributesFile)
            it(ObjectAttributes, FileInformation);
    }

    static void on_ZwQueryBootEntryOrder(monitor::syscallswow64::Data& d)
    {
        const auto Ids   = arg<wntdll::PULONG>(d.core, 0);
        const auto Count = arg<wntdll::PULONG>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQueryBootEntryOrder(Ids:{:#x}, Count:{:#x})", Ids, Count));

        for(const auto& it : d.observers_ZwQueryBootEntryOrder)
            it(Ids, Count);
    }

    static void on_ZwQueryBootOptions(monitor::syscallswow64::Data& d)
    {
        const auto BootOptions       = arg<wntdll::PBOOT_OPTIONS>(d.core, 0);
        const auto BootOptionsLength = arg<wntdll::PULONG>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQueryBootOptions(BootOptions:{:#x}, BootOptionsLength:{:#x})", BootOptions, BootOptionsLength));

        for(const auto& it : d.observers_ZwQueryBootOptions)
            it(BootOptions, BootOptionsLength);
    }

    static void on_NtQueryDebugFilterState(monitor::syscallswow64::Data& d)
    {
        const auto ComponentId = arg<wntdll::ULONG>(d.core, 0);
        const auto Level       = arg<wntdll::ULONG>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtQueryDebugFilterState(ComponentId:{:#x}, Level:{:#x})", ComponentId, Level));

        for(const auto& it : d.observers_NtQueryDebugFilterState)
            it(ComponentId, Level);
    }

    static void on_NtQueryDefaultLocale(monitor::syscallswow64::Data& d)
    {
        const auto UserProfile     = arg<wntdll::BOOLEAN>(d.core, 0);
        const auto DefaultLocaleId = arg<wntdll::PLCID>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtQueryDefaultLocale(UserProfile:{:#x}, DefaultLocaleId:{:#x})", UserProfile, DefaultLocaleId));

        for(const auto& it : d.observers_NtQueryDefaultLocale)
            it(UserProfile, DefaultLocaleId);
    }

    static void on_ZwQueryDefaultUILanguage(monitor::syscallswow64::Data& d)
    {
        const auto STARDefaultUILanguageId = arg<wntdll::LANGID>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQueryDefaultUILanguage(STARDefaultUILanguageId:{:#x})", STARDefaultUILanguageId));

        for(const auto& it : d.observers_ZwQueryDefaultUILanguage)
            it(STARDefaultUILanguageId);
    }

    static void on_ZwQueryDirectoryFile(monitor::syscallswow64::Data& d)
    {
        const auto FileHandle           = arg<wntdll::HANDLE>(d.core, 0);
        const auto Event                = arg<wntdll::HANDLE>(d.core, 1);
        const auto ApcRoutine           = arg<wntdll::PIO_APC_ROUTINE>(d.core, 2);
        const auto ApcContext           = arg<wntdll::PVOID>(d.core, 3);
        const auto IoStatusBlock        = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 4);
        const auto FileInformation      = arg<wntdll::PVOID>(d.core, 5);
        const auto Length               = arg<wntdll::ULONG>(d.core, 6);
        const auto FileInformationClass = arg<wntdll::FILE_INFORMATION_CLASS>(d.core, 7);
        const auto ReturnSingleEntry    = arg<wntdll::BOOLEAN>(d.core, 8);
        const auto FileName             = arg<wntdll::PUNICODE_STRING>(d.core, 9);
        const auto RestartScan          = arg<wntdll::BOOLEAN>(d.core, 10);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQueryDirectoryFile(FileHandle:{:#x}, Event:{:#x}, ApcRoutine:{:#x}, ApcContext:{:#x}, IoStatusBlock:{:#x}, FileInformation:{:#x}, Length:{:#x}, FileInformationClass:{:#x}, ReturnSingleEntry:{:#x}, FileName:{:#x}, RestartScan:{:#x})", FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, FileInformation, Length, FileInformationClass, ReturnSingleEntry, FileName, RestartScan));

        for(const auto& it : d.observers_ZwQueryDirectoryFile)
            it(FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, FileInformation, Length, FileInformationClass, ReturnSingleEntry, FileName, RestartScan);
    }

    static void on_ZwQueryDirectoryObject(monitor::syscallswow64::Data& d)
    {
        const auto DirectoryHandle   = arg<wntdll::HANDLE>(d.core, 0);
        const auto Buffer            = arg<wntdll::PVOID>(d.core, 1);
        const auto Length            = arg<wntdll::ULONG>(d.core, 2);
        const auto ReturnSingleEntry = arg<wntdll::BOOLEAN>(d.core, 3);
        const auto RestartScan       = arg<wntdll::BOOLEAN>(d.core, 4);
        const auto Context           = arg<wntdll::PULONG>(d.core, 5);
        const auto ReturnLength      = arg<wntdll::PULONG>(d.core, 6);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQueryDirectoryObject(DirectoryHandle:{:#x}, Buffer:{:#x}, Length:{:#x}, ReturnSingleEntry:{:#x}, RestartScan:{:#x}, Context:{:#x}, ReturnLength:{:#x})", DirectoryHandle, Buffer, Length, ReturnSingleEntry, RestartScan, Context, ReturnLength));

        for(const auto& it : d.observers_ZwQueryDirectoryObject)
            it(DirectoryHandle, Buffer, Length, ReturnSingleEntry, RestartScan, Context, ReturnLength);
    }

    static void on_NtQueryDriverEntryOrder(monitor::syscallswow64::Data& d)
    {
        const auto Ids   = arg<wntdll::PULONG>(d.core, 0);
        const auto Count = arg<wntdll::PULONG>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtQueryDriverEntryOrder(Ids:{:#x}, Count:{:#x})", Ids, Count));

        for(const auto& it : d.observers_NtQueryDriverEntryOrder)
            it(Ids, Count);
    }

    static void on_ZwQueryEaFile(monitor::syscallswow64::Data& d)
    {
        const auto FileHandle        = arg<wntdll::HANDLE>(d.core, 0);
        const auto IoStatusBlock     = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 1);
        const auto Buffer            = arg<wntdll::PVOID>(d.core, 2);
        const auto Length            = arg<wntdll::ULONG>(d.core, 3);
        const auto ReturnSingleEntry = arg<wntdll::BOOLEAN>(d.core, 4);
        const auto EaList            = arg<wntdll::PVOID>(d.core, 5);
        const auto EaListLength      = arg<wntdll::ULONG>(d.core, 6);
        const auto EaIndex           = arg<wntdll::PULONG>(d.core, 7);
        const auto RestartScan       = arg<wntdll::BOOLEAN>(d.core, 8);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQueryEaFile(FileHandle:{:#x}, IoStatusBlock:{:#x}, Buffer:{:#x}, Length:{:#x}, ReturnSingleEntry:{:#x}, EaList:{:#x}, EaListLength:{:#x}, EaIndex:{:#x}, RestartScan:{:#x})", FileHandle, IoStatusBlock, Buffer, Length, ReturnSingleEntry, EaList, EaListLength, EaIndex, RestartScan));

        for(const auto& it : d.observers_ZwQueryEaFile)
            it(FileHandle, IoStatusBlock, Buffer, Length, ReturnSingleEntry, EaList, EaListLength, EaIndex, RestartScan);
    }

    static void on_NtQueryEvent(monitor::syscallswow64::Data& d)
    {
        const auto EventHandle            = arg<wntdll::HANDLE>(d.core, 0);
        const auto EventInformationClass  = arg<wntdll::EVENT_INFORMATION_CLASS>(d.core, 1);
        const auto EventInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto EventInformationLength = arg<wntdll::ULONG>(d.core, 3);
        const auto ReturnLength           = arg<wntdll::PULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtQueryEvent(EventHandle:{:#x}, EventInformationClass:{:#x}, EventInformation:{:#x}, EventInformationLength:{:#x}, ReturnLength:{:#x})", EventHandle, EventInformationClass, EventInformation, EventInformationLength, ReturnLength));

        for(const auto& it : d.observers_NtQueryEvent)
            it(EventHandle, EventInformationClass, EventInformation, EventInformationLength, ReturnLength);
    }

    static void on_ZwQueryFullAttributesFile(monitor::syscallswow64::Data& d)
    {
        const auto ObjectAttributes = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 0);
        const auto FileInformation  = arg<wntdll::PFILE_NETWORK_OPEN_INFORMATION>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQueryFullAttributesFile(ObjectAttributes:{:#x}, FileInformation:{:#x})", ObjectAttributes, FileInformation));

        for(const auto& it : d.observers_ZwQueryFullAttributesFile)
            it(ObjectAttributes, FileInformation);
    }

    static void on_NtQueryInformationAtom(monitor::syscallswow64::Data& d)
    {
        const auto Atom                  = arg<wntdll::RTL_ATOM>(d.core, 0);
        const auto InformationClass      = arg<wntdll::ATOM_INFORMATION_CLASS>(d.core, 1);
        const auto AtomInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto AtomInformationLength = arg<wntdll::ULONG>(d.core, 3);
        const auto ReturnLength          = arg<wntdll::PULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtQueryInformationAtom(Atom:{:#x}, InformationClass:{:#x}, AtomInformation:{:#x}, AtomInformationLength:{:#x}, ReturnLength:{:#x})", Atom, InformationClass, AtomInformation, AtomInformationLength, ReturnLength));

        for(const auto& it : d.observers_NtQueryInformationAtom)
            it(Atom, InformationClass, AtomInformation, AtomInformationLength, ReturnLength);
    }

    static void on_ZwQueryInformationEnlistment(monitor::syscallswow64::Data& d)
    {
        const auto EnlistmentHandle            = arg<wntdll::HANDLE>(d.core, 0);
        const auto EnlistmentInformationClass  = arg<wntdll::ENLISTMENT_INFORMATION_CLASS>(d.core, 1);
        const auto EnlistmentInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto EnlistmentInformationLength = arg<wntdll::ULONG>(d.core, 3);
        const auto ReturnLength                = arg<wntdll::PULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQueryInformationEnlistment(EnlistmentHandle:{:#x}, EnlistmentInformationClass:{:#x}, EnlistmentInformation:{:#x}, EnlistmentInformationLength:{:#x}, ReturnLength:{:#x})", EnlistmentHandle, EnlistmentInformationClass, EnlistmentInformation, EnlistmentInformationLength, ReturnLength));

        for(const auto& it : d.observers_ZwQueryInformationEnlistment)
            it(EnlistmentHandle, EnlistmentInformationClass, EnlistmentInformation, EnlistmentInformationLength, ReturnLength);
    }

    static void on_ZwQueryInformationFile(monitor::syscallswow64::Data& d)
    {
        const auto FileHandle           = arg<wntdll::HANDLE>(d.core, 0);
        const auto IoStatusBlock        = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 1);
        const auto FileInformation      = arg<wntdll::PVOID>(d.core, 2);
        const auto Length               = arg<wntdll::ULONG>(d.core, 3);
        const auto FileInformationClass = arg<wntdll::FILE_INFORMATION_CLASS>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQueryInformationFile(FileHandle:{:#x}, IoStatusBlock:{:#x}, FileInformation:{:#x}, Length:{:#x}, FileInformationClass:{:#x})", FileHandle, IoStatusBlock, FileInformation, Length, FileInformationClass));

        for(const auto& it : d.observers_ZwQueryInformationFile)
            it(FileHandle, IoStatusBlock, FileInformation, Length, FileInformationClass);
    }

    static void on_ZwQueryInformationJobObject(monitor::syscallswow64::Data& d)
    {
        const auto JobHandle                  = arg<wntdll::HANDLE>(d.core, 0);
        const auto JobObjectInformationClass  = arg<wntdll::JOBOBJECTINFOCLASS>(d.core, 1);
        const auto JobObjectInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto JobObjectInformationLength = arg<wntdll::ULONG>(d.core, 3);
        const auto ReturnLength               = arg<wntdll::PULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQueryInformationJobObject(JobHandle:{:#x}, JobObjectInformationClass:{:#x}, JobObjectInformation:{:#x}, JobObjectInformationLength:{:#x}, ReturnLength:{:#x})", JobHandle, JobObjectInformationClass, JobObjectInformation, JobObjectInformationLength, ReturnLength));

        for(const auto& it : d.observers_ZwQueryInformationJobObject)
            it(JobHandle, JobObjectInformationClass, JobObjectInformation, JobObjectInformationLength, ReturnLength);
    }

    static void on_ZwQueryInformationPort(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle           = arg<wntdll::HANDLE>(d.core, 0);
        const auto PortInformationClass = arg<wntdll::PORT_INFORMATION_CLASS>(d.core, 1);
        const auto PortInformation      = arg<wntdll::PVOID>(d.core, 2);
        const auto Length               = arg<wntdll::ULONG>(d.core, 3);
        const auto ReturnLength         = arg<wntdll::PULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQueryInformationPort(PortHandle:{:#x}, PortInformationClass:{:#x}, PortInformation:{:#x}, Length:{:#x}, ReturnLength:{:#x})", PortHandle, PortInformationClass, PortInformation, Length, ReturnLength));

        for(const auto& it : d.observers_ZwQueryInformationPort)
            it(PortHandle, PortInformationClass, PortInformation, Length, ReturnLength);
    }

    static void on_ZwQueryInformationProcess(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle            = arg<wntdll::HANDLE>(d.core, 0);
        const auto ProcessInformationClass  = arg<wntdll::PROCESSINFOCLASS>(d.core, 1);
        const auto ProcessInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto ProcessInformationLength = arg<wntdll::ULONG>(d.core, 3);
        const auto ReturnLength             = arg<wntdll::PULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQueryInformationProcess(ProcessHandle:{:#x}, ProcessInformationClass:{:#x}, ProcessInformation:{:#x}, ProcessInformationLength:{:#x}, ReturnLength:{:#x})", ProcessHandle, ProcessInformationClass, ProcessInformation, ProcessInformationLength, ReturnLength));

        for(const auto& it : d.observers_ZwQueryInformationProcess)
            it(ProcessHandle, ProcessInformationClass, ProcessInformation, ProcessInformationLength, ReturnLength);
    }

    static void on_ZwQueryInformationResourceManager(monitor::syscallswow64::Data& d)
    {
        const auto ResourceManagerHandle            = arg<wntdll::HANDLE>(d.core, 0);
        const auto ResourceManagerInformationClass  = arg<wntdll::RESOURCEMANAGER_INFORMATION_CLASS>(d.core, 1);
        const auto ResourceManagerInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto ResourceManagerInformationLength = arg<wntdll::ULONG>(d.core, 3);
        const auto ReturnLength                     = arg<wntdll::PULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQueryInformationResourceManager(ResourceManagerHandle:{:#x}, ResourceManagerInformationClass:{:#x}, ResourceManagerInformation:{:#x}, ResourceManagerInformationLength:{:#x}, ReturnLength:{:#x})", ResourceManagerHandle, ResourceManagerInformationClass, ResourceManagerInformation, ResourceManagerInformationLength, ReturnLength));

        for(const auto& it : d.observers_ZwQueryInformationResourceManager)
            it(ResourceManagerHandle, ResourceManagerInformationClass, ResourceManagerInformation, ResourceManagerInformationLength, ReturnLength);
    }

    static void on_NtQueryInformationThread(monitor::syscallswow64::Data& d)
    {
        const auto ThreadHandle            = arg<wntdll::HANDLE>(d.core, 0);
        const auto ThreadInformationClass  = arg<wntdll::THREADINFOCLASS>(d.core, 1);
        const auto ThreadInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto ThreadInformationLength = arg<wntdll::ULONG>(d.core, 3);
        const auto ReturnLength            = arg<wntdll::PULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtQueryInformationThread(ThreadHandle:{:#x}, ThreadInformationClass:{:#x}, ThreadInformation:{:#x}, ThreadInformationLength:{:#x}, ReturnLength:{:#x})", ThreadHandle, ThreadInformationClass, ThreadInformation, ThreadInformationLength, ReturnLength));

        for(const auto& it : d.observers_NtQueryInformationThread)
            it(ThreadHandle, ThreadInformationClass, ThreadInformation, ThreadInformationLength, ReturnLength);
    }

    static void on_ZwQueryInformationToken(monitor::syscallswow64::Data& d)
    {
        const auto TokenHandle            = arg<wntdll::HANDLE>(d.core, 0);
        const auto TokenInformationClass  = arg<wntdll::TOKEN_INFORMATION_CLASS>(d.core, 1);
        const auto TokenInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto TokenInformationLength = arg<wntdll::ULONG>(d.core, 3);
        const auto ReturnLength           = arg<wntdll::PULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQueryInformationToken(TokenHandle:{:#x}, TokenInformationClass:{:#x}, TokenInformation:{:#x}, TokenInformationLength:{:#x}, ReturnLength:{:#x})", TokenHandle, TokenInformationClass, TokenInformation, TokenInformationLength, ReturnLength));

        for(const auto& it : d.observers_ZwQueryInformationToken)
            it(TokenHandle, TokenInformationClass, TokenInformation, TokenInformationLength, ReturnLength);
    }

    static void on_ZwQueryInformationTransaction(monitor::syscallswow64::Data& d)
    {
        const auto TransactionHandle            = arg<wntdll::HANDLE>(d.core, 0);
        const auto TransactionInformationClass  = arg<wntdll::TRANSACTION_INFORMATION_CLASS>(d.core, 1);
        const auto TransactionInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto TransactionInformationLength = arg<wntdll::ULONG>(d.core, 3);
        const auto ReturnLength                 = arg<wntdll::PULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQueryInformationTransaction(TransactionHandle:{:#x}, TransactionInformationClass:{:#x}, TransactionInformation:{:#x}, TransactionInformationLength:{:#x}, ReturnLength:{:#x})", TransactionHandle, TransactionInformationClass, TransactionInformation, TransactionInformationLength, ReturnLength));

        for(const auto& it : d.observers_ZwQueryInformationTransaction)
            it(TransactionHandle, TransactionInformationClass, TransactionInformation, TransactionInformationLength, ReturnLength);
    }

    static void on_NtQueryInformationTransactionManager(monitor::syscallswow64::Data& d)
    {
        const auto TransactionManagerHandle            = arg<wntdll::HANDLE>(d.core, 0);
        const auto TransactionManagerInformationClass  = arg<wntdll::TRANSACTIONMANAGER_INFORMATION_CLASS>(d.core, 1);
        const auto TransactionManagerInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto TransactionManagerInformationLength = arg<wntdll::ULONG>(d.core, 3);
        const auto ReturnLength                        = arg<wntdll::PULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtQueryInformationTransactionManager(TransactionManagerHandle:{:#x}, TransactionManagerInformationClass:{:#x}, TransactionManagerInformation:{:#x}, TransactionManagerInformationLength:{:#x}, ReturnLength:{:#x})", TransactionManagerHandle, TransactionManagerInformationClass, TransactionManagerInformation, TransactionManagerInformationLength, ReturnLength));

        for(const auto& it : d.observers_NtQueryInformationTransactionManager)
            it(TransactionManagerHandle, TransactionManagerInformationClass, TransactionManagerInformation, TransactionManagerInformationLength, ReturnLength);
    }

    static void on_ZwQueryInformationWorkerFactory(monitor::syscallswow64::Data& d)
    {
        const auto WorkerFactoryHandle            = arg<wntdll::HANDLE>(d.core, 0);
        const auto WorkerFactoryInformationClass  = arg<wntdll::WORKERFACTORYINFOCLASS>(d.core, 1);
        const auto WorkerFactoryInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto WorkerFactoryInformationLength = arg<wntdll::ULONG>(d.core, 3);
        const auto ReturnLength                   = arg<wntdll::PULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQueryInformationWorkerFactory(WorkerFactoryHandle:{:#x}, WorkerFactoryInformationClass:{:#x}, WorkerFactoryInformation:{:#x}, WorkerFactoryInformationLength:{:#x}, ReturnLength:{:#x})", WorkerFactoryHandle, WorkerFactoryInformationClass, WorkerFactoryInformation, WorkerFactoryInformationLength, ReturnLength));

        for(const auto& it : d.observers_ZwQueryInformationWorkerFactory)
            it(WorkerFactoryHandle, WorkerFactoryInformationClass, WorkerFactoryInformation, WorkerFactoryInformationLength, ReturnLength);
    }

    static void on_NtQueryInstallUILanguage(monitor::syscallswow64::Data& d)
    {
        const auto STARInstallUILanguageId = arg<wntdll::LANGID>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtQueryInstallUILanguage(STARInstallUILanguageId:{:#x})", STARInstallUILanguageId));

        for(const auto& it : d.observers_NtQueryInstallUILanguage)
            it(STARInstallUILanguageId);
    }

    static void on_NtQueryIntervalProfile(monitor::syscallswow64::Data& d)
    {
        const auto ProfileSource = arg<wntdll::KPROFILE_SOURCE>(d.core, 0);
        const auto Interval      = arg<wntdll::PULONG>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtQueryIntervalProfile(ProfileSource:{:#x}, Interval:{:#x})", ProfileSource, Interval));

        for(const auto& it : d.observers_NtQueryIntervalProfile)
            it(ProfileSource, Interval);
    }

    static void on_NtQueryIoCompletion(monitor::syscallswow64::Data& d)
    {
        const auto IoCompletionHandle            = arg<wntdll::HANDLE>(d.core, 0);
        const auto IoCompletionInformationClass  = arg<wntdll::IO_COMPLETION_INFORMATION_CLASS>(d.core, 1);
        const auto IoCompletionInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto IoCompletionInformationLength = arg<wntdll::ULONG>(d.core, 3);
        const auto ReturnLength                  = arg<wntdll::PULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtQueryIoCompletion(IoCompletionHandle:{:#x}, IoCompletionInformationClass:{:#x}, IoCompletionInformation:{:#x}, IoCompletionInformationLength:{:#x}, ReturnLength:{:#x})", IoCompletionHandle, IoCompletionInformationClass, IoCompletionInformation, IoCompletionInformationLength, ReturnLength));

        for(const auto& it : d.observers_NtQueryIoCompletion)
            it(IoCompletionHandle, IoCompletionInformationClass, IoCompletionInformation, IoCompletionInformationLength, ReturnLength);
    }

    static void on_ZwQueryKey(monitor::syscallswow64::Data& d)
    {
        const auto KeyHandle           = arg<wntdll::HANDLE>(d.core, 0);
        const auto KeyInformationClass = arg<wntdll::KEY_INFORMATION_CLASS>(d.core, 1);
        const auto KeyInformation      = arg<wntdll::PVOID>(d.core, 2);
        const auto Length              = arg<wntdll::ULONG>(d.core, 3);
        const auto ResultLength        = arg<wntdll::PULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQueryKey(KeyHandle:{:#x}, KeyInformationClass:{:#x}, KeyInformation:{:#x}, Length:{:#x}, ResultLength:{:#x})", KeyHandle, KeyInformationClass, KeyInformation, Length, ResultLength));

        for(const auto& it : d.observers_ZwQueryKey)
            it(KeyHandle, KeyInformationClass, KeyInformation, Length, ResultLength);
    }

    static void on_NtQueryLicenseValue(monitor::syscallswow64::Data& d)
    {
        const auto Name           = arg<wntdll::PUNICODE_STRING>(d.core, 0);
        const auto Type           = arg<wntdll::PULONG>(d.core, 1);
        const auto Buffer         = arg<wntdll::PVOID>(d.core, 2);
        const auto Length         = arg<wntdll::ULONG>(d.core, 3);
        const auto ReturnedLength = arg<wntdll::PULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtQueryLicenseValue(Name:{:#x}, Type:{:#x}, Buffer:{:#x}, Length:{:#x}, ReturnedLength:{:#x})", Name, Type, Buffer, Length, ReturnedLength));

        for(const auto& it : d.observers_NtQueryLicenseValue)
            it(Name, Type, Buffer, Length, ReturnedLength);
    }

    static void on_NtQueryMultipleValueKey(monitor::syscallswow64::Data& d)
    {
        const auto KeyHandle            = arg<wntdll::HANDLE>(d.core, 0);
        const auto ValueEntries         = arg<wntdll::PKEY_VALUE_ENTRY>(d.core, 1);
        const auto EntryCount           = arg<wntdll::ULONG>(d.core, 2);
        const auto ValueBuffer          = arg<wntdll::PVOID>(d.core, 3);
        const auto BufferLength         = arg<wntdll::PULONG>(d.core, 4);
        const auto RequiredBufferLength = arg<wntdll::PULONG>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtQueryMultipleValueKey(KeyHandle:{:#x}, ValueEntries:{:#x}, EntryCount:{:#x}, ValueBuffer:{:#x}, BufferLength:{:#x}, RequiredBufferLength:{:#x})", KeyHandle, ValueEntries, EntryCount, ValueBuffer, BufferLength, RequiredBufferLength));

        for(const auto& it : d.observers_NtQueryMultipleValueKey)
            it(KeyHandle, ValueEntries, EntryCount, ValueBuffer, BufferLength, RequiredBufferLength);
    }

    static void on_NtQueryMutant(monitor::syscallswow64::Data& d)
    {
        const auto MutantHandle            = arg<wntdll::HANDLE>(d.core, 0);
        const auto MutantInformationClass  = arg<wntdll::MUTANT_INFORMATION_CLASS>(d.core, 1);
        const auto MutantInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto MutantInformationLength = arg<wntdll::ULONG>(d.core, 3);
        const auto ReturnLength            = arg<wntdll::PULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtQueryMutant(MutantHandle:{:#x}, MutantInformationClass:{:#x}, MutantInformation:{:#x}, MutantInformationLength:{:#x}, ReturnLength:{:#x})", MutantHandle, MutantInformationClass, MutantInformation, MutantInformationLength, ReturnLength));

        for(const auto& it : d.observers_NtQueryMutant)
            it(MutantHandle, MutantInformationClass, MutantInformation, MutantInformationLength, ReturnLength);
    }

    static void on_NtQueryObject(monitor::syscallswow64::Data& d)
    {
        const auto Handle                  = arg<wntdll::HANDLE>(d.core, 0);
        const auto ObjectInformationClass  = arg<wntdll::OBJECT_INFORMATION_CLASS>(d.core, 1);
        const auto ObjectInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto ObjectInformationLength = arg<wntdll::ULONG>(d.core, 3);
        const auto ReturnLength            = arg<wntdll::PULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtQueryObject(Handle:{:#x}, ObjectInformationClass:{:#x}, ObjectInformation:{:#x}, ObjectInformationLength:{:#x}, ReturnLength:{:#x})", Handle, ObjectInformationClass, ObjectInformation, ObjectInformationLength, ReturnLength));

        for(const auto& it : d.observers_NtQueryObject)
            it(Handle, ObjectInformationClass, ObjectInformation, ObjectInformationLength, ReturnLength);
    }

    static void on_NtQueryOpenSubKeysEx(monitor::syscallswow64::Data& d)
    {
        const auto TargetKey    = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 0);
        const auto BufferLength = arg<wntdll::ULONG>(d.core, 1);
        const auto Buffer       = arg<wntdll::PVOID>(d.core, 2);
        const auto RequiredSize = arg<wntdll::PULONG>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtQueryOpenSubKeysEx(TargetKey:{:#x}, BufferLength:{:#x}, Buffer:{:#x}, RequiredSize:{:#x})", TargetKey, BufferLength, Buffer, RequiredSize));

        for(const auto& it : d.observers_NtQueryOpenSubKeysEx)
            it(TargetKey, BufferLength, Buffer, RequiredSize);
    }

    static void on_NtQueryOpenSubKeys(monitor::syscallswow64::Data& d)
    {
        const auto TargetKey   = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 0);
        const auto HandleCount = arg<wntdll::PULONG>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtQueryOpenSubKeys(TargetKey:{:#x}, HandleCount:{:#x})", TargetKey, HandleCount));

        for(const auto& it : d.observers_NtQueryOpenSubKeys)
            it(TargetKey, HandleCount);
    }

    static void on_NtQueryPerformanceCounter(monitor::syscallswow64::Data& d)
    {
        const auto PerformanceCounter   = arg<wntdll::PLARGE_INTEGER>(d.core, 0);
        const auto PerformanceFrequency = arg<wntdll::PLARGE_INTEGER>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtQueryPerformanceCounter(PerformanceCounter:{:#x}, PerformanceFrequency:{:#x})", PerformanceCounter, PerformanceFrequency));

        for(const auto& it : d.observers_NtQueryPerformanceCounter)
            it(PerformanceCounter, PerformanceFrequency);
    }

    static void on_ZwQueryQuotaInformationFile(monitor::syscallswow64::Data& d)
    {
        const auto FileHandle        = arg<wntdll::HANDLE>(d.core, 0);
        const auto IoStatusBlock     = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 1);
        const auto Buffer            = arg<wntdll::PVOID>(d.core, 2);
        const auto Length            = arg<wntdll::ULONG>(d.core, 3);
        const auto ReturnSingleEntry = arg<wntdll::BOOLEAN>(d.core, 4);
        const auto SidList           = arg<wntdll::PVOID>(d.core, 5);
        const auto SidListLength     = arg<wntdll::ULONG>(d.core, 6);
        const auto StartSid          = arg<wntdll::PULONG>(d.core, 7);
        const auto RestartScan       = arg<wntdll::BOOLEAN>(d.core, 8);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQueryQuotaInformationFile(FileHandle:{:#x}, IoStatusBlock:{:#x}, Buffer:{:#x}, Length:{:#x}, ReturnSingleEntry:{:#x}, SidList:{:#x}, SidListLength:{:#x}, StartSid:{:#x}, RestartScan:{:#x})", FileHandle, IoStatusBlock, Buffer, Length, ReturnSingleEntry, SidList, SidListLength, StartSid, RestartScan));

        for(const auto& it : d.observers_ZwQueryQuotaInformationFile)
            it(FileHandle, IoStatusBlock, Buffer, Length, ReturnSingleEntry, SidList, SidListLength, StartSid, RestartScan);
    }

    static void on_ZwQuerySection(monitor::syscallswow64::Data& d)
    {
        const auto SectionHandle            = arg<wntdll::HANDLE>(d.core, 0);
        const auto SectionInformationClass  = arg<wntdll::SECTION_INFORMATION_CLASS>(d.core, 1);
        const auto SectionInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto SectionInformationLength = arg<wntdll::SIZE_T>(d.core, 3);
        const auto ReturnLength             = arg<wntdll::PSIZE_T>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQuerySection(SectionHandle:{:#x}, SectionInformationClass:{:#x}, SectionInformation:{:#x}, SectionInformationLength:{:#x}, ReturnLength:{:#x})", SectionHandle, SectionInformationClass, SectionInformation, SectionInformationLength, ReturnLength));

        for(const auto& it : d.observers_ZwQuerySection)
            it(SectionHandle, SectionInformationClass, SectionInformation, SectionInformationLength, ReturnLength);
    }

    static void on_ZwQuerySecurityAttributesToken(monitor::syscallswow64::Data& d)
    {
        const auto TokenHandle        = arg<wntdll::HANDLE>(d.core, 0);
        const auto Attributes         = arg<wntdll::PUNICODE_STRING>(d.core, 1);
        const auto NumberOfAttributes = arg<wntdll::ULONG>(d.core, 2);
        const auto Buffer             = arg<wntdll::PVOID>(d.core, 3);
        const auto Length             = arg<wntdll::ULONG>(d.core, 4);
        const auto ReturnLength       = arg<wntdll::PULONG>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQuerySecurityAttributesToken(TokenHandle:{:#x}, Attributes:{:#x}, NumberOfAttributes:{:#x}, Buffer:{:#x}, Length:{:#x}, ReturnLength:{:#x})", TokenHandle, Attributes, NumberOfAttributes, Buffer, Length, ReturnLength));

        for(const auto& it : d.observers_ZwQuerySecurityAttributesToken)
            it(TokenHandle, Attributes, NumberOfAttributes, Buffer, Length, ReturnLength);
    }

    static void on_NtQuerySecurityObject(monitor::syscallswow64::Data& d)
    {
        const auto Handle              = arg<wntdll::HANDLE>(d.core, 0);
        const auto SecurityInformation = arg<wntdll::SECURITY_INFORMATION>(d.core, 1);
        const auto SecurityDescriptor  = arg<wntdll::PSECURITY_DESCRIPTOR>(d.core, 2);
        const auto Length              = arg<wntdll::ULONG>(d.core, 3);
        const auto LengthNeeded        = arg<wntdll::PULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtQuerySecurityObject(Handle:{:#x}, SecurityInformation:{:#x}, SecurityDescriptor:{:#x}, Length:{:#x}, LengthNeeded:{:#x})", Handle, SecurityInformation, SecurityDescriptor, Length, LengthNeeded));

        for(const auto& it : d.observers_NtQuerySecurityObject)
            it(Handle, SecurityInformation, SecurityDescriptor, Length, LengthNeeded);
    }

    static void on_ZwQuerySemaphore(monitor::syscallswow64::Data& d)
    {
        const auto SemaphoreHandle            = arg<wntdll::HANDLE>(d.core, 0);
        const auto SemaphoreInformationClass  = arg<wntdll::SEMAPHORE_INFORMATION_CLASS>(d.core, 1);
        const auto SemaphoreInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto SemaphoreInformationLength = arg<wntdll::ULONG>(d.core, 3);
        const auto ReturnLength               = arg<wntdll::PULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQuerySemaphore(SemaphoreHandle:{:#x}, SemaphoreInformationClass:{:#x}, SemaphoreInformation:{:#x}, SemaphoreInformationLength:{:#x}, ReturnLength:{:#x})", SemaphoreHandle, SemaphoreInformationClass, SemaphoreInformation, SemaphoreInformationLength, ReturnLength));

        for(const auto& it : d.observers_ZwQuerySemaphore)
            it(SemaphoreHandle, SemaphoreInformationClass, SemaphoreInformation, SemaphoreInformationLength, ReturnLength);
    }

    static void on_ZwQuerySymbolicLinkObject(monitor::syscallswow64::Data& d)
    {
        const auto LinkHandle     = arg<wntdll::HANDLE>(d.core, 0);
        const auto LinkTarget     = arg<wntdll::PUNICODE_STRING>(d.core, 1);
        const auto ReturnedLength = arg<wntdll::PULONG>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQuerySymbolicLinkObject(LinkHandle:{:#x}, LinkTarget:{:#x}, ReturnedLength:{:#x})", LinkHandle, LinkTarget, ReturnedLength));

        for(const auto& it : d.observers_ZwQuerySymbolicLinkObject)
            it(LinkHandle, LinkTarget, ReturnedLength);
    }

    static void on_ZwQuerySystemEnvironmentValueEx(monitor::syscallswow64::Data& d)
    {
        const auto VariableName = arg<wntdll::PUNICODE_STRING>(d.core, 0);
        const auto VendorGuid   = arg<wntdll::LPGUID>(d.core, 1);
        const auto Value        = arg<wntdll::PVOID>(d.core, 2);
        const auto ValueLength  = arg<wntdll::PULONG>(d.core, 3);
        const auto Attributes   = arg<wntdll::PULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQuerySystemEnvironmentValueEx(VariableName:{:#x}, VendorGuid:{:#x}, Value:{:#x}, ValueLength:{:#x}, Attributes:{:#x})", VariableName, VendorGuid, Value, ValueLength, Attributes));

        for(const auto& it : d.observers_ZwQuerySystemEnvironmentValueEx)
            it(VariableName, VendorGuid, Value, ValueLength, Attributes);
    }

    static void on_ZwQuerySystemEnvironmentValue(monitor::syscallswow64::Data& d)
    {
        const auto VariableName  = arg<wntdll::PUNICODE_STRING>(d.core, 0);
        const auto VariableValue = arg<wntdll::PWSTR>(d.core, 1);
        const auto ValueLength   = arg<wntdll::USHORT>(d.core, 2);
        const auto ReturnLength  = arg<wntdll::PUSHORT>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQuerySystemEnvironmentValue(VariableName:{:#x}, VariableValue:{:#x}, ValueLength:{:#x}, ReturnLength:{:#x})", VariableName, VariableValue, ValueLength, ReturnLength));

        for(const auto& it : d.observers_ZwQuerySystemEnvironmentValue)
            it(VariableName, VariableValue, ValueLength, ReturnLength);
    }

    static void on_ZwQuerySystemInformationEx(monitor::syscallswow64::Data& d)
    {
        const auto SystemInformationClass  = arg<wntdll::SYSTEM_INFORMATION_CLASS>(d.core, 0);
        const auto QueryInformation        = arg<wntdll::PVOID>(d.core, 1);
        const auto QueryInformationLength  = arg<wntdll::ULONG>(d.core, 2);
        const auto SystemInformation       = arg<wntdll::PVOID>(d.core, 3);
        const auto SystemInformationLength = arg<wntdll::ULONG>(d.core, 4);
        const auto ReturnLength            = arg<wntdll::PULONG>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQuerySystemInformationEx(SystemInformationClass:{:#x}, QueryInformation:{:#x}, QueryInformationLength:{:#x}, SystemInformation:{:#x}, SystemInformationLength:{:#x}, ReturnLength:{:#x})", SystemInformationClass, QueryInformation, QueryInformationLength, SystemInformation, SystemInformationLength, ReturnLength));

        for(const auto& it : d.observers_ZwQuerySystemInformationEx)
            it(SystemInformationClass, QueryInformation, QueryInformationLength, SystemInformation, SystemInformationLength, ReturnLength);
    }

    static void on_NtQuerySystemInformation(monitor::syscallswow64::Data& d)
    {
        const auto SystemInformationClass  = arg<wntdll::SYSTEM_INFORMATION_CLASS>(d.core, 0);
        const auto SystemInformation       = arg<wntdll::PVOID>(d.core, 1);
        const auto SystemInformationLength = arg<wntdll::ULONG>(d.core, 2);
        const auto ReturnLength            = arg<wntdll::PULONG>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtQuerySystemInformation(SystemInformationClass:{:#x}, SystemInformation:{:#x}, SystemInformationLength:{:#x}, ReturnLength:{:#x})", SystemInformationClass, SystemInformation, SystemInformationLength, ReturnLength));

        for(const auto& it : d.observers_NtQuerySystemInformation)
            it(SystemInformationClass, SystemInformation, SystemInformationLength, ReturnLength);
    }

    static void on_NtQuerySystemTime(monitor::syscallswow64::Data& d)
    {
        const auto SystemTime = arg<wntdll::PLARGE_INTEGER>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtQuerySystemTime(SystemTime:{:#x})", SystemTime));

        for(const auto& it : d.observers_NtQuerySystemTime)
            it(SystemTime);
    }

    static void on_ZwQueryTimer(monitor::syscallswow64::Data& d)
    {
        const auto TimerHandle            = arg<wntdll::HANDLE>(d.core, 0);
        const auto TimerInformationClass  = arg<wntdll::TIMER_INFORMATION_CLASS>(d.core, 1);
        const auto TimerInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto TimerInformationLength = arg<wntdll::ULONG>(d.core, 3);
        const auto ReturnLength           = arg<wntdll::PULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQueryTimer(TimerHandle:{:#x}, TimerInformationClass:{:#x}, TimerInformation:{:#x}, TimerInformationLength:{:#x}, ReturnLength:{:#x})", TimerHandle, TimerInformationClass, TimerInformation, TimerInformationLength, ReturnLength));

        for(const auto& it : d.observers_ZwQueryTimer)
            it(TimerHandle, TimerInformationClass, TimerInformation, TimerInformationLength, ReturnLength);
    }

    static void on_NtQueryTimerResolution(monitor::syscallswow64::Data& d)
    {
        const auto MaximumTime = arg<wntdll::PULONG>(d.core, 0);
        const auto MinimumTime = arg<wntdll::PULONG>(d.core, 1);
        const auto CurrentTime = arg<wntdll::PULONG>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtQueryTimerResolution(MaximumTime:{:#x}, MinimumTime:{:#x}, CurrentTime:{:#x})", MaximumTime, MinimumTime, CurrentTime));

        for(const auto& it : d.observers_NtQueryTimerResolution)
            it(MaximumTime, MinimumTime, CurrentTime);
    }

    static void on_ZwQueryValueKey(monitor::syscallswow64::Data& d)
    {
        const auto KeyHandle                = arg<wntdll::HANDLE>(d.core, 0);
        const auto ValueName                = arg<wntdll::PUNICODE_STRING>(d.core, 1);
        const auto KeyValueInformationClass = arg<wntdll::KEY_VALUE_INFORMATION_CLASS>(d.core, 2);
        const auto KeyValueInformation      = arg<wntdll::PVOID>(d.core, 3);
        const auto Length                   = arg<wntdll::ULONG>(d.core, 4);
        const auto ResultLength             = arg<wntdll::PULONG>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQueryValueKey(KeyHandle:{:#x}, ValueName:{:#x}, KeyValueInformationClass:{:#x}, KeyValueInformation:{:#x}, Length:{:#x}, ResultLength:{:#x})", KeyHandle, ValueName, KeyValueInformationClass, KeyValueInformation, Length, ResultLength));

        for(const auto& it : d.observers_ZwQueryValueKey)
            it(KeyHandle, ValueName, KeyValueInformationClass, KeyValueInformation, Length, ResultLength);
    }

    static void on_NtQueryVirtualMemory(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle           = arg<wntdll::HANDLE>(d.core, 0);
        const auto BaseAddress             = arg<wntdll::PVOID>(d.core, 1);
        const auto MemoryInformationClass  = arg<wntdll::MEMORY_INFORMATION_CLASS>(d.core, 2);
        const auto MemoryInformation       = arg<wntdll::PVOID>(d.core, 3);
        const auto MemoryInformationLength = arg<wntdll::SIZE_T>(d.core, 4);
        const auto ReturnLength            = arg<wntdll::PSIZE_T>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtQueryVirtualMemory(ProcessHandle:{:#x}, BaseAddress:{:#x}, MemoryInformationClass:{:#x}, MemoryInformation:{:#x}, MemoryInformationLength:{:#x}, ReturnLength:{:#x})", ProcessHandle, BaseAddress, MemoryInformationClass, MemoryInformation, MemoryInformationLength, ReturnLength));

        for(const auto& it : d.observers_NtQueryVirtualMemory)
            it(ProcessHandle, BaseAddress, MemoryInformationClass, MemoryInformation, MemoryInformationLength, ReturnLength);
    }

    static void on_NtQueryVolumeInformationFile(monitor::syscallswow64::Data& d)
    {
        const auto FileHandle         = arg<wntdll::HANDLE>(d.core, 0);
        const auto IoStatusBlock      = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 1);
        const auto FsInformation      = arg<wntdll::PVOID>(d.core, 2);
        const auto Length             = arg<wntdll::ULONG>(d.core, 3);
        const auto FsInformationClass = arg<wntdll::FS_INFORMATION_CLASS>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtQueryVolumeInformationFile(FileHandle:{:#x}, IoStatusBlock:{:#x}, FsInformation:{:#x}, Length:{:#x}, FsInformationClass:{:#x})", FileHandle, IoStatusBlock, FsInformation, Length, FsInformationClass));

        for(const auto& it : d.observers_NtQueryVolumeInformationFile)
            it(FileHandle, IoStatusBlock, FsInformation, Length, FsInformationClass);
    }

    static void on_NtQueueApcThreadEx(monitor::syscallswow64::Data& d)
    {
        const auto ThreadHandle         = arg<wntdll::HANDLE>(d.core, 0);
        const auto UserApcReserveHandle = arg<wntdll::HANDLE>(d.core, 1);
        const auto ApcRoutine           = arg<wntdll::PPS_APC_ROUTINE>(d.core, 2);
        const auto ApcArgument1         = arg<wntdll::PVOID>(d.core, 3);
        const auto ApcArgument2         = arg<wntdll::PVOID>(d.core, 4);
        const auto ApcArgument3         = arg<wntdll::PVOID>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtQueueApcThreadEx(ThreadHandle:{:#x}, UserApcReserveHandle:{:#x}, ApcRoutine:{:#x}, ApcArgument1:{:#x}, ApcArgument2:{:#x}, ApcArgument3:{:#x})", ThreadHandle, UserApcReserveHandle, ApcRoutine, ApcArgument1, ApcArgument2, ApcArgument3));

        for(const auto& it : d.observers_NtQueueApcThreadEx)
            it(ThreadHandle, UserApcReserveHandle, ApcRoutine, ApcArgument1, ApcArgument2, ApcArgument3);
    }

    static void on_NtQueueApcThread(monitor::syscallswow64::Data& d)
    {
        const auto ThreadHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto ApcRoutine   = arg<wntdll::PPS_APC_ROUTINE>(d.core, 1);
        const auto ApcArgument1 = arg<wntdll::PVOID>(d.core, 2);
        const auto ApcArgument2 = arg<wntdll::PVOID>(d.core, 3);
        const auto ApcArgument3 = arg<wntdll::PVOID>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtQueueApcThread(ThreadHandle:{:#x}, ApcRoutine:{:#x}, ApcArgument1:{:#x}, ApcArgument2:{:#x}, ApcArgument3:{:#x})", ThreadHandle, ApcRoutine, ApcArgument1, ApcArgument2, ApcArgument3));

        for(const auto& it : d.observers_NtQueueApcThread)
            it(ThreadHandle, ApcRoutine, ApcArgument1, ApcArgument2, ApcArgument3);
    }

    static void on_ZwRaiseException(monitor::syscallswow64::Data& d)
    {
        const auto ExceptionRecord = arg<wntdll::PEXCEPTION_RECORD>(d.core, 0);
        const auto ContextRecord   = arg<wntdll::PCONTEXT>(d.core, 1);
        const auto FirstChance     = arg<wntdll::BOOLEAN>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwRaiseException(ExceptionRecord:{:#x}, ContextRecord:{:#x}, FirstChance:{:#x})", ExceptionRecord, ContextRecord, FirstChance));

        for(const auto& it : d.observers_ZwRaiseException)
            it(ExceptionRecord, ContextRecord, FirstChance);
    }

    static void on_ZwRaiseHardError(monitor::syscallswow64::Data& d)
    {
        const auto ErrorStatus                = arg<wntdll::NTSTATUS>(d.core, 0);
        const auto NumberOfParameters         = arg<wntdll::ULONG>(d.core, 1);
        const auto UnicodeStringParameterMask = arg<wntdll::ULONG>(d.core, 2);
        const auto Parameters                 = arg<wntdll::PULONG_PTR>(d.core, 3);
        const auto ValidResponseOptions       = arg<wntdll::ULONG>(d.core, 4);
        const auto Response                   = arg<wntdll::PULONG>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwRaiseHardError(ErrorStatus:{:#x}, NumberOfParameters:{:#x}, UnicodeStringParameterMask:{:#x}, Parameters:{:#x}, ValidResponseOptions:{:#x}, Response:{:#x})", ErrorStatus, NumberOfParameters, UnicodeStringParameterMask, Parameters, ValidResponseOptions, Response));

        for(const auto& it : d.observers_ZwRaiseHardError)
            it(ErrorStatus, NumberOfParameters, UnicodeStringParameterMask, Parameters, ValidResponseOptions, Response);
    }

    static void on_NtReadFile(monitor::syscallswow64::Data& d)
    {
        const auto FileHandle    = arg<wntdll::HANDLE>(d.core, 0);
        const auto Event         = arg<wntdll::HANDLE>(d.core, 1);
        const auto ApcRoutine    = arg<wntdll::PIO_APC_ROUTINE>(d.core, 2);
        const auto ApcContext    = arg<wntdll::PVOID>(d.core, 3);
        const auto IoStatusBlock = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 4);
        const auto Buffer        = arg<wntdll::PVOID>(d.core, 5);
        const auto Length        = arg<wntdll::ULONG>(d.core, 6);
        const auto ByteOffset    = arg<wntdll::PLARGE_INTEGER>(d.core, 7);
        const auto Key           = arg<wntdll::PULONG>(d.core, 8);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtReadFile(FileHandle:{:#x}, Event:{:#x}, ApcRoutine:{:#x}, ApcContext:{:#x}, IoStatusBlock:{:#x}, Buffer:{:#x}, Length:{:#x}, ByteOffset:{:#x}, Key:{:#x})", FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, Buffer, Length, ByteOffset, Key));

        for(const auto& it : d.observers_NtReadFile)
            it(FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, Buffer, Length, ByteOffset, Key);
    }

    static void on_NtReadFileScatter(monitor::syscallswow64::Data& d)
    {
        const auto FileHandle    = arg<wntdll::HANDLE>(d.core, 0);
        const auto Event         = arg<wntdll::HANDLE>(d.core, 1);
        const auto ApcRoutine    = arg<wntdll::PIO_APC_ROUTINE>(d.core, 2);
        const auto ApcContext    = arg<wntdll::PVOID>(d.core, 3);
        const auto IoStatusBlock = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 4);
        const auto SegmentArray  = arg<wntdll::PFILE_SEGMENT_ELEMENT>(d.core, 5);
        const auto Length        = arg<wntdll::ULONG>(d.core, 6);
        const auto ByteOffset    = arg<wntdll::PLARGE_INTEGER>(d.core, 7);
        const auto Key           = arg<wntdll::PULONG>(d.core, 8);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtReadFileScatter(FileHandle:{:#x}, Event:{:#x}, ApcRoutine:{:#x}, ApcContext:{:#x}, IoStatusBlock:{:#x}, SegmentArray:{:#x}, Length:{:#x}, ByteOffset:{:#x}, Key:{:#x})", FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, SegmentArray, Length, ByteOffset, Key));

        for(const auto& it : d.observers_NtReadFileScatter)
            it(FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, SegmentArray, Length, ByteOffset, Key);
    }

    static void on_ZwReadOnlyEnlistment(monitor::syscallswow64::Data& d)
    {
        const auto EnlistmentHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto TmVirtualClock   = arg<wntdll::PLARGE_INTEGER>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwReadOnlyEnlistment(EnlistmentHandle:{:#x}, TmVirtualClock:{:#x})", EnlistmentHandle, TmVirtualClock));

        for(const auto& it : d.observers_ZwReadOnlyEnlistment)
            it(EnlistmentHandle, TmVirtualClock);
    }

    static void on_ZwReadRequestData(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle        = arg<wntdll::HANDLE>(d.core, 0);
        const auto Message           = arg<wntdll::PPORT_MESSAGE>(d.core, 1);
        const auto DataEntryIndex    = arg<wntdll::ULONG>(d.core, 2);
        const auto Buffer            = arg<wntdll::PVOID>(d.core, 3);
        const auto BufferSize        = arg<wntdll::SIZE_T>(d.core, 4);
        const auto NumberOfBytesRead = arg<wntdll::PSIZE_T>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwReadRequestData(PortHandle:{:#x}, Message:{:#x}, DataEntryIndex:{:#x}, Buffer:{:#x}, BufferSize:{:#x}, NumberOfBytesRead:{:#x})", PortHandle, Message, DataEntryIndex, Buffer, BufferSize, NumberOfBytesRead));

        for(const auto& it : d.observers_ZwReadRequestData)
            it(PortHandle, Message, DataEntryIndex, Buffer, BufferSize, NumberOfBytesRead);
    }

    static void on_NtReadVirtualMemory(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle     = arg<wntdll::HANDLE>(d.core, 0);
        const auto BaseAddress       = arg<wntdll::PVOID>(d.core, 1);
        const auto Buffer            = arg<wntdll::PVOID>(d.core, 2);
        const auto BufferSize        = arg<wntdll::SIZE_T>(d.core, 3);
        const auto NumberOfBytesRead = arg<wntdll::PSIZE_T>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtReadVirtualMemory(ProcessHandle:{:#x}, BaseAddress:{:#x}, Buffer:{:#x}, BufferSize:{:#x}, NumberOfBytesRead:{:#x})", ProcessHandle, BaseAddress, Buffer, BufferSize, NumberOfBytesRead));

        for(const auto& it : d.observers_NtReadVirtualMemory)
            it(ProcessHandle, BaseAddress, Buffer, BufferSize, NumberOfBytesRead);
    }

    static void on_NtRecoverEnlistment(monitor::syscallswow64::Data& d)
    {
        const auto EnlistmentHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto EnlistmentKey    = arg<wntdll::PVOID>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtRecoverEnlistment(EnlistmentHandle:{:#x}, EnlistmentKey:{:#x})", EnlistmentHandle, EnlistmentKey));

        for(const auto& it : d.observers_NtRecoverEnlistment)
            it(EnlistmentHandle, EnlistmentKey);
    }

    static void on_NtRecoverResourceManager(monitor::syscallswow64::Data& d)
    {
        const auto ResourceManagerHandle = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtRecoverResourceManager(ResourceManagerHandle:{:#x})", ResourceManagerHandle));

        for(const auto& it : d.observers_NtRecoverResourceManager)
            it(ResourceManagerHandle);
    }

    static void on_ZwRecoverTransactionManager(monitor::syscallswow64::Data& d)
    {
        const auto TransactionManagerHandle = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwRecoverTransactionManager(TransactionManagerHandle:{:#x})", TransactionManagerHandle));

        for(const auto& it : d.observers_ZwRecoverTransactionManager)
            it(TransactionManagerHandle);
    }

    static void on_ZwRegisterProtocolAddressInformation(monitor::syscallswow64::Data& d)
    {
        const auto ResourceManager         = arg<wntdll::HANDLE>(d.core, 0);
        const auto ProtocolId              = arg<wntdll::PCRM_PROTOCOL_ID>(d.core, 1);
        const auto ProtocolInformationSize = arg<wntdll::ULONG>(d.core, 2);
        const auto ProtocolInformation     = arg<wntdll::PVOID>(d.core, 3);
        const auto CreateOptions           = arg<wntdll::ULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwRegisterProtocolAddressInformation(ResourceManager:{:#x}, ProtocolId:{:#x}, ProtocolInformationSize:{:#x}, ProtocolInformation:{:#x}, CreateOptions:{:#x})", ResourceManager, ProtocolId, ProtocolInformationSize, ProtocolInformation, CreateOptions));

        for(const auto& it : d.observers_ZwRegisterProtocolAddressInformation)
            it(ResourceManager, ProtocolId, ProtocolInformationSize, ProtocolInformation, CreateOptions);
    }

    static void on_ZwRegisterThreadTerminatePort(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwRegisterThreadTerminatePort(PortHandle:{:#x})", PortHandle));

        for(const auto& it : d.observers_ZwRegisterThreadTerminatePort)
            it(PortHandle);
    }

    static void on_NtReleaseKeyedEvent(monitor::syscallswow64::Data& d)
    {
        const auto KeyedEventHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto KeyValue         = arg<wntdll::PVOID>(d.core, 1);
        const auto Alertable        = arg<wntdll::BOOLEAN>(d.core, 2);
        const auto Timeout          = arg<wntdll::PLARGE_INTEGER>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtReleaseKeyedEvent(KeyedEventHandle:{:#x}, KeyValue:{:#x}, Alertable:{:#x}, Timeout:{:#x})", KeyedEventHandle, KeyValue, Alertable, Timeout));

        for(const auto& it : d.observers_NtReleaseKeyedEvent)
            it(KeyedEventHandle, KeyValue, Alertable, Timeout);
    }

    static void on_ZwReleaseMutant(monitor::syscallswow64::Data& d)
    {
        const auto MutantHandle  = arg<wntdll::HANDLE>(d.core, 0);
        const auto PreviousCount = arg<wntdll::PLONG>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwReleaseMutant(MutantHandle:{:#x}, PreviousCount:{:#x})", MutantHandle, PreviousCount));

        for(const auto& it : d.observers_ZwReleaseMutant)
            it(MutantHandle, PreviousCount);
    }

    static void on_NtReleaseSemaphore(monitor::syscallswow64::Data& d)
    {
        const auto SemaphoreHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto ReleaseCount    = arg<wntdll::LONG>(d.core, 1);
        const auto PreviousCount   = arg<wntdll::PLONG>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtReleaseSemaphore(SemaphoreHandle:{:#x}, ReleaseCount:{:#x}, PreviousCount:{:#x})", SemaphoreHandle, ReleaseCount, PreviousCount));

        for(const auto& it : d.observers_NtReleaseSemaphore)
            it(SemaphoreHandle, ReleaseCount, PreviousCount);
    }

    static void on_ZwReleaseWorkerFactoryWorker(monitor::syscallswow64::Data& d)
    {
        const auto WorkerFactoryHandle = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwReleaseWorkerFactoryWorker(WorkerFactoryHandle:{:#x})", WorkerFactoryHandle));

        for(const auto& it : d.observers_ZwReleaseWorkerFactoryWorker)
            it(WorkerFactoryHandle);
    }

    static void on_ZwRemoveIoCompletionEx(monitor::syscallswow64::Data& d)
    {
        const auto IoCompletionHandle      = arg<wntdll::HANDLE>(d.core, 0);
        const auto IoCompletionInformation = arg<wntdll::PFILE_IO_COMPLETION_INFORMATION>(d.core, 1);
        const auto Count                   = arg<wntdll::ULONG>(d.core, 2);
        const auto NumEntriesRemoved       = arg<wntdll::PULONG>(d.core, 3);
        const auto Timeout                 = arg<wntdll::PLARGE_INTEGER>(d.core, 4);
        const auto Alertable               = arg<wntdll::BOOLEAN>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwRemoveIoCompletionEx(IoCompletionHandle:{:#x}, IoCompletionInformation:{:#x}, Count:{:#x}, NumEntriesRemoved:{:#x}, Timeout:{:#x}, Alertable:{:#x})", IoCompletionHandle, IoCompletionInformation, Count, NumEntriesRemoved, Timeout, Alertable));

        for(const auto& it : d.observers_ZwRemoveIoCompletionEx)
            it(IoCompletionHandle, IoCompletionInformation, Count, NumEntriesRemoved, Timeout, Alertable);
    }

    static void on_ZwRemoveIoCompletion(monitor::syscallswow64::Data& d)
    {
        const auto IoCompletionHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto STARKeyContext     = arg<wntdll::PVOID>(d.core, 1);
        const auto STARApcContext     = arg<wntdll::PVOID>(d.core, 2);
        const auto IoStatusBlock      = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 3);
        const auto Timeout            = arg<wntdll::PLARGE_INTEGER>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwRemoveIoCompletion(IoCompletionHandle:{:#x}, STARKeyContext:{:#x}, STARApcContext:{:#x}, IoStatusBlock:{:#x}, Timeout:{:#x})", IoCompletionHandle, STARKeyContext, STARApcContext, IoStatusBlock, Timeout));

        for(const auto& it : d.observers_ZwRemoveIoCompletion)
            it(IoCompletionHandle, STARKeyContext, STARApcContext, IoStatusBlock, Timeout);
    }

    static void on_ZwRemoveProcessDebug(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle     = arg<wntdll::HANDLE>(d.core, 0);
        const auto DebugObjectHandle = arg<wntdll::HANDLE>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwRemoveProcessDebug(ProcessHandle:{:#x}, DebugObjectHandle:{:#x})", ProcessHandle, DebugObjectHandle));

        for(const auto& it : d.observers_ZwRemoveProcessDebug)
            it(ProcessHandle, DebugObjectHandle);
    }

    static void on_ZwRenameKey(monitor::syscallswow64::Data& d)
    {
        const auto KeyHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto NewName   = arg<wntdll::PUNICODE_STRING>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwRenameKey(KeyHandle:{:#x}, NewName:{:#x})", KeyHandle, NewName));

        for(const auto& it : d.observers_ZwRenameKey)
            it(KeyHandle, NewName);
    }

    static void on_NtRenameTransactionManager(monitor::syscallswow64::Data& d)
    {
        const auto LogFileName                    = arg<wntdll::PUNICODE_STRING>(d.core, 0);
        const auto ExistingTransactionManagerGuid = arg<wntdll::LPGUID>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtRenameTransactionManager(LogFileName:{:#x}, ExistingTransactionManagerGuid:{:#x})", LogFileName, ExistingTransactionManagerGuid));

        for(const auto& it : d.observers_NtRenameTransactionManager)
            it(LogFileName, ExistingTransactionManagerGuid);
    }

    static void on_ZwReplaceKey(monitor::syscallswow64::Data& d)
    {
        const auto NewFile      = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 0);
        const auto TargetHandle = arg<wntdll::HANDLE>(d.core, 1);
        const auto OldFile      = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwReplaceKey(NewFile:{:#x}, TargetHandle:{:#x}, OldFile:{:#x})", NewFile, TargetHandle, OldFile));

        for(const auto& it : d.observers_ZwReplaceKey)
            it(NewFile, TargetHandle, OldFile);
    }

    static void on_NtReplacePartitionUnit(monitor::syscallswow64::Data& d)
    {
        const auto TargetInstancePath = arg<wntdll::PUNICODE_STRING>(d.core, 0);
        const auto SpareInstancePath  = arg<wntdll::PUNICODE_STRING>(d.core, 1);
        const auto Flags              = arg<wntdll::ULONG>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtReplacePartitionUnit(TargetInstancePath:{:#x}, SpareInstancePath:{:#x}, Flags:{:#x})", TargetInstancePath, SpareInstancePath, Flags));

        for(const auto& it : d.observers_NtReplacePartitionUnit)
            it(TargetInstancePath, SpareInstancePath, Flags);
    }

    static void on_ZwReplyPort(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle   = arg<wntdll::HANDLE>(d.core, 0);
        const auto ReplyMessage = arg<wntdll::PPORT_MESSAGE>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwReplyPort(PortHandle:{:#x}, ReplyMessage:{:#x})", PortHandle, ReplyMessage));

        for(const auto& it : d.observers_ZwReplyPort)
            it(PortHandle, ReplyMessage);
    }

    static void on_NtReplyWaitReceivePortEx(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle      = arg<wntdll::HANDLE>(d.core, 0);
        const auto STARPortContext = arg<wntdll::PVOID>(d.core, 1);
        const auto ReplyMessage    = arg<wntdll::PPORT_MESSAGE>(d.core, 2);
        const auto ReceiveMessage  = arg<wntdll::PPORT_MESSAGE>(d.core, 3);
        const auto Timeout         = arg<wntdll::PLARGE_INTEGER>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtReplyWaitReceivePortEx(PortHandle:{:#x}, STARPortContext:{:#x}, ReplyMessage:{:#x}, ReceiveMessage:{:#x}, Timeout:{:#x})", PortHandle, STARPortContext, ReplyMessage, ReceiveMessage, Timeout));

        for(const auto& it : d.observers_NtReplyWaitReceivePortEx)
            it(PortHandle, STARPortContext, ReplyMessage, ReceiveMessage, Timeout);
    }

    static void on_NtReplyWaitReceivePort(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle      = arg<wntdll::HANDLE>(d.core, 0);
        const auto STARPortContext = arg<wntdll::PVOID>(d.core, 1);
        const auto ReplyMessage    = arg<wntdll::PPORT_MESSAGE>(d.core, 2);
        const auto ReceiveMessage  = arg<wntdll::PPORT_MESSAGE>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtReplyWaitReceivePort(PortHandle:{:#x}, STARPortContext:{:#x}, ReplyMessage:{:#x}, ReceiveMessage:{:#x})", PortHandle, STARPortContext, ReplyMessage, ReceiveMessage));

        for(const auto& it : d.observers_NtReplyWaitReceivePort)
            it(PortHandle, STARPortContext, ReplyMessage, ReceiveMessage);
    }

    static void on_NtReplyWaitReplyPort(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle   = arg<wntdll::HANDLE>(d.core, 0);
        const auto ReplyMessage = arg<wntdll::PPORT_MESSAGE>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtReplyWaitReplyPort(PortHandle:{:#x}, ReplyMessage:{:#x})", PortHandle, ReplyMessage));

        for(const auto& it : d.observers_NtReplyWaitReplyPort)
            it(PortHandle, ReplyMessage);
    }

    static void on_ZwRequestPort(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle     = arg<wntdll::HANDLE>(d.core, 0);
        const auto RequestMessage = arg<wntdll::PPORT_MESSAGE>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwRequestPort(PortHandle:{:#x}, RequestMessage:{:#x})", PortHandle, RequestMessage));

        for(const auto& it : d.observers_ZwRequestPort)
            it(PortHandle, RequestMessage);
    }

    static void on_NtRequestWaitReplyPort(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle     = arg<wntdll::HANDLE>(d.core, 0);
        const auto RequestMessage = arg<wntdll::PPORT_MESSAGE>(d.core, 1);
        const auto ReplyMessage   = arg<wntdll::PPORT_MESSAGE>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtRequestWaitReplyPort(PortHandle:{:#x}, RequestMessage:{:#x}, ReplyMessage:{:#x})", PortHandle, RequestMessage, ReplyMessage));

        for(const auto& it : d.observers_NtRequestWaitReplyPort)
            it(PortHandle, RequestMessage, ReplyMessage);
    }

    static void on_NtResetEvent(monitor::syscallswow64::Data& d)
    {
        const auto EventHandle   = arg<wntdll::HANDLE>(d.core, 0);
        const auto PreviousState = arg<wntdll::PLONG>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtResetEvent(EventHandle:{:#x}, PreviousState:{:#x})", EventHandle, PreviousState));

        for(const auto& it : d.observers_NtResetEvent)
            it(EventHandle, PreviousState);
    }

    static void on_ZwResetWriteWatch(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto BaseAddress   = arg<wntdll::PVOID>(d.core, 1);
        const auto RegionSize    = arg<wntdll::SIZE_T>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwResetWriteWatch(ProcessHandle:{:#x}, BaseAddress:{:#x}, RegionSize:{:#x})", ProcessHandle, BaseAddress, RegionSize));

        for(const auto& it : d.observers_ZwResetWriteWatch)
            it(ProcessHandle, BaseAddress, RegionSize);
    }

    static void on_NtRestoreKey(monitor::syscallswow64::Data& d)
    {
        const auto KeyHandle  = arg<wntdll::HANDLE>(d.core, 0);
        const auto FileHandle = arg<wntdll::HANDLE>(d.core, 1);
        const auto Flags      = arg<wntdll::ULONG>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtRestoreKey(KeyHandle:{:#x}, FileHandle:{:#x}, Flags:{:#x})", KeyHandle, FileHandle, Flags));

        for(const auto& it : d.observers_NtRestoreKey)
            it(KeyHandle, FileHandle, Flags);
    }

    static void on_ZwResumeProcess(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwResumeProcess(ProcessHandle:{:#x})", ProcessHandle));

        for(const auto& it : d.observers_ZwResumeProcess)
            it(ProcessHandle);
    }

    static void on_ZwResumeThread(monitor::syscallswow64::Data& d)
    {
        const auto ThreadHandle         = arg<wntdll::HANDLE>(d.core, 0);
        const auto PreviousSuspendCount = arg<wntdll::PULONG>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwResumeThread(ThreadHandle:{:#x}, PreviousSuspendCount:{:#x})", ThreadHandle, PreviousSuspendCount));

        for(const auto& it : d.observers_ZwResumeThread)
            it(ThreadHandle, PreviousSuspendCount);
    }

    static void on_ZwRollbackComplete(monitor::syscallswow64::Data& d)
    {
        const auto EnlistmentHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto TmVirtualClock   = arg<wntdll::PLARGE_INTEGER>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwRollbackComplete(EnlistmentHandle:{:#x}, TmVirtualClock:{:#x})", EnlistmentHandle, TmVirtualClock));

        for(const auto& it : d.observers_ZwRollbackComplete)
            it(EnlistmentHandle, TmVirtualClock);
    }

    static void on_NtRollbackEnlistment(monitor::syscallswow64::Data& d)
    {
        const auto EnlistmentHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto TmVirtualClock   = arg<wntdll::PLARGE_INTEGER>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtRollbackEnlistment(EnlistmentHandle:{:#x}, TmVirtualClock:{:#x})", EnlistmentHandle, TmVirtualClock));

        for(const auto& it : d.observers_NtRollbackEnlistment)
            it(EnlistmentHandle, TmVirtualClock);
    }

    static void on_NtRollbackTransaction(monitor::syscallswow64::Data& d)
    {
        const auto TransactionHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto Wait              = arg<wntdll::BOOLEAN>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtRollbackTransaction(TransactionHandle:{:#x}, Wait:{:#x})", TransactionHandle, Wait));

        for(const auto& it : d.observers_NtRollbackTransaction)
            it(TransactionHandle, Wait);
    }

    static void on_NtRollforwardTransactionManager(monitor::syscallswow64::Data& d)
    {
        const auto TransactionManagerHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto TmVirtualClock           = arg<wntdll::PLARGE_INTEGER>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtRollforwardTransactionManager(TransactionManagerHandle:{:#x}, TmVirtualClock:{:#x})", TransactionManagerHandle, TmVirtualClock));

        for(const auto& it : d.observers_NtRollforwardTransactionManager)
            it(TransactionManagerHandle, TmVirtualClock);
    }

    static void on_NtSaveKeyEx(monitor::syscallswow64::Data& d)
    {
        const auto KeyHandle  = arg<wntdll::HANDLE>(d.core, 0);
        const auto FileHandle = arg<wntdll::HANDLE>(d.core, 1);
        const auto Format     = arg<wntdll::ULONG>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtSaveKeyEx(KeyHandle:{:#x}, FileHandle:{:#x}, Format:{:#x})", KeyHandle, FileHandle, Format));

        for(const auto& it : d.observers_NtSaveKeyEx)
            it(KeyHandle, FileHandle, Format);
    }

    static void on_NtSaveKey(monitor::syscallswow64::Data& d)
    {
        const auto KeyHandle  = arg<wntdll::HANDLE>(d.core, 0);
        const auto FileHandle = arg<wntdll::HANDLE>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtSaveKey(KeyHandle:{:#x}, FileHandle:{:#x})", KeyHandle, FileHandle));

        for(const auto& it : d.observers_NtSaveKey)
            it(KeyHandle, FileHandle);
    }

    static void on_NtSaveMergedKeys(monitor::syscallswow64::Data& d)
    {
        const auto HighPrecedenceKeyHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto LowPrecedenceKeyHandle  = arg<wntdll::HANDLE>(d.core, 1);
        const auto FileHandle              = arg<wntdll::HANDLE>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtSaveMergedKeys(HighPrecedenceKeyHandle:{:#x}, LowPrecedenceKeyHandle:{:#x}, FileHandle:{:#x})", HighPrecedenceKeyHandle, LowPrecedenceKeyHandle, FileHandle));

        for(const auto& it : d.observers_NtSaveMergedKeys)
            it(HighPrecedenceKeyHandle, LowPrecedenceKeyHandle, FileHandle);
    }

    static void on_NtSecureConnectPort(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle                  = arg<wntdll::PHANDLE>(d.core, 0);
        const auto PortName                    = arg<wntdll::PUNICODE_STRING>(d.core, 1);
        const auto SecurityQos                 = arg<wntdll::PSECURITY_QUALITY_OF_SERVICE>(d.core, 2);
        const auto ClientView                  = arg<wntdll::PPORT_VIEW>(d.core, 3);
        const auto RequiredServerSid           = arg<wntdll::PSID>(d.core, 4);
        const auto ServerView                  = arg<wntdll::PREMOTE_PORT_VIEW>(d.core, 5);
        const auto MaxMessageLength            = arg<wntdll::PULONG>(d.core, 6);
        const auto ConnectionInformation       = arg<wntdll::PVOID>(d.core, 7);
        const auto ConnectionInformationLength = arg<wntdll::PULONG>(d.core, 8);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtSecureConnectPort(PortHandle:{:#x}, PortName:{:#x}, SecurityQos:{:#x}, ClientView:{:#x}, RequiredServerSid:{:#x}, ServerView:{:#x}, MaxMessageLength:{:#x}, ConnectionInformation:{:#x}, ConnectionInformationLength:{:#x})", PortHandle, PortName, SecurityQos, ClientView, RequiredServerSid, ServerView, MaxMessageLength, ConnectionInformation, ConnectionInformationLength));

        for(const auto& it : d.observers_NtSecureConnectPort)
            it(PortHandle, PortName, SecurityQos, ClientView, RequiredServerSid, ServerView, MaxMessageLength, ConnectionInformation, ConnectionInformationLength);
    }

    static void on_ZwSetBootEntryOrder(monitor::syscallswow64::Data& d)
    {
        const auto Ids   = arg<wntdll::PULONG>(d.core, 0);
        const auto Count = arg<wntdll::ULONG>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetBootEntryOrder(Ids:{:#x}, Count:{:#x})", Ids, Count));

        for(const auto& it : d.observers_ZwSetBootEntryOrder)
            it(Ids, Count);
    }

    static void on_ZwSetBootOptions(monitor::syscallswow64::Data& d)
    {
        const auto BootOptions    = arg<wntdll::PBOOT_OPTIONS>(d.core, 0);
        const auto FieldsToChange = arg<wntdll::ULONG>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetBootOptions(BootOptions:{:#x}, FieldsToChange:{:#x})", BootOptions, FieldsToChange));

        for(const auto& it : d.observers_ZwSetBootOptions)
            it(BootOptions, FieldsToChange);
    }

    static void on_ZwSetContextThread(monitor::syscallswow64::Data& d)
    {
        const auto ThreadHandle  = arg<wntdll::HANDLE>(d.core, 0);
        const auto ThreadContext = arg<wntdll::PCONTEXT>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetContextThread(ThreadHandle:{:#x}, ThreadContext:{:#x})", ThreadHandle, ThreadContext));

        for(const auto& it : d.observers_ZwSetContextThread)
            it(ThreadHandle, ThreadContext);
    }

    static void on_NtSetDebugFilterState(monitor::syscallswow64::Data& d)
    {
        const auto ComponentId = arg<wntdll::ULONG>(d.core, 0);
        const auto Level       = arg<wntdll::ULONG>(d.core, 1);
        const auto State       = arg<wntdll::BOOLEAN>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtSetDebugFilterState(ComponentId:{:#x}, Level:{:#x}, State:{:#x})", ComponentId, Level, State));

        for(const auto& it : d.observers_NtSetDebugFilterState)
            it(ComponentId, Level, State);
    }

    static void on_NtSetDefaultHardErrorPort(monitor::syscallswow64::Data& d)
    {
        const auto DefaultHardErrorPort = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtSetDefaultHardErrorPort(DefaultHardErrorPort:{:#x})", DefaultHardErrorPort));

        for(const auto& it : d.observers_NtSetDefaultHardErrorPort)
            it(DefaultHardErrorPort);
    }

    static void on_NtSetDefaultLocale(monitor::syscallswow64::Data& d)
    {
        const auto UserProfile     = arg<wntdll::BOOLEAN>(d.core, 0);
        const auto DefaultLocaleId = arg<wntdll::LCID>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtSetDefaultLocale(UserProfile:{:#x}, DefaultLocaleId:{:#x})", UserProfile, DefaultLocaleId));

        for(const auto& it : d.observers_NtSetDefaultLocale)
            it(UserProfile, DefaultLocaleId);
    }

    static void on_ZwSetDefaultUILanguage(monitor::syscallswow64::Data& d)
    {
        const auto DefaultUILanguageId = arg<wntdll::LANGID>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetDefaultUILanguage(DefaultUILanguageId:{:#x})", DefaultUILanguageId));

        for(const auto& it : d.observers_ZwSetDefaultUILanguage)
            it(DefaultUILanguageId);
    }

    static void on_NtSetDriverEntryOrder(monitor::syscallswow64::Data& d)
    {
        const auto Ids   = arg<wntdll::PULONG>(d.core, 0);
        const auto Count = arg<wntdll::ULONG>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtSetDriverEntryOrder(Ids:{:#x}, Count:{:#x})", Ids, Count));

        for(const auto& it : d.observers_NtSetDriverEntryOrder)
            it(Ids, Count);
    }

    static void on_ZwSetEaFile(monitor::syscallswow64::Data& d)
    {
        const auto FileHandle    = arg<wntdll::HANDLE>(d.core, 0);
        const auto IoStatusBlock = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 1);
        const auto Buffer        = arg<wntdll::PVOID>(d.core, 2);
        const auto Length        = arg<wntdll::ULONG>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetEaFile(FileHandle:{:#x}, IoStatusBlock:{:#x}, Buffer:{:#x}, Length:{:#x})", FileHandle, IoStatusBlock, Buffer, Length));

        for(const auto& it : d.observers_ZwSetEaFile)
            it(FileHandle, IoStatusBlock, Buffer, Length);
    }

    static void on_NtSetEventBoostPriority(monitor::syscallswow64::Data& d)
    {
        const auto EventHandle = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtSetEventBoostPriority(EventHandle:{:#x})", EventHandle));

        for(const auto& it : d.observers_NtSetEventBoostPriority)
            it(EventHandle);
    }

    static void on_NtSetEvent(monitor::syscallswow64::Data& d)
    {
        const auto EventHandle   = arg<wntdll::HANDLE>(d.core, 0);
        const auto PreviousState = arg<wntdll::PLONG>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtSetEvent(EventHandle:{:#x}, PreviousState:{:#x})", EventHandle, PreviousState));

        for(const auto& it : d.observers_NtSetEvent)
            it(EventHandle, PreviousState);
    }

    static void on_NtSetHighEventPair(monitor::syscallswow64::Data& d)
    {
        const auto EventPairHandle = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtSetHighEventPair(EventPairHandle:{:#x})", EventPairHandle));

        for(const auto& it : d.observers_NtSetHighEventPair)
            it(EventPairHandle);
    }

    static void on_NtSetHighWaitLowEventPair(monitor::syscallswow64::Data& d)
    {
        const auto EventPairHandle = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtSetHighWaitLowEventPair(EventPairHandle:{:#x})", EventPairHandle));

        for(const auto& it : d.observers_NtSetHighWaitLowEventPair)
            it(EventPairHandle);
    }

    static void on_ZwSetInformationDebugObject(monitor::syscallswow64::Data& d)
    {
        const auto DebugObjectHandle           = arg<wntdll::HANDLE>(d.core, 0);
        const auto DebugObjectInformationClass = arg<wntdll::DEBUGOBJECTINFOCLASS>(d.core, 1);
        const auto DebugInformation            = arg<wntdll::PVOID>(d.core, 2);
        const auto DebugInformationLength      = arg<wntdll::ULONG>(d.core, 3);
        const auto ReturnLength                = arg<wntdll::PULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetInformationDebugObject(DebugObjectHandle:{:#x}, DebugObjectInformationClass:{:#x}, DebugInformation:{:#x}, DebugInformationLength:{:#x}, ReturnLength:{:#x})", DebugObjectHandle, DebugObjectInformationClass, DebugInformation, DebugInformationLength, ReturnLength));

        for(const auto& it : d.observers_ZwSetInformationDebugObject)
            it(DebugObjectHandle, DebugObjectInformationClass, DebugInformation, DebugInformationLength, ReturnLength);
    }

    static void on_NtSetInformationEnlistment(monitor::syscallswow64::Data& d)
    {
        const auto EnlistmentHandle            = arg<wntdll::HANDLE>(d.core, 0);
        const auto EnlistmentInformationClass  = arg<wntdll::ENLISTMENT_INFORMATION_CLASS>(d.core, 1);
        const auto EnlistmentInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto EnlistmentInformationLength = arg<wntdll::ULONG>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtSetInformationEnlistment(EnlistmentHandle:{:#x}, EnlistmentInformationClass:{:#x}, EnlistmentInformation:{:#x}, EnlistmentInformationLength:{:#x})", EnlistmentHandle, EnlistmentInformationClass, EnlistmentInformation, EnlistmentInformationLength));

        for(const auto& it : d.observers_NtSetInformationEnlistment)
            it(EnlistmentHandle, EnlistmentInformationClass, EnlistmentInformation, EnlistmentInformationLength);
    }

    static void on_ZwSetInformationFile(monitor::syscallswow64::Data& d)
    {
        const auto FileHandle           = arg<wntdll::HANDLE>(d.core, 0);
        const auto IoStatusBlock        = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 1);
        const auto FileInformation      = arg<wntdll::PVOID>(d.core, 2);
        const auto Length               = arg<wntdll::ULONG>(d.core, 3);
        const auto FileInformationClass = arg<wntdll::FILE_INFORMATION_CLASS>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetInformationFile(FileHandle:{:#x}, IoStatusBlock:{:#x}, FileInformation:{:#x}, Length:{:#x}, FileInformationClass:{:#x})", FileHandle, IoStatusBlock, FileInformation, Length, FileInformationClass));

        for(const auto& it : d.observers_ZwSetInformationFile)
            it(FileHandle, IoStatusBlock, FileInformation, Length, FileInformationClass);
    }

    static void on_ZwSetInformationJobObject(monitor::syscallswow64::Data& d)
    {
        const auto JobHandle                  = arg<wntdll::HANDLE>(d.core, 0);
        const auto JobObjectInformationClass  = arg<wntdll::JOBOBJECTINFOCLASS>(d.core, 1);
        const auto JobObjectInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto JobObjectInformationLength = arg<wntdll::ULONG>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetInformationJobObject(JobHandle:{:#x}, JobObjectInformationClass:{:#x}, JobObjectInformation:{:#x}, JobObjectInformationLength:{:#x})", JobHandle, JobObjectInformationClass, JobObjectInformation, JobObjectInformationLength));

        for(const auto& it : d.observers_ZwSetInformationJobObject)
            it(JobHandle, JobObjectInformationClass, JobObjectInformation, JobObjectInformationLength);
    }

    static void on_ZwSetInformationKey(monitor::syscallswow64::Data& d)
    {
        const auto KeyHandle               = arg<wntdll::HANDLE>(d.core, 0);
        const auto KeySetInformationClass  = arg<wntdll::KEY_SET_INFORMATION_CLASS>(d.core, 1);
        const auto KeySetInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto KeySetInformationLength = arg<wntdll::ULONG>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetInformationKey(KeyHandle:{:#x}, KeySetInformationClass:{:#x}, KeySetInformation:{:#x}, KeySetInformationLength:{:#x})", KeyHandle, KeySetInformationClass, KeySetInformation, KeySetInformationLength));

        for(const auto& it : d.observers_ZwSetInformationKey)
            it(KeyHandle, KeySetInformationClass, KeySetInformation, KeySetInformationLength);
    }

    static void on_ZwSetInformationObject(monitor::syscallswow64::Data& d)
    {
        const auto Handle                  = arg<wntdll::HANDLE>(d.core, 0);
        const auto ObjectInformationClass  = arg<wntdll::OBJECT_INFORMATION_CLASS>(d.core, 1);
        const auto ObjectInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto ObjectInformationLength = arg<wntdll::ULONG>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetInformationObject(Handle:{:#x}, ObjectInformationClass:{:#x}, ObjectInformation:{:#x}, ObjectInformationLength:{:#x})", Handle, ObjectInformationClass, ObjectInformation, ObjectInformationLength));

        for(const auto& it : d.observers_ZwSetInformationObject)
            it(Handle, ObjectInformationClass, ObjectInformation, ObjectInformationLength);
    }

    static void on_ZwSetInformationProcess(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle            = arg<wntdll::HANDLE>(d.core, 0);
        const auto ProcessInformationClass  = arg<wntdll::PROCESSINFOCLASS>(d.core, 1);
        const auto ProcessInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto ProcessInformationLength = arg<wntdll::ULONG>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetInformationProcess(ProcessHandle:{:#x}, ProcessInformationClass:{:#x}, ProcessInformation:{:#x}, ProcessInformationLength:{:#x})", ProcessHandle, ProcessInformationClass, ProcessInformation, ProcessInformationLength));

        for(const auto& it : d.observers_ZwSetInformationProcess)
            it(ProcessHandle, ProcessInformationClass, ProcessInformation, ProcessInformationLength);
    }

    static void on_ZwSetInformationResourceManager(monitor::syscallswow64::Data& d)
    {
        const auto ResourceManagerHandle            = arg<wntdll::HANDLE>(d.core, 0);
        const auto ResourceManagerInformationClass  = arg<wntdll::RESOURCEMANAGER_INFORMATION_CLASS>(d.core, 1);
        const auto ResourceManagerInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto ResourceManagerInformationLength = arg<wntdll::ULONG>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetInformationResourceManager(ResourceManagerHandle:{:#x}, ResourceManagerInformationClass:{:#x}, ResourceManagerInformation:{:#x}, ResourceManagerInformationLength:{:#x})", ResourceManagerHandle, ResourceManagerInformationClass, ResourceManagerInformation, ResourceManagerInformationLength));

        for(const auto& it : d.observers_ZwSetInformationResourceManager)
            it(ResourceManagerHandle, ResourceManagerInformationClass, ResourceManagerInformation, ResourceManagerInformationLength);
    }

    static void on_ZwSetInformationThread(monitor::syscallswow64::Data& d)
    {
        const auto ThreadHandle            = arg<wntdll::HANDLE>(d.core, 0);
        const auto ThreadInformationClass  = arg<wntdll::THREADINFOCLASS>(d.core, 1);
        const auto ThreadInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto ThreadInformationLength = arg<wntdll::ULONG>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetInformationThread(ThreadHandle:{:#x}, ThreadInformationClass:{:#x}, ThreadInformation:{:#x}, ThreadInformationLength:{:#x})", ThreadHandle, ThreadInformationClass, ThreadInformation, ThreadInformationLength));

        for(const auto& it : d.observers_ZwSetInformationThread)
            it(ThreadHandle, ThreadInformationClass, ThreadInformation, ThreadInformationLength);
    }

    static void on_ZwSetInformationToken(monitor::syscallswow64::Data& d)
    {
        const auto TokenHandle            = arg<wntdll::HANDLE>(d.core, 0);
        const auto TokenInformationClass  = arg<wntdll::TOKEN_INFORMATION_CLASS>(d.core, 1);
        const auto TokenInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto TokenInformationLength = arg<wntdll::ULONG>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetInformationToken(TokenHandle:{:#x}, TokenInformationClass:{:#x}, TokenInformation:{:#x}, TokenInformationLength:{:#x})", TokenHandle, TokenInformationClass, TokenInformation, TokenInformationLength));

        for(const auto& it : d.observers_ZwSetInformationToken)
            it(TokenHandle, TokenInformationClass, TokenInformation, TokenInformationLength);
    }

    static void on_ZwSetInformationTransaction(monitor::syscallswow64::Data& d)
    {
        const auto TransactionHandle            = arg<wntdll::HANDLE>(d.core, 0);
        const auto TransactionInformationClass  = arg<wntdll::TRANSACTION_INFORMATION_CLASS>(d.core, 1);
        const auto TransactionInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto TransactionInformationLength = arg<wntdll::ULONG>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetInformationTransaction(TransactionHandle:{:#x}, TransactionInformationClass:{:#x}, TransactionInformation:{:#x}, TransactionInformationLength:{:#x})", TransactionHandle, TransactionInformationClass, TransactionInformation, TransactionInformationLength));

        for(const auto& it : d.observers_ZwSetInformationTransaction)
            it(TransactionHandle, TransactionInformationClass, TransactionInformation, TransactionInformationLength);
    }

    static void on_ZwSetInformationTransactionManager(monitor::syscallswow64::Data& d)
    {
        const auto TmHandle                            = arg<wntdll::HANDLE>(d.core, 0);
        const auto TransactionManagerInformationClass  = arg<wntdll::TRANSACTIONMANAGER_INFORMATION_CLASS>(d.core, 1);
        const auto TransactionManagerInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto TransactionManagerInformationLength = arg<wntdll::ULONG>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetInformationTransactionManager(TmHandle:{:#x}, TransactionManagerInformationClass:{:#x}, TransactionManagerInformation:{:#x}, TransactionManagerInformationLength:{:#x})", TmHandle, TransactionManagerInformationClass, TransactionManagerInformation, TransactionManagerInformationLength));

        for(const auto& it : d.observers_ZwSetInformationTransactionManager)
            it(TmHandle, TransactionManagerInformationClass, TransactionManagerInformation, TransactionManagerInformationLength);
    }

    static void on_ZwSetInformationWorkerFactory(monitor::syscallswow64::Data& d)
    {
        const auto WorkerFactoryHandle            = arg<wntdll::HANDLE>(d.core, 0);
        const auto WorkerFactoryInformationClass  = arg<wntdll::WORKERFACTORYINFOCLASS>(d.core, 1);
        const auto WorkerFactoryInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto WorkerFactoryInformationLength = arg<wntdll::ULONG>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetInformationWorkerFactory(WorkerFactoryHandle:{:#x}, WorkerFactoryInformationClass:{:#x}, WorkerFactoryInformation:{:#x}, WorkerFactoryInformationLength:{:#x})", WorkerFactoryHandle, WorkerFactoryInformationClass, WorkerFactoryInformation, WorkerFactoryInformationLength));

        for(const auto& it : d.observers_ZwSetInformationWorkerFactory)
            it(WorkerFactoryHandle, WorkerFactoryInformationClass, WorkerFactoryInformation, WorkerFactoryInformationLength);
    }

    static void on_NtSetIntervalProfile(monitor::syscallswow64::Data& d)
    {
        const auto Interval = arg<wntdll::ULONG>(d.core, 0);
        const auto Source   = arg<wntdll::KPROFILE_SOURCE>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtSetIntervalProfile(Interval:{:#x}, Source:{:#x})", Interval, Source));

        for(const auto& it : d.observers_NtSetIntervalProfile)
            it(Interval, Source);
    }

    static void on_NtSetIoCompletionEx(monitor::syscallswow64::Data& d)
    {
        const auto IoCompletionHandle        = arg<wntdll::HANDLE>(d.core, 0);
        const auto IoCompletionReserveHandle = arg<wntdll::HANDLE>(d.core, 1);
        const auto KeyContext                = arg<wntdll::PVOID>(d.core, 2);
        const auto ApcContext                = arg<wntdll::PVOID>(d.core, 3);
        const auto IoStatus                  = arg<wntdll::NTSTATUS>(d.core, 4);
        const auto IoStatusInformation       = arg<wntdll::ULONG_PTR>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtSetIoCompletionEx(IoCompletionHandle:{:#x}, IoCompletionReserveHandle:{:#x}, KeyContext:{:#x}, ApcContext:{:#x}, IoStatus:{:#x}, IoStatusInformation:{:#x})", IoCompletionHandle, IoCompletionReserveHandle, KeyContext, ApcContext, IoStatus, IoStatusInformation));

        for(const auto& it : d.observers_NtSetIoCompletionEx)
            it(IoCompletionHandle, IoCompletionReserveHandle, KeyContext, ApcContext, IoStatus, IoStatusInformation);
    }

    static void on_NtSetIoCompletion(monitor::syscallswow64::Data& d)
    {
        const auto IoCompletionHandle  = arg<wntdll::HANDLE>(d.core, 0);
        const auto KeyContext          = arg<wntdll::PVOID>(d.core, 1);
        const auto ApcContext          = arg<wntdll::PVOID>(d.core, 2);
        const auto IoStatus            = arg<wntdll::NTSTATUS>(d.core, 3);
        const auto IoStatusInformation = arg<wntdll::ULONG_PTR>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtSetIoCompletion(IoCompletionHandle:{:#x}, KeyContext:{:#x}, ApcContext:{:#x}, IoStatus:{:#x}, IoStatusInformation:{:#x})", IoCompletionHandle, KeyContext, ApcContext, IoStatus, IoStatusInformation));

        for(const auto& it : d.observers_NtSetIoCompletion)
            it(IoCompletionHandle, KeyContext, ApcContext, IoStatus, IoStatusInformation);
    }

    static void on_ZwSetLdtEntries(monitor::syscallswow64::Data& d)
    {
        const auto Selector0 = arg<wntdll::ULONG>(d.core, 0);
        const auto Entry0Low = arg<wntdll::ULONG>(d.core, 1);
        const auto Entry0Hi  = arg<wntdll::ULONG>(d.core, 2);
        const auto Selector1 = arg<wntdll::ULONG>(d.core, 3);
        const auto Entry1Low = arg<wntdll::ULONG>(d.core, 4);
        const auto Entry1Hi  = arg<wntdll::ULONG>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetLdtEntries(Selector0:{:#x}, Entry0Low:{:#x}, Entry0Hi:{:#x}, Selector1:{:#x}, Entry1Low:{:#x}, Entry1Hi:{:#x})", Selector0, Entry0Low, Entry0Hi, Selector1, Entry1Low, Entry1Hi));

        for(const auto& it : d.observers_ZwSetLdtEntries)
            it(Selector0, Entry0Low, Entry0Hi, Selector1, Entry1Low, Entry1Hi);
    }

    static void on_ZwSetLowEventPair(monitor::syscallswow64::Data& d)
    {
        const auto EventPairHandle = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetLowEventPair(EventPairHandle:{:#x})", EventPairHandle));

        for(const auto& it : d.observers_ZwSetLowEventPair)
            it(EventPairHandle);
    }

    static void on_ZwSetLowWaitHighEventPair(monitor::syscallswow64::Data& d)
    {
        const auto EventPairHandle = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetLowWaitHighEventPair(EventPairHandle:{:#x})", EventPairHandle));

        for(const auto& it : d.observers_ZwSetLowWaitHighEventPair)
            it(EventPairHandle);
    }

    static void on_ZwSetQuotaInformationFile(monitor::syscallswow64::Data& d)
    {
        const auto FileHandle    = arg<wntdll::HANDLE>(d.core, 0);
        const auto IoStatusBlock = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 1);
        const auto Buffer        = arg<wntdll::PVOID>(d.core, 2);
        const auto Length        = arg<wntdll::ULONG>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetQuotaInformationFile(FileHandle:{:#x}, IoStatusBlock:{:#x}, Buffer:{:#x}, Length:{:#x})", FileHandle, IoStatusBlock, Buffer, Length));

        for(const auto& it : d.observers_ZwSetQuotaInformationFile)
            it(FileHandle, IoStatusBlock, Buffer, Length);
    }

    static void on_NtSetSecurityObject(monitor::syscallswow64::Data& d)
    {
        const auto Handle              = arg<wntdll::HANDLE>(d.core, 0);
        const auto SecurityInformation = arg<wntdll::SECURITY_INFORMATION>(d.core, 1);
        const auto SecurityDescriptor  = arg<wntdll::PSECURITY_DESCRIPTOR>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtSetSecurityObject(Handle:{:#x}, SecurityInformation:{:#x}, SecurityDescriptor:{:#x})", Handle, SecurityInformation, SecurityDescriptor));

        for(const auto& it : d.observers_NtSetSecurityObject)
            it(Handle, SecurityInformation, SecurityDescriptor);
    }

    static void on_ZwSetSystemEnvironmentValueEx(monitor::syscallswow64::Data& d)
    {
        const auto VariableName = arg<wntdll::PUNICODE_STRING>(d.core, 0);
        const auto VendorGuid   = arg<wntdll::LPGUID>(d.core, 1);
        const auto Value        = arg<wntdll::PVOID>(d.core, 2);
        const auto ValueLength  = arg<wntdll::ULONG>(d.core, 3);
        const auto Attributes   = arg<wntdll::ULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetSystemEnvironmentValueEx(VariableName:{:#x}, VendorGuid:{:#x}, Value:{:#x}, ValueLength:{:#x}, Attributes:{:#x})", VariableName, VendorGuid, Value, ValueLength, Attributes));

        for(const auto& it : d.observers_ZwSetSystemEnvironmentValueEx)
            it(VariableName, VendorGuid, Value, ValueLength, Attributes);
    }

    static void on_ZwSetSystemEnvironmentValue(monitor::syscallswow64::Data& d)
    {
        const auto VariableName  = arg<wntdll::PUNICODE_STRING>(d.core, 0);
        const auto VariableValue = arg<wntdll::PUNICODE_STRING>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetSystemEnvironmentValue(VariableName:{:#x}, VariableValue:{:#x})", VariableName, VariableValue));

        for(const auto& it : d.observers_ZwSetSystemEnvironmentValue)
            it(VariableName, VariableValue);
    }

    static void on_ZwSetSystemInformation(monitor::syscallswow64::Data& d)
    {
        const auto SystemInformationClass  = arg<wntdll::SYSTEM_INFORMATION_CLASS>(d.core, 0);
        const auto SystemInformation       = arg<wntdll::PVOID>(d.core, 1);
        const auto SystemInformationLength = arg<wntdll::ULONG>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetSystemInformation(SystemInformationClass:{:#x}, SystemInformation:{:#x}, SystemInformationLength:{:#x})", SystemInformationClass, SystemInformation, SystemInformationLength));

        for(const auto& it : d.observers_ZwSetSystemInformation)
            it(SystemInformationClass, SystemInformation, SystemInformationLength);
    }

    static void on_ZwSetSystemPowerState(monitor::syscallswow64::Data& d)
    {
        const auto SystemAction   = arg<wntdll::POWER_ACTION>(d.core, 0);
        const auto MinSystemState = arg<wntdll::SYSTEM_POWER_STATE>(d.core, 1);
        const auto Flags          = arg<wntdll::ULONG>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetSystemPowerState(SystemAction:{:#x}, MinSystemState:{:#x}, Flags:{:#x})", SystemAction, MinSystemState, Flags));

        for(const auto& it : d.observers_ZwSetSystemPowerState)
            it(SystemAction, MinSystemState, Flags);
    }

    static void on_ZwSetSystemTime(monitor::syscallswow64::Data& d)
    {
        const auto SystemTime   = arg<wntdll::PLARGE_INTEGER>(d.core, 0);
        const auto PreviousTime = arg<wntdll::PLARGE_INTEGER>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetSystemTime(SystemTime:{:#x}, PreviousTime:{:#x})", SystemTime, PreviousTime));

        for(const auto& it : d.observers_ZwSetSystemTime)
            it(SystemTime, PreviousTime);
    }

    static void on_ZwSetThreadExecutionState(monitor::syscallswow64::Data& d)
    {
        const auto esFlags           = arg<wntdll::EXECUTION_STATE>(d.core, 0);
        const auto STARPreviousFlags = arg<wntdll::EXECUTION_STATE>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetThreadExecutionState(esFlags:{:#x}, STARPreviousFlags:{:#x})", esFlags, STARPreviousFlags));

        for(const auto& it : d.observers_ZwSetThreadExecutionState)
            it(esFlags, STARPreviousFlags);
    }

    static void on_ZwSetTimerEx(monitor::syscallswow64::Data& d)
    {
        const auto TimerHandle               = arg<wntdll::HANDLE>(d.core, 0);
        const auto TimerSetInformationClass  = arg<wntdll::TIMER_SET_INFORMATION_CLASS>(d.core, 1);
        const auto TimerSetInformation       = arg<wntdll::PVOID>(d.core, 2);
        const auto TimerSetInformationLength = arg<wntdll::ULONG>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetTimerEx(TimerHandle:{:#x}, TimerSetInformationClass:{:#x}, TimerSetInformation:{:#x}, TimerSetInformationLength:{:#x})", TimerHandle, TimerSetInformationClass, TimerSetInformation, TimerSetInformationLength));

        for(const auto& it : d.observers_ZwSetTimerEx)
            it(TimerHandle, TimerSetInformationClass, TimerSetInformation, TimerSetInformationLength);
    }

    static void on_ZwSetTimer(monitor::syscallswow64::Data& d)
    {
        const auto TimerHandle     = arg<wntdll::HANDLE>(d.core, 0);
        const auto DueTime         = arg<wntdll::PLARGE_INTEGER>(d.core, 1);
        const auto TimerApcRoutine = arg<wntdll::PTIMER_APC_ROUTINE>(d.core, 2);
        const auto TimerContext    = arg<wntdll::PVOID>(d.core, 3);
        const auto WakeTimer       = arg<wntdll::BOOLEAN>(d.core, 4);
        const auto Period          = arg<wntdll::LONG>(d.core, 5);
        const auto PreviousState   = arg<wntdll::PBOOLEAN>(d.core, 6);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetTimer(TimerHandle:{:#x}, DueTime:{:#x}, TimerApcRoutine:{:#x}, TimerContext:{:#x}, WakeTimer:{:#x}, Period:{:#x}, PreviousState:{:#x})", TimerHandle, DueTime, TimerApcRoutine, TimerContext, WakeTimer, Period, PreviousState));

        for(const auto& it : d.observers_ZwSetTimer)
            it(TimerHandle, DueTime, TimerApcRoutine, TimerContext, WakeTimer, Period, PreviousState);
    }

    static void on_NtSetTimerResolution(monitor::syscallswow64::Data& d)
    {
        const auto DesiredTime   = arg<wntdll::ULONG>(d.core, 0);
        const auto SetResolution = arg<wntdll::BOOLEAN>(d.core, 1);
        const auto ActualTime    = arg<wntdll::PULONG>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtSetTimerResolution(DesiredTime:{:#x}, SetResolution:{:#x}, ActualTime:{:#x})", DesiredTime, SetResolution, ActualTime));

        for(const auto& it : d.observers_NtSetTimerResolution)
            it(DesiredTime, SetResolution, ActualTime);
    }

    static void on_ZwSetUuidSeed(monitor::syscallswow64::Data& d)
    {
        const auto Seed = arg<wntdll::PCHAR>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetUuidSeed(Seed:{:#x})", Seed));

        for(const auto& it : d.observers_ZwSetUuidSeed)
            it(Seed);
    }

    static void on_ZwSetValueKey(monitor::syscallswow64::Data& d)
    {
        const auto KeyHandle  = arg<wntdll::HANDLE>(d.core, 0);
        const auto ValueName  = arg<wntdll::PUNICODE_STRING>(d.core, 1);
        const auto TitleIndex = arg<wntdll::ULONG>(d.core, 2);
        const auto Type       = arg<wntdll::ULONG>(d.core, 3);
        const auto Data       = arg<wntdll::PVOID>(d.core, 4);
        const auto DataSize   = arg<wntdll::ULONG>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSetValueKey(KeyHandle:{:#x}, ValueName:{:#x}, TitleIndex:{:#x}, Type:{:#x}, Data:{:#x}, DataSize:{:#x})", KeyHandle, ValueName, TitleIndex, Type, Data, DataSize));

        for(const auto& it : d.observers_ZwSetValueKey)
            it(KeyHandle, ValueName, TitleIndex, Type, Data, DataSize);
    }

    static void on_NtSetVolumeInformationFile(monitor::syscallswow64::Data& d)
    {
        const auto FileHandle         = arg<wntdll::HANDLE>(d.core, 0);
        const auto IoStatusBlock      = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 1);
        const auto FsInformation      = arg<wntdll::PVOID>(d.core, 2);
        const auto Length             = arg<wntdll::ULONG>(d.core, 3);
        const auto FsInformationClass = arg<wntdll::FS_INFORMATION_CLASS>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtSetVolumeInformationFile(FileHandle:{:#x}, IoStatusBlock:{:#x}, FsInformation:{:#x}, Length:{:#x}, FsInformationClass:{:#x})", FileHandle, IoStatusBlock, FsInformation, Length, FsInformationClass));

        for(const auto& it : d.observers_NtSetVolumeInformationFile)
            it(FileHandle, IoStatusBlock, FsInformation, Length, FsInformationClass);
    }

    static void on_ZwShutdownSystem(monitor::syscallswow64::Data& d)
    {
        const auto Action = arg<wntdll::SHUTDOWN_ACTION>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwShutdownSystem(Action:{:#x})", Action));

        for(const auto& it : d.observers_ZwShutdownSystem)
            it(Action);
    }

    static void on_NtShutdownWorkerFactory(monitor::syscallswow64::Data& d)
    {
        const auto WorkerFactoryHandle    = arg<wntdll::HANDLE>(d.core, 0);
        const auto STARPendingWorkerCount = arg<wntdll::LONG>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtShutdownWorkerFactory(WorkerFactoryHandle:{:#x}, STARPendingWorkerCount:{:#x})", WorkerFactoryHandle, STARPendingWorkerCount));

        for(const auto& it : d.observers_NtShutdownWorkerFactory)
            it(WorkerFactoryHandle, STARPendingWorkerCount);
    }

    static void on_ZwSignalAndWaitForSingleObject(monitor::syscallswow64::Data& d)
    {
        const auto SignalHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto WaitHandle   = arg<wntdll::HANDLE>(d.core, 1);
        const auto Alertable    = arg<wntdll::BOOLEAN>(d.core, 2);
        const auto Timeout      = arg<wntdll::PLARGE_INTEGER>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSignalAndWaitForSingleObject(SignalHandle:{:#x}, WaitHandle:{:#x}, Alertable:{:#x}, Timeout:{:#x})", SignalHandle, WaitHandle, Alertable, Timeout));

        for(const auto& it : d.observers_ZwSignalAndWaitForSingleObject)
            it(SignalHandle, WaitHandle, Alertable, Timeout);
    }

    static void on_ZwSinglePhaseReject(monitor::syscallswow64::Data& d)
    {
        const auto EnlistmentHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto TmVirtualClock   = arg<wntdll::PLARGE_INTEGER>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSinglePhaseReject(EnlistmentHandle:{:#x}, TmVirtualClock:{:#x})", EnlistmentHandle, TmVirtualClock));

        for(const auto& it : d.observers_ZwSinglePhaseReject)
            it(EnlistmentHandle, TmVirtualClock);
    }

    static void on_NtStartProfile(monitor::syscallswow64::Data& d)
    {
        const auto ProfileHandle = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtStartProfile(ProfileHandle:{:#x})", ProfileHandle));

        for(const auto& it : d.observers_NtStartProfile)
            it(ProfileHandle);
    }

    static void on_ZwStopProfile(monitor::syscallswow64::Data& d)
    {
        const auto ProfileHandle = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwStopProfile(ProfileHandle:{:#x})", ProfileHandle));

        for(const auto& it : d.observers_ZwStopProfile)
            it(ProfileHandle);
    }

    static void on_ZwSuspendProcess(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSuspendProcess(ProcessHandle:{:#x})", ProcessHandle));

        for(const auto& it : d.observers_ZwSuspendProcess)
            it(ProcessHandle);
    }

    static void on_ZwSuspendThread(monitor::syscallswow64::Data& d)
    {
        const auto ThreadHandle         = arg<wntdll::HANDLE>(d.core, 0);
        const auto PreviousSuspendCount = arg<wntdll::PULONG>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwSuspendThread(ThreadHandle:{:#x}, PreviousSuspendCount:{:#x})", ThreadHandle, PreviousSuspendCount));

        for(const auto& it : d.observers_ZwSuspendThread)
            it(ThreadHandle, PreviousSuspendCount);
    }

    static void on_NtSystemDebugControl(monitor::syscallswow64::Data& d)
    {
        const auto Command            = arg<wntdll::SYSDBG_COMMAND>(d.core, 0);
        const auto InputBuffer        = arg<wntdll::PVOID>(d.core, 1);
        const auto InputBufferLength  = arg<wntdll::ULONG>(d.core, 2);
        const auto OutputBuffer       = arg<wntdll::PVOID>(d.core, 3);
        const auto OutputBufferLength = arg<wntdll::ULONG>(d.core, 4);
        const auto ReturnLength       = arg<wntdll::PULONG>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtSystemDebugControl(Command:{:#x}, InputBuffer:{:#x}, InputBufferLength:{:#x}, OutputBuffer:{:#x}, OutputBufferLength:{:#x}, ReturnLength:{:#x})", Command, InputBuffer, InputBufferLength, OutputBuffer, OutputBufferLength, ReturnLength));

        for(const auto& it : d.observers_NtSystemDebugControl)
            it(Command, InputBuffer, InputBufferLength, OutputBuffer, OutputBufferLength, ReturnLength);
    }

    static void on_ZwTerminateJobObject(monitor::syscallswow64::Data& d)
    {
        const auto JobHandle  = arg<wntdll::HANDLE>(d.core, 0);
        const auto ExitStatus = arg<wntdll::NTSTATUS>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwTerminateJobObject(JobHandle:{:#x}, ExitStatus:{:#x})", JobHandle, ExitStatus));

        for(const auto& it : d.observers_ZwTerminateJobObject)
            it(JobHandle, ExitStatus);
    }

    static void on_ZwTerminateProcess(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto ExitStatus    = arg<wntdll::NTSTATUS>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwTerminateProcess(ProcessHandle:{:#x}, ExitStatus:{:#x})", ProcessHandle, ExitStatus));

        for(const auto& it : d.observers_ZwTerminateProcess)
            it(ProcessHandle, ExitStatus);
    }

    static void on_ZwTerminateThread(monitor::syscallswow64::Data& d)
    {
        const auto ThreadHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto ExitStatus   = arg<wntdll::NTSTATUS>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwTerminateThread(ThreadHandle:{:#x}, ExitStatus:{:#x})", ThreadHandle, ExitStatus));

        for(const auto& it : d.observers_ZwTerminateThread)
            it(ThreadHandle, ExitStatus);
    }

    static void on_ZwTraceControl(monitor::syscallswow64::Data& d)
    {
        const auto FunctionCode = arg<wntdll::ULONG>(d.core, 0);
        const auto InBuffer     = arg<wntdll::PVOID>(d.core, 1);
        const auto InBufferLen  = arg<wntdll::ULONG>(d.core, 2);
        const auto OutBuffer    = arg<wntdll::PVOID>(d.core, 3);
        const auto OutBufferLen = arg<wntdll::ULONG>(d.core, 4);
        const auto ReturnLength = arg<wntdll::PULONG>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwTraceControl(FunctionCode:{:#x}, InBuffer:{:#x}, InBufferLen:{:#x}, OutBuffer:{:#x}, OutBufferLen:{:#x}, ReturnLength:{:#x})", FunctionCode, InBuffer, InBufferLen, OutBuffer, OutBufferLen, ReturnLength));

        for(const auto& it : d.observers_ZwTraceControl)
            it(FunctionCode, InBuffer, InBufferLen, OutBuffer, OutBufferLen, ReturnLength);
    }

    static void on_NtTraceEvent(monitor::syscallswow64::Data& d)
    {
        const auto TraceHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto Flags       = arg<wntdll::ULONG>(d.core, 1);
        const auto FieldSize   = arg<wntdll::ULONG>(d.core, 2);
        const auto Fields      = arg<wntdll::PVOID>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtTraceEvent(TraceHandle:{:#x}, Flags:{:#x}, FieldSize:{:#x}, Fields:{:#x})", TraceHandle, Flags, FieldSize, Fields));

        for(const auto& it : d.observers_NtTraceEvent)
            it(TraceHandle, Flags, FieldSize, Fields);
    }

    static void on_NtTranslateFilePath(monitor::syscallswow64::Data& d)
    {
        const auto InputFilePath        = arg<wntdll::PFILE_PATH>(d.core, 0);
        const auto OutputType           = arg<wntdll::ULONG>(d.core, 1);
        const auto OutputFilePath       = arg<wntdll::PFILE_PATH>(d.core, 2);
        const auto OutputFilePathLength = arg<wntdll::PULONG>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtTranslateFilePath(InputFilePath:{:#x}, OutputType:{:#x}, OutputFilePath:{:#x}, OutputFilePathLength:{:#x})", InputFilePath, OutputType, OutputFilePath, OutputFilePathLength));

        for(const auto& it : d.observers_NtTranslateFilePath)
            it(InputFilePath, OutputType, OutputFilePath, OutputFilePathLength);
    }

    static void on_ZwUnloadDriver(monitor::syscallswow64::Data& d)
    {
        const auto DriverServiceName = arg<wntdll::PUNICODE_STRING>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwUnloadDriver(DriverServiceName:{:#x})", DriverServiceName));

        for(const auto& it : d.observers_ZwUnloadDriver)
            it(DriverServiceName);
    }

    static void on_ZwUnloadKey2(monitor::syscallswow64::Data& d)
    {
        const auto TargetKey = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 0);
        const auto Flags     = arg<wntdll::ULONG>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwUnloadKey2(TargetKey:{:#x}, Flags:{:#x})", TargetKey, Flags));

        for(const auto& it : d.observers_ZwUnloadKey2)
            it(TargetKey, Flags);
    }

    static void on_ZwUnloadKeyEx(monitor::syscallswow64::Data& d)
    {
        const auto TargetKey = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 0);
        const auto Event     = arg<wntdll::HANDLE>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwUnloadKeyEx(TargetKey:{:#x}, Event:{:#x})", TargetKey, Event));

        for(const auto& it : d.observers_ZwUnloadKeyEx)
            it(TargetKey, Event);
    }

    static void on_NtUnloadKey(monitor::syscallswow64::Data& d)
    {
        const auto TargetKey = arg<wntdll::POBJECT_ATTRIBUTES>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtUnloadKey(TargetKey:{:#x})", TargetKey));

        for(const auto& it : d.observers_NtUnloadKey)
            it(TargetKey);
    }

    static void on_ZwUnlockFile(monitor::syscallswow64::Data& d)
    {
        const auto FileHandle    = arg<wntdll::HANDLE>(d.core, 0);
        const auto IoStatusBlock = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 1);
        const auto ByteOffset    = arg<wntdll::PLARGE_INTEGER>(d.core, 2);
        const auto Length        = arg<wntdll::PLARGE_INTEGER>(d.core, 3);
        const auto Key           = arg<wntdll::ULONG>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwUnlockFile(FileHandle:{:#x}, IoStatusBlock:{:#x}, ByteOffset:{:#x}, Length:{:#x}, Key:{:#x})", FileHandle, IoStatusBlock, ByteOffset, Length, Key));

        for(const auto& it : d.observers_ZwUnlockFile)
            it(FileHandle, IoStatusBlock, ByteOffset, Length, Key);
    }

    static void on_NtUnlockVirtualMemory(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle   = arg<wntdll::HANDLE>(d.core, 0);
        const auto STARBaseAddress = arg<wntdll::PVOID>(d.core, 1);
        const auto RegionSize      = arg<wntdll::PSIZE_T>(d.core, 2);
        const auto MapType         = arg<wntdll::ULONG>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtUnlockVirtualMemory(ProcessHandle:{:#x}, STARBaseAddress:{:#x}, RegionSize:{:#x}, MapType:{:#x})", ProcessHandle, STARBaseAddress, RegionSize, MapType));

        for(const auto& it : d.observers_NtUnlockVirtualMemory)
            it(ProcessHandle, STARBaseAddress, RegionSize, MapType);
    }

    static void on_NtUnmapViewOfSection(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto BaseAddress   = arg<wntdll::PVOID>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtUnmapViewOfSection(ProcessHandle:{:#x}, BaseAddress:{:#x})", ProcessHandle, BaseAddress));

        for(const auto& it : d.observers_NtUnmapViewOfSection)
            it(ProcessHandle, BaseAddress);
    }

    static void on_NtVdmControl(monitor::syscallswow64::Data& d)
    {
        const auto Service     = arg<wntdll::VDMSERVICECLASS>(d.core, 0);
        const auto ServiceData = arg<wntdll::PVOID>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtVdmControl(Service:{:#x}, ServiceData:{:#x})", Service, ServiceData));

        for(const auto& it : d.observers_NtVdmControl)
            it(Service, ServiceData);
    }

    static void on_NtWaitForDebugEvent(monitor::syscallswow64::Data& d)
    {
        const auto DebugObjectHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto Alertable         = arg<wntdll::BOOLEAN>(d.core, 1);
        const auto Timeout           = arg<wntdll::PLARGE_INTEGER>(d.core, 2);
        const auto WaitStateChange   = arg<wntdll::PDBGUI_WAIT_STATE_CHANGE>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtWaitForDebugEvent(DebugObjectHandle:{:#x}, Alertable:{:#x}, Timeout:{:#x}, WaitStateChange:{:#x})", DebugObjectHandle, Alertable, Timeout, WaitStateChange));

        for(const auto& it : d.observers_NtWaitForDebugEvent)
            it(DebugObjectHandle, Alertable, Timeout, WaitStateChange);
    }

    static void on_NtWaitForKeyedEvent(monitor::syscallswow64::Data& d)
    {
        const auto KeyedEventHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto KeyValue         = arg<wntdll::PVOID>(d.core, 1);
        const auto Alertable        = arg<wntdll::BOOLEAN>(d.core, 2);
        const auto Timeout          = arg<wntdll::PLARGE_INTEGER>(d.core, 3);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtWaitForKeyedEvent(KeyedEventHandle:{:#x}, KeyValue:{:#x}, Alertable:{:#x}, Timeout:{:#x})", KeyedEventHandle, KeyValue, Alertable, Timeout));

        for(const auto& it : d.observers_NtWaitForKeyedEvent)
            it(KeyedEventHandle, KeyValue, Alertable, Timeout);
    }

    static void on_NtWaitForMultipleObjects32(monitor::syscallswow64::Data& d)
    {
        const auto Count     = arg<wntdll::ULONG>(d.core, 0);
        const auto Handles   = arg<wntdll::LONG>(d.core, 1);
        const auto WaitType  = arg<wntdll::WAIT_TYPE>(d.core, 2);
        const auto Alertable = arg<wntdll::BOOLEAN>(d.core, 3);
        const auto Timeout   = arg<wntdll::PLARGE_INTEGER>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtWaitForMultipleObjects32(Count:{:#x}, Handles:{:#x}, WaitType:{:#x}, Alertable:{:#x}, Timeout:{:#x})", Count, Handles, WaitType, Alertable, Timeout));

        for(const auto& it : d.observers_NtWaitForMultipleObjects32)
            it(Count, Handles, WaitType, Alertable, Timeout);
    }

    static void on_NtWaitForMultipleObjects(monitor::syscallswow64::Data& d)
    {
        const auto Count     = arg<wntdll::ULONG>(d.core, 0);
        const auto Handles   = arg<wntdll::HANDLE>(d.core, 1);
        const auto WaitType  = arg<wntdll::WAIT_TYPE>(d.core, 2);
        const auto Alertable = arg<wntdll::BOOLEAN>(d.core, 3);
        const auto Timeout   = arg<wntdll::PLARGE_INTEGER>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtWaitForMultipleObjects(Count:{:#x}, Handles:{:#x}, WaitType:{:#x}, Alertable:{:#x}, Timeout:{:#x})", Count, Handles, WaitType, Alertable, Timeout));

        for(const auto& it : d.observers_NtWaitForMultipleObjects)
            it(Count, Handles, WaitType, Alertable, Timeout);
    }

    static void on_ZwWaitForSingleObject(monitor::syscallswow64::Data& d)
    {
        const auto Handle    = arg<wntdll::HANDLE>(d.core, 0);
        const auto Alertable = arg<wntdll::BOOLEAN>(d.core, 1);
        const auto Timeout   = arg<wntdll::PLARGE_INTEGER>(d.core, 2);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwWaitForSingleObject(Handle:{:#x}, Alertable:{:#x}, Timeout:{:#x})", Handle, Alertable, Timeout));

        for(const auto& it : d.observers_ZwWaitForSingleObject)
            it(Handle, Alertable, Timeout);
    }

    static void on_NtWaitForWorkViaWorkerFactory(monitor::syscallswow64::Data& d)
    {
        const auto WorkerFactoryHandle = arg<wntdll::HANDLE>(d.core, 0);
        const auto MiniPacket          = arg<wntdll::PFILE_IO_COMPLETION_INFORMATION>(d.core, 1);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtWaitForWorkViaWorkerFactory(WorkerFactoryHandle:{:#x}, MiniPacket:{:#x})", WorkerFactoryHandle, MiniPacket));

        for(const auto& it : d.observers_NtWaitForWorkViaWorkerFactory)
            it(WorkerFactoryHandle, MiniPacket);
    }

    static void on_ZwWaitHighEventPair(monitor::syscallswow64::Data& d)
    {
        const auto EventPairHandle = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwWaitHighEventPair(EventPairHandle:{:#x})", EventPairHandle));

        for(const auto& it : d.observers_ZwWaitHighEventPair)
            it(EventPairHandle);
    }

    static void on_NtWaitLowEventPair(monitor::syscallswow64::Data& d)
    {
        const auto EventPairHandle = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtWaitLowEventPair(EventPairHandle:{:#x})", EventPairHandle));

        for(const auto& it : d.observers_NtWaitLowEventPair)
            it(EventPairHandle);
    }

    static void on_NtWorkerFactoryWorkerReady(monitor::syscallswow64::Data& d)
    {
        const auto WorkerFactoryHandle = arg<wntdll::HANDLE>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtWorkerFactoryWorkerReady(WorkerFactoryHandle:{:#x})", WorkerFactoryHandle));

        for(const auto& it : d.observers_NtWorkerFactoryWorkerReady)
            it(WorkerFactoryHandle);
    }

    static void on_NtWriteFileGather(monitor::syscallswow64::Data& d)
    {
        const auto FileHandle    = arg<wntdll::HANDLE>(d.core, 0);
        const auto Event         = arg<wntdll::HANDLE>(d.core, 1);
        const auto ApcRoutine    = arg<wntdll::PIO_APC_ROUTINE>(d.core, 2);
        const auto ApcContext    = arg<wntdll::PVOID>(d.core, 3);
        const auto IoStatusBlock = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 4);
        const auto SegmentArray  = arg<wntdll::PFILE_SEGMENT_ELEMENT>(d.core, 5);
        const auto Length        = arg<wntdll::ULONG>(d.core, 6);
        const auto ByteOffset    = arg<wntdll::PLARGE_INTEGER>(d.core, 7);
        const auto Key           = arg<wntdll::PULONG>(d.core, 8);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtWriteFileGather(FileHandle:{:#x}, Event:{:#x}, ApcRoutine:{:#x}, ApcContext:{:#x}, IoStatusBlock:{:#x}, SegmentArray:{:#x}, Length:{:#x}, ByteOffset:{:#x}, Key:{:#x})", FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, SegmentArray, Length, ByteOffset, Key));

        for(const auto& it : d.observers_NtWriteFileGather)
            it(FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, SegmentArray, Length, ByteOffset, Key);
    }

    static void on_NtWriteFile(monitor::syscallswow64::Data& d)
    {
        const auto FileHandle    = arg<wntdll::HANDLE>(d.core, 0);
        const auto Event         = arg<wntdll::HANDLE>(d.core, 1);
        const auto ApcRoutine    = arg<wntdll::PIO_APC_ROUTINE>(d.core, 2);
        const auto ApcContext    = arg<wntdll::PVOID>(d.core, 3);
        const auto IoStatusBlock = arg<wntdll::PIO_STATUS_BLOCK>(d.core, 4);
        const auto Buffer        = arg<wntdll::PVOID>(d.core, 5);
        const auto Length        = arg<wntdll::ULONG>(d.core, 6);
        const auto ByteOffset    = arg<wntdll::PLARGE_INTEGER>(d.core, 7);
        const auto Key           = arg<wntdll::PULONG>(d.core, 8);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtWriteFile(FileHandle:{:#x}, Event:{:#x}, ApcRoutine:{:#x}, ApcContext:{:#x}, IoStatusBlock:{:#x}, Buffer:{:#x}, Length:{:#x}, ByteOffset:{:#x}, Key:{:#x})", FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, Buffer, Length, ByteOffset, Key));

        for(const auto& it : d.observers_NtWriteFile)
            it(FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, Buffer, Length, ByteOffset, Key);
    }

    static void on_NtWriteRequestData(monitor::syscallswow64::Data& d)
    {
        const auto PortHandle           = arg<wntdll::HANDLE>(d.core, 0);
        const auto Message              = arg<wntdll::PPORT_MESSAGE>(d.core, 1);
        const auto DataEntryIndex       = arg<wntdll::ULONG>(d.core, 2);
        const auto Buffer               = arg<wntdll::PVOID>(d.core, 3);
        const auto BufferSize           = arg<wntdll::SIZE_T>(d.core, 4);
        const auto NumberOfBytesWritten = arg<wntdll::PSIZE_T>(d.core, 5);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtWriteRequestData(PortHandle:{:#x}, Message:{:#x}, DataEntryIndex:{:#x}, Buffer:{:#x}, BufferSize:{:#x}, NumberOfBytesWritten:{:#x})", PortHandle, Message, DataEntryIndex, Buffer, BufferSize, NumberOfBytesWritten));

        for(const auto& it : d.observers_NtWriteRequestData)
            it(PortHandle, Message, DataEntryIndex, Buffer, BufferSize, NumberOfBytesWritten);
    }

    static void on_NtWriteVirtualMemory(monitor::syscallswow64::Data& d)
    {
        const auto ProcessHandle        = arg<wntdll::HANDLE>(d.core, 0);
        const auto BaseAddress          = arg<wntdll::PVOID>(d.core, 1);
        const auto Buffer               = arg<wntdll::PVOID>(d.core, 2);
        const auto BufferSize           = arg<wntdll::SIZE_T>(d.core, 3);
        const auto NumberOfBytesWritten = arg<wntdll::PSIZE_T>(d.core, 4);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtWriteVirtualMemory(ProcessHandle:{:#x}, BaseAddress:{:#x}, Buffer:{:#x}, BufferSize:{:#x}, NumberOfBytesWritten:{:#x})", ProcessHandle, BaseAddress, Buffer, BufferSize, NumberOfBytesWritten));

        for(const auto& it : d.observers_NtWriteVirtualMemory)
            it(ProcessHandle, BaseAddress, Buffer, BufferSize, NumberOfBytesWritten);
    }

    static void on_NtDisableLastKnownGood(monitor::syscallswow64::Data& d)
    {
        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtDisableLastKnownGood()"));

        for(const auto& it : d.observers_NtDisableLastKnownGood)
            it();
    }

    static void on_NtEnableLastKnownGood(monitor::syscallswow64::Data& d)
    {
        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtEnableLastKnownGood()"));

        for(const auto& it : d.observers_NtEnableLastKnownGood)
            it();
    }

    static void on_ZwFlushProcessWriteBuffers(monitor::syscallswow64::Data& d)
    {
        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwFlushProcessWriteBuffers()"));

        for(const auto& it : d.observers_ZwFlushProcessWriteBuffers)
            it();
    }

    static void on_NtFlushWriteBuffer(monitor::syscallswow64::Data& d)
    {
        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtFlushWriteBuffer()"));

        for(const auto& it : d.observers_NtFlushWriteBuffer)
            it();
    }

    static void on_NtGetCurrentProcessorNumber(monitor::syscallswow64::Data& d)
    {
        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtGetCurrentProcessorNumber()"));

        for(const auto& it : d.observers_NtGetCurrentProcessorNumber)
            it();
    }

    static void on_NtIsSystemResumeAutomatic(monitor::syscallswow64::Data& d)
    {
        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtIsSystemResumeAutomatic()"));

        for(const auto& it : d.observers_NtIsSystemResumeAutomatic)
            it();
    }

    static void on_ZwIsUILanguageComitted(monitor::syscallswow64::Data& d)
    {
        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwIsUILanguageComitted()"));

        for(const auto& it : d.observers_ZwIsUILanguageComitted)
            it();
    }

    static void on_ZwQueryPortInformationProcess(monitor::syscallswow64::Data& d)
    {
        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwQueryPortInformationProcess()"));

        for(const auto& it : d.observers_ZwQueryPortInformationProcess)
            it();
    }

    static void on_NtSerializeBoot(monitor::syscallswow64::Data& d)
    {
        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtSerializeBoot()"));

        for(const auto& it : d.observers_NtSerializeBoot)
            it();
    }

    static void on_NtTestAlert(monitor::syscallswow64::Data& d)
    {
        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtTestAlert()"));

        for(const auto& it : d.observers_NtTestAlert)
            it();
    }

    static void on_ZwThawRegistry(monitor::syscallswow64::Data& d)
    {
        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwThawRegistry()"));

        for(const auto& it : d.observers_ZwThawRegistry)
            it();
    }

    static void on_NtThawTransactions(monitor::syscallswow64::Data& d)
    {
        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("NtThawTransactions()"));

        for(const auto& it : d.observers_NtThawTransactions)
            it();
    }

    static void on_ZwUmsThreadYield(monitor::syscallswow64::Data& d)
    {
        const auto SchedulerParam = arg<wntdll::PVOID>(d.core, 0);

        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwUmsThreadYield(SchedulerParam:{:#x})", SchedulerParam));

        for(const auto& it : d.observers_ZwUmsThreadYield)
            it(SchedulerParam);
    }

    static void on_ZwYieldExecution(monitor::syscallswow64::Data& d)
    {
        if constexpr(g_debug)
            logg::print(logg::level_t::info, fmt::format("ZwYieldExecution()"));

        for(const auto& it : d.observers_ZwYieldExecution)
            it();
    }

}


bool monitor::syscallswow64::register_NtAcceptConnectPort(proc_t proc, const on_NtAcceptConnectPort_fn& on_func)
{
    if(d_->observers_NtAcceptConnectPort.empty())
        if(!register_callback_with(*d_, proc, "_NtAcceptConnectPort@24", &on_NtAcceptConnectPort))
            return false;

    d_->observers_NtAcceptConnectPort.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwAccessCheckAndAuditAlarm(proc_t proc, const on_ZwAccessCheckAndAuditAlarm_fn& on_func)
{
    if(d_->observers_ZwAccessCheckAndAuditAlarm.empty())
        if(!register_callback_with(*d_, proc, "_ZwAccessCheckAndAuditAlarm@44", &on_ZwAccessCheckAndAuditAlarm))
            return false;

    d_->observers_ZwAccessCheckAndAuditAlarm.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtAccessCheckByTypeAndAuditAlarm(proc_t proc, const on_NtAccessCheckByTypeAndAuditAlarm_fn& on_func)
{
    if(d_->observers_NtAccessCheckByTypeAndAuditAlarm.empty())
        if(!register_callback_with(*d_, proc, "_NtAccessCheckByTypeAndAuditAlarm@64", &on_NtAccessCheckByTypeAndAuditAlarm))
            return false;

    d_->observers_NtAccessCheckByTypeAndAuditAlarm.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtAccessCheckByType(proc_t proc, const on_NtAccessCheckByType_fn& on_func)
{
    if(d_->observers_NtAccessCheckByType.empty())
        if(!register_callback_with(*d_, proc, "_NtAccessCheckByType@44", &on_NtAccessCheckByType))
            return false;

    d_->observers_NtAccessCheckByType.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwAccessCheckByTypeResultListAndAuditAlarmByHandle(proc_t proc, const on_ZwAccessCheckByTypeResultListAndAuditAlarmByHandle_fn& on_func)
{
    if(d_->observers_ZwAccessCheckByTypeResultListAndAuditAlarmByHandle.empty())
        if(!register_callback_with(*d_, proc, "_ZwAccessCheckByTypeResultListAndAuditAlarmByHandle@68", &on_ZwAccessCheckByTypeResultListAndAuditAlarmByHandle))
            return false;

    d_->observers_ZwAccessCheckByTypeResultListAndAuditAlarmByHandle.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtAccessCheckByTypeResultListAndAuditAlarm(proc_t proc, const on_NtAccessCheckByTypeResultListAndAuditAlarm_fn& on_func)
{
    if(d_->observers_NtAccessCheckByTypeResultListAndAuditAlarm.empty())
        if(!register_callback_with(*d_, proc, "_NtAccessCheckByTypeResultListAndAuditAlarm@64", &on_NtAccessCheckByTypeResultListAndAuditAlarm))
            return false;

    d_->observers_NtAccessCheckByTypeResultListAndAuditAlarm.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtAccessCheckByTypeResultList(proc_t proc, const on_NtAccessCheckByTypeResultList_fn& on_func)
{
    if(d_->observers_NtAccessCheckByTypeResultList.empty())
        if(!register_callback_with(*d_, proc, "_NtAccessCheckByTypeResultList@44", &on_NtAccessCheckByTypeResultList))
            return false;

    d_->observers_NtAccessCheckByTypeResultList.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtAccessCheck(proc_t proc, const on_NtAccessCheck_fn& on_func)
{
    if(d_->observers_NtAccessCheck.empty())
        if(!register_callback_with(*d_, proc, "_NtAccessCheck@32", &on_NtAccessCheck))
            return false;

    d_->observers_NtAccessCheck.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtAddAtom(proc_t proc, const on_NtAddAtom_fn& on_func)
{
    if(d_->observers_NtAddAtom.empty())
        if(!register_callback_with(*d_, proc, "_NtAddAtom@12", &on_NtAddAtom))
            return false;

    d_->observers_NtAddAtom.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwAddBootEntry(proc_t proc, const on_ZwAddBootEntry_fn& on_func)
{
    if(d_->observers_ZwAddBootEntry.empty())
        if(!register_callback_with(*d_, proc, "_ZwAddBootEntry@8", &on_ZwAddBootEntry))
            return false;

    d_->observers_ZwAddBootEntry.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtAddDriverEntry(proc_t proc, const on_NtAddDriverEntry_fn& on_func)
{
    if(d_->observers_NtAddDriverEntry.empty())
        if(!register_callback_with(*d_, proc, "_NtAddDriverEntry@8", &on_NtAddDriverEntry))
            return false;

    d_->observers_NtAddDriverEntry.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwAdjustGroupsToken(proc_t proc, const on_ZwAdjustGroupsToken_fn& on_func)
{
    if(d_->observers_ZwAdjustGroupsToken.empty())
        if(!register_callback_with(*d_, proc, "_ZwAdjustGroupsToken@24", &on_ZwAdjustGroupsToken))
            return false;

    d_->observers_ZwAdjustGroupsToken.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwAdjustPrivilegesToken(proc_t proc, const on_ZwAdjustPrivilegesToken_fn& on_func)
{
    if(d_->observers_ZwAdjustPrivilegesToken.empty())
        if(!register_callback_with(*d_, proc, "_ZwAdjustPrivilegesToken@24", &on_ZwAdjustPrivilegesToken))
            return false;

    d_->observers_ZwAdjustPrivilegesToken.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtAlertResumeThread(proc_t proc, const on_NtAlertResumeThread_fn& on_func)
{
    if(d_->observers_NtAlertResumeThread.empty())
        if(!register_callback_with(*d_, proc, "_NtAlertResumeThread@8", &on_NtAlertResumeThread))
            return false;

    d_->observers_NtAlertResumeThread.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtAlertThread(proc_t proc, const on_NtAlertThread_fn& on_func)
{
    if(d_->observers_NtAlertThread.empty())
        if(!register_callback_with(*d_, proc, "_NtAlertThread@4", &on_NtAlertThread))
            return false;

    d_->observers_NtAlertThread.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwAllocateLocallyUniqueId(proc_t proc, const on_ZwAllocateLocallyUniqueId_fn& on_func)
{
    if(d_->observers_ZwAllocateLocallyUniqueId.empty())
        if(!register_callback_with(*d_, proc, "_ZwAllocateLocallyUniqueId@4", &on_ZwAllocateLocallyUniqueId))
            return false;

    d_->observers_ZwAllocateLocallyUniqueId.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtAllocateReserveObject(proc_t proc, const on_NtAllocateReserveObject_fn& on_func)
{
    if(d_->observers_NtAllocateReserveObject.empty())
        if(!register_callback_with(*d_, proc, "_NtAllocateReserveObject@12", &on_NtAllocateReserveObject))
            return false;

    d_->observers_NtAllocateReserveObject.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtAllocateUserPhysicalPages(proc_t proc, const on_NtAllocateUserPhysicalPages_fn& on_func)
{
    if(d_->observers_NtAllocateUserPhysicalPages.empty())
        if(!register_callback_with(*d_, proc, "_NtAllocateUserPhysicalPages@12", &on_NtAllocateUserPhysicalPages))
            return false;

    d_->observers_NtAllocateUserPhysicalPages.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtAllocateUuids(proc_t proc, const on_NtAllocateUuids_fn& on_func)
{
    if(d_->observers_NtAllocateUuids.empty())
        if(!register_callback_with(*d_, proc, "_NtAllocateUuids@16", &on_NtAllocateUuids))
            return false;

    d_->observers_NtAllocateUuids.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtAllocateVirtualMemory(proc_t proc, const on_NtAllocateVirtualMemory_fn& on_func)
{
    if(d_->observers_NtAllocateVirtualMemory.empty())
        if(!register_callback_with(*d_, proc, "_NtAllocateVirtualMemory@24", &on_NtAllocateVirtualMemory))
            return false;

    d_->observers_NtAllocateVirtualMemory.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtAlpcAcceptConnectPort(proc_t proc, const on_NtAlpcAcceptConnectPort_fn& on_func)
{
    if(d_->observers_NtAlpcAcceptConnectPort.empty())
        if(!register_callback_with(*d_, proc, "_NtAlpcAcceptConnectPort@36", &on_NtAlpcAcceptConnectPort))
            return false;

    d_->observers_NtAlpcAcceptConnectPort.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwAlpcCancelMessage(proc_t proc, const on_ZwAlpcCancelMessage_fn& on_func)
{
    if(d_->observers_ZwAlpcCancelMessage.empty())
        if(!register_callback_with(*d_, proc, "_ZwAlpcCancelMessage@12", &on_ZwAlpcCancelMessage))
            return false;

    d_->observers_ZwAlpcCancelMessage.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwAlpcConnectPort(proc_t proc, const on_ZwAlpcConnectPort_fn& on_func)
{
    if(d_->observers_ZwAlpcConnectPort.empty())
        if(!register_callback_with(*d_, proc, "_ZwAlpcConnectPort@44", &on_ZwAlpcConnectPort))
            return false;

    d_->observers_ZwAlpcConnectPort.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwAlpcCreatePort(proc_t proc, const on_ZwAlpcCreatePort_fn& on_func)
{
    if(d_->observers_ZwAlpcCreatePort.empty())
        if(!register_callback_with(*d_, proc, "_ZwAlpcCreatePort@12", &on_ZwAlpcCreatePort))
            return false;

    d_->observers_ZwAlpcCreatePort.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtAlpcCreatePortSection(proc_t proc, const on_NtAlpcCreatePortSection_fn& on_func)
{
    if(d_->observers_NtAlpcCreatePortSection.empty())
        if(!register_callback_with(*d_, proc, "_NtAlpcCreatePortSection@24", &on_NtAlpcCreatePortSection))
            return false;

    d_->observers_NtAlpcCreatePortSection.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwAlpcCreateResourceReserve(proc_t proc, const on_ZwAlpcCreateResourceReserve_fn& on_func)
{
    if(d_->observers_ZwAlpcCreateResourceReserve.empty())
        if(!register_callback_with(*d_, proc, "_ZwAlpcCreateResourceReserve@16", &on_ZwAlpcCreateResourceReserve))
            return false;

    d_->observers_ZwAlpcCreateResourceReserve.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwAlpcCreateSectionView(proc_t proc, const on_ZwAlpcCreateSectionView_fn& on_func)
{
    if(d_->observers_ZwAlpcCreateSectionView.empty())
        if(!register_callback_with(*d_, proc, "_ZwAlpcCreateSectionView@12", &on_ZwAlpcCreateSectionView))
            return false;

    d_->observers_ZwAlpcCreateSectionView.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwAlpcCreateSecurityContext(proc_t proc, const on_ZwAlpcCreateSecurityContext_fn& on_func)
{
    if(d_->observers_ZwAlpcCreateSecurityContext.empty())
        if(!register_callback_with(*d_, proc, "_ZwAlpcCreateSecurityContext@12", &on_ZwAlpcCreateSecurityContext))
            return false;

    d_->observers_ZwAlpcCreateSecurityContext.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwAlpcDeletePortSection(proc_t proc, const on_ZwAlpcDeletePortSection_fn& on_func)
{
    if(d_->observers_ZwAlpcDeletePortSection.empty())
        if(!register_callback_with(*d_, proc, "_ZwAlpcDeletePortSection@12", &on_ZwAlpcDeletePortSection))
            return false;

    d_->observers_ZwAlpcDeletePortSection.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtAlpcDeleteResourceReserve(proc_t proc, const on_NtAlpcDeleteResourceReserve_fn& on_func)
{
    if(d_->observers_NtAlpcDeleteResourceReserve.empty())
        if(!register_callback_with(*d_, proc, "_NtAlpcDeleteResourceReserve@12", &on_NtAlpcDeleteResourceReserve))
            return false;

    d_->observers_NtAlpcDeleteResourceReserve.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtAlpcDeleteSectionView(proc_t proc, const on_NtAlpcDeleteSectionView_fn& on_func)
{
    if(d_->observers_NtAlpcDeleteSectionView.empty())
        if(!register_callback_with(*d_, proc, "_NtAlpcDeleteSectionView@12", &on_NtAlpcDeleteSectionView))
            return false;

    d_->observers_NtAlpcDeleteSectionView.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtAlpcDeleteSecurityContext(proc_t proc, const on_NtAlpcDeleteSecurityContext_fn& on_func)
{
    if(d_->observers_NtAlpcDeleteSecurityContext.empty())
        if(!register_callback_with(*d_, proc, "_NtAlpcDeleteSecurityContext@12", &on_NtAlpcDeleteSecurityContext))
            return false;

    d_->observers_NtAlpcDeleteSecurityContext.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtAlpcDisconnectPort(proc_t proc, const on_NtAlpcDisconnectPort_fn& on_func)
{
    if(d_->observers_NtAlpcDisconnectPort.empty())
        if(!register_callback_with(*d_, proc, "_NtAlpcDisconnectPort@8", &on_NtAlpcDisconnectPort))
            return false;

    d_->observers_NtAlpcDisconnectPort.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwAlpcImpersonateClientOfPort(proc_t proc, const on_ZwAlpcImpersonateClientOfPort_fn& on_func)
{
    if(d_->observers_ZwAlpcImpersonateClientOfPort.empty())
        if(!register_callback_with(*d_, proc, "_ZwAlpcImpersonateClientOfPort@12", &on_ZwAlpcImpersonateClientOfPort))
            return false;

    d_->observers_ZwAlpcImpersonateClientOfPort.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwAlpcOpenSenderProcess(proc_t proc, const on_ZwAlpcOpenSenderProcess_fn& on_func)
{
    if(d_->observers_ZwAlpcOpenSenderProcess.empty())
        if(!register_callback_with(*d_, proc, "_ZwAlpcOpenSenderProcess@24", &on_ZwAlpcOpenSenderProcess))
            return false;

    d_->observers_ZwAlpcOpenSenderProcess.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwAlpcOpenSenderThread(proc_t proc, const on_ZwAlpcOpenSenderThread_fn& on_func)
{
    if(d_->observers_ZwAlpcOpenSenderThread.empty())
        if(!register_callback_with(*d_, proc, "_ZwAlpcOpenSenderThread@24", &on_ZwAlpcOpenSenderThread))
            return false;

    d_->observers_ZwAlpcOpenSenderThread.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwAlpcQueryInformation(proc_t proc, const on_ZwAlpcQueryInformation_fn& on_func)
{
    if(d_->observers_ZwAlpcQueryInformation.empty())
        if(!register_callback_with(*d_, proc, "_ZwAlpcQueryInformation@20", &on_ZwAlpcQueryInformation))
            return false;

    d_->observers_ZwAlpcQueryInformation.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwAlpcQueryInformationMessage(proc_t proc, const on_ZwAlpcQueryInformationMessage_fn& on_func)
{
    if(d_->observers_ZwAlpcQueryInformationMessage.empty())
        if(!register_callback_with(*d_, proc, "_ZwAlpcQueryInformationMessage@24", &on_ZwAlpcQueryInformationMessage))
            return false;

    d_->observers_ZwAlpcQueryInformationMessage.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtAlpcRevokeSecurityContext(proc_t proc, const on_NtAlpcRevokeSecurityContext_fn& on_func)
{
    if(d_->observers_NtAlpcRevokeSecurityContext.empty())
        if(!register_callback_with(*d_, proc, "_NtAlpcRevokeSecurityContext@12", &on_NtAlpcRevokeSecurityContext))
            return false;

    d_->observers_NtAlpcRevokeSecurityContext.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtAlpcSendWaitReceivePort(proc_t proc, const on_NtAlpcSendWaitReceivePort_fn& on_func)
{
    if(d_->observers_NtAlpcSendWaitReceivePort.empty())
        if(!register_callback_with(*d_, proc, "_NtAlpcSendWaitReceivePort@32", &on_NtAlpcSendWaitReceivePort))
            return false;

    d_->observers_NtAlpcSendWaitReceivePort.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtAlpcSetInformation(proc_t proc, const on_NtAlpcSetInformation_fn& on_func)
{
    if(d_->observers_NtAlpcSetInformation.empty())
        if(!register_callback_with(*d_, proc, "_NtAlpcSetInformation@16", &on_NtAlpcSetInformation))
            return false;

    d_->observers_NtAlpcSetInformation.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtApphelpCacheControl(proc_t proc, const on_NtApphelpCacheControl_fn& on_func)
{
    if(d_->observers_NtApphelpCacheControl.empty())
        if(!register_callback_with(*d_, proc, "_NtApphelpCacheControl@8", &on_NtApphelpCacheControl))
            return false;

    d_->observers_NtApphelpCacheControl.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwAreMappedFilesTheSame(proc_t proc, const on_ZwAreMappedFilesTheSame_fn& on_func)
{
    if(d_->observers_ZwAreMappedFilesTheSame.empty())
        if(!register_callback_with(*d_, proc, "_ZwAreMappedFilesTheSame@8", &on_ZwAreMappedFilesTheSame))
            return false;

    d_->observers_ZwAreMappedFilesTheSame.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwAssignProcessToJobObject(proc_t proc, const on_ZwAssignProcessToJobObject_fn& on_func)
{
    if(d_->observers_ZwAssignProcessToJobObject.empty())
        if(!register_callback_with(*d_, proc, "_ZwAssignProcessToJobObject@8", &on_ZwAssignProcessToJobObject))
            return false;

    d_->observers_ZwAssignProcessToJobObject.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwCallbackReturn(proc_t proc, const on_ZwCallbackReturn_fn& on_func)
{
    if(d_->observers_ZwCallbackReturn.empty())
        if(!register_callback_with(*d_, proc, "_ZwCallbackReturn@12", &on_ZwCallbackReturn))
            return false;

    d_->observers_ZwCallbackReturn.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtCancelIoFileEx(proc_t proc, const on_NtCancelIoFileEx_fn& on_func)
{
    if(d_->observers_NtCancelIoFileEx.empty())
        if(!register_callback_with(*d_, proc, "_NtCancelIoFileEx@12", &on_NtCancelIoFileEx))
            return false;

    d_->observers_NtCancelIoFileEx.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwCancelIoFile(proc_t proc, const on_ZwCancelIoFile_fn& on_func)
{
    if(d_->observers_ZwCancelIoFile.empty())
        if(!register_callback_with(*d_, proc, "_ZwCancelIoFile@8", &on_ZwCancelIoFile))
            return false;

    d_->observers_ZwCancelIoFile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtCancelSynchronousIoFile(proc_t proc, const on_NtCancelSynchronousIoFile_fn& on_func)
{
    if(d_->observers_NtCancelSynchronousIoFile.empty())
        if(!register_callback_with(*d_, proc, "_NtCancelSynchronousIoFile@12", &on_NtCancelSynchronousIoFile))
            return false;

    d_->observers_NtCancelSynchronousIoFile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwCancelTimer(proc_t proc, const on_ZwCancelTimer_fn& on_func)
{
    if(d_->observers_ZwCancelTimer.empty())
        if(!register_callback_with(*d_, proc, "_ZwCancelTimer@8", &on_ZwCancelTimer))
            return false;

    d_->observers_ZwCancelTimer.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtClearEvent(proc_t proc, const on_NtClearEvent_fn& on_func)
{
    if(d_->observers_NtClearEvent.empty())
        if(!register_callback_with(*d_, proc, "_NtClearEvent@4", &on_NtClearEvent))
            return false;

    d_->observers_NtClearEvent.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtClose(proc_t proc, const on_NtClose_fn& on_func)
{
    if(d_->observers_NtClose.empty())
        if(!register_callback_with(*d_, proc, "_NtClose@4", &on_NtClose))
            return false;

    d_->observers_NtClose.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwCloseObjectAuditAlarm(proc_t proc, const on_ZwCloseObjectAuditAlarm_fn& on_func)
{
    if(d_->observers_ZwCloseObjectAuditAlarm.empty())
        if(!register_callback_with(*d_, proc, "_ZwCloseObjectAuditAlarm@12", &on_ZwCloseObjectAuditAlarm))
            return false;

    d_->observers_ZwCloseObjectAuditAlarm.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwCommitComplete(proc_t proc, const on_ZwCommitComplete_fn& on_func)
{
    if(d_->observers_ZwCommitComplete.empty())
        if(!register_callback_with(*d_, proc, "_ZwCommitComplete@8", &on_ZwCommitComplete))
            return false;

    d_->observers_ZwCommitComplete.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtCommitEnlistment(proc_t proc, const on_NtCommitEnlistment_fn& on_func)
{
    if(d_->observers_NtCommitEnlistment.empty())
        if(!register_callback_with(*d_, proc, "_NtCommitEnlistment@8", &on_NtCommitEnlistment))
            return false;

    d_->observers_NtCommitEnlistment.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtCommitTransaction(proc_t proc, const on_NtCommitTransaction_fn& on_func)
{
    if(d_->observers_NtCommitTransaction.empty())
        if(!register_callback_with(*d_, proc, "_NtCommitTransaction@8", &on_NtCommitTransaction))
            return false;

    d_->observers_NtCommitTransaction.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtCompactKeys(proc_t proc, const on_NtCompactKeys_fn& on_func)
{
    if(d_->observers_NtCompactKeys.empty())
        if(!register_callback_with(*d_, proc, "_NtCompactKeys@8", &on_NtCompactKeys))
            return false;

    d_->observers_NtCompactKeys.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwCompareTokens(proc_t proc, const on_ZwCompareTokens_fn& on_func)
{
    if(d_->observers_ZwCompareTokens.empty())
        if(!register_callback_with(*d_, proc, "_ZwCompareTokens@12", &on_ZwCompareTokens))
            return false;

    d_->observers_ZwCompareTokens.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtCompleteConnectPort(proc_t proc, const on_NtCompleteConnectPort_fn& on_func)
{
    if(d_->observers_NtCompleteConnectPort.empty())
        if(!register_callback_with(*d_, proc, "_NtCompleteConnectPort@4", &on_NtCompleteConnectPort))
            return false;

    d_->observers_NtCompleteConnectPort.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwCompressKey(proc_t proc, const on_ZwCompressKey_fn& on_func)
{
    if(d_->observers_ZwCompressKey.empty())
        if(!register_callback_with(*d_, proc, "_ZwCompressKey@4", &on_ZwCompressKey))
            return false;

    d_->observers_ZwCompressKey.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtConnectPort(proc_t proc, const on_NtConnectPort_fn& on_func)
{
    if(d_->observers_NtConnectPort.empty())
        if(!register_callback_with(*d_, proc, "_NtConnectPort@32", &on_NtConnectPort))
            return false;

    d_->observers_NtConnectPort.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwContinue(proc_t proc, const on_ZwContinue_fn& on_func)
{
    if(d_->observers_ZwContinue.empty())
        if(!register_callback_with(*d_, proc, "_ZwContinue@8", &on_ZwContinue))
            return false;

    d_->observers_ZwContinue.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwCreateDebugObject(proc_t proc, const on_ZwCreateDebugObject_fn& on_func)
{
    if(d_->observers_ZwCreateDebugObject.empty())
        if(!register_callback_with(*d_, proc, "_ZwCreateDebugObject@16", &on_ZwCreateDebugObject))
            return false;

    d_->observers_ZwCreateDebugObject.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwCreateDirectoryObject(proc_t proc, const on_ZwCreateDirectoryObject_fn& on_func)
{
    if(d_->observers_ZwCreateDirectoryObject.empty())
        if(!register_callback_with(*d_, proc, "_ZwCreateDirectoryObject@12", &on_ZwCreateDirectoryObject))
            return false;

    d_->observers_ZwCreateDirectoryObject.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwCreateEnlistment(proc_t proc, const on_ZwCreateEnlistment_fn& on_func)
{
    if(d_->observers_ZwCreateEnlistment.empty())
        if(!register_callback_with(*d_, proc, "_ZwCreateEnlistment@32", &on_ZwCreateEnlistment))
            return false;

    d_->observers_ZwCreateEnlistment.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtCreateEvent(proc_t proc, const on_NtCreateEvent_fn& on_func)
{
    if(d_->observers_NtCreateEvent.empty())
        if(!register_callback_with(*d_, proc, "_NtCreateEvent@20", &on_NtCreateEvent))
            return false;

    d_->observers_NtCreateEvent.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtCreateEventPair(proc_t proc, const on_NtCreateEventPair_fn& on_func)
{
    if(d_->observers_NtCreateEventPair.empty())
        if(!register_callback_with(*d_, proc, "_NtCreateEventPair@12", &on_NtCreateEventPair))
            return false;

    d_->observers_NtCreateEventPair.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtCreateFile(proc_t proc, const on_NtCreateFile_fn& on_func)
{
    if(d_->observers_NtCreateFile.empty())
        if(!register_callback_with(*d_, proc, "_NtCreateFile@44", &on_NtCreateFile))
            return false;

    d_->observers_NtCreateFile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtCreateIoCompletion(proc_t proc, const on_NtCreateIoCompletion_fn& on_func)
{
    if(d_->observers_NtCreateIoCompletion.empty())
        if(!register_callback_with(*d_, proc, "_NtCreateIoCompletion@16", &on_NtCreateIoCompletion))
            return false;

    d_->observers_NtCreateIoCompletion.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwCreateJobObject(proc_t proc, const on_ZwCreateJobObject_fn& on_func)
{
    if(d_->observers_ZwCreateJobObject.empty())
        if(!register_callback_with(*d_, proc, "_ZwCreateJobObject@12", &on_ZwCreateJobObject))
            return false;

    d_->observers_ZwCreateJobObject.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtCreateJobSet(proc_t proc, const on_NtCreateJobSet_fn& on_func)
{
    if(d_->observers_NtCreateJobSet.empty())
        if(!register_callback_with(*d_, proc, "_NtCreateJobSet@12", &on_NtCreateJobSet))
            return false;

    d_->observers_NtCreateJobSet.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwCreateKeyedEvent(proc_t proc, const on_ZwCreateKeyedEvent_fn& on_func)
{
    if(d_->observers_ZwCreateKeyedEvent.empty())
        if(!register_callback_with(*d_, proc, "_ZwCreateKeyedEvent@16", &on_ZwCreateKeyedEvent))
            return false;

    d_->observers_ZwCreateKeyedEvent.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwCreateKey(proc_t proc, const on_ZwCreateKey_fn& on_func)
{
    if(d_->observers_ZwCreateKey.empty())
        if(!register_callback_with(*d_, proc, "_ZwCreateKey@28", &on_ZwCreateKey))
            return false;

    d_->observers_ZwCreateKey.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtCreateKeyTransacted(proc_t proc, const on_NtCreateKeyTransacted_fn& on_func)
{
    if(d_->observers_NtCreateKeyTransacted.empty())
        if(!register_callback_with(*d_, proc, "_NtCreateKeyTransacted@32", &on_NtCreateKeyTransacted))
            return false;

    d_->observers_NtCreateKeyTransacted.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwCreateMailslotFile(proc_t proc, const on_ZwCreateMailslotFile_fn& on_func)
{
    if(d_->observers_ZwCreateMailslotFile.empty())
        if(!register_callback_with(*d_, proc, "_ZwCreateMailslotFile@32", &on_ZwCreateMailslotFile))
            return false;

    d_->observers_ZwCreateMailslotFile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwCreateMutant(proc_t proc, const on_ZwCreateMutant_fn& on_func)
{
    if(d_->observers_ZwCreateMutant.empty())
        if(!register_callback_with(*d_, proc, "_ZwCreateMutant@16", &on_ZwCreateMutant))
            return false;

    d_->observers_ZwCreateMutant.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwCreateNamedPipeFile(proc_t proc, const on_ZwCreateNamedPipeFile_fn& on_func)
{
    if(d_->observers_ZwCreateNamedPipeFile.empty())
        if(!register_callback_with(*d_, proc, "_ZwCreateNamedPipeFile@56", &on_ZwCreateNamedPipeFile))
            return false;

    d_->observers_ZwCreateNamedPipeFile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtCreatePagingFile(proc_t proc, const on_NtCreatePagingFile_fn& on_func)
{
    if(d_->observers_NtCreatePagingFile.empty())
        if(!register_callback_with(*d_, proc, "_NtCreatePagingFile@16", &on_NtCreatePagingFile))
            return false;

    d_->observers_NtCreatePagingFile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwCreatePort(proc_t proc, const on_ZwCreatePort_fn& on_func)
{
    if(d_->observers_ZwCreatePort.empty())
        if(!register_callback_with(*d_, proc, "_ZwCreatePort@20", &on_ZwCreatePort))
            return false;

    d_->observers_ZwCreatePort.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtCreatePrivateNamespace(proc_t proc, const on_NtCreatePrivateNamespace_fn& on_func)
{
    if(d_->observers_NtCreatePrivateNamespace.empty())
        if(!register_callback_with(*d_, proc, "_NtCreatePrivateNamespace@16", &on_NtCreatePrivateNamespace))
            return false;

    d_->observers_NtCreatePrivateNamespace.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwCreateProcessEx(proc_t proc, const on_ZwCreateProcessEx_fn& on_func)
{
    if(d_->observers_ZwCreateProcessEx.empty())
        if(!register_callback_with(*d_, proc, "_ZwCreateProcessEx@36", &on_ZwCreateProcessEx))
            return false;

    d_->observers_ZwCreateProcessEx.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwCreateProcess(proc_t proc, const on_ZwCreateProcess_fn& on_func)
{
    if(d_->observers_ZwCreateProcess.empty())
        if(!register_callback_with(*d_, proc, "_ZwCreateProcess@32", &on_ZwCreateProcess))
            return false;

    d_->observers_ZwCreateProcess.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtCreateProfileEx(proc_t proc, const on_NtCreateProfileEx_fn& on_func)
{
    if(d_->observers_NtCreateProfileEx.empty())
        if(!register_callback_with(*d_, proc, "_NtCreateProfileEx@40", &on_NtCreateProfileEx))
            return false;

    d_->observers_NtCreateProfileEx.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwCreateProfile(proc_t proc, const on_ZwCreateProfile_fn& on_func)
{
    if(d_->observers_ZwCreateProfile.empty())
        if(!register_callback_with(*d_, proc, "_ZwCreateProfile@36", &on_ZwCreateProfile))
            return false;

    d_->observers_ZwCreateProfile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwCreateResourceManager(proc_t proc, const on_ZwCreateResourceManager_fn& on_func)
{
    if(d_->observers_ZwCreateResourceManager.empty())
        if(!register_callback_with(*d_, proc, "_ZwCreateResourceManager@28", &on_ZwCreateResourceManager))
            return false;

    d_->observers_ZwCreateResourceManager.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtCreateSection(proc_t proc, const on_NtCreateSection_fn& on_func)
{
    if(d_->observers_NtCreateSection.empty())
        if(!register_callback_with(*d_, proc, "_NtCreateSection@28", &on_NtCreateSection))
            return false;

    d_->observers_NtCreateSection.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtCreateSemaphore(proc_t proc, const on_NtCreateSemaphore_fn& on_func)
{
    if(d_->observers_NtCreateSemaphore.empty())
        if(!register_callback_with(*d_, proc, "_NtCreateSemaphore@20", &on_NtCreateSemaphore))
            return false;

    d_->observers_NtCreateSemaphore.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwCreateSymbolicLinkObject(proc_t proc, const on_ZwCreateSymbolicLinkObject_fn& on_func)
{
    if(d_->observers_ZwCreateSymbolicLinkObject.empty())
        if(!register_callback_with(*d_, proc, "_ZwCreateSymbolicLinkObject@16", &on_ZwCreateSymbolicLinkObject))
            return false;

    d_->observers_ZwCreateSymbolicLinkObject.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtCreateThreadEx(proc_t proc, const on_NtCreateThreadEx_fn& on_func)
{
    if(d_->observers_NtCreateThreadEx.empty())
        if(!register_callback_with(*d_, proc, "_NtCreateThreadEx@44", &on_NtCreateThreadEx))
            return false;

    d_->observers_NtCreateThreadEx.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtCreateThread(proc_t proc, const on_NtCreateThread_fn& on_func)
{
    if(d_->observers_NtCreateThread.empty())
        if(!register_callback_with(*d_, proc, "_NtCreateThread@32", &on_NtCreateThread))
            return false;

    d_->observers_NtCreateThread.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwCreateTimer(proc_t proc, const on_ZwCreateTimer_fn& on_func)
{
    if(d_->observers_ZwCreateTimer.empty())
        if(!register_callback_with(*d_, proc, "_ZwCreateTimer@16", &on_ZwCreateTimer))
            return false;

    d_->observers_ZwCreateTimer.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtCreateToken(proc_t proc, const on_NtCreateToken_fn& on_func)
{
    if(d_->observers_NtCreateToken.empty())
        if(!register_callback_with(*d_, proc, "_NtCreateToken@52", &on_NtCreateToken))
            return false;

    d_->observers_NtCreateToken.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwCreateTransactionManager(proc_t proc, const on_ZwCreateTransactionManager_fn& on_func)
{
    if(d_->observers_ZwCreateTransactionManager.empty())
        if(!register_callback_with(*d_, proc, "_ZwCreateTransactionManager@24", &on_ZwCreateTransactionManager))
            return false;

    d_->observers_ZwCreateTransactionManager.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtCreateTransaction(proc_t proc, const on_NtCreateTransaction_fn& on_func)
{
    if(d_->observers_NtCreateTransaction.empty())
        if(!register_callback_with(*d_, proc, "_NtCreateTransaction@40", &on_NtCreateTransaction))
            return false;

    d_->observers_NtCreateTransaction.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtCreateUserProcess(proc_t proc, const on_NtCreateUserProcess_fn& on_func)
{
    if(d_->observers_NtCreateUserProcess.empty())
        if(!register_callback_with(*d_, proc, "_NtCreateUserProcess@44", &on_NtCreateUserProcess))
            return false;

    d_->observers_NtCreateUserProcess.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwCreateWaitablePort(proc_t proc, const on_ZwCreateWaitablePort_fn& on_func)
{
    if(d_->observers_ZwCreateWaitablePort.empty())
        if(!register_callback_with(*d_, proc, "_ZwCreateWaitablePort@20", &on_ZwCreateWaitablePort))
            return false;

    d_->observers_ZwCreateWaitablePort.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtCreateWorkerFactory(proc_t proc, const on_NtCreateWorkerFactory_fn& on_func)
{
    if(d_->observers_NtCreateWorkerFactory.empty())
        if(!register_callback_with(*d_, proc, "_NtCreateWorkerFactory@40", &on_NtCreateWorkerFactory))
            return false;

    d_->observers_NtCreateWorkerFactory.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtDebugActiveProcess(proc_t proc, const on_NtDebugActiveProcess_fn& on_func)
{
    if(d_->observers_NtDebugActiveProcess.empty())
        if(!register_callback_with(*d_, proc, "_NtDebugActiveProcess@8", &on_NtDebugActiveProcess))
            return false;

    d_->observers_NtDebugActiveProcess.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwDebugContinue(proc_t proc, const on_ZwDebugContinue_fn& on_func)
{
    if(d_->observers_ZwDebugContinue.empty())
        if(!register_callback_with(*d_, proc, "_ZwDebugContinue@12", &on_ZwDebugContinue))
            return false;

    d_->observers_ZwDebugContinue.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwDelayExecution(proc_t proc, const on_ZwDelayExecution_fn& on_func)
{
    if(d_->observers_ZwDelayExecution.empty())
        if(!register_callback_with(*d_, proc, "_ZwDelayExecution@8", &on_ZwDelayExecution))
            return false;

    d_->observers_ZwDelayExecution.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwDeleteAtom(proc_t proc, const on_ZwDeleteAtom_fn& on_func)
{
    if(d_->observers_ZwDeleteAtom.empty())
        if(!register_callback_with(*d_, proc, "_ZwDeleteAtom@4", &on_ZwDeleteAtom))
            return false;

    d_->observers_ZwDeleteAtom.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtDeleteBootEntry(proc_t proc, const on_NtDeleteBootEntry_fn& on_func)
{
    if(d_->observers_NtDeleteBootEntry.empty())
        if(!register_callback_with(*d_, proc, "_NtDeleteBootEntry@4", &on_NtDeleteBootEntry))
            return false;

    d_->observers_NtDeleteBootEntry.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwDeleteDriverEntry(proc_t proc, const on_ZwDeleteDriverEntry_fn& on_func)
{
    if(d_->observers_ZwDeleteDriverEntry.empty())
        if(!register_callback_with(*d_, proc, "_ZwDeleteDriverEntry@4", &on_ZwDeleteDriverEntry))
            return false;

    d_->observers_ZwDeleteDriverEntry.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtDeleteFile(proc_t proc, const on_NtDeleteFile_fn& on_func)
{
    if(d_->observers_NtDeleteFile.empty())
        if(!register_callback_with(*d_, proc, "_NtDeleteFile@4", &on_NtDeleteFile))
            return false;

    d_->observers_NtDeleteFile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwDeleteKey(proc_t proc, const on_ZwDeleteKey_fn& on_func)
{
    if(d_->observers_ZwDeleteKey.empty())
        if(!register_callback_with(*d_, proc, "_ZwDeleteKey@4", &on_ZwDeleteKey))
            return false;

    d_->observers_ZwDeleteKey.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtDeleteObjectAuditAlarm(proc_t proc, const on_NtDeleteObjectAuditAlarm_fn& on_func)
{
    if(d_->observers_NtDeleteObjectAuditAlarm.empty())
        if(!register_callback_with(*d_, proc, "_NtDeleteObjectAuditAlarm@12", &on_NtDeleteObjectAuditAlarm))
            return false;

    d_->observers_NtDeleteObjectAuditAlarm.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtDeletePrivateNamespace(proc_t proc, const on_NtDeletePrivateNamespace_fn& on_func)
{
    if(d_->observers_NtDeletePrivateNamespace.empty())
        if(!register_callback_with(*d_, proc, "_NtDeletePrivateNamespace@4", &on_NtDeletePrivateNamespace))
            return false;

    d_->observers_NtDeletePrivateNamespace.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtDeleteValueKey(proc_t proc, const on_NtDeleteValueKey_fn& on_func)
{
    if(d_->observers_NtDeleteValueKey.empty())
        if(!register_callback_with(*d_, proc, "_NtDeleteValueKey@8", &on_NtDeleteValueKey))
            return false;

    d_->observers_NtDeleteValueKey.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwDeviceIoControlFile(proc_t proc, const on_ZwDeviceIoControlFile_fn& on_func)
{
    if(d_->observers_ZwDeviceIoControlFile.empty())
        if(!register_callback_with(*d_, proc, "_ZwDeviceIoControlFile@40", &on_ZwDeviceIoControlFile))
            return false;

    d_->observers_ZwDeviceIoControlFile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtDisplayString(proc_t proc, const on_NtDisplayString_fn& on_func)
{
    if(d_->observers_NtDisplayString.empty())
        if(!register_callback_with(*d_, proc, "_NtDisplayString@4", &on_NtDisplayString))
            return false;

    d_->observers_NtDisplayString.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwDrawText(proc_t proc, const on_ZwDrawText_fn& on_func)
{
    if(d_->observers_ZwDrawText.empty())
        if(!register_callback_with(*d_, proc, "_ZwDrawText@4", &on_ZwDrawText))
            return false;

    d_->observers_ZwDrawText.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwDuplicateObject(proc_t proc, const on_ZwDuplicateObject_fn& on_func)
{
    if(d_->observers_ZwDuplicateObject.empty())
        if(!register_callback_with(*d_, proc, "_ZwDuplicateObject@28", &on_ZwDuplicateObject))
            return false;

    d_->observers_ZwDuplicateObject.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtDuplicateToken(proc_t proc, const on_NtDuplicateToken_fn& on_func)
{
    if(d_->observers_NtDuplicateToken.empty())
        if(!register_callback_with(*d_, proc, "_NtDuplicateToken@24", &on_NtDuplicateToken))
            return false;

    d_->observers_NtDuplicateToken.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwEnumerateBootEntries(proc_t proc, const on_ZwEnumerateBootEntries_fn& on_func)
{
    if(d_->observers_ZwEnumerateBootEntries.empty())
        if(!register_callback_with(*d_, proc, "_ZwEnumerateBootEntries@8", &on_ZwEnumerateBootEntries))
            return false;

    d_->observers_ZwEnumerateBootEntries.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtEnumerateDriverEntries(proc_t proc, const on_NtEnumerateDriverEntries_fn& on_func)
{
    if(d_->observers_NtEnumerateDriverEntries.empty())
        if(!register_callback_with(*d_, proc, "_NtEnumerateDriverEntries@8", &on_NtEnumerateDriverEntries))
            return false;

    d_->observers_NtEnumerateDriverEntries.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwEnumerateKey(proc_t proc, const on_ZwEnumerateKey_fn& on_func)
{
    if(d_->observers_ZwEnumerateKey.empty())
        if(!register_callback_with(*d_, proc, "_ZwEnumerateKey@24", &on_ZwEnumerateKey))
            return false;

    d_->observers_ZwEnumerateKey.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwEnumerateSystemEnvironmentValuesEx(proc_t proc, const on_ZwEnumerateSystemEnvironmentValuesEx_fn& on_func)
{
    if(d_->observers_ZwEnumerateSystemEnvironmentValuesEx.empty())
        if(!register_callback_with(*d_, proc, "_ZwEnumerateSystemEnvironmentValuesEx@12", &on_ZwEnumerateSystemEnvironmentValuesEx))
            return false;

    d_->observers_ZwEnumerateSystemEnvironmentValuesEx.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwEnumerateTransactionObject(proc_t proc, const on_ZwEnumerateTransactionObject_fn& on_func)
{
    if(d_->observers_ZwEnumerateTransactionObject.empty())
        if(!register_callback_with(*d_, proc, "_ZwEnumerateTransactionObject@20", &on_ZwEnumerateTransactionObject))
            return false;

    d_->observers_ZwEnumerateTransactionObject.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtEnumerateValueKey(proc_t proc, const on_NtEnumerateValueKey_fn& on_func)
{
    if(d_->observers_NtEnumerateValueKey.empty())
        if(!register_callback_with(*d_, proc, "_NtEnumerateValueKey@24", &on_NtEnumerateValueKey))
            return false;

    d_->observers_NtEnumerateValueKey.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwExtendSection(proc_t proc, const on_ZwExtendSection_fn& on_func)
{
    if(d_->observers_ZwExtendSection.empty())
        if(!register_callback_with(*d_, proc, "_ZwExtendSection@8", &on_ZwExtendSection))
            return false;

    d_->observers_ZwExtendSection.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtFilterToken(proc_t proc, const on_NtFilterToken_fn& on_func)
{
    if(d_->observers_NtFilterToken.empty())
        if(!register_callback_with(*d_, proc, "_NtFilterToken@24", &on_NtFilterToken))
            return false;

    d_->observers_NtFilterToken.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtFindAtom(proc_t proc, const on_NtFindAtom_fn& on_func)
{
    if(d_->observers_NtFindAtom.empty())
        if(!register_callback_with(*d_, proc, "_NtFindAtom@12", &on_NtFindAtom))
            return false;

    d_->observers_NtFindAtom.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwFlushBuffersFile(proc_t proc, const on_ZwFlushBuffersFile_fn& on_func)
{
    if(d_->observers_ZwFlushBuffersFile.empty())
        if(!register_callback_with(*d_, proc, "_ZwFlushBuffersFile@8", &on_ZwFlushBuffersFile))
            return false;

    d_->observers_ZwFlushBuffersFile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwFlushInstallUILanguage(proc_t proc, const on_ZwFlushInstallUILanguage_fn& on_func)
{
    if(d_->observers_ZwFlushInstallUILanguage.empty())
        if(!register_callback_with(*d_, proc, "_ZwFlushInstallUILanguage@8", &on_ZwFlushInstallUILanguage))
            return false;

    d_->observers_ZwFlushInstallUILanguage.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwFlushInstructionCache(proc_t proc, const on_ZwFlushInstructionCache_fn& on_func)
{
    if(d_->observers_ZwFlushInstructionCache.empty())
        if(!register_callback_with(*d_, proc, "_ZwFlushInstructionCache@12", &on_ZwFlushInstructionCache))
            return false;

    d_->observers_ZwFlushInstructionCache.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtFlushKey(proc_t proc, const on_NtFlushKey_fn& on_func)
{
    if(d_->observers_NtFlushKey.empty())
        if(!register_callback_with(*d_, proc, "_NtFlushKey@4", &on_NtFlushKey))
            return false;

    d_->observers_NtFlushKey.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwFlushVirtualMemory(proc_t proc, const on_ZwFlushVirtualMemory_fn& on_func)
{
    if(d_->observers_ZwFlushVirtualMemory.empty())
        if(!register_callback_with(*d_, proc, "_ZwFlushVirtualMemory@16", &on_ZwFlushVirtualMemory))
            return false;

    d_->observers_ZwFlushVirtualMemory.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtFreeUserPhysicalPages(proc_t proc, const on_NtFreeUserPhysicalPages_fn& on_func)
{
    if(d_->observers_NtFreeUserPhysicalPages.empty())
        if(!register_callback_with(*d_, proc, "_NtFreeUserPhysicalPages@12", &on_NtFreeUserPhysicalPages))
            return false;

    d_->observers_NtFreeUserPhysicalPages.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtFreeVirtualMemory(proc_t proc, const on_NtFreeVirtualMemory_fn& on_func)
{
    if(d_->observers_NtFreeVirtualMemory.empty())
        if(!register_callback_with(*d_, proc, "_NtFreeVirtualMemory@16", &on_NtFreeVirtualMemory))
            return false;

    d_->observers_NtFreeVirtualMemory.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtFreezeRegistry(proc_t proc, const on_NtFreezeRegistry_fn& on_func)
{
    if(d_->observers_NtFreezeRegistry.empty())
        if(!register_callback_with(*d_, proc, "_NtFreezeRegistry@4", &on_NtFreezeRegistry))
            return false;

    d_->observers_NtFreezeRegistry.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwFreezeTransactions(proc_t proc, const on_ZwFreezeTransactions_fn& on_func)
{
    if(d_->observers_ZwFreezeTransactions.empty())
        if(!register_callback_with(*d_, proc, "_ZwFreezeTransactions@8", &on_ZwFreezeTransactions))
            return false;

    d_->observers_ZwFreezeTransactions.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtFsControlFile(proc_t proc, const on_NtFsControlFile_fn& on_func)
{
    if(d_->observers_NtFsControlFile.empty())
        if(!register_callback_with(*d_, proc, "_NtFsControlFile@40", &on_NtFsControlFile))
            return false;

    d_->observers_NtFsControlFile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtGetContextThread(proc_t proc, const on_NtGetContextThread_fn& on_func)
{
    if(d_->observers_NtGetContextThread.empty())
        if(!register_callback_with(*d_, proc, "_NtGetContextThread@8", &on_NtGetContextThread))
            return false;

    d_->observers_NtGetContextThread.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtGetDevicePowerState(proc_t proc, const on_NtGetDevicePowerState_fn& on_func)
{
    if(d_->observers_NtGetDevicePowerState.empty())
        if(!register_callback_with(*d_, proc, "_NtGetDevicePowerState@8", &on_NtGetDevicePowerState))
            return false;

    d_->observers_NtGetDevicePowerState.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtGetMUIRegistryInfo(proc_t proc, const on_NtGetMUIRegistryInfo_fn& on_func)
{
    if(d_->observers_NtGetMUIRegistryInfo.empty())
        if(!register_callback_with(*d_, proc, "_NtGetMUIRegistryInfo@12", &on_NtGetMUIRegistryInfo))
            return false;

    d_->observers_NtGetMUIRegistryInfo.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwGetNextProcess(proc_t proc, const on_ZwGetNextProcess_fn& on_func)
{
    if(d_->observers_ZwGetNextProcess.empty())
        if(!register_callback_with(*d_, proc, "_ZwGetNextProcess@20", &on_ZwGetNextProcess))
            return false;

    d_->observers_ZwGetNextProcess.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwGetNextThread(proc_t proc, const on_ZwGetNextThread_fn& on_func)
{
    if(d_->observers_ZwGetNextThread.empty())
        if(!register_callback_with(*d_, proc, "_ZwGetNextThread@24", &on_ZwGetNextThread))
            return false;

    d_->observers_ZwGetNextThread.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtGetNlsSectionPtr(proc_t proc, const on_NtGetNlsSectionPtr_fn& on_func)
{
    if(d_->observers_NtGetNlsSectionPtr.empty())
        if(!register_callback_with(*d_, proc, "_NtGetNlsSectionPtr@20", &on_NtGetNlsSectionPtr))
            return false;

    d_->observers_NtGetNlsSectionPtr.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwGetNotificationResourceManager(proc_t proc, const on_ZwGetNotificationResourceManager_fn& on_func)
{
    if(d_->observers_ZwGetNotificationResourceManager.empty())
        if(!register_callback_with(*d_, proc, "_ZwGetNotificationResourceManager@28", &on_ZwGetNotificationResourceManager))
            return false;

    d_->observers_ZwGetNotificationResourceManager.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtGetWriteWatch(proc_t proc, const on_NtGetWriteWatch_fn& on_func)
{
    if(d_->observers_NtGetWriteWatch.empty())
        if(!register_callback_with(*d_, proc, "_NtGetWriteWatch@28", &on_NtGetWriteWatch))
            return false;

    d_->observers_NtGetWriteWatch.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtImpersonateAnonymousToken(proc_t proc, const on_NtImpersonateAnonymousToken_fn& on_func)
{
    if(d_->observers_NtImpersonateAnonymousToken.empty())
        if(!register_callback_with(*d_, proc, "_NtImpersonateAnonymousToken@4", &on_NtImpersonateAnonymousToken))
            return false;

    d_->observers_NtImpersonateAnonymousToken.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwImpersonateClientOfPort(proc_t proc, const on_ZwImpersonateClientOfPort_fn& on_func)
{
    if(d_->observers_ZwImpersonateClientOfPort.empty())
        if(!register_callback_with(*d_, proc, "_ZwImpersonateClientOfPort@8", &on_ZwImpersonateClientOfPort))
            return false;

    d_->observers_ZwImpersonateClientOfPort.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwImpersonateThread(proc_t proc, const on_ZwImpersonateThread_fn& on_func)
{
    if(d_->observers_ZwImpersonateThread.empty())
        if(!register_callback_with(*d_, proc, "_ZwImpersonateThread@12", &on_ZwImpersonateThread))
            return false;

    d_->observers_ZwImpersonateThread.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtInitializeNlsFiles(proc_t proc, const on_NtInitializeNlsFiles_fn& on_func)
{
    if(d_->observers_NtInitializeNlsFiles.empty())
        if(!register_callback_with(*d_, proc, "_NtInitializeNlsFiles@12", &on_NtInitializeNlsFiles))
            return false;

    d_->observers_NtInitializeNlsFiles.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwInitializeRegistry(proc_t proc, const on_ZwInitializeRegistry_fn& on_func)
{
    if(d_->observers_ZwInitializeRegistry.empty())
        if(!register_callback_with(*d_, proc, "_ZwInitializeRegistry@4", &on_ZwInitializeRegistry))
            return false;

    d_->observers_ZwInitializeRegistry.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtInitiatePowerAction(proc_t proc, const on_NtInitiatePowerAction_fn& on_func)
{
    if(d_->observers_NtInitiatePowerAction.empty())
        if(!register_callback_with(*d_, proc, "_NtInitiatePowerAction@16", &on_NtInitiatePowerAction))
            return false;

    d_->observers_NtInitiatePowerAction.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwIsProcessInJob(proc_t proc, const on_ZwIsProcessInJob_fn& on_func)
{
    if(d_->observers_ZwIsProcessInJob.empty())
        if(!register_callback_with(*d_, proc, "_ZwIsProcessInJob@8", &on_ZwIsProcessInJob))
            return false;

    d_->observers_ZwIsProcessInJob.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwListenPort(proc_t proc, const on_ZwListenPort_fn& on_func)
{
    if(d_->observers_ZwListenPort.empty())
        if(!register_callback_with(*d_, proc, "_ZwListenPort@8", &on_ZwListenPort))
            return false;

    d_->observers_ZwListenPort.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtLoadDriver(proc_t proc, const on_NtLoadDriver_fn& on_func)
{
    if(d_->observers_NtLoadDriver.empty())
        if(!register_callback_with(*d_, proc, "_NtLoadDriver@4", &on_NtLoadDriver))
            return false;

    d_->observers_NtLoadDriver.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtLoadKey2(proc_t proc, const on_NtLoadKey2_fn& on_func)
{
    if(d_->observers_NtLoadKey2.empty())
        if(!register_callback_with(*d_, proc, "_NtLoadKey2@12", &on_NtLoadKey2))
            return false;

    d_->observers_NtLoadKey2.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtLoadKeyEx(proc_t proc, const on_NtLoadKeyEx_fn& on_func)
{
    if(d_->observers_NtLoadKeyEx.empty())
        if(!register_callback_with(*d_, proc, "_NtLoadKeyEx@32", &on_NtLoadKeyEx))
            return false;

    d_->observers_NtLoadKeyEx.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtLoadKey(proc_t proc, const on_NtLoadKey_fn& on_func)
{
    if(d_->observers_NtLoadKey.empty())
        if(!register_callback_with(*d_, proc, "_NtLoadKey@8", &on_NtLoadKey))
            return false;

    d_->observers_NtLoadKey.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtLockFile(proc_t proc, const on_NtLockFile_fn& on_func)
{
    if(d_->observers_NtLockFile.empty())
        if(!register_callback_with(*d_, proc, "_NtLockFile@40", &on_NtLockFile))
            return false;

    d_->observers_NtLockFile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwLockProductActivationKeys(proc_t proc, const on_ZwLockProductActivationKeys_fn& on_func)
{
    if(d_->observers_ZwLockProductActivationKeys.empty())
        if(!register_callback_with(*d_, proc, "_ZwLockProductActivationKeys@8", &on_ZwLockProductActivationKeys))
            return false;

    d_->observers_ZwLockProductActivationKeys.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtLockRegistryKey(proc_t proc, const on_NtLockRegistryKey_fn& on_func)
{
    if(d_->observers_NtLockRegistryKey.empty())
        if(!register_callback_with(*d_, proc, "_NtLockRegistryKey@4", &on_NtLockRegistryKey))
            return false;

    d_->observers_NtLockRegistryKey.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwLockVirtualMemory(proc_t proc, const on_ZwLockVirtualMemory_fn& on_func)
{
    if(d_->observers_ZwLockVirtualMemory.empty())
        if(!register_callback_with(*d_, proc, "_ZwLockVirtualMemory@16", &on_ZwLockVirtualMemory))
            return false;

    d_->observers_ZwLockVirtualMemory.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwMakePermanentObject(proc_t proc, const on_ZwMakePermanentObject_fn& on_func)
{
    if(d_->observers_ZwMakePermanentObject.empty())
        if(!register_callback_with(*d_, proc, "_ZwMakePermanentObject@4", &on_ZwMakePermanentObject))
            return false;

    d_->observers_ZwMakePermanentObject.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtMakeTemporaryObject(proc_t proc, const on_NtMakeTemporaryObject_fn& on_func)
{
    if(d_->observers_NtMakeTemporaryObject.empty())
        if(!register_callback_with(*d_, proc, "_NtMakeTemporaryObject@4", &on_NtMakeTemporaryObject))
            return false;

    d_->observers_NtMakeTemporaryObject.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwMapCMFModule(proc_t proc, const on_ZwMapCMFModule_fn& on_func)
{
    if(d_->observers_ZwMapCMFModule.empty())
        if(!register_callback_with(*d_, proc, "_ZwMapCMFModule@24", &on_ZwMapCMFModule))
            return false;

    d_->observers_ZwMapCMFModule.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtMapUserPhysicalPages(proc_t proc, const on_NtMapUserPhysicalPages_fn& on_func)
{
    if(d_->observers_NtMapUserPhysicalPages.empty())
        if(!register_callback_with(*d_, proc, "_NtMapUserPhysicalPages@12", &on_NtMapUserPhysicalPages))
            return false;

    d_->observers_NtMapUserPhysicalPages.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwMapUserPhysicalPagesScatter(proc_t proc, const on_ZwMapUserPhysicalPagesScatter_fn& on_func)
{
    if(d_->observers_ZwMapUserPhysicalPagesScatter.empty())
        if(!register_callback_with(*d_, proc, "_ZwMapUserPhysicalPagesScatter@12", &on_ZwMapUserPhysicalPagesScatter))
            return false;

    d_->observers_ZwMapUserPhysicalPagesScatter.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwMapViewOfSection(proc_t proc, const on_ZwMapViewOfSection_fn& on_func)
{
    if(d_->observers_ZwMapViewOfSection.empty())
        if(!register_callback_with(*d_, proc, "_ZwMapViewOfSection@40", &on_ZwMapViewOfSection))
            return false;

    d_->observers_ZwMapViewOfSection.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtModifyBootEntry(proc_t proc, const on_NtModifyBootEntry_fn& on_func)
{
    if(d_->observers_NtModifyBootEntry.empty())
        if(!register_callback_with(*d_, proc, "_NtModifyBootEntry@4", &on_NtModifyBootEntry))
            return false;

    d_->observers_NtModifyBootEntry.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwModifyDriverEntry(proc_t proc, const on_ZwModifyDriverEntry_fn& on_func)
{
    if(d_->observers_ZwModifyDriverEntry.empty())
        if(!register_callback_with(*d_, proc, "_ZwModifyDriverEntry@4", &on_ZwModifyDriverEntry))
            return false;

    d_->observers_ZwModifyDriverEntry.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtNotifyChangeDirectoryFile(proc_t proc, const on_NtNotifyChangeDirectoryFile_fn& on_func)
{
    if(d_->observers_NtNotifyChangeDirectoryFile.empty())
        if(!register_callback_with(*d_, proc, "_NtNotifyChangeDirectoryFile@36", &on_NtNotifyChangeDirectoryFile))
            return false;

    d_->observers_NtNotifyChangeDirectoryFile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtNotifyChangeKey(proc_t proc, const on_NtNotifyChangeKey_fn& on_func)
{
    if(d_->observers_NtNotifyChangeKey.empty())
        if(!register_callback_with(*d_, proc, "_NtNotifyChangeKey@40", &on_NtNotifyChangeKey))
            return false;

    d_->observers_NtNotifyChangeKey.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtNotifyChangeMultipleKeys(proc_t proc, const on_NtNotifyChangeMultipleKeys_fn& on_func)
{
    if(d_->observers_NtNotifyChangeMultipleKeys.empty())
        if(!register_callback_with(*d_, proc, "_NtNotifyChangeMultipleKeys@48", &on_NtNotifyChangeMultipleKeys))
            return false;

    d_->observers_NtNotifyChangeMultipleKeys.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtNotifyChangeSession(proc_t proc, const on_NtNotifyChangeSession_fn& on_func)
{
    if(d_->observers_NtNotifyChangeSession.empty())
        if(!register_callback_with(*d_, proc, "_NtNotifyChangeSession@32", &on_NtNotifyChangeSession))
            return false;

    d_->observers_NtNotifyChangeSession.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwOpenDirectoryObject(proc_t proc, const on_ZwOpenDirectoryObject_fn& on_func)
{
    if(d_->observers_ZwOpenDirectoryObject.empty())
        if(!register_callback_with(*d_, proc, "_ZwOpenDirectoryObject@12", &on_ZwOpenDirectoryObject))
            return false;

    d_->observers_ZwOpenDirectoryObject.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwOpenEnlistment(proc_t proc, const on_ZwOpenEnlistment_fn& on_func)
{
    if(d_->observers_ZwOpenEnlistment.empty())
        if(!register_callback_with(*d_, proc, "_ZwOpenEnlistment@20", &on_ZwOpenEnlistment))
            return false;

    d_->observers_ZwOpenEnlistment.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtOpenEvent(proc_t proc, const on_NtOpenEvent_fn& on_func)
{
    if(d_->observers_NtOpenEvent.empty())
        if(!register_callback_with(*d_, proc, "_NtOpenEvent@12", &on_NtOpenEvent))
            return false;

    d_->observers_NtOpenEvent.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtOpenEventPair(proc_t proc, const on_NtOpenEventPair_fn& on_func)
{
    if(d_->observers_NtOpenEventPair.empty())
        if(!register_callback_with(*d_, proc, "_NtOpenEventPair@12", &on_NtOpenEventPair))
            return false;

    d_->observers_NtOpenEventPair.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtOpenFile(proc_t proc, const on_NtOpenFile_fn& on_func)
{
    if(d_->observers_NtOpenFile.empty())
        if(!register_callback_with(*d_, proc, "_NtOpenFile@24", &on_NtOpenFile))
            return false;

    d_->observers_NtOpenFile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwOpenIoCompletion(proc_t proc, const on_ZwOpenIoCompletion_fn& on_func)
{
    if(d_->observers_ZwOpenIoCompletion.empty())
        if(!register_callback_with(*d_, proc, "_ZwOpenIoCompletion@12", &on_ZwOpenIoCompletion))
            return false;

    d_->observers_ZwOpenIoCompletion.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwOpenJobObject(proc_t proc, const on_ZwOpenJobObject_fn& on_func)
{
    if(d_->observers_ZwOpenJobObject.empty())
        if(!register_callback_with(*d_, proc, "_ZwOpenJobObject@12", &on_ZwOpenJobObject))
            return false;

    d_->observers_ZwOpenJobObject.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtOpenKeyedEvent(proc_t proc, const on_NtOpenKeyedEvent_fn& on_func)
{
    if(d_->observers_NtOpenKeyedEvent.empty())
        if(!register_callback_with(*d_, proc, "_NtOpenKeyedEvent@12", &on_NtOpenKeyedEvent))
            return false;

    d_->observers_NtOpenKeyedEvent.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwOpenKeyEx(proc_t proc, const on_ZwOpenKeyEx_fn& on_func)
{
    if(d_->observers_ZwOpenKeyEx.empty())
        if(!register_callback_with(*d_, proc, "_ZwOpenKeyEx@16", &on_ZwOpenKeyEx))
            return false;

    d_->observers_ZwOpenKeyEx.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwOpenKey(proc_t proc, const on_ZwOpenKey_fn& on_func)
{
    if(d_->observers_ZwOpenKey.empty())
        if(!register_callback_with(*d_, proc, "_ZwOpenKey@12", &on_ZwOpenKey))
            return false;

    d_->observers_ZwOpenKey.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtOpenKeyTransactedEx(proc_t proc, const on_NtOpenKeyTransactedEx_fn& on_func)
{
    if(d_->observers_NtOpenKeyTransactedEx.empty())
        if(!register_callback_with(*d_, proc, "_NtOpenKeyTransactedEx@20", &on_NtOpenKeyTransactedEx))
            return false;

    d_->observers_NtOpenKeyTransactedEx.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtOpenKeyTransacted(proc_t proc, const on_NtOpenKeyTransacted_fn& on_func)
{
    if(d_->observers_NtOpenKeyTransacted.empty())
        if(!register_callback_with(*d_, proc, "_NtOpenKeyTransacted@16", &on_NtOpenKeyTransacted))
            return false;

    d_->observers_NtOpenKeyTransacted.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtOpenMutant(proc_t proc, const on_NtOpenMutant_fn& on_func)
{
    if(d_->observers_NtOpenMutant.empty())
        if(!register_callback_with(*d_, proc, "_NtOpenMutant@12", &on_NtOpenMutant))
            return false;

    d_->observers_NtOpenMutant.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwOpenObjectAuditAlarm(proc_t proc, const on_ZwOpenObjectAuditAlarm_fn& on_func)
{
    if(d_->observers_ZwOpenObjectAuditAlarm.empty())
        if(!register_callback_with(*d_, proc, "_ZwOpenObjectAuditAlarm@48", &on_ZwOpenObjectAuditAlarm))
            return false;

    d_->observers_ZwOpenObjectAuditAlarm.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtOpenPrivateNamespace(proc_t proc, const on_NtOpenPrivateNamespace_fn& on_func)
{
    if(d_->observers_NtOpenPrivateNamespace.empty())
        if(!register_callback_with(*d_, proc, "_NtOpenPrivateNamespace@16", &on_NtOpenPrivateNamespace))
            return false;

    d_->observers_NtOpenPrivateNamespace.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwOpenProcess(proc_t proc, const on_ZwOpenProcess_fn& on_func)
{
    if(d_->observers_ZwOpenProcess.empty())
        if(!register_callback_with(*d_, proc, "_ZwOpenProcess@16", &on_ZwOpenProcess))
            return false;

    d_->observers_ZwOpenProcess.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwOpenProcessTokenEx(proc_t proc, const on_ZwOpenProcessTokenEx_fn& on_func)
{
    if(d_->observers_ZwOpenProcessTokenEx.empty())
        if(!register_callback_with(*d_, proc, "_ZwOpenProcessTokenEx@16", &on_ZwOpenProcessTokenEx))
            return false;

    d_->observers_ZwOpenProcessTokenEx.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwOpenProcessToken(proc_t proc, const on_ZwOpenProcessToken_fn& on_func)
{
    if(d_->observers_ZwOpenProcessToken.empty())
        if(!register_callback_with(*d_, proc, "_ZwOpenProcessToken@12", &on_ZwOpenProcessToken))
            return false;

    d_->observers_ZwOpenProcessToken.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwOpenResourceManager(proc_t proc, const on_ZwOpenResourceManager_fn& on_func)
{
    if(d_->observers_ZwOpenResourceManager.empty())
        if(!register_callback_with(*d_, proc, "_ZwOpenResourceManager@20", &on_ZwOpenResourceManager))
            return false;

    d_->observers_ZwOpenResourceManager.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtOpenSection(proc_t proc, const on_NtOpenSection_fn& on_func)
{
    if(d_->observers_NtOpenSection.empty())
        if(!register_callback_with(*d_, proc, "_NtOpenSection@12", &on_NtOpenSection))
            return false;

    d_->observers_NtOpenSection.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtOpenSemaphore(proc_t proc, const on_NtOpenSemaphore_fn& on_func)
{
    if(d_->observers_NtOpenSemaphore.empty())
        if(!register_callback_with(*d_, proc, "_NtOpenSemaphore@12", &on_NtOpenSemaphore))
            return false;

    d_->observers_NtOpenSemaphore.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtOpenSession(proc_t proc, const on_NtOpenSession_fn& on_func)
{
    if(d_->observers_NtOpenSession.empty())
        if(!register_callback_with(*d_, proc, "_NtOpenSession@12", &on_NtOpenSession))
            return false;

    d_->observers_NtOpenSession.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtOpenSymbolicLinkObject(proc_t proc, const on_NtOpenSymbolicLinkObject_fn& on_func)
{
    if(d_->observers_NtOpenSymbolicLinkObject.empty())
        if(!register_callback_with(*d_, proc, "_NtOpenSymbolicLinkObject@12", &on_NtOpenSymbolicLinkObject))
            return false;

    d_->observers_NtOpenSymbolicLinkObject.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwOpenThread(proc_t proc, const on_ZwOpenThread_fn& on_func)
{
    if(d_->observers_ZwOpenThread.empty())
        if(!register_callback_with(*d_, proc, "_ZwOpenThread@16", &on_ZwOpenThread))
            return false;

    d_->observers_ZwOpenThread.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtOpenThreadTokenEx(proc_t proc, const on_NtOpenThreadTokenEx_fn& on_func)
{
    if(d_->observers_NtOpenThreadTokenEx.empty())
        if(!register_callback_with(*d_, proc, "_NtOpenThreadTokenEx@20", &on_NtOpenThreadTokenEx))
            return false;

    d_->observers_NtOpenThreadTokenEx.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtOpenThreadToken(proc_t proc, const on_NtOpenThreadToken_fn& on_func)
{
    if(d_->observers_NtOpenThreadToken.empty())
        if(!register_callback_with(*d_, proc, "_NtOpenThreadToken@16", &on_NtOpenThreadToken))
            return false;

    d_->observers_NtOpenThreadToken.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwOpenTimer(proc_t proc, const on_ZwOpenTimer_fn& on_func)
{
    if(d_->observers_ZwOpenTimer.empty())
        if(!register_callback_with(*d_, proc, "_ZwOpenTimer@12", &on_ZwOpenTimer))
            return false;

    d_->observers_ZwOpenTimer.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwOpenTransactionManager(proc_t proc, const on_ZwOpenTransactionManager_fn& on_func)
{
    if(d_->observers_ZwOpenTransactionManager.empty())
        if(!register_callback_with(*d_, proc, "_ZwOpenTransactionManager@24", &on_ZwOpenTransactionManager))
            return false;

    d_->observers_ZwOpenTransactionManager.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwOpenTransaction(proc_t proc, const on_ZwOpenTransaction_fn& on_func)
{
    if(d_->observers_ZwOpenTransaction.empty())
        if(!register_callback_with(*d_, proc, "_ZwOpenTransaction@20", &on_ZwOpenTransaction))
            return false;

    d_->observers_ZwOpenTransaction.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtPlugPlayControl(proc_t proc, const on_NtPlugPlayControl_fn& on_func)
{
    if(d_->observers_NtPlugPlayControl.empty())
        if(!register_callback_with(*d_, proc, "_NtPlugPlayControl@12", &on_NtPlugPlayControl))
            return false;

    d_->observers_NtPlugPlayControl.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwPowerInformation(proc_t proc, const on_ZwPowerInformation_fn& on_func)
{
    if(d_->observers_ZwPowerInformation.empty())
        if(!register_callback_with(*d_, proc, "_ZwPowerInformation@20", &on_ZwPowerInformation))
            return false;

    d_->observers_ZwPowerInformation.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtPrepareComplete(proc_t proc, const on_NtPrepareComplete_fn& on_func)
{
    if(d_->observers_NtPrepareComplete.empty())
        if(!register_callback_with(*d_, proc, "_NtPrepareComplete@8", &on_NtPrepareComplete))
            return false;

    d_->observers_NtPrepareComplete.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwPrepareEnlistment(proc_t proc, const on_ZwPrepareEnlistment_fn& on_func)
{
    if(d_->observers_ZwPrepareEnlistment.empty())
        if(!register_callback_with(*d_, proc, "_ZwPrepareEnlistment@8", &on_ZwPrepareEnlistment))
            return false;

    d_->observers_ZwPrepareEnlistment.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwPrePrepareComplete(proc_t proc, const on_ZwPrePrepareComplete_fn& on_func)
{
    if(d_->observers_ZwPrePrepareComplete.empty())
        if(!register_callback_with(*d_, proc, "_ZwPrePrepareComplete@8", &on_ZwPrePrepareComplete))
            return false;

    d_->observers_ZwPrePrepareComplete.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtPrePrepareEnlistment(proc_t proc, const on_NtPrePrepareEnlistment_fn& on_func)
{
    if(d_->observers_NtPrePrepareEnlistment.empty())
        if(!register_callback_with(*d_, proc, "_NtPrePrepareEnlistment@8", &on_NtPrePrepareEnlistment))
            return false;

    d_->observers_NtPrePrepareEnlistment.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwPrivilegeCheck(proc_t proc, const on_ZwPrivilegeCheck_fn& on_func)
{
    if(d_->observers_ZwPrivilegeCheck.empty())
        if(!register_callback_with(*d_, proc, "_ZwPrivilegeCheck@12", &on_ZwPrivilegeCheck))
            return false;

    d_->observers_ZwPrivilegeCheck.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtPrivilegedServiceAuditAlarm(proc_t proc, const on_NtPrivilegedServiceAuditAlarm_fn& on_func)
{
    if(d_->observers_NtPrivilegedServiceAuditAlarm.empty())
        if(!register_callback_with(*d_, proc, "_NtPrivilegedServiceAuditAlarm@20", &on_NtPrivilegedServiceAuditAlarm))
            return false;

    d_->observers_NtPrivilegedServiceAuditAlarm.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwPrivilegeObjectAuditAlarm(proc_t proc, const on_ZwPrivilegeObjectAuditAlarm_fn& on_func)
{
    if(d_->observers_ZwPrivilegeObjectAuditAlarm.empty())
        if(!register_callback_with(*d_, proc, "_ZwPrivilegeObjectAuditAlarm@24", &on_ZwPrivilegeObjectAuditAlarm))
            return false;

    d_->observers_ZwPrivilegeObjectAuditAlarm.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtPropagationComplete(proc_t proc, const on_NtPropagationComplete_fn& on_func)
{
    if(d_->observers_NtPropagationComplete.empty())
        if(!register_callback_with(*d_, proc, "_NtPropagationComplete@16", &on_NtPropagationComplete))
            return false;

    d_->observers_NtPropagationComplete.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwPropagationFailed(proc_t proc, const on_ZwPropagationFailed_fn& on_func)
{
    if(d_->observers_ZwPropagationFailed.empty())
        if(!register_callback_with(*d_, proc, "_ZwPropagationFailed@12", &on_ZwPropagationFailed))
            return false;

    d_->observers_ZwPropagationFailed.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwProtectVirtualMemory(proc_t proc, const on_ZwProtectVirtualMemory_fn& on_func)
{
    if(d_->observers_ZwProtectVirtualMemory.empty())
        if(!register_callback_with(*d_, proc, "_ZwProtectVirtualMemory@20", &on_ZwProtectVirtualMemory))
            return false;

    d_->observers_ZwProtectVirtualMemory.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwPulseEvent(proc_t proc, const on_ZwPulseEvent_fn& on_func)
{
    if(d_->observers_ZwPulseEvent.empty())
        if(!register_callback_with(*d_, proc, "_ZwPulseEvent@8", &on_ZwPulseEvent))
            return false;

    d_->observers_ZwPulseEvent.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQueryAttributesFile(proc_t proc, const on_ZwQueryAttributesFile_fn& on_func)
{
    if(d_->observers_ZwQueryAttributesFile.empty())
        if(!register_callback_with(*d_, proc, "_ZwQueryAttributesFile@8", &on_ZwQueryAttributesFile))
            return false;

    d_->observers_ZwQueryAttributesFile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQueryBootEntryOrder(proc_t proc, const on_ZwQueryBootEntryOrder_fn& on_func)
{
    if(d_->observers_ZwQueryBootEntryOrder.empty())
        if(!register_callback_with(*d_, proc, "_ZwQueryBootEntryOrder@8", &on_ZwQueryBootEntryOrder))
            return false;

    d_->observers_ZwQueryBootEntryOrder.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQueryBootOptions(proc_t proc, const on_ZwQueryBootOptions_fn& on_func)
{
    if(d_->observers_ZwQueryBootOptions.empty())
        if(!register_callback_with(*d_, proc, "_ZwQueryBootOptions@8", &on_ZwQueryBootOptions))
            return false;

    d_->observers_ZwQueryBootOptions.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtQueryDebugFilterState(proc_t proc, const on_NtQueryDebugFilterState_fn& on_func)
{
    if(d_->observers_NtQueryDebugFilterState.empty())
        if(!register_callback_with(*d_, proc, "_NtQueryDebugFilterState@8", &on_NtQueryDebugFilterState))
            return false;

    d_->observers_NtQueryDebugFilterState.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtQueryDefaultLocale(proc_t proc, const on_NtQueryDefaultLocale_fn& on_func)
{
    if(d_->observers_NtQueryDefaultLocale.empty())
        if(!register_callback_with(*d_, proc, "_NtQueryDefaultLocale@8", &on_NtQueryDefaultLocale))
            return false;

    d_->observers_NtQueryDefaultLocale.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQueryDefaultUILanguage(proc_t proc, const on_ZwQueryDefaultUILanguage_fn& on_func)
{
    if(d_->observers_ZwQueryDefaultUILanguage.empty())
        if(!register_callback_with(*d_, proc, "_ZwQueryDefaultUILanguage@4", &on_ZwQueryDefaultUILanguage))
            return false;

    d_->observers_ZwQueryDefaultUILanguage.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQueryDirectoryFile(proc_t proc, const on_ZwQueryDirectoryFile_fn& on_func)
{
    if(d_->observers_ZwQueryDirectoryFile.empty())
        if(!register_callback_with(*d_, proc, "_ZwQueryDirectoryFile@44", &on_ZwQueryDirectoryFile))
            return false;

    d_->observers_ZwQueryDirectoryFile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQueryDirectoryObject(proc_t proc, const on_ZwQueryDirectoryObject_fn& on_func)
{
    if(d_->observers_ZwQueryDirectoryObject.empty())
        if(!register_callback_with(*d_, proc, "_ZwQueryDirectoryObject@28", &on_ZwQueryDirectoryObject))
            return false;

    d_->observers_ZwQueryDirectoryObject.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtQueryDriverEntryOrder(proc_t proc, const on_NtQueryDriverEntryOrder_fn& on_func)
{
    if(d_->observers_NtQueryDriverEntryOrder.empty())
        if(!register_callback_with(*d_, proc, "_NtQueryDriverEntryOrder@8", &on_NtQueryDriverEntryOrder))
            return false;

    d_->observers_NtQueryDriverEntryOrder.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQueryEaFile(proc_t proc, const on_ZwQueryEaFile_fn& on_func)
{
    if(d_->observers_ZwQueryEaFile.empty())
        if(!register_callback_with(*d_, proc, "_ZwQueryEaFile@36", &on_ZwQueryEaFile))
            return false;

    d_->observers_ZwQueryEaFile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtQueryEvent(proc_t proc, const on_NtQueryEvent_fn& on_func)
{
    if(d_->observers_NtQueryEvent.empty())
        if(!register_callback_with(*d_, proc, "_NtQueryEvent@20", &on_NtQueryEvent))
            return false;

    d_->observers_NtQueryEvent.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQueryFullAttributesFile(proc_t proc, const on_ZwQueryFullAttributesFile_fn& on_func)
{
    if(d_->observers_ZwQueryFullAttributesFile.empty())
        if(!register_callback_with(*d_, proc, "_ZwQueryFullAttributesFile@8", &on_ZwQueryFullAttributesFile))
            return false;

    d_->observers_ZwQueryFullAttributesFile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtQueryInformationAtom(proc_t proc, const on_NtQueryInformationAtom_fn& on_func)
{
    if(d_->observers_NtQueryInformationAtom.empty())
        if(!register_callback_with(*d_, proc, "_NtQueryInformationAtom@20", &on_NtQueryInformationAtom))
            return false;

    d_->observers_NtQueryInformationAtom.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQueryInformationEnlistment(proc_t proc, const on_ZwQueryInformationEnlistment_fn& on_func)
{
    if(d_->observers_ZwQueryInformationEnlistment.empty())
        if(!register_callback_with(*d_, proc, "_ZwQueryInformationEnlistment@20", &on_ZwQueryInformationEnlistment))
            return false;

    d_->observers_ZwQueryInformationEnlistment.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQueryInformationFile(proc_t proc, const on_ZwQueryInformationFile_fn& on_func)
{
    if(d_->observers_ZwQueryInformationFile.empty())
        if(!register_callback_with(*d_, proc, "_ZwQueryInformationFile@20", &on_ZwQueryInformationFile))
            return false;

    d_->observers_ZwQueryInformationFile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQueryInformationJobObject(proc_t proc, const on_ZwQueryInformationJobObject_fn& on_func)
{
    if(d_->observers_ZwQueryInformationJobObject.empty())
        if(!register_callback_with(*d_, proc, "_ZwQueryInformationJobObject@20", &on_ZwQueryInformationJobObject))
            return false;

    d_->observers_ZwQueryInformationJobObject.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQueryInformationPort(proc_t proc, const on_ZwQueryInformationPort_fn& on_func)
{
    if(d_->observers_ZwQueryInformationPort.empty())
        if(!register_callback_with(*d_, proc, "_ZwQueryInformationPort@20", &on_ZwQueryInformationPort))
            return false;

    d_->observers_ZwQueryInformationPort.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQueryInformationProcess(proc_t proc, const on_ZwQueryInformationProcess_fn& on_func)
{
    if(d_->observers_ZwQueryInformationProcess.empty())
        if(!register_callback_with(*d_, proc, "_ZwQueryInformationProcess@20", &on_ZwQueryInformationProcess))
            return false;

    d_->observers_ZwQueryInformationProcess.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQueryInformationResourceManager(proc_t proc, const on_ZwQueryInformationResourceManager_fn& on_func)
{
    if(d_->observers_ZwQueryInformationResourceManager.empty())
        if(!register_callback_with(*d_, proc, "_ZwQueryInformationResourceManager@20", &on_ZwQueryInformationResourceManager))
            return false;

    d_->observers_ZwQueryInformationResourceManager.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtQueryInformationThread(proc_t proc, const on_NtQueryInformationThread_fn& on_func)
{
    if(d_->observers_NtQueryInformationThread.empty())
        if(!register_callback_with(*d_, proc, "_NtQueryInformationThread@20", &on_NtQueryInformationThread))
            return false;

    d_->observers_NtQueryInformationThread.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQueryInformationToken(proc_t proc, const on_ZwQueryInformationToken_fn& on_func)
{
    if(d_->observers_ZwQueryInformationToken.empty())
        if(!register_callback_with(*d_, proc, "_ZwQueryInformationToken@20", &on_ZwQueryInformationToken))
            return false;

    d_->observers_ZwQueryInformationToken.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQueryInformationTransaction(proc_t proc, const on_ZwQueryInformationTransaction_fn& on_func)
{
    if(d_->observers_ZwQueryInformationTransaction.empty())
        if(!register_callback_with(*d_, proc, "_ZwQueryInformationTransaction@20", &on_ZwQueryInformationTransaction))
            return false;

    d_->observers_ZwQueryInformationTransaction.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtQueryInformationTransactionManager(proc_t proc, const on_NtQueryInformationTransactionManager_fn& on_func)
{
    if(d_->observers_NtQueryInformationTransactionManager.empty())
        if(!register_callback_with(*d_, proc, "_NtQueryInformationTransactionManager@20", &on_NtQueryInformationTransactionManager))
            return false;

    d_->observers_NtQueryInformationTransactionManager.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQueryInformationWorkerFactory(proc_t proc, const on_ZwQueryInformationWorkerFactory_fn& on_func)
{
    if(d_->observers_ZwQueryInformationWorkerFactory.empty())
        if(!register_callback_with(*d_, proc, "_ZwQueryInformationWorkerFactory@20", &on_ZwQueryInformationWorkerFactory))
            return false;

    d_->observers_ZwQueryInformationWorkerFactory.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtQueryInstallUILanguage(proc_t proc, const on_NtQueryInstallUILanguage_fn& on_func)
{
    if(d_->observers_NtQueryInstallUILanguage.empty())
        if(!register_callback_with(*d_, proc, "_NtQueryInstallUILanguage@4", &on_NtQueryInstallUILanguage))
            return false;

    d_->observers_NtQueryInstallUILanguage.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtQueryIntervalProfile(proc_t proc, const on_NtQueryIntervalProfile_fn& on_func)
{
    if(d_->observers_NtQueryIntervalProfile.empty())
        if(!register_callback_with(*d_, proc, "_NtQueryIntervalProfile@8", &on_NtQueryIntervalProfile))
            return false;

    d_->observers_NtQueryIntervalProfile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtQueryIoCompletion(proc_t proc, const on_NtQueryIoCompletion_fn& on_func)
{
    if(d_->observers_NtQueryIoCompletion.empty())
        if(!register_callback_with(*d_, proc, "_NtQueryIoCompletion@20", &on_NtQueryIoCompletion))
            return false;

    d_->observers_NtQueryIoCompletion.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQueryKey(proc_t proc, const on_ZwQueryKey_fn& on_func)
{
    if(d_->observers_ZwQueryKey.empty())
        if(!register_callback_with(*d_, proc, "_ZwQueryKey@20", &on_ZwQueryKey))
            return false;

    d_->observers_ZwQueryKey.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtQueryLicenseValue(proc_t proc, const on_NtQueryLicenseValue_fn& on_func)
{
    if(d_->observers_NtQueryLicenseValue.empty())
        if(!register_callback_with(*d_, proc, "_NtQueryLicenseValue@20", &on_NtQueryLicenseValue))
            return false;

    d_->observers_NtQueryLicenseValue.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtQueryMultipleValueKey(proc_t proc, const on_NtQueryMultipleValueKey_fn& on_func)
{
    if(d_->observers_NtQueryMultipleValueKey.empty())
        if(!register_callback_with(*d_, proc, "_NtQueryMultipleValueKey@24", &on_NtQueryMultipleValueKey))
            return false;

    d_->observers_NtQueryMultipleValueKey.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtQueryMutant(proc_t proc, const on_NtQueryMutant_fn& on_func)
{
    if(d_->observers_NtQueryMutant.empty())
        if(!register_callback_with(*d_, proc, "_NtQueryMutant@20", &on_NtQueryMutant))
            return false;

    d_->observers_NtQueryMutant.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtQueryObject(proc_t proc, const on_NtQueryObject_fn& on_func)
{
    if(d_->observers_NtQueryObject.empty())
        if(!register_callback_with(*d_, proc, "_NtQueryObject@20", &on_NtQueryObject))
            return false;

    d_->observers_NtQueryObject.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtQueryOpenSubKeysEx(proc_t proc, const on_NtQueryOpenSubKeysEx_fn& on_func)
{
    if(d_->observers_NtQueryOpenSubKeysEx.empty())
        if(!register_callback_with(*d_, proc, "_NtQueryOpenSubKeysEx@16", &on_NtQueryOpenSubKeysEx))
            return false;

    d_->observers_NtQueryOpenSubKeysEx.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtQueryOpenSubKeys(proc_t proc, const on_NtQueryOpenSubKeys_fn& on_func)
{
    if(d_->observers_NtQueryOpenSubKeys.empty())
        if(!register_callback_with(*d_, proc, "_NtQueryOpenSubKeys@8", &on_NtQueryOpenSubKeys))
            return false;

    d_->observers_NtQueryOpenSubKeys.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtQueryPerformanceCounter(proc_t proc, const on_NtQueryPerformanceCounter_fn& on_func)
{
    if(d_->observers_NtQueryPerformanceCounter.empty())
        if(!register_callback_with(*d_, proc, "_NtQueryPerformanceCounter@8", &on_NtQueryPerformanceCounter))
            return false;

    d_->observers_NtQueryPerformanceCounter.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQueryQuotaInformationFile(proc_t proc, const on_ZwQueryQuotaInformationFile_fn& on_func)
{
    if(d_->observers_ZwQueryQuotaInformationFile.empty())
        if(!register_callback_with(*d_, proc, "_ZwQueryQuotaInformationFile@36", &on_ZwQueryQuotaInformationFile))
            return false;

    d_->observers_ZwQueryQuotaInformationFile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQuerySection(proc_t proc, const on_ZwQuerySection_fn& on_func)
{
    if(d_->observers_ZwQuerySection.empty())
        if(!register_callback_with(*d_, proc, "_ZwQuerySection@20", &on_ZwQuerySection))
            return false;

    d_->observers_ZwQuerySection.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQuerySecurityAttributesToken(proc_t proc, const on_ZwQuerySecurityAttributesToken_fn& on_func)
{
    if(d_->observers_ZwQuerySecurityAttributesToken.empty())
        if(!register_callback_with(*d_, proc, "_ZwQuerySecurityAttributesToken@24", &on_ZwQuerySecurityAttributesToken))
            return false;

    d_->observers_ZwQuerySecurityAttributesToken.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtQuerySecurityObject(proc_t proc, const on_NtQuerySecurityObject_fn& on_func)
{
    if(d_->observers_NtQuerySecurityObject.empty())
        if(!register_callback_with(*d_, proc, "_NtQuerySecurityObject@20", &on_NtQuerySecurityObject))
            return false;

    d_->observers_NtQuerySecurityObject.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQuerySemaphore(proc_t proc, const on_ZwQuerySemaphore_fn& on_func)
{
    if(d_->observers_ZwQuerySemaphore.empty())
        if(!register_callback_with(*d_, proc, "_ZwQuerySemaphore@20", &on_ZwQuerySemaphore))
            return false;

    d_->observers_ZwQuerySemaphore.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQuerySymbolicLinkObject(proc_t proc, const on_ZwQuerySymbolicLinkObject_fn& on_func)
{
    if(d_->observers_ZwQuerySymbolicLinkObject.empty())
        if(!register_callback_with(*d_, proc, "_ZwQuerySymbolicLinkObject@12", &on_ZwQuerySymbolicLinkObject))
            return false;

    d_->observers_ZwQuerySymbolicLinkObject.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQuerySystemEnvironmentValueEx(proc_t proc, const on_ZwQuerySystemEnvironmentValueEx_fn& on_func)
{
    if(d_->observers_ZwQuerySystemEnvironmentValueEx.empty())
        if(!register_callback_with(*d_, proc, "_ZwQuerySystemEnvironmentValueEx@20", &on_ZwQuerySystemEnvironmentValueEx))
            return false;

    d_->observers_ZwQuerySystemEnvironmentValueEx.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQuerySystemEnvironmentValue(proc_t proc, const on_ZwQuerySystemEnvironmentValue_fn& on_func)
{
    if(d_->observers_ZwQuerySystemEnvironmentValue.empty())
        if(!register_callback_with(*d_, proc, "_ZwQuerySystemEnvironmentValue@16", &on_ZwQuerySystemEnvironmentValue))
            return false;

    d_->observers_ZwQuerySystemEnvironmentValue.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQuerySystemInformationEx(proc_t proc, const on_ZwQuerySystemInformationEx_fn& on_func)
{
    if(d_->observers_ZwQuerySystemInformationEx.empty())
        if(!register_callback_with(*d_, proc, "_ZwQuerySystemInformationEx@24", &on_ZwQuerySystemInformationEx))
            return false;

    d_->observers_ZwQuerySystemInformationEx.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtQuerySystemInformation(proc_t proc, const on_NtQuerySystemInformation_fn& on_func)
{
    if(d_->observers_NtQuerySystemInformation.empty())
        if(!register_callback_with(*d_, proc, "_NtQuerySystemInformation@16", &on_NtQuerySystemInformation))
            return false;

    d_->observers_NtQuerySystemInformation.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtQuerySystemTime(proc_t proc, const on_NtQuerySystemTime_fn& on_func)
{
    if(d_->observers_NtQuerySystemTime.empty())
        if(!register_callback_with(*d_, proc, "_NtQuerySystemTime@4", &on_NtQuerySystemTime))
            return false;

    d_->observers_NtQuerySystemTime.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQueryTimer(proc_t proc, const on_ZwQueryTimer_fn& on_func)
{
    if(d_->observers_ZwQueryTimer.empty())
        if(!register_callback_with(*d_, proc, "_ZwQueryTimer@20", &on_ZwQueryTimer))
            return false;

    d_->observers_ZwQueryTimer.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtQueryTimerResolution(proc_t proc, const on_NtQueryTimerResolution_fn& on_func)
{
    if(d_->observers_NtQueryTimerResolution.empty())
        if(!register_callback_with(*d_, proc, "_NtQueryTimerResolution@12", &on_NtQueryTimerResolution))
            return false;

    d_->observers_NtQueryTimerResolution.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQueryValueKey(proc_t proc, const on_ZwQueryValueKey_fn& on_func)
{
    if(d_->observers_ZwQueryValueKey.empty())
        if(!register_callback_with(*d_, proc, "_ZwQueryValueKey@24", &on_ZwQueryValueKey))
            return false;

    d_->observers_ZwQueryValueKey.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtQueryVirtualMemory(proc_t proc, const on_NtQueryVirtualMemory_fn& on_func)
{
    if(d_->observers_NtQueryVirtualMemory.empty())
        if(!register_callback_with(*d_, proc, "_NtQueryVirtualMemory@24", &on_NtQueryVirtualMemory))
            return false;

    d_->observers_NtQueryVirtualMemory.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtQueryVolumeInformationFile(proc_t proc, const on_NtQueryVolumeInformationFile_fn& on_func)
{
    if(d_->observers_NtQueryVolumeInformationFile.empty())
        if(!register_callback_with(*d_, proc, "_NtQueryVolumeInformationFile@20", &on_NtQueryVolumeInformationFile))
            return false;

    d_->observers_NtQueryVolumeInformationFile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtQueueApcThreadEx(proc_t proc, const on_NtQueueApcThreadEx_fn& on_func)
{
    if(d_->observers_NtQueueApcThreadEx.empty())
        if(!register_callback_with(*d_, proc, "_NtQueueApcThreadEx@24", &on_NtQueueApcThreadEx))
            return false;

    d_->observers_NtQueueApcThreadEx.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtQueueApcThread(proc_t proc, const on_NtQueueApcThread_fn& on_func)
{
    if(d_->observers_NtQueueApcThread.empty())
        if(!register_callback_with(*d_, proc, "_NtQueueApcThread@20", &on_NtQueueApcThread))
            return false;

    d_->observers_NtQueueApcThread.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwRaiseException(proc_t proc, const on_ZwRaiseException_fn& on_func)
{
    if(d_->observers_ZwRaiseException.empty())
        if(!register_callback_with(*d_, proc, "_ZwRaiseException@12", &on_ZwRaiseException))
            return false;

    d_->observers_ZwRaiseException.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwRaiseHardError(proc_t proc, const on_ZwRaiseHardError_fn& on_func)
{
    if(d_->observers_ZwRaiseHardError.empty())
        if(!register_callback_with(*d_, proc, "_ZwRaiseHardError@24", &on_ZwRaiseHardError))
            return false;

    d_->observers_ZwRaiseHardError.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtReadFile(proc_t proc, const on_NtReadFile_fn& on_func)
{
    if(d_->observers_NtReadFile.empty())
        if(!register_callback_with(*d_, proc, "_NtReadFile@36", &on_NtReadFile))
            return false;

    d_->observers_NtReadFile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtReadFileScatter(proc_t proc, const on_NtReadFileScatter_fn& on_func)
{
    if(d_->observers_NtReadFileScatter.empty())
        if(!register_callback_with(*d_, proc, "_NtReadFileScatter@36", &on_NtReadFileScatter))
            return false;

    d_->observers_NtReadFileScatter.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwReadOnlyEnlistment(proc_t proc, const on_ZwReadOnlyEnlistment_fn& on_func)
{
    if(d_->observers_ZwReadOnlyEnlistment.empty())
        if(!register_callback_with(*d_, proc, "_ZwReadOnlyEnlistment@8", &on_ZwReadOnlyEnlistment))
            return false;

    d_->observers_ZwReadOnlyEnlistment.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwReadRequestData(proc_t proc, const on_ZwReadRequestData_fn& on_func)
{
    if(d_->observers_ZwReadRequestData.empty())
        if(!register_callback_with(*d_, proc, "_ZwReadRequestData@24", &on_ZwReadRequestData))
            return false;

    d_->observers_ZwReadRequestData.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtReadVirtualMemory(proc_t proc, const on_NtReadVirtualMemory_fn& on_func)
{
    if(d_->observers_NtReadVirtualMemory.empty())
        if(!register_callback_with(*d_, proc, "_NtReadVirtualMemory@20", &on_NtReadVirtualMemory))
            return false;

    d_->observers_NtReadVirtualMemory.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtRecoverEnlistment(proc_t proc, const on_NtRecoverEnlistment_fn& on_func)
{
    if(d_->observers_NtRecoverEnlistment.empty())
        if(!register_callback_with(*d_, proc, "_NtRecoverEnlistment@8", &on_NtRecoverEnlistment))
            return false;

    d_->observers_NtRecoverEnlistment.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtRecoverResourceManager(proc_t proc, const on_NtRecoverResourceManager_fn& on_func)
{
    if(d_->observers_NtRecoverResourceManager.empty())
        if(!register_callback_with(*d_, proc, "_NtRecoverResourceManager@4", &on_NtRecoverResourceManager))
            return false;

    d_->observers_NtRecoverResourceManager.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwRecoverTransactionManager(proc_t proc, const on_ZwRecoverTransactionManager_fn& on_func)
{
    if(d_->observers_ZwRecoverTransactionManager.empty())
        if(!register_callback_with(*d_, proc, "_ZwRecoverTransactionManager@4", &on_ZwRecoverTransactionManager))
            return false;

    d_->observers_ZwRecoverTransactionManager.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwRegisterProtocolAddressInformation(proc_t proc, const on_ZwRegisterProtocolAddressInformation_fn& on_func)
{
    if(d_->observers_ZwRegisterProtocolAddressInformation.empty())
        if(!register_callback_with(*d_, proc, "_ZwRegisterProtocolAddressInformation@20", &on_ZwRegisterProtocolAddressInformation))
            return false;

    d_->observers_ZwRegisterProtocolAddressInformation.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwRegisterThreadTerminatePort(proc_t proc, const on_ZwRegisterThreadTerminatePort_fn& on_func)
{
    if(d_->observers_ZwRegisterThreadTerminatePort.empty())
        if(!register_callback_with(*d_, proc, "_ZwRegisterThreadTerminatePort@4", &on_ZwRegisterThreadTerminatePort))
            return false;

    d_->observers_ZwRegisterThreadTerminatePort.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtReleaseKeyedEvent(proc_t proc, const on_NtReleaseKeyedEvent_fn& on_func)
{
    if(d_->observers_NtReleaseKeyedEvent.empty())
        if(!register_callback_with(*d_, proc, "_NtReleaseKeyedEvent@16", &on_NtReleaseKeyedEvent))
            return false;

    d_->observers_NtReleaseKeyedEvent.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwReleaseMutant(proc_t proc, const on_ZwReleaseMutant_fn& on_func)
{
    if(d_->observers_ZwReleaseMutant.empty())
        if(!register_callback_with(*d_, proc, "_ZwReleaseMutant@8", &on_ZwReleaseMutant))
            return false;

    d_->observers_ZwReleaseMutant.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtReleaseSemaphore(proc_t proc, const on_NtReleaseSemaphore_fn& on_func)
{
    if(d_->observers_NtReleaseSemaphore.empty())
        if(!register_callback_with(*d_, proc, "_NtReleaseSemaphore@12", &on_NtReleaseSemaphore))
            return false;

    d_->observers_NtReleaseSemaphore.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwReleaseWorkerFactoryWorker(proc_t proc, const on_ZwReleaseWorkerFactoryWorker_fn& on_func)
{
    if(d_->observers_ZwReleaseWorkerFactoryWorker.empty())
        if(!register_callback_with(*d_, proc, "_ZwReleaseWorkerFactoryWorker@4", &on_ZwReleaseWorkerFactoryWorker))
            return false;

    d_->observers_ZwReleaseWorkerFactoryWorker.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwRemoveIoCompletionEx(proc_t proc, const on_ZwRemoveIoCompletionEx_fn& on_func)
{
    if(d_->observers_ZwRemoveIoCompletionEx.empty())
        if(!register_callback_with(*d_, proc, "_ZwRemoveIoCompletionEx@24", &on_ZwRemoveIoCompletionEx))
            return false;

    d_->observers_ZwRemoveIoCompletionEx.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwRemoveIoCompletion(proc_t proc, const on_ZwRemoveIoCompletion_fn& on_func)
{
    if(d_->observers_ZwRemoveIoCompletion.empty())
        if(!register_callback_with(*d_, proc, "_ZwRemoveIoCompletion@20", &on_ZwRemoveIoCompletion))
            return false;

    d_->observers_ZwRemoveIoCompletion.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwRemoveProcessDebug(proc_t proc, const on_ZwRemoveProcessDebug_fn& on_func)
{
    if(d_->observers_ZwRemoveProcessDebug.empty())
        if(!register_callback_with(*d_, proc, "_ZwRemoveProcessDebug@8", &on_ZwRemoveProcessDebug))
            return false;

    d_->observers_ZwRemoveProcessDebug.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwRenameKey(proc_t proc, const on_ZwRenameKey_fn& on_func)
{
    if(d_->observers_ZwRenameKey.empty())
        if(!register_callback_with(*d_, proc, "_ZwRenameKey@8", &on_ZwRenameKey))
            return false;

    d_->observers_ZwRenameKey.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtRenameTransactionManager(proc_t proc, const on_NtRenameTransactionManager_fn& on_func)
{
    if(d_->observers_NtRenameTransactionManager.empty())
        if(!register_callback_with(*d_, proc, "_NtRenameTransactionManager@8", &on_NtRenameTransactionManager))
            return false;

    d_->observers_NtRenameTransactionManager.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwReplaceKey(proc_t proc, const on_ZwReplaceKey_fn& on_func)
{
    if(d_->observers_ZwReplaceKey.empty())
        if(!register_callback_with(*d_, proc, "_ZwReplaceKey@12", &on_ZwReplaceKey))
            return false;

    d_->observers_ZwReplaceKey.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtReplacePartitionUnit(proc_t proc, const on_NtReplacePartitionUnit_fn& on_func)
{
    if(d_->observers_NtReplacePartitionUnit.empty())
        if(!register_callback_with(*d_, proc, "_NtReplacePartitionUnit@12", &on_NtReplacePartitionUnit))
            return false;

    d_->observers_NtReplacePartitionUnit.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwReplyPort(proc_t proc, const on_ZwReplyPort_fn& on_func)
{
    if(d_->observers_ZwReplyPort.empty())
        if(!register_callback_with(*d_, proc, "_ZwReplyPort@8", &on_ZwReplyPort))
            return false;

    d_->observers_ZwReplyPort.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtReplyWaitReceivePortEx(proc_t proc, const on_NtReplyWaitReceivePortEx_fn& on_func)
{
    if(d_->observers_NtReplyWaitReceivePortEx.empty())
        if(!register_callback_with(*d_, proc, "_NtReplyWaitReceivePortEx@20", &on_NtReplyWaitReceivePortEx))
            return false;

    d_->observers_NtReplyWaitReceivePortEx.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtReplyWaitReceivePort(proc_t proc, const on_NtReplyWaitReceivePort_fn& on_func)
{
    if(d_->observers_NtReplyWaitReceivePort.empty())
        if(!register_callback_with(*d_, proc, "_NtReplyWaitReceivePort@16", &on_NtReplyWaitReceivePort))
            return false;

    d_->observers_NtReplyWaitReceivePort.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtReplyWaitReplyPort(proc_t proc, const on_NtReplyWaitReplyPort_fn& on_func)
{
    if(d_->observers_NtReplyWaitReplyPort.empty())
        if(!register_callback_with(*d_, proc, "_NtReplyWaitReplyPort@8", &on_NtReplyWaitReplyPort))
            return false;

    d_->observers_NtReplyWaitReplyPort.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwRequestPort(proc_t proc, const on_ZwRequestPort_fn& on_func)
{
    if(d_->observers_ZwRequestPort.empty())
        if(!register_callback_with(*d_, proc, "_ZwRequestPort@8", &on_ZwRequestPort))
            return false;

    d_->observers_ZwRequestPort.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtRequestWaitReplyPort(proc_t proc, const on_NtRequestWaitReplyPort_fn& on_func)
{
    if(d_->observers_NtRequestWaitReplyPort.empty())
        if(!register_callback_with(*d_, proc, "_NtRequestWaitReplyPort@12", &on_NtRequestWaitReplyPort))
            return false;

    d_->observers_NtRequestWaitReplyPort.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtResetEvent(proc_t proc, const on_NtResetEvent_fn& on_func)
{
    if(d_->observers_NtResetEvent.empty())
        if(!register_callback_with(*d_, proc, "_NtResetEvent@8", &on_NtResetEvent))
            return false;

    d_->observers_NtResetEvent.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwResetWriteWatch(proc_t proc, const on_ZwResetWriteWatch_fn& on_func)
{
    if(d_->observers_ZwResetWriteWatch.empty())
        if(!register_callback_with(*d_, proc, "_ZwResetWriteWatch@12", &on_ZwResetWriteWatch))
            return false;

    d_->observers_ZwResetWriteWatch.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtRestoreKey(proc_t proc, const on_NtRestoreKey_fn& on_func)
{
    if(d_->observers_NtRestoreKey.empty())
        if(!register_callback_with(*d_, proc, "_NtRestoreKey@12", &on_NtRestoreKey))
            return false;

    d_->observers_NtRestoreKey.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwResumeProcess(proc_t proc, const on_ZwResumeProcess_fn& on_func)
{
    if(d_->observers_ZwResumeProcess.empty())
        if(!register_callback_with(*d_, proc, "_ZwResumeProcess@4", &on_ZwResumeProcess))
            return false;

    d_->observers_ZwResumeProcess.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwResumeThread(proc_t proc, const on_ZwResumeThread_fn& on_func)
{
    if(d_->observers_ZwResumeThread.empty())
        if(!register_callback_with(*d_, proc, "_ZwResumeThread@8", &on_ZwResumeThread))
            return false;

    d_->observers_ZwResumeThread.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwRollbackComplete(proc_t proc, const on_ZwRollbackComplete_fn& on_func)
{
    if(d_->observers_ZwRollbackComplete.empty())
        if(!register_callback_with(*d_, proc, "_ZwRollbackComplete@8", &on_ZwRollbackComplete))
            return false;

    d_->observers_ZwRollbackComplete.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtRollbackEnlistment(proc_t proc, const on_NtRollbackEnlistment_fn& on_func)
{
    if(d_->observers_NtRollbackEnlistment.empty())
        if(!register_callback_with(*d_, proc, "_NtRollbackEnlistment@8", &on_NtRollbackEnlistment))
            return false;

    d_->observers_NtRollbackEnlistment.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtRollbackTransaction(proc_t proc, const on_NtRollbackTransaction_fn& on_func)
{
    if(d_->observers_NtRollbackTransaction.empty())
        if(!register_callback_with(*d_, proc, "_NtRollbackTransaction@8", &on_NtRollbackTransaction))
            return false;

    d_->observers_NtRollbackTransaction.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtRollforwardTransactionManager(proc_t proc, const on_NtRollforwardTransactionManager_fn& on_func)
{
    if(d_->observers_NtRollforwardTransactionManager.empty())
        if(!register_callback_with(*d_, proc, "_NtRollforwardTransactionManager@8", &on_NtRollforwardTransactionManager))
            return false;

    d_->observers_NtRollforwardTransactionManager.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtSaveKeyEx(proc_t proc, const on_NtSaveKeyEx_fn& on_func)
{
    if(d_->observers_NtSaveKeyEx.empty())
        if(!register_callback_with(*d_, proc, "_NtSaveKeyEx@12", &on_NtSaveKeyEx))
            return false;

    d_->observers_NtSaveKeyEx.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtSaveKey(proc_t proc, const on_NtSaveKey_fn& on_func)
{
    if(d_->observers_NtSaveKey.empty())
        if(!register_callback_with(*d_, proc, "_NtSaveKey@8", &on_NtSaveKey))
            return false;

    d_->observers_NtSaveKey.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtSaveMergedKeys(proc_t proc, const on_NtSaveMergedKeys_fn& on_func)
{
    if(d_->observers_NtSaveMergedKeys.empty())
        if(!register_callback_with(*d_, proc, "_NtSaveMergedKeys@12", &on_NtSaveMergedKeys))
            return false;

    d_->observers_NtSaveMergedKeys.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtSecureConnectPort(proc_t proc, const on_NtSecureConnectPort_fn& on_func)
{
    if(d_->observers_NtSecureConnectPort.empty())
        if(!register_callback_with(*d_, proc, "_NtSecureConnectPort@36", &on_NtSecureConnectPort))
            return false;

    d_->observers_NtSecureConnectPort.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetBootEntryOrder(proc_t proc, const on_ZwSetBootEntryOrder_fn& on_func)
{
    if(d_->observers_ZwSetBootEntryOrder.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetBootEntryOrder@8", &on_ZwSetBootEntryOrder))
            return false;

    d_->observers_ZwSetBootEntryOrder.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetBootOptions(proc_t proc, const on_ZwSetBootOptions_fn& on_func)
{
    if(d_->observers_ZwSetBootOptions.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetBootOptions@8", &on_ZwSetBootOptions))
            return false;

    d_->observers_ZwSetBootOptions.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetContextThread(proc_t proc, const on_ZwSetContextThread_fn& on_func)
{
    if(d_->observers_ZwSetContextThread.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetContextThread@8", &on_ZwSetContextThread))
            return false;

    d_->observers_ZwSetContextThread.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtSetDebugFilterState(proc_t proc, const on_NtSetDebugFilterState_fn& on_func)
{
    if(d_->observers_NtSetDebugFilterState.empty())
        if(!register_callback_with(*d_, proc, "_NtSetDebugFilterState@12", &on_NtSetDebugFilterState))
            return false;

    d_->observers_NtSetDebugFilterState.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtSetDefaultHardErrorPort(proc_t proc, const on_NtSetDefaultHardErrorPort_fn& on_func)
{
    if(d_->observers_NtSetDefaultHardErrorPort.empty())
        if(!register_callback_with(*d_, proc, "_NtSetDefaultHardErrorPort@4", &on_NtSetDefaultHardErrorPort))
            return false;

    d_->observers_NtSetDefaultHardErrorPort.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtSetDefaultLocale(proc_t proc, const on_NtSetDefaultLocale_fn& on_func)
{
    if(d_->observers_NtSetDefaultLocale.empty())
        if(!register_callback_with(*d_, proc, "_NtSetDefaultLocale@8", &on_NtSetDefaultLocale))
            return false;

    d_->observers_NtSetDefaultLocale.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetDefaultUILanguage(proc_t proc, const on_ZwSetDefaultUILanguage_fn& on_func)
{
    if(d_->observers_ZwSetDefaultUILanguage.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetDefaultUILanguage@4", &on_ZwSetDefaultUILanguage))
            return false;

    d_->observers_ZwSetDefaultUILanguage.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtSetDriverEntryOrder(proc_t proc, const on_NtSetDriverEntryOrder_fn& on_func)
{
    if(d_->observers_NtSetDriverEntryOrder.empty())
        if(!register_callback_with(*d_, proc, "_NtSetDriverEntryOrder@8", &on_NtSetDriverEntryOrder))
            return false;

    d_->observers_NtSetDriverEntryOrder.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetEaFile(proc_t proc, const on_ZwSetEaFile_fn& on_func)
{
    if(d_->observers_ZwSetEaFile.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetEaFile@16", &on_ZwSetEaFile))
            return false;

    d_->observers_ZwSetEaFile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtSetEventBoostPriority(proc_t proc, const on_NtSetEventBoostPriority_fn& on_func)
{
    if(d_->observers_NtSetEventBoostPriority.empty())
        if(!register_callback_with(*d_, proc, "_NtSetEventBoostPriority@4", &on_NtSetEventBoostPriority))
            return false;

    d_->observers_NtSetEventBoostPriority.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtSetEvent(proc_t proc, const on_NtSetEvent_fn& on_func)
{
    if(d_->observers_NtSetEvent.empty())
        if(!register_callback_with(*d_, proc, "_NtSetEvent@8", &on_NtSetEvent))
            return false;

    d_->observers_NtSetEvent.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtSetHighEventPair(proc_t proc, const on_NtSetHighEventPair_fn& on_func)
{
    if(d_->observers_NtSetHighEventPair.empty())
        if(!register_callback_with(*d_, proc, "_NtSetHighEventPair@4", &on_NtSetHighEventPair))
            return false;

    d_->observers_NtSetHighEventPair.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtSetHighWaitLowEventPair(proc_t proc, const on_NtSetHighWaitLowEventPair_fn& on_func)
{
    if(d_->observers_NtSetHighWaitLowEventPair.empty())
        if(!register_callback_with(*d_, proc, "_NtSetHighWaitLowEventPair@4", &on_NtSetHighWaitLowEventPair))
            return false;

    d_->observers_NtSetHighWaitLowEventPair.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetInformationDebugObject(proc_t proc, const on_ZwSetInformationDebugObject_fn& on_func)
{
    if(d_->observers_ZwSetInformationDebugObject.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetInformationDebugObject@20", &on_ZwSetInformationDebugObject))
            return false;

    d_->observers_ZwSetInformationDebugObject.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtSetInformationEnlistment(proc_t proc, const on_NtSetInformationEnlistment_fn& on_func)
{
    if(d_->observers_NtSetInformationEnlistment.empty())
        if(!register_callback_with(*d_, proc, "_NtSetInformationEnlistment@16", &on_NtSetInformationEnlistment))
            return false;

    d_->observers_NtSetInformationEnlistment.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetInformationFile(proc_t proc, const on_ZwSetInformationFile_fn& on_func)
{
    if(d_->observers_ZwSetInformationFile.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetInformationFile@20", &on_ZwSetInformationFile))
            return false;

    d_->observers_ZwSetInformationFile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetInformationJobObject(proc_t proc, const on_ZwSetInformationJobObject_fn& on_func)
{
    if(d_->observers_ZwSetInformationJobObject.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetInformationJobObject@16", &on_ZwSetInformationJobObject))
            return false;

    d_->observers_ZwSetInformationJobObject.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetInformationKey(proc_t proc, const on_ZwSetInformationKey_fn& on_func)
{
    if(d_->observers_ZwSetInformationKey.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetInformationKey@16", &on_ZwSetInformationKey))
            return false;

    d_->observers_ZwSetInformationKey.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetInformationObject(proc_t proc, const on_ZwSetInformationObject_fn& on_func)
{
    if(d_->observers_ZwSetInformationObject.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetInformationObject@16", &on_ZwSetInformationObject))
            return false;

    d_->observers_ZwSetInformationObject.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetInformationProcess(proc_t proc, const on_ZwSetInformationProcess_fn& on_func)
{
    if(d_->observers_ZwSetInformationProcess.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetInformationProcess@16", &on_ZwSetInformationProcess))
            return false;

    d_->observers_ZwSetInformationProcess.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetInformationResourceManager(proc_t proc, const on_ZwSetInformationResourceManager_fn& on_func)
{
    if(d_->observers_ZwSetInformationResourceManager.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetInformationResourceManager@16", &on_ZwSetInformationResourceManager))
            return false;

    d_->observers_ZwSetInformationResourceManager.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetInformationThread(proc_t proc, const on_ZwSetInformationThread_fn& on_func)
{
    if(d_->observers_ZwSetInformationThread.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetInformationThread@16", &on_ZwSetInformationThread))
            return false;

    d_->observers_ZwSetInformationThread.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetInformationToken(proc_t proc, const on_ZwSetInformationToken_fn& on_func)
{
    if(d_->observers_ZwSetInformationToken.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetInformationToken@16", &on_ZwSetInformationToken))
            return false;

    d_->observers_ZwSetInformationToken.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetInformationTransaction(proc_t proc, const on_ZwSetInformationTransaction_fn& on_func)
{
    if(d_->observers_ZwSetInformationTransaction.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetInformationTransaction@16", &on_ZwSetInformationTransaction))
            return false;

    d_->observers_ZwSetInformationTransaction.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetInformationTransactionManager(proc_t proc, const on_ZwSetInformationTransactionManager_fn& on_func)
{
    if(d_->observers_ZwSetInformationTransactionManager.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetInformationTransactionManager@16", &on_ZwSetInformationTransactionManager))
            return false;

    d_->observers_ZwSetInformationTransactionManager.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetInformationWorkerFactory(proc_t proc, const on_ZwSetInformationWorkerFactory_fn& on_func)
{
    if(d_->observers_ZwSetInformationWorkerFactory.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetInformationWorkerFactory@16", &on_ZwSetInformationWorkerFactory))
            return false;

    d_->observers_ZwSetInformationWorkerFactory.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtSetIntervalProfile(proc_t proc, const on_NtSetIntervalProfile_fn& on_func)
{
    if(d_->observers_NtSetIntervalProfile.empty())
        if(!register_callback_with(*d_, proc, "_NtSetIntervalProfile@8", &on_NtSetIntervalProfile))
            return false;

    d_->observers_NtSetIntervalProfile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtSetIoCompletionEx(proc_t proc, const on_NtSetIoCompletionEx_fn& on_func)
{
    if(d_->observers_NtSetIoCompletionEx.empty())
        if(!register_callback_with(*d_, proc, "_NtSetIoCompletionEx@24", &on_NtSetIoCompletionEx))
            return false;

    d_->observers_NtSetIoCompletionEx.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtSetIoCompletion(proc_t proc, const on_NtSetIoCompletion_fn& on_func)
{
    if(d_->observers_NtSetIoCompletion.empty())
        if(!register_callback_with(*d_, proc, "_NtSetIoCompletion@20", &on_NtSetIoCompletion))
            return false;

    d_->observers_NtSetIoCompletion.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetLdtEntries(proc_t proc, const on_ZwSetLdtEntries_fn& on_func)
{
    if(d_->observers_ZwSetLdtEntries.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetLdtEntries@24", &on_ZwSetLdtEntries))
            return false;

    d_->observers_ZwSetLdtEntries.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetLowEventPair(proc_t proc, const on_ZwSetLowEventPair_fn& on_func)
{
    if(d_->observers_ZwSetLowEventPair.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetLowEventPair@4", &on_ZwSetLowEventPair))
            return false;

    d_->observers_ZwSetLowEventPair.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetLowWaitHighEventPair(proc_t proc, const on_ZwSetLowWaitHighEventPair_fn& on_func)
{
    if(d_->observers_ZwSetLowWaitHighEventPair.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetLowWaitHighEventPair@4", &on_ZwSetLowWaitHighEventPair))
            return false;

    d_->observers_ZwSetLowWaitHighEventPair.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetQuotaInformationFile(proc_t proc, const on_ZwSetQuotaInformationFile_fn& on_func)
{
    if(d_->observers_ZwSetQuotaInformationFile.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetQuotaInformationFile@16", &on_ZwSetQuotaInformationFile))
            return false;

    d_->observers_ZwSetQuotaInformationFile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtSetSecurityObject(proc_t proc, const on_NtSetSecurityObject_fn& on_func)
{
    if(d_->observers_NtSetSecurityObject.empty())
        if(!register_callback_with(*d_, proc, "_NtSetSecurityObject@12", &on_NtSetSecurityObject))
            return false;

    d_->observers_NtSetSecurityObject.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetSystemEnvironmentValueEx(proc_t proc, const on_ZwSetSystemEnvironmentValueEx_fn& on_func)
{
    if(d_->observers_ZwSetSystemEnvironmentValueEx.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetSystemEnvironmentValueEx@20", &on_ZwSetSystemEnvironmentValueEx))
            return false;

    d_->observers_ZwSetSystemEnvironmentValueEx.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetSystemEnvironmentValue(proc_t proc, const on_ZwSetSystemEnvironmentValue_fn& on_func)
{
    if(d_->observers_ZwSetSystemEnvironmentValue.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetSystemEnvironmentValue@8", &on_ZwSetSystemEnvironmentValue))
            return false;

    d_->observers_ZwSetSystemEnvironmentValue.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetSystemInformation(proc_t proc, const on_ZwSetSystemInformation_fn& on_func)
{
    if(d_->observers_ZwSetSystemInformation.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetSystemInformation@12", &on_ZwSetSystemInformation))
            return false;

    d_->observers_ZwSetSystemInformation.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetSystemPowerState(proc_t proc, const on_ZwSetSystemPowerState_fn& on_func)
{
    if(d_->observers_ZwSetSystemPowerState.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetSystemPowerState@12", &on_ZwSetSystemPowerState))
            return false;

    d_->observers_ZwSetSystemPowerState.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetSystemTime(proc_t proc, const on_ZwSetSystemTime_fn& on_func)
{
    if(d_->observers_ZwSetSystemTime.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetSystemTime@8", &on_ZwSetSystemTime))
            return false;

    d_->observers_ZwSetSystemTime.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetThreadExecutionState(proc_t proc, const on_ZwSetThreadExecutionState_fn& on_func)
{
    if(d_->observers_ZwSetThreadExecutionState.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetThreadExecutionState@8", &on_ZwSetThreadExecutionState))
            return false;

    d_->observers_ZwSetThreadExecutionState.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetTimerEx(proc_t proc, const on_ZwSetTimerEx_fn& on_func)
{
    if(d_->observers_ZwSetTimerEx.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetTimerEx@16", &on_ZwSetTimerEx))
            return false;

    d_->observers_ZwSetTimerEx.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetTimer(proc_t proc, const on_ZwSetTimer_fn& on_func)
{
    if(d_->observers_ZwSetTimer.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetTimer@28", &on_ZwSetTimer))
            return false;

    d_->observers_ZwSetTimer.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtSetTimerResolution(proc_t proc, const on_NtSetTimerResolution_fn& on_func)
{
    if(d_->observers_NtSetTimerResolution.empty())
        if(!register_callback_with(*d_, proc, "_NtSetTimerResolution@12", &on_NtSetTimerResolution))
            return false;

    d_->observers_NtSetTimerResolution.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetUuidSeed(proc_t proc, const on_ZwSetUuidSeed_fn& on_func)
{
    if(d_->observers_ZwSetUuidSeed.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetUuidSeed@4", &on_ZwSetUuidSeed))
            return false;

    d_->observers_ZwSetUuidSeed.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSetValueKey(proc_t proc, const on_ZwSetValueKey_fn& on_func)
{
    if(d_->observers_ZwSetValueKey.empty())
        if(!register_callback_with(*d_, proc, "_ZwSetValueKey@24", &on_ZwSetValueKey))
            return false;

    d_->observers_ZwSetValueKey.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtSetVolumeInformationFile(proc_t proc, const on_NtSetVolumeInformationFile_fn& on_func)
{
    if(d_->observers_NtSetVolumeInformationFile.empty())
        if(!register_callback_with(*d_, proc, "_NtSetVolumeInformationFile@20", &on_NtSetVolumeInformationFile))
            return false;

    d_->observers_NtSetVolumeInformationFile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwShutdownSystem(proc_t proc, const on_ZwShutdownSystem_fn& on_func)
{
    if(d_->observers_ZwShutdownSystem.empty())
        if(!register_callback_with(*d_, proc, "_ZwShutdownSystem@4", &on_ZwShutdownSystem))
            return false;

    d_->observers_ZwShutdownSystem.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtShutdownWorkerFactory(proc_t proc, const on_NtShutdownWorkerFactory_fn& on_func)
{
    if(d_->observers_NtShutdownWorkerFactory.empty())
        if(!register_callback_with(*d_, proc, "_NtShutdownWorkerFactory@8", &on_NtShutdownWorkerFactory))
            return false;

    d_->observers_NtShutdownWorkerFactory.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSignalAndWaitForSingleObject(proc_t proc, const on_ZwSignalAndWaitForSingleObject_fn& on_func)
{
    if(d_->observers_ZwSignalAndWaitForSingleObject.empty())
        if(!register_callback_with(*d_, proc, "_ZwSignalAndWaitForSingleObject@16", &on_ZwSignalAndWaitForSingleObject))
            return false;

    d_->observers_ZwSignalAndWaitForSingleObject.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSinglePhaseReject(proc_t proc, const on_ZwSinglePhaseReject_fn& on_func)
{
    if(d_->observers_ZwSinglePhaseReject.empty())
        if(!register_callback_with(*d_, proc, "_ZwSinglePhaseReject@8", &on_ZwSinglePhaseReject))
            return false;

    d_->observers_ZwSinglePhaseReject.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtStartProfile(proc_t proc, const on_NtStartProfile_fn& on_func)
{
    if(d_->observers_NtStartProfile.empty())
        if(!register_callback_with(*d_, proc, "_NtStartProfile@4", &on_NtStartProfile))
            return false;

    d_->observers_NtStartProfile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwStopProfile(proc_t proc, const on_ZwStopProfile_fn& on_func)
{
    if(d_->observers_ZwStopProfile.empty())
        if(!register_callback_with(*d_, proc, "_ZwStopProfile@4", &on_ZwStopProfile))
            return false;

    d_->observers_ZwStopProfile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSuspendProcess(proc_t proc, const on_ZwSuspendProcess_fn& on_func)
{
    if(d_->observers_ZwSuspendProcess.empty())
        if(!register_callback_with(*d_, proc, "_ZwSuspendProcess@4", &on_ZwSuspendProcess))
            return false;

    d_->observers_ZwSuspendProcess.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwSuspendThread(proc_t proc, const on_ZwSuspendThread_fn& on_func)
{
    if(d_->observers_ZwSuspendThread.empty())
        if(!register_callback_with(*d_, proc, "_ZwSuspendThread@8", &on_ZwSuspendThread))
            return false;

    d_->observers_ZwSuspendThread.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtSystemDebugControl(proc_t proc, const on_NtSystemDebugControl_fn& on_func)
{
    if(d_->observers_NtSystemDebugControl.empty())
        if(!register_callback_with(*d_, proc, "_NtSystemDebugControl@24", &on_NtSystemDebugControl))
            return false;

    d_->observers_NtSystemDebugControl.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwTerminateJobObject(proc_t proc, const on_ZwTerminateJobObject_fn& on_func)
{
    if(d_->observers_ZwTerminateJobObject.empty())
        if(!register_callback_with(*d_, proc, "_ZwTerminateJobObject@8", &on_ZwTerminateJobObject))
            return false;

    d_->observers_ZwTerminateJobObject.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwTerminateProcess(proc_t proc, const on_ZwTerminateProcess_fn& on_func)
{
    if(d_->observers_ZwTerminateProcess.empty())
        if(!register_callback_with(*d_, proc, "_ZwTerminateProcess@8", &on_ZwTerminateProcess))
            return false;

    d_->observers_ZwTerminateProcess.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwTerminateThread(proc_t proc, const on_ZwTerminateThread_fn& on_func)
{
    if(d_->observers_ZwTerminateThread.empty())
        if(!register_callback_with(*d_, proc, "_ZwTerminateThread@8", &on_ZwTerminateThread))
            return false;

    d_->observers_ZwTerminateThread.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwTraceControl(proc_t proc, const on_ZwTraceControl_fn& on_func)
{
    if(d_->observers_ZwTraceControl.empty())
        if(!register_callback_with(*d_, proc, "_ZwTraceControl@24", &on_ZwTraceControl))
            return false;

    d_->observers_ZwTraceControl.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtTraceEvent(proc_t proc, const on_NtTraceEvent_fn& on_func)
{
    if(d_->observers_NtTraceEvent.empty())
        if(!register_callback_with(*d_, proc, "_NtTraceEvent@16", &on_NtTraceEvent))
            return false;

    d_->observers_NtTraceEvent.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtTranslateFilePath(proc_t proc, const on_NtTranslateFilePath_fn& on_func)
{
    if(d_->observers_NtTranslateFilePath.empty())
        if(!register_callback_with(*d_, proc, "_NtTranslateFilePath@16", &on_NtTranslateFilePath))
            return false;

    d_->observers_NtTranslateFilePath.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwUnloadDriver(proc_t proc, const on_ZwUnloadDriver_fn& on_func)
{
    if(d_->observers_ZwUnloadDriver.empty())
        if(!register_callback_with(*d_, proc, "_ZwUnloadDriver@4", &on_ZwUnloadDriver))
            return false;

    d_->observers_ZwUnloadDriver.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwUnloadKey2(proc_t proc, const on_ZwUnloadKey2_fn& on_func)
{
    if(d_->observers_ZwUnloadKey2.empty())
        if(!register_callback_with(*d_, proc, "_ZwUnloadKey2@8", &on_ZwUnloadKey2))
            return false;

    d_->observers_ZwUnloadKey2.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwUnloadKeyEx(proc_t proc, const on_ZwUnloadKeyEx_fn& on_func)
{
    if(d_->observers_ZwUnloadKeyEx.empty())
        if(!register_callback_with(*d_, proc, "_ZwUnloadKeyEx@8", &on_ZwUnloadKeyEx))
            return false;

    d_->observers_ZwUnloadKeyEx.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtUnloadKey(proc_t proc, const on_NtUnloadKey_fn& on_func)
{
    if(d_->observers_NtUnloadKey.empty())
        if(!register_callback_with(*d_, proc, "_NtUnloadKey@4", &on_NtUnloadKey))
            return false;

    d_->observers_NtUnloadKey.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwUnlockFile(proc_t proc, const on_ZwUnlockFile_fn& on_func)
{
    if(d_->observers_ZwUnlockFile.empty())
        if(!register_callback_with(*d_, proc, "_ZwUnlockFile@20", &on_ZwUnlockFile))
            return false;

    d_->observers_ZwUnlockFile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtUnlockVirtualMemory(proc_t proc, const on_NtUnlockVirtualMemory_fn& on_func)
{
    if(d_->observers_NtUnlockVirtualMemory.empty())
        if(!register_callback_with(*d_, proc, "_NtUnlockVirtualMemory@16", &on_NtUnlockVirtualMemory))
            return false;

    d_->observers_NtUnlockVirtualMemory.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtUnmapViewOfSection(proc_t proc, const on_NtUnmapViewOfSection_fn& on_func)
{
    if(d_->observers_NtUnmapViewOfSection.empty())
        if(!register_callback_with(*d_, proc, "_NtUnmapViewOfSection@8", &on_NtUnmapViewOfSection))
            return false;

    d_->observers_NtUnmapViewOfSection.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtVdmControl(proc_t proc, const on_NtVdmControl_fn& on_func)
{
    if(d_->observers_NtVdmControl.empty())
        if(!register_callback_with(*d_, proc, "_NtVdmControl@8", &on_NtVdmControl))
            return false;

    d_->observers_NtVdmControl.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtWaitForDebugEvent(proc_t proc, const on_NtWaitForDebugEvent_fn& on_func)
{
    if(d_->observers_NtWaitForDebugEvent.empty())
        if(!register_callback_with(*d_, proc, "_NtWaitForDebugEvent@16", &on_NtWaitForDebugEvent))
            return false;

    d_->observers_NtWaitForDebugEvent.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtWaitForKeyedEvent(proc_t proc, const on_NtWaitForKeyedEvent_fn& on_func)
{
    if(d_->observers_NtWaitForKeyedEvent.empty())
        if(!register_callback_with(*d_, proc, "_NtWaitForKeyedEvent@16", &on_NtWaitForKeyedEvent))
            return false;

    d_->observers_NtWaitForKeyedEvent.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtWaitForMultipleObjects32(proc_t proc, const on_NtWaitForMultipleObjects32_fn& on_func)
{
    if(d_->observers_NtWaitForMultipleObjects32.empty())
        if(!register_callback_with(*d_, proc, "_NtWaitForMultipleObjects32@20", &on_NtWaitForMultipleObjects32))
            return false;

    d_->observers_NtWaitForMultipleObjects32.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtWaitForMultipleObjects(proc_t proc, const on_NtWaitForMultipleObjects_fn& on_func)
{
    if(d_->observers_NtWaitForMultipleObjects.empty())
        if(!register_callback_with(*d_, proc, "_NtWaitForMultipleObjects@20", &on_NtWaitForMultipleObjects))
            return false;

    d_->observers_NtWaitForMultipleObjects.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwWaitForSingleObject(proc_t proc, const on_ZwWaitForSingleObject_fn& on_func)
{
    if(d_->observers_ZwWaitForSingleObject.empty())
        if(!register_callback_with(*d_, proc, "_ZwWaitForSingleObject@12", &on_ZwWaitForSingleObject))
            return false;

    d_->observers_ZwWaitForSingleObject.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtWaitForWorkViaWorkerFactory(proc_t proc, const on_NtWaitForWorkViaWorkerFactory_fn& on_func)
{
    if(d_->observers_NtWaitForWorkViaWorkerFactory.empty())
        if(!register_callback_with(*d_, proc, "_NtWaitForWorkViaWorkerFactory@8", &on_NtWaitForWorkViaWorkerFactory))
            return false;

    d_->observers_NtWaitForWorkViaWorkerFactory.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwWaitHighEventPair(proc_t proc, const on_ZwWaitHighEventPair_fn& on_func)
{
    if(d_->observers_ZwWaitHighEventPair.empty())
        if(!register_callback_with(*d_, proc, "_ZwWaitHighEventPair@4", &on_ZwWaitHighEventPair))
            return false;

    d_->observers_ZwWaitHighEventPair.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtWaitLowEventPair(proc_t proc, const on_NtWaitLowEventPair_fn& on_func)
{
    if(d_->observers_NtWaitLowEventPair.empty())
        if(!register_callback_with(*d_, proc, "_NtWaitLowEventPair@4", &on_NtWaitLowEventPair))
            return false;

    d_->observers_NtWaitLowEventPair.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtWorkerFactoryWorkerReady(proc_t proc, const on_NtWorkerFactoryWorkerReady_fn& on_func)
{
    if(d_->observers_NtWorkerFactoryWorkerReady.empty())
        if(!register_callback_with(*d_, proc, "_NtWorkerFactoryWorkerReady@4", &on_NtWorkerFactoryWorkerReady))
            return false;

    d_->observers_NtWorkerFactoryWorkerReady.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtWriteFileGather(proc_t proc, const on_NtWriteFileGather_fn& on_func)
{
    if(d_->observers_NtWriteFileGather.empty())
        if(!register_callback_with(*d_, proc, "_NtWriteFileGather@36", &on_NtWriteFileGather))
            return false;

    d_->observers_NtWriteFileGather.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtWriteFile(proc_t proc, const on_NtWriteFile_fn& on_func)
{
    if(d_->observers_NtWriteFile.empty())
        if(!register_callback_with(*d_, proc, "_NtWriteFile@36", &on_NtWriteFile))
            return false;

    d_->observers_NtWriteFile.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtWriteRequestData(proc_t proc, const on_NtWriteRequestData_fn& on_func)
{
    if(d_->observers_NtWriteRequestData.empty())
        if(!register_callback_with(*d_, proc, "_NtWriteRequestData@24", &on_NtWriteRequestData))
            return false;

    d_->observers_NtWriteRequestData.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtWriteVirtualMemory(proc_t proc, const on_NtWriteVirtualMemory_fn& on_func)
{
    if(d_->observers_NtWriteVirtualMemory.empty())
        if(!register_callback_with(*d_, proc, "_NtWriteVirtualMemory@20", &on_NtWriteVirtualMemory))
            return false;

    d_->observers_NtWriteVirtualMemory.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtDisableLastKnownGood(proc_t proc, const on_NtDisableLastKnownGood_fn& on_func)
{
    if(d_->observers_NtDisableLastKnownGood.empty())
        if(!register_callback_with(*d_, proc, "_NtDisableLastKnownGood@0", &on_NtDisableLastKnownGood))
            return false;

    d_->observers_NtDisableLastKnownGood.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtEnableLastKnownGood(proc_t proc, const on_NtEnableLastKnownGood_fn& on_func)
{
    if(d_->observers_NtEnableLastKnownGood.empty())
        if(!register_callback_with(*d_, proc, "_NtEnableLastKnownGood@0", &on_NtEnableLastKnownGood))
            return false;

    d_->observers_NtEnableLastKnownGood.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwFlushProcessWriteBuffers(proc_t proc, const on_ZwFlushProcessWriteBuffers_fn& on_func)
{
    if(d_->observers_ZwFlushProcessWriteBuffers.empty())
        if(!register_callback_with(*d_, proc, "_ZwFlushProcessWriteBuffers@0", &on_ZwFlushProcessWriteBuffers))
            return false;

    d_->observers_ZwFlushProcessWriteBuffers.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtFlushWriteBuffer(proc_t proc, const on_NtFlushWriteBuffer_fn& on_func)
{
    if(d_->observers_NtFlushWriteBuffer.empty())
        if(!register_callback_with(*d_, proc, "_NtFlushWriteBuffer@0", &on_NtFlushWriteBuffer))
            return false;

    d_->observers_NtFlushWriteBuffer.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtGetCurrentProcessorNumber(proc_t proc, const on_NtGetCurrentProcessorNumber_fn& on_func)
{
    if(d_->observers_NtGetCurrentProcessorNumber.empty())
        if(!register_callback_with(*d_, proc, "_NtGetCurrentProcessorNumber@0", &on_NtGetCurrentProcessorNumber))
            return false;

    d_->observers_NtGetCurrentProcessorNumber.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtIsSystemResumeAutomatic(proc_t proc, const on_NtIsSystemResumeAutomatic_fn& on_func)
{
    if(d_->observers_NtIsSystemResumeAutomatic.empty())
        if(!register_callback_with(*d_, proc, "_NtIsSystemResumeAutomatic@0", &on_NtIsSystemResumeAutomatic))
            return false;

    d_->observers_NtIsSystemResumeAutomatic.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwIsUILanguageComitted(proc_t proc, const on_ZwIsUILanguageComitted_fn& on_func)
{
    if(d_->observers_ZwIsUILanguageComitted.empty())
        if(!register_callback_with(*d_, proc, "_ZwIsUILanguageComitted@0", &on_ZwIsUILanguageComitted))
            return false;

    d_->observers_ZwIsUILanguageComitted.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwQueryPortInformationProcess(proc_t proc, const on_ZwQueryPortInformationProcess_fn& on_func)
{
    if(d_->observers_ZwQueryPortInformationProcess.empty())
        if(!register_callback_with(*d_, proc, "_ZwQueryPortInformationProcess@0", &on_ZwQueryPortInformationProcess))
            return false;

    d_->observers_ZwQueryPortInformationProcess.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtSerializeBoot(proc_t proc, const on_NtSerializeBoot_fn& on_func)
{
    if(d_->observers_NtSerializeBoot.empty())
        if(!register_callback_with(*d_, proc, "_NtSerializeBoot@0", &on_NtSerializeBoot))
            return false;

    d_->observers_NtSerializeBoot.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtTestAlert(proc_t proc, const on_NtTestAlert_fn& on_func)
{
    if(d_->observers_NtTestAlert.empty())
        if(!register_callback_with(*d_, proc, "_NtTestAlert@0", &on_NtTestAlert))
            return false;

    d_->observers_NtTestAlert.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwThawRegistry(proc_t proc, const on_ZwThawRegistry_fn& on_func)
{
    if(d_->observers_ZwThawRegistry.empty())
        if(!register_callback_with(*d_, proc, "_ZwThawRegistry@0", &on_ZwThawRegistry))
            return false;

    d_->observers_ZwThawRegistry.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_NtThawTransactions(proc_t proc, const on_NtThawTransactions_fn& on_func)
{
    if(d_->observers_NtThawTransactions.empty())
        if(!register_callback_with(*d_, proc, "_NtThawTransactions@0", &on_NtThawTransactions))
            return false;

    d_->observers_NtThawTransactions.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwUmsThreadYield(proc_t proc, const on_ZwUmsThreadYield_fn& on_func)
{
    if(d_->observers_ZwUmsThreadYield.empty())
        if(!register_callback_with(*d_, proc, "_ZwUmsThreadYield@4", &on_ZwUmsThreadYield))
            return false;

    d_->observers_ZwUmsThreadYield.push_back(on_func);
    return true;
}

bool monitor::syscallswow64::register_ZwYieldExecution(proc_t proc, const on_ZwYieldExecution_fn& on_func)
{
    if(d_->observers_ZwYieldExecution.empty())
        if(!register_callback_with(*d_, proc, "_ZwYieldExecution@0", &on_ZwYieldExecution))
            return false;

    d_->observers_ZwYieldExecution.push_back(on_func);
    return true;
}

namespace
{
    static const char g_names[][64] =
    {
      "_NtAcceptConnectPort@24",
      "_ZwAccessCheckAndAuditAlarm@44",
      "_NtAccessCheckByTypeAndAuditAlarm@64",
      "_NtAccessCheckByType@44",
      "_ZwAccessCheckByTypeResultListAndAuditAlarmByHandle@68",
      "_NtAccessCheckByTypeResultListAndAuditAlarm@64",
      "_NtAccessCheckByTypeResultList@44",
      "_NtAccessCheck@32",
      "_NtAddAtom@12",
      "_ZwAddBootEntry@8",
      "_NtAddDriverEntry@8",
      "_ZwAdjustGroupsToken@24",
      "_ZwAdjustPrivilegesToken@24",
      "_NtAlertResumeThread@8",
      "_NtAlertThread@4",
      "_ZwAllocateLocallyUniqueId@4",
      "_NtAllocateReserveObject@12",
      "_NtAllocateUserPhysicalPages@12",
      "_NtAllocateUuids@16",
      "_NtAllocateVirtualMemory@24",
      "_NtAlpcAcceptConnectPort@36",
      "_ZwAlpcCancelMessage@12",
      "_ZwAlpcConnectPort@44",
      "_ZwAlpcCreatePort@12",
      "_NtAlpcCreatePortSection@24",
      "_ZwAlpcCreateResourceReserve@16",
      "_ZwAlpcCreateSectionView@12",
      "_ZwAlpcCreateSecurityContext@12",
      "_ZwAlpcDeletePortSection@12",
      "_NtAlpcDeleteResourceReserve@12",
      "_NtAlpcDeleteSectionView@12",
      "_NtAlpcDeleteSecurityContext@12",
      "_NtAlpcDisconnectPort@8",
      "_ZwAlpcImpersonateClientOfPort@12",
      "_ZwAlpcOpenSenderProcess@24",
      "_ZwAlpcOpenSenderThread@24",
      "_ZwAlpcQueryInformation@20",
      "_ZwAlpcQueryInformationMessage@24",
      "_NtAlpcRevokeSecurityContext@12",
      "_NtAlpcSendWaitReceivePort@32",
      "_NtAlpcSetInformation@16",
      "_NtApphelpCacheControl@8",
      "_ZwAreMappedFilesTheSame@8",
      "_ZwAssignProcessToJobObject@8",
      "_ZwCallbackReturn@12",
      "_NtCancelIoFileEx@12",
      "_ZwCancelIoFile@8",
      "_NtCancelSynchronousIoFile@12",
      "_ZwCancelTimer@8",
      "_NtClearEvent@4",
      "_NtClose@4",
      "_ZwCloseObjectAuditAlarm@12",
      "_ZwCommitComplete@8",
      "_NtCommitEnlistment@8",
      "_NtCommitTransaction@8",
      "_NtCompactKeys@8",
      "_ZwCompareTokens@12",
      "_NtCompleteConnectPort@4",
      "_ZwCompressKey@4",
      "_NtConnectPort@32",
      "_ZwContinue@8",
      "_ZwCreateDebugObject@16",
      "_ZwCreateDirectoryObject@12",
      "_ZwCreateEnlistment@32",
      "_NtCreateEvent@20",
      "_NtCreateEventPair@12",
      "_NtCreateFile@44",
      "_NtCreateIoCompletion@16",
      "_ZwCreateJobObject@12",
      "_NtCreateJobSet@12",
      "_ZwCreateKeyedEvent@16",
      "_ZwCreateKey@28",
      "_NtCreateKeyTransacted@32",
      "_ZwCreateMailslotFile@32",
      "_ZwCreateMutant@16",
      "_ZwCreateNamedPipeFile@56",
      "_NtCreatePagingFile@16",
      "_ZwCreatePort@20",
      "_NtCreatePrivateNamespace@16",
      "_ZwCreateProcessEx@36",
      "_ZwCreateProcess@32",
      "_NtCreateProfileEx@40",
      "_ZwCreateProfile@36",
      "_ZwCreateResourceManager@28",
      "_NtCreateSection@28",
      "_NtCreateSemaphore@20",
      "_ZwCreateSymbolicLinkObject@16",
      "_NtCreateThreadEx@44",
      "_NtCreateThread@32",
      "_ZwCreateTimer@16",
      "_NtCreateToken@52",
      "_ZwCreateTransactionManager@24",
      "_NtCreateTransaction@40",
      "_NtCreateUserProcess@44",
      "_ZwCreateWaitablePort@20",
      "_NtCreateWorkerFactory@40",
      "_NtDebugActiveProcess@8",
      "_ZwDebugContinue@12",
      "_ZwDelayExecution@8",
      "_ZwDeleteAtom@4",
      "_NtDeleteBootEntry@4",
      "_ZwDeleteDriverEntry@4",
      "_NtDeleteFile@4",
      "_ZwDeleteKey@4",
      "_NtDeleteObjectAuditAlarm@12",
      "_NtDeletePrivateNamespace@4",
      "_NtDeleteValueKey@8",
      "_ZwDeviceIoControlFile@40",
      "_NtDisplayString@4",
      "_ZwDrawText@4",
      "_ZwDuplicateObject@28",
      "_NtDuplicateToken@24",
      "_ZwEnumerateBootEntries@8",
      "_NtEnumerateDriverEntries@8",
      "_ZwEnumerateKey@24",
      "_ZwEnumerateSystemEnvironmentValuesEx@12",
      "_ZwEnumerateTransactionObject@20",
      "_NtEnumerateValueKey@24",
      "_ZwExtendSection@8",
      "_NtFilterToken@24",
      "_NtFindAtom@12",
      "_ZwFlushBuffersFile@8",
      "_ZwFlushInstallUILanguage@8",
      "_ZwFlushInstructionCache@12",
      "_NtFlushKey@4",
      "_ZwFlushVirtualMemory@16",
      "_NtFreeUserPhysicalPages@12",
      "_NtFreeVirtualMemory@16",
      "_NtFreezeRegistry@4",
      "_ZwFreezeTransactions@8",
      "_NtFsControlFile@40",
      "_NtGetContextThread@8",
      "_NtGetDevicePowerState@8",
      "_NtGetMUIRegistryInfo@12",
      "_ZwGetNextProcess@20",
      "_ZwGetNextThread@24",
      "_NtGetNlsSectionPtr@20",
      "_ZwGetNotificationResourceManager@28",
      "_NtGetWriteWatch@28",
      "_NtImpersonateAnonymousToken@4",
      "_ZwImpersonateClientOfPort@8",
      "_ZwImpersonateThread@12",
      "_NtInitializeNlsFiles@12",
      "_ZwInitializeRegistry@4",
      "_NtInitiatePowerAction@16",
      "_ZwIsProcessInJob@8",
      "_ZwListenPort@8",
      "_NtLoadDriver@4",
      "_NtLoadKey2@12",
      "_NtLoadKeyEx@32",
      "_NtLoadKey@8",
      "_NtLockFile@40",
      "_ZwLockProductActivationKeys@8",
      "_NtLockRegistryKey@4",
      "_ZwLockVirtualMemory@16",
      "_ZwMakePermanentObject@4",
      "_NtMakeTemporaryObject@4",
      "_ZwMapCMFModule@24",
      "_NtMapUserPhysicalPages@12",
      "_ZwMapUserPhysicalPagesScatter@12",
      "_ZwMapViewOfSection@40",
      "_NtModifyBootEntry@4",
      "_ZwModifyDriverEntry@4",
      "_NtNotifyChangeDirectoryFile@36",
      "_NtNotifyChangeKey@40",
      "_NtNotifyChangeMultipleKeys@48",
      "_NtNotifyChangeSession@32",
      "_ZwOpenDirectoryObject@12",
      "_ZwOpenEnlistment@20",
      "_NtOpenEvent@12",
      "_NtOpenEventPair@12",
      "_NtOpenFile@24",
      "_ZwOpenIoCompletion@12",
      "_ZwOpenJobObject@12",
      "_NtOpenKeyedEvent@12",
      "_ZwOpenKeyEx@16",
      "_ZwOpenKey@12",
      "_NtOpenKeyTransactedEx@20",
      "_NtOpenKeyTransacted@16",
      "_NtOpenMutant@12",
      "_ZwOpenObjectAuditAlarm@48",
      "_NtOpenPrivateNamespace@16",
      "_ZwOpenProcess@16",
      "_ZwOpenProcessTokenEx@16",
      "_ZwOpenProcessToken@12",
      "_ZwOpenResourceManager@20",
      "_NtOpenSection@12",
      "_NtOpenSemaphore@12",
      "_NtOpenSession@12",
      "_NtOpenSymbolicLinkObject@12",
      "_ZwOpenThread@16",
      "_NtOpenThreadTokenEx@20",
      "_NtOpenThreadToken@16",
      "_ZwOpenTimer@12",
      "_ZwOpenTransactionManager@24",
      "_ZwOpenTransaction@20",
      "_NtPlugPlayControl@12",
      "_ZwPowerInformation@20",
      "_NtPrepareComplete@8",
      "_ZwPrepareEnlistment@8",
      "_ZwPrePrepareComplete@8",
      "_NtPrePrepareEnlistment@8",
      "_ZwPrivilegeCheck@12",
      "_NtPrivilegedServiceAuditAlarm@20",
      "_ZwPrivilegeObjectAuditAlarm@24",
      "_NtPropagationComplete@16",
      "_ZwPropagationFailed@12",
      "_ZwProtectVirtualMemory@20",
      "_ZwPulseEvent@8",
      "_ZwQueryAttributesFile@8",
      "_ZwQueryBootEntryOrder@8",
      "_ZwQueryBootOptions@8",
      "_NtQueryDebugFilterState@8",
      "_NtQueryDefaultLocale@8",
      "_ZwQueryDefaultUILanguage@4",
      "_ZwQueryDirectoryFile@44",
      "_ZwQueryDirectoryObject@28",
      "_NtQueryDriverEntryOrder@8",
      "_ZwQueryEaFile@36",
      "_NtQueryEvent@20",
      "_ZwQueryFullAttributesFile@8",
      "_NtQueryInformationAtom@20",
      "_ZwQueryInformationEnlistment@20",
      "_ZwQueryInformationFile@20",
      "_ZwQueryInformationJobObject@20",
      "_ZwQueryInformationPort@20",
      "_ZwQueryInformationProcess@20",
      "_ZwQueryInformationResourceManager@20",
      "_NtQueryInformationThread@20",
      "_ZwQueryInformationToken@20",
      "_ZwQueryInformationTransaction@20",
      "_NtQueryInformationTransactionManager@20",
      "_ZwQueryInformationWorkerFactory@20",
      "_NtQueryInstallUILanguage@4",
      "_NtQueryIntervalProfile@8",
      "_NtQueryIoCompletion@20",
      "_ZwQueryKey@20",
      "_NtQueryLicenseValue@20",
      "_NtQueryMultipleValueKey@24",
      "_NtQueryMutant@20",
      "_NtQueryObject@20",
      "_NtQueryOpenSubKeysEx@16",
      "_NtQueryOpenSubKeys@8",
      "_NtQueryPerformanceCounter@8",
      "_ZwQueryQuotaInformationFile@36",
      "_ZwQuerySection@20",
      "_ZwQuerySecurityAttributesToken@24",
      "_NtQuerySecurityObject@20",
      "_ZwQuerySemaphore@20",
      "_ZwQuerySymbolicLinkObject@12",
      "_ZwQuerySystemEnvironmentValueEx@20",
      "_ZwQuerySystemEnvironmentValue@16",
      "_ZwQuerySystemInformationEx@24",
      "_NtQuerySystemInformation@16",
      "_NtQuerySystemTime@4",
      "_ZwQueryTimer@20",
      "_NtQueryTimerResolution@12",
      "_ZwQueryValueKey@24",
      "_NtQueryVirtualMemory@24",
      "_NtQueryVolumeInformationFile@20",
      "_NtQueueApcThreadEx@24",
      "_NtQueueApcThread@20",
      "_ZwRaiseException@12",
      "_ZwRaiseHardError@24",
      "_NtReadFile@36",
      "_NtReadFileScatter@36",
      "_ZwReadOnlyEnlistment@8",
      "_ZwReadRequestData@24",
      "_NtReadVirtualMemory@20",
      "_NtRecoverEnlistment@8",
      "_NtRecoverResourceManager@4",
      "_ZwRecoverTransactionManager@4",
      "_ZwRegisterProtocolAddressInformation@20",
      "_ZwRegisterThreadTerminatePort@4",
      "_NtReleaseKeyedEvent@16",
      "_ZwReleaseMutant@8",
      "_NtReleaseSemaphore@12",
      "_ZwReleaseWorkerFactoryWorker@4",
      "_ZwRemoveIoCompletionEx@24",
      "_ZwRemoveIoCompletion@20",
      "_ZwRemoveProcessDebug@8",
      "_ZwRenameKey@8",
      "_NtRenameTransactionManager@8",
      "_ZwReplaceKey@12",
      "_NtReplacePartitionUnit@12",
      "_ZwReplyPort@8",
      "_NtReplyWaitReceivePortEx@20",
      "_NtReplyWaitReceivePort@16",
      "_NtReplyWaitReplyPort@8",
      "_ZwRequestPort@8",
      "_NtRequestWaitReplyPort@12",
      "_NtResetEvent@8",
      "_ZwResetWriteWatch@12",
      "_NtRestoreKey@12",
      "_ZwResumeProcess@4",
      "_ZwResumeThread@8",
      "_ZwRollbackComplete@8",
      "_NtRollbackEnlistment@8",
      "_NtRollbackTransaction@8",
      "_NtRollforwardTransactionManager@8",
      "_NtSaveKeyEx@12",
      "_NtSaveKey@8",
      "_NtSaveMergedKeys@12",
      "_NtSecureConnectPort@36",
      "_ZwSetBootEntryOrder@8",
      "_ZwSetBootOptions@8",
      "_ZwSetContextThread@8",
      "_NtSetDebugFilterState@12",
      "_NtSetDefaultHardErrorPort@4",
      "_NtSetDefaultLocale@8",
      "_ZwSetDefaultUILanguage@4",
      "_NtSetDriverEntryOrder@8",
      "_ZwSetEaFile@16",
      "_NtSetEventBoostPriority@4",
      "_NtSetEvent@8",
      "_NtSetHighEventPair@4",
      "_NtSetHighWaitLowEventPair@4",
      "_ZwSetInformationDebugObject@20",
      "_NtSetInformationEnlistment@16",
      "_ZwSetInformationFile@20",
      "_ZwSetInformationJobObject@16",
      "_ZwSetInformationKey@16",
      "_ZwSetInformationObject@16",
      "_ZwSetInformationProcess@16",
      "_ZwSetInformationResourceManager@16",
      "_ZwSetInformationThread@16",
      "_ZwSetInformationToken@16",
      "_ZwSetInformationTransaction@16",
      "_ZwSetInformationTransactionManager@16",
      "_ZwSetInformationWorkerFactory@16",
      "_NtSetIntervalProfile@8",
      "_NtSetIoCompletionEx@24",
      "_NtSetIoCompletion@20",
      "_ZwSetLdtEntries@24",
      "_ZwSetLowEventPair@4",
      "_ZwSetLowWaitHighEventPair@4",
      "_ZwSetQuotaInformationFile@16",
      "_NtSetSecurityObject@12",
      "_ZwSetSystemEnvironmentValueEx@20",
      "_ZwSetSystemEnvironmentValue@8",
      "_ZwSetSystemInformation@12",
      "_ZwSetSystemPowerState@12",
      "_ZwSetSystemTime@8",
      "_ZwSetThreadExecutionState@8",
      "_ZwSetTimerEx@16",
      "_ZwSetTimer@28",
      "_NtSetTimerResolution@12",
      "_ZwSetUuidSeed@4",
      "_ZwSetValueKey@24",
      "_NtSetVolumeInformationFile@20",
      "_ZwShutdownSystem@4",
      "_NtShutdownWorkerFactory@8",
      "_ZwSignalAndWaitForSingleObject@16",
      "_ZwSinglePhaseReject@8",
      "_NtStartProfile@4",
      "_ZwStopProfile@4",
      "_ZwSuspendProcess@4",
      "_ZwSuspendThread@8",
      "_NtSystemDebugControl@24",
      "_ZwTerminateJobObject@8",
      "_ZwTerminateProcess@8",
      "_ZwTerminateThread@8",
      "_ZwTraceControl@24",
      "_NtTraceEvent@16",
      "_NtTranslateFilePath@16",
      "_ZwUnloadDriver@4",
      "_ZwUnloadKey2@8",
      "_ZwUnloadKeyEx@8",
      "_NtUnloadKey@4",
      "_ZwUnlockFile@20",
      "_NtUnlockVirtualMemory@16",
      "_NtUnmapViewOfSection@8",
      "_NtVdmControl@8",
      "_NtWaitForDebugEvent@16",
      "_NtWaitForKeyedEvent@16",
      "_NtWaitForMultipleObjects32@20",
      "_NtWaitForMultipleObjects@20",
      "_ZwWaitForSingleObject@12",
      "_NtWaitForWorkViaWorkerFactory@8",
      "_ZwWaitHighEventPair@4",
      "_NtWaitLowEventPair@4",
      "_NtWorkerFactoryWorkerReady@4",
      "_NtWriteFileGather@36",
      "_NtWriteFile@36",
      "_NtWriteRequestData@24",
      "_NtWriteVirtualMemory@20",
      "_NtDisableLastKnownGood@0",
      "_NtEnableLastKnownGood@0",
      "_ZwFlushProcessWriteBuffers@0",
      "_NtFlushWriteBuffer@0",
      "_NtGetCurrentProcessorNumber@0",
      "_NtIsSystemResumeAutomatic@0",
      "_ZwIsUILanguageComitted@0",
      "_ZwQueryPortInformationProcess@0",
      "_NtSerializeBoot@0",
      "_NtTestAlert@0",
      "_ZwThawRegistry@0",
      "_NtThawTransactions@0",
      "_ZwUmsThreadYield@4",
      "_ZwYieldExecution@0",
    };
}

bool monitor::syscallswow64::register_all(proc_t proc, const monitor::syscallswow64::on_call_fn& on_call)
{
    Data::Breakpoints breakpoints;
    for(const auto it : g_names)
    {
        const auto bp = register_callback(*d_, proc, it, on_call);
        if(!bp)
            continue;

        breakpoints.emplace_back(bp);
    }

    d_->breakpoints.insert(d_->breakpoints.end(), breakpoints.begin(), breakpoints.end());
    return true;
}
