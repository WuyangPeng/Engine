/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 15:17)

#ifndef FRAMEWORK_LINUX_LINUX_FRAME_BUILD_DETAIL_H
#define FRAMEWORK_LINUX_LINUX_FRAME_BUILD_DETAIL_H

#include "LinuxFrameBuild.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

template <typename LinuxProcess>
Framework::LinuxFrameBuild<LinuxProcess>::LinuxFrameBuild() noexcept
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename LinuxProcess>
bool Framework::LinuxFrameBuild<LinuxProcess>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename LinuxProcess>
void Framework::LinuxFrameBuild<LinuxProcess>::EnterMessageLoop() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;
}

#endif  // FRAMEWORK_LINUX_LINUX_FRAME_BUILD_DETAIL_H
