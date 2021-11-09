@ingroup group_CoreToolsTesting_Documentation

----------------------------
核心工具库单元测试

----------------------------
1.   HelperSuite 

对Helper模块的单元测试，包括：
（1） 函数描述宏：FunctionDescribedMacroTesting。
（2） 断言测试宏：AssertTestExceptionThrowTesting、AssertTestConditionTesting、AssertTestOperatorTesting、
				  AssertTestApproximateTesting、AssertTestNullptrTesting、AssertTestRangeTesting。
（3） 断言异常宏：AssertExceptionMacroTesting。
（4） 类不变式宏：ClassInvariantMacroTesting、ModuleClassInvariantMacroTesting。
（5） 断言宏：CustomAssertMacroTesting、ModuleCustomAssertMacroTesting。
（6） 导出宏：ExportMacroTesting、ModuleExportMacroTesting、CopyModuleExportMacroTesting、CopyUnsharedExportMacroTesting、
			  DelayCopyUnsharedExportMacroTesting、NonCopyExportMacroTesting、PerformanceUnsharedExportMacroTesting、SharedExportMacroTesting。
（7） 日志宏：LogDefaultMacroTesting、LogFileMacroTesting、LogConsoleMacroTesting、
			  LogFileAndConsoleMacroTesting、LogEngineMacroTesting、LogTriggerAssertMacroTesting。
（8） 初始化销毁宏：InitializeTerminatorMacroTesting。
（9） 主函数宏：MainFunctionMacroTesting。
（10）成员函数宏：MemberFunctionNoexceptMacroTesting、MemberFunctionMacroTesting、CallConstMemberFunctionMacroTesting、
				  MemberFunctionStaticAssertMacroTesting、CopyMemberFunctionStaticAssertMacroTesting。
（11）内存宏：MemoryMacroTesting。
（12）运行时类型识别宏：RttiMacroBaseTesting、RttiMacroTesting、RttiMacroFinalTesting。
（13）单例宏：SingletonMacroTesting。
（14）名字宏：NameMacroTesting。
（15）字节流宏：StreamSizeMacroTesting、DebugStreamMacroTesting、DefaultTestingNoObjectPtrTesting、DefaultTestingObjectPtrTesting、
				TestingNoObjectPtrTesting、TestingObjectPtrTesting、TestingObjectSizeTesting、TestingObjectTesting。
（16）单元测试宏：UnitTestSuiteMacroCompleteTesting、UnitTestSuiteMacroCompleteUseTestingTypeTesting、UnitTestSuiteMacroTesting。
（17）智能指针宏：SharedPtrMacroTesting。
（18）异常宏：ExceptionMacroTesting。 
（19）属性宏：PropertiesMacroTesting。
（20）用户宏：UserMacroTesting。
（21）while循环安全计数器宏：SafetyLimitMacroTesting。
（22）获取数值所需的位：GetRequiredBitsTesting。
 
----------------------------
2.   ContractSuite 

对契约模块的单元测试，包括：
（1） 函数描述：FunctionDescribedTesting。
（2） 资源自动管理：ScopeExitTesting。
（3） 触发断言：TriggerAssertTesting。
（4） 类不变式：CheckInvariantTesting。
（5） Noexcept：NoexceptTesting。
（6） 断言：AssertionTesting。
（7） Impl特征类：ImplStaticAssertHelperTesting、CopyUnsharedImplTesting、DelayCopyUnsharedImplTesting、
				  NonCopyImplTesting、PerformanceUnsharedImplTesting、SharedImplTesting。
 
----------------------------
3.   BaseSuite 

对基本功能模块的单元测试，包括：
（1）单例基类：SingletonTesting。
（2）唯一ID管理：UniqueIDManagerTesting。
（3）版本信息：VersionTesting。
（4）动态链接库：LoadingLibraryTesting。
（5）跨度迭代器：SpanIteratorTesting。
（6）静态单例：StaticSingletonTesting。

----------------------------
4.   CharacterStringSuite 

对字符串模块的单元测试，包括：
（1）格式化错误消息：FormatErrorMessageTesting。
（2）字符串转换：StringConversionTesting。
（3）忽略大小写的字符类：CaseInsensitiveStringTesting、CaseInsensitiveStringIOStreamTesting。 

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
（2）控制台颜色：ConsoleColorsTesting、ConsoleTextColorsManagerTesting。
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
（1）字节序：ByteSwapperTesting、ByteSwapTesting、TypeAliaserTesting、EndianTesting。
（2）文件缓冲区：FileBufferTesting。
（3）C文件管理：CWriteFileManagerTesting、CReadFileManagerTesting、CFileManagerTesting。
（4）C++文件管理：OFStreamManagerTesting、IFStreamManagerTesting。
（5）删除文件工具：DeleteFileToolsTesting。
（6）复制文件工具：CopyFileToolsTesting。
（7）Handle文件管理：WriteFileHandleTesting、ReadFileHandleTesting、ReadAndWriteFileHandleTesting、FileHandleHelperTesting、FileHandleTesting。
（8）文件管理：WriteFileManagerTesting、ReadFileManagerTesting、FileManagerHelperTesting。
（9）目录管理：DirectoryTesting。
（10）缓冲区IO：ReadBufferIOTesting、WriteBufferIOTesting。
（11）环境变量：EnvironmentTesting、EnvironmentVariableTesting。
（12）文件读取存入异步管理：FileAsynchronousParameterTesting、FileEventTesting、FileAsynchronousTesting。
（13）随机文件名：GenerateRandomNameTesting。

