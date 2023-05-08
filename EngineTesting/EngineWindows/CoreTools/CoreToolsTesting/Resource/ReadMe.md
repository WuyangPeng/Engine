@ingroup group_CoreToolsTesting_Documentation

----------------------------
核心工具库单元测试

----------------------------
1.   HelperSuite 

对Helper模块的单元测试，包括：
（1） 函数描述宏：FunctionDescribedMacroTesting。
（2） 断言测试宏：AssertTestExceptionThrowTesting、
				  AssertTestConditionTesting、
				  AssertTestOperatorTesting、
				  AssertTestApproximateTesting、
				  AssertTestNullptrTesting、
				  AssertTestRangeTesting。
（3） 断言异常宏：AssertTestExceptionThrowTesting、
				  AssertThrowExceptionTesting、
				  AssertExecuteLoopNotThrowTesting。
（4） 类不变式宏：ClassInvariantMacroTesting、
			      ModuleClassInvariantMacroTesting。
（5） 断言宏：CustomAssertMacroTesting、
			  ModuleCustomAssertMacroTesting。
（6） 导出宏：ExportMacroTesting、
			  ModuleExportMacroTesting、
			  CopyModuleExportMacroTesting、
			  CopyUnsharedExportMacroTesting、
			  DelayCopyUnsharedExportMacroTesting、
			  NonCopyExportMacroTesting、
			  PerformanceUnsharedExportMacroTesting、
			  SharedExportMacroTesting。
（7） 日志宏：LogDefaultMacroTesting、
			  LogFileMacroTesting、
			  LogConsoleMacroTesting、
			  LogFileAndConsoleMacroTesting、
			  LogEngineMacroTesting、
			  LogTriggerAssertMacroTesting。
（8） 初始化销毁宏：InitializeTerminatorMacroTesting。
（9） 主函数宏：MainFunctionMacroTesting。
（10）成员函数宏：MemberFunctionNoexceptMacroTesting、
				  MemberFunctionMacroTesting、
				  CallConstMemberFunctionMacroTesting、
				  MemberFunctionStaticAssertMacroTesting、
				  CopyMemberFunctionStaticAssertMacroTesting。
（11）运行时类型识别宏：RttiMacroBaseTesting、
					    RttiMacroTesting、
						RttiMacroFinalTesting。
（12）单例宏：SingletonMacroTesting。
（13）名字宏：NameMacroTesting。
（14）字节流宏：StreamSizeMacroTesting、
				DebugStreamMacroTesting、
				DefaultTestingNoObjectPtrTesting、
				DefaultTestingObjectPtrTesting、
				TestingNoObjectPtrTesting、
				TestingObjectPtrTesting、
				TestingObjectSizeTesting、
				TestingObjectTesting。
（15）单元测试宏：UnitTestSuiteMacroTesting。
（16）智能指针宏：SharedPtrMacroTesting。
（17）异常宏：ExceptionMacroTesting、
			  ExceptionCatchMacroTesting。 
（18）属性宏：PropertiesMacroTesting。
（19）用户宏：UserMacroTesting。
（20）while循环安全计数器宏：SafetyLimitMacroTesting。
（21）获取数值所需的位：GetRequiredBitsTesting。
（22）哈希组合：HashCombineTesting。
 
----------------------------
2.   ContractSuite 

对契约模块的单元测试，包括：
（1） 函数描述：FunctionDescribedTesting。
（2） 资源自动管理：ScopeExitTesting。
（3） 触发断言：TriggerAssertTesting。
（4） 类不变式：CheckInvariantTesting。
（5） Noexcept：NoexceptTesting。
（6） 断言：AssertionTesting。
（7） Impl特征类：ImplStaticAssertHelperTesting、
				  CopyUnsharedImplTesting、
				  DelayCopyUnsharedImplTesting、
				  NonCopyImplTesting、
				  PerformanceUnsharedImplTesting、
				  SharedImplTesting。
 
----------------------------
3.   BaseSuite 

对基本功能模块的单元测试，包括：
（1）单例基类：SingletonTesting。
（2）唯一ID管理：UniqueIdManagerTesting。
（3）版本信息：VersionTesting。
（4）动态链接库：LoadingLibraryTesting。
（5）跨度迭代器：SpanIteratorTesting。
（6）静态单例：StaticSingletonTesting。

----------------------------
4.   CharacterStringSuite 

对字符串模块的单元测试，包括：
（1）格式化错误消息：FormatErrorMessageTesting。
（2）字符串转换：StringConversionTesting。
（3）忽略大小写的字符类：CaseInsensitiveStringTesting、
						 CaseInsensitiveStringIOStreamTesting。 
