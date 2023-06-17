///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:33)

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