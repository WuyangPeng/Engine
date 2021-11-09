///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/11/08 7:09)

#include "CoreTools/CoreToolsExport.h"

#include "ZipEntryImpl.h"
#include "System/CharacterString/FormatString.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
#include "CoreTools/Base/UniqueIDManagerDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/Flags/CSVConstant.h"

#include <gsl/span>

using std::string;

CoreTools::SimpleZip::ZipEntryImpl::ZipEntryImpl(const ZipEntryInfo& info)
    : entryInfo{ info }, entryData{}, isModified{ false }
{
    //  更新索引计数器。
    UNIQUE_ID_MANAGER_SINGLETON.SetUniqueID(UniqueIDSelect::ZipFile, info.m_file_index);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleZip::ZipEntryImpl::ZipEntryImpl(const string& name, const ZipEntryData& data)
    : entryInfo{ CreateInfo(name) }, entryData{ data }, isModified{ true }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

// private
CoreTools::SimpleZip::ZipEntryInfo CoreTools::SimpleZip::ZipEntryImpl::CreateInfo(const string& fileName)
{
    ZipEntryInfo info{};

    info.m_file_index = boost::numeric_cast<mz_uint32>(UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(UniqueIDSelect::ZipFile));
    info.m_time = System::GetTimeInSeconds();
    info.m_is_directory = (fileName.back() == TextParsing::g_ForwardSlash);
    info.m_is_encrypted = false;
    info.m_is_supported = true;

    if (MZ_ZIP_MAX_ARCHIVE_FILENAME_SIZE <= fileName.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("复制文件名失败。"s));
    }

    const gsl::span<char, MZ_ZIP_MAX_ARCHIVE_FILENAME_SIZE> span{ info.m_filename };

    std::copy(fileName.cbegin(), fileName.cend(), span.begin());

    return info;
}

CoreTools::SimpleZip::ZipEntryImpl::ZipEntryImpl(const string& name, const string& data)
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

string CoreTools::SimpleZip::ZipEntryImpl::GetDataAsString() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return string{ entryData.begin(), entryData.end() };
}

void CoreTools::SimpleZip::ZipEntryImpl::SetData(const string& data)
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

string CoreTools::SimpleZip::ZipEntryImpl::GetFileName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26485)

    return string{ entryInfo.m_filename };

#include STSTEM_WARNING_POP
}

void CoreTools::SimpleZip::ZipEntryImpl::SetFileName(const string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (MZ_ZIP_MAX_ARCHIVE_FILENAME_SIZE <= name.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("复制文件名失败。"s));
    }

    const gsl::span<char, MZ_ZIP_MAX_ARCHIVE_FILENAME_SIZE> span{ entryInfo.m_filename };

    std::fill(std::begin(entryInfo.m_filename), std::end(entryInfo.m_filename), '\0');
    std::copy(name.cbegin(), name.cend(), span.begin());
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

string CoreTools::SimpleZip::ZipEntryImpl::GetComment() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26485)

    return string{ entryInfo.m_comment };

#include STSTEM_WARNING_POP
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

void CoreTools::SimpleZip::ZipEntryImpl::ReaderExtractFileToMem(mz_zip_archive* archive, const string& name) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    mz_zip_reader_extract_file_to_mem(archive, name.c_str(), entryData.data(), entryData.size(), 0);
}

bool CoreTools::SimpleZip::ZipEntryImpl::WriterAddMem(mz_zip_archive* archive) const
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return mz_zip_writer_add_mem(archive,
                                 GetFileName().c_str(),
                                 entryData.data(),
                                 entryData.size(),
                                 static_cast<mz_uint32>(MZ_DEFAULT_COMPRESSION)) != 0;
}