（4）字符串工具：StringUtilityTesting。

----------------------------
5.   ExceptionSuite 

对异常模块的单元测试，包括：
（1）错误码：LastErrorTesting。
（2）错误：ErrorTesting。
（3）游戏异常：GameErrorTesting。

----------------------------
6.  ConsoleSuite 

对控制台模块的单元测试，包括：
（1）控制台实例：ConsoleTesting。
（2）控制台颜色：ConsoleColorsTesting、
				 ConsoleTextColorsManagerTesting。
（3）控制台创建：ConsoleAllocTesting。

----------------------------
7.	 ThreadingSuite 

对线程模块的单元测试，包括：
（1） 临界区：CriticalSectionTesting。
（2） Windows互斥锁：WindowsMutexTesting。
（3） std互斥锁：StdMutexTesting。
（4） std递归互斥锁：StdRecursiveMutexTesting。
（5） boost互斥锁：BoostMutexTesting。
（6） boost递归互斥锁：BoostRecursiveMutexTesting。
（7） 空互斥锁：NullMutexTesting。
（8） 事件：EventTesting。
（9） 信号量：SemaphoreTesting。
（10）线程：ThreadTesting。
（11）线程管理：ThreadManagerTesting。 
（12）线程守卫：ThreadGuardTesting。 
（13）线程组：ThreadGroupTesting。 

----------------------------
8.	 FileManagerSuite 

对文件管理模块的单元测试，包括：
（1）字节序：ByteSwapperTesting、
			 ByteSwapTesting、
			 TypeAliaserTesting、
			 EndianTesting。
（2）文件缓冲区：FileBufferTesting。
（3）C文件管理：CWriteFileManagerTesting、
			    CReadFileManagerTesting、
				CFileManagerTesting。
（4）C++文件管理：OFStreamManagerTesting、
				  IFStreamManagerTesting。
（5）删除文件工具：DeleteFileToolsTesting。
（6）复制文件工具：CopyFileToolsTesting。
（7）Handle文件管理：WriteFileHandleTesting、
					 ReadFileHandleTesting、
					 ReadAndWriteFileHandleTesting、
					 FileHandleHelperTesting、
					 FileHandleTesting。
（8）文件管理：WriteFileManagerTesting、
			   ReadFileManagerTesting、
			   FileManagerHelperTesting。
（9）目录管理：DirectoryTesting。
（10）缓冲区IO：ReadBufferIOTesting、
				WriteBufferIOTesting。
（11）环境变量：EnvironmentTesting、
				EnvironmentVariableTesting。
（12）文件读取存入异步管理：FileAsynchronousParameterTesting、
						    FileEventTesting、
							FileAsynchronousTesting。
（13）随机文件名：GenerateRandomNameTesting。

----------------------------
9.  TextParsingSuite 

对文本解析模块的单元测试，包括：
（1）简易zip管理：ZipEntryTesting、
				  ZipArchiveTesting。
（2）简易csv管理：SimpleCSVExceptionTesting、
				  XmlDataTesting、
				  XmlFileTesting、
				  SharedStringsTesting、
				  ColorTesting、
				  CellValueProxyTesting、
				  CellValueTesting、
				  CellReferenceTesting、
				  CellTesting、
				  CellRangeTesting、
				  CellIteratorTesting、
				  ColumnTesting、
				  RowDataIteratorTesting、
				  RowDataRangeTesting、
				  RowRangeTesting、
				  RowTesting、
				  RowDataProxyTesting、
				  SheetBaseTesting、
				  WorksheetTesting、
				  AppPropertiesTesting、
				  PropertiesTesting、
				  ContentItemTesting、
				  ContentTypesTesting、
				  RelationshipItemTesting、
				  RelationshipsTesting、
				  WorkbookTesting、
				  DocumentTesting。
（3）简易csv控制：CommandSetSheetNameTesting、
				  CommandSetSheetVisibilityTesting、
				  CommandSetSheetColorTesting、
				  CommandSetSheetIndexTesting、
				  CommandResetCalcChainTesting、
				  CommandAddSharedStringsTesting、
				  CommandAddWorksheetTesting、
				  CommandAddChartsheetTesting、
				  CommandDeleteSheetTesting、
				  CommandCloneSheetTesting。
（4）简易csv查询：QuerySheetNameTesting、
				  QuerySheetIndexTesting、
				  QuerySheetVisibilityTesting、
				  QuerySheetTypeTesting、
				  QuerySheetIDTesting、
				  QuerySheetRelsIDTesting、
				  QuerySheetRelsTargetTesting、
				  QuerySharedStringsTesting、
				  QueryXmlDataTesting。
