///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:38)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_MACINTOSH_MAIN_FUNCTION_HELPER_DETAIL_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_MACINTOSH_MAIN_FUNCTION_HELPER_DETAIL_H

#include "MacintoshMainFunctionHelper.h"
#include "Flags/MainFunctionSchedule.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <iostream>

template <template <typename> class Build, typename Process>
Framework::MacintoshMainFunctionHelper<Build, Process>::MacintoshMainFunctionHelper(const EnvironmentDirectory& environmentDirectory)
    : ParentType{ environmentDirectory }, build{}, macintoshMainFunctionSchedule{ MacintoshMainFunctionSchedule::Failure }
{
    Initializers();

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

// private
template <template <typename> class Build, typename CallBack>
int Framework::MacintoshMainFunctionHelper<Build, CallBack>::DoRun() noexcept
{
    return RunMacintoshMainLoop();
}

// private
template <template <typename> class Build, typename Process>
int Framework::MacintoshMainFunctionHelper<Build, Process>::RunMacintoshMainLoop() noexcept
{
    if (build != nullptr)
    {
        build->EnterMessageLoop();
    }

    return 0;
}

// private
template <template <typename> class Build, typename Process>
void Framework::MacintoshMainFunctionHelper<Build, Process>::Initializers()
{
    EXCEPTION_TRY
    {
        InitMacintoshProcess();
        InitImpl();
    }
    EXCEPTION_ENTRY_POINT_CATCH
}

// private
template <template <typename> class Build, typename Process>
void Framework::MacintoshMainFunctionHelper<Build, Process>::InitMacintoshProcess() noexcept
{
    macintoshMainFunctionSchedule = MacintoshMainFunctionSchedule::MacintoshProcess;
}

// private
template <template <typename> class Build, typename Process>
void Framework::MacintoshMainFunctionHelper<Build, Process>::InitImpl()
{
    build = std::make_shared<BuildType>();
    macintoshMainFunctionSchedule = MacintoshMainFunctionSchedule::Max;
}

// private
template <template <typename> class Build, typename Process>
void Framework::MacintoshMainFunctionHelper<Build, Process>::Terminators()
{
    EXCEPTION_TRY
    {
        DestroyImpl();
        DestroyMacintoshProcess();
    }
    EXCEPTION_ENTRY_POINT_CATCH
}

// private
template <template <typename> class Build, typename Process>
void Framework::MacintoshMainFunctionHelper<Build, Process>::DestroyImpl() noexcept
{
    if (MacintoshMainFunctionSchedule::Max <= macintoshMainFunctionSchedule)
    {
        build.reset();
        macintoshMainFunctionSchedule = MacintoshMainFunctionSchedule::MacintoshProcess;
    }
}

// private
template <template <typename> class Build, typename Process>
void Framework::MacintoshMainFunctionHelper<Build, Process>::DestroyMacintoshProcess() noexcept
{
    if (MacintoshMainFunctionSchedule::MacintoshProcess <= macintoshMainFunctionSchedule)
    {
        macintoshMainFunctionSchedule = MacintoshMainFunctionSchedule::Failure;
    }
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_MACINTOSH_MAIN_FUNCTION_HELPER_DETAIL_H
