/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 22:49)

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
        /// 当且仅当读出的字节数等于data的大小，操作是成功的。否则抛出Error异常。
        int ReadFromBuffer(size_t itemSize, size_t itemsNumber, void* data);

    private:
        ConstFileBufferSharedPtr buffer;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_READ_BUFFER_IO_IMPL_H