（5）Excel转csv功能： ExcelConversionCSVTesting、
					  BatchConversionCSVTesting。
（6）csv解析：CSVDataTesting、
			  CSVTypeConversionTesting、
			  CSVHeadTesting、
			  CSVRowTesting、
			  CSVContentTesting、
			  CSVGenerateTesting、
			  CSVTotalGenerateTesting、
			  CSVConfigureTesting、
			  DataTypeDescribeTesting。
（7）json解析： JsonHeadTesting、
				JsonNodeContainerTesting、
				JsonNodeTesting、
				JsonGenerateTesting、
				JsonRowTesting、
				JsonConfigureTesting、
				JsonTotalGenerateTesting。 

----------------------------
10.	 LogManagerSuite 

对日志管理模块的单元测试，包括：
（1）日志过滤器：LogFilterManagerTesting。
（2）日志等级管理：LogLevelManagerTesting。
（3）日志消息：LogMessagePostfixTesting、
			   LogMessagePrefixTesting、
			   LogMessageTesting。
（4）日志控制台颜色管理：LogConsoleTextColorsManagerTesting。
（5）附加器：AppenderManagerTesting、
			 AppenderTesting。
（6）日志记录器：LoggerTesting。
（7）日志文件名：LogFileNameTesting。
（8）日志IO管理：LogAppenderIOManagerTesting。
（9）日志管理：LogTesting、
			   LogAsynchronousTesting、
			   LogHelperTesting。

----------------------------
11.	 DataTypesSuite 

对数据类型模块的单元测试，包括：
（1）元组：TupleTesting、
		   TupleLessTesting。
（2）表：TableTesting。
（3）最小堆：MinHeapRecordIndexTesting、
			 MinHeapRecordStoredManagerTesting、
			 MinHeapRecordStoredTesting、
			 MinHeapRecordTesting、
			 MinHeapTesting。
（4）线程安全容器：ThreadSafeMapTesting、
				   ThreadSafeQueueTesting。

----------------------------
12.	 MemoryToolsSuite 

对内存工具模块的单元测试，包括：
（1）堆分配：HeapAllocateTesting。
（2）指针比较：RawIteratorsTesting、
			   RawPtrCompareTesting、
			   SharedPtrCompareTesting、
			   WeakPtrCompareTesting。
（3）多维数组：AtomicMinMaxTesting、
			   TypeTraitsTesting、
			   Array2Testing、
			   Array3Testing、
			   Array4Testing、
			   ContainerAdapterTesting、
			   LatticeTesting、
			   LexicoArray2Testing、
			   MultiArrayTesting、
			   MultiArrayAdapterTesting。

----------------------------
13.	 ObjectSystemsSuite 

对对象系统模块的单元测试，包括：
（1） 初始终止器：InitTermTesting、
				  InitTermContainerTesting、
				  InitTermRegisterFactoryTesting。
（2） Rtti：RttiTesting、
		    RttiTestingBase。
（3） 对象名字：ObjectNameTesting。
（4） 对象系统文件流：BufferInStreamTesting、
					  BufferOutStreamTesting、
					  BufferSourceTesting、
					  BufferTargetTesting、
					  FileInStreamTesting、
					  FileOutStreamTesting、
					  InTopLevelTesting、
					  StreamSizeTesting、
					  StreamTesting。
（5） 对象系统管理器：ObjectLinkTesting、
					  ObjectManagerTesting、
					  ObjectRegisterTesting、
					  ObjectTesting、
					  OutTopLevelTesting、
					  ConstObjectAssociatedTesting、
					  ConstWeakObjectAssociatedTesting、
					  ObjectAssociatedTesting、
					  WeakObjectAssociatedTesting、
					  NullObjectTesting、
					  ObjectInterfaceTesting。

----------------------------
14.	 TimeSuite 

对时间模块的单元测试，包括：
（1）时间：DeltaTimeManagerTesting、
		   DateTesting。
（2）计时器：SecondTimerTesting、
			 MillisecondTimerTesting。
（3）定制时间器：CustomTimeTesting。

----------------------------
15.	 ReportOutputSuite 

对报告输出模块的单元测试，包括：
（1）等长报告输出：EquilongReportOutputTesting。
（2）测试失败报告输出：UnitTestFailReportOutputTesting。
（3）测试套件报告输出：UnitTestSuiteReportOutputTesting。

----------------------------
16.	 UnitTestSuiteSuite 

