//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 20:30)

#ifndef CORE_TOOLS_FILE_MANAGER_WRITE_BUFFERIO_H
#define CORE_TOOLS_FILE_MANAGER_WRITE_BUFFERIO_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

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
        ~WriteBufferIO() noexcept = default;
        WriteBufferIO(const WriteBufferIO& rhs) noexcept = delete;
        WriteBufferIO& operator=(const WriteBufferIO& rhs) noexcept = delete;
        WriteBufferIO(WriteBufferIO&& rhs) noexcept = delete;
        WriteBufferIO& operator=(WriteBufferIO&& rhs) noexcept = delete;
        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int GetBytesTotal() const;
        [[nodiscard]] int GetBytesProcessed() const noexcept;

        void IncrementBytesProcessed(int bytesNumber) noexcept(g_Assert < 2 || g_CoreToolsAssert < 2);
        void Write(size_t itemSize, const void* data);
        void Write(size_t itemSize, size_t itemsNumber, const void* data);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_WRITE_BUFFERIO_H
