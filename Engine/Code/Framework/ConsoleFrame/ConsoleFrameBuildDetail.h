/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 15:19)

#ifndef FRAMEWORK_CONSOLE_CONSOLE_FRAME_BUILD_DETAIL_H
#define FRAMEWORK_CONSOLE_CONSOLE_FRAME_BUILD_DETAIL_H

#include "ConsoleFrameBuild.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

template <typename ConsoleProcess>
Framework::ConsoleFrameBuild<ConsoleProcess>::ConsoleFrameBuild() noexcept
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename ConsoleProcess>
bool Framework::ConsoleFrameBuild<ConsoleProcess>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename ConsoleProcess>
void Framework::ConsoleFrameBuild<ConsoleProcess>::EnterMessageLoop() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;
}

#endif  // FRAMEWORK_CONSOLE_CONSOLE_FRAME_BUILD_DETAIL_H
