/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:15)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_OPENGL_GLUT_MAIN_FUNCTION_HELPER_DETAIL_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_OPENGL_GLUT_MAIN_FUNCTION_HELPER_DETAIL_H

#include "OpenGLGlutMainFunctionHelper.h"
#include "Flags/MainFunctionSchedule.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Framework/Application/GLUTApplicationInformation.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessManager.h"

template <template <typename> class Build, typename Process>
Framework::OpenGLGlutMainFunctionHelper<Build, Process>::OpenGLGlutMainFunctionHelper(int argc, char** argv, const GLUTApplicationInformation& information, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ environmentDirectory }, build{}, openGLGlutMainFunctionSchedule{ OpenGLGlutMainFunctionSchedule::Failure }
{
    Initializer(argc, argv, information, environmentDirectory);

    // 构造未完成
}

template <template <typename> class Build, typename Process>
void Framework::OpenGLGlutMainFunctionHelper<Build, Process>::Init()
{
    OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.SetMainFunctionHelper(shared_from_this());
    openGLGlutMainFunctionSchedule = OpenGLGlutMainFunctionSchedule::InitComplete;

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <template <typename> class Build, typename Process>
Framework::OpenGLGlutMainFunctionHelper<Build, Process>::OpenGLGlutMainFunctionHelper(OpenGLGlutMainFunctionHelper&& rhs) noexcept
    : ParentType{ std::move(rhs) }, build{ std::move(rhs.build) }, openGLGlutMainFunctionSchedule{ rhs.openGLGlutMainFunctionSchedule }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <template <typename> class Build, typename Process>
Framework::OpenGLGlutMainFunctionHelper<Build, Process>& Framework::OpenGLGlutMainFunctionHelper<Build, Process>::operator=(OpenGLGlutMainFunctionHelper&& rhs) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::operator=(std::move(rhs));

    build = std::move(rhs.build);
    openGLGlutMainFunctionSchedule = rhs.openGLGlutMainFunctionSchedule;

    return *this;
}

template <template <typename> class Build, typename Process>
Framework::OpenGLGlutMainFunctionHelper<Build, Process>::~OpenGLGlutMainFunctionHelper() noexcept
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;

    CoreTools::NoexceptNoReturn(*this, &ClassType::Destroy);
}

#ifdef OPEN_CLASS_INVARIANT

template <template <typename> class Build, typename Process>
bool Framework::OpenGLGlutMainFunctionHelper<Build, Process>::IsValid() const noexcept
{
    if (ParentType::IsValid() &&
        (openGLGlutMainFunctionSchedule != OpenGLGlutMainFunctionSchedule::Max) &&
        ((openGLGlutMainFunctionSchedule == OpenGLGlutMainFunctionSchedule::InitComplete) ^ (build == nullptr)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <template <typename> class Build, typename Process>
void Framework::OpenGLGlutMainFunctionHelper<Build, Process>::Destroy()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (OpenGLGlutMainFunctionSchedule::Failure < openGLGlutMainFunctionSchedule)
    {
        Terminators();
    }

    ParentType::Destroy();
}

template <template <typename> class Build, typename Process>
int Framework::OpenGLGlutMainFunctionHelper<Build, Process>::DoRun()
{
    return RunOpenGLGlutMainLoop();
}

template <template <typename> class Build, typename Process>
int Framework::OpenGLGlutMainFunctionHelper<Build, Process>::RunOpenGLGlutMainLoop()
{
    if (build != nullptr)
    {
        build->RunOpenGLGlutMainLoop();
    }

    return 0;
}

template <template <typename> class Build, typename Process>
void Framework::OpenGLGlutMainFunctionHelper<Build, Process>::Initializer(int argc, char** argv, const GLUTApplicationInformation& information, const EnvironmentDirectory& environmentDirectory)
{
    EXCEPTION_TRY
    {
        InitOpenGLGlutProcess();
        InitOpenGLImpl(argc, argv, information, environmentDirectory);
    }
    EXCEPTION_WINDOWS_ENTRY_POINT_CATCH
}

template <template <typename> class Build, typename Process>
void Framework::OpenGLGlutMainFunctionHelper<Build, Process>::InitOpenGLGlutProcess()
{
    OpenGLGlutProcessManager::Create();
    openGLGlutMainFunctionSchedule = OpenGLGlutMainFunctionSchedule::OpenGLGlutProcess;
}

template <template <typename> class Build, typename Process>
void Framework::OpenGLGlutMainFunctionHelper<Build, Process>::InitOpenGLImpl(int argc, char** argv, const GLUTApplicationInformation& information, const EnvironmentDirectory& environmentDirectory)
{
    build = std::make_shared<BuildType>(information, environmentDirectory);
    openGLGlutMainFunctionSchedule = OpenGLGlutMainFunctionSchedule::Max;
    if (!build->InitOpenGLGlutContext(argc, argv))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Info, Framework, SYSTEM_TEXT("InitOpenGLGlutContext失败。"));
    }
}

template <template <typename> class Build, typename Process>
void Framework::OpenGLGlutMainFunctionHelper<Build, Process>::Terminators()
{
    EXCEPTION_TRY
    {
        DestroyOpenGLImpl();
        DestroyOpenGLGlutProcess();
    }
    EXCEPTION_WINDOWS_ENTRY_POINT_CATCH
}

template <template <typename> class Build, typename Process>
void Framework::OpenGLGlutMainFunctionHelper<Build, Process>::DestroyOpenGLImpl() noexcept
{
    if (OpenGLGlutMainFunctionSchedule::Max <= openGLGlutMainFunctionSchedule)
    {
        build.reset();
        openGLGlutMainFunctionSchedule = OpenGLGlutMainFunctionSchedule::OpenGLGlutProcess;
    }
}

template <template <typename> class Build, typename Process>
void Framework::OpenGLGlutMainFunctionHelper<Build, Process>::DestroyOpenGLGlutProcess()
{
    if (OpenGLGlutMainFunctionSchedule::OpenGLGlutProcess <= openGLGlutMainFunctionSchedule)
    {
        OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.ClearMainFunctionHelper();
        OpenGLGlutProcessManager::Destroy();

        openGLGlutMainFunctionSchedule = OpenGLGlutMainFunctionSchedule::Failure;
    }
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_OPENGL_GLUT_MAIN_FUNCTION_HELPER_DETAIL_H
