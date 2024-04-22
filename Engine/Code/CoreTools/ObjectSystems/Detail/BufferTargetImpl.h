/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 22:09)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_IMPL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/FileManager/WriteBufferIO.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE BufferTargetImpl final
    {
    public:
        using ClassType = BufferTargetImpl;

    public:
        BufferTargetImpl(int bufferSize, const ConstObjectRegisterSharedPtr& objectRegister);
        ~BufferTargetImpl() noexcept = default;
        BufferTargetImpl(const BufferTargetImpl& rhs) noexcept = delete;
        BufferTargetImpl& operator=(const BufferTargetImpl& rhs) noexcept = delete;
        BufferTargetImpl(BufferTargetImpl&& rhs) noexcept = delete;
        BufferTargetImpl& operator=(BufferTargetImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        /// ԭ������д�뺯����
        void Write(size_t itemSize, const void* data);
        void Write(size_t itemSize, size_t itemsNumber, const void* data);

        /// ��������
        NODISCARD int GetBytesWritten() const noexcept;
        void WriteUniqueId(const ConstObjectInterfaceSharedPtr& object);

        NODISCARD ConstFileBufferSharedPtr GetFileBuffer() const noexcept;

    private:
        WriteBufferIO target;
        ConstObjectRegisterSharedPtr objectRegister;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_IMPL_H
