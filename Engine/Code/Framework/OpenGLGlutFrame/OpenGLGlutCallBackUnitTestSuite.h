///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 14:22)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_WINDOW_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_WINDOW_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_H

#include "Framework/FrameworkDll.h"

#include "OpenGLGlutCallBackInterface.h"
#include "OpenGLGlutProcess.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

#include <string>

EXPORT_SHARED_PTR(Framework, WindowMessageUnitTestSuiteStream, FRAMEWORK_DEFAULT_DECLARE);
EXPORT_SHARED_PTR(Framework, OpenGLGlutCallBackUnitTestSuiteImpl, FRAMEWORK_DEFAULT_DECLARE);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE OpenGLGlutCallBackUnitTestSuite : public OpenGLGlutCallBackInterface
    {
    public:
        using ClassType = OpenGLGlutCallBackUnitTestSuite;
        using ParentType = OpenGLGlutCallBackInterface;
        using ClassShareType = CoreTools::NonCopyClasses;
        using ImplType = OpenGLGlutCallBackUnitTestSuiteImpl;
        using StreamType = WindowMessageUnitTestSuiteStream;
        using Suite = CoreTools::Suite;
        using OStreamShared = CoreTools::OStreamShared;
        using UnitTestSharedPtr = std::shared_ptr<CoreTools::UnitTestComposite>;

    public:
        OpenGLGlutCallBackUnitTestSuite(int64_t delta, const std::string& suiteName);
        ~OpenGLGlutCallBackUnitTestSuite() noexcept = default;
        OpenGLGlutCallBackUnitTestSuite(const OpenGLGlutCallBackUnitTestSuite& rhs) noexcept = delete;
        OpenGLGlutCallBackUnitTestSuite& operator=(const OpenGLGlutCallBackUnitTestSuite& rhs) noexcept = delete;
        OpenGLGlutCallBackUnitTestSuite(OpenGLGlutCallBackUnitTestSuite&& rhs) noexcept;
        OpenGLGlutCallBackUnitTestSuite& operator=(OpenGLGlutCallBackUnitTestSuite&& rhs) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Initialize() override;
        NODISCARD bool SpecialKeysDown(int key, int xCoordinate, int yCoordinate) override;
        NODISCARD bool IdleFunction() override;
        NODISCARD int GetPassedNumber() const noexcept;

    protected:
        NODISCARD OStreamShared GetStreamShared() noexcept;
        void DoAddSuite(const Suite& suite);
        NODISCARD bool IsPrintRun() const noexcept;
        void AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestSharedPtr& unitTest);

        template <typename TestType, typename... Types>
        void AddTest(Suite& suite, const std::string& suiteName, const std::string& testName, Types&&... args)
        {
            auto unitTest = std::make_shared<TestType>(GetStreamShared(), std::forward<Types>(args)...);

            AddTest(suiteName, suite, testName, unitTest);
        }

        NODISCARD Suite GenerateSuite(const std::string& name);

    private:
        using OpenGLGlutCallBackUnitTestSuiteImplPtr = std::shared_ptr<ImplType>;
        using StreamTypeSharedPtr = std::shared_ptr<StreamType>;

    private:
        virtual void AddSuite() = 0;

        NODISCARD bool AddSuiteOnInitialize();

    private:
        StreamTypeSharedPtr stream;
        OpenGLGlutCallBackUnitTestSuiteImplPtr impl;
        bool isInit;
    };

    using OpenGLGlutProcessUnitTestSuite = OpenGLGlutProcess<OpenGLGlutCallBackUnitTestSuite>;
}

#endif  // FRAMEWORK_OPENGL_GLUT_FRAME_WINDOW_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_H
