//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/13 10:10)

#ifndef CORE_TOOLS_FILE_MANAGER_BUFFERIO_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_BUFFERIO_IMPL_H

#include "CoreTools/CoreToolsDll.h"

// ֧�ֶ�ȡ��д������ƻ�����������಻֧�ֶ�д���ʡ�
// ����BufferIOһ����������;��ʹ��FileHandleHelp::LoadFromFile��ȡ�����ļ���Ȼ��ʹ��BufferIO��ȡ�ֶΡ�
// ͬ����BufferIO�����ڽ��ֶ�д��һ����������Ȼ��ʹ��FileHandleHelper::SaveIntoFile���������ļ���

// ���е������ļ����洢Ϊlittle endian��ʽ����Ϊ�����ƽ̨����little endian��

// BufferIO�౻���Ϊ�������ļ����ص���������Ȼ�������������

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE BufferIOImpl
    {
    public:
        using ClassType = BufferIOImpl;

    public:
        BufferIOImpl() noexcept;
        virtual ~BufferIOImpl() noexcept = default;

        BufferIOImpl(const BufferIOImpl&) = delete;
        BufferIOImpl& operator=(const BufferIOImpl&) = delete;
        BufferIOImpl(BufferIOImpl&&) noexcept = delete;
        BufferIOImpl& operator=(BufferIOImpl&&) noexcept = delete;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] virtual int GetBytesTotal() const = 0;
        [[nodiscard]] virtual BufferIO GetBufferIOType() const noexcept = 0;

        [[nodiscard]] int GetBytesProcessed() const noexcept;
        void IncrementBytesProcessed(int bytesNumber) noexcept(g_Assert < 2 || g_CoreToolsAssert < 2);

    protected:
        void SetBytesProcessed(int bytesProcessed) noexcept;

    private:
        int m_BytesProcessed;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_BUFFERIO_IMPL_H
