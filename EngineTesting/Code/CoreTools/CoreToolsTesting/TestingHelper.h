/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.0 (2024/08/09 22:02)

#ifndef CORE_TOOLS_TESTING_TESTING_HELPER_H
#define CORE_TOOLS_TESTING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace CoreTools
{
    class TestingHelper final : public CMainFunctionTestingHelper
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = CMainFunctionTestingHelper;

    public:
        TestingHelper(int argc, char** argv);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void InitSuite();

        void AddHelperSuite();

        NODISCARD Suite GetAssertExceptionMacroSuite();
        NODISCARD Suite GetAssertTestMacroSuite();
        NODISCARD Suite GetClassInvariantMacroSuite();
        NODISCARD Suite GetCustomAssertMacroSuite();
        NODISCARD Suite GetExportMacroSuite();
        NODISCARD Suite GetLogMacroSuite();
        NODISCARD Suite GetMemberFunctionMacroSuite();
        NODISCARD Suite GetRttiMacroSuite();
        NODISCARD Suite GetStreamMacroSuite();
        NODISCARD Suite GetUnitTestSuiteMacroSuite();
        NODISCARD Suite GetExceptionMacroSuite();

        void AddContractSuite();

        NODISCARD Suite GetImplSuite();

        void AddBaseSuite();
        void AddCharacterStringSuite();

        NODISCARD Suite GetCaseInsensitiveStringSuite();
        NODISCARD Suite GetCodeMappingSuite();

        void AddExceptionSuite();
        void AddConsoleSuite();
        void AddThreadingSuite();
        void AddFileManagerSuite();

        NODISCARD Suite GetEndianSuite();
        NODISCARD Suite GetCFileManagerSuite();
        NODISCARD Suite GetStreamManagerSuite();
        NODISCARD Suite GetFileHandleSuite();
        NODISCARD Suite GetFileSuite();
        NODISCARD Suite GetBufferIOSuite();
        NODISCARD Suite GetEnvironmentSuite();
        NODISCARD Suite GetFileAsynchronousSuite();

        void AddTextParsingSuite();

        NODISCARD Suite GetSimpleZipSuite();
        NODISCARD Suite GetSimpleCSVSuite();
        NODISCARD Suite GetExcelSuite();
        NODISCARD Suite GetCSVSuite();

        NODISCARD Suite GetCommandSuite();
        NODISCARD Suite GetQuerySuite();

        void AddLogManagerSuite();
        void AddDataTypesSuite();
        void AddMemoryToolsSuite();
        void AddObjectSystemSuite();
        void AddTimeSuite();
        void AddReportOutputSuite();
        void AddUnitTestSuite();
        void AddTemplateToolsSuite();
        void AddCommandSuite();
        void AddMainFunctionHelperSuite();
        void AddModuleInitializerTerminatorSuite();
        void AddSyntacticParserSuite();
        void AddPerformanceProfilerSuite();
        void AddEngineConfigurationSuite();
        void AddPropertiesSuite();
        void AddCyclicRedundancyCheckSuite();
        void AddMessageEventSuite();
        void AddStateMachineSuite();
        void AddNetworkSuite();
        void AddCoroutineSuite();
    };
}

#endif  // CORE_TOOLS_TESTING_TESTING_HELPER_H