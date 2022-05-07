///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/08 11:10)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

using namespace std::literals;

System::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "ϵͳ��"s }
{
    InitSuite();

    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, TestingHelper)

void System::TestingHelper::InitSuite()
{
    AddHelperSuite();
    AddSystemOutputSuite();
    AddDynamicLinkSuite();
    AddCharacterStringSuite();
    AddConsoleSuite();
    AddMemoryToolsSuite();
    AddThreadingSuite();
    AddTimeSuite();
    AddFileManagerSuite();
    AddSecuritySuite();
    AddNetworkSuite();
    AddOpenGLSuite();
    AddDirectXSuite();
    AddWindowsSuite();
    AddLinuxSuite();
    AddMacintoshSuite();
    AddAndroidSuite();
}

void System::TestingHelper::AddHelperSuite()
{
    auto helperSuite = GenerateSuite("����"s);

    helperSuite.AddSuite(GetConfigMacroSuite());
    ADD_TEST(helperSuite, UserMacroTesting);
    ADD_TEST(helperSuite, StringizeMacroTesting);
    ADD_TEST(helperSuite, UnicodeUsingTesting);
    ADD_TEST(helperSuite, PragmaMessageMacroTesting);
    ADD_TEST(helperSuite, VersionTesting);
    ADD_TEST(helperSuite, ExportMacroTesting);
    helperSuite.AddSuite(GetWindowsMacroSuite());
    ADD_TEST(helperSuite, SecuritySidMacroTesting);
    ADD_TEST(helperSuite, NetworkMacroTesting);
    ADD_TEST(helperSuite, PlatformTesting);
    ADD_TEST(helperSuite, EnumCastTesting);
    helperSuite.AddSuite(GetEnumMacroSuite());
    ADD_TEST(helperSuite, NoexceptTesting);
    ADD_TEST(helperSuite, PragmaWarningTesting);
    ADD_TEST(helperSuite, GlExtensionsMacroTesting);
    helperSuite.AddSuite(GetOpenGLMacroSuite());
    ADD_TEST(helperSuite, VariableTemplateTypeTesting);

    AddSuite(helperSuite);
}

CoreTools::Suite System::TestingHelper::GetConfigMacroSuite()
{
    auto configMacroSuite = GenerateSuite("���ú�"s);

    ADD_TEST(configMacroSuite, FixedSizeTesting);
    ADD_TEST(configMacroSuite, CompilerConfigTesting);
    ADD_TEST(configMacroSuite, PlatformConfigTesting);
    ADD_TEST(configMacroSuite, StdLibConfigTesting);
    ADD_TEST(configMacroSuite, EndianTesting);
    ADD_TEST(configMacroSuite, ConfigMarkTesting);

    return configMacroSuite;
}

CoreTools::Suite System::TestingHelper::GetWindowsMacroSuite()
{
    auto windowsMacroSuite = GenerateSuite("Windows��"s);

    ADD_TEST(windowsMacroSuite, GetArraySizeTesting);
    ADD_TEST(windowsMacroSuite, UnusedFunctionTesting);
    ADD_TEST(windowsMacroSuite, MakeLanguageIDTesting);
    ADD_TEST(windowsMacroSuite, MakeIntreSourceTesting);
    ADD_TEST(windowsMacroSuite, MakeLanguageCIDTesting);
    ADD_TEST(windowsMacroSuite, HResultTesting);
    ADD_TEST(windowsMacroSuite, MakeWordTesting);
    ADD_TEST(windowsMacroSuite, PtrToIntTesting);
    ADD_TEST(windowsMacroSuite, MarkTesting);

    return windowsMacroSuite;
}

CoreTools::Suite System::TestingHelper::GetEnumMacroSuite()
{
    auto enumMacroSuite = GenerateSuite("ö�ٺ�"s);

    ADD_TEST(enumMacroSuite, EnumAddableTesting);
    ADD_TEST(enumMacroSuite, EnumSubtractableTesting);
    ADD_TEST(enumMacroSuite, EnumMultiplicationTesting);
    ADD_TEST(enumMacroSuite, EnumNegateTesting);
    ADD_TEST(enumMacroSuite, EnumIncrementableTesting);
    ADD_TEST(enumMacroSuite, EnumDecrementableTesting);
    ADD_TEST(enumMacroSuite, EnumAndableTesting);
    ADD_TEST(enumMacroSuite, EnumOrableTesting);
    ADD_TEST(enumMacroSuite, EnumXorableTesting);
    ADD_TEST(enumMacroSuite, EnumShiftableTesting);

    return enumMacroSuite;
}

CoreTools::Suite System::TestingHelper::GetOpenGLMacroSuite()
{
    auto openGLMacroSuite = GenerateSuite("OpenGL��"s);

    ADD_TEST(openGLMacroSuite, WglExtensionsMacroTesting);
    ADD_TEST(openGLMacroSuite, GlxExtensionsMacroTesting);
    ADD_TEST(openGLMacroSuite, GlPluginMacroTesting);
    openGLMacroSuite.AddSuite(GetGlUtilityMacroSuite());

    return openGLMacroSuite;
}

