///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.7 (2023/04/26 14:02)

#include "ZipEntryTesting.h"
#include "System/CharacterString/FormatString.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Base/Flags/UniqueIdSelect.h"
#include "CoreTools/Base/UniqueIdManager.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/SimpleZip/ZipArchive.h"
#include "CoreTools/TextParsing/SimpleZip/ZipEntry.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::ZipEntryTesting::ZipEntryTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ZipEntryTesting)

void CoreTools::ZipEntryTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ZipEntryTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ZipEntryInfoTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ZipEntryDataTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StringDataTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WriterAddMemTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ReaderExtractFileToMemTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RemoveFile);
}

void CoreTools::ZipEntryTesting::ZipEntryInfoTest()
{
    const auto fileIndex = boost::numeric_cast<mz_uint32>(UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(UniqueIdSelect::ZipFile));
    const auto zipEntryInfo = GetZipEntryInfo(fileIndex);

    SimpleZip::ZipEntry zipEntry{ zipEntryInfo };

    const auto zipEntryData = zipEntry.GetEntryData();
    ASSERT_TRUE(zipEntryData.empty());

    const auto dataAsString = zipEntry.GetDataAsString();
    ASSERT_TRUE(dataAsString.empty());

    ASSERT_EQUAL(fileIndex, zipEntry.GetIndex());
    ASSERT_EQUAL(100, zipEntry.GetCompressedSize());
    ASSERT_EQUAL(200, zipEntry.GetUncompressedSize());

    ASSERT_FALSE(zipEntry.IsDirectory());
    ASSERT_FALSE(zipEntry.IsEncrypted());
    ASSERT_TRUE(zipEntry.IsSupported());

    ASSERT_FALSE(zipEntry.IsModified());

    ASSERT_EQUAL("ZipEntryInfo.zip", zipEntry.GetFileName());
    ASSERT_EQUAL("comment", zipEntry.GetComment());

    ASSERT_EQUAL(0u, zipEntry.GetEntrySize());
    ASSERT_TRUE(zipEntry.IsEntryDataEmpty());
    ASSERT_LESS_EQUAL(zipEntry.GetTime(), System::GetTimeInSeconds());

    const auto result = zipEntry.GetZipEntryInfo();
    ASSERT_EQUAL(fileIndex, result.m_file_index);
    ASSERT_EQUAL(100, result.m_comp_size);
    ASSERT_EQUAL(200, result.m_uncomp_size);

    zipEntry.SetFileName("EntryInfo.zip");
    ASSERT_EQUAL("EntryInfo.zip", zipEntry.GetFileName());

    zipEntry.ResizeZipEntryData(10);
    ASSERT_EQUAL(10u, zipEntry.GetEntrySize());

    zipEntry.SetData(SimpleZip::ZipEntryData{ '1', '2' });
    ASSERT_EQUAL(2u, zipEntry.GetEntrySize());

    zipEntry.SetData("12345"s);
    ASSERT_EQUAL(5u, zipEntry.GetEntrySize());
}

CoreTools::SimpleZip::ZipEntryInfo CoreTools::ZipEntryTesting::GetZipEntryInfo(mz_uint32 fileIndex)
{
    SimpleZip::ZipEntryInfo zipEntryInfo{};

    zipEntryInfo.m_file_index = fileIndex;
    zipEntryInfo.m_central_dir_ofs = 0;
    zipEntryInfo.m_version_made_by = 0;
    zipEntryInfo.m_version_needed = 0;
    zipEntryInfo.m_bit_flag = 0;
    zipEntryInfo.m_method = 0;
    zipEntryInfo.m_time = System::GetTimeInSeconds();
    zipEntryInfo.m_crc32 = 0;
    zipEntryInfo.m_comp_size = 100;
    zipEntryInfo.m_uncomp_size = 200;
    zipEntryInfo.m_internal_attr = 0;
    zipEntryInfo.m_external_attr = 0;
    zipEntryInfo.m_local_header_ofs = 0;
    zipEntryInfo.m_comment_size = 0;
    zipEntryInfo.m_is_directory = false;
    zipEntryInfo.m_is_encrypted = false;
    zipEntryInfo.m_is_supported = true;

    std::ranges::copy("ZipEntryInfo.zip", std::begin(zipEntryInfo.m_filename));
    std::ranges::copy("comment", std::begin(zipEntryInfo.m_comment));

    return zipEntryInfo;
}

void CoreTools::ZipEntryTesting::ZipEntryDataTest()
{
    const SimpleZip::ZipEntryData originalZipEntryData{ '1', '2' };
    SimpleZip::ZipEntry zipEntry{ "ZipEntryInfo.zip", originalZipEntryData };

    const auto zipEntryData = zipEntry.GetEntryData();
    ASSERT_FALSE(zipEntryData.empty());
    ASSERT_EQUAL(zipEntryData, originalZipEntryData);

    const auto dataAsString = zipEntry.GetDataAsString();
    ASSERT_FALSE(dataAsString.empty());
    ASSERT_EQUAL(dataAsString.size(), 2u);

    ASSERT_LESS_EQUAL(1u, zipEntry.GetIndex());
    ASSERT_EQUAL(0, zipEntry.GetUncompressedSize());
    ASSERT_EQUAL(0, zipEntry.GetUncompressedSize());

    ASSERT_FALSE(zipEntry.IsDirectory());
    ASSERT_FALSE(zipEntry.IsEncrypted());
    ASSERT_TRUE(zipEntry.IsSupported());

    ASSERT_TRUE(zipEntry.IsModified());

    ASSERT_EQUAL("ZipEntryInfo.zip", zipEntry.GetFileName());
    ASSERT_TRUE(zipEntry.GetComment().empty());

    ASSERT_EQUAL(2u, zipEntry.GetEntrySize());
    ASSERT_FALSE(zipEntry.IsEntryDataEmpty());
    ASSERT_LESS_EQUAL(System::GetTimeInSeconds(), zipEntry.GetTime());

    const auto result = zipEntry.GetZipEntryInfo();
    ASSERT_EQUAL(zipEntry.GetIndex(), result.m_file_index);
    ASSERT_EQUAL(0, result.m_comp_size);
    ASSERT_EQUAL(0, result.m_uncomp_size);

    zipEntry.SetFileName("EntryInfo.zip");
    ASSERT_EQUAL("EntryInfo.zip", zipEntry.GetFileName());

    zipEntry.ResizeZipEntryData(10);
    ASSERT_EQUAL(10u, zipEntry.GetEntrySize());

    zipEntry.SetData(SimpleZip::ZipEntryData{ '1', '2', '3' });
    ASSERT_EQUAL(3u, zipEntry.GetEntrySize());

    zipEntry.SetData("12345"s);
    ASSERT_EQUAL(5u, zipEntry.GetEntrySize());
}

