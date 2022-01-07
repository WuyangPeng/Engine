///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/24 14:14)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_IMPL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/ObjectInterface.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE BufferOutStreamImpl final
    {
    public:
        using ClassType = BufferOutStreamImpl;

    public:
        explicit BufferOutStreamImpl(const OutTopLevel& topLevel);

        ~BufferOutStreamImpl() noexcept = default;
        BufferOutStreamImpl(const BufferOutStreamImpl& rhs) = delete;
        BufferOutStreamImpl& operator=(const BufferOutStreamImpl& rhs) = delete;
        BufferOutStreamImpl(BufferOutStreamImpl&& rhs) noexcept = delete;
        BufferOutStreamImpl& operator=(BufferOutStreamImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD FileBufferSharedPtr GetBufferOutStreamInformation() const noexcept;

    private:
        void GenerateBuffer();
        void Register();
        NODISCARD int GetBufferSize();
        void ResetBufferSize(int bufferSize);
        void SaveToBuffer();

    private:
        // 顶层对象的流。
        OutTopLevel topLevel;

        // 存储objects，对顶层对象使用图的深度优先遍历。
        ObjectRegisterSharedPtr objectRegister;

        FileBufferSharedPtr buffer;
        BufferTargetSharedPtr target;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_IMPL_H