CoreTools::Suite System::TestingHelper::GetGlUtilityMacroSuite()
{
    auto glUtilityMacroSuite = GenerateSuite("OpenGL���ߺ�"s);

    ADD_TEST(glUtilityMacroSuite, GlUtilityMarkTesting);
    ADD_TEST(glUtilityMacroSuite, GlUtilityGetFunctionTesting);
    ADD_TEST(glUtilityMacroSuite, GlUtilityPreviouslyBodyTesting);
    ADD_TEST(glUtilityMacroSuite, GlUtilityPreviouslyBodyResultTesting);
    ADD_TEST(glUtilityMacroSuite, GlUtilityBodyTesting);
    ADD_TEST(glUtilityMacroSuite, GlUtilityBodyResultTesting);

    return glUtilityMacroSuite;
}

void System::TestingHelper::AddSystemOutputSuite()
{
    auto systemOutputSuite = GenerateSuite("ϵͳ���"s);

    ADD_TEST(systemOutputSuite, MessageBoxFlagsDataTesting);
    ADD_TEST(systemOutputSuite, LanguageIDDataTesting);
    ADD_TEST(systemOutputSuite, OutputDebugStringTesting);
    systemOutputSuite.AddSuite(GetMessageBoxSelectionSuite());

    AddSuite(systemOutputSuite);
}

CoreTools::Suite System::TestingHelper::GetMessageBoxSelectionSuite()
{
    auto messageBoxSelectionSuite = GenerateSuite("��Ϣ��ѡ��"s);

    ADD_TEST(messageBoxSelectionSuite, MessageBoxSelectionUseYesNoCancelTesting);
    ADD_TEST(messageBoxSelectionSuite, MessageBoxSelectionUseFlagsDataTesting);
    ADD_TEST(messageBoxSelectionSuite, MessageBoxSelectionUseLanguageIDDataTesting);

    return messageBoxSelectionSuite;
}

void System::TestingHelper::AddDynamicLinkSuite()
{
    auto dynamicLinkSuite = GenerateSuite("��̬���ӿ�"s);

    dynamicLinkSuite.AddSuite(GetLoadLibrarySuite());
    dynamicLinkSuite.AddSuite(GetLibraryToolsSuite());
    ADD_TEST(dynamicLinkSuite, LibraryDirectoryTesting);
    dynamicLinkSuite.AddSuite(GetLoadResourceToolsSuite());
    ADD_TEST(dynamicLinkSuite, EnumResourceDataTesting);
    dynamicLinkSuite.AddSuite(GetEnumResourceToolsSuite());

    AddSuite(dynamicLinkSuite);
}

CoreTools::Suite System::TestingHelper::GetLoadLibrarySuite()
{
    auto loadLibrarySuite = GenerateSuite("���ض�̬���ӿ�"s);

    ADD_TEST(loadLibrarySuite, LoadLibraryTesting);
    ADD_TEST(loadLibrarySuite, GetProcAddressTesting);
    ADD_TEST(loadLibrarySuite, FreeLibraryTesting);

    return loadLibrarySuite;
}

CoreTools::Suite System::TestingHelper::GetLibraryToolsSuite()
{
    auto libraryToolsSuite = GenerateSuite("��̬���ӿ⹤��"s);

    ADD_TEST(libraryToolsSuite, GetModuleHandleTesting);
    ADD_TEST(libraryToolsSuite, GetModuleFileNameTesting);

    return libraryToolsSuite;
}

CoreTools::Suite System::TestingHelper::GetLoadResourceToolsSuite()
{
    auto loadResourceToolsSuite = GenerateSuite("������Դ����"s);

    ADD_TEST(loadResourceToolsSuite, FindResourceTesting);
    ADD_TEST(loadResourceToolsSuite, LoadResourceTesting);
    ADD_TEST(loadResourceToolsSuite, LoadStringTesting);

    return loadResourceToolsSuite;
}

CoreTools::Suite System::TestingHelper::GetEnumResourceToolsSuite()
{
    auto enumResourceToolsSuite = GenerateSuite("ö����Դ����"s);

    ADD_TEST(enumResourceToolsSuite, EnumResourceToolsTesting);
    ADD_TEST(enumResourceToolsSuite, ResourceEnumTesting);

    return enumResourceToolsSuite;
}

void System::TestingHelper::AddCharacterStringSuite()
{
    auto characterStringSuite = GenerateSuite("�ַ�����"s);

    characterStringSuite.AddSuite(GetFormatErrorMessageSuite());
    characterStringSuite.AddSuite(GetCodePageSuite());
    characterStringSuite.AddSuite(GetStringConversionSuite());
    characterStringSuite.AddSuite(GetFormatStringSuite());

    AddSuite(characterStringSuite);
}

CoreTools::Suite System::TestingHelper::GetFormatErrorMessageSuite()
{
    auto formatErrorMessageSuite = GenerateSuite("��ʽ��������Ϣ"s);

    ADD_TEST(formatErrorMessageSuite, FormatErrorMessageUseLocalAllocTesting);
    ADD_TEST(formatErrorMessageSuite, FormatErrorMessageUseBufferTesting);
    ADD_TEST(formatErrorMessageSuite, FormatErrorMessageUseDllMoudleAndLocalAllocTesting);
    ADD_TEST(formatErrorMessageSuite, FormatErrorMessageUseDllMoudleAndUseBufferTesting);
    ADD_TEST(formatErrorMessageSuite, FormatErrorMessageTesting);
    ADD_TEST(formatErrorMessageSuite, FormatStringMessageUseArgumentArrayAndLocalAllocTesting);
    ADD_TEST(formatErrorMessageSuite, FormatStringMessageUseArgumentArrayAndBufferTesting);
    ADD_TEST(formatErrorMessageSuite, FormatStringMessageUseVaListAndLocalAllocTesting);
    ADD_TEST(formatErrorMessageSuite, FormatStringMessageUseVaListAndUseBufferTesting);
    ADD_TEST(formatErrorMessageSuite, SoftwareExceptionTesting);

    return formatErrorMessageSuite;
}

