///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/28 16:38)

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
        void AddTest(const std::string& suiteName, Suite& aSuite, const std::string& testName, const UnitTestSharedPtr& unitTest);

        NODISCARD bool IsPrintRun() const noexcept;

        NODISCARD int RunSuite();

        void AddSuite(const Suite& aSuite);

        template <typename TestType, typename... Types>
        void AddTest(Suite& aSuite, const std::string& suiteName, const std::string& testName, Types&&... args);

        NODISCARD Suite GenerateSuite(const std::string& name) const;

    private:
        NODISCARD int DoRun() override;

    private:
        TestingInformationHelper testingInformationHelper;
        Suite suite;
    };
}

#endif  // CORE_TOOLS_MAIN_FUNCTION_HELPER_C_MAIN_FUNCTION_TESTING_HELPER_H