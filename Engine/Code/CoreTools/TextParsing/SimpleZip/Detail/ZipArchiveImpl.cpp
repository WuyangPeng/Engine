///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 22:37)

#include "CoreTools/CoreToolsExport.h"

#include "ZipArchiveImpl.h"
#include "ZipEntryImpl.h"
#include "ZipWriter.h"
#include "System/FileManager/File.h"
#include "System/FileManager/FileTools.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/FileManager/GenerateRandomName.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/SimpleZip/ZipEntry.h"

#include <fstream>

using std::ifstream;
using std::make_shared;
using std::ofstream;
using std::string;
using namespace std::literals;

CoreTools::SimpleZip::ZipArchiveImpl::ZipArchiveImpl() noexcept
    : archivePath{}, zipReader{}, zipEntries{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleZip::ZipArchiveImpl::ZipArchiveImpl(const string& fileName, bool isCreate)
    : archivePath{ fileName }, zipReader{}, zipEntries{}
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

CoreTools::SimpleZip::ZipArchiveImpl::ZipArchiveImpl(const string& fileName)
    : archivePath{ fileName }, zipReader{}, zipEntries{}
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
    : archivePath{ std::move(rhs.archivePath) }, zipReader{ std::move(rhs.zipReader) }, zipEntries{ std::move(rhs.zipEntries) }
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
    ZipWriter zipWriter{ archivePath };

    zipWriter.Close();
    zipWriter.ValidateFileArchive();

    // 如果一切正常，打开新创建的存档。
    Open();
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
    // 删除具有相同名称的条目。 将保留最新条目。
    const auto isEqual = [](const auto& lhs, const auto& rhs) {
        return lhs.GetFileName() == rhs.GetFileName();
    };

    std::reverse(zipEntries.begin(), zipEntries.end());
    zipEntries.erase(std::unique(zipEntries.begin(), zipEntries.end(), isEqual), zipEntries.end());
    std::reverse(zipEntries.begin(), zipEntries.end());
}

void CoreTools::SimpleZip::ZipArchiveImpl::AddFolderEntries()
{
    // 如果文件夹条目不存在，则添加它们
    for (const auto& entry : GetEntryNames(false, true))
    {
        const auto position = entry.rfind(TextParsing::g_ForwardSlash);
        if (position != std::string::npos)
        {
            AddEntry(entry.substr(0, position + 1), "");
        }
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

    // 遍历存档中的所有条目
    for (const auto& item : zipEntries)
    {
        if (includeDirs && item.IsDirectory())
        {
            result.emplace_back(item.GetFileName());
        }
        else if (includeFiles && !item.IsDirectory())
        {
            result.emplace_back(item.GetFileName());
        }
    }

    return result;
}

void CoreTools::SimpleZip::ZipArchiveImpl::CheckZipReader() const
{
    if (!zipReader)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("文件未开启！"s));
    }
}

CoreTools::SimpleZip::ZipArchiveImpl::EntryNamesType CoreTools::SimpleZip::ZipArchiveImpl::GetEntryNamesInDir(const string& dir, bool includeDirs, bool includeFiles) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    CheckZipReader();

    // 获取完整的条目列表
    auto result = GetEntryNames(includeDirs, includeFiles);

    // 删除不在相关目录中的所有条目，以及根目录本身。
    if (!dir.empty())
    {
        auto conditionDir = dir;
        if (conditionDir.back() != TextParsing::g_ForwardSlash)
        {
            conditionDir += TextParsing::g_ForwardSlash;
        }

        result.erase(std::remove_if(result.begin(),
                                    result.end(),
                                    [&](const auto& fileName) {
                                        return fileName == conditionDir || fileName.substr(0, conditionDir.size()) != conditionDir;
                                    }),
                     result.end());
    }

    const auto count = std::count(dir.cbegin(), dir.cend(), TextParsing::g_ForwardSlash);
    const auto rootDepth = (dir.empty() ? 1 : (dir.back() == TextParsing::g_ForwardSlash ? count + 1 : count + 2));

    // 确保只包含一级子目录。
    result.erase(std::remove_if(result.begin(),
                                result.end(),
                                [&](const auto& fileName) {
                                    const auto subFolderDepth = std::count(fileName.cbegin(), fileName.cend(), TextParsing::g_ForwardSlash);

                                    return (rootDepth < subFolderDepth) || (subFolderDepth == rootDepth && fileName.back() != TextParsing::g_ForwardSlash);
                                }),
                 result.end());

    return result;
}