CoreTools::Suite System::TestingHelper::GetCodePageSuite()
{
    auto codePageSuite = GenerateSuite("����ҳ"s);

    ADD_TEST(codePageSuite, CodePageValidTesting);
    ADD_TEST(codePageSuite, CodePageTesting);

    return codePageSuite;
}

CoreTools::Suite System::TestingHelper::GetStringConversionSuite()
{
    auto stringConversionSuite = GenerateSuite("�ַ���ת��"s);

    ADD_TEST(stringConversionSuite, MultiByteConversionWideCharTesting);
    ADD_TEST(stringConversionSuite, WideCharConversionMultiByteTesting);
    ADD_TEST(stringConversionSuite, UTF8ConversionWideCharTesting);
    ADD_TEST(stringConversionSuite, WideCharConversionUTF8Testing);
    ADD_TEST(stringConversionSuite, CompareStringUseLocaleFlagsTesting);
    ADD_TEST(stringConversionSuite, CompareStringUseLocaleStringTesting);
    ADD_TEST(stringConversionSuite, CompareStringOrdinalUseBinaryTesting);
    ADD_TEST(stringConversionSuite, CaseInsensitiveComparisonTesting);

    return stringConversionSuite;
}

CoreTools::Suite System::TestingHelper::GetFormatStringSuite()
{
    auto formatStringSuite = GenerateSuite("��ʽ����Ϣ"s);

    ADD_TEST(formatStringSuite, VsnPrintfTesting);
    ADD_TEST(formatStringSuite, StrcatTesting);
    ADD_TEST(formatStringSuite, StrlenTesting);
    ADD_TEST(formatStringSuite, StrcpyTesting);
    ADD_TEST(formatStringSuite, StrtokTesting);
    ADD_TEST(formatStringSuite, StrstrTesting);
    ADD_TEST(formatStringSuite, SNPrintfTesting);

    return formatStringSuite;
}

void System::TestingHelper::AddConsoleSuite()
{
    auto consoleSuite = GenerateSuite("����̨"s);

    ADD_TEST(consoleSuite, ConsoleHandleTesting);
    consoleSuite.AddSuite(GetConsoleColoursSuite());
    consoleSuite.AddSuite(GetConsoleScreenBufferSuite());
    ADD_TEST(consoleSuite, ConsoleFontTesting);
    ADD_TEST(consoleSuite, ConsoleModeTesting);
    ADD_TEST(consoleSuite, ConsoleCodePageTesting);
    ADD_TEST(consoleSuite, ConsoleCreateTesting);

    AddSuite(consoleSuite);
}

CoreTools::Suite System::TestingHelper::GetConsoleColoursSuite()
{
    auto consoleColoursSuite = GenerateSuite("����̨��ɫ"s);

    ADD_TEST(consoleColoursSuite, TextColourTesting);
    ADD_TEST(consoleColoursSuite, BackgroundColourTesting);
    ADD_TEST(consoleColoursSuite, ConsoleCommonTesting);
    ADD_TEST(consoleColoursSuite, DefaultTextAttributeTesting);
    ADD_TEST(consoleColoursSuite, ReadAttributeTesting);
    ADD_TEST(consoleColoursSuite, WriteAttributeTesting);
    ADD_TEST(consoleColoursSuite, FillAttributeTesting);

    return consoleColoursSuite;
}

CoreTools::Suite System::TestingHelper::GetConsoleScreenBufferSuite()
{
    auto consoleScreenBufferSuite = GenerateSuite("����̨������"s);

    ADD_TEST(consoleScreenBufferSuite, CreateSystemConsoleScreenBufferTesting);
    ADD_TEST(consoleScreenBufferSuite, ConsoleScreenBufferInfoTesting);
    ADD_TEST(consoleScreenBufferSuite, SetConsoleHandleScreenBufferInfoTesting);
    ADD_TEST(consoleScreenBufferSuite, SetSystemConsoleScreenBufferSizeTesting);

    return consoleScreenBufferSuite;
}

void System::TestingHelper::AddMemoryToolsSuite()
{
    auto memoryToolsSuite = GenerateSuite("�ڴ湤�߿�"s);

    memoryToolsSuite.AddSuite(GetHeapToolsSuite());
    memoryToolsSuite.AddSuite(GetVirtualToolsSuite());
    memoryToolsSuite.AddSuite(GetViewOfFileSuite());
    memoryToolsSuite.AddSuite(GetMemoryHelperSuite());
    memoryToolsSuite.AddSuite(GetLocalToolsSuite());

    AddSuite(memoryToolsSuite);
}

CoreTools::Suite System::TestingHelper::GetHeapToolsSuite()
{
    auto heapToolsSuite = GenerateSuite("�ѹ��߿�"s);

    ADD_TEST(heapToolsSuite, CreateHeapTesting);
    ADD_TEST(heapToolsSuite, AllocateHeapTesting);
    ADD_TEST(heapToolsSuite, AllocateGenerateExceptionsTesting);
    ADD_TEST(heapToolsSuite, ReAllocateHeapTesting);
    ADD_TEST(heapToolsSuite, ValidateHeapTesting);
    ADD_TEST(heapToolsSuite, CompactHeapTesting);
    ADD_TEST(heapToolsSuite, CurrentProcessHeapTesting);

    return heapToolsSuite;
}

