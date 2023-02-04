@ingroup group_SystemTesting_Documentation

----------------------------
ϵ�y�ⵥԪ����

----------------------------
1.	HelperSuite

��Helperģ��ĵ�Ԫ���ԣ�������
��1�� ���ó����ͺ꣺FixedSizeTesting��
					CompilerConfigTesting��
					PlatformConfigTesting��
					StdLibConfigTesting��
					EndianTesting��
					ConfigMarkTesting��
��2�� �û��꣺UserMacroTesting��
��3�� �ַ���ƴ�Ӻ꣺StringizeMacroTesting�� 
��4�� Unicode�ַ� using ������StringMacroTesting��
							  FileStreamMacroTesting��
							  NullCharTesting��
							  StringStreamMacroTesting��
							  ToStringTesting�� 
��5�� ��ӡ��������Ϣ�꣺PragmaMessageMacroTesting��
��6�� �汾�ţ�VersionTesting��
��7�� ������־�꣺ExportMacroTesting��
��8�� Windowsƽ̨��غ꣺MakeLanguageIDTesting��
						 MakeIntreSourceTesting��
						 MakeLanguageCIDTesting��  
						 HResultTesting��
						 MakeWordTesting��
						 PtrToIntTesting��
						 MarkTesting��
��9�� ��ȫ��ʶ���꣺SecuritySidMacroTesting��
��10������꣺NetworkMacroTesting��
��11��ƽ̨ͷ�ļ���PlatformTesting��
��12��ö�ٵ�ת���������EnumCastTesting��
��13��ö���������EnumAddableTesting��
				  EnumSubtractableTesting��
				  EnumMultiplicationTesting��
				  EnumNegateTesting��
				  EnumIncrementableTesting��
				  EnumDecrementableTesting��
				  EnumAndableTesting��
				  EnumOrableTesting��
				  EnumXorableTesting��
				  EnumShiftableTesting��
��14��Noexcept��NoexceptTesting��
��15��PragmaWarning��PragmaWarningTesting��
��16��gl��չ�꣺GlExtensionsMacroTesting��
				WglExtensionsMacroTesting��
				GlxExtensionsMacroTesting��
				GlPluginMacroTesting��
				GlUtilityMarkTesting��
				GlUtilityGetFunctionTesting��
				GlUtilityPreviouslyBodyTesting��
				GlUtilityPreviouslyBodyResultTesting��
				GlUtilityBodyTesting��
				GlUtilityBodyResultTesting��
��17���ɱ����ģ�����ͣ�VariableTemplateTypeTesting��
��18�����ߣ�GetArraySizeTesting��
			UnusedFunctionTesting��
			DebugTesting��

----------------------------
2.	SystemOutputSuite

��ϵͳ���ģ��ĵ�Ԫ���ԣ������� 
��1�� ��Ϣ���־���ݣ�MessageBoxFlagsDataTesting��
��2�� ����ID���ݣ�LanguageIDDataTesting��
��3�� �����Ϣ��OutputDebugStringTesting��
��4�� ��Ϣ��ѡ��MessageBoxSelectionUseYesNoCancelTesting��
				  MessageBoxSelectionUseFlagsDataTesting��
				  MessageBoxSelectionUseLanguageIDDataTesting��

----------------------------
3.	DynamicLinkSuite 

�Զ�̬����ģ��ĵ�Ԫ���ԣ�������
��1�����ض�̬���ӿ⣺LoadLibraryTesting��
					 GetProcAddressTesting��
					 FreeLibraryTesting��
��2���⹤�ߣ�GetModuleHandleTesting��
			 GetModuleFileNameTesting��
��3����Ŀ¼��LibraryDirectoryTesting��
��4��������Դ���ߣ�FindResourceTesting��
				   LoadResourceTesting��
				   LoadStringTesting��
��5��ö����Դ���ݣ�EnumResourceDataTesting��
��6��ö����Դ���ߣ�EnumResourceToolsTesting��
				   ResourceEnumTesting��

----------------------------
4.	CharacterStringSuite 

