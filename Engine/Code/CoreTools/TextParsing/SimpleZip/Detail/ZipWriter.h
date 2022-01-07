///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 13:41)

#ifndef CORE_TOOLS_TEXT_PARSING_ZIP_WRITER_H
#define CORE_TOOLS_TEXT_PARSING_ZIP_WRITER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/TextParsing/SimpleZip/SimpleZipInternalFwd.h"

#include <string>
#include <vector>

namespace CoreTools
{
    namespace SimpleZip
    {
        class CORE_TOOLS_HIDDEN_DECLARE ZipWriter final
        {
        public:
            using ClassType = ZipWriter;

        public:
            explicit ZipWriter(const std::string& archivePath);
            ~ZipWriter() noexcept;
            ZipWriter(const ZipWriter& rhs) = delete;
            ZipWriter& operator=(const ZipWriter& rhs) = delete;
            ZipWriter(ZipWriter&& rhs) noexcept = delete;
            ZipWriter& operator=(ZipWriter&& rhs) noexcept = delete;

            CLASS_INVARIANT_DECLARE;

            void Close() noexcept;

            void ValidateFileArchive();

            void AddZipEntry(const ZipEntry& zipEntry, mz_zip_archive* readArchive);

        private:
            void Init() noexcept;

        private:
            std::string archivePath;
            mz_zip_archive archive;
            bool isClose;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_ZIP_WRITER_H