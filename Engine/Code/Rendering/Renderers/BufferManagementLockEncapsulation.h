///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:36)

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