���ַ���ģ��ĵ�Ԫ���ԣ�������  
��1�� ��ʽ��������Ϣ��FormatErrorMessageUseLocalAllocTesting��
					  FormatErrorMessageUseBufferTesting��
					  FormatErrorMessageUseDllMoudleAndLocalAllocTesting��
					  FormatErrorMessageUseDllMoudleAndUseBufferTesting��
					  FormatErrorMessageReturnStringTesting��
					  FormatErrorMessageTesting��
					  FormatStringMessageUseArgumentArrayAndLocalAllocTesting��
					  FormatStringMessageUseArgumentArrayAndBufferTesting��
					  FormatStringMessageUseVaListAndLocalAllocTesting��
					  FormatStringMessageUseVaListAndUseBufferTesting��
					  SoftwareExceptionTesting��
					  FormatErrorMessageParameterTesting��
��2�� ����ҳ��CodePageValidTesting��
			  CodePageTesting��
			  LocaleTesting��
��3�� �ַ�ת����MultiByteConversionWideCharTesting��
				WideCharConversionMultiByteTesting��
				UTF8ConversionWideCharTesting��
			    WideCharConversionUTF8Testing��
				CompareStringUseLocaleFlagsTesting��
				CompareStringUseLocaleStringTesting��
				CompareStringOrdinalUseBinaryTesting��
				CaseInsensitiveComparisonTesting��
��4�� ��ʽ���ַ�����VsnPrintfTesting��
					StrcatTesting��
					StrlenTesting��
					StrcpyTesting��
					StrtokTesting��
					StrstrTesting��
					SNPrintfTesting�� 

----------------------------
5.	ConsoleSuite 

�Կ���̨ģ��ĵ�Ԫ���ԣ�������
��1�� ����̨�����ConsoleHandleTesting�� 
��2�� ����̨��ɫ��TextColourTesting��
				  BackgroundColourTesting��
				  ConsoleCommonTesting��
				  DefaultTextAttributeTesting�� 
			      ReadAttributeTesting ��
				  WriteAttributeTesting��
				  FillAttributeTesting��
��3�� ����̨��Ļ��������CreateSystemConsoleScreenBufferTesting��
						ConsoleScreenBufferInfoTesting��
						SetConsoleHandleScreenBufferInfoTesting��
						SetSystemConsoleScreenBufferSizeTesting��
��4�� ����̨���壺ConsoleFontSizeTesting��
				  CurrentConsoleFontTesting��
				  SetCurrentConsoleFontTesting�� 
��5�� ����̨ģʽ��ConsoleOutputModeTesting��
				  ConsoleInputModeTesting�� 
��6�� ����̨����ҳ��ConsoleCodePageTesting�� 
��7�� ����̨������ConsoleCreateTesting�� 

----------------------------
6.	MemoryToolsSuite 

���ڴ湤��ģ��ĵ�Ԫ���ԣ������� 
��1�� �ѣ�CreateHeapTesting��
		  AllocateHeapTesting��
		  AllocateGenerateExceptionsTesting��
		  ReAllocateHeapTesting��
		  ValidateHeapTesting��
		  CompactHeapTesting��
		  CurrentProcessHeapTesting ��
��2�� �����ڴ棺AllocateVirtualOneStepTesting��
				AllocateVirtualSeparationTesting��
				VirtualProtectTesting��
				VirtualQueryTesting��
��3�� �ļ�ӳ��ϵͳ��CreateFileMappingTesting��
					OpenFileMappingTesting��
					ViewOfFileTesting��
��4�� �ڴ湤�ߣ�MemorySetTesting��
				MemoryCopyTesting��
				MallocMemoryTesting��
				FillMemoryTesting��
				GetWindowsStructDefaultSizeTesting��
��5�� �ֲ��ڴ棺LocalMemoryAllocTesting��
				LocalMemorySizeTesting��
 
----------------------------
7.	ThreadingSuite
 
���߳�ģ��ĵ�Ԫ���ԣ������� 
��1�� �ٽ�����CriticalSectionTesting��
			  CriticalSectionThreadTesting��
			  SpecifyCriticalSectionTesting��
			  SpecifyCriticalSectionAndSpinCountTesting��
��2�� �ź�����CreateSemaphoreThreadTesting��
			  CreateSemaphoreThreadUseNameTesting��
			  ReleaseSemaphoreTesting��
			  WaitSemaphoreTesting��
			  WaitMultipleSemaphoreTesting��
			  OpenSemaphoreTesting��
��3�� �¼�����CreateEventTesting��
				CreateEventUseNameTesting��
				ManualEventThreadTesting��
				AutoEventThreadTesting��
				ResetEventTesting��
				WaitForEventTesting��
				WaitForMultipleEventTesting��
				OpenEventTesting��
��4�� ��������CreateDefaultMutexTesting��
			  CreateMutexTesting��
			  CreateMutexUseFlagsTesting��
			  CreateMutexUseNameTesting��
			  ThreadMutexTesting��
			  WaitForMutexTesting��
			  WaitForMultipleMutexTesting��
			  OpenMutexTesting��
			  PThreadMutexTesting��
��5�� ��д����SlimReaderWriterInitializeTesting��
	          SlimReaderWriterReaderTesting��
			  SlimReaderWriterWriterTesting��
��6�� ����������ConditionVariableCriticalSectionTesting��
				ConditionVariableSlimReaderWriterLockTesting��
��7�� һ�ζ���InitOnceSynchronousTesting��
				InitOnceAsynchronousTesting��
��8�� �ȴ���ʱ����CreateWaitableTimerManualTesting��
				  CreateWaitableTimerSynchronizationTesting��
				  CreateWaitableTimerUseNameTesting��
				  CreateWaitableTimerManualUseFlagsTesting��
				  CreateWaitableTimerSynchronizationUseFlagsTesting��
				  OpenWaitableTimerTesting��
				  WaitForWaitableTimerTesting��
				  WaitForMultipleWaitableTimerTesting��
				  CancelWaitableTimerTesting��
				  SetWaitableTimerTesting��
��9�� ͬ�����ߣ�SleepTesting��
				SignalObjectAndWaitTesting��
��10��ԭ�Ӳ�����InterlockedTesting��
				InterlockedSubtractTesting��
				InterlockedBinaryTesting��
��11���̣߳�CreateDefaultThreadTesting��
			CreateSuspendedThreadTesting��
			CreateCThreadTesting��
			GetCurrentThreadTesting��
		    ThreadPriorityTesting��
			WaitForThreadTesting��
			WaitForMultipleThreadTesting��
��12���̸߳������ߣ�OpenThreadTesting��
					PriorityBoostTesting��
					ThreadTimesTesting��
					ThreadTokenTesting��
��13���ֲ߳̾��洢��ThreadLocalStorageTesting��
��14�����̣�CreateDefaultProcessTesting��
			CreateProcessTesting��
			GetProcessHandleTesting��
			ProcessPriorityClassTesting��
			OpenProcessTesting��
			ExitProcessTesting��
��15�����̹��ߣ�ProcessTokenTesting��

----------------------------
8.	TimeSuite 

��ʱ��ģ��ĵ�Ԫ���ԣ�������
��1�� ʱ�䣺CurrentDeltaTimeTesting��
��2�� ���ʱ��ֵ��DeltaTimeValueDataTesting��
��3�� ���ʱ�䣺DeltaTimeTesting�� 
��4�� ��ͣ����̨��SystemPauseTesting��

----------------------------
9.	FileManagerSuite 
 
���ļ�����ģ��ĵ�Ԫ���ԣ�������
��1�� C�����ļ�ϵͳ��CFileOpenTesting��
					 CFileWriteReadTesting��
					 CFileSetVBufferTesting��
					 CFileCharacterTesting��
					 CFileOperatorTesting��
��2�� �����ļ�ϵͳ��CreateExistingFileTesting��
					CreateFileWithDefaultAttributesTesting��
					CreateFileWithOtherFlagsTesting��
					CreateFileWithSecurityFlagsTesting��
					CreateFileWithAttributesTesting��
					DirectoryTesting��					
					MoveFileTesting��
					FileLengthTesting��
					CopyFileTesting��
					FileHandlePointerTesting��
					OpenFileTesting��
					ReadFileTesting��
					ReadFileUseOverlappedTesting��
					ReadFileUseCompletionRoutineTesting��
					WriteFileTesting��
					WriteFileUseCompletionRoutineTesting��
					WriteFileUseOverlappedTesting��
					AppendFileTesting��
