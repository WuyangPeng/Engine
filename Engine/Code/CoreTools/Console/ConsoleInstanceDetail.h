/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 20:35)

#ifndef CORE_TOOLS_CONSOLE_CONSOLE_INSTANCE_DETAIL_H
#define CORE_TOOLS_CONSOLE_CONSOLE_INSTANCE_DETAIL_H

#include "ConsoleInstance.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <CoreTools::StandardHandle Handle>
CoreTools::ConsoleInstance<Handle> CoreTools::ConsoleInstance<Handle>::Create()
{
    return ConsoleInstance{ DisableNotThrow::Disable };
}

template <CoreTools::StandardHandle Handle>
CoreTools::ConsoleInstance<Handle>::ConsoleInstance(DisableNotThrow disableNotThrow)
    : handle{ System::GetStandardHandle(Handle) }
{
    System::UnusedFunction(disableNotThrow);

    if (!System::IsHandleValid(handle))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("获取标准设备的句柄失败。"s))
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <CoreTools::StandardHandle Handle>
bool CoreTools::ConsoleInstance<Handle>::IsValid() const noexcept
{
    if (System::IsHandleValid(handle))
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <CoreTools::StandardHandle Handle>
typename CoreTools::ConsoleInstance<Handle>::ConsoleHandle CoreTools::ConsoleInstance<Handle>::GetHandle() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return handle;
}

#endif  // CORE_TOOLS_CONSOLE_CONSOLE_INSTANCE_DETAIL_H
