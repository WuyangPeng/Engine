///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/06 11:27)

#ifndef CORE_TOOLS_TEXT_PARSING_ZIP_WRITER_H
#define CORE_TOOLS_TEXT_PARSING_ZIP_WRITER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/TextParsing/SimpleZip/SimpleZipInternalFwd.h"

#include <string>
#include <vector>

namespace CoreTools::SimpleZip
{
    class CORE_TOOLS_HIDDEN_DECLARE ZipWriter final
    {
    public:
        using ClassType = ZipWriter;

    public:
        explicit ZipWriter(std::string archivePath) noexcept;
        ~ZipWriter() noexcept;
        ZipWriter(const ZipWriter& rhs) = delete;
        ZipWriter& operator=(const ZipWriter& rhs) = delete;
        ZipWriter(ZipWriter&& rhs) noexcept = delete;
        ZipWriter& operator=(ZipWriter&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        void Close() noexcept;

        void ValidateFileArchive() const;

        void AddZipEntry(const ZipEntry& zipEntry, mz_zip_archive* readArchive);

    private:
        void Init() noexcept;

    private:
        std::string archivePath;
        mz_zip_archive archive;
        bool isClose;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_ZIP_WRITER_H