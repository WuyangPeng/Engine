///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:07)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_H

#include "Framework/FrameworkDll.h"

#include "WindowMessageInterface.h"
#include "WindowProcessHandleDetail.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/OStreamShared.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(WindowMessageUnitTestSuiteImpl);
EXPORT_SHARED_PTR(Framework, WindowMessageUnitTestSuiteStream, FRAMEWORK_DEFAULT_DECLARE);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE WindowMessageUnitTestSuite : public WindowMessageInterface
    {
    public:
        NON_COPY_TYPE_DECLARE(WindowMessageUnitTestSuite);
        using ParentType = WindowMessageInterface;
        using StreamType = WindowMessageUnitTestSuiteStream;
        using Suite = CoreTools::Suite;
        using OStreamShared = CoreTools::OStreamShared;
        using UnitTestSharedPtr = std::shared_ptr<CoreTools::UnitTestComposite>;

    public:
        WindowMessageUnitTestSuite(int64_t delta, const std::string& suiteName);
        WindowMessageUnitTestSuite(int64_t delta, const std::string& suiteName, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetPassedNumber() const noexcept;

        LResult CreateMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
        LResult KeyDownMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
        void Display(HWnd hwnd, int64_t timeDelta) override;

    protected:
        NODISCARD bool IsPrintRun() const noexcept;
        NODISCARD OStreamShared GetStreamShared() noexcept;
        void AddSuite(const Suite& suite);

        void AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestSharedPtr& unitTest);

        template <typename TestType, typename... Types>
        void AddTest(Suite& suite, const std::string& suiteName, const std::string& testName, Types&&... args);

        NODISCARD Suite GenerateSuite(const std::string& name);

    private:
        using StreamSharedPtr = std::shared_ptr<StreamType>;

    private:
        virtual void InitSuite() = 0;

        LResult AddSuiteOnCreateMessage(HWnd hwnd, WParam wParam, LParam lParam);

    private:
        StreamSharedPtr stream;
        PackageType impl;
    };

    using WindowProcessUnitTestSuite = WindowProcessHandle<WindowMessageUnitTestSuite>;
}

#endif  // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_H
