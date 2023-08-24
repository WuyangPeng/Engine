///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/04 11:03)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_H

#include "Framework/FrameworkDll.h"

#include "WindowMessageInterface.h"
#include "WindowProcessHandle.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(WindowMessageUnitTestSuiteImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE WindowMessageUnitTestSuite : public WindowMessageInterface
    {
    public:
        NON_COPY_TYPE_DECLARE(WindowMessageUnitTestSuite);
        using ParentType = WindowMessageInterface;

        using Suite = CoreTools::Suite;
        using OStreamShared = CoreTools::OStreamShared;
        using UnitTestComposite = CoreTools::UnitTestComposite;
        using UnitTestSharedPtr = std::shared_ptr<UnitTestComposite>;

    public:
        WindowMessageUnitTestSuite(int64_t delta, const std::string& suiteName);
        WindowMessageUnitTestSuite(int64_t delta, const std::string& suiteName, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetPassedNumber() const noexcept;

        NODISCARD LResult CreateMessage(HWnd hWnd, WParam wParam, LParam lParam) override;
        NODISCARD LResult KeyDownMessage(HWnd hWnd, WParam wParam, LParam lParam) override;
        void Display(HWnd hWnd, int64_t timeDelta) override;

    protected:
        NODISCARD bool IsPrintRun() const noexcept;
        NODISCARD OStreamShared GetStreamShared() noexcept;

        void AddSuite(const Suite& suite);
        void AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestSharedPtr& unitTest);

        template <typename TestType, typename... Types>
        void AddTest(Suite& suite, const std::string& suiteName, const std::string& testName, Types&&... args);

        NODISCARD Suite GenerateSuite(const std::string& name);

    private:
        virtual void InitSuite() = 0;

        NODISCARD LResult AddSuiteOnCreateMessage(HWnd hWnd, WParam wParam, LParam lParam);

    private:
        PackageType impl;
    };

    using WindowProcessUnitTestSuite = WindowProcessHandle<WindowMessageUnitTestSuite>;
}

#endif  // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_H
