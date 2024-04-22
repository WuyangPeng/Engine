/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 15:19)

#ifndef CORE_TOOLS_TEXT_PARSING_ZIP_ENTRY_META_DATA_H
#define CORE_TOOLS_TEXT_PARSING_ZIP_ENTRY_META_DATA_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/TextParsing/SimpleZip/SimpleZipInternalFwd.h"

#include <string>

namespace CoreTools::SimpleZip
{
    /// ZipEntryMetaData本质上是ZipEntryInfo结构的包装器，它是miniz结构的别名。
    class CORE_TOOLS_HIDDEN_DECLARE ZipEntryMetaData final
    {
    public:
        using ClassType = ZipEntryMetaData;

    public:
        explicit ZipEntryMetaData(const ZipEntryInfo& info);

        CLASS_INVARIANT_DECLARE;

        NODISCARD uint32_t GetIndex() const noexcept;
        NODISCARD uint64_t GetCompressedSize() const noexcept;
        NODISCARD uint64_t GetUncompressedSize() const noexcept;
        NODISCARD bool IsDirectory() const noexcept;
        NODISCARD bool IsEncrypted() const noexcept;
        NODISCARD bool IsSupported() const noexcept;
        NODISCARD std::string GetFileName() const;
        NODISCARD std::string GetComment() const;
        NODISCARD time_t GetTime() const noexcept;

    private:
        uint32_t index;
        uint64_t compressedSize;
        uint64_t uncompressedSize;
        bool isDirectory;
        bool isEncrypted;
        bool isSupported;
        std::string fileName;
        std::string comment;
        time_t time;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_ZIP_ENTRY_META_DATA_H