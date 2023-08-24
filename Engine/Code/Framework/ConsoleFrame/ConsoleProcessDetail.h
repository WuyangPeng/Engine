///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/08 19:52)

#ifndef FRAMEWORK_CONSOLE_CONSOLE_PROCESS_DETAIL_H
#define FRAMEWORK_CONSOLE_CONSOLE_PROCESS_DETAIL_H

#include "ConsoleProcess.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

#ifdef OPEN_CLASS_INVARIANT

template <typename ConsoleCallBack>
bool Framework::ConsoleProcess<ConsoleCallBack>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

#endif  // FRAMEWORK_CONSOLE_CONSOLE_PROCESS_DETAIL_H