----------------------------
9.  TextParsingSuite 

对文本解析模块的单元测试，包括：
（1）简易zip管理：ZipEntryTesting、ZipArchiveTesting。
（2）简易csv管理：SimpleCSVExceptionTesting、XmlDataTesting、XmlFileTesting、SharedStringsTesting、
				  ColorTesting、CellValueProxyTesting、CellValueTesting、CellReferenceTesting、
				  CellTesting、CellRangeTesting、CellIteratorTesting、ColumnTesting、
				  RowDataIteratorTesting、RowDataRangeTesting、RowRangeTesting、RowTesting、
				  RowDataProxyTesting、SheetBaseTesting、WorksheetTesting、AppPropertiesTesting、
				  PropertiesTesting、ContentItemTesting、ContentTypesTesting、RelationshipItemTesting、
				  RelationshipsTesting、WorkbookTesting、DocumentTesting。
（3）简易csv控制：CommandSetSheetNameTesting、CommandSetSheetVisibilityTesting、CommandSetSheetColorTesting、CommandSetSheetIndexTesting、
						CommandResetCalcChainTesting、CommandAddSharedStringsTesting、CommandAddWorksheetTesting、
						CommandAddChartsheetTesting、CommandDeleteSheetTesting、CommandCloneSheetTesting。
（4）简易csv查询：QuerySheetNameTesting、QuerySheetIndexTesting、QuerySheetVisibilityTesting、
				  QuerySheetTypeTesting、QuerySheetIDTesting、QuerySheetRelsIDTesting、
				  QuerySheetRelsTargetTesting、QuerySharedStringsTesting、QueryXmlDataTesting。
（5）Excel转csv功能： ExcelConversionCSVTesting、BatchConversionCSVTesting。
（6）csv解析：CSVTypeConversionTesting、CSVHeadTesting、CSVRowTesting、CSVContentTesting、
			  CSVGenerateTesting、CSVTotalGenerateTesting、CSVConfigureTesting。
（7）json解析：
（8）json转换成枚举：
（9）xml解析：
（10）ini解析：
（11）info解析： 

----------------------------
10.	 LogManagerSuite 

对日志管理模块的单元测试，包括：
（1）日志过滤器：LogFilterManagerTesting。
（2）日志等级管理：LogLevelManagerTesting。
（3）日志消息：LogMessagePostfixTesting、LogMessagePrefixTesting、LogMessageTesting。
（4）日志控制台颜色管理：LogConsoleTextColorsManagerTesting。
（5）附加器：AppenderManagerTesting、AppenderTesting。
（6）日志记录器：LoggerTesting。
（7）日志文件名：LogFileNameTesting。
（8）日志IO管理：LogAppenderIOManagerTesting。
（9）日志管理：LogTesting。

----------------------------
11.	 DataTypesSuite 

对数据类型模块的单元测试，包括：
（1）元组：TupleTesting。
（2）表：TableTesting。
（3）最小堆：MinHeapRecordIndexTesting、MinHeapRecordStoredManagerTesting、MinHeapRecordStoredTesting、MinHeapRecordTesting、MinHeapTesting。

----------------------------
12.	 MemoryToolsSuite 

对内存工具模块的单元测试，包括：
（1）堆分配：HeapAllocateTesting。
（2）内存管理：：BufferStreamTesting、BufferTesting、DefaultMemoryTesting、MemoryManagerTesting、MemoryTesting。
（3）智能指针管理：SmartPointerTesting。
（4）MD5：MD5ContextTesting、MD5Testing。
（5）随机数：RandomTesting。
（6）内存池：BufferPoolTesting、PoolTesting。
（7）子类智能指针管理：SubclassSmartPointerTesting。

----------------------------
13.	 ObjectSystemsSuite 

对对象系统模块的单元测试，包括：
（1） 初始终止器：InitTermTesting。
（2） Rtti：RttiTesting、RttiTestingBase。
（3） 对象名字：ObjectNameTesting。
（4） 对象系统文件流：BufferInStreamTesting、BufferOutStreamTesting、BufferSourceTesting、BufferTargetTesting、
					  FileInStreamTesting、FileOutStreamTesting、InTopLevelTesting、StreamSizeTesting、StreamTesting。
