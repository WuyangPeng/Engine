///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/09 20:49)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_UNIT_TEST_SUITE_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_UNIT_TEST_SUITE_H

#include "Framework/FrameworkDll.h"

#include "AndroidCallBackInterface.h"
#include "AndroidProcess.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(AndroidCallBackUnitTestSuiteImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE AndroidCallBackUnitTestSuite : public AndroidCallBackInterface
    {
    public:
        NON_COPY_TYPE_DECLARE(AndroidCallBackUnitTestSuite);
        using ParentType = AndroidCallBackInterface;

        using Suite = CoreTools::Suite;
        using OStreamShared = CoreTools::OStreamShared;
        using UnitTestComposite = CoreTools::UnitTestComposite;
        using UnitTestSharedPtr = std::shared_ptr<UnitTestComposite>;

    public:
        AndroidCallBackUnitTestSuite(int64_t delta, const std::string& suiteName);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Initialize() override;

        NODISCARD int KeyDownMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent) override;
        void Display(AndroidApp* androidApp, int64_t timeDelta) override;

        NODISCARD int GetPassedNumber() const noexcept;
        NODISCARD bool IsPrintRun() const noexcept;

        template <typename TestType, typename... Types>
        void AddTest(Suite& suite, const std::string& suiteName, const std::string& testName, Types&&... args);

        void AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestSharedPtr& unitTest);

        NODISCARD Suite GenerateSuite(const std::string& name);

    protected:
        NODISCARD OStreamShared GetStreamShared() const noexcept;

        void AddSuite(const Suite& suite);

    private:
        virtual void InitSuite() = 0;

        NODISCARD bool AddSuiteOnInitialize();
        void RunUnitTest();
        void ResetTestData();

    private:
        PackageType impl;
        bool isInit;
    };

    using AndroidProcessUnitTestSuite = AndroidProcess<AndroidCallBackUnitTestSuite>;
}

#endif  // FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_UNIT_TEST_SUITE_H
