// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:40)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_UNIT_TEST_SUITE_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_UNIT_TEST_SUITE_H

#include "Framework/FrameworkDll.h"

#include "AndroidCallBackInterface.h"
#include "AndroidProcess.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

 
EXPORT_SHARED_PTR(Framework, AndroidCallBackUnitTestSuiteImpl, FRAMEWORK_DEFAULT_DECLARE);
EXPORT_SHARED_PTR(Framework, WindowMessageUnitTestSuiteStream, FRAMEWORK_DEFAULT_DECLARE);
namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE AndroidCallBackUnitTestSuite : public AndroidCallBackInterface
    {
    public:
        using ClassType = AndroidCallBackUnitTestSuite;
        using ParentType = AndroidCallBackInterface;
        using ClassShareType = CoreTools::NonCopyClasses;
        using ImplType = AndroidCallBackUnitTestSuiteImpl;
        using StreamType = WindowMessageUnitTestSuiteStream;
        using Suite = CoreTools::Suite;
        using OStreamShared = CoreTools::OStreamShared;
        using UnitTestSharedPtr = std::shared_ptr<CoreTools::UnitTestComposite>;

    public:
        AndroidCallBackUnitTestSuite(int64_t delta, const std::string& suiteName);
        ~AndroidCallBackUnitTestSuite() noexcept = default;
        AndroidCallBackUnitTestSuite(const AndroidCallBackUnitTestSuite&) noexcept = delete;
        AndroidCallBackUnitTestSuite& operator=(const AndroidCallBackUnitTestSuite&) noexcept = delete;
        AndroidCallBackUnitTestSuite(AndroidCallBackUnitTestSuite&& rhs) noexcept;
        AndroidCallBackUnitTestSuite& operator=(AndroidCallBackUnitTestSuite&& rhs) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        bool Initialize() override;

        int KeyDownMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent) override;
        void Display(AndroidApp* androidApp, int64_t timeDelta) override;

        int GetPassedNumber() const noexcept;
        bool IsPrintRun() const noexcept;

        template <typename TestType, typename... Types>
        void AddTest(Suite& suite, const std::string& suiteName, const std::string& testName, Types&&... args)
        {
            auto unitTest = std::make_shared<TestType>(GetStreamShared(), std::forward<Types>(args)...);

            AddTest(suiteName, suite, testName, unitTest);
        }

        void AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestSharedPtr& unitTest);

        [[nodiscard]] Suite GenerateSuite(const std::string& name);

    protected:
        OStreamShared GetStreamShared() const noexcept;

        void AddSuite(const Suite& suite);

    private:
        using AndroidCallBackUnitTestSuiteImplPtr = std::shared_ptr<ImplType>;
        using StreamTypeSharedPtr = std::shared_ptr<StreamType>;

    private:
        virtual void InitSuite() = 0;

        bool AddSuiteOnInitialize();
        void RunUnitTest();
        void ResetTestData();

    private:
        StreamTypeSharedPtr m_StreamType;
        AndroidCallBackUnitTestSuiteImplPtr impl;
        bool m_IsInit;
    };

    using AndroidProcessUnitTestSuite = AndroidProcess<AndroidCallBackUnitTestSuite>;
}

#endif  // FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_UNIT_TEST_SUITE_H
