/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/08 11:44)

#include "CoreTools/CoreToolsExport.h"

#include "ZipArchiveImpl.h"
#include "ZipEntryImpl.h"
#include "ZipHelper.h"
#include "ZipWriter.h"
#include "System/FileManager/File.h"
#include "System/FileManager/FileTools.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/FileManager/GenerateRandomName.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/SimpleZip/ZipEntry.h"

#include <fstream>

using namespace std::literals;

CoreTools::SimpleZip::ZipArchiveImpl::ZipArchiveImpl() noexcept
    : archivePath{}, zipReader{}, zipEntries{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleZip::ZipArchiveImpl::ZipArchiveImpl(std::string fileName, bool isCreate)
    : archivePath{ std::move(fileName) }, zipReader{}, zipEntries{}
{
    Init(isCreate);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

void CoreTools::SimpleZip::ZipArchiveImpl::Init(bool isCreate)
{
    if (isCreate)
    {
        Create();
    }
    else
    {
        Open();
    }
}

CoreTools::SimpleZip::ZipArchiveImpl::ZipArchiveImpl(std::string fileName)
    : archivePath{ std::move(fileName) }, zipReader{}, zipEntries{}
{
    Init();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

void CoreTools::SimpleZip::ZipArchiveImpl::Init()
{
    const auto isCreate = !FileManagerHelper::IsFileExists(archivePath);

    Init(isCreate);
}

CoreTools::SimpleZip::ZipArchiveImpl::~ZipArchiveImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    Close();
}

CoreTools::SimpleZip::ZipArchiveImpl::ZipArchiveImpl(ZipArchiveImpl&& rhs) noexcept
    : archivePath{ std::move(rhs.archivePath) },
      zipReader{ std::move(rhs.zipReader) },
      zipEntries{ std::move(rhs.zipEntries) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleZip::ZipArchiveImpl& CoreTools::SimpleZip::ZipArchiveImpl::operator=(ZipArchiveImpl&& rhs) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (this != &rhs)
    {
        archivePath = std::move(rhs.archivePath);
        zipReader = std::move(rhs.zipReader);
        zipEntries = std::move(rhs.zipEntries);
    }

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleZip, ZipArchiveImpl)

void CoreTools::SimpleZip::ZipArchiveImpl::Create()
{
    CreateZipWriter();

    /// ���һ�����������´����Ĵ浵��
    Open();
}

void CoreTools::SimpleZip::ZipArchiveImpl::CreateZipWriter() const
{
    ZipWriter zipWriter{ archivePath };

    zipWriter.Close();
    zipWriter.ValidateFileArchive();
}

void CoreTools::SimpleZip::ZipArchiveImpl::Open()
{
    zipReader = make_shared<ZipReader>(archivePath);

    zipEntries = zipReader->GetEntry();

    DeleteSameEntries();
    AddFolderEntries();
}

void CoreTools::SimpleZip::ZipArchiveImpl::DeleteSameEntries()
{
    /// ɾ��������ͬ���Ƶ���Ŀ�� ������������Ŀ��
    constexpr auto isEqual = [](const auto& lhs, const auto& rhs) {
        return lhs.GetFileName() == rhs.GetFileName();
    };

    std::ranges::reverse(zipEntries);
    const auto result = std::ranges::unique(zipEntries.begin(), zipEntries.end(), isEqual);
    zipEntries.erase(result.begin(), result.end());
    std::ranges::reverse(zipEntries);
}

void CoreTools::SimpleZip::ZipArchiveImpl::AddFolderEntries()
{
    /// ����ļ�����Ŀ�����ڣ���������ǡ�
    for (const auto& entry : GetEntryNames(false, true))
    {
        AddFolderEntries(entry);
    }
}

void CoreTools::SimpleZip::ZipArchiveImpl::AddFolderEntries(const std::string& entry)
{
    if (const auto position = entry.rfind(forwardSlash);
        position != std::string::npos)
    {
        AddEntry(entry.substr(0, position + 1), "");
    }
}

void CoreTools::SimpleZip::ZipArchiveImpl::Close() noexcept
{
    zipReader.reset();
    zipEntries.clear();
    archivePath.clear();
}

CoreTools::SimpleZip::ZipArchiveImpl::EntryNamesType CoreTools::SimpleZip::ZipArchiveImpl::GetEntryNames(bool includeDirs, bool includeFiles) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    CheckZipReader();

    EntryNamesType result{};

    /// �����浵�е�������Ŀ
    for (const auto& item : zipEntries)
    {
        if (IsMeetConditionZipEntry(includeDirs, includeFiles, item))
        {
            result.emplace_back(item.GetFileName());
        }
    }

    return result;
}

bool CoreTools::SimpleZip::ZipArchiveImpl::IsMeetConditionZipEntry(bool includeDirs, bool includeFiles, const ZipEntry& item) noexcept
{
    return (includeDirs && item.IsDirectory()) || (includeFiles && !item.IsDirectory());
}

void CoreTools::SimpleZip::ZipArchiveImpl::CheckZipReader() const
{
    if (!zipReader)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�ļ�δ������"s))
    }
}

