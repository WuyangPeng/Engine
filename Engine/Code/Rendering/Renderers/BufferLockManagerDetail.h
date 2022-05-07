///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/21 17:18)

#ifndef RENDERING_RENDERERS_BUFFER_LOCK_MANAGE_DETAIL_H
#define RENDERING_RENDERERS_BUFFER_LOCK_MANAGE_DETAIL_H

#include "BufferLockManager.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename PlatformBufferType>
Rendering::BufferLockManager<PlatformBufferType>::BufferLockManager(PlatformBufferType& manager) noexcept
    : manager{ manager }, lock{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

template <typename PlatformBufferType>
Rendering::BufferLockManager<PlatformBufferType>::~BufferLockManager() noexcept
{
    EXCEPTION_TRY
    {
        if (lock)
        {
            manager.Unlock();
        }
    }
    EXCEPTION_ALL_CATCH(Rendering)

    RENDERING_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename PlatformBufferType>
bool Rendering::BufferLockManager<PlatformBufferType>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename PlatformBufferType>
void* Rendering::BufferLockManager<PlatformBufferType>::Lock(BufferLocking mode) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    auto videoMemory = manager.Lock(mode);
    lock = true;

    return videoMemory;
}

#endif  // RENDERING_RENDERERS_BUFFER_LOCK_MANAGE_DETAIL_H