��3�� �������ߣ�CreateDirectoryTesting��
				DiskFreeTesting��
��4�� �ļ�ʱ�䣺FileTimeCompareTesting��
				FileTimeConvertTesting��
				FileTimeTesting�� 
��5�� ����������EnvironmentVariableTesting�� 

----------------------------
10.	SecuritySuite
 
�԰�ȫ��ģ��ĵ�Ԫ���ԣ�������
��1�� ����Ȩ�ޣ�GetLookupPrivilegeDisplayNameTesting��
			    GetLookupPrivilegeNameTesting��
				GetLookupPrivilegeValueTesting�� 
��2�� ������ȫ�ԣ�FileSecurityTesting��
				  KernelObjectSecurityTesting��
				  CreatePrivateObjectSecurityTesting��
				  CreateFilePrivateObjectSecurityTesting��
				  CreatePrivateObjectSecurityUseAutoInheritTesting��
				  CreatePrivateObjectSecurityWithMultipleInheritanceTesting��
				  SetPrivateObjectSecurityTesting��
				  ConvertToAutoInheritPrivateObjectSecurityTesting��
				  SecurityAccessMaskTesting��
��3�� ��ȫ�Ա�ʶ����InitializeSecurityIdentifierTesting��
					AllocateAndInitializeSecurityIdentifierTesting��
					GetSubAuthorityTesting��
					WellKnownSidTesting��
					CopySecurityIdentifierTesting�� 
��4�� ���ʿ����б�InitializeAclTesting��
					AclInformationTesting�� 
��5�� ��ȫ��������UserObjectSecurityTesting��
				  InitializeSecurityDescriptorTesting��
				  SecurityDescriptorDiscretionaryAccessControlListTesting��
				  SecurityDescriptorControlTesting��
				  SecurityDescriptorGroupTesting��
				  SecurityDescriptorOwnerTesting��
				  SecurityDescriptorResourceManagerControlTesting��
				  SecurityDescriptorSystemAccessControlListTesting�� 
��6�� ���ʿ����AddAccessControlEntriesTesting��
				  FindFirstFreeAccessControlEntriesTesting��
				  AddMandatoryAceTesting��
��7�� ��ӷ���Ȩ�ޣ�AddAccessAllowedAceTesting��
				    AddAccessAllowedAceUseAceFlagsTesting��
					AddAccessAllowedObjectAceTesting��
					AddAccessDeniedAceTesting��
					AddAccessDeniedObjectAceTesting��
					AddAuditAccessAceTesting��
					AddAuditAccessObjectAceTesting��
��8�� ��ȫ������TokenInformationTesting��
				AdjustTokenPrivilegesTesting��
				AdjustTokenGroupsTesting��
				AccessesGrantedEnlistmentMapTesting��
				AccessesGrantedFileMapTesting��
				AccessesGrantedResourceManagerMapTesting��
				AccessesGrantedTransactionManagerMapTesting��
				AccessesGrantedTransactionMapTesting��
				DuplicateTokenTesting��
				RestrictedTokenTesting��
				QuerySecurityAccessMaskTesting��
��9�� ���ʼ�飺MapGenericMaskTesting��
				EnlistmentMapGenericMaskTesting��
				FileMapGenericMaskTesting��
				ResourceManagerMapGenericMaskTesting��
				TransactionManagerMapGenericMaskTesting��
				TransactionMapGenericMaskTesting��
				AccessCheckTesting��
				AccessCheckByTypeResultListTesting��
				AccessCheckByTypeTesting��

----------------------------
11.	NetworkSuite 

������ģ��ĵ�Ԫ���ԣ�������
��1�� �׽���ԭ�ͣ�GetSocketTesting��
				  HostNetConversionTesting��
				  AcceptTesting��
				  ConnectTesting��
				  SocketNameTesting��
				  SockOptionTesting��
				  IoctlSocketTesting��
				  ShutDownTesting�� 
				  RecvFromTesting��
				  SendToTesting��
				  SelectTesting�� 
