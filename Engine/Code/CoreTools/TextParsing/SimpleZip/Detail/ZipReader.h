/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 15:20)

#ifndef CORE_TOOLS_TEXT_PARSING_ZIP_READER_H
#define CORE_TOOLS_TEXT_PARSING_ZIP_READER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/TextParsing/SimpleZip/SimpleZipInternalFwd.h"
#include "CoreTools/TextParsing/SimpleZip/ZipEntry.h"

#include <string>
#include <vector>

namespace CoreTools::SimpleZip
{
    class CORE_TOOLS_HIDDEN_DECLARE ZipReader final
    {
    public:
        using ClassType = ZipReader;

        using ZipEntryType = std::vector<ZipEntry>;

    public:
        explicit ZipReader(std::string archivePath);
        ~ZipReader() noexcept;
        ZipReader(const ZipReader& rhs) = delete;
        ZipReader& operator=(const ZipReader& rhs) = delete;
        ZipReader(ZipReader&& rhs) noexcept = delete;
        ZipReader& operator=(ZipReader&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD mz_zip_archive* GetArchive() noexcept;
        NODISCARD ZipEntryType GetEntry();

    private:
        void Init();
        void Close() noexcept;
        NODISCARD ZipEntryInfo GetZipEntryInfo(mz_uint index);

    private:
        std::string archivePath;
        mz_zip_archive archive;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_ZIP_READER_H