CoreTools::Suite System::TestingHelper::GetVirtualToolsSuite()
{
    auto virtualToolsSuite = GenerateSuite("�����ڴ湤�߿�"s);

    ADD_TEST(virtualToolsSuite, AllocateVirtualOneStepTesting);
    ADD_TEST(virtualToolsSuite, AllocateVirtualSeparationTesting);
    ADD_TEST(virtualToolsSuite, VirtualProtectTesting);
    ADD_TEST(virtualToolsSuite, VirtualQueryTesting);

    return virtualToolsSuite;
}

CoreTools::Suite System::TestingHelper::GetViewOfFileSuite()
{
    auto viewOfFileSuite = GenerateSuite("�ļ�ӳ���"s);

    ADD_TEST(viewOfFileSuite, CreateFileMappingTesting);
    ADD_TEST(viewOfFileSuite, OpenFileMappingTesting);
    ADD_TEST(viewOfFileSuite, ViewOfFileTesting);

    return viewOfFileSuite;
}

CoreTools::Suite System::TestingHelper::GetMemoryHelperSuite()
{
    auto memoryHelperSuite = GenerateSuite("�ڴ������"s);

    ADD_TEST(memoryHelperSuite, MemorySetTesting);
    ADD_TEST(memoryHelperSuite, MemoryCopyTesting);
    ADD_TEST(memoryHelperSuite, MallocMemoryTesting);
    ADD_TEST(memoryHelperSuite, FillMemoryTesting);
    ADD_TEST(memoryHelperSuite, GetWindowsStructDefaultSizeTesting);

    return memoryHelperSuite;
}

CoreTools::Suite System::TestingHelper::GetLocalToolsSuite()
{
    auto localToolsSuite = GenerateSuite("�ֲ��ڴ��"s);

    ADD_TEST(localToolsSuite, LocalMemoryAllocTesting);
    ADD_TEST(localToolsSuite, LocalMemorySizeTesting);

    return localToolsSuite;
}

void System::TestingHelper::AddThreadingSuite()
{
    auto threadingSuite = GenerateSuite("�߳̿�"s);

    threadingSuite.AddSuite(GetCriticalSectionSuite());
    threadingSuite.AddSuite(GetSemaphoreSuite());
    threadingSuite.AddSuite(GetEventSuite());
    threadingSuite.AddSuite(GetMutexSuite());
    threadingSuite.AddSuite(GetSlimReaderWriterSuite());
    threadingSuite.AddSuite(GetConditionVariableSuite());
    threadingSuite.AddSuite(GetInitOnceSuite());
    threadingSuite.AddSuite(GetWaitableTimerSuite());
    threadingSuite.AddSuite(GetSyncToolsSuite());
    threadingSuite.AddSuite(GetInterlockedSuite());
    threadingSuite.AddSuite(GetThreadSuite());
    threadingSuite.AddSuite(GetThreadToolsSuite());
    ADD_TEST(threadingSuite, ThreadLocalStorageTesting);
    threadingSuite.AddSuite(GetProcessSuite());
    threadingSuite.AddSuite(GetProcessToolsSuite());

    AddSuite(threadingSuite);
}

CoreTools::Suite System::TestingHelper::GetCriticalSectionSuite()
{
    auto criticalSectionSuite = GenerateSuite("�ٽ���"s);

    ADD_TEST(criticalSectionSuite, CriticalSectionTesting);
    ADD_TEST(criticalSectionSuite, CriticalSectionThreadTesting);
    ADD_TEST(criticalSectionSuite, SpecifyCriticalSectionTesting);
    ADD_TEST(criticalSectionSuite, SpecifyCriticalSectionAndSpinCountTesting);

    return criticalSectionSuite;
}

CoreTools::Suite System::TestingHelper::GetSemaphoreSuite()
{
    auto semaphoreSuite = GenerateSuite("�ź���"s);

    ADD_TEST(semaphoreSuite, CreateSemaphoreThreadTesting);
    ADD_TEST(semaphoreSuite, CreateSemaphoreThreadUseNameTesting);
    ADD_TEST(semaphoreSuite, ReleaseSemaphoreTesting);
    ADD_TEST(semaphoreSuite, WaitSemaphoreTesting);
    ADD_TEST(semaphoreSuite, WaitMultipleSemaphoreTesting);
    ADD_TEST(semaphoreSuite, OpenSemaphoreTesting);

    return semaphoreSuite;
}

CoreTools::Suite System::TestingHelper::GetEventSuite()
{
    auto eventSuite = GenerateSuite("�¼�����"s);

    ADD_TEST(eventSuite, CreateEventTesting);
    ADD_TEST(eventSuite, CreateEventUseNameTesting);
    ADD_TEST(eventSuite, ManualEventThreadTesting);
    ADD_TEST(eventSuite, AutoEventThreadTesting);
    ADD_TEST(eventSuite, ResetEventTesting);
    ADD_TEST(eventSuite, WaitForEventTesting);
    ADD_TEST(eventSuite, WaitForMultipleEventTesting);
    ADD_TEST(eventSuite, OpenEventTesting);

    return eventSuite;
}