void CoreTools::ZipEntryTesting::StringDataTest()
{
    SimpleZip::ZipEntry zipEntry{ "ZipEntryInfo.zip", "12"s };

    const auto zipEntryData = zipEntry.GetEntryData();
    ASSERT_FALSE(zipEntryData.empty());
    ASSERT_EQUAL(zipEntryData.size(), 2u);

    const auto dataAsString = zipEntry.GetDataAsString();
    ASSERT_FALSE(dataAsString.empty());
    ASSERT_EQUAL(dataAsString.size(), 2u);

    ASSERT_LESS_EQUAL(1u, zipEntry.GetIndex());
    ASSERT_EQUAL(0, zipEntry.GetCompressedSize());
    ASSERT_EQUAL(0, zipEntry.GetUncompressedSize());

    ASSERT_FALSE(zipEntry.IsDirectory());
    ASSERT_FALSE(zipEntry.IsEncrypted());
    ASSERT_TRUE(zipEntry.IsSupported());

    ASSERT_TRUE(zipEntry.IsModified());

    ASSERT_EQUAL("ZipEntryInfo.zip", zipEntry.GetFileName());
    ASSERT_TRUE(zipEntry.GetComment().empty());

    ASSERT_EQUAL(2u, zipEntry.GetEntrySize());
    ASSERT_FALSE(zipEntry.IsEntryDataEmpty());
    ASSERT_LESS_EQUAL(System::GetTimeInSeconds(), zipEntry.GetTime());

    const auto result = zipEntry.GetZipEntryInfo();
    ASSERT_EQUAL(zipEntry.GetIndex(), result.m_file_index);
    ASSERT_EQUAL(0, result.m_comp_size);
    ASSERT_EQUAL(0, result.m_uncomp_size);

    zipEntry.SetFileName("EntryInfo.zip");
    ASSERT_EQUAL("EntryInfo.zip", zipEntry.GetFileName());

    zipEntry.ResizeZipEntryData(10);
    ASSERT_EQUAL(10u, zipEntry.GetEntrySize());

    zipEntry.SetData(SimpleZip::ZipEntryData{ '1', '2', '3' });
    ASSERT_EQUAL(3u, zipEntry.GetEntrySize());

    zipEntry.SetData("12345"s);
    ASSERT_EQUAL(5u, zipEntry.GetEntrySize());
}

void CoreTools::ZipEntryTesting::WriterAddMemTest()
{
    const auto zipArchiveFileName = GetZipArchiveFileName();

    mz_zip_archive archive{};
    mz_zip_writer_init_file(&archive, zipArchiveFileName.c_str(), 0);

    const auto data = "123456789"s;
    const auto fileIndex = boost::numeric_cast<mz_uint32>(UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(UniqueIdSelect::ZipFile));
    auto zipEntryInfo = GetZipEntryInfo(fileIndex);
    zipEntryInfo.m_comp_size = data.size();

    SimpleZip::ZipEntry zipEntry{ zipEntryInfo };
    zipEntry.SetFileName("Test.txt");
    zipEntry.SetData(data);

    ASSERT_TRUE(zipEntry.WriterAddMem(&archive));

    mz_zip_writer_finalize_archive(&archive);
    mz_zip_writer_end(&archive);
}

void CoreTools::ZipEntryTesting::ReaderExtractFileToMemTest()
{
    const auto zipArchiveFileName = GetZipArchiveFileName();
    mz_zip_archive archive{};
    if (!mz_zip_reader_init_file(&archive, zipArchiveFileName.c_str(), 0))
    {
        THROW_EXCEPTION(StringConversion::MultiByteConversionStandard(mz_zip_get_error_string(archive.m_last_error)));
    }

    const auto fileIndex = boost::numeric_cast<mz_uint32>(UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(UniqueIdSelect::ZipFile));
    const auto zipEntryInfo = GetZipEntryInfo(fileIndex);

    SimpleZip::ZipEntry zipEntry{ zipEntryInfo };

    const auto data = "123456789"s;
    zipEntry.ResizeZipEntryData(boost::numeric_cast<int>(data.size()));
    zipEntry.ReaderExtractFileToMem(&archive, "Test.txt");

    ASSERT_EQUAL(zipEntry.GetDataAsString(), data);

    mz_zip_reader_end(&archive);
}

std::string CoreTools::ZipEntryTesting::GetZipArchiveFileName()
{
    return "Resource/SimpleZipTesting/ZipEntry.zip";
}

void CoreTools::ZipEntryTesting::RemoveFile()
{
    DeleteFileTools deleteFileTools{ StringConversion::MultiByteConversionStandard(GetZipArchiveFileName()) };
}
