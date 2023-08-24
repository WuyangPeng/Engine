///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/05 14:48)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_WINDOW_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_WINDOW_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_H

#include "Framework/FrameworkDll.h"

#include "OpenGLGlutCallBackInterface.h"
#include "OpenGLGlutProcess.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

#include <string>

FRAMEWORK_NON_COPY_EXPORT_IMPL(OpenGLGlutCallBackUnitTestSuiteImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE OpenGLGlutCallBackUnitTestSuite : public OpenGLGlutCallBackInterface
    {
    public:
        NON_COPY_TYPE_DECLARE(OpenGLGlutCallBackUnitTestSuite);
        using ParentType = OpenGLGlutCallBackInterface;

        using Suite = CoreTools::Suite;
        using OStreamShared = CoreTools::OStreamShared;
        using UnitTestComposite = CoreTools::UnitTestComposite;
        using UnitTestSharedPtr = std::shared_ptr<UnitTestComposite>;

    public:
        OpenGLGlutCallBackUnitTestSuite(int64_t delta, const std::string& suiteName);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Initialize() override;
        NODISCARD bool SpecialKeysDown(int key, int xCoordinate, int yCoordinate) override;
        NODISCARD bool IdleFunction() override;
        NODISCARD int GetPassedNumber() const noexcept;

    protected:
        NODISCARD bool IsPrintRun() const noexcept;
        NODISCARD OStreamShared GetStreamShared() noexcept;

        void DoAddSuite(const Suite& suite);
        void AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestSharedPtr& unitTest);
        NODISCARD Suite GenerateSuite(const std::string& name);

        template <typename TestType, typename... Types>
        void AddTest(Suite& suite, const std::string& suiteName, const std::string& testName, Types&&... args);

    private:
        virtual void AddSuite() = 0;

        NODISCARD bool AddSuiteOnInitialize();

    private:
        PackageType impl;
        bool isInit;
    };

    using OpenGLGlutProcessUnitTestSuite = OpenGLGlutProcess<OpenGLGlutCallBackUnitTestSuite>;
}

#endif  // FRAMEWORK_OPENGL_GLUT_FRAME_WINDOW_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_H