CoreTools::SimpleZip::ZipArchiveImpl::EntryNamesType CoreTools::SimpleZip::ZipArchiveImpl::GetEntryNamesInDir(const std::string& dir, bool includeDirs, bool includeFiles) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    CheckZipReader();

    /// ��ȡ��������Ŀ�б�
    auto result = GetEntryNames(includeDirs, includeFiles);

    /// ɾ���������Ŀ¼�е�������Ŀ���Լ���Ŀ¼����
    RemoveConditionDir(dir, result);

    /// ȷ��ֻ����һ����Ŀ¼��
    RemoveRootDepth(dir, result);

    return result;
}

void CoreTools::SimpleZip::ZipArchiveImpl::RemoveConditionDir(const std::string& dir, EntryNamesType& result)
{
    if (!dir.empty())
    {
        const auto conditionDir = GetForwardSlashBack(dir);

        const auto removeEntryNames = [&](const auto& fileName) {
            return fileName == conditionDir || !fileName.starts_with(conditionDir);
        };

        const auto ranges = std::ranges::remove_if(result, removeEntryNames);

        result.erase(ranges.begin(), ranges.end());
    }
}

void CoreTools::SimpleZip::ZipArchiveImpl::RemoveRootDepth(const std::string& dir, EntryNamesType& result)
{
    const auto count = std::ranges::count(dir, forwardSlash);
    const auto rootDepth = (dir.empty() ? 1 : (dir.back() == forwardSlash ? count + 1 : count + 2));

    const auto removeEntryNames = [&](const auto& fileName) {
        const auto subFolderDepth = std::ranges::count(fileName, forwardSlash);

        return (rootDepth < subFolderDepth) || (subFolderDepth == rootDepth && fileName.back() != forwardSlash);
    };

    const auto ranges = std::ranges::remove_if(result, removeEntryNames);

    result.erase(ranges.begin(), ranges.end());
}

CoreTools::SimpleZip::ZipArchiveImpl::ZipEntryMetaDataType CoreTools::SimpleZip::ZipArchiveImpl::GetMetaData(bool includeDirs, bool includeFiles) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    CheckZipReader();

    ZipEntryMetaDataType result{};
    for (const auto& item : zipEntries)
    {
        if (IsMeetConditionZipEntry(includeDirs, includeFiles, item))
        {
            result.emplace_back(item.GetZipEntryInfo());
        }
    }

    return result;
}

CoreTools::SimpleZip::ZipArchiveImpl::ZipEntryMetaDataType CoreTools::SimpleZip::ZipArchiveImpl::GetMetaDataInDir(const std::string& dir, bool includeDirs, bool includeFiles) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    CheckZipReader();

    ZipEntryMetaDataType result{};
    for (const auto& item : zipEntries)
    {
        if (item.GetFileName().starts_with(dir) &&
            IsMeetConditionZipEntry(includeDirs, includeFiles, item))
        {
            result.emplace_back(item.GetZipEntryInfo());
        }
    }

    return result;
}

int CoreTools::SimpleZip::ZipArchiveImpl::GetNumEntries(bool includeDirs, bool includeFiles) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    CheckZipReader();

    return boost::numeric_cast<int>(GetEntryNames(includeDirs, includeFiles).size());
}

