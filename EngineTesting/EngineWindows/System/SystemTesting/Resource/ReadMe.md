@ingroup group_SystemTesting_Documentation

----------------------------
系統库单元测试

----------------------------
1.	HelperSuite

对Helper模块的单元测试，包括：
（1） 配置常量和宏：FixedSizeTesting、
					CompilerConfigTesting、
					PlatformConfigTesting、
					StdLibConfigTesting、
					EndianTesting、
					ConfigMarkTesting。
（2） 用户宏：UserMacroTesting。
（3） 字符串拼接宏：StringizeMacroTesting。 
（4） Unicode字符 using 声明：StringMacroTesting、
							  FileStreamMacroTesting、
							  NullCharTesting、
							  StringStreamMacroTesting、
							  ToStringTesting。 
（5） 打印编译器信息宏：PragmaMessageMacroTesting。
（6） 版本号：VersionTesting。
（7） 导出标志宏：ExportMacroTesting。
（8） Windows平台相关宏：MakeLanguageIDTesting、
						 MakeIntreSourceTesting、
						 MakeLanguageCIDTesting、  
						 HResultTesting、
						 MakeWordTesting、
						 PtrToIntTesting、
						 MarkTesting。
（9） 安全标识符宏：SecuritySidMacroTesting。
（10）网络宏：NetworkMacroTesting。
（11）平台头文件：PlatformTesting。
（12）枚举的转换运算符：EnumCastTesting。
（13）枚举运算符：EnumAddableTesting、
				  EnumSubtractableTesting、
				  EnumMultiplicationTesting、
				  EnumNegateTesting、
				  EnumIncrementableTesting、
				  EnumDecrementableTesting、
				  EnumAndableTesting、
				  EnumOrableTesting、
				  EnumXorableTesting、
				  EnumShiftableTesting。
（14）Noexcept：NoexceptTesting。
（15）PragmaWarning：PragmaWarningTesting。
（16）gl扩展宏：GlExtensionsMacroTesting、
				WglExtensionsMacroTesting、
				GlxExtensionsMacroTesting、
				GlPluginMacroTesting、
				GlUtilityMarkTesting、
				GlUtilityGetFunctionTesting、
				GlUtilityPreviouslyBodyTesting、
				GlUtilityPreviouslyBodyResultTesting、
				GlUtilityBodyTesting、
				GlUtilityBodyResultTesting。
（17）可变参数模板类型：VariableTemplateTypeTesting。
（18）工具：GetArraySizeTesting、
			UnusedFunctionTesting、
			DebugTesting。

----------------------------
2.	SystemOutputSuite

对系统输出模块的单元测试，包括： 
（1） 消息框标志数据：MessageBoxFlagsDataTesting。
（2） 语言ID数据：LanguageIDDataTesting。
（3） 输出信息：OutputDebugStringTesting。
（4） 消息框选择：MessageBoxSelectionUseYesNoCancelTesting、
				  MessageBoxSelectionUseFlagsDataTesting、
				  MessageBoxSelectionUseLanguageIDDataTesting。

----------------------------
3.	DynamicLinkSuite 

对动态链接模块的单元测试，包括：
（1）加载动态链接库：LoadLibraryTesting、
					 GetProcAddressTesting、
					 FreeLibraryTesting。
（2）库工具：GetModuleHandleTesting、
			 GetModuleFileNameTesting。
（3）库目录：LibraryDirectoryTesting。
（4）加载资源工具：FindResourceTesting、
				   LoadResourceTesting、
				   LoadStringTesting。
（5）枚举资源数据：EnumResourceDataTesting。
（6）枚举资源工具：EnumResourceToolsTesting、
				   ResourceEnumTesting。

----------------------------
4.	CharacterStringSuite 

对字符串模块的单元测试，包括：  
（1） 格式化错误消息：FormatErrorMessageUseLocalAllocTesting、
					  FormatErrorMessageUseBufferTesting、
					  FormatErrorMessageUseDllMoudleAndLocalAllocTesting、
					  FormatErrorMessageUseDllMoudleAndUseBufferTesting、
					  FormatErrorMessageReturnStringTesting、
					  FormatErrorMessageTesting、
					  FormatStringMessageUseArgumentArrayAndLocalAllocTesting、
					  FormatStringMessageUseArgumentArrayAndBufferTesting、
					  FormatStringMessageUseVaListAndLocalAllocTesting、
					  FormatStringMessageUseVaListAndUseBufferTesting、
					  SoftwareExceptionTesting、
					  FormatErrorMessageParameterTesting。
（2） 代码页：CodePageValidTesting、
			  CodePageTesting、
			  LocaleTesting。
