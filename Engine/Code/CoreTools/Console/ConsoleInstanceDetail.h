///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/11 14:54)

#ifndef CORE_TOOLS_CONSOLE_CONSOLE_INSTANCE_DETAIL_H
#define CORE_TOOLS_CONSOLE_CONSOLE_INSTANCE_DETAIL_H

#include "ConsoleInstance.h"
#include "System/Console/ConsoleHandle.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <CoreTools::StandardHandle Handle>
CoreTools::ConsoleInstance<Handle> CoreTools::ConsoleInstance<Handle>::Create()
{
    return ConsoleInstance{ DisableNotThrow::Disable };
}

template <CoreTools::StandardHandle Handle>
CoreTools::ConsoleInstance<Handle>::ConsoleInstance(MAYBE_UNUSED DisableNotThrow disableNotThrow)
    : handle{ System::GetStandardHandle(Handle) }
{
    if (!System::IsHandleValid(handle))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("获取标准设备的句柄失败。"s));
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
typename CoreTools::ConsoleInstance<Handle>::ConsoleHandle CoreTools::ConsoleInstance<Handle>::GetHandle() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return handle;
}

#endif  // CORE_TOOLS_CONSOLE_CONSOLE_INSTANCE_DETAIL_H