CoreTools::Suite System::TestingHelper::GetMutexSuite()
{
    auto mutexSuite = GenerateSuite("������"s);

    ADD_TEST(mutexSuite, CreateDefaultMutexTesting);
    ADD_TEST(mutexSuite, CreateMutexTesting);
    ADD_TEST(mutexSuite, CreateMutexUseFlagsTesting);
    ADD_TEST(mutexSuite, ThreadMutexTesting);
    ADD_TEST(mutexSuite, WaitForMutexTesting);
    ADD_TEST(mutexSuite, WaitForMultipleMutexTesting);
    ADD_TEST(mutexSuite, OpenMutexTesting);
    ADD_TEST(mutexSuite, PThreadMutexTesting);

    return mutexSuite;
}

CoreTools::Suite System::TestingHelper::GetSlimReaderWriterSuite()
{
    auto slimReaderWriterSuite = GenerateSuite("��д��"s);

    ADD_TEST(slimReaderWriterSuite, SlimReaderWriterInitializeTesting);
    ADD_TEST(slimReaderWriterSuite, SlimReaderWriterReaderTesting);
    ADD_TEST(slimReaderWriterSuite, SlimReaderWriterWriterTesting);

    return slimReaderWriterSuite;
}

CoreTools::Suite System::TestingHelper::GetConditionVariableSuite()
{
    auto conditionVariableSuite = GenerateSuite("��������"s);

    ADD_TEST(conditionVariableSuite, ConditionVariableSlimReaderWriterLockTesting);
    ADD_TEST(conditionVariableSuite, ConditionVariableCriticalSectionTesting);

    return conditionVariableSuite;
}

CoreTools::Suite System::TestingHelper::GetInitOnceSuite()
{
    auto initOnceSuite = GenerateSuite("һ�ζ���"s);

    ADD_TEST(initOnceSuite, InitOnceSynchronousTesting);
    ADD_TEST(initOnceSuite, InitOnceAsynchronousTesting);

    return initOnceSuite;
}

CoreTools::Suite System::TestingHelper::GetWaitableTimerSuite()
{
    auto waitableTimerSuite = GenerateSuite("��ʱ��"s);

    ADD_TEST(waitableTimerSuite, CreateWaitableTimerManualTesting);
    ADD_TEST(waitableTimerSuite, CreateWaitableTimerSynchronizationTesting);
    ADD_TEST(waitableTimerSuite, CreateWaitableTimerUseNameTesting);
    ADD_TEST(waitableTimerSuite, CreateWaitableTimerManualUseFlagsTesting);
    ADD_TEST(waitableTimerSuite, CreateWaitableTimerSynchronizationUseFlagsTesting);
    ADD_TEST(waitableTimerSuite, OpenWaitableTimerTesting);
    ADD_TEST(waitableTimerSuite, WaitForWaitableTimerTesting);
    ADD_TEST(waitableTimerSuite, WaitForMultipleWaitableTimerTesting);
    ADD_TEST(waitableTimerSuite, CancelWaitableTimerTesting);
    ADD_TEST(waitableTimerSuite, SetWaitableTimerTesting);

    return waitableTimerSuite;
}

CoreTools::Suite System::TestingHelper::GetSyncToolsSuite()
{
    auto syncToolsSuite = GenerateSuite("ͬ������"s);

    ADD_TEST(syncToolsSuite, SleepTesting);
    ADD_TEST(syncToolsSuite, SignalObjectAndWaitTesting);

    return syncToolsSuite;
}

CoreTools::Suite System::TestingHelper::GetInterlockedSuite()
{
    auto interlockedSuite = GenerateSuite("ԭ�Ӳ���"s);

    ADD_TEST(interlockedSuite, InterlockedTesting);
    ADD_TEST(interlockedSuite, InterlockedSubtractTesting);
    ADD_TEST(interlockedSuite, InterlockedBinaryTesting);

    return interlockedSuite;
}

CoreTools::Suite System::TestingHelper::GetThreadSuite()
{
    auto threadSuite = GenerateSuite("�߳�"s);

    ADD_TEST(threadSuite, CreateDefaultThreadTesting);
    ADD_TEST(threadSuite, CreateSuspendedThreadTesting);
    ADD_TEST(threadSuite, CreateCThreadTesting);
    ADD_TEST(threadSuite, GetCurrentThreadTesting);
    ADD_TEST(threadSuite, ThreadPriorityTesting);
    ADD_TEST(threadSuite, WaitForThreadTesting);
    ADD_TEST(threadSuite, WaitForMultipleThreadTesting);

    return threadSuite;
}

CoreTools::Suite System::TestingHelper::GetThreadToolsSuite()
{
    auto threadToolsSuite = GenerateSuite("�̹߳���"s);

    ADD_TEST(threadToolsSuite, OpenThreadTesting);
    ADD_TEST(threadToolsSuite, PriorityBoostTesting);
    ADD_TEST(threadToolsSuite, ThreadTokenTesting);
    ADD_TEST(threadToolsSuite, ThreadTimesTesting);

    return threadToolsSuite;
}

CoreTools::Suite System::TestingHelper::GetProcessSuite()
{
    auto processSuite = GenerateSuite("����"s);

    ADD_TEST(processSuite, CreateDefaultProcessTesting);
    ADD_TEST(processSuite, CreateProcessTesting);
    ADD_TEST(processSuite, GetProcessHandleTesting);
    ADD_TEST(processSuite, ProcessPriorityClassTesting);
    ADD_TEST(processSuite, OpenProcessTesting);

    return processSuite;
}

