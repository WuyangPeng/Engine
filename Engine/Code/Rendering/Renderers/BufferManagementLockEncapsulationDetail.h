///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:33)

#ifndef RENDERING_RENDERERS_BUFFER_MANAGEMENT_LOCK_ENCAPSULATION_DETAIL_H
#define RENDERING_RENDERERS_BUFFER_MANAGEMENT_LOCK_ENCAPSULATION_DETAIL_H

#include "BufferManagementLockEncapsulation.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename BufferManagementType>
Rendering::BufferManagementLockEncapsulation<BufferManagementType>::BufferManagementLockEncapsulation(BufferManagementType& manager) noexcept
    : manager{ manager }, buffer{ nullptr }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

template <typename BufferManagementType>
Rendering::BufferManagementLockEncapsulation<BufferManagementType>::~BufferManagementLockEncapsulation() noexcept
{
    EXCEPTION_TRY
    {
        if (buffer != nullptr)
        {
            manager.Unlock(buffer);
        }
    }
    EXCEPTION_ALL_CATCH(Rendering)

    RENDERING_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename BufferManagementType>
bool Rendering::BufferManagementLockEncapsulation<BufferManagementType>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename BufferManagementType>
void* Rendering::BufferManagementLockEncapsulation<BufferManagementType>::Lock(ConstBufferSharedPtr aBuffer, BufferLocking mode)
{
    RENDERING_CLASS_IS_VALID_9;

    auto videoMemory = manager.Lock(aBuffer, mode);
    buffer = aBuffer;

    return videoMemory;
}

#endif  // RENDERING_RENDERERS_BUFFER_MANAGEMENT_LOCK_ENCAPSULATION_DETAIL_H