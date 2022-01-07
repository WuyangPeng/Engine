///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 22:36)

#include "CoreTools/CoreToolsExport.h"

#include "ZipWriter.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/SimpleZip/ZipEntry.h"

using std::string;

CoreTools::SimpleZip::ZipWriter::ZipWriter(const string& archivePath)
    : archivePath{ archivePath }, archive{}, isClose{ false }
{
    Init();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleZip::ZipWriter::~ZipWriter()
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    Close();
}

void CoreTools::SimpleZip::ZipWriter::Init() noexcept
{
    // ׼��һ���浵�ļ���
    mz_zip_writer_init_file(&archive, archivePath.c_str(), 0);
}

void CoreTools::SimpleZip::ZipWriter::Close() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (!isClose)
    {
        // ��ɲ��ر���ʱ�浵
        mz_zip_writer_finalize_archive(&archive);
        mz_zip_writer_end(&archive);

        isClose = true;
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleZip, ZipWriter)

void CoreTools::SimpleZip::ZipWriter::ValidateFileArchive()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26812)

    mz_zip_error errordata{};

#include STSTEM_WARNING_POP

    // ��֤��ʱ�ļ�
    if (!mz_zip_validate_file_archive(archivePath.c_str(), 0, &errordata))
    {
        THROW_EXCEPTION(StringConversion::MultiByteConversionStandard(mz_zip_get_error_string(errordata)));
    }
}

void CoreTools::SimpleZip::ZipWriter::AddZipEntry(const ZipEntry& zipEntry, mz_zip_archive* readArchive)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (isClose)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�ļ��ѹرա�\n"s));
    }

    if (zipEntry.IsDirectory())
    {
        return;
    }
    if (!zipEntry.IsModified())
    {
        if (!mz_zip_writer_add_from_zip_reader(&archive, readArchive, zipEntry.GetIndex()))
        {
            THROW_EXCEPTION(StringConversion::MultiByteConversionStandard(mz_zip_get_error_string(archive.m_last_error)));
        }
    }
    else
    {
        if (!zipEntry.WriterAddMem(&archive))
        {
            THROW_EXCEPTION(StringConversion::MultiByteConversionStandard(mz_zip_get_error_string(archive.m_last_error)));
        }
    }
}
