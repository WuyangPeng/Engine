///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/08 19:34)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_DETAIL_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_DETAIL_H

#include "ConsoleMainFunctionHelper.h"
#include "Flags/MainFunctionSchedule.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <iostream>

template <template <typename> class Build, typename Process>
Framework::ConsoleMainFunctionHelper<Build, Process>::ConsoleMainFunctionHelper(int argc, char** argv, const String& consoleTitle, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ argc, argv, consoleTitle, environmentDirectory }, build{}, consoleMainFunctionSchedule{ ConsoleMainFunctionSchedule::Failure }
{
    Initializer();

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <template <typename> class Build, typename Process>
Framework::ConsoleMainFunctionHelper<Build, Process>::ConsoleMainFunctionHelper(ConsoleMainFunctionHelper&& rhs) noexcept
    : ParentType{ std::move(rhs) }, build{ std::move(rhs.build) }, consoleMainFunctionSchedule{ rhs.consoleMainFunctionSchedule }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <template <typename> class Build, typename Process>
Framework::ConsoleMainFunctionHelper<Build, Process>& Framework::ConsoleMainFunctionHelper<Build, Process>::operator=(ConsoleMainFunctionHelper&& rhs) noexcept
{
    ParentType::operator=(std::move(rhs));

    build = std::move(rhs.build);
    consoleMainFunctionSchedule = rhs.consoleMainFunctionSchedule;

    return *this;
}

template <template <typename> class Build, typename Process>
Framework::ConsoleMainFunctionHelper<Build, Process>::~ConsoleMainFunctionHelper() noexcept
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;

    CoreTools::NoexceptNoReturn(*this, &ClassType::Destroy);
}

#ifdef OPEN_CLASS_INVARIANT

template <template <typename> class Build, typename Process>
bool Framework::ConsoleMainFunctionHelper<Build, Process>::IsValid() const noexcept
{
    if (ParentType::IsValid() && ((ConsoleMainFunctionSchedule::Max <= consoleMainFunctionSchedule) ^ (build == nullptr)))
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <template <typename> class Build, typename Process>
void Framework::ConsoleMainFunctionHelper<Build, Process>::Destroy()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ConsoleMainFunctionSchedule::Failure < consoleMainFunctionSchedule)
    {
        Terminators();
    }

    ParentType::Destroy();
}

template <template <typename> class Build, typename CallBack>
int Framework::ConsoleMainFunctionHelper<Build, CallBack>::DoRun() noexcept
{
    return RunConsoleMainLoop();
}

template <template <typename> class Build, typename Process>
int Framework::ConsoleMainFunctionHelper<Build, Process>::RunConsoleMainLoop() noexcept
{
    if (build != nullptr)
    {
        build->EnterMessageLoop();
    }

    return 0;
}

template <template <typename> class Build, typename Process>
void Framework::ConsoleMainFunctionHelper<Build, Process>::Initializer()
{
    EXCEPTION_TRY
    {
        InitConsoleProcess();
        InitConsoleImpl();
    }
    EXCEPTION_ENTRY_POINT_CATCH
}

template <template <typename> class Build, typename Process>
void Framework::ConsoleMainFunctionHelper<Build, Process>::InitConsoleProcess() noexcept
{
    consoleMainFunctionSchedule = ConsoleMainFunctionSchedule::ConsoleProcess;
}

template <template <typename> class Build, typename Process>
void Framework::ConsoleMainFunctionHelper<Build, Process>::InitConsoleImpl()
{
    build = std::make_shared<BuildType>();
    consoleMainFunctionSchedule = ConsoleMainFunctionSchedule::Max;
}

template <template <typename> class Build, typename Process>
void Framework::ConsoleMainFunctionHelper<Build, Process>::Terminators()
{
    EXCEPTION_TRY
    {
        DestroyConsoleImpl();
        DestroyConsoleProcess();
    }
    EXCEPTION_ENTRY_POINT_CATCH
}

template <template <typename> class Build, typename Process>
void Framework::ConsoleMainFunctionHelper<Build, Process>::DestroyConsoleImpl() noexcept
{
    if (ConsoleMainFunctionSchedule::Max <= consoleMainFunctionSchedule)
    {
        build.reset();
        consoleMainFunctionSchedule = ConsoleMainFunctionSchedule::ConsoleProcess;
    }
}

template <template <typename> class Build, typename Process>
void Framework::ConsoleMainFunctionHelper<Build, Process>::DestroyConsoleProcess() noexcept
{
    if (ConsoleMainFunctionSchedule::ConsoleProcess <= consoleMainFunctionSchedule)
    {
        consoleMainFunctionSchedule = ConsoleMainFunctionSchedule::Failure;
    }
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_DETAIL_H
