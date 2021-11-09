///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/07/29 18:58)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

using namespace std::literals;

CoreTools::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "核心工具库"s }
{
    InitSuite();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TestingHelper)

void CoreTools::TestingHelper::InitSuite()
{
    AddHelperSuite();
    AddContractSuite();
    AddBaseSuite();
    AddCharacterStringSuite();
    AddExceptionSuite();
    AddConsoleSuite();
    AddThreadingSuite();
    AddFileManagerSuite();
    AddTextParsingSuite();
    AddLogManagerSuite();
    AddDataTypesSuite();
    AddMemoryToolsSuite();
    AddObjectSystemSuite();
    AddTimeSuite();
    AddReportOutputSuite();
    AddUnitTestSuite();
    AddTemplateToolsSuite();
    AddCommandSuite();
    AddMainFunctionHelperSuite();
    AddHandleManagerSuite();
    AddResourceManagerSuite();
    AddFrameMemorySystemSuite();
    AddBitArraySuite();
    AddModuleInitializerTerminatorSuite();
    AddSyntacticParserSuite();
    AddPerformanceProfilerSuite();
    AddEngineConfigurationSuite();
    AddPropertiesSuite();
    AddCyclicRedundancyCheckSuite();
    AddRegularExpressionSuite();
    AddMessageEventSuite();
    AddStateMachineSuite();
    AddNetworkSuite();
    AddZlibSuite();
    AddFreetypeSuite();
}

// private
void CoreTools::TestingHelper::AddHelperSuite()
{
    auto helperSuite = GenerateSuite("帮助");

    ADD_TEST(helperSuite, FunctionDescribedMacroTesting);
    helperSuite.AddSuite(GetAssertTestMacroSuite());
    ADD_TEST(helperSuite, AssertExceptionMacroTesting);
    helperSuite.AddSuite(GetClassInvariantMacroSuite());
    helperSuite.AddSuite(GetCustomAssertMacroSuite());
    helperSuite.AddSuite(GetExportMacroSuite());
    helperSuite.AddSuite(GetLogMacroSuite());
    ADD_TEST(helperSuite, InitializeTerminatorMacroTesting);
    ADD_TEST(helperSuite, MainFunctionMacroTesting);
    helperSuite.AddSuite(GetMemberFunctionMacroSuite());
    ADD_TEST(helperSuite, MemoryMacroTesting);
    helperSuite.AddSuite(GetRttiMacroSuite());
    ADD_TEST(helperSuite, SingletonMacroTesting);
    ADD_TEST(helperSuite, NameMacroTesting);
    helperSuite.AddSuite(GetStreamMacroSuite());
    helperSuite.AddSuite(GetUnitTestSuiteMacroSuite());
    ADD_TEST(helperSuite, SharedPtrMacroTesting);
    helperSuite.AddSuite(GetExceptionMacroSuite());
    ADD_TEST(helperSuite, PropertiesMacroTesting);
    ADD_TEST(helperSuite, UserMacroTesting);
    ADD_TEST(helperSuite, SafetyLimitMacroTesting);
    ADD_TEST(helperSuite, GetRequiredBitsTesting);

    AddSuite(helperSuite);
}

CoreTools::Suite CoreTools::TestingHelper::GetAssertTestMacroSuite()
{
    auto assertTestMacroSuite = GenerateSuite("断言测试");

    ADD_TEST(assertTestMacroSuite, AssertTestExceptionThrowTesting);
    ADD_TEST(assertTestMacroSuite, AssertTestConditionTesting);
    ADD_TEST(assertTestMacroSuite, AssertTestOperatorTesting);
    ADD_TEST(assertTestMacroSuite, AssertTestApproximateTesting);
    ADD_TEST(assertTestMacroSuite, AssertTestNullptrTesting);
    ADD_TEST(assertTestMacroSuite, AssertTestRangeTesting);

    return assertTestMacroSuite;
}

// private
CoreTools::Suite CoreTools::TestingHelper::GetClassInvariantMacroSuite()
{
    auto classInvariantMacroSuite = GenerateSuite("类不变式宏");

    ADD_TEST(classInvariantMacroSuite, ClassInvariantMacroTesting);
    ADD_TEST(classInvariantMacroSuite, ModuleClassInvariantMacroTesting);

    return classInvariantMacroSuite;
}

// private
CoreTools::Suite CoreTools::TestingHelper::GetCustomAssertMacroSuite()
{
    auto customAssertMacroSuite = GenerateSuite("断言宏");

    ADD_TEST(customAssertMacroSuite, CustomAssertMacroTesting);
    ADD_TEST(customAssertMacroSuite, ModuleCustomAssertMacroTesting);

    return customAssertMacroSuite;
}