对单元测试模块的单元测试，包括：
（1） 单元测试：OStreamSharedTesting、
				UnitTestTesting、
				UnitTestCompositeTesting、
				UnitTestStreamTesting。
（2） 单元测试套件：SuiteTesting。

----------------------------
17.	 TemplateToolsSuite 

对模板工具模块的单元测试，包括：
（1） 约束：ConstraintTesting。
（2） 阶乘：FactorialTesting。
（3） 斐波那契数：FibonacciTesting。
（4） 参数类型：ParamTypeTesting。
（5） 三角函数：TrigonometricFunctionTesting。
（6） 指针比较：PtrCompareTesting、
				RangeIterationTesting。
（7） IfThenElse：IfThenElseTesting。
（8） 数学函数：SqrtTesting、
			    Pow3Testing、
				MaxElementTesting。
（9） 转换：ExplicitCastTesting、
			LiteralCastTesting、
			ReferenceCastTesting。
（10）自增自减：IncrementScopeTesting、
		        ValueScopeTesting。
（11）真实地址：RealAddressTesting。
（12）Tiny：TinyTesting。

----------------------------
18.	 CommandSuite 

对命令行模块的单元测试，包括：
（1） 命令行参数：CommandArgumentTesting。
（2） 命令行信息：CommandLineInformationTesting。
（3） 命令行：CommandTesting。

----------------------------
19.	 MainFunctionHelperSuite 

对主函数帮助模块的单元测试，包括：
（1）测试信息帮助：TestingInformationHelperTesting。
（2）动态链接库函数帮助：DllFunctionHelperTesting。
（3）主函数帮助：CMainFunctionHelperTesting。
（4）主函数测试帮助：CMainFunctionTestingHelperTesting。

----------------------------
20.	 ModuleInitializerTerminatorSuite 

对模块自动及终止模块的单元测试，包括：
（1）模块配置。 
（2）模块自动加载及终止。
（3）模块重载。

----------------------------
21.	 SyntacticParserSuite 

对语法分析器模块的单元测试，包括：
（1） 语法分析器。

----------------------------
22.	 PerformanceProfilerSuite 

对性能剖析和统计采集模块的单元测试，包括：
（1）性能剖析器。
（2）统计采集。

----------------------------
23.	 EngineConfigurationSuite 

对引擎配置模块的单元测试，包括：
（1） 字符替换：StringReplacingTesting。

----------------------------
24.	 PropertiesSuite（属性）

对属性模块的单元测试，包括：
（1）属性：DirectPropertyInternalTesting、
		   MethodPropertyTesting、
		   PropertiesBaseTesting、
		   PropertyExternalTesting、
		   PropertyOffsetTesting、
		   SimplePropertyExternalTesting、
		   StaticPropertyExternalTesting。 

----------------------------
25.	 CyclicRedundancyCheckSuite 

对CRC模块的单元测试，包括：
（1）CheckSum校验码算法：CyclicRedundancyCheckCCITTTesting、
						 CyclicRedundancyCheckCCITTUsingTableTesting、
						 CyclicRedundancyCheckHandleTesting、
						 IntelCheckSumTesting、
						 SevenModElevenCheckSumTesting、
						 SpecifyCheckSumTesting。
（2）CRC16算法：CyclicRedundancyCheck16Testing。
（3）CRC32算法：CyclicRedundancyCheck32Testing。

----------------------------
26.	 RegularExpressionSuite 

对正则表达式模块的单元测试，包括：
（1）正则表达式。

----------------------------
27.	 MessageEventSuite 

对消息事件模块的单元测试，包括：
（1）实体消息：ParametersInterfaceTesting、
			   CallbackParametersTesting、
			   EventInterfaceTesting、
			   EventSlotTesting、
			   EventSlotManagerTesting、
			   MessageManagerTesting、
			   TelegramTesting、
			   TelegramLessTesting。 
（2）类监听事件：BaseEntityTesting、
				 EntityManagerTesting、
				 EventEntityTesting、
				 TelegramMessageManagerTesting。

----------------------------
28.	 StateMachineManagerSuite 

对状态机模块的单元测试，包括：
（1） 状态机管理器：StateEntityTesting、
					StateMachineTesting。

----------------------------
29.  NetworkSuite 

对网络模块的单元测试，包括：
（1） 网络。

----------------------------
30.  ZlibSuite 

对zlib模块的单元测试，包括：
（1） zlib。

----------------------------
31.  FreetypeSuite 

对freetype模块的单元测试，包括：
（1）freetype。

----------------------------
32.  CoroutineSuite 

对协程模块的单元测试，包括：
（1）协程。

----------------------------