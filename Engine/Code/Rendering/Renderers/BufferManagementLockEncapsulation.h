///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/21 18:22)

#ifndef RENDERING_RENDERERS_BUFFER_MANAGEMENT_LOCK_ENCAPSULATION_H
#define RENDERING_RENDERERS_BUFFER_MANAGEMENT_LOCK_ENCAPSULATION_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    template <typename BufferManagementType>
    class BufferManagementLockEncapsulation
    {
    public:
        using ClassType = BufferManagementLockEncapsulation<BufferManagementType>;
        using ConstBufferSharedPtr = typename BufferManagementType::ConstBufferSharedPtr;

    public:
        explicit BufferManagementLockEncapsulation(BufferManagementType& manager) noexcept;
        ~BufferManagementLockEncapsulation() noexcept;
        BufferManagementLockEncapsulation(const BufferManagementLockEncapsulation& rhs) = delete;
        BufferManagementLockEncapsulation& operator=(const BufferManagementLockEncapsulation& rhs) = delete;
        BufferManagementLockEncapsulation(BufferManagementLockEncapsulation&& rhs) noexcept = delete;
        BufferManagementLockEncapsulation& operator=(BufferManagementLockEncapsulation&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD void* Lock(ConstBufferSharedPtr aBuffer, BufferLocking mode);

    private:
        BufferManagementType& manager;
        ConstBufferSharedPtr buffer;
    };
}

#endif  // RENDERING_RENDERERS_BUFFER_MANAGEMENT_LOCK_ENCAPSULATION_H
