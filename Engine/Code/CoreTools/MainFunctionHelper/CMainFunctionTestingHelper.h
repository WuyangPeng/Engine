//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 18:29)

#ifndef CORE_TOOLS_MAIN_FUNCTION_HELPER_C_MAIN_FUNCTION_TESTING_HELPER_H
#define CORE_TOOLS_MAIN_FUNCTION_HELPER_C_MAIN_FUNCTION_TESTING_HELPER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "CMainFunctionHelper.h"
#include "TestingInformationHelper.h"
#include "CoreTools/UnitTestSuite/Suite.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CMainFunctionTestingHelper : public CMainFunctionHelper
    {
    public:
        using ClassType = CMainFunctionTestingHelper;
        using ParentType = CMainFunctionHelper;
        using UnitTestSharedPtr = std::shared_ptr<UnitTestComposite>;

    public:
        CMainFunctionTestingHelper(int argc, char** argv);
        CMainFunctionTestingHelper(int argc, char** argv, const std::string& suiteName);
        ~CMainFunctionTestingHelper() = 0;

        CMainFunctionTestingHelper(const CMainFunctionTestingHelper& rhs) = delete;
        CMainFunctionTestingHelper& operator=(const CMainFunctionTestingHelper& rhs) = delete;
        CMainFunctionTestingHelper(CMainFunctionTestingHelper&& rhs) noexcept;
        CMainFunctionTestingHelper& operator=(CMainFunctionTestingHelper&& rhs) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        using SuiteSharedPtr = std::shared_ptr<Suite>;

    protected:
        void AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestSharedPtr& unitTest);

        [[nodiscard]] bool IsPrintRun() const noexcept;

        [[nodiscard]] int RunSuite();

        void AddSuite(const Suite& suite);

        template <typename TestType, typename... Types>
        void AddTest(Suite& suite, const std::string& suiteName, const std::string& testName, Types&&... args);

        [[nodiscard]] Suite GenerateSuite(const std::string& name);

    private:
        [[nodiscard]] int DoRun() override;

    private:
        TestingInformationHelper m_TestingInformationHelper;
        Suite m_Suite;
    };
}

#endif  // CORE_TOOLS_MAIN_FUNCTION_HELPER_C_MAIN_FUNCTION_TESTING_HELPER_H