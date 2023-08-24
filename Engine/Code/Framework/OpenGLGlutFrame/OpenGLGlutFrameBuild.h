///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/05 14:53)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_FRAME_BUILD_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_FRAME_BUILD_H

#include "Framework/FrameworkDll.h"

#include "Rendering/RendererEngine/RendererParameter.h"
#include "Framework/Application/GLUTApplicationInformation.h"
#include "Framework/MainFunctionHelper/MainFunctionHelperFwd.h"

namespace Framework
{
    template <typename OpenGLGlutProcess>
    class OpenGLGlutFrameBuild
    {
    public:
        using ClassType = OpenGLGlutFrameBuild<OpenGLGlutProcess>;

        using RendererParameter = Rendering::RendererParameter;

    public:
        OpenGLGlutFrameBuild(GLUTApplicationInformation glutInformation, const EnvironmentDirectory& environmentDirectory);
        virtual ~OpenGLGlutFrameBuild() noexcept = default;
        OpenGLGlutFrameBuild(const OpenGLGlutFrameBuild& rhs) noexcept = default;
        OpenGLGlutFrameBuild& operator=(const OpenGLGlutFrameBuild& rhs) noexcept = default;
        OpenGLGlutFrameBuild(OpenGLGlutFrameBuild&& rhs) noexcept = default;
        OpenGLGlutFrameBuild& operator=(OpenGLGlutFrameBuild&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual bool InitOpenGLGlutContext(int argc, char** argv);
        virtual void RunOpenGLGlutMainLoop();

    private:
        NODISCARD virtual bool PreCreate();
        NODISCARD virtual bool InitGlutFunctionLibrary(int argc, char** argv) noexcept;
        NODISCARD virtual bool CreateGlutWindow();
        NODISCARD virtual bool SetCallBackFunction() noexcept;
        NODISCARD virtual bool SetupRenderStatus() noexcept;
        NODISCARD virtual bool OpenGLInit();
        NODISCARD virtual bool CreateMenu() noexcept;

        NODISCARD static std::string GetRendererParameter(const EnvironmentDirectory& environmentDirectory);

    private:
        static constexpr auto interval = 60;

        OpenGLGlutProcess openGLGlutProcess;
        GLUTApplicationInformation glutInformation;
        int windowId;
        int menuId;
        RendererParameter rendererParameter;
    };
}

#endif  // FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_FRAME_BUILD_H
