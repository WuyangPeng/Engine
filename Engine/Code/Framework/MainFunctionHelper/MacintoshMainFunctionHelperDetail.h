/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:16)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_MACINTOSH_MAIN_FUNCTION_HELPER_DETAIL_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_MACINTOSH_MAIN_FUNCTION_HELPER_DETAIL_H

#include "MacintoshMainFunctionHelper.h"
#include "Flags/MainFunctionSchedule.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <iostream>

template <template <typename> class Build, typename Process>
Framework::MacintoshMainFunctionHelper<Build, Process>::MacintoshMainFunctionHelper(const EnvironmentDirectory& environmentDirectory)
    : ParentType{ environmentDirectory }, build{}, macintoshMainFunctionSchedule{ MacintoshMainFunctionSchedule::Failure }
{
    Initializer();

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <template <typename> class Build, typename Process>
Framework::MacintoshMainFunctionHelper<Build, Process>::MacintoshMainFunctionHelper(MacintoshMainFunctionHelper&& rhs) noexcept
    : ParentType{ std::move(rhs) }, build{ std::move(rhs.build) }, macintoshMainFunctionSchedule{ rhs.macintoshMainFunctionSchedule }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <template <typename> class Build, typename Process>
Framework::MacintoshMainFunctionHelper<Build, Process>& Framework::MacintoshMainFunctionHelper<Build, Process>::operator=(MacintoshMainFunctionHelper&& rhs) noexcept
{
    ParentType::operator=(std::move(rhs));

    build = std::move(rhs.build);
    macintoshMainFunctionSchedule = rhs.macintoshMainFunctionSchedule;

    return *this;
}

template <template <typename> class Build, typename Process>
Framework::MacintoshMainFunctionHelper<Build, Process>::~MacintoshMainFunctionHelper() noexcept
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;

    CoreTools::NoexceptNoReturn(*this, &ClassType::Destroy);
}

#ifdef OPEN_CLASS_INVARIANT

template <template <typename> class Build, typename Process>
bool Framework::MacintoshMainFunctionHelper<Build, Process>::IsValid() const noexcept
{
    if (ParentType::IsValid() && ((MacintoshMainFunctionSchedule::Max <= macintoshMainFunctionSchedule) ^ (build == nullptr)))
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <template <typename> class Build, typename Process>
void Framework::MacintoshMainFunctionHelper<Build, Process>::Destroy()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (MacintoshMainFunctionSchedule::Failure < macintoshMainFunctionSchedule)
    {
        Terminators();
    }

    ParentType::Destroy();
}

template <template <typename> class Build, typename CallBack>
int Framework::MacintoshMainFunctionHelper<Build, CallBack>::DoRun() noexcept
{
    return RunMacintoshMainLoop();
}

template <template <typename> class Build, typename Process>
int Framework::MacintoshMainFunctionHelper<Build, Process>::RunMacintoshMainLoop() noexcept
{
    if (build != nullptr)
    {
        build->EnterMessageLoop();
    }

    return 0;
}

template <template <typename> class Build, typename Process>
void Framework::MacintoshMainFunctionHelper<Build, Process>::Initializer()
{
    EXCEPTION_TRY
    {
        InitMacintoshProcess();
        InitMacintoshImpl();
    }
    EXCEPTION_ENTRY_POINT_CATCH
}

template <template <typename> class Build, typename Process>
void Framework::MacintoshMainFunctionHelper<Build, Process>::InitMacintoshProcess() noexcept
{
    macintoshMainFunctionSchedule = MacintoshMainFunctionSchedule::MacintoshProcess;
}

template <template <typename> class Build, typename Process>
void Framework::MacintoshMainFunctionHelper<Build, Process>::InitMacintoshImpl()
{
    build = std::make_shared<BuildType>();
    macintoshMainFunctionSchedule = MacintoshMainFunctionSchedule::Max;
}

template <template <typename> class Build, typename Process>
void Framework::MacintoshMainFunctionHelper<Build, Process>::Terminators()
{
    EXCEPTION_TRY
    {
        DestroyMacintoshImpl();
        DestroyMacintoshProcess();
    }
    EXCEPTION_ENTRY_POINT_CATCH
}

template <template <typename> class Build, typename Process>
void Framework::MacintoshMainFunctionHelper<Build, Process>::DestroyMacintoshImpl() noexcept
{
    if (MacintoshMainFunctionSchedule::Max <= macintoshMainFunctionSchedule)
    {
        build.reset();
        macintoshMainFunctionSchedule = MacintoshMainFunctionSchedule::MacintoshProcess;
    }
}

template <template <typename> class Build, typename Process>
void Framework::MacintoshMainFunctionHelper<Build, Process>::DestroyMacintoshProcess() noexcept
{
    if (MacintoshMainFunctionSchedule::MacintoshProcess <= macintoshMainFunctionSchedule)
    {
        macintoshMainFunctionSchedule = MacintoshMainFunctionSchedule::Failure;
    }
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_MACINTOSH_MAIN_FUNCTION_HELPER_DETAIL_H
