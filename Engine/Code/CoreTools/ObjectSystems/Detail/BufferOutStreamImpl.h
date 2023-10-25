///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 15:13)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_IMPL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/ObjectInterface.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE BufferOutStreamImpl final
    {
    public:
        using ClassType = BufferOutStreamImpl;

    public:
        explicit BufferOutStreamImpl(OutTopLevel topLevel);

        ~BufferOutStreamImpl() noexcept = default;
        BufferOutStreamImpl(const BufferOutStreamImpl& rhs) = delete;
        BufferOutStreamImpl& operator=(const BufferOutStreamImpl& rhs) = delete;
        BufferOutStreamImpl(BufferOutStreamImpl&& rhs) noexcept = delete;
        BufferOutStreamImpl& operator=(BufferOutStreamImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstFileBufferSharedPtr GetBufferOutStreamInformation() const noexcept;

    private:
        void GenerateBuffer();
        void Register();
        NODISCARD int GetBufferSize() const;
        void ResetBufferSize(int bufferSize);
        void SaveToBuffer();

    private:
        // 顶层对象的流。
        OutTopLevel topLevel;

        // 存储objects，对顶层对象使用图的深度优先遍历。
        ObjectRegisterSharedPtr objectRegister;

        BufferTargetSharedPtr target;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_IMPL_H
