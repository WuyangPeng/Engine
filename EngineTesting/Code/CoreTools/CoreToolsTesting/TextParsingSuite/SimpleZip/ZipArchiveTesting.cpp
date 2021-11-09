///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.3 (2021/09/13 12:51)

#include "ZipArchiveTesting.h"
#include "System/CharacterString/FormatString.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
#include "CoreTools/Base/UniqueIDManager.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/ExcelConversionCSV.h"
#include "CoreTools/TextParsing/SimpleZip/ZipArchive.h"
#include "CoreTools/TextParsing/SimpleZip/ZipEntry.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::string;
using namespace std::literals;

CoreTools::ZipArchiveTesting::ZipArchiveTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ZipArchiveTesting)

void CoreTools::ZipArchiveTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ZipArchiveTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateZipArchiveTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ReadZipArchiveTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RemoveFile);
    ASSERT_THROW_EXCEPTION_0(DefautlTest);
}

void CoreTools::ZipArchiveTesting::CreateZipArchiveTest()
{
    SimpleZip::ZipArchive zipArchive{ GetZipArchiveFileName(), true };
    const auto entryName = "Test.txt"s;
    const auto data = "12345678"s;

    ASSERT_FALSE(zipArchive.HasEntry(entryName));

    zipArchive.AddEntry(entryName, data);

    ASSERT_TRUE(zipArchive.HasEntry(entryName));
    ASSERT_EQUAL(zipArchive.GetEntry(entryName), data);

    zipArchive.Save();

    zipArchive.DeleteEntry(entryName);

    ASSERT_FALSE(zipArchive.HasEntry(entryName));
}

void CoreTools::ZipArchiveTesting::ReadZipArchiveTest()
{
    SimpleZip::ZipArchive zipArchive{ GetZipArchiveFileName() };
    const auto entryName = "Test.txt"s;
    const auto data = "12345678"s;

    ASSERT_TRUE(zipArchive.HasEntry(entryName));
    ASSERT_EQUAL(zipArchive.GetEntry(entryName), data);
}

string CoreTools::ZipArchiveTesting::GetZipArchiveFileName()
{
    return "Resource/SimpleZipTesting/ZipArchive.zip";
}

void CoreTools::ZipArchiveTesting::RemoveFile()
{
    DeleteFileTools deleteFileTools{ StringConversion::MultiByteConversionStandard(GetZipArchiveFileName()) };
}

void CoreTools::ZipArchiveTesting::DefautlTest()
{
    SimpleZip::ZipArchive zipArchive{ DisableNotThrow::Disable };

    const auto entryName = "Test.txt"s;
    const auto data = "12345678"s;

    zipArchive.AddEntry(entryName, data);
}
