@ingroup group_CoreToolsTesting_Documentation

----------------------------
���Ĺ��߿ⵥԪ����

----------------------------
1.   HelperSuite 

��Helperģ��ĵ�Ԫ���ԣ�������
��1�� ���������꣺FunctionDescribedMacroTesting��
��2�� ���Բ��Ժ꣺AssertTestExceptionThrowTesting��AssertTestConditionTesting��AssertTestOperatorTesting��
				  AssertTestApproximateTesting��AssertTestNullptrTesting��AssertTestRangeTesting��
��3�� �����쳣�꣺AssertExceptionMacroTesting��
��4�� �಻��ʽ�꣺ClassInvariantMacroTesting��ModuleClassInvariantMacroTesting��
��5�� ���Ժ꣺CustomAssertMacroTesting��ModuleCustomAssertMacroTesting��
��6�� �����꣺ExportMacroTesting��ModuleExportMacroTesting��CopyModuleExportMacroTesting��CopyUnsharedExportMacroTesting��
			  DelayCopyUnsharedExportMacroTesting��NonCopyExportMacroTesting��PerformanceUnsharedExportMacroTesting��SharedExportMacroTesting��
��7�� ��־�꣺LogDefaultMacroTesting��LogFileMacroTesting��LogConsoleMacroTesting��
			  LogFileAndConsoleMacroTesting��LogEngineMacroTesting��LogTriggerAssertMacroTesting��
��8�� ��ʼ�����ٺ꣺InitializeTerminatorMacroTesting��
��9�� �������꣺MainFunctionMacroTesting��
��10����Ա�����꣺MemberFunctionNoexceptMacroTesting��MemberFunctionMacroTesting��CallConstMemberFunctionMacroTesting��
				  MemberFunctionStaticAssertMacroTesting��CopyMemberFunctionStaticAssertMacroTesting��
��11���ڴ�꣺MemoryMacroTesting��
��12������ʱ����ʶ��꣺RttiMacroBaseTesting��RttiMacroTesting��RttiMacroFinalTesting��
��13�������꣺SingletonMacroTesting��
��14�����ֺ꣺NameMacroTesting��
��15���ֽ����꣺StreamSizeMacroTesting��DebugStreamMacroTesting��DefaultTestingNoObjectPtrTesting��DefaultTestingObjectPtrTesting��
				TestingNoObjectPtrTesting��TestingObjectPtrTesting��TestingObjectSizeTesting��TestingObjectTesting��
��16����Ԫ���Ժ꣺UnitTestSuiteMacroCompleteTesting��UnitTestSuiteMacroCompleteUseTestingTypeTesting��UnitTestSuiteMacroTesting��
��17������ָ��꣺SharedPtrMacroTesting��
��18���쳣�꣺ExceptionMacroTesting�� 
��19�����Ժ꣺PropertiesMacroTesting��
��20���û��꣺UserMacroTesting��
��21��whileѭ����ȫ�������꣺SafetyLimitMacroTesting��
��22����ȡ��ֵ�����λ��GetRequiredBitsTesting��
 
----------------------------
2.   ContractSuite 

����Լģ��ĵ�Ԫ���ԣ�������
��1�� ����������FunctionDescribedTesting��
��2�� ��Դ�Զ�����ScopeExitTesting��
��3�� �������ԣ�TriggerAssertTesting��
��4�� �಻��ʽ��CheckInvariantTesting��
��5�� Noexcept��NoexceptTesting��
��6�� ���ԣ�AssertionTesting��
��7�� Impl�����ࣺImplStaticAssertHelperTesting��CopyUnsharedImplTesting��DelayCopyUnsharedImplTesting��
				  NonCopyImplTesting��PerformanceUnsharedImplTesting��SharedImplTesting��
 
----------------------------
3.   BaseSuite 

�Ի�������ģ��ĵ�Ԫ���ԣ�������
��1���������ࣺSingletonTesting��
��2��ΨһID����UniqueIDManagerTesting��
��3���汾��Ϣ��VersionTesting��
��4����̬���ӿ⣺LoadingLibraryTesting��
��5����ȵ�������SpanIteratorTesting��
��6����̬������StaticSingletonTesting��

----------------------------
4.   CharacterStringSuite 

���ַ���ģ��ĵ�Ԫ���ԣ�������
��1����ʽ��������Ϣ��FormatErrorMessageTesting��
��2���ַ���ת����StringConversionTesting��
��3�����Դ�Сд���ַ��ࣺCaseInsensitiveStringTesting��CaseInsensitiveStringIOStreamTesting�� 

