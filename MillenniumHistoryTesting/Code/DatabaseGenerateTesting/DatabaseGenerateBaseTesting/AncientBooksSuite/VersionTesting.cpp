/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:13)

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Version.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/VersionContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "VersionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateBaseTesting::VersionTesting::VersionTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream },
      ancientBooksContainer{ ancientBooksContainer },
      versionContainer{ ancientBooksContainer.GetVersionContainer() }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, VersionTesting)

void DatabaseGenerateBaseTesting::VersionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateBaseTesting::VersionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MappingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateBaseTesting::VersionTesting::MappingTest()
{
    for (const auto& version : versionContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(BookMappingTest, *version);
        ASSERT_NOT_THROW_EXCEPTION_1(CountryMappingTest, *version);
        ASSERT_NOT_THROW_EXCEPTION_1(ReignTitleMappingTest, *version);
        ASSERT_NOT_THROW_EXCEPTION_1(YearMappingTest, *version);
        ASSERT_NOT_THROW_EXCEPTION_1(OtherAuthorMappingTest, *version);
    }
}

void DatabaseGenerateBaseTesting::VersionTesting::BookMappingTest(const Version& version)
{
    ASSERT_GREATER_USE_MESSAGE(version.GetBook(), 0, "id = " + std::to_string(version.GetId()));
    ASSERT_UNEQUAL_NULL_PTR(version.GetBook(ancientBooksContainer));
}

void DatabaseGenerateBaseTesting::VersionTesting::CountryMappingTest(const Version& version)
{
    if (0 < version.GetCountry())
    {
        ASSERT_UNEQUAL_NULL_PTR(version.GetCountry(ancientBooksContainer));
    }
}

void DatabaseGenerateBaseTesting::VersionTesting::ReignTitleMappingTest(const Version& version)
{
    if (0 < version.GetReignTitle())
    {
        ASSERT_UNEQUAL_NULL_PTR(version.GetReignTitle(ancientBooksContainer));
    }
}

void DatabaseGenerateBaseTesting::VersionTesting::YearMappingTest(const Version& version)
{
    if (0 < version.GetYear())
    {
        ASSERT_UNEQUAL_NULL_PTR(version.GetYear(ancientBooksContainer));
    }
}

void DatabaseGenerateBaseTesting::VersionTesting::OtherAuthorMappingTest(const Version& version)
{
    ASSERT_EQUAL(version.GetOtherAuthor().size(), version.GetOtherAuthor(ancientBooksContainer).size());
}

void DatabaseGenerateBaseTesting::VersionTesting::EffectiveTest()
{
    for (const auto& version : versionContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(IdTest, *version);
    }
}

void DatabaseGenerateBaseTesting::VersionTesting::IdTest(const Version& version)
{
    ASSERT_EQUAL(version.GetId(), version.GetBook() * 10 + version.GetSource());
}