（3） 字符转换：MultiByteConversionWideCharTesting、
				WideCharConversionMultiByteTesting、
				UTF8ConversionWideCharTesting、
			    WideCharConversionUTF8Testing、
				CompareStringUseLocaleFlagsTesting、
				CompareStringUseLocaleStringTesting、
				CompareStringOrdinalUseBinaryTesting、
				CaseInsensitiveComparisonTesting。
（4） 格式化字符串：VsnPrintfTesting、
					StrcatTesting、
					StrlenTesting、
					StrcpyTesting、
					StrtokTesting、
					StrstrTesting、
					SNPrintfTesting。 

----------------------------
5.	ConsoleSuite 

对控制台模块的单元测试，包括：
（1） 控制台句柄：ConsoleHandleTesting。 
（2） 控制台颜色：TextColourTesting、
				  BackgroundColourTesting、
				  ConsoleCommonTesting、
				  DefaultTextAttributeTesting、 
			      ReadAttributeTesting 、
				  WriteAttributeTesting、
				  FillAttributeTesting。
（3） 控制台屏幕缓冲区：CreateSystemConsoleScreenBufferTesting、
						ConsoleScreenBufferInfoTesting、
						SetConsoleHandleScreenBufferInfoTesting、
						SetSystemConsoleScreenBufferSizeTesting。
（4） 控制台字体：ConsoleFontSizeTesting、
				  CurrentConsoleFontTesting、
				  SetCurrentConsoleFontTesting。 
（5） 控制台模式：ConsoleOutputModeTesting、
				  ConsoleInputModeTesting。 
（6） 控制台代码页：ConsoleCodePageTesting。 
（7） 控制台创建：ConsoleCreateTesting。 

----------------------------
6.	MemoryToolsSuite 

对内存工具模块的单元测试，包括： 
（1） 堆：CreateHeapTesting、
		  AllocateHeapTesting、
		  AllocateGenerateExceptionsTesting、
		  ReAllocateHeapTesting、
		  ValidateHeapTesting、
		  CompactHeapTesting、
		  CurrentProcessHeapTesting 。
（2） 虚拟内存：AllocateVirtualOneStepTesting、
				AllocateVirtualSeparationTesting、
				VirtualProtectTesting、
				VirtualQueryTesting。
（3） 文件映射系统：CreateFileMappingTesting、
					OpenFileMappingTesting、
					ViewOfFileTesting。
（4） 内存工具：MemorySetTesting、
				MemoryCopyTesting、
				MallocMemoryTesting、
				FillMemoryTesting、
				GetWindowsStructDefaultSizeTesting。
（5） 局部内存：LocalMemoryAllocTesting、
				LocalMemorySizeTesting。
 
----------------------------
7.	ThreadingSuite
 
对线程模块的单元测试，包括： 
（1） 临界区：CriticalSectionTesting、
			  CriticalSectionThreadTesting、
			  SpecifyCriticalSectionTesting、
			  SpecifyCriticalSectionAndSpinCountTesting。
（2） 信号量：CreateSemaphoreThreadTesting、
			  CreateSemaphoreThreadUseNameTesting、
			  ReleaseSemaphoreTesting、
			  WaitSemaphoreTesting、
			  WaitMultipleSemaphoreTesting、
			  OpenSemaphoreTesting。
（3） 事件对象：CreateEventTesting、
				CreateEventUseNameTesting、
				ManualEventThreadTesting、
				AutoEventThreadTesting、
				ResetEventTesting、
				WaitForEventTesting、
				WaitForMultipleEventTesting、
				OpenEventTesting。
（4） 互斥锁：CreateDefaultMutexTesting、
			  CreateMutexTesting、
			  CreateMutexUseFlagsTesting、
			  CreateMutexUseNameTesting、
			  ThreadMutexTesting、
			  WaitForMutexTesting、
			  WaitForMultipleMutexTesting、
			  OpenMutexTesting、
			  PThreadMutexTesting。
（5） 读写锁：SlimReaderWriterInitializeTesting、
	          SlimReaderWriterReaderTesting、
			  SlimReaderWriterWriterTesting。
（6） 条件变量：ConditionVariableCriticalSectionTesting、
				ConditionVariableSlimReaderWriterLockTesting。
（7） 一次对象：InitOnceSynchronousTesting、
				InitOnceAsynchronousTesting。
（8） 等待计时器：CreateWaitableTimerManualTesting、
				  CreateWaitableTimerSynchronizationTesting、
				  CreateWaitableTimerUseNameTesting、
				  CreateWaitableTimerManualUseFlagsTesting、
				  CreateWaitableTimerSynchronizationUseFlagsTesting、
				  OpenWaitableTimerTesting、
				  WaitForWaitableTimerTesting、
				  WaitForMultipleWaitableTimerTesting、
				  CancelWaitableTimerTesting、
				  SetWaitableTimerTesting。
