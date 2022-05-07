///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/06 14:55)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_OPENGL_GLUT_MAIN_FUNCTION_HELPER_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_OPENGL_GLUT_MAIN_FUNCTION_HELPER_H

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

        void Initializers(int argc, char** argv, const GLUTApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);
        void Terminators();

        void InitOpenGLGlutProcess();
        void InitCamera();
        void InitImpl(int argc, char** argv, const GLUTApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        void DestroyImpl() noexcept;
        void DestroyCamera() noexcept;
        void DestroyOpenGLGlutProcess();

    private:
        BuildSharedPtr build;
        OpenGLGlutMainFunctionSchedule openGLGlutMainFunctionSchedule;
    };
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_OPENGL_GLUT_MAIN_FUNCTION_HELPER_H