----------------------------
5.   ExceptionSuite 

���쳣ģ��ĵ�Ԫ���ԣ�������
��1�������룺LastErrorTesting��
��2������ErrorTesting��
��3����Ϸ�쳣��GameErrorTesting��

----------------------------
6.  ConsoleSuite 

�Կ���̨ģ��ĵ�Ԫ���ԣ�������
��1������̨ʵ����ConsoleTesting��
��2������̨��ɫ��ConsoleColorsTesting��ConsoleTextColorsManagerTesting��
��3������̨������ConsoleAllocTesting��

----------------------------
7.	 ThreadingSuite 

���߳�ģ��ĵ�Ԫ���ԣ�������
��1�� �ٽ�����CriticalSectionTesting��
��2�� Windows��������WindowsMutexTesting��
��3�� std��������StdMutexTesting��
��4�� std�ݹ黥������StdRecursiveMutexTesting��
��5�� boost��������BoostMutexTesting��
��6�� boost�ݹ黥������BoostRecursiveMutexTesting��
��7�� �ջ�������NullMutexTesting��
��8�� �¼���EventTesting��
��9�� �ź�����SemaphoreTesting��
��10���̣߳�ThreadTesting��
��11���̹߳���ThreadManagerTesting�� 
��12���߳�������ThreadGuardTesting�� 
��13���߳��飺ThreadGroupTesting�� 

----------------------------
8.	 FileManagerSuite 

���ļ�����ģ��ĵ�Ԫ���ԣ�������
��1���ֽ���ByteSwapperTesting��ByteSwapTesting��TypeAliaserTesting��EndianTesting��
��2���ļ���������FileBufferTesting��
��3��C�ļ�����CWriteFileManagerTesting��CReadFileManagerTesting��CFileManagerTesting��
��4��C++�ļ�����OFStreamManagerTesting��IFStreamManagerTesting��
��5��ɾ���ļ����ߣ�DeleteFileToolsTesting��
��6�������ļ����ߣ�CopyFileToolsTesting��
��7��Handle�ļ�����WriteFileHandleTesting��ReadFileHandleTesting��ReadAndWriteFileHandleTesting��FileHandleHelperTesting��FileHandleTesting��
��8���ļ�����WriteFileManagerTesting��ReadFileManagerTesting��FileManagerHelperTesting��
��9��Ŀ¼����DirectoryTesting��
��10��������IO��ReadBufferIOTesting��WriteBufferIOTesting��
��11������������EnvironmentTesting��EnvironmentVariableTesting��
��12���ļ���ȡ�����첽����FileAsynchronousParameterTesting��FileEventTesting��FileAsynchronousTesting��
��13������ļ�����GenerateRandomNameTesting��

----------------------------
9.  TextParsingSuite 

���ı�����ģ��ĵ�Ԫ���ԣ�������
��1������zip����ZipEntryTesting��ZipArchiveTesting��
��2������csv����SimpleCSVExceptionTesting��XmlDataTesting��XmlFileTesting��SharedStringsTesting��
				  ColorTesting��CellValueProxyTesting��CellValueTesting��CellReferenceTesting��
				  CellTesting��CellRangeTesting��CellIteratorTesting��ColumnTesting��
				  RowDataIteratorTesting��RowDataRangeTesting��RowRangeTesting��RowTesting��
				  RowDataProxyTesting��SheetBaseTesting��WorksheetTesting��AppPropertiesTesting��
				  PropertiesTesting��ContentItemTesting��ContentTypesTesting��RelationshipItemTesting��
				  RelationshipsTesting��WorkbookTesting��DocumentTesting��
��3������csv���ƣ�CommandSetSheetNameTesting��CommandSetSheetVisibilityTesting��CommandSetSheetColorTesting��CommandSetSheetIndexTesting��
						CommandResetCalcChainTesting��CommandAddSharedStringsTesting��CommandAddWorksheetTesting��
						CommandAddChartsheetTesting��CommandDeleteSheetTesting��CommandCloneSheetTesting��
��4������csv��ѯ��QuerySheetNameTesting��QuerySheetIndexTesting��QuerySheetVisibilityTesting��
				  QuerySheetTypeTesting��QuerySheetIDTesting��QuerySheetRelsIDTesting��
				  QuerySheetRelsTargetTesting��QuerySharedStringsTesting��QueryXmlDataTesting��
��5��Excelתcsv���ܣ� ExcelConversionCSVTesting��BatchConversionCSVTesting��
��6��csv������CSVTypeConversionTesting��CSVHeadTesting��CSVRowTesting��CSVContentTesting��
			  CSVGenerateTesting��CSVTotalGenerateTesting��CSVConfigureTesting��
��7��json������
��8��jsonת����ö�٣�
��9��xml������
��10��ini������
��11��info������ 

----------------------------
10.	 LogManagerSuite 

����־����ģ��ĵ�Ԫ���ԣ�������
��1����־��������LogFilterManagerTesting��
��2����־�ȼ�����LogLevelManagerTesting��
��3����־��Ϣ��LogMessagePostfixTesting��LogMessagePrefixTesting��LogMessageTesting��
��4����־����̨��ɫ����LogConsoleTextColorsManagerTesting��
��5����������AppenderManagerTesting��AppenderTesting��
��6����־��¼����LoggerTesting��
��7����־�ļ�����LogFileNameTesting��
��8����־IO����LogAppenderIOManagerTesting��
��9����־����LogTesting��

----------------------------
11.	 DataTypesSuite 

����������ģ��ĵ�Ԫ���ԣ�������
��1��Ԫ�飺TupleTesting��
��2����TableTesting��
��3����С�ѣ�MinHeapRecordIndexTesting��MinHeapRecordStoredManagerTesting��MinHeapRecordStoredTesting��MinHeapRecordTesting��MinHeapTesting��

----------------------------
12.	 MemoryToolsSuite 

���ڴ湤��ģ��ĵ�Ԫ���ԣ�������
��1���ѷ��䣺HeapAllocateTesting��
��2���ڴ������BufferStreamTesting��BufferTesting��DefaultMemoryTesting��MemoryManagerTesting��MemoryTesting��
��3������ָ�����SmartPointerTesting��
��4��MD5��MD5ContextTesting��MD5Testing��
��5���������RandomTesting��
��6���ڴ�أ�BufferPoolTesting��PoolTesting��
��7����������ָ�����SubclassSmartPointerTesting��

----------------------------
13.	 ObjectSystemsSuite 

�Զ���ϵͳģ��ĵ�Ԫ���ԣ�������
��1�� ��ʼ��ֹ����InitTermTesting��
��2�� Rtti��RttiTesting��RttiTestingBase��
��3�� �������֣�ObjectNameTesting��
��4�� ����ϵͳ�ļ�����BufferInStreamTesting��BufferOutStreamTesting��BufferSourceTesting��BufferTargetTesting��
					  FileInStreamTesting��FileOutStreamTesting��InTopLevelTesting��StreamSizeTesting��StreamTesting��
��5�� ����ϵͳ��������ObjectLinkTesting��ObjectManagerTesting��ObjectRegisterTesting��ObjectTesting��OutTopLevelTesting��
��6�� ����ϵͳ����ת����TypeCastingTesting��

----------------------------
14.	 TimeSuite 

��ʱ��ģ��ĵ�Ԫ���ԣ�������
��1��ʱ�䣺DeltaTimeManagerTesting��
��2����ʱ����SecondTimerTesting��MillisecondTimerTesting��
��3������ʱ������CustomTimeTesting��

----------------------------
15.	 ReportOutputSuite 

�Ա������ģ��ĵ�Ԫ���ԣ�������
��1���ȳ����������EquilongReportOutputTesting��
��2������ʧ�ܱ��������UnitTestFailReportOutputTesting��
��3�������׼����������UnitTestSuiteReportOutputTesting��

----------------------------
16.	 UnitTestSuiteSuite 

�Ե�Ԫ����ģ��ĵ�Ԫ���ԣ�������
��1�� ��Ԫ���ԣ�UnitTestTesting��
��2�� ��Ԫ�����׼���SuiteTesting��

----------------------------
17.	 TemplateToolsSuite 

��ģ�幤��ģ��ĵ�Ԫ���ԣ�������
��1�� Լ����ConstraintTesting��
��2�� �׳ˣ�FactorialTesting��
��3�� 쳲���������FibonacciTesting��
��4�� �������ͣ�ParamTypeTesting��
��5�� ���Ǻ�����TrigonometricFunctionTesting��
��6�� ָ��Ƚϣ�PtrCompareTesting��
��7�� IfThenElse��
��8�� ��ѧ������SqrtTesting��Pow3Testing��
��9�� ת����ExplicitCastTesting��LiteralCastTesting��ReferenceCastTesting��
��10�������Լ���IncrementScopeTesting��ValueScopeTesting��
��11����ʵ��ַ��RealAddressTesting��
��12��Tiny��TinyTesting��

----------------------------
18.	 CommandSuite 

