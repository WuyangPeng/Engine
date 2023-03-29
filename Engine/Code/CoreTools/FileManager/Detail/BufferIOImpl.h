///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/23 15:21)

#ifndef CORE_TOOLS_FILE_MANAGER_BUFFER_IO_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_BUFFER_IO_IMPL_H

#include "CoreTools/CoreToolsDll.h"

/// ֧�ֶ�ȡ��д������ƻ�����������಻֧�ֶ�д���ʡ�
/// ����BufferIOһ����������;��ʹ��FileHandleHelp::LoadFromFile��ȡ�����ļ���Ȼ��ʹ��BufferIO��ȡ�ֶΡ�
/// ͬ����BufferIO�����ڽ��ֶ�д��һ����������Ȼ��ʹ��FileHandleHelper::SaveIntoFile���������ļ���

/// ���е������ļ����洢Ϊlittle endian��ʽ����Ϊ�����ƽ̨����little endian��

/// BufferIO�౻���Ϊ�������ļ����ص���������Ȼ�������������

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

        BufferIOImpl(const BufferIOImpl& rhs) = delete;
        BufferIOImpl& operator=(const BufferIOImpl& rhs) = delete;
        BufferIOImpl(BufferIOImpl&& rhs) noexcept = delete;
        BufferIOImpl& operator=(BufferIOImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetBytesTotal() const = 0;
        NODISCARD virtual BufferIO GetBufferIOType() const noexcept = 0;

        NODISCARD int GetBytesProcessed() const noexcept;
        void IncrementBytesProcessed(int bytesNumber);

    protected:
        void SetBytesProcessed(int aBytesProcessed) noexcept;

    private:
        int bytesProcessed;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_BUFFER_IO_IMPL_H
