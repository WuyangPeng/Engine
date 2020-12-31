//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/21 10:17)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_IMPL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/ObjectInterface.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"

namespace CoreTools
{
    // дobjects���ڴ�顣������ʧ��ʱ���׳�Error�쳣��
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
        // ������������
        OutTopLevel m_TopLevel;

        // �洢objects���Զ������ʹ��ͼ��������ȱ�����
        ObjectRegisterSharedPtr m_ObjectRegister;

        FileBufferSharedPtr m_Buffer;
        BufferTargetSharedPtr m_Target;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_IMPL_H