��2�� ����ԭ�ͣ�WinSockHostTesting��
				WinSockServentTesting��
				WinSockProtoentTesting��
��3�� Windows��չԭ�ͣ�WindowsExtensionPrototypesTesting��
��4�� Windows�׽��֣� GetWinSocketTesting��
					  WinSocketAcceptTesting��
					  WinSocketConnectTesting��
					  WinSocketConnectByNameTesting��
					  WinSocketHostNetConversionTesting��
					  WinSocketRecvFromTesting��
					  WinSocketSendToTesting��   

----------------------------
12.	OpenGLSuite 

��OpenGLģ��ĵ�Ԫ���ԣ�������
��1�� OpenGL���ߣ�OpenGLUtilityTesting��
��2�� OpenGL��ʼ����OpenGLInitTesting��
��3�� OpenGL Base��OpenGLBaseTesting��
��4�� OpenGL ��������OpenGLBuffersTesting��
��5�� OpenGL ����OpenGLTexturesTesting��
��6�� OpenGL Polygon��OpenGLPolygonTesting��
��7�� OpenGL Samplers��OpenGLSamplersTesting��
��8�� OpenGL Program��OpenGLProgramTesting��
��9�� OpenGL Shader��OpenGLShaderTesting��
��10��GLUT��OpenGLGlutTesting��
��11��OpenGL Wgl ԭ�ͣ�OpenGLWglPrototypesTesting��  

----------------------------
13.	DirectXSuite 

��DirectXģ��ĵ�Ԫ���ԣ�������
��1�� DirectXD3D11��DirectXD3D11Testing�� 

----------------------------
14.	VulkanSuite 

��Vulkanģ��ĵ�Ԫ���ԣ�������
��1�� Vulkan��VulkanTesting�� 

----------------------------
15.	WindowsSuite 

��Windowsģ��ĵ�Ԫ���ԣ�������
��1�� ϵͳ�����룺LastWindowErrorTesting��
��2�� Window������WindowsCreateLParamTesting��
				  WindowsCreateWParamTesting��
��3�� Window���̣�WindowsProcessTesting��
��4�� Windowע�᣺WindowsRegisterTesting��
��5�� Window������Ϣ��WindowsFontInformationTesting��
��6�� Windowϵͳ��GetSystemInfoTesting��
				  DebugBreakTesting��
				  ExitTesting��
				  SystemCommandTesting��
				  SystemDirectoryTesting��
				  GetSystemUserNameTesting��
				  BoolConversionTesting��
				  GetSystemInputTesting��
��7�� Window���ֹܵ���WindowsNamedPipeTesting��
��8�� Window�û���WindowsUserTesting��
��9�� Engineering��EngineeringNumDigitsTesting��
				   EngineeringOffsetTesting��
				   EngineeringSuffixTesting��
				   EngineeringTypeDisplayerTesting��
				   GetLastSlashPositionTesting��  

----------------------------
16.	LinuxSuite 

��Linuxģ��ĵ�Ԫ���ԣ�������
��1�� Linuxԭ�����ڣ�LinuxNativeWindowTesting��

----------------------------
17.	MacintoshSuite 

��Macintoshģ��ĵ�Ԫ���ԣ�������
��1�� Macintoshԭ�����ڣ�MacintoshNativeWindowTesting��

----------------------------
18.	AndroidSuite

��Androidģ��ĵ�Ԫ���ԣ�������
��1�� ��׿������¼���AndroidInputKeyEventFacadeTesting��  
��2�� ��׿��������¼���AndroidInputMotionEventFacadeTesting��  
��3�� ��׿ѭ����AndroidLooperTesting��
��4�� ��׿������У�AndroidInputQueueFacadeTesting�� 
��5�� ��׿���ڣ�AndroidNativeWindowFacadeTesting��
��6�� ��׿Ӧ�ó���AndroidNativeAppGlueTesting��

----------------------------