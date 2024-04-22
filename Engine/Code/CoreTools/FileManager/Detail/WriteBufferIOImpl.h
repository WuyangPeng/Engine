/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 22:50)

#ifndef CORE_TOOLS_FILE_MANAGER_WRITE_BUFFER_IO_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_WRITE_BUFFER_IO_IMPL_H

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
        NODISCARD int GetBytesTotal() const override;

        NODISCARD BufferIO GetBufferIOType() const noexcept override;
        NODISCARD ConstFileBufferSharedPtr GetFileBuffer() const noexcept;

    private:
        /// 当且仅当写入的字节数等于data的大小，操作是成功的。否则抛出Error异常。
        uint32_t WriteToBuffer(size_t itemSize, size_t itemsNumber, const void* data);

    private:
        FileBufferSharedPtr buffer;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_WRITE_BUFFER_IO_IMPL_H