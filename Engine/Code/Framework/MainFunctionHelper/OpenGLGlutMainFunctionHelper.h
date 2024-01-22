/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:12)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_OPENGL_GLUT_MAIN_FUNCTION_HELPER_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_OPENGL_GLUT_MAIN_FUNCTION_HELPER_H

#include "Framework/FrameworkDll.h"

#include "MainFunctionHelperBase.h"
#include "Framework/Application/ApplicationFwd.h"

namespace Framework
{
    template <template <typename> class Build, typename Process>
    class OpenGLGlutMainFunctionHelper : public MainFunctionHelperBase
    {
    public:
        using ClassType = OpenGLGlutMainFunctionHelper<Build, Process>;
        using ParentType = MainFunctionHelperBase;

        using ClassShareType = CoreTools::NonCopyClasses;
        using BuildType = Build<Process>;

    public:
        OpenGLGlutMainFunctionHelper(int argc,
                                     char** argv,
                                     const GLUTApplicationInformation& information,
                                     const EnvironmentDirectory& environmentDirectory);
        ~OpenGLGlutMainFunctionHelper() noexcept;
        OpenGLGlutMainFunctionHelper(const OpenGLGlutMainFunctionHelper& rhs) noexcept = delete;
        OpenGLGlutMainFunctionHelper& operator=(const OpenGLGlutMainFunctionHelper& rhs) noexcept = delete;
        OpenGLGlutMainFunctionHelper(OpenGLGlutMainFunctionHelper&& rhs) noexcept;
        OpenGLGlutMainFunctionHelper& operator=(OpenGLGlutMainFunctionHelper&& rhs) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Init();
        void Destroy() override;

    private:
        using BuildSharedPtr = std::shared_ptr<BuildType>;

    private:
        NODISCARD int DoRun() override;
        NODISCARD virtual int RunOpenGLGlutMainLoop();

        void Initializer(int argc, char** argv, const GLUTApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);
        void Terminators();

        void InitOpenGLGlutProcess();
        void InitOpenGLImpl(int argc, char** argv, const GLUTApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        void DestroyOpenGLImpl() noexcept;
        void DestroyOpenGLGlutProcess();

    private:
        BuildSharedPtr build;
        OpenGLGlutMainFunctionSchedule openGLGlutMainFunctionSchedule;
    };
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_OPENGL_GLUT_MAIN_FUNCTION_HELPER_H