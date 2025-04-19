/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/07 16:25)

#include "CoreTools/CoreToolsExport.h"

#include "ZipEntryImpl.h"
#include "System/CharacterString/FormatString.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Base/Flags/UniqueIdSelect.h"
#include "CoreTools/Base/UniqueIdManagerDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

#include <gsl/span>

CoreTools::SimpleZip::ZipEntryImpl::ZipEntryImpl(const ZipEntryInfo& info)
    : entryInfo{ info }, entryData{}, isModified{ false }
{
    ///  更新索引计数器。
    UNIQUE_ID_MANAGER_SINGLETON.SetUniqueId(UniqueIdSelect::ZipFile, info.m_file_index);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleZip::ZipEntryImpl::ZipEntryImpl(const std::string& name, ZipEntryData data)
    : entryInfo{ CreateInfo(name) }, entryData{ std::move(data) }, isModified{ true }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleZip::ZipEntryInfo CoreTools::SimpleZip::ZipEntryImpl::CreateInfo(const std::string& fileName)
{
    ZipEntryInfo info{};

    info.m_file_index = boost::numeric_cast<mz_uint32>(UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(UniqueIdSelect::ZipFile));
    info.m_time = System::GetTimeInSeconds();
    info.m_is_directory = (fileName.back() == TextParsing::gForwardSlash);
    info.m_is_encrypted = false;
    info.m_is_supported = true;

    if (MZ_ZIP_MAX_ARCHIVE_FILENAME_SIZE <= fileName.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("复制文件名失败。"s))
    }

    const gsl::span span{ info.m_filename };

    std::ranges::copy(fileName, span.begin());

    return info;
}

CoreTools::SimpleZip::ZipEntryImpl::ZipEntryImpl(const std::string& name, const std::string& data)
    : entryInfo{ CreateInfo(name) }, entryData{ data.begin(), data.end() }, isModified{ true }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleZip, ZipEntryImpl)

CoreTools::SimpleZip::ZipEntryData CoreTools::SimpleZip::ZipEntryImpl::GetEntryData() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return entryData;
}

size_t CoreTools::SimpleZip::ZipEntryImpl::GetEntrySize() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return entryData.size();
}

bool CoreTools::SimpleZip::ZipEntryImpl::IsEntryDataEmpty() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return entryData.empty();
}

std::string CoreTools::SimpleZip::ZipEntryImpl::GetDataAsString() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return std::string{ entryData.begin(), entryData.end() };
}

void CoreTools::SimpleZip::ZipEntryImpl::SetData(const std::string& data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    entryData = ZipEntryData{ data.begin(), data.end() };

    isModified = true;
}

void CoreTools::SimpleZip::ZipEntryImpl::SetData(const ZipEntryData& data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    entryData = data;
    isModified = true;
}

std::string CoreTools::SimpleZip::ZipEntryImpl::GetFileName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26485)

    return std::string{ entryInfo.m_filename };

#include SYSTEM_WARNING_POP
}

void CoreTools::SimpleZip::ZipEntryImpl::SetFileName(const std::string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (MZ_ZIP_MAX_ARCHIVE_FILENAME_SIZE <= name.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("复制文件名失败。"s))
    }

    const gsl::span span{ entryInfo.m_filename };

    std::ranges::fill(entryInfo.m_filename, '\0');
    std::ranges::copy(name, span.begin());
}

uint32_t CoreTools::SimpleZip::ZipEntryImpl::GetIndex() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return entryInfo.m_file_index;
}

uint64_t CoreTools::SimpleZip::ZipEntryImpl::GetCompressedSize() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return entryInfo.m_comp_size;
}

uint64_t CoreTools::SimpleZip::ZipEntryImpl::GetUncompressedSize() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return entryInfo.m_uncomp_size;
}

bool CoreTools::SimpleZip::ZipEntryImpl::IsDirectory() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return entryInfo.m_is_directory;
}

bool CoreTools::SimpleZip::ZipEntryImpl::IsEncrypted() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return entryInfo.m_is_encrypted;
}

bool CoreTools::SimpleZip::ZipEntryImpl::IsSupported() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return entryInfo.m_is_supported;
}

std::string CoreTools::SimpleZip::ZipEntryImpl::GetComment() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26485)

    return std::string{ entryInfo.m_comment };

#include SYSTEM_WARNING_POP
}

time_t CoreTools::SimpleZip::ZipEntryImpl::GetTime() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return entryInfo.m_time;
}

bool CoreTools::SimpleZip::ZipEntryImpl::IsModified() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return isModified;
}

CoreTools::SimpleZip::ZipEntryInfo CoreTools::SimpleZip::ZipEntryImpl::GetZipEntryInfo() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return entryInfo;
}

void CoreTools::SimpleZip::ZipEntryImpl::ResizeZipEntryData(int uncompressedSize)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    entryData.resize(uncompressedSize);
}

void CoreTools::SimpleZip::ZipEntryImpl::ReaderExtractFileToMem(mz_zip_archive* archive, const std::string& name) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    mz_zip_reader_extract_file_to_mem(archive, name.c_str(), entryData.data(), entryData.size(), 0);
}

bool CoreTools::SimpleZip::ZipEntryImpl::WriterAddMem(mz_zip_archive* archive) const
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    /// 这里是将MZ_DEFAULT_COMPRESSION（-1）转换成无符号数。
    return mz_zip_writer_add_mem(archive,
                                 GetFileName().c_str(),
                                 entryData.data(),
                                 entryData.size(),
                                 static_cast<mz_uint32>(MZ_DEFAULT_COMPRESSION)) != 0;
}
