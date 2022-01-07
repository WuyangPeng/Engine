///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 22:36)

#include "CoreTools/CoreToolsExport.h"

#include "ZipReader.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::string;

CoreTools::SimpleZip::ZipReader::ZipReader(const string& archivePath)
    : archivePath{ archivePath }, archive{}
{
    Init();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleZip::ZipReader::~ZipReader()
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    Close();
}

void CoreTools::SimpleZip::ZipReader::Init()
{
    if (!mz_zip_reader_init_file(&archive, archivePath.c_str(), 0))
    {
        THROW_EXCEPTION(StringConversion::MultiByteConversionStandard(mz_zip_get_error_string(archive.m_last_error)));
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

CoreTools::SimpleZip::ZipReader::ZipEntryType CoreTools::SimpleZip::ZipReader::GetEntry()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ZipEntryType zipEntries{};

    // 遍历存档并将条目添加到内部数据结构中
    const auto filesNum = mz_zip_reader_get_num_files(&archive);
    for (auto index = 0u; index < filesNum; ++index)
    {
        ZipEntryInfo info{};
        if (!mz_zip_reader_file_stat(&archive, index, &info))
        {
            THROW_EXCEPTION(StringConversion::MultiByteConversionStandard(mz_zip_get_error_string(archive.m_last_error)));
        }

        zipEntries.emplace_back(info);
    }

    return zipEntries;
}
