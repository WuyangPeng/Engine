//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 10:10)

#ifndef CORE_TOOLS_FILE_MANAGER_BUFFERIO_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_BUFFERIO_IMPL_H

#include "CoreTools/CoreToolsDll.h"

// 支持读取或写入二进制缓冲区。这个类不支持读写访问。
// 对于BufferIO一个常见的用途是使用FileHandleHelp::LoadFromFile读取整个文件，然后使用BufferIO读取字段。
// 同样，BufferIO可用于将字段写入一个缓冲区，然后使用FileHandleHelper::SaveIntoFile保存整个文件。

// 所有的数据文件都存储为little endian格式，因为大多数平台都是little endian。

// BufferIO类被设计为将整个文件加载到缓冲区，然后解析缓冲区。

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
