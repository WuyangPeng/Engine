/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 15:20)

#ifndef CORE_TOOLS_TEXT_PARSING_ZIP_ENTRY_H
#define CORE_TOOLS_TEXT_PARSING_ZIP_ENTRY_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/TextParsing/SimpleZip/SimpleZipInternalFwd.h"

#include <memory>
#include <string>
#include <vector>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<CoreTools::SimpleZip::ZipEntryImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::DelayCopyUnsharedImpl<CoreTools::SimpleZip::ZipEntry, CoreTools::SimpleZip::ZipEntryImpl>;

namespace CoreTools::SimpleZip
{
    class CORE_TOOLS_DEFAULT_DECLARE ZipEntry final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(ZipEntry);

    public:
        explicit ZipEntry(const ZipEntryInfo& info);
        ZipEntry(const std::string& name, const ZipEntryData& data);
        ZipEntry(const std::string& name, const std::string& data);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ZipEntryData GetEntryData() const;
        NODISCARD size_t GetEntrySize() const noexcept;
        NODISCARD bool IsEntryDataEmpty() const noexcept;

        NODISCARD std::string GetDataAsString() const;
        void SetData(const std::string& data);
        void SetData(const ZipEntryData& data);

        NODISCARD std::string GetFileName() const;
        void SetFileName(const std::string& name);

        NODISCARD uint32_t GetIndex() const noexcept;
        NODISCARD uint64_t GetCompressedSize() const noexcept;
        NODISCARD uint64_t GetUncompressedSize() const noexcept;
        NODISCARD bool IsDirectory() const noexcept;
        NODISCARD bool IsEncrypted() const noexcept;
        NODISCARD bool IsSupported() const noexcept;
        NODISCARD std::string GetComment() const;
        NODISCARD time_t GetTime() const noexcept;

        NODISCARD ZipEntryInfo GetZipEntryInfo() const noexcept;
        void ResizeZipEntryData(int uncompressedSize);

        NODISCARD bool IsModified() const noexcept;

        void ReaderExtractFileToMem(mz_zip_archive* archive, const std::string& name);
        NODISCARD bool WriterAddMem(mz_zip_archive* archive) const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_ZIP_ENTRY_H