///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/24 14:14)

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
        // ������������
        OutTopLevel topLevel;

        // �洢objects���Զ������ʹ��ͼ��������ȱ�����
        ObjectRegisterSharedPtr objectRegister;

        FileBufferSharedPtr buffer;
        BufferTargetSharedPtr target;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_IMPL_H
