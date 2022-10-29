///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 13:59)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_FRAME_BUILD_DETAIL_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_FRAME_BUILD_DETAIL_H

#include "OpenGLGlutFrameBuild.h"
#include "System/Console/ConsoleCreate.h"
#include "System/OpenGL/Flags/GlutFlags.h"
#include "System/OpenGL/OpenGLAPI.h"
#include "System/OpenGL/OpenGLGlut.h"
#include "System/OpenGL/OpenGLInit.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

template <typename OpenGLGlutProcess>
Framework::OpenGLGlutFrameBuild<OpenGLGlutProcess>::OpenGLGlutFrameBuild(const GLUTApplicationInformation& glutInformation, const EnvironmentDirectory& environmentDirectory)
    : openGLGlutProcess{ System::gMicroseconds / interval },
      glutInformation{ glutInformation },
      windowID{ 0 },
      menuID{ 0 },
      rendererParameter{ GetRendererParameter(environmentDirectory) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <typename OpenGLGlutProcess>
std::string Framework::OpenGLGlutFrameBuild<OpenGLGlutProcess>::GetRendererParameter(const EnvironmentDirectory& environmentDirectory)
{
    return CoreTools::StringConversion::StandardConversionMultiByte(environmentDirectory.GetDirectory(UpperDirectory::Configuration) + SYSTEM_TEXT("Renderer.json"));
}

#ifdef OPEN_CLASS_INVARIANT

template <typename OpenGLGlutProcess>
bool Framework::OpenGLGlutFrameBuild<OpenGLGlutProcess>::IsValid() const noexcept
{
    if (0 <= windowID && 0 <= menuID)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename OpenGLGlutProcess>
bool Framework::OpenGLGlutFrameBuild<OpenGLGlutProcess>::InitOpenGLGlutContext(int argc, char** argv)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (PreCreate() &&
        InitGlutFunctionLibrary(argc, argv) &&
        CreateGlutWindow() &&
        SetCallBackFunction() &&
        OpenGLInit() &&
        SetupRenderStatus() &&
        CreateMenu())
        return true;

    return false;
}

// private
template <typename OpenGLGlutProcess>
bool Framework::OpenGLGlutFrameBuild<OpenGLGlutProcess>::PreCreate()
{
    CLASS_IS_VALID;

    return openGLGlutProcess.PreCreate();
}

// private
template <typename OpenGLGlutProcess>
bool Framework::OpenGLGlutFrameBuild<OpenGLGlutProcess>::InitGlutFunctionLibrary(int argc, char** argv) noexcept
{
    System::GlutInit(&argc, argv);

    System::GlutInitDisplayMode(0 < rendererParameter.GetNumMultisamples());

    System::GlutInitWindowPosition(rendererParameter.GetXPosition(), rendererParameter.GetYPosition());
    System::GlutInitWindowSize(rendererParameter.GetWidth(), rendererParameter.GetHeight());
    System::GlutInitContextVersion(glutInformation.GetOpenGLMajorVersion(), glutInformation.GetOpenGLMinorVersion());

    System::GlutSetOption(System::GlutOption::WindowClose, System::EnumCastUnderlying(System::GlutExtension::GlutMainLoopReturns));

    MAYBE_UNUSED const auto result = System::RemoveConsoleCloseButton();

    return true;
}

// private
template <typename OpenGLGlutProcess>
bool Framework::OpenGLGlutFrameBuild<OpenGLGlutProcess>::CreateGlutWindow()
{
    windowID = System::GlutCreateWindow(rendererParameter.GetWindowTitle());

    if (windowID == 0)
    {
        return false;
    }
    else
    {
        openGLGlutProcess.SetWindowID(windowID);
        openGLGlutProcess.SetMillisecond(System::EnumCastUnderlying(glutInformation.GetFrame()));

        return true;
    }
}

// private
template <typename OpenGLGlutProcess>
bool Framework::OpenGLGlutFrameBuild<OpenGLGlutProcess>::SetCallBackFunction() noexcept
{
    System::GlutReshapeFunc(openGLGlutProcess.GetChangeSizeCallback());
    System::GlutDisplayFunc(openGLGlutProcess.GetRenderSceneCallback());
    System::GlutIdleFunc(openGLGlutProcess.GetIdleFunctionCallback());
    System::GlutKeyboardFunc(openGLGlutProcess.GetKeyboardDownCallback());
    System::GlutSpecialFunc(openGLGlutProcess.GetSpecialKeysDownCallback());
    System::GlutKeyboardUpFunc(openGLGlutProcess.GetKeyboardUpCallback());
    System::GlutSpecialUpFunc(openGLGlutProcess.GetSpecialKeysUpCallback());
    System::GlutMouseFunc(openGLGlutProcess.GetMouseFunctionCallback());
    System::GlutMotionFunc(openGLGlutProcess.GetMotionFunctionCallback());
    System::GlutPassiveMotionFunc(openGLGlutProcess.GetPassiveMotionCallback());
    System::GlutTimerFunc(System::EnumCastUnderlying(glutInformation.GetFrame()), openGLGlutProcess.GetTimerFunctionCallback(), 1);

    // 注册终止函数，这样我们就可以在GLUT调用exit前销毁窗口。
    if (atexit(openGLGlutProcess.GetTerminateCallback()) != 0)
    {
        return false;
    }

    return true;
}

// private
template <typename OpenGLGlutProcess>
bool Framework::OpenGLGlutFrameBuild<OpenGLGlutProcess>::SetupRenderStatus() noexcept
{
    System::SetupRenderStatus();

    return true;
}

// private
template <typename OpenGLGlutProcess>
bool Framework::OpenGLGlutFrameBuild<OpenGLGlutProcess>::OpenGLInit()
{
    return System::OpenGLInit();
}

// private
template <typename OpenGLGlutProcess>
bool Framework::OpenGLGlutFrameBuild<OpenGLGlutProcess>::CreateMenu() noexcept
{
    menuID = System::GlutCreateMenu(openGLGlutProcess.GetProcessMenuCallback());

    if (menuID == 0)
        return false;

    return true;
}

template <typename OpenGLGlutProcess>
void Framework::OpenGLGlutFrameBuild<OpenGLGlutProcess>::RunOpenGLGlutMainLoop()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (openGLGlutProcess.Initialize())
    {
        openGLGlutProcess.PreIdle();

        System::GlutMainLoop();
    }
}

#endif  // FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_FRAME_BUILD_DETAIL_H