// private
CoreTools::Suite CoreTools::TestingHelper::GetExportMacroSuite()
{
    auto exportMacroSuite = GenerateSuite("导出宏");

    ADD_TEST(exportMacroSuite, ExportMacroTesting);
    ADD_TEST(exportMacroSuite, ModuleExportMacroTesting);
    ADD_TEST(exportMacroSuite, CopyModuleExportMacroTesting);
    ADD_TEST(exportMacroSuite, CopyUnsharedExportMacroTesting);
    ADD_TEST(exportMacroSuite, DelayCopyUnsharedExportMacroTesting);
    ADD_TEST(exportMacroSuite, NonCopyExportMacroTesting);
    ADD_TEST(exportMacroSuite, PerformanceUnsharedExportMacroTesting);
    ADD_TEST(exportMacroSuite, SharedExportMacroTesting);

    return exportMacroSuite;
}

// private
CoreTools::Suite CoreTools::TestingHelper::GetLogMacroSuite()
{
    auto logMacroSuite = GenerateSuite("日志宏");

    ADD_TEST(logMacroSuite, LogDefaultMacroTesting);
    ADD_TEST(logMacroSuite, LogFileMacroTesting);
    ADD_TEST(logMacroSuite, LogConsoleMacroTesting);
    ADD_TEST(logMacroSuite, LogFileAndConsoleMacroTesting);
    ADD_TEST(logMacroSuite, LogEngineMacroTesting);
    ADD_TEST(logMacroSuite, LogTriggerAssertMacroTesting);

    return logMacroSuite;
}

// private
CoreTools::Suite CoreTools::TestingHelper::GetMemberFunctionMacroSuite()
{
    auto memberFunctionMacroSuite = GenerateSuite("成员函数宏");

    ADD_TEST(memberFunctionMacroSuite, MemberFunctionMacroTesting);
    ADD_TEST(memberFunctionMacroSuite, MemberFunctionNoexceptMacroTesting);
    ADD_TEST(memberFunctionMacroSuite, CallConstMemberFunctionMacroTesting);
    ADD_TEST(memberFunctionMacroSuite, MemberFunctionStaticAssertMacroTesting);
    ADD_TEST(memberFunctionMacroSuite, CopyMemberFunctionStaticAssertMacroTesting);

    return memberFunctionMacroSuite;
}

// private
CoreTools::Suite CoreTools::TestingHelper::GetRttiMacroSuite()
{
    auto rttiMacroSuite = GenerateSuite("Rtti宏");

    ADD_TEST(rttiMacroSuite, RttiMacroBaseTesting);
    ADD_TEST(rttiMacroSuite, RttiMacroTesting);
    ADD_TEST(rttiMacroSuite, RttiMacroFinalTesting);

    return rttiMacroSuite;
}

// private
CoreTools::Suite CoreTools::TestingHelper::GetStreamMacroSuite()
{
    auto streamMacroSuite = GenerateSuite("字节流宏");

    ADD_TEST(streamMacroSuite, StreamSizeMacroTesting);
    ADD_TEST(streamMacroSuite, DebugStreamMacroTesting);
    ADD_TEST(streamMacroSuite, DefaultTestingNoObjectPtrTesting);
    ADD_TEST(streamMacroSuite, DefaultTestingObjectPtrTesting);
    ADD_TEST(streamMacroSuite, TestingNoObjectPtrTesting);
    ADD_TEST(streamMacroSuite, TestingObjectPtrTesting);
    ADD_TEST(streamMacroSuite, TestingObjectSizeTesting);
    ADD_TEST(streamMacroSuite, TestingObjectTesting);

    return streamMacroSuite;
}

// private
CoreTools::Suite CoreTools::TestingHelper::GetUnitTestSuiteMacroSuite()
{
    auto unitTestSuiteMacroSuite = GenerateSuite("UnitTestSuite宏");

    ADD_TEST(unitTestSuiteMacroSuite, UnitTestSuiteMacroCompleteTesting);
    ADD_TEST(unitTestSuiteMacroSuite, UnitTestSuiteMacroCompleteUseTestingTypeTesting);
    ADD_TEST_USE_PARAMETER_1(unitTestSuiteMacroSuite, UnitTestSuiteMacroTesting, IsPrintRun());

    return unitTestSuiteMacroSuite;
}

// private
CoreTools::Suite CoreTools::TestingHelper::GetExceptionMacroSuite()
{
    auto exceptionMacroSuite = GenerateSuite("异常宏");

    ADD_TEST(exceptionMacroSuite, ExceptionMacroTesting);
    ADD_TEST(exceptionMacroSuite, ExceptionCatchMacroTesting);

    return exceptionMacroSuite;
}

// private
void CoreTools::TestingHelper::AddContractSuite()
{
    auto contractSuite = GenerateSuite("契约");

    ADD_TEST(contractSuite, FunctionDescribedTesting);
    ADD_TEST(contractSuite, ScopeExitTesting);
    ADD_TEST(contractSuite, TriggerAssertTesting);
    ADD_TEST(contractSuite, CheckInvariantTesting);
    ADD_TEST(contractSuite, NoexceptTesting);
    ADD_TEST(contractSuite, AssertionTesting);
    contractSuite.AddSuite(GetImplSuite());

    AddSuite(contractSuite);
}

