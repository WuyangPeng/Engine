///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/04 15:03)

#include "CoreTools/CoreToolsExport.h"

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

    // �����浵������Ŀ��ӵ��ڲ����ݽṹ��
    const auto filesNum = mz_zip_reader_get_num_files(&archive);
    for (auto index = 0u; index < filesNum; ++index)
    {
        ZipEntryInfo info{};
        if (!mz_zip_reader_file_stat(&archive, index, &info))
        {
            THROW_EXCEPTION(StringConversion::MultiByteConversionStandard(mz_zip_get_error_string(archive.m_last_error)))
        }

        zipEntries.emplace_back(info);
    }

    return zipEntries;
}
