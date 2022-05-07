///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 14:07)

#ifndef FRAMEWORK_MACINTOSH_MACINTOSH_FRAME_BUILD_DETAIL_H
#define FRAMEWORK_MACINTOSH_MACINTOSH_FRAME_BUILD_DETAIL_H

#include "MacintoshFrameBuild.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename MacintoshProcess>
Framework::MacintoshFrameBuild<MacintoshProcess>::MacintoshFrameBuild() noexcept
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename MacintoshProcess>
bool Framework::MacintoshFrameBuild<MacintoshProcess>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename MacintoshProcess>
void Framework::MacintoshFrameBuild<MacintoshProcess>::EnterMessageLoop() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;
}

#endif  // FRAMEWORK_MACINTOSH_MACINTOSH_FRAME_BUILD_DETAIL_H
