/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 09:53)

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
        // ������������
        OutTopLevel topLevel;

        // �洢objects���Զ������ʹ��ͼ��������ȱ�����
        ObjectRegisterSharedPtr objectRegister;

        BufferTargetSharedPtr target;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_IMPL_H
