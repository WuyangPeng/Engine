//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 20:19)

#ifndef CORE_TOOLS_FILE_MANAGER_READ_BUFFERIO_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_READ_BUFFERIO_IMPL_H

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

        [[nodiscard]] std::string GetText(int length) const;

        void Read(size_t itemSize, void* data);
        void Read(size_t itemSize, size_t itemsNumber, void* data);

        [[nodiscard]] int GetBytesTotal() const final;

        [[nodiscard]] BufferIO GetBufferIOType() const noexcept final;

    private:
        // 当且仅当读出的字节数等于data的大小，操作是成功的。否则抛出Error异常。
        int ReadFromBuffer(size_t itemSize, size_t itemsNumber, void* data);

    private:
        ConstFileBufferSharedPtr m_Buffer;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_READ_BUFFERIO_IMPL_H