��������ģ��ĵ�Ԫ���ԣ�������
��1�� �����в�����CommandArgumentTesting��
��2�� ��������Ϣ��CommandLineInformationTesting��
��3�� �����У�CommandTesting��

----------------------------
19.	 MainFunctionHelperSuite 

������������ģ��ĵ�Ԫ���ԣ�������
��1��������Ϣ������TestingInformationHelperTesting��
��2����̬���ӿ⺯��������DllFunctionHelperTesting��
��3��������������CMainFunctionHelperTesting��
��4�����������԰�����CMainFunctionTestingHelperTesting��

----------------------------
20.	 HandleManagerSuite 

�Ծ������ģ��ĵ�Ԫ���ԣ�������
��1��������͹���HandleManagerTesting��
��2����Դ�����ResourceHandleTesting��

----------------------------
21.	 ResourceManagerSuite 

����Դ����ģ��ĵ�Ԫ���ԣ�������
��1����Դ��CommonDataResourceTesting��
��2����Դ����ResourceManagerTesting��
��3����Դ������ResourceFactoryTesting��
��4����Դ����ResourceManagerLockTesting��

----------------------------
22.	 FrameMemorySystemSuite 

��֡�ڴ�ϵͳģ��ĵ�Ԫ���ԣ�������
��1�� ֡�ڴ湲��ָ�룺FrameMemorySystemPointerShareTesting��
��2�� ����֡�ڴ�ϵͳ��FrameMemorySystemTesting��
��3�� ֡�ڴ�ϵͳ����FrameMemorySystemTesting��

----------------------------
23.	 BitArraySuite 

��λ����ģ��ĵ�Ԫ���ԣ�������
��1��һά��λ���飺BitArrayTesting��
��2����ά��λ���飺BitArray2DTesting��
��3��һά����λλ���飺TwoBitArrayTesting��

----------------------------
24.	 ModuleInitializerTerminatorSuite 

��ģ���Զ�����ֹģ��ĵ�Ԫ���ԣ�������
��1��ģ�����á� 
��2��ģ���Զ����ؼ���ֹ��
��3��ģ�����ء�

----------------------------
25.	 SyntacticParserSuite 

���﷨������ģ��ĵ�Ԫ���ԣ�������
��1�� �﷨��������

----------------------------
26.	 PerformanceProfilerSuite 

������������ͳ�Ʋɼ�ģ��ĵ�Ԫ���ԣ�������
��1��������������
��2��ͳ�Ʋɼ���

----------------------------
27.	 EngineConfigurationSuite 

����������ģ��ĵ�Ԫ���ԣ�������
��1�� �ַ��滻��StringReplacingTesting��

----------------------------
28.	 PropertiesSuite�����ԣ�

������ģ��ĵ�Ԫ���ԣ�������
��1��ֻ�����ԡ�
��2��ֻд���ԡ�
��3����д���ԡ�
��4����̬����ֻ�����ԡ�
��5����̬����ֻд���ԡ�
��6����̬������д���ԡ�

----------------------------
29.	 CyclicRedundancyCheckSuite 

��CRCģ��ĵ�Ԫ���ԣ�������
��1��CheckSumУ�����㷨��CyclicRedundancyCheckCCITTTesting��CyclicRedundancyCheckCCITTUsingTableTesting��CyclicRedundancyCheckHandleTesting��
						 IntelCheckSumTesting��SevenModElevenCheckSumTesting��SpecifyCheckSumTesting��
��2��CRC16�㷨��CyclicRedundancyCheck16Testing��
��3��CRC32�㷨��CyclicRedundancyCheck32Testing��

----------------------------
30.	 RegularExpressionSuite 

��������ʽģ��ĵ�Ԫ���ԣ�������
��1��������ʽ��

----------------------------
31.	 MessageEventSuite 

����Ϣ�¼�ģ��ĵ�Ԫ���ԣ�������
��1��ʵ����Ϣ��
��2��������¼���

----------------------------
32.	 StateMachineManagerSuite 

��״̬��ģ��ĵ�Ԫ���ԣ�������
��1�� ״̬����������StateEntityTesting��StateMachineTesting��

----------------------------
33.  NetworkSuite 

������ģ��ĵ�Ԫ���ԣ�������
��1�� �����ļ���DownloadingFilesTesting��DownloadingFilesEventTesting��

----------------------------
34.  ZlibSuite 

��zlibģ��ĵ�Ԫ���ԣ�������
��1�� zlib��

----------------------------
35.  FreetypeSuite 

��freetypeģ��ĵ�Ԫ���ԣ�������
��1��freetype��

----------------------------