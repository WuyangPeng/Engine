///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/07/29 18:57)

#ifndef CORE_TOOLS_TESTING_TESTING_HELPER_H
#define CORE_TOOLS_TESTING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

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
        void AddHandleManagerSuite();
        void AddResourceManagerSuite();
        void AddFrameMemorySystemSuite();
        void AddBitArraySuite();
        void AddModuleInitializerTerminatorSuite();
        void AddSyntacticParserSuite();
        void AddPerformanceProfilerSuite();
        void AddEngineConfigurationSuite();
        void AddPropertiesSuite();
        void AddCyclicRedundancyCheckSuite();
        void AddRegularExpressionSuite();
        void AddMessageEventSuite();
        void AddStateMachineSuite();
        void AddNetworkSuite();
        void AddZlibSuite();
        void AddFreetypeSuite();
    };
}

#endif  // CORE_TOOLS_TESTING_TESTING_HELPER_H