CoreTools::Suite System::TestingHelper::GetProcessToolsSuite()
{
    auto processToolsSuite = GenerateSuite("���̹���"s);

    ADD_TEST(processToolsSuite, ProcessTokenTesting);

    return processToolsSuite;
}

void System::TestingHelper::AddTimeSuite()
{
    auto timeSuite = GenerateSuite("ʱ��"s);

    ADD_TEST(timeSuite, TimeOfDayDataTesting);
    ADD_TEST(timeSuite, DeltaTimeValueDataTesting);
    ADD_TEST(timeSuite, DeltaTimeTesting);
    ADD_TEST(timeSuite, SystemPauseTesting);

    AddSuite(timeSuite);
}

void System::TestingHelper::AddFileManagerSuite()
{
    auto fileManagerSuite = GenerateSuite("�ļ�������"s);

    fileManagerSuite.AddSuite(GetCFileSuite());
    fileManagerSuite.AddSuite(GetFileSuite());
    fileManagerSuite.AddSuite(GetFileToolsSuite());
    fileManagerSuite.AddSuite(GetFileTimeSuite());
    ADD_TEST(fileManagerSuite, EnvironmentVariableTesting);

    AddSuite(fileManagerSuite);
}

CoreTools::Suite System::TestingHelper::GetCFileSuite()
{
    auto cFileSuite = GenerateSuite("C�����ļ�"s);

    ADD_TEST(cFileSuite, CFileOpenTesting);
    ADD_TEST(cFileSuite, CFileReadTesting);
    ADD_TEST(cFileSuite, CFileWriteTesting);
    ADD_TEST(cFileSuite, CFileSetvBufTesting);
    ADD_TEST(cFileSuite, CFileCharacterTesting);
    ADD_TEST(cFileSuite, CFileOperatorTesting);

    return cFileSuite;
}

CoreTools::Suite System::TestingHelper::GetFileSuite()
{
    auto fileSuite = GenerateSuite("�ļ�"s);

    ADD_TEST(fileSuite, CreateExistingFileTesting);
    ADD_TEST(fileSuite, CreateFileWithDefaultAttributesTesting);
    ADD_TEST(fileSuite, CreateFileWithOtherFlagsTesting);
    ADD_TEST(fileSuite, CreateFileWithSecurityFlagsTesting);
    ADD_TEST(fileSuite, DirectoryTesting);
    ADD_TEST(fileSuite, CreateFileWithAttributesTesting);
    ADD_TEST(fileSuite, MoveFileTesting);
    ADD_TEST(fileSuite, FileLengthTesting);
    ADD_TEST(fileSuite, CopyFileTesting);
    ADD_TEST(fileSuite, FileHandlePointerTesting);
    ADD_TEST(fileSuite, OpenFileTesting);
    ADD_TEST(fileSuite, ReadFileTesting);
    ADD_TEST(fileSuite, WriteFileTesting);

    return fileSuite;
}

CoreTools::Suite System::TestingHelper::GetFileToolsSuite()
{
    auto fileToolsSuite = GenerateSuite("�ļ�����"s);

    ADD_TEST(fileToolsSuite, CreateDirectoryTesting);
    ADD_TEST(fileToolsSuite, DiskFreeTesting);

    return fileToolsSuite;
}

CoreTools::Suite System::TestingHelper::GetFileTimeSuite()
{
    auto fileTimeSuite = GenerateSuite("�ļ�ʱ��"s);

    ADD_TEST(fileTimeSuite, FileTimeCompareTesting);
    ADD_TEST(fileTimeSuite, FileTimeConvertTesting);
    ADD_TEST(fileTimeSuite, FileTimeTesting);

    return fileTimeSuite;
}

void System::TestingHelper::AddSecuritySuite()
{
    auto securitySuite = GenerateSuite("��ȫ��"s);

    ADD_TEST(securitySuite, LookupPrivilegeTesting);
    securitySuite.AddSuite(GetCreateSecuritySuite());
    securitySuite.AddSuite(GetSecuritySidSuite());
    securitySuite.AddSuite(GetSecurityAclSuite());
    securitySuite.AddSuite(GetSecurityDescriptorSuite());
    securitySuite.AddSuite(GetSecurityAceSuite());
    securitySuite.AddSuite(GetAddAccessSuite());
    securitySuite.AddSuite(GetSecurityBaseSuite());
    securitySuite.AddSuite(GetAccessCheckSuite());

    AddSuite(securitySuite);
}

CoreTools::Suite System::TestingHelper::GetCreateSecuritySuite()
{
    auto createSecuritySuite = GenerateSuite("������ȫ"s);

    ADD_TEST(createSecuritySuite, FileSecurityTesting);
    ADD_TEST(createSecuritySuite, KernelObjectSecurityTesting);
    ADD_TEST(createSecuritySuite, CreatePrivateObjectSecurityTesting);
    ADD_TEST(createSecuritySuite, CreateFilePrivateObjectSecurityTesting);
    ADD_TEST(createSecuritySuite, CreatePrivateObjectSecurityUseAutoInheritTesting);
    ADD_TEST(createSecuritySuite, CreatePrivateObjectSecurityWithMultipleInheritanceTesting);
    ADD_TEST(createSecuritySuite, SetPrivateObjectSecurityTesting);
    ADD_TEST(createSecuritySuite, ConvertToAutoInheritPrivateObjectSecurityTesting);
    ADD_TEST(createSecuritySuite, SecurityAccessMaskTesting);

    return createSecuritySuite;
}