CoreTools::Suite CoreTools::TestingHelper::GetImplSuite()
{
    auto implSuite = GenerateSuite("impl");

    ADD_TEST(implSuite, ImplStaticAssertHelperTesting);
    ADD_TEST(implSuite, CopyUnsharedImplTesting);
    ADD_TEST(implSuite, DelayCopyUnsharedImplTesting);
    ADD_TEST(implSuite, NonCopyImplTesting);
    ADD_TEST(implSuite, PerformanceUnsharedImplTesting);
    ADD_TEST(implSuite, SharedImplTesting);

    return implSuite;
}

// private
void CoreTools::TestingHelper::AddBaseSuite()
{
    auto baseSuite = GenerateSuite("基础");

    ADD_TEST(baseSuite, SingletonTesting);
    ADD_TEST(baseSuite, UniqueIDManagerTesting);
    ADD_TEST(baseSuite, VersionTesting);
    ADD_TEST(baseSuite, LoadingLibraryTesting);
    ADD_TEST(baseSuite, SpanIteratorTesting);
    ADD_TEST(baseSuite, StaticSingletonTesting);

    AddSuite(baseSuite);
}

// private
void CoreTools::TestingHelper::AddCharacterStringSuite()
{
    auto characterStringSuite = GenerateSuite("字符串类");

    ADD_TEST(characterStringSuite, StringConversionTesting);
    ADD_TEST(characterStringSuite, FormatErrorMessageTesting);
    characterStringSuite.AddSuite(GetCaseInsensitiveStringSuite());

    AddSuite(characterStringSuite);
}

CoreTools::Suite CoreTools::TestingHelper::GetCaseInsensitiveStringSuite()
{
    auto caseInsensitiveStringSuite = GenerateSuite("不区分大小写的字符串类");

    ADD_TEST(caseInsensitiveStringSuite, CaseInsensitiveStringTesting);
    ADD_TEST(caseInsensitiveStringSuite, CaseInsensitiveStringIOStreamTesting);

    return caseInsensitiveStringSuite;
}

// private
void CoreTools::TestingHelper::AddExceptionSuite()
{
    auto exceptionSuite = GenerateSuite("异常库");

    ADD_TEST(exceptionSuite, LastErrorTesting);
    ADD_TEST(exceptionSuite, ErrorTesting);

    AddSuite(exceptionSuite);
}

// private
void CoreTools::TestingHelper::AddConsoleSuite()
{
    auto consoleSuite = GenerateSuite("控制台库");

    ADD_TEST(consoleSuite, ConsoleTesting);
    ADD_TEST(consoleSuite, ConsoleColorsTesting);
    ADD_TEST(consoleSuite, ConsoleTextColorsManagerTesting);
    ADD_TEST(consoleSuite, ConsoleAllocTesting);

    AddSuite(consoleSuite);
}

// private
void CoreTools::TestingHelper::AddThreadingSuite()
{
    auto threadingSuite = GenerateSuite("线程库");

    ADD_TEST(threadingSuite, CriticalSectionTesting);
    ADD_TEST(threadingSuite, WindowsMutexTesting);
    ADD_TEST(threadingSuite, StdMutexTesting);
    ADD_TEST(threadingSuite, StdRecursiveMutexTesting);
    ADD_TEST(threadingSuite, BoostMutexTesting);
    ADD_TEST(threadingSuite, BoostRecursiveMutexTesting);
    ADD_TEST(threadingSuite, NullMutexTesting);
    ADD_TEST(threadingSuite, EventTesting);
    ADD_TEST(threadingSuite, SemaphoreTesting);
    ADD_TEST(threadingSuite, ThreadTesting);
    ADD_TEST(threadingSuite, ThreadManagerTesting);
    ADD_TEST(threadingSuite, ThreadGuardTesting);
    ADD_TEST(threadingSuite, ThreadGroupTesting);

    AddSuite(threadingSuite);
}

// private
void CoreTools::TestingHelper::AddFileManagerSuite()
{
    auto fileManagerSuite = GenerateSuite("文件管理库");

    fileManagerSuite.AddSuite(GetEndianSuite());
    ADD_TEST(fileManagerSuite, FileBufferTesting);
    fileManagerSuite.AddSuite(GetCFileManagerSuite());
    fileManagerSuite.AddSuite(GetStreamManagerSuite());
    ADD_TEST(fileManagerSuite, DeleteFileToolsTesting);
    ADD_TEST(fileManagerSuite, CopyFileToolsTesting);
    fileManagerSuite.AddSuite(GetFileHandleSuite());
    fileManagerSuite.AddSuite(GetFileSuite());
    ADD_TEST(fileManagerSuite, DirectoryTesting);
    fileManagerSuite.AddSuite(GetBufferIOSuite());
    fileManagerSuite.AddSuite(GetEnvironmentSuite());
    fileManagerSuite.AddSuite(GetFileAsynchronousSuite());
    ADD_TEST(fileManagerSuite, GenerateRandomNameTesting);

    AddSuite(fileManagerSuite);
}

