///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/09/14 11:06)

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
            ZipWriter(ZipWriter&& rhs) = delete;
            ZipWriter& operator=(ZipWriter&& rhs) = delete;

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