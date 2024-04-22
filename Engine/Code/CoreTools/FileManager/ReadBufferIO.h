/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/30 22:56)

#ifndef CORE_TOOLS_FILE_MANAGER_READ_BUFFER_IO_H
#define CORE_TOOLS_FILE_MANAGER_READ_BUFFER_IO_H

#include "CoreTools/CoreToolsDll.h"

#include "FileBuffer.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(ReadBufferIOImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ReadBufferIO final
    {
    public:
        NON_COPY_TYPE_DECLARE(ReadBufferIO);

    public:
        explicit ReadBufferIO(const ConstFileBufferSharedPtr& fileBuffer);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetText(int length) const;

        NODISCARD int GetBytesTotal() const;
        NODISCARD int GetBytesProcessed() const noexcept;

        void IncrementBytesProcessed(int bytesNumber);
        void Read(size_t itemSize, void* data);
        void Read(size_t itemSize, size_t itemsNumber, void* data);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_READ_BUFFER_IO_H