（5） 对象系统管理器：ObjectLinkTesting、ObjectManagerTesting、ObjectRegisterTesting、ObjectTesting、OutTopLevelTesting。
（6） 对象系统类型转换：TypeCastingTesting。

----------------------------
14.	 TimeSuite 

对时间模块的单元测试，包括：
（1）时间：DeltaTimeManagerTesting。
（2）计时器：SecondTimerTesting、MillisecondTimerTesting。
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
（1） 单元测试：UnitTestTesting。
（2） 单元测试套件：SuiteTesting。

----------------------------
17.	 TemplateToolsSuite 

对模板工具模块的单元测试，包括：
（1） 约束：ConstraintTesting。
（2） 阶乘：FactorialTesting。
（3） 斐波那契数：FibonacciTesting。
（4） 参数类型：ParamTypeTesting。
（5） 三角函数：TrigonometricFunctionTesting。
（6） 指针比较：PtrCompareTesting。
（7） IfThenElse。
（8） 数学函数：SqrtTesting、Pow3Testing。
（9） 转换：ExplicitCastTesting、LiteralCastTesting、ReferenceCastTesting。
（10）自增自减：IncrementScopeTesting、ValueScopeTesting。
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
20.	 HandleManagerSuite 

对句柄管理模块的单元测试，包括：
（1）句柄类型管理：HandleManagerTesting。
（2）资源句柄：ResourceHandleTesting。

----------------------------
21.	 ResourceManagerSuite 

对资源管理模块的单元测试，包括：
（1）资源：CommonDataResourceTesting。
（2）资源管理：ResourceManagerTesting。
（3）资源工厂：ResourceFactoryTesting。
（4）资源锁：ResourceManagerLockTesting。

----------------------------
22.	 FrameMemorySystemSuite 

对帧内存系统模块的单元测试，包括：
（1） 帧内存共享指针：FrameMemorySystemPointerShareTesting。
（2） 基础帧内存系统：FrameMemorySystemTesting。
（3） 帧内存系统管理：FrameMemorySystemTesting。

----------------------------
23.	 BitArraySuite 

对位数组模块的单元测试，包括：
（1）一维的位数组：BitArrayTesting。
（2）二维的位数组：BitArray2DTesting。
（3）一维的两位位数组：TwoBitArrayTesting。

----------------------------
24.	 ModuleInitializerTerminatorSuite 

对模块自动及终止模块的单元测试，包括：
（1）模块配置。 
（2）模块自动加载及终止。
（3）模块重载。

----------------------------
25.	 SyntacticParserSuite 

对语法分析器模块的单元测试，包括：
（1） 语法分析器。

----------------------------
26.	 PerformanceProfilerSuite 

对性能剖析和统计采集模块的单元测试，包括：
（1）性能剖析器。
（2）统计采集。

----------------------------
27.	 EngineConfigurationSuite 

对引擎配置模块的单元测试，包括：
（1） 字符替换：StringReplacingTesting。

----------------------------
28.	 PropertiesSuite（属性）

对属性模块的单元测试，包括：
（1）只读属性。
（2）只写属性。
（3）读写属性。
（4）静态变量只读属性。
（5）静态变量只写属性。
（6）静态变量读写属性。

----------------------------
29.	 CyclicRedundancyCheckSuite 

对CRC模块的单元测试，包括：
（1）CheckSum校验码算法：CyclicRedundancyCheckCCITTTesting、CyclicRedundancyCheckCCITTUsingTableTesting、CyclicRedundancyCheckHandleTesting、
						 IntelCheckSumTesting、SevenModElevenCheckSumTesting、SpecifyCheckSumTesting。
（2）CRC16算法：CyclicRedundancyCheck16Testing。
（3）CRC32算法：CyclicRedundancyCheck32Testing。

----------------------------
30.	 RegularExpressionSuite 

对正则表达式模块的单元测试，包括：
（1）正则表达式。

----------------------------
31.	 MessageEventSuite 

对消息事件模块的单元测试，包括：
（1）实体消息。
（2）类监听事件。

----------------------------
32.	 StateMachineManagerSuite 

对状态机模块的单元测试，包括：
（1） 状态机管理器：StateEntityTesting、StateMachineTesting。

----------------------------
33.  NetworkSuite 

对网络模块的单元测试，包括：
（1） 下载文件：DownloadingFilesTesting、DownloadingFilesEventTesting。

----------------------------
34.  ZlibSuite 

对zlib模块的单元测试，包括：
（1） zlib。

----------------------------
35.  FreetypeSuite 

对freetype模块的单元测试，包括：
（1）freetype。

----------------------------