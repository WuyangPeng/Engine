/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/07 20:10)

#include "CoreTools/CoreToolsExport.h"

#include "ZipHelper.h"
#include "ZipReader.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::SimpleZip::ZipReader::ZipReader(std::string archivePath)
    : archivePath{ std::move(archivePath) }, archive{}
{
    Init();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleZip::ZipReader::~ZipReader() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    Close();
}

void CoreTools::SimpleZip::ZipReader::Init()
{
    if (!mz_zip_reader_init_file(&archive, archivePath.c_str(), 0))
    {
        THROW_EXCEPTION(GetArchiveLastError(archive.m_last_error))
    }
}

void CoreTools::SimpleZip::ZipReader::Close() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    mz_zip_reader_end(&archive);
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleZip, ZipReader)

mz_zip_archive* CoreTools::SimpleZip::ZipReader::GetArchive() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return &archive;
}

CoreTools::SimpleZip::ZipEntryInfo CoreTools::SimpleZip::ZipReader::GetZipEntryInfo(mz_uint index)
{
    ZipEntryInfo zipEntryInfo{};

    if (!mz_zip_reader_file_stat(&archive, index, &zipEntryInfo))
    {
        THROW_EXCEPTION(GetArchiveLastError(archive.m_last_error))
    }

    return zipEntryInfo;
}

CoreTools::SimpleZip::ZipReader::ZipEntryType CoreTools::SimpleZip::ZipReader::GetEntry()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ZipEntryType zipEntries{};

    /// 遍历存档并将条目添加到内部数据结构中
    const auto filesNum = mz_zip_reader_get_num_files(&archive);
    for (auto index = 0u; index < filesNum; ++index)
    {
        zipEntries.emplace_back(GetZipEntryInfo(index));
    }

    return zipEntries;
}