int CoreTools::SimpleZip::ZipArchiveImpl::GetNumEntriesInDir(const std::string& dir, bool includeDirs, bool includeFiles) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    CheckZipReader();

    return boost::numeric_cast<int>(GetEntryNamesInDir(dir, includeDirs, includeFiles).size());
}

bool CoreTools::SimpleZip::ZipArchiveImpl::HasEntry(const std::string& entryName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    CheckZipReader();

    const auto result = GetEntryNames(true, true);
    return std::ranges::find(result, entryName) != result.cend();
}

void CoreTools::SimpleZip::ZipArchiveImpl::Save(const std::string& fileName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    CheckZipReader();

    const auto saveFileName = GetSaveFileName(fileName);

    /// �����뵱ǰ�ļ�·����ͬ������ļ���
    const auto randomFileName = GetRandomFileName(saveFileName);

    SaveZipWriter(randomFileName);

    MoveZipFile(saveFileName, randomFileName);
}

std::string CoreTools::SimpleZip::ZipArchiveImpl::GetSaveFileName(const std::string& fileName) const
{
    if (fileName.empty())
    {
        return archivePath;
    }

    return fileName;
}

void CoreTools::SimpleZip::ZipArchiveImpl::SaveZipWriter(const std::string& randomFileName) const
{
    /// ׼��һ������ļ�������ʱ�浵�ļ�
    ZipWriter zipWriter{ randomFileName };

    /// ����ZipEntries������Ŀ��ӵ���ʱ�ļ�
    for (const auto& file : zipEntries)
    {
        zipWriter.AddZipEntry(file, zipReader->GetArchive());
    }

    zipWriter.Close();
    zipWriter.ValidateFileArchive();
}

std::string CoreTools::SimpleZip::ZipArchiveImpl::GetRandomFileName(const std::string& saveFileName)
{
    const auto position = saveFileName.rfind(forwardSlash);

    constexpr auto randomNameLength = 20;
    const auto suffix = "tmp"s;

    if (position != std::string::npos)
    {
        return saveFileName.substr(0, position + 1) + GenerateRandomName::GetName(randomNameLength, suffix);
    }
    else
    {
        return saveFileName + GenerateRandomName::GetName(randomNameLength, suffix);
    }
}

void CoreTools::SimpleZip::ZipArchiveImpl::MoveZipFile(const std::string& saveFileName, const std::string& randomFileName)
{
    const auto oldFileName = archivePath;
    Close();

    DoMoveZipFile(saveFileName, randomFileName);

    archivePath = oldFileName;
    Open();
}

void CoreTools::SimpleZip::ZipArchiveImpl::DoMoveZipFile(const std::string& saveFileName, const std::string& randomFileName)
{
    EXCEPTION_TRY
    {
        MAYBE_UNUSED const auto removeResult = System::RemoveSystemFile(StringConversion::MultiByteConversionStandard(saveFileName));

        if (!System::MoveSystemFile(StringConversion::MultiByteConversionStandard(randomFileName), StringConversion::MultiByteConversionStandard(saveFileName)))
        {
            THROW_EXCEPTION(SYSTEM_TEXT("�ƶ��ļ�ʧ�ܡ�"s))
        }
    }
    EXCEPTION_ALL_CATCH(CoreTools)
}

void CoreTools::SimpleZip::ZipArchiveImpl::DeleteEntry(const std::string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    CheckZipReader();

    const auto ranges = std::ranges::remove_if(zipEntries,
                                               [&](const auto& entry) {
                                                   return name == entry.GetFileName();
                                               });

    zipEntries.erase(ranges.begin(), ranges.end());
}

CoreTools::SimpleZip::ZipEntry CoreTools::SimpleZip::ZipArchiveImpl::GetEntry(const std::string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    CheckZipReader();

    /// ���� ZipEntry ����
    const auto result = std::ranges::find_if(zipEntries, [&](const auto& entry) {
        return name == entry.GetFileName();
    });

    if (result == zipEntries.cend())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("����ָ�����Ƶ���Ŀ��"s))
    }

    ReaderExtractFileToMem(name, *result);

    /// ���ش����ļ����ݵ� ZipEntry ����
    return ZipEntry{ *result };
}

