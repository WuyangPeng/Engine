///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/09/13 17:23)

#ifndef CORE_TOOLS_TEXT_PARSING_ZIP_ARCHIVE_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_ZIP_ARCHIVE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "ZipEntryMetaData.h"
#include "ZipReader.h"
#include "CoreTools/TextParsing/SimpleZip/SimpleZipInternalFwd.h"

#include <memory>

namespace CoreTools
{
    namespace SimpleZip
    {
        /// ZipArchiveImpl类代表整个zip存档文件。
        /// 它由单独的zip条目组成，可以是文件和文件夹。
        /// 它是磁盘上.zip 存档的主要访问点，可用于创建新存档以及打开和修改现有存档。
        /// 使用ZipArchiveImpl 类，可以创建新的.zip 存档文件，以及打开和修改现有文件。
        /// 请注意，.zip 存档中的实际文件可以通过ZipEntry接口而不是ZipArchiveImpl接口检索。
        class CORE_TOOLS_HIDDEN_DECLARE ZipArchiveImpl final
        {
        public:
            using ClassType = ZipArchiveImpl;
            using EntryNamesType = std::vector<std::string>;
            using ZipEntryMetaDataType = std::vector<ZipEntryMetaData>;

        public:
            /// 使用fileName输入参数构造归档对象。 如果文件已经存在，它将被打开。 否则，将创建一个新对象。
            ZipArchiveImpl() noexcept;
            explicit ZipArchiveImpl(const std::string& fileName);
            ZipArchiveImpl(const std::string& fileName, bool isCreate);

            virtual ~ZipArchiveImpl() noexcept;
            ZipArchiveImpl(const ZipArchiveImpl& rhs) = delete;
            ZipArchiveImpl& operator=(const ZipArchiveImpl& rhs) = delete;
            ZipArchiveImpl(ZipArchiveImpl&& rhs) noexcept;
            ZipArchiveImpl& operator=(ZipArchiveImpl&& rhs) noexcept;

            CLASS_INVARIANT_DECLARE;

            /// 获取档案中条目的列表。 根据输入参数，列表将包括目录、文件或两者。
            NODISCARD EntryNamesType GetEntryNames(bool includeDirs = true, bool includeFiles = true) const;

            /// 获取档案特定目录中的条目列表。 根据输入参数，列表将包括目录、文件或两者。
            /// 此函数的行为与GetEntryNames()函数略有不同。请求文件夹中的所有条目将作为绝对路径返回，但是，只会返回一级子文件夹。
            NODISCARD EntryNamesType GetEntryNamesInDir(const std::string& dir, bool includeDirs = true, bool includeFiles = true) const;

            /// 获取档案中条目的元数据列表。 根据输入参数，列表将包括目录、文件或两者。
            NODISCARD ZipEntryMetaDataType GetMetaData(bool includeDirs = true, bool includeFiles = true) const;

            /// 获取档案特定目录中条目的元数据列表。 根据输入参数，列表将包括目录、文件或两者。
            /// 目录本身不包括在内。
            NODISCARD ZipEntryMetaDataType GetMetaDataInDir(const std::string& dir, bool includeDirs = true, bool includeFiles = true) const;

            NODISCARD int GetNumEntries(bool includeDirs = true, bool includeFiles = true) const;
            NODISCARD int GetNumEntriesInDir(const std::string& dir, bool includeDirs = true, bool includeFiles = true) const;
            NODISCARD bool HasEntry(const std::string& entryName) const;

            /// 使用新名称保存存档。 原始存档将保持不变。
            /// 如果没有提供文件名，文件将以现有名称保存，覆盖任何现有数据。
            void Save(const std::string& fileName = std::string{});

            /// 从档案中删除一个条目。
            void DeleteEntry(const std::string& name);

            /// 获取具有指定名称的条目。
            NODISCARD ZipEntry GetEntry(const std::string& name);

            /// 将具有提供名称的条目提取到目标路径。
            void ExtractEntry(const std::string& name, const std::string& dest);

            ZipEntry AddEntry(const std::string& name, const ZipEntryData& data);
            ZipEntry AddEntry(const std::string& name, const std::string& data);
            ZipEntry AddEntry(const std::string& name, const ZipEntry& entry);

        private:
            void Init();
            void Init(bool isCreate);
            void Create();
            void Open();
            void Close() noexcept;
            void CheckZipReader() const;

            void DeleteSameEntries();
            void AddFolderEntries();
            void MoveZipFile(const std::string& saveFileName, const std::string& randomFileName);

            ZipEntry AddEntryImpl(const std::string& name, const ZipEntryData& data);

            NODISCARD std::string GetRandomFileName(const std::string& saveFileName) const;

        private:
            using ZipEntryType = std::vector<ZipEntry>;
            using ZipReaderSharedPtr = std::shared_ptr<ZipReader>;

        private:
            std::string archivePath;
            ZipReaderSharedPtr zipReader;
            ZipEntryType zipEntries;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_ZIP_ARCHIVE_IMPL_H