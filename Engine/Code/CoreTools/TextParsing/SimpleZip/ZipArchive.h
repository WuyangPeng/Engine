/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 15:20)

#ifndef CORE_TOOLS_TEXT_PARSING_ZIP_ARCHIVE_H
#define CORE_TOOLS_TEXT_PARSING_ZIP_ARCHIVE_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/TextParsing/SimpleZip/SimpleZipInternalFwd.h"

#include <memory>
#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<CoreTools::SimpleZip::ZipArchiveImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::NonCopyImpl<CoreTools::SimpleZip::ZipArchiveImpl>;

namespace CoreTools::SimpleZip
{
    class CORE_TOOLS_DEFAULT_DECLARE ZipArchive final
    {
    public:
        NON_COPY_TYPE_DECLARE(ZipArchive);

    public:
        NODISCARD static ZipArchive Create();

        explicit ZipArchive(const std::string& fileName);
        ZipArchive(const std::string& fileName, bool isCreate);

        CLASS_INVARIANT_DECLARE;

        void Save(const std::string& path = std::string{});

        void AddEntry(const std::string& name, const std::string& data);

        void DeleteEntry(const std::string& entryName);

        NODISCARD std::string GetEntry(const std::string& name);

        NODISCARD bool HasEntry(const std::string& entryName);

    private:
        explicit ZipArchive(DisableNotThrow disableNotThrow);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_ZIP_ARCHIVE_H
