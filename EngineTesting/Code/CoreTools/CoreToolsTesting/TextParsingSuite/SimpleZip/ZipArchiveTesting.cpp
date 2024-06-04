/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 09:41)

#include "ZipArchiveTesting.h"
#include "System/CharacterString/FormatString.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
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

CoreTools::ZipArchiveTesting::ZipArchiveTesting(const OStreamShared& stream)
    : ParentType{ stream }, entryName{ "Test.txt" }, data{ "12345678" }
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
    ASSERT_THROW_EXCEPTION_0(DefaultTest);
}

void CoreTools::ZipArchiveTesting::CreateZipArchiveTest()
{
    SimpleZip::ZipArchive zipArchive{ GetZipArchiveFileName(), true };

    ASSERT_FALSE(zipArchive.HasEntry(entryName));

    ASSERT_NOT_THROW_EXCEPTION_1(CreateZipArchiveAddEntryTest, zipArchive);
    ASSERT_NOT_THROW_EXCEPTION_1(CreateZipArchiveDeleteEntryTest, zipArchive);
}

void CoreTools::ZipArchiveTesting::CreateZipArchiveAddEntryTest(ZipArchive& zipArchive)
{
    zipArchive.AddEntry(entryName, data);

    ASSERT_TRUE(zipArchive.HasEntry(entryName));
    ASSERT_EQUAL(zipArchive.GetEntry(entryName), data);

    zipArchive.Save();
}

void CoreTools::ZipArchiveTesting::CreateZipArchiveDeleteEntryTest(ZipArchive& zipArchive)
{
    zipArchive.DeleteEntry(entryName);

    ASSERT_FALSE(zipArchive.HasEntry(entryName));
}

void CoreTools::ZipArchiveTesting::ReadZipArchiveTest()
{
    SimpleZip::ZipArchive zipArchive{ GetZipArchiveFileName() };

    ASSERT_TRUE(zipArchive.HasEntry(entryName));
    ASSERT_EQUAL(zipArchive.GetEntry(entryName), data);
}

std::string CoreTools::ZipArchiveTesting::GetZipArchiveFileName()
{
    return "Resource/SimpleZipTesting/ZipArchive.zip";
}

void CoreTools::ZipArchiveTesting::RemoveFile()
{
    DeleteFileTools deleteFileTools{ StringConversion::MultiByteConversionStandard(GetZipArchiveFileName()) };
}

void CoreTools::ZipArchiveTesting::DefaultTest()
{
    auto zipArchive = SimpleZip::ZipArchive::Create();

    zipArchive.AddEntry(entryName, data);
}