// private
CoreTools::Suite CoreTools::TestingHelper::GetEndianSuite()
{
    auto endianSuite = GenerateSuite("字节序");

    ADD_TEST(endianSuite, ByteSwapTesting);
    ADD_TEST(endianSuite, ByteSwapperTesting);
    ADD_TEST(endianSuite, TypeAliaserTesting);
    ADD_TEST(endianSuite, EndianTesting);

    return endianSuite;
}

// private
CoreTools::Suite CoreTools::TestingHelper::GetCFileManagerSuite()
{
    auto cFileManagerSuite = GenerateSuite("C文件管理");

    ADD_TEST(cFileManagerSuite, CWriteFileManagerTesting);
    ADD_TEST(cFileManagerSuite, CReadFileManagerTesting);
    ADD_TEST(cFileManagerSuite, CFileManagerTesting);

    return cFileManagerSuite;
}

// private
CoreTools::Suite CoreTools::TestingHelper::GetStreamManagerSuite()
{
    auto streamManagerSuite = GenerateSuite("C++文件管理");

    ADD_TEST(streamManagerSuite, OFStreamManagerTesting);
    ADD_TEST(streamManagerSuite, IFStreamManagerTesting);

    return streamManagerSuite;
}

// private
CoreTools::Suite CoreTools::TestingHelper::GetFileSuite()
{
    auto fileSuite = GenerateSuite("文件管理");

    ADD_TEST(fileSuite, WriteFileManagerTesting);
    ADD_TEST(fileSuite, ReadFileManagerTesting);
    ADD_TEST(fileSuite, FileManagerHelperTesting);

    return fileSuite;
}

// private
CoreTools::Suite CoreTools::TestingHelper::GetFileHandleSuite()
{
    auto fileHandleSuite = GenerateSuite("文件句柄管理");

    ADD_TEST(fileHandleSuite, WriteFileHandleTesting);
    ADD_TEST(fileHandleSuite, ReadFileHandleTesting);
    ADD_TEST(fileHandleSuite, ReadAndWriteFileHandleTesting);
    ADD_TEST(fileHandleSuite, FileHandleHelperTesting);
    ADD_TEST(fileHandleSuite, FileHandleTesting);

    return fileHandleSuite;
}

// private
CoreTools::Suite CoreTools::TestingHelper::GetBufferIOSuite()
{
    auto bufferIOSuite = GenerateSuite("缓冲区IO");

    ADD_TEST(bufferIOSuite, ReadBufferIOTesting);
    ADD_TEST(bufferIOSuite, WriteBufferIOTesting);

    return bufferIOSuite;
}

// private
CoreTools::Suite CoreTools::TestingHelper::GetEnvironmentSuite()
{
    auto environmentSuite = GenerateSuite("缓冲区IO");

    ADD_TEST(environmentSuite, EnvironmentVariableTesting);
    ADD_TEST(environmentSuite, EnvironmentTesting);

    return environmentSuite;
}

// private
CoreTools::Suite CoreTools::TestingHelper::GetFileAsynchronousSuite()
{
    auto fileAsynchronousSuite = GenerateSuite("文件异步管理");

    ADD_TEST(fileAsynchronousSuite, FileAsynchronousParameterTesting);
    ADD_TEST(fileAsynchronousSuite, FileEventTesting);
    ADD_TEST(fileAsynchronousSuite, FileAsynchronousTesting);

    return fileAsynchronousSuite;
}

void CoreTools::TestingHelper::AddTextParsingSuite()
{
    auto textParsingSuite = GenerateSuite("文本解析");

    textParsingSuite.AddSuite(GetSimpleZipSuite());
    textParsingSuite.AddSuite(GetSimpleCSVSuite());
    ADD_TEST(textParsingSuite, ExcelConversionCSVTesting);
    ADD_TEST(textParsingSuite, BatchConversionCSVTesting);
    ADD_TEST(textParsingSuite, CSVTypeConversionTesting);
    ADD_TEST(textParsingSuite, CSVHeadTesting);
    ADD_TEST(textParsingSuite, CSVRowTesting);
    ADD_TEST(textParsingSuite, CSVContentTesting);
    ADD_TEST(textParsingSuite, CSVGenerateTesting);
    ADD_TEST(textParsingSuite, CSVTotalGenerateTesting);
    ADD_TEST(textParsingSuite, CSVConfigureTesting);

    AddSuite(textParsingSuite);
}