void CoreTools::SimpleZip::ZipArchiveImpl::ReaderExtractFileToMem(const std::string& name, ZipEntry& result) const
{
    auto* archive = zipReader->GetArchive();

    /// �����δ�Ӵ浵����ȡ���ݣ���m_EntryDataΪ�գ��������ݴӴ浵����ȡ��ZipEntry����
    if (result.IsEntryDataEmpty())
    {
        result.ResizeZipEntryData(boost::numeric_cast<int>(result.GetUncompressedSize()));
        result.ReaderExtractFileToMem(archive, name);
    }

    /// �������Ƿ�ɹ�
    if (!result.IsDirectory() &&
        result.IsEntryDataEmpty())
    {
        THROW_EXCEPTION(GetArchiveLastError(archive->m_last_error))
    }
}

void CoreTools::SimpleZip::ZipArchiveImpl::ExtractEntry(const std::string& name, const std::string& dest)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    CheckZipReader();

    if (const auto entry = GetEntry(name);
        entry.IsDirectory())
    {
        /// �����Ŀ��Ŀ¼���򽫸�Ŀ¼����Ϊdest����Ŀ¼
        System::CreateFileDirectory(StringConversion::MultiByteConversionStandard(dest + entry.GetFileName()));
    }
    else
    {
        /// �����Ŀ���ļ�������Ŀ������ʽ���䵽�ļ���
        ExtractEntry(dest, entry);
    }
}

void CoreTools::SimpleZip::ZipArchiveImpl::ExtractEntry(const std::string& dest, const ZipEntry& entry)
{
    std::ofstream output{ dest + std::string{ forwardSlash } + entry.GetFileName(), std::ios::binary };

    for (const auto ch : entry.GetEntryData())
    {
        output << boost::numeric_cast<uint8_t>(ch);
    }
    output.close();
}

CoreTools::SimpleZip::ZipEntry CoreTools::SimpleZip::ZipArchiveImpl::AddEntry(const std::string& name, const ZipEntryData& data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    CheckZipReader();

    return AddEntryImpl(name, data);
}

CoreTools::SimpleZip::ZipEntry CoreTools::SimpleZip::ZipArchiveImpl::AddEntry(const std::string& name, const std::string& data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    CheckZipReader();

    const ZipEntryData stringData{ data.cbegin(), data.cend() };
    return AddEntryImpl(name, stringData);
}

CoreTools::SimpleZip::ZipEntry CoreTools::SimpleZip::ZipArchiveImpl::AddEntry(const std::string& name, const ZipEntry& entry)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    CheckZipReader();

    return AddEntryImpl(name, entry.GetEntryData());
}

void CoreTools::SimpleZip::ZipArchiveImpl::Register(const std::string& name)
{
    /// ȷ�������ļ��к����ļ����ڴ浵�ж���һ����Ŀ
    auto folders = GetEntryNames(true, false);

    for (auto pos = name.find(forwardSlash, 0);
         pos != std::string::npos;
         pos = name.find(forwardSlash, pos))
    {
        ++pos;

        /// ����ļ���δ�ڴ浵��ע�ᣬ���������
        if (auto folder = name.substr(0, pos);
            std::ranges::find(folders, folder) == folders.cend())
        {
            zipEntries.emplace_back(folder, "");
            folders.emplace_back(folder);
        }
    }
}

CoreTools::SimpleZip::ZipEntry CoreTools::SimpleZip::ZipArchiveImpl::AddEntryImpl(const std::string& name, const ZipEntryData& data)
{
    CheckZipReader();

    Register(name);

    return DoAddEntryImpl(name, data);
}

CoreTools::SimpleZip::ZipEntry CoreTools::SimpleZip::ZipArchiveImpl::DoAddEntryImpl(const std::string& name, const ZipEntryData& data)
{
    /// ���浵���Ƿ��Ѵ��ھ��и������Ƶ���Ŀ��
    const auto result = std::ranges::find_if(zipEntries, [&](const auto& entry) {
        return name == entry.GetFileName();
    });

    /// �����Ŀ���ڣ������������滻�������ݣ������� ZipEntry ����
    if (result != zipEntries.cend())
    {
        result->SetData(data);
        return ZipEntry{ *result };
    }

    /// �����Ӿ��и������ƺ����ݵ�����Ŀ�������ض���
    return ZipEntry{ zipEntries.emplace_back(name, data) };
}