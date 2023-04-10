///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:14)

#ifndef CORE_TOOLS_TEXT_PARSING_ZIP_ENTRY_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_ZIP_ENTRY_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "ZipEntryMetaData.h"
#include "System/Helper/PragmaWarning/Miniz.h"

namespace CoreTools::SimpleZip
{
    /// ZipEntryImpl类实现了操作zip存档中的条目所需的功能。
    /// 这是实现类。
    class CORE_TOOLS_HIDDEN_DECLARE ZipEntryImpl final
    {
    public:
        using ClassType = ZipEntryImpl;

    public:
        explicit ZipEntryImpl(const ZipEntryInfo& info);

        /// 使用给定的名称和二进制数据创建一个新的ZipEntryImpl，这应该仅用于创建新条目。
        ZipEntryImpl(const std::string& name, ZipEntryData data);

        /// 使用给定的名称和字符串数据创建一个新的ZipEntryImpl，这应该仅用于创建新条目。
        ZipEntryImpl(const std::string& name, const std::string& data);

        ~ZipEntryImpl() noexcept = default;
        ZipEntryImpl(const ZipEntryImpl& rhs) = default;
        ZipEntryImpl& operator=(const ZipEntryImpl& rhs) = default;
        ZipEntryImpl(ZipEntryImpl&& rhs) noexcept = default;
        ZipEntryImpl& operator=(ZipEntryImpl&& rhs) noexcept = default;

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

        void ReaderExtractFileToMem(mz_zip_archive* archive, const std::string& name) noexcept;
        NODISCARD bool WriterAddMem(mz_zip_archive* archive) const;

    private:
        /// 创建一个新的ZipEntryInfo结构。
        /// 此函数将根据输入的文件名创建一个新的ZipEntryInfo结构。
        /// 除了文件索引、时间戳、文件名和is_directory标志外，结构值大多是虚拟值。
        NODISCARD static ZipEntryInfo CreateInfo(const std::string& fileName);

    private:
        ZipEntryInfo entryInfo;
        ZipEntryData entryData;
        bool isModified;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_ZIP_ENTRY_IMPL_H