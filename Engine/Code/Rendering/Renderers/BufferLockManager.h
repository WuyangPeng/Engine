///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:36)

#ifndef RENDERING_RENDERERS_BUFFER_LOCK_MANAGE_H
#define RENDERING_RENDERERS_BUFFER_LOCK_MANAGE_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    template <typename PlatformBufferType>
    class BufferLockManager
    {
    public:
        using ClassType = BufferLockManager<PlatformBufferType>;

    public:
        explicit BufferLockManager(PlatformBufferType& manager) noexcept;
        ~BufferLockManager() noexcept;
        BufferLockManager(const BufferLockManager& rhs) = delete;
        BufferLockManager& operator=(const BufferLockManager& rhs) = delete;
        BufferLockManager(BufferLockManager&& rhs) noexcept = delete;
        BufferLockManager& operator=(BufferLockManager&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD void* Lock(BufferLocking mode) noexcept;

    private:
        PlatformBufferType& manager;
        bool lock;
    };
}

#endif  // RENDERING_RENDERERS_BUFFER_LOCK_MANAGE_H