CoreTools::SimpleZip::ZipArchiveImpl::ZipEntryMetaDataType CoreTools::SimpleZip::ZipArchiveImpl::GetMetaData(bool includeDirs, bool includeFiles) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    CheckZipReader();

    ZipEntryMetaDataType result{};
    for (const auto& item : zipEntries)
    {
        if (includeDirs && item.IsDirectory())
        {
            result.emplace_back(item.GetZipEntryInfo());
        }
        else if (includeFiles && !item.IsDirectory())
        {
            result.emplace_back(item.GetZipEntryInfo());
        }
    }

    return result;
}

CoreTools::SimpleZip::ZipArchiveImpl::ZipEntryMetaDataType CoreTools::SimpleZip::ZipArchiveImpl::GetMetaDataInDir(const string& dir, bool includeDirs, bool includeFiles) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    CheckZipReader();

    ZipEntryMetaDataType result{};
    for (const auto& item : zipEntries)
    {
        if (item.GetFileName().substr(0, dir.size()) != dir)
        {
            continue;
        }

        if (includeDirs && item.IsDirectory())
        {
            result.emplace_back(item.GetZipEntryInfo());
        }
        else if (includeFiles && !item.IsDirectory())
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

int CoreTools::SimpleZip::ZipArchiveImpl::GetNumEntriesInDir(const string& dir, bool includeDirs, bool includeFiles) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    CheckZipReader();

    return boost::numeric_cast<int>(GetEntryNamesInDir(dir, includeDirs, includeFiles).size());
}

bool CoreTools::SimpleZip::ZipArchiveImpl::HasEntry(const string& entryName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    CheckZipReader();

    auto result = GetEntryNames(true, true);
    return std::find(result.cbegin(), result.cend(), entryName) != result.cend();
}

void CoreTools::SimpleZip::ZipArchiveImpl::Save(const string& fileName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    CheckZipReader();

    auto saveFileName = fileName;
    if (saveFileName.empty())
    {
        saveFileName = archivePath;
    }

    // 生成与当前文件路径相同的随机文件名
    auto randomFileName = GetRandomFileName(saveFileName);

    // 准备一个随机文件名的临时存档文件；
    ZipWriter zipWriter{ randomFileName };

    // 遍历ZipEntries并将条目添加到临时文件
    for (const auto& file : zipEntries)
    {
        zipWriter.AddZipEntry(file, zipReader->GetArchive());
    }

    zipWriter.Close();
    zipWriter.ValidateFileArchive();

    MoveZipFile(saveFileName, randomFileName);
}

string CoreTools::SimpleZip::ZipArchiveImpl::GetRandomFileName(const string& saveFileName) const
{
    const auto position = saveFileName.rfind(TextParsing::g_ForwardSlash);

    constexpr auto randomNameLength = 20;
    const auto suffix = "tmp"s;

    if (position != string::npos)
    {
        return saveFileName.substr(0, position + 1) + GenerateRandomName::GetName(randomNameLength, suffix);
    }
    else
    {
        return saveFileName + GenerateRandomName::GetName(randomNameLength, suffix);
    }
}

void CoreTools::SimpleZip::ZipArchiveImpl::MoveZipFile(const string& saveFileName, const string& randomFileName)
{
    auto oldFileName = archivePath;
    Close();

    EXCEPTION_TRY
    {
        MAYBE_UNUSED const auto removeResult = System::RemoveSystemFile(StringConversion::MultiByteConversionStandard(saveFileName));

        if (!System::MoveSystemFile(StringConversion::MultiByteConversionStandard(randomFileName), StringConversion::MultiByteConversionStandard(saveFileName)))
        {
            THROW_EXCEPTION(SYSTEM_TEXT("移动文件失败。"s));
        }
    }
    EXCEPTION_ALL_CATCH(CoreTools);

    archivePath = oldFileName;
    Open();
}

void CoreTools::SimpleZip::ZipArchiveImpl::DeleteEntry(const string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    CheckZipReader();

    zipEntries.erase(std::remove_if(zipEntries.begin(),
                                    zipEntries.end(),
                                    [&](const auto& entry) {
                                        return name == entry.GetFileName();
                                    }),
                     zipEntries.end());
}

CoreTools::SimpleZip::ZipEntry CoreTools::SimpleZip::ZipArchiveImpl::GetEntry(const string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    CheckZipReader();

    // 查找 ZipEntry 对象。
    auto result = std::find_if(zipEntries.begin(), zipEntries.end(), [&](const auto& entry) {
        return name == entry.GetFileName();
    });

    if (result == zipEntries.cend())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("具有指定名称的条目！"s));
    }

    // 如果尚未从存档中提取数据（即m_EntryData为空），则将数据从存档中提取到ZipEntry对象。
    if (result->IsEntryDataEmpty())
    {
        result->ResizeZipEntryData(boost::numeric_cast<int>(result->GetUncompressedSize()));
        result->ReaderExtractFileToMem(zipReader->GetArchive(), name);
    }

    // 检查操作是否成功
    if (!result->IsDirectory() && result->IsEntryDataEmpty())
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26812)

        THROW_EXCEPTION(StringConversion::MultiByteConversionStandard(mz_zip_get_error_string(zipReader->GetArchive()->m_last_error)));

#include STSTEM_WARNING_POP
    }

    // 返回带有文件数据的 ZipEntry 对象。
    return ZipEntry{ *result };
}

void CoreTools::SimpleZip::ZipArchiveImpl::ExtractEntry(const std::string& name, const std::string& dest)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    CheckZipReader();

    auto entry = GetEntry(name);

    /// 如果条目是目录，则将该目录创建为dest的子目录
    if (entry.IsDirectory())
    {
        MAYBE_UNUSED const auto result = System::CreateFileDirectory(StringConversion::MultiByteConversionStandard(dest + entry.GetFileName()), nullptr);
    }
    // 如果条目是文件，则将条目数据流式传输到文件。
    else
    {
        ofstream output{ dest + string{ TextParsing::g_ForwardSlash } + entry.GetFileName(), std::ios::binary };

        for (auto ch : entry.GetEntryData())
        {
            output << boost::numeric_cast<uint8_t>(ch);
        }
        output.close();
    }
}

CoreTools::SimpleZip ::ZipEntry CoreTools::SimpleZip::ZipArchiveImpl::AddEntry(const string& name, const ZipEntryData& data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    CheckZipReader();

    return AddEntryImpl(name, data);
}

CoreTools::SimpleZip::ZipEntry CoreTools::SimpleZip::ZipArchiveImpl::AddEntry(const string& name, const string& data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    CheckZipReader();

    ZipEntryData stringData{ data.cbegin(), data.cend() };
    return AddEntryImpl(name, stringData);
}

CoreTools::SimpleZip::ZipEntry CoreTools::SimpleZip::ZipArchiveImpl::AddEntry(const string& name, const ZipEntry& entry)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    CheckZipReader();

    return AddEntryImpl(name, entry.GetEntryData());
}

CoreTools::SimpleZip::ZipEntry CoreTools::SimpleZip::ZipArchiveImpl::AddEntryImpl(const string& name, const ZipEntryData& data)
{
    CheckZipReader();

    // 确保所有文件夹和子文件夹在存档中都有一个条目
    auto folders = GetEntryNames(true, false);

    for (auto pos = name.find(TextParsing::g_ForwardSlash, 0); pos != string::npos; pos = name.find(TextParsing::g_ForwardSlash, pos))
    {
        ++pos;
        auto folder = name.substr(0, pos);

        // 如果文件夹未在存档中注册，请添加它。
        if (std::find(folders.cbegin(), folders.cend(), folder) == folders.cend())
        {
            zipEntries.emplace_back(folder, "");
            folders.emplace_back(folder);
        }
    }

    // 检查存档中是否已存在具有给定名称的条目。
    auto result = std::find_if(zipEntries.begin(), zipEntries.end(), [&](const auto& entry) {
        return name == entry.GetFileName();
    });

    // 如果条目存在，则用新数据替换现有数据，并返回 ZipEntry 对象。
    if (result != zipEntries.cend())
    {
        result->SetData(data);
        return ZipEntry{ *result };
    }

    // 最后，添加具有给定名称和数据的新条目，并返回对象。
    return ZipEntry{ zipEntries.emplace_back(name, data) };
}
