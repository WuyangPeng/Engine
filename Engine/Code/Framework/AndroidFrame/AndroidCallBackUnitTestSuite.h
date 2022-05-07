///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/05 18:28)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_UNIT_TEST_SUITE_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_UNIT_TEST_SUITE_H

#include "Framework/FrameworkDll.h"

#include "AndroidCallBackInterface.h"
#include "AndroidProcess.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(AndroidCallBackUnitTestSuiteImpl);
EXPORT_SHARED_PTR(Framework, WindowMessageUnitTestSuiteStream, FRAMEWORK_DEFAULT_DECLARE);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE AndroidCallBackUnitTestSuite : public AndroidCallBackInterface
    {
    public:
        NON_COPY_TYPE_DECLARE(AndroidCallBackUnitTestSuite);
        using ParentType = AndroidCallBackInterface;
        using StreamType = WindowMessageUnitTestSuiteStream;
        using Suite = CoreTools::Suite;
        using OStreamShared = CoreTools::OStreamShared;
        using UnitTestSharedPtr = std::shared_ptr<CoreTools::UnitTestComposite>;

    public:
        AndroidCallBackUnitTestSuite(int64_t delta, const std::string& suiteName);
        ~AndroidCallBackUnitTestSuite() noexcept = default;
        AndroidCallBackUnitTestSuite(const AndroidCallBackUnitTestSuite& rhs) noexcept = delete;
        AndroidCallBackUnitTestSuite& operator=(const AndroidCallBackUnitTestSuite& rhs) noexcept = delete;
        AndroidCallBackUnitTestSuite(AndroidCallBackUnitTestSuite&& rhs) noexcept;
        AndroidCallBackUnitTestSuite& operator=(AndroidCallBackUnitTestSuite&& rhs) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Initialize() override;

        NODISCARD int KeyDownMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent) override;
        void Display(AndroidApp* androidApp, int64_t timeDelta) override;

        NODISCARD int GetPassedNumber() const noexcept;
        NODISCARD bool IsPrintRun() const noexcept;

        template <typename TestType, typename... Types>
        void AddTest(Suite& suite, const std::string& suiteName, const std::string& testName, Types&&... args)
        {
            auto unitTest = std::make_shared<TestType>(GetStreamShared(), std::forward<Types>(args)...);

            AddTest(suiteName, suite, testName, unitTest);
        }

        void AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestSharedPtr& unitTest);

        NODISCARD Suite GenerateSuite(const std::string& name);

    protected:
        NODISCARD OStreamShared GetStreamShared() const noexcept;

        void AddSuite(const Suite& suite);

    private:
        using StreamTypeSharedPtr = std::shared_ptr<StreamType>;

    private:
        virtual void InitSuite() = 0;

        NODISCARD bool AddSuiteOnInitialize();
        void RunUnitTest();
        void ResetTestData();

    private:
        StreamTypeSharedPtr streamType;
        PackageType impl;
        bool isInit;
    };

    using AndroidProcessUnitTestSuite = AndroidProcess<AndroidCallBackUnitTestSuite>;
}

#endif  // FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_UNIT_TEST_SUITE_H
