///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/08 23:32)

#ifndef CORE_TOOLS_FILE_MANAGER_WRITE_BUFFERIO_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_WRITE_BUFFERIO_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "BufferIOImpl.h"
#include "CoreTools/FileManager/FileBuffer.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE WriteBufferIOImpl final : public BufferIOImpl
    {
    public:
        using ClassType = WriteBufferIOImpl;
        using ParentType = BufferIOImpl;

    public:
        explicit WriteBufferIOImpl(int bufferSize);

        CLASS_INVARIANT_FINAL_DECLARE;

        void Write(size_t itemSize, const void* data);
        void Write(size_t itemSize, size_t itemsNumber, const void* data);
        NODISCARD int GetBytesTotal() const final;

        NODISCARD BufferIO GetBufferIOType() const noexcept final;
        NODISCARD ConstFileBufferSharedPtr GetFileBuffer() const noexcept;

    private:
        // ���ҽ���д����ֽ�������data�Ĵ�С�������ǳɹ��ġ������׳�Error�쳣��
        uint32_t WriteToBuffer(size_t itemSize, size_t itemsNumber, const void* data);

    private:
        FileBufferSharedPtr buffer;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_WRITE_BUFFERIO_IMPL_H