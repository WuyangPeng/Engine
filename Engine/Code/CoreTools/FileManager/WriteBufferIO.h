///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/08 23:43)

#ifndef CORE_TOOLS_FILE_MANAGER_WRITE_BUFFERIO_H
#define CORE_TOOLS_FILE_MANAGER_WRITE_BUFFERIO_H

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

#endif  // CORE_TOOLS_FILE_MANAGER_WRITE_BUFFERIO_H