CoreTools::Suite System::TestingHelper::GetSecuritySidSuite()
{
    auto securitySidSuite = GenerateSuite("��ȫϵͳʶ����"s);

    ADD_TEST(securitySidSuite, InitializeSecurityIdentifierTesting);
    ADD_TEST(securitySidSuite, GetSubAuthorityTesting);
    ADD_TEST(securitySidSuite, WellKnownSidTesting);
    ADD_TEST(securitySidSuite, CopySecurityIdentifierTesting);

    return securitySidSuite;
}

CoreTools::Suite System::TestingHelper::GetSecurityAclSuite()
{
    auto securityAclSuite = GenerateSuite("���ʿ����б�"s);

    ADD_TEST(securityAclSuite, InitializeAclTesting);
    ADD_TEST(securityAclSuite, AclInformationTesting);

    return securityAclSuite;
}

CoreTools::Suite System::TestingHelper::GetSecurityDescriptorSuite()
{
    auto securityDescriptorSuite = GenerateSuite("��ȫ������"s);

    ADD_TEST(securityDescriptorSuite, UserObjectSecurityTesting);
    ADD_TEST(securityDescriptorSuite, InitializeSecurityDescriptorTesting);
    ADD_TEST(securityDescriptorSuite, SecurityDescriptorDaclTesting);
    ADD_TEST(securityDescriptorSuite, SecurityDescriptorControlTesting);
    ADD_TEST(securityDescriptorSuite, SecurityDescriptorGroupTesting);
    ADD_TEST(securityDescriptorSuite, SecurityDescriptorOwnerTesting);
    ADD_TEST(securityDescriptorSuite, SecurityDescriptorRMControlTesting);
    ADD_TEST(securityDescriptorSuite, SecurityDescriptorSaclTesting);

    return securityDescriptorSuite;
}

CoreTools::Suite System::TestingHelper::GetSecurityAceSuite()
{
    auto securityAceSuite = GenerateSuite("���ʿ�����"s);

    ADD_TEST(securityAceSuite, AddAccessControlEntriesTesting);
    ADD_TEST(securityAceSuite, FindFirstFreeAccessControlEntriesTesting);
    ADD_TEST(securityAceSuite, AddMandatoryAceTesting);

    return securityAceSuite;
}

CoreTools::Suite System::TestingHelper::GetAddAccessSuite()
{
    auto addAccessSuite = GenerateSuite("���ӷ���"s);

    ADD_TEST(addAccessSuite, AddAccessAllowedAceTesting);
    ADD_TEST(addAccessSuite, AddAccessAllowedAceUseAceFlagsTesting);
    ADD_TEST(addAccessSuite, AddAccessAllowedObjectAceTesting);
    ADD_TEST(addAccessSuite, AddAccessDeniedAceTesting);
    ADD_TEST(addAccessSuite, AddAccessDeniedObjectAceTesting);
    ADD_TEST(addAccessSuite, AddAuditAccessAceTesting);
    ADD_TEST(addAccessSuite, AddAuditAccessObjectAceTesting);

    return addAccessSuite;
}

CoreTools::Suite System::TestingHelper::GetSecurityBaseSuite()
{
    auto securityBaseSuite = GenerateSuite("��ȫ����"s);

    ADD_TEST(securityBaseSuite, IsSystemTokenElevatedTesting);
    ADD_TEST(securityBaseSuite, TokenInformationTesting);
    ADD_TEST(securityBaseSuite, AdjustTokenTesting);
    ADD_TEST(securityBaseSuite, AccessesGrantedTesting);
    ADD_TEST(securityBaseSuite, DuplicateTokenTesting);
    ADD_TEST(securityBaseSuite, RestrictedTokenTesting);
    ADD_TEST(securityBaseSuite, QuerySecurityAccessMaskTesting);

    return securityBaseSuite;
}

CoreTools::Suite System::TestingHelper::GetAccessCheckSuite()
{
    auto accessCheckSuite = GenerateSuite("���ʼ��"s);

    ADD_TEST(accessCheckSuite, MapGenericMaskTesting);
    ADD_TEST(accessCheckSuite, AccessCheckTesting);

    return accessCheckSuite;
}

void System::TestingHelper::AddNetworkSuite()
{
    auto networkSuite = GenerateSuite("����"s);

    networkSuite.AddSuite(GetSocketPrototypesSuite());
    networkSuite.AddSuite(GetDatabasePrototypesSuite());
    ADD_TEST(networkSuite, WindowsExtensionPrototypesTesting);
    networkSuite.AddSuite(GetWindowsSockExSuite());

    AddSuite(networkSuite);
}

CoreTools::Suite System::TestingHelper::GetSocketPrototypesSuite()
{
    auto socketPrototypesSuite = GenerateSuite("�׽���ԭ��"s);

    ADD_TEST(socketPrototypesSuite, GetSocketTesting);
    ADD_TEST(socketPrototypesSuite, HostNetConversionTesting);
    ADD_TEST(socketPrototypesSuite, AcceptTesting);
    ADD_TEST(socketPrototypesSuite, ConnectTesting);
    ADD_TEST(socketPrototypesSuite, SocketNameTesting);
    ADD_TEST(socketPrototypesSuite, SockOptTesting);
    ADD_TEST(socketPrototypesSuite, IoctlSocketTesting);
    ADD_TEST(socketPrototypesSuite, ShutDownTesting);
    ADD_TEST(socketPrototypesSuite, RecvFromTesting);
    ADD_TEST(socketPrototypesSuite, SendToTesting);
    ADD_TEST(socketPrototypesSuite, SelectTesting);

    return socketPrototypesSuite;
}

CoreTools::Suite System::TestingHelper::GetDatabasePrototypesSuite()
{
    auto databasePrototypesSuite = GenerateSuite("����ԭ��"s);

    ADD_TEST(databasePrototypesSuite, WinSockHostTesting);
    ADD_TEST(databasePrototypesSuite, WinSockServentTesting);
    ADD_TEST(databasePrototypesSuite, WinSockProtoentTesting);

    return databasePrototypesSuite;
}

CoreTools::Suite System::TestingHelper::GetWindowsSockExSuite()
{
    auto windowsSockExSuite = GenerateSuite("Windows�׽�����չ"s);

    ADD_TEST(windowsSockExSuite, GetWinSocketTesting);
    ADD_TEST(windowsSockExSuite, WinSocketAcceptTesting);
    ADD_TEST(windowsSockExSuite, WinSocketConnectTesting);
    ADD_TEST(windowsSockExSuite, WinSocketConnectByNameTesting);
    ADD_TEST(windowsSockExSuite, WinSocketHostNetConversionTesting);
    ADD_TEST(windowsSockExSuite, WinSocketRecvFromTesting);
    ADD_TEST(windowsSockExSuite, WinSocketSendToTesting);

    return windowsSockExSuite;
}

void System::TestingHelper::AddOpenGLSuite()
{
    auto openGLSuite = GenerateSuite("OpenGL"s);

    ADD_TEST(openGLSuite, OpenGLUtilityTesting);
    ADD_TEST(openGLSuite, OpenGLGlutTesting);
    ADD_TEST(openGLSuite, OpenGLAPITesting);
    ADD_TEST(openGLSuite, OpenGLProgramTesting);
    ADD_TEST(openGLSuite, OpenGLShaderTesting);
    ADD_TEST(openGLSuite, OpenGLInitTesting);
    ADD_TEST(openGLSuite, OpenGLWglPrototypesTesting);

    AddSuite(openGLSuite);
}

void System::TestingHelper::AddDirectXSuite()
{
    auto directXSuite = GenerateSuite("DirectX"s);

    ADD_TEST(directXSuite, DirectXD3D11Testing);

    AddSuite(directXSuite);
}

void System::TestingHelper::AddWindowsSuite()
{
    auto windowsSuite = GenerateSuite("Windows"s);

    ADD_TEST(windowsSuite, LastPlatformErrorTesting);
    ADD_TEST(windowsSuite, WindowsCreateTesting);
    ADD_TEST(windowsSuite, WindowsProcessTesting);
    ADD_TEST(windowsSuite, WindowsRegisterTesting);
    ADD_TEST(windowsSuite, WindowsFontInformationTesting);
    AddSuite(GetWindowsSystemSuite());
    ADD_TEST(windowsSuite, WindowsNamedPipeTesting);
    ADD_TEST(windowsSuite, WindowsUserTesting);
    ADD_TEST(windowsSuite, EngineeringTesting);

    AddSuite(windowsSuite);
}

CoreTools::Suite System::TestingHelper::GetWindowsSystemSuite()
{
    auto windowsSystemSuite = GenerateSuite("Windowsϵͳ"s);

    ADD_TEST(windowsSystemSuite, GetSystemInfoTesting);
    ADD_TEST(windowsSystemSuite, DebugBreakTesting);
    ADD_TEST(windowsSystemSuite, ExitTesting);
    ADD_TEST(windowsSystemSuite, SystemCommandTesting);
    ADD_TEST(windowsSystemSuite, SystemDirectoryTesting);
    ADD_TEST(windowsSystemSuite, GetSystemUserNameTesting);
    ADD_TEST(windowsSystemSuite, BoolConversionTesting);
    ADD_TEST(windowsSystemSuite, GetSystemInputTesting);

    return windowsSystemSuite;
}

void System::TestingHelper::AddLinuxSuite()
{
    auto linuxSuite = GenerateSuite("Linux"s);

    ADD_TEST(linuxSuite, LinuxNativeWindowTesting);

    AddSuite(linuxSuite);
}

void System::TestingHelper::AddMacintoshSuite()
{
    auto macintoshSuite = GenerateSuite("Macintosh"s);

    ADD_TEST(macintoshSuite, MacintoshNativeWindowTesting);

    AddSuite(macintoshSuite);
}

void System::TestingHelper::AddAndroidSuite()
{
    auto androidSuite = GenerateSuite("��׿"s);

    ADD_TEST(androidSuite, AndroidInputKeyEventTesting);
    ADD_TEST(androidSuite, AndroidInputMotionEventTesting);
    ADD_TEST(androidSuite, AndroidLooperTesting);
    ADD_TEST(androidSuite, AndroidInputQueueTesting);
    ADD_TEST(androidSuite, AndroidNativeWindowTesting);
    ADD_TEST(androidSuite, AndroidNativeAppGlueTesting);

    AddSuite(androidSuite);
}