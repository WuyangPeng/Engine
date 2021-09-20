//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/21 10:20)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_IMPL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_IMPL_H

#include "CoreTools/CoreToolsDll.h"

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

        // 原生数据写入函数。
        void Write(size_t itemSize, const void* data);
        void Write(size_t itemSize, size_t itemsNumber, const void* data);

        // 帮助函数
        [[nodiscard]] int GetBytesWritten() const noexcept;
        void WriteUniqueID(const ConstObjectInterfaceSharedPtr& object);

    private:
        WriteBufferIO m_Target;
        ConstObjectRegisterSharedPtr m_ObjectRegister;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_IMPL_H
