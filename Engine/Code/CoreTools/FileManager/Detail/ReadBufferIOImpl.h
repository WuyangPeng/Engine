/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/30 22:49)

#ifndef CORE_TOOLS_FILE_MANAGER_READ_BUFFER_IO_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_READ_BUFFER_IO_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "BufferIOImpl.h"
#include "CoreTools/FileManager/FileBuffer.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ReadBufferIOImpl final : public BufferIOImpl
    {
    public:
        using ClassType = ReadBufferIOImpl;
        using ParentType = BufferIOImpl;

    public:
        explicit ReadBufferIOImpl(const ConstFileBufferSharedPtr& fileBuffer) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD std::string GetText(int length) const;

        void Read(size_t itemSize, void* data);
        void Read(size_t itemSize, size_t itemsNumber, void* data);

        NODISCARD int GetBytesTotal() const override;

        NODISCARD BufferIO GetBufferIOType() const noexcept override;

    private:
        /// ���ҽ����������ֽ�������data�Ĵ�С�������ǳɹ��ġ������׳�Error�쳣��
        int ReadFromBuffer(size_t itemSize, size_t itemsNumber, void* data);

    private:
        ConstFileBufferSharedPtr buffer;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_READ_BUFFER_IO_IMPL_H