// private
CoreTools::Suite CoreTools::TestingHelper::GetSimpleZipSuite()
{
    auto SimpleZipSuite = GenerateSuite("简易Zip");

    ADD_TEST(SimpleZipSuite, ZipEntryTesting);
    ADD_TEST(SimpleZipSuite, ZipArchiveTesting);

    return SimpleZipSuite;
}

// private
CoreTools::Suite CoreTools::TestingHelper::GetSimpleCSVSuite()
{
    auto simpleCSVSuite = GenerateSuite("简易Csv");

    ADD_TEST(simpleCSVSuite, SimpleCSVExceptionTesting);
    simpleCSVSuite.AddSuite(GetCommandSuite());
    simpleCSVSuite.AddSuite(GetQuerySuite());
    ADD_TEST(simpleCSVSuite, XmlDataTesting);
    ADD_TEST(simpleCSVSuite, XmlFileTesting);
    ADD_TEST(simpleCSVSuite, SharedStringsTesting);
    ADD_TEST(simpleCSVSuite, ColorTesting);
    ADD_TEST(simpleCSVSuite, CellValueProxyTesting);
    ADD_TEST(simpleCSVSuite, CellValueTesting);
    ADD_TEST(simpleCSVSuite, CellReferenceTesting);
    ADD_TEST(simpleCSVSuite, CellTesting);
    ADD_TEST(simpleCSVSuite, CellRangeTesting);
    ADD_TEST(simpleCSVSuite, CellIteratorTesting);
    ADD_TEST(simpleCSVSuite, ColumnTesting);
    ADD_TEST(simpleCSVSuite, RowDataIteratorTesting);
    ADD_TEST(simpleCSVSuite, RowDataRangeTesting);
    ADD_TEST(simpleCSVSuite, RowRangeTesting);
    ADD_TEST(simpleCSVSuite, RowTesting);
    ADD_TEST(simpleCSVSuite, RowDataProxyTesting);
    ADD_TEST(simpleCSVSuite, SheetBaseTesting);
    ADD_TEST(simpleCSVSuite, WorksheetTesting);
    ADD_TEST(simpleCSVSuite, AppPropertiesTesting);
    ADD_TEST(simpleCSVSuite, PropertiesTesting);
    ADD_TEST(simpleCSVSuite, ContentItemTesting);
    ADD_TEST(simpleCSVSuite, ContentTypesTesting);
    ADD_TEST(simpleCSVSuite, RelationshipItemTesting);
    ADD_TEST(simpleCSVSuite, RelationshipsTesting);
    ADD_TEST(simpleCSVSuite, WorkbookTesting);
    ADD_TEST(simpleCSVSuite, DocumentTesting);

    return simpleCSVSuite;
}

// private
CoreTools::Suite CoreTools::TestingHelper::GetCommandSuite()
{
    auto simpleCSVCommandSuite = GenerateSuite("Csv命令");

    ADD_TEST(simpleCSVCommandSuite, CommandSetSheetNameTesting);
    ADD_TEST(simpleCSVCommandSuite, CommandSetSheetVisibilityTesting);
    ADD_TEST(simpleCSVCommandSuite, CommandSetSheetColorTesting);
    ADD_TEST(simpleCSVCommandSuite, CommandSetSheetIndexTesting);
    ADD_TEST(simpleCSVCommandSuite, CommandResetCalcChainTesting);
    ADD_TEST(simpleCSVCommandSuite, CommandAddSharedStringsTesting);
    ADD_TEST(simpleCSVCommandSuite, CommandAddWorksheetTesting);
    ADD_TEST(simpleCSVCommandSuite, CommandAddChartsheetTesting);
    ADD_TEST(simpleCSVCommandSuite, CommandDeleteSheetTesting);
    ADD_TEST(simpleCSVCommandSuite, CommandCloneSheetTesting);

    return simpleCSVCommandSuite;
}

// private
CoreTools::Suite CoreTools::TestingHelper::GetQuerySuite()
{
    auto querySuite = GenerateSuite("Csv查询");

    ADD_TEST(querySuite, QuerySheetNameTesting);
    ADD_TEST(querySuite, QuerySheetIndexTesting);
    ADD_TEST(querySuite, QuerySheetVisibilityTesting);
    ADD_TEST(querySuite, QuerySheetTypeTesting);
    ADD_TEST(querySuite, QuerySheetIDTesting);
    ADD_TEST(querySuite, QuerySheetRelsIDTesting);
    ADD_TEST(querySuite, QuerySheetRelsTargetTesting);
    ADD_TEST(querySuite, QuerySharedStringsTesting);
    ADD_TEST(querySuite, QueryXmlDataTesting);

    return querySuite;
}

// private
void CoreTools::TestingHelper::AddLogManagerSuite()
{
    auto logManagerSuite = GenerateSuite("日志管理库");

    ADD_TEST(logManagerSuite, LogFilterManagerTesting);
    ADD_TEST(logManagerSuite, LogLevelManagerTesting);
    ADD_TEST(logManagerSuite, LogMessageTesting);
    ADD_TEST(logManagerSuite, LogMessagePrefixTesting);
    ADD_TEST(logManagerSuite, LogMessagePostfixTesting);
    ADD_TEST(logManagerSuite, LogConsoleTextColorsManagerTesting);
    ADD_TEST(logManagerSuite, AppenderTesting);
    ADD_TEST(logManagerSuite, LoggerTesting);
    ADD_TEST(logManagerSuite, AppenderManagerTesting);
    ADD_TEST(logManagerSuite, LogFileNameTesting);
    ADD_TEST(logManagerSuite, LogAppenderIOManagerTesting);
    ADD_TEST(logManagerSuite, LogTesting);

    AddSuite(logManagerSuite);
}

// private
void CoreTools::TestingHelper::AddDataTypesSuite()
{
    auto dataTypesSuite = GenerateSuite("数据类型库");

    ADD_TEST(dataTypesSuite, TupleTesting);
    ADD_TEST(dataTypesSuite, TableTesting);
    ADD_TEST(dataTypesSuite, MinHeapRecordTesting);
    ADD_TEST(dataTypesSuite, MinHeapRecordStoredTesting);
    ADD_TEST(dataTypesSuite, MinHeapRecordIndexTesting);
    ADD_TEST(dataTypesSuite, MinHeapRecordStoredManagerTesting);
    ADD_TEST(dataTypesSuite, MinHeapTesting);

    AddSuite(dataTypesSuite);
}

// private
void CoreTools::TestingHelper::AddMemoryToolsSuite()
{
    auto memoryToolsSuite = GenerateSuite("内存工具库");

    ADD_TEST(memoryToolsSuite, HeapAllocateTesting);
    ADD_TEST(memoryToolsSuite, DefaultMemoryTesting);
    ADD_TEST(memoryToolsSuite, MemoryTesting);
    ADD_TEST(memoryToolsSuite, MemoryManagerTesting);
    ADD_TEST(memoryToolsSuite, SmartPointerTesting);
    ADD_TEST(memoryToolsSuite, MD5ContextTesting);
    ADD_TEST(memoryToolsSuite, MD5Testing);
    ADD_TEST(memoryToolsSuite, RandomTesting);
    ADD_TEST(memoryToolsSuite, PoolTesting);
    ADD_TEST(memoryToolsSuite, BufferPoolTesting);
    ADD_TEST(memoryToolsSuite, BufferTesting);
    ADD_TEST(memoryToolsSuite, BufferStreamTesting);
    ADD_TEST(memoryToolsSuite, SubclassSmartPointerTesting);

    AddSuite(memoryToolsSuite);
}

// private
void CoreTools::TestingHelper::AddObjectSystemSuite()
{
    auto objectSystemsSuite = GenerateSuite("对象系统库");

    ADD_TEST(objectSystemsSuite, InitTermTesting);
    ADD_TEST(objectSystemsSuite, RttiTestingBase);
    ADD_TEST(objectSystemsSuite, RttiTesting);
    ADD_TEST(objectSystemsSuite, ObjectNameTesting);
    ADD_TEST(objectSystemsSuite, OutTopLevelTesting);
    ADD_TEST(objectSystemsSuite, ObjectRegisterTesting);
    ADD_TEST(objectSystemsSuite, BufferTargetTesting);
    ADD_TEST(objectSystemsSuite, BufferOutStreamTesting);
    ADD_TEST(objectSystemsSuite, FileOutStreamTesting);
    ADD_TEST(objectSystemsSuite, StreamTesting);
    ADD_TEST(objectSystemsSuite, StreamSizeTesting);
    ADD_TEST(objectSystemsSuite, BufferSourceTesting);
    ADD_TEST(objectSystemsSuite, InTopLevelTesting);
    ADD_TEST(objectSystemsSuite, ObjectLinkTesting);
    ADD_TEST(objectSystemsSuite, BufferInStreamTesting);
    ADD_TEST(objectSystemsSuite, FileInStreamTesting);
    ADD_TEST(objectSystemsSuite, ObjectTesting);
    ADD_TEST(objectSystemsSuite, ObjectManagerTesting);
    ADD_TEST(objectSystemsSuite, TypeCastingTesting);

    AddSuite(objectSystemsSuite);
}

// private
void CoreTools::TestingHelper::AddTimeSuite()
{
    auto timeSuite = GenerateSuite("时间库");

    ADD_TEST(timeSuite, CustomTimeTesting);
    ADD_TEST(timeSuite, DeltaTimeManagerTesting);
    ADD_TEST(timeSuite, MillisecondTimerTesting);
    ADD_TEST(timeSuite, SecondTimerTesting);

    AddSuite(timeSuite);
}

// private
void CoreTools::TestingHelper::AddReportOutputSuite()
{
    auto reportOutputSuite = GenerateSuite("报告输出库");

    ADD_TEST(reportOutputSuite, EquilongReportOutputTesting);
    ADD_TEST(reportOutputSuite, UnitTestFailReportOutputTesting);
    ADD_TEST(reportOutputSuite, UnitTestSuiteReportOutputTesting);

    AddSuite(reportOutputSuite);
}

// private
void CoreTools::TestingHelper::AddUnitTestSuite()
{
    auto unitTestSuite = GenerateSuite("单元测试库");

    ADD_TEST(unitTestSuite, UnitTestTesting);
    ADD_TEST(unitTestSuite, SuiteTesting);

    AddSuite(unitTestSuite);
}

// private
void CoreTools::TestingHelper::AddTemplateToolsSuite()
{
    auto templateToolsSuite = GenerateSuite("模板工具库");

    ADD_TEST(templateToolsSuite, ConstraintTesting);
    ADD_TEST(templateToolsSuite, FactorialTesting);
    ADD_TEST(templateToolsSuite, FibonacciTesting);
    ADD_TEST(templateToolsSuite, ParamTypeTesting);
    ADD_TEST(templateToolsSuite, TrigonometricFunctionTesting);
    ADD_TEST(templateToolsSuite, PtrCompareTesting);
    ADD_TEST(templateToolsSuite, SqrtTesting);
    ADD_TEST(templateToolsSuite, Pow3Testing);
    ADD_TEST(templateToolsSuite, ExplicitCastTesting);
    ADD_TEST(templateToolsSuite, IncrementScopeTesting);
    ADD_TEST(templateToolsSuite, RealAddressTesting);
    ADD_TEST(templateToolsSuite, LiteralCastTesting);
    ADD_TEST(templateToolsSuite, ReferenceCastTesting);
    ADD_TEST(templateToolsSuite, ValueScopeTesting);
    ADD_TEST(templateToolsSuite, TinyTesting);

    AddSuite(templateToolsSuite);
}

// private
void CoreTools::TestingHelper::AddCommandSuite()
{
    auto commandSuite = GenerateSuite("命令行库");

    ADD_TEST(commandSuite, CommandArgumentTesting);
    ADD_TEST(commandSuite, CommandLineInformationTesting);
    ADD_TEST(commandSuite, CommandTesting);

    AddSuite(commandSuite);
}

// private
void CoreTools::TestingHelper::AddMainFunctionHelperSuite()
{
    auto mainFunctionHelperSuite = GenerateSuite("主函数帮助库");

    ADD_TEST(mainFunctionHelperSuite, TestingInformationHelperTesting);
    ADD_TEST(mainFunctionHelperSuite, CMainFunctionHelperTesting);
    ADD_TEST(mainFunctionHelperSuite, DllFunctionHelperTesting);
    ADD_TEST(mainFunctionHelperSuite, CMainFunctionTestingHelperTesting);

    AddSuite(mainFunctionHelperSuite);
}

// private
void CoreTools::TestingHelper::AddHandleManagerSuite()
{
    auto handleManagerSuite = GenerateSuite("句柄管理");

    ADD_TEST(handleManagerSuite, HandleManagerTesting);
    ADD_TEST(handleManagerSuite, ResourceHandleTesting);

    AddSuite(handleManagerSuite);
}

// private
void CoreTools::TestingHelper::AddResourceManagerSuite()
{
    auto resourceManagerSuite = GenerateSuite("资源管理");

    ADD_TEST(resourceManagerSuite, CommonDataResourceTesting);
    ADD_TEST(resourceManagerSuite, ResourceManagerTesting);
    ADD_TEST(resourceManagerSuite, ResourceManagerLockTesting);
    ADD_TEST(resourceManagerSuite, ResourceFactoryTesting);

    AddSuite(resourceManagerSuite);
}

// private
void CoreTools::TestingHelper::AddFrameMemorySystemSuite()
{
    auto frameMemorySystemSuite = GenerateSuite("帧内存管理");

    ADD_TEST(frameMemorySystemSuite, FrameMemorySystemTesting);
    ADD_TEST(frameMemorySystemSuite, FrameMemorySystemManagerTesting);
    ADD_TEST(frameMemorySystemSuite, FrameMemorySystemPointerShareTesting);

    AddSuite(frameMemorySystemSuite);
}

// private
void CoreTools::TestingHelper::AddBitArraySuite()
{
    auto bitArraySuite = GenerateSuite("位数组管理");

    ADD_TEST(bitArraySuite, BitArrayTesting);
    ADD_TEST(bitArraySuite, BitArray2DTesting);
    ADD_TEST(bitArraySuite, TwoBitArrayTesting);

    AddSuite(bitArraySuite);
}

void CoreTools::TestingHelper::AddModuleInitializerTerminatorSuite()
{
    auto moduleInitializerTerminatorSuite = GenerateSuite("模块自动及终止");

    AddSuite(moduleInitializerTerminatorSuite);
}

void CoreTools::TestingHelper::AddSyntacticParserSuite()
{
    auto syntacticParserSuite = GenerateSuite("语法分析器");

    AddSuite(syntacticParserSuite);
}

void CoreTools::TestingHelper::AddPerformanceProfilerSuite()
{
    auto performanceProfilerSuite = GenerateSuite("性能剖析/统计采集");

    AddSuite(performanceProfilerSuite);
}

void CoreTools::TestingHelper::AddEngineConfigurationSuite()
{
    auto engineConfigurationSuite = GenerateSuite("引擎配置");

    ADD_TEST(engineConfigurationSuite, StringReplacingTesting);

    AddSuite(engineConfigurationSuite);
}

void CoreTools::TestingHelper::AddPropertiesSuite()
{
    auto propertiesSuite = GenerateSuite("属性");

    ADD_TEST(propertiesSuite, SimplePropertyExternalTesting);
    ADD_TEST(propertiesSuite, PropertyExternalTesting);
    ADD_TEST(propertiesSuite, StaticPropertyExternalTesting);
    ADD_TEST(propertiesSuite, DirectPropertyInternalTesting);
    ADD_TEST(propertiesSuite, PropertyOffsetTesting);
    ADD_TEST(propertiesSuite, MethodPropertyTesting);
    ADD_TEST(propertiesSuite, PropertiesBaseTesting);

    AddSuite(propertiesSuite);
}

void CoreTools::TestingHelper::AddCyclicRedundancyCheckSuite()
{
    auto cyclicRedundancyCheckSuite = GenerateSuite("CRC");

    ADD_TEST(cyclicRedundancyCheckSuite, IntelCheckSumTesting);
    ADD_TEST(cyclicRedundancyCheckSuite, SevenModElevenCheckSumTesting);
    ADD_TEST(cyclicRedundancyCheckSuite, SpecifyCheckSumTesting);
    ADD_TEST(cyclicRedundancyCheckSuite, CyclicRedundancyCheckCCITTTesting);
    ADD_TEST(cyclicRedundancyCheckSuite, CyclicRedundancyCheckHandleTesting);
    ADD_TEST(cyclicRedundancyCheckSuite, CyclicRedundancyCheckCCITTUsingTableTesting);
    ADD_TEST(cyclicRedundancyCheckSuite, CyclicRedundancyCheck16Testing);
    ADD_TEST(cyclicRedundancyCheckSuite, CyclicRedundancyCheck32Testing);

    AddSuite(cyclicRedundancyCheckSuite);
}

void CoreTools::TestingHelper::AddRegularExpressionSuite()
{
    auto regularExpressionSuite = GenerateSuite("正则表达式");

    AddSuite(regularExpressionSuite);
}

void CoreTools::TestingHelper::AddMessageEventSuite()
{
    auto messageEventSuite = GenerateSuite("消息事件");

    ADD_TEST(messageEventSuite, ParametersInterfaceTesting);
    ADD_TEST(messageEventSuite, CallbackParametersTesting);
    ADD_TEST(messageEventSuite, EventInterfaceTesting);
    ADD_TEST(messageEventSuite, EventSlotTesting);
    ADD_TEST(messageEventSuite, EventSlotManagerTesting);
    ADD_TEST(messageEventSuite, MessageManagerTesting);
    ADD_TEST(messageEventSuite, TelegramTesting);
    ADD_TEST(messageEventSuite, TelegramLessTesting);
    ADD_TEST(messageEventSuite, BaseEntityTesting);
    ADD_TEST(messageEventSuite, EntityManagerTesting);
    ADD_TEST(messageEventSuite, EventEntityTesting);
    ADD_TEST(messageEventSuite, TelegramMessageManagerTesting);

    AddSuite(messageEventSuite);
}

void CoreTools::TestingHelper::AddStateMachineSuite()
{
    auto stateMachineSuite = GenerateSuite("状态机");

    ADD_TEST(stateMachineSuite, StateMachineTesting);
    ADD_TEST(stateMachineSuite, StateEntityTesting);

    AddSuite(stateMachineSuite);
}

void CoreTools::TestingHelper::AddNetworkSuite()
{
    auto networkSuite = GenerateSuite("网络");

    AddSuite(networkSuite);
}

void CoreTools::TestingHelper::AddZlibSuite()
{
    auto zlibSuite = GenerateSuite("zlib");

    AddSuite(zlibSuite);
}

void CoreTools::TestingHelper::AddFreetypeSuite()
{
    auto freetypeSuite = GenerateSuite("freetype");

    AddSuite(freetypeSuite);
}
