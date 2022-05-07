///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 14:18)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_ANDROID_MAIN_FUNCTION_HELPER_DETAIL_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_ANDROID_MAIN_FUNCTION_HELPER_DETAIL_H

#include "AndroidMainFunctionHelper.h"
#include "Flags/MainFunctionSchedule.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Framework/AndroidFrame/AndroidProcessManager.h"

template <template <typename> class Build, typename Process>
Framework::AndroidMainFunctionHelper<Build, Process>::AndroidMainFunctionHelper(AndroidApp* androidApp, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ environmentDirectory }, build{}, androidMainFunctionSchedule{ AndroidMainFunctionSchedule::Failure }
{
    Initializers(androidApp);

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <template <typename> class Build, typename Process>
Framework::AndroidMainFunctionHelper<Build, Process>::AndroidMainFunctionHelper(AndroidMainFunctionHelper&& rhs) noexcept
    : ParentType{ std::move(rhs) }, build{ std::move(rhs.build) }, androidMainFunctionSchedule{ rhs.androidMainFunctionSchedule }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <template <typename> class Build, typename Process>
Framework::AndroidMainFunctionHelper<Build, Process>& Framework::AndroidMainFunctionHelper<Build, Process>::operator=(AndroidMainFunctionHelper&& rhs) noexcept
{
    ParentType::operator=(std::move(rhs));

    build = std::move(rhs.build);
    androidMainFunctionSchedule = rhs.androidMainFunctionSchedule;

    return *this;
}

template <template <typename> class Build, typename Process>
Framework::AndroidMainFunctionHelper<Build, Process>::~AndroidMainFunctionHelper() noexcept
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;

    CoreTools::NoexceptNoReturn(*this, &ClassType::Destroy);
}

#ifdef OPEN_CLASS_INVARIANT
template <template <typename> class Build, typename Process>
bool Framework::AndroidMainFunctionHelper<Build, Process>::IsValid() const noexcept
{
    if (ParentType::IsValid() && ((AndroidMainFunctionSchedule::Max <= androidMainFunctionSchedule) ^ (build == nullptr)))
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <template <typename> class Build, typename Process>
void Framework::AndroidMainFunctionHelper<Build, Process>::Destroy()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (AndroidMainFunctionSchedule::Failure < androidMainFunctionSchedule)
    {
        Terminators();
    }

    ParentType::Destroy();
}

// protected
template <template <typename> class Build, typename Process>
System::AndroidApp* Framework::AndroidMainFunctionHelper<Build, Process>::GetAndroidApp()
{
    using namespace std::literals;

    if (build != nullptr)
    {
        return build->GetAndroidApp();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("获取安卓App失败！"s));
    }
}

// private
template <template <typename> class Build, typename CallBack>
int Framework::AndroidMainFunctionHelper<Build, CallBack>::DoRun()
{
    return RunAndroidMainLoop();
}

// private
template <template <typename> class Build, typename Process>
int Framework::AndroidMainFunctionHelper<Build, Process>::RunAndroidMainLoop()
{
    if (build != nullptr)
    {
        build->EnterMessageLoop();
    }

    return 0;
}

// private
template <template <typename> class Build, typename Process>
void Framework::AndroidMainFunctionHelper<Build, Process>::Initializers(AndroidApp* androidApp)
{
    EXCEPTION_TRY
    {
        InitAndroidProcess();
        InitImpl(androidApp);
    }
    EXCEPTION_ENTRY_POINT_CATCH
}

// private
template <template <typename> class Build, typename Process>
void Framework::AndroidMainFunctionHelper<Build, Process>::InitAndroidProcess()
{
    AndroidProcessManager::Create();
    androidMainFunctionSchedule = AndroidMainFunctionSchedule::AndroidProcess;
}

// private
template <template <typename> class Build, typename Process>
void Framework::AndroidMainFunctionHelper<Build, Process>::InitImpl(AndroidApp* androidApp)
{
    build = std::make_shared<BuildType>(androidApp);
    androidMainFunctionSchedule = AndroidMainFunctionSchedule::Max;
}

// private
template <template <typename> class Build, typename Process>
void Framework::AndroidMainFunctionHelper<Build, Process>::Terminators()
{
    EXCEPTION_TRY
    {
        DestroyImpl();
        DestroyAndroidProcess();
    }
    EXCEPTION_ENTRY_POINT_CATCH
}

// private
template <template <typename> class Build, typename Process>
void Framework::AndroidMainFunctionHelper<Build, Process>::DestroyImpl() noexcept
{
    if (AndroidMainFunctionSchedule::Max <= androidMainFunctionSchedule)
    {
        build.reset();
        androidMainFunctionSchedule = AndroidMainFunctionSchedule::AndroidProcess;
    }
}

// private
template <template <typename> class Build, typename Process>
void Framework::AndroidMainFunctionHelper<Build, Process>::DestroyAndroidProcess() noexcept
{
    if (AndroidMainFunctionSchedule::AndroidProcess <= androidMainFunctionSchedule)
    {
        AndroidProcessManager::Destroy();
        androidMainFunctionSchedule = AndroidMainFunctionSchedule::Failure;
    }
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_ANDROID_MAIN_FUNCTION_HELPER_DETAIL_H
