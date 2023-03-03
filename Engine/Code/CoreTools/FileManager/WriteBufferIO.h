///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/02 10:17)

#ifndef CORE_TOOLS_FILE_MANAGER_WRITE_BUFFER_IO_H
#define CORE_TOOLS_FILE_MANAGER_WRITE_BUFFER_IO_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(WriteBufferIOImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE WriteBufferIO final
    {
    public:
        NON_COPY_TYPE_DECLARE(WriteBufferIO);

    public:
        explicit WriteBufferIO(int bufferSize);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetBytesTotal() const;
        NODISCARD int GetBytesProcessed() const noexcept;

        void IncrementBytesProcessed(int bytesNumber);
        void Write(size_t itemSize, const void* data);
        void Write(size_t itemSize, size_t itemsNumber, const void* data);

        NODISCARD ConstFileBufferSharedPtr GetFileBuffer() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_WRITE_BUFFER_IO_H
