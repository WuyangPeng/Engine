///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/08 19:51)

#ifndef FRAMEWORK_MACINTOSH_MACINTOSH_FRAME_BUILD_DETAIL_H
#define FRAMEWORK_MACINTOSH_MACINTOSH_FRAME_BUILD_DETAIL_H

#include "MacintoshFrameBuild.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

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
