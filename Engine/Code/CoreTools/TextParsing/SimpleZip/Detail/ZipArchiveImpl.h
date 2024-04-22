/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/08 11:44)

#ifndef CORE_TOOLS_TEXT_PARSING_ZIP_ARCHIVE_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_ZIP_ARCHIVE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "ZipEntryMetaData.h"
#include "ZipReader.h"
#include "CoreTools/TextParsing/SimpleZip/SimpleZipInternalFwd.h"

#include <memory>

namespace CoreTools::SimpleZip
{
    /// ZipArchiveImpl���������zip�浵�ļ���
    /// ���ɵ�����zip��Ŀ��ɣ��������ļ����ļ��С�
    /// ���Ǵ�����.zip �浵����Ҫ���ʵ㣬�����ڴ����´浵�Լ��򿪺��޸����д浵��
    /// ʹ��ZipArchiveImpl �࣬���Դ����µ�.zip �浵�ļ����Լ��򿪺��޸������ļ���
    /// ��ע�⣬.zip �浵�е�ʵ���ļ�����ͨ��ZipEntry�ӿڶ�����ZipArchiveImpl�ӿڼ�����
    class CORE_TOOLS_HIDDEN_DECLARE ZipArchiveImpl final
    {
    public:
        using ClassType = ZipArchiveImpl;

        using EntryNamesType = std::vector<std::string>;
        using ZipEntryMetaDataType = std::vector<ZipEntryMetaData>;

    public:
        /// ʹ��fileName�����������鵵���� ����ļ��Ѿ����ڣ��������򿪡� ���򣬽�����һ���¶���
        ZipArchiveImpl() noexcept;
        explicit ZipArchiveImpl(std::string fileName);
        ZipArchiveImpl(std::string fileName, bool isCreate);

        ~ZipArchiveImpl() noexcept;
        ZipArchiveImpl(const ZipArchiveImpl& rhs) = delete;
        ZipArchiveImpl& operator=(const ZipArchiveImpl& rhs) = delete;
        ZipArchiveImpl(ZipArchiveImpl&& rhs) noexcept;
        ZipArchiveImpl& operator=(ZipArchiveImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        /// ��ȡ��������Ŀ���б� ��������������б�����Ŀ¼���ļ������ߡ�
        NODISCARD EntryNamesType GetEntryNames(bool includeDirs = true, bool includeFiles = true) const;

        /// ��ȡ�����ض�Ŀ¼�е���Ŀ�б� ��������������б�����Ŀ¼���ļ������ߡ�
        /// �˺�������Ϊ��GetEntryNames()�������в�ͬ�������ļ����е�������Ŀ����Ϊ����·�����أ����ǣ�ֻ�᷵��һ�����ļ��С�
        NODISCARD EntryNamesType GetEntryNamesInDir(const std::string& dir, bool includeDirs = true, bool includeFiles = true) const;

        /// ��ȡ��������Ŀ��Ԫ�����б� ��������������б�����Ŀ¼���ļ������ߡ�
        NODISCARD ZipEntryMetaDataType GetMetaData(bool includeDirs = true, bool includeFiles = true) const;

        /// ��ȡ�����ض�Ŀ¼����Ŀ��Ԫ�����б� ��������������б�����Ŀ¼���ļ������ߡ�
        /// Ŀ¼�����������ڡ�
        NODISCARD ZipEntryMetaDataType GetMetaDataInDir(const std::string& dir, bool includeDirs = true, bool includeFiles = true) const;

        NODISCARD int GetNumEntries(bool includeDirs = true, bool includeFiles = true) const;
        NODISCARD int GetNumEntriesInDir(const std::string& dir, bool includeDirs = true, bool includeFiles = true) const;
        NODISCARD bool HasEntry(const std::string& entryName) const;

        /// ʹ�������Ʊ���浵�� ԭʼ�浵�����ֲ��䡣
        /// ���û���ṩ�ļ������ļ������������Ʊ��棬�����κ��������ݡ�
        void Save(const std::string& fileName = std::string{});

        /// �ӵ�����ɾ��һ����Ŀ��
        void DeleteEntry(const std::string& name);

        /// ��ȡ����ָ�����Ƶ���Ŀ��
        NODISCARD ZipEntry GetEntry(const std::string& name);

        /// �������ṩ���Ƶ���Ŀ��ȡ��Ŀ��·����
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
        void CreateZipWriter() const;

        void DeleteSameEntries();
        void AddFolderEntries();
        void AddFolderEntries(const std::string& entry);
        void MoveZipFile(const std::string& saveFileName, const std::string& randomFileName);
        void SaveZipWriter(const std::string& randomFileName) const;
        void ReaderExtractFileToMem(const std::string& name, ZipEntry& result) const;
        void Register(const std::string& name);

        ZipEntry AddEntryImpl(const std::string& name, const ZipEntryData& data);
        ZipEntry DoAddEntryImpl(const std::string& name, const ZipEntryData& data);

        NODISCARD std::string GetSaveFileName(const std::string& fileName) const;

        NODISCARD static std::string GetRandomFileName(const std::string& saveFileName);
        static void RemoveConditionDir(const std::string& dir, EntryNamesType& result);
        static void RemoveRootDepth(const std::string& dir, EntryNamesType& result);
        static void ExtractEntry(const std::string& dest, const ZipEntry& entry);
        static void DoMoveZipFile(const std::string& saveFileName, const std::string& randomFileName);

    private:
        using ZipEntryType = std::vector<ZipEntry>;
        using ZipReaderSharedPtr = std::shared_ptr<ZipReader>;

    private:
        NODISCARD static bool IsMeetConditionZipEntry(bool includeDirs, bool includeFiles, const ZipEntry& item) noexcept;

    private:
        std::string archivePath;
        ZipReaderSharedPtr zipReader;
        ZipEntryType zipEntries;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_ZIP_ARCHIVE_IMPL_H