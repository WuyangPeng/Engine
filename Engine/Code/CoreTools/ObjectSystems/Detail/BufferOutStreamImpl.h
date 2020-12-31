//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/21 10:17)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_IMPL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/ObjectInterface.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"

namespace CoreTools
{
    // 写objects到内存块。当操作失败时，抛出Error异常。
    class CORE_TOOLS_HIDDEN_DECLARE BufferOutStreamImpl final : private boost::noncopyable
    {
    public:
        using ClassType = BufferOutStreamImpl;

    public:
        explicit BufferOutStreamImpl(const OutTopLevel& topLevel);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] FileBufferSharedPtr GetBufferOutStreamInformation() const noexcept;

    private:
        void GenerateBuffer();
        void Register();
        [[nodiscard]] int GetBufferSize();
        void ResetBufferSize(int bufferSize);
        void SaveToBuffer();

    private:
        // 顶层对象的流。
        OutTopLevel m_TopLevel;

        // 存储objects，对顶层对象使用图的深度优先遍历。
        ObjectRegisterSharedPtr m_ObjectRegister;

        FileBufferSharedPtr m_Buffer;
        BufferTargetSharedPtr m_Target;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_IMPL_H
