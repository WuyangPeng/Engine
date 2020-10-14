//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/13 20:20)

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
        [[nodiscard]] int GetBytesTotal() const final;

        [[nodiscard]] BufferIO GetBufferIOType() const noexcept final;

    private:
        // ���ҽ���д����ֽ�������data�Ĵ�С�������ǳɹ��ġ������׳�Error�쳣��
        uint32_t WriteToBuffer(size_t itemSize, size_t itemsNumber, const void* data);

    private:
        FileBuffer m_Buffer;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_WRITE_BUFFERIO_IMPL_H