（9） 同步工具：SleepTesting、
				SignalObjectAndWaitTesting。
（10）原子操作：InterlockedTesting、
				InterlockedSubtractTesting、
				InterlockedBinaryTesting。
（11）线程：CreateDefaultThreadTesting、
			CreateSuspendedThreadTesting、
			CreateCThreadTesting、
			GetCurrentThreadTesting、
		    ThreadPriorityTesting、
			WaitForThreadTesting、
			WaitForMultipleThreadTesting。
（12）线程辅助工具：OpenThreadTesting、
					PriorityBoostTesting、
					ThreadTimesTesting、
					ThreadTokenTesting。
（13）线程局部存储：ThreadLocalStorageTesting。
（14）进程：CreateDefaultProcessTesting、
			CreateProcessTesting、
			GetProcessHandleTesting、
			ProcessPriorityClassTesting、
			OpenProcessTesting、
			ExitProcessTesting。
（15）进程工具：ProcessTokenTesting。

----------------------------
8.	TimeSuite 

对时间模块的单元测试，包括：
（1） 时间：CurrentDeltaTimeTesting。
（2） 间隔时间值：DeltaTimeValueDataTesting。
（3） 间隔时间：DeltaTimeTesting。 
（4） 暂停控制台：SystemPauseTesting。

----------------------------
9.	FileManagerSuite 
 
对文件管理模块的单元测试，包括：
（1） C函数文件系统：CFileOpenTesting、
					 CFileWriteReadTesting、
					 CFileSetVBufferTesting、
					 CFileCharacterTesting、
					 CFileOperatorTesting。
（2） 基础文件系统：CreateExistingFileTesting、
					CreateFileWithDefaultAttributesTesting、
					CreateFileWithOtherFlagsTesting、
					CreateFileWithSecurityFlagsTesting、
					CreateFileWithAttributesTesting、
					DirectoryTesting、					
					MoveFileTesting、
					FileLengthTesting、
					CopyFileTesting、
					FileHandlePointerTesting、
					OpenFileTesting、
					ReadFileTesting、
					ReadFileUseOverlappedTesting、
					ReadFileUseCompletionRoutineTesting、
					WriteFileTesting、
					WriteFileUseCompletionRoutineTesting、
					WriteFileUseOverlappedTesting、
					AppendFileTesting。
（3） 辅助工具：CreateDirectoryTesting、
				DiskFreeTesting。
（4） 文件时间：FileTimeCompareTesting、
				FileTimeConvertTesting、
				FileTimeTesting。 
（5） 环境变量：EnvironmentVariableTesting。 

----------------------------
10.	SecuritySuite
 
对安全性模块的单元测试，包括：
（1） 查找权限：GetLookupPrivilegeDisplayNameTesting、
			    GetLookupPrivilegeNameTesting、
				GetLookupPrivilegeValueTesting。 
（2） 创建安全性：FileSecurityTesting、
				  KernelObjectSecurityTesting、
				  CreatePrivateObjectSecurityTesting、
				  CreateFilePrivateObjectSecurityTesting、
				  CreatePrivateObjectSecurityUseAutoInheritTesting、
				  CreatePrivateObjectSecurityWithMultipleInheritanceTesting、
				  SetPrivateObjectSecurityTesting、
				  ConvertToAutoInheritPrivateObjectSecurityTesting、
				  SecurityAccessMaskTesting。
（3） 安全性标识符：InitializeSecurityIdentifierTesting、
					AllocateAndInitializeSecurityIdentifierTesting、
					GetSubAuthorityTesting、
					WellKnownSidTesting、
					CopySecurityIdentifierTesting。 
（4） 访问控制列表：InitializeAclTesting、
					AclInformationTesting。 
（5） 安全描述符：UserObjectSecurityTesting、
				  InitializeSecurityDescriptorTesting、
				  SecurityDescriptorDiscretionaryAccessControlListTesting、
				  SecurityDescriptorControlTesting、
				  SecurityDescriptorGroupTesting、
				  SecurityDescriptorOwnerTesting、
				  SecurityDescriptorResourceManagerControlTesting、
				  SecurityDescriptorSystemAccessControlListTesting。 
（6） 访问控制项：AddAccessControlEntriesTesting、
				  FindFirstFreeAccessControlEntriesTesting、
				  AddMandatoryAceTesting。
（7） 添加访问权限：AddAccessAllowedAceTesting、
				    AddAccessAllowedAceUseAceFlagsTesting、
					AddAccessAllowedObjectAceTesting、
					AddAccessDeniedAceTesting、
					AddAccessDeniedObjectAceTesting、
					AddAuditAccessAceTesting、
					AddAuditAccessObjectAceTesting。
（8） 安全基础：TokenInformationTesting、
				AdjustTokenPrivilegesTesting、
				AdjustTokenGroupsTesting、
				AccessesGrantedEnlistmentMapTesting、
				AccessesGrantedFileMapTesting、
				AccessesGrantedResourceManagerMapTesting、
				AccessesGrantedTransactionManagerMapTesting、
				AccessesGrantedTransactionMapTesting、
				DuplicateTokenTesting、
				RestrictedTokenTesting、
				QuerySecurityAccessMaskTesting。
（9） 访问检查：MapGenericMaskTesting、
				EnlistmentMapGenericMaskTesting、
				FileMapGenericMaskTesting、
				ResourceManagerMapGenericMaskTesting、
				TransactionManagerMapGenericMaskTesting、
				TransactionMapGenericMaskTesting、
				AccessCheckTesting、
				AccessCheckByTypeResultListTesting、
				AccessCheckByTypeTesting。

----------------------------
11.	NetworkSuite 

对网络模块的单元测试，包括：
（1） 套接字原型：GetSocketTesting、
				  HostNetConversionTesting、
				  AcceptTesting、
				  ConnectTesting、
				  SocketNameTesting、
				  SockOptionTesting、
				  IoctlSocketTesting、
				  ShutDownTesting、 
				  RecvFromTesting、
				  SendToTesting、
				  SelectTesting。 
（2） 数据原型：WinSockHostTesting、
				WinSockServentTesting、
				WinSockProtoentTesting。
（3） Windows扩展原型：WindowsExtensionPrototypesTesting。
（4） Windows套接字： GetWinSocketTesting、
					  WinSocketAcceptTesting、
					  WinSocketConnectTesting、
					  WinSocketConnectByNameTesting、
					  WinSocketHostNetConversionTesting、
					  WinSocketRecvFromTesting、
					  WinSocketSendToTesting。   

----------------------------
12.	OpenGLSuite 

对OpenGL模块的单元测试，包括：
（1） OpenGL工具：OpenGLUtilityTesting。
（2） OpenGL初始化：OpenGLInitTesting。
（3） OpenGL Base：OpenGLBaseTesting。
（4） OpenGL 缓冲区：OpenGLBuffersTesting。
（5） OpenGL 纹理：OpenGLTexturesTesting。
（6） OpenGL Polygon：OpenGLPolygonTesting。
（7） OpenGL Samplers：OpenGLSamplersTesting。
（8） OpenGL Program：OpenGLProgramTesting。
（9） OpenGL Shader：OpenGLShaderTesting。
（10）GLUT：OpenGLGlutTesting。
（11）OpenGL Wgl 原型：OpenGLWglPrototypesTesting。  

----------------------------
13.	DirectXSuite 

对DirectX模块的单元测试，包括：
（1） DirectXD3D11：DirectXD3D11Testing。 

----------------------------
14.	VulkanSuite 

对Vulkan模块的单元测试，包括：
（1） Vulkan：VulkanTesting。 

----------------------------
15.	WindowsSuite 

对Windows模块的单元测试，包括：
（1） 系统错误码：LastWindowErrorTesting。
（2） Window创建：WindowsCreateLParamTesting、
				  WindowsCreateWParamTesting。
（3） Window进程：WindowsProcessTesting。
（4） Window注册：WindowsRegisterTesting。
（5） Window字体信息：WindowsFontInformationTesting。
（6） Window系统：GetSystemInfoTesting、
				  DebugBreakTesting、
				  ExitTesting、
				  SystemCommandTesting、
				  SystemDirectoryTesting、
				  GetSystemUserNameTesting、
				  BoolConversionTesting、
				  GetSystemInputTesting。
（7） Window名字管道：WindowsNamedPipeTesting。
（8） Window用户：WindowsUserTesting。
（9） Engineering：EngineeringNumDigitsTesting、
				   EngineeringOffsetTesting、
				   EngineeringSuffixTesting、
				   EngineeringTypeDisplayerTesting、
				   GetLastSlashPositionTesting。  

----------------------------
16.	LinuxSuite 

对Linux模块的单元测试，包括：
（1） Linux原生窗口：LinuxNativeWindowTesting。

----------------------------
17.	MacintoshSuite 

对Macintosh模块的单元测试，包括：
（1） Macintosh原生窗口：MacintoshNativeWindowTesting。

----------------------------
18.	AndroidSuite

对Android模块的单元测试，包括：
（1） 安卓输入键事件：AndroidInputKeyEventFacadeTesting。  
（2） 安卓输入滚动事件：AndroidInputMotionEventFacadeTesting。  
（3） 安卓循环：AndroidLooperTesting。
（4） 安卓输入队列：AndroidInputQueueFacadeTesting。 
（5） 安卓窗口：AndroidNativeWindowFacadeTesting。
（6） 安卓应用程序：AndroidNativeAppGlueTesting。

----------------------------