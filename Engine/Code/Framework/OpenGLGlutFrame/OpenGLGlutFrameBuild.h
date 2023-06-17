///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:17)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_FRAME_BUILD_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_FRAME_BUILD_H

#include "Rendering/Renderers/RendererParameter.h"
#include "Framework/Application/GLUTApplicationInformation.h"
#include "Framework/MainFunctionHelper/MainFunctionHelperFwd.h"

namespace Framework
{
    template <typename OpenGLGlutProcess>
    class OpenGLGlutFrameBuild
    {
    public:
        using ProcessType = OpenGLGlutProcess;
        using ClassType = OpenGLGlutFrameBuild<ProcessType>;
        using RendererParameter = Rendering::RendererParameter;

    public:
        OpenGLGlutFrameBuild(const GLUTApplicationInformation& glutInformation, const EnvironmentDirectory& environmentDirectory);
        virtual ~OpenGLGlutFrameBuild() noexcept = default;
        OpenGLGlutFrameBuild(const OpenGLGlutFrameBuild& rhs) noexcept = default;
        OpenGLGlutFrameBuild& operator=(const OpenGLGlutFrameBuild& rhs) noexcept = default;
        OpenGLGlutFrameBuild(OpenGLGlutFrameBuild&& rhs) noexcept = default;
        OpenGLGlutFrameBuild& operator=(OpenGLGlutFrameBuild&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual bool InitOpenGLGlutContext(int argc, char** argv);
        virtual void RunOpenGLGlutMainLoop();

    private:
        virtual bool PreCreate();
        virtual bool InitGlutFunctionLibrary(int argc, char** argv) noexcept;
        virtual bool CreateGlutWindow();
        virtual bool SetCallBackFunction() noexcept;
        virtual bool SetupRenderStatus() noexcept;
        virtual bool OpenGLInit();
        virtual bool CreateMenu() noexcept;

        NODISCARD static std::string GetRendererParameter(const EnvironmentDirectory& environmentDirectory);

    private:
        static constexpr auto interval = 60;

        OpenGLGlutProcess openGLGlutProcess;
        GLUTApplicationInformation glutInformation;
        int windowID;
        int menuID;
        RendererParameter rendererParameter;
    };
}

#endif  // FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_FRAME_BUILD_H
