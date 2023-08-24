///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/08 19:30)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_WINDOW_MAIN_FUNCTION_HELPER_DETAIL_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_WINDOW_MAIN_FUNCTION_HELPER_DETAIL_H

#include "WindowMainFunctionHelper.h"

#include "Flags/MainFunctionSchedule.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Framework/WindowProcess/WindowProcessManager.h"

template <template <typename> class Build, typename Process>
Framework::WindowMainFunctionHelper<Build, Process>::WindowMainFunctionHelper(WindowsHInstance instance,
                                                                              const char* commandLine,
                                                                              const WindowApplicationInformation& information,
                                                                              const EnvironmentDirectory& environmentDirectory)
    : ParentType{ environmentDirectory }, build{}, windowMainFunctionSchedule{ WindowMainFunctionSchedule::Failure }
{
    Initializer(instance, commandLine, information);

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <template <typename> class Build, typename Process>
Framework::WindowMainFunctionHelper<Build, Process>::WindowMainFunctionHelper(WindowMainFunctionHelper&& rhs) noexcept
    : ParentType{ std::move(rhs) }, build{ std::move(rhs.build) }, windowMainFunctionSchedule{ rhs.windowMainFunctionSchedule }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <template <typename> class Build, typename Process>
Framework::WindowMainFunctionHelper<Build, Process>& Framework::WindowMainFunctionHelper<Build, Process>::operator=(WindowMainFunctionHelper&& rhs) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::operator=(std::move(rhs));

    build = std::move(rhs.build);
    windowMainFunctionSchedule = rhs.windowMainFunctionSchedule;

    return *this;
}

template <template <typename> class Build, typename Process>
Framework::WindowMainFunctionHelper<Build, Process>::~WindowMainFunctionHelper() noexcept
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;

    CoreTools::NoexceptNoReturn(*this, &ClassType::Destroy);
}

#ifdef OPEN_CLASS_INVARIANT

template <template <typename> class Build, typename Process>
bool Framework::WindowMainFunctionHelper<Build, Process>::IsValid() const noexcept
{
    if (ParentType::IsValid() && ((WindowMainFunctionSchedule::Max <= windowMainFunctionSchedule) ^ (build == nullptr)))
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <template <typename> class Build, typename Process>
int Framework::WindowMainFunctionHelper<Build, Process>::DoRun()
{
    return EnterMessageLoop();
}

template <template <typename> class Build, typename Process>
int Framework::WindowMainFunctionHelper<Build, Process>::EnterMessageLoop()
{
    if (build != nullptr)
        return boost::numeric_cast<int>(build->EnterMessageLoop());
    else
        return -1;
}

template <template <typename> class Build, typename Process>
System::WindowsHWnd Framework::WindowMainFunctionHelper<Build, Process>::GetHWnd() const noexcept
{
    if (build != nullptr)
        return build->GetHWnd();
    else
        return nullptr;
}

template <template <typename> class Build, typename Process>
void Framework::WindowMainFunctionHelper<Build, Process>::Destroy()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (WindowMainFunctionSchedule::Failure < windowMainFunctionSchedule)
    {
        Terminators();
    }

    ParentType::Destroy();
}

template <template <typename> class Build, typename Process>
void Framework::WindowMainFunctionHelper<Build, Process>::Initializer(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information)
{
    EXCEPTION_TRY
    {
        InitWindowProcess();
        InitCamera();
        InitWindowImpl(instance, commandLine, information);
    }
    EXCEPTION_WINDOWS_ENTRY_POINT_CATCH
}

template <template <typename> class Build, typename Process>
void Framework::WindowMainFunctionHelper<Build, Process>::InitWindowProcess()
{
    WindowProcessManager::Create();
    windowMainFunctionSchedule = WindowMainFunctionSchedule::WindowProcess;
}

template <template <typename> class Build, typename Process>
void Framework::WindowMainFunctionHelper<Build, Process>::InitCamera()
{
    Rendering::CameraManager::Create();
    windowMainFunctionSchedule = WindowMainFunctionSchedule::Camera;
}

template <template <typename> class Build, typename Process>
void Framework::WindowMainFunctionHelper<Build, Process>::InitWindowImpl(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information)
{
    build = std::make_shared<BuildType>(instance, commandLine, information, GetEnvironmentDirectory());
    windowMainFunctionSchedule = WindowMainFunctionSchedule::Max;
}

template <template <typename> class Build, typename Process>
void Framework::WindowMainFunctionHelper<Build, Process>::Terminators()
{
    EXCEPTION_TRY
    {
        DestroyWindowImpl();
        DestroyCamera();
        DestroyWindowProcess();
    }
    EXCEPTION_WINDOWS_ENTRY_POINT_CATCH
}

template <template <typename> class Build, typename Process>
void Framework::WindowMainFunctionHelper<Build, Process>::DestroyWindowImpl() noexcept
{
    if (WindowMainFunctionSchedule::Max <= windowMainFunctionSchedule)
    {
        build.reset();
        windowMainFunctionSchedule = WindowMainFunctionSchedule::Camera;
    }
}

template <template <typename> class Build, typename Process>
void Framework::WindowMainFunctionHelper<Build, Process>::DestroyCamera() noexcept
{
    if (WindowMainFunctionSchedule::Camera <= windowMainFunctionSchedule)
    {
        Rendering::CameraManager::Destroy();
        windowMainFunctionSchedule = WindowMainFunctionSchedule::WindowProcess;
    }
}

template <template <typename> class Build, typename Process>
void Framework::WindowMainFunctionHelper<Build, Process>::DestroyWindowProcess() noexcept
{
    if (WindowMainFunctionSchedule::WindowProcess <= windowMainFunctionSchedule)
    {
        WindowProcessManager::Destroy();
        windowMainFunctionSchedule = WindowMainFunctionSchedule::Failure;
    }
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_WINDOW_MAIN_FUNCTION_HELPER_DETAIL_H
