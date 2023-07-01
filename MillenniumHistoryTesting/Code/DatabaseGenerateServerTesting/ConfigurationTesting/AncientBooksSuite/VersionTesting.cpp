///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/24 12:17)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Version.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/VersionContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "VersionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerBaseTesting::VersionTesting::VersionTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream }, ancientBooksContainer{ ancientBooksContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, VersionTesting)

void DatabaseGenerateServerBaseTesting::VersionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateServerBaseTesting::VersionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MappingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateServerBaseTesting::VersionTesting::MappingTest()
{
    const auto versionContainer = ancientBooksContainer.GetVersionContainer();

    for (const auto& version : versionContainer->GetContainer())
    {
        ASSERT_GREATER_USE_MESSAGE(version->GetBook(), 0, "id = " + std::to_string(version->GetId()));
        ASSERT_UNEQUAL_NULL_PTR(version->GetBook(ancientBooksContainer));

        if (0 < version->GetCountry())
        {
            ASSERT_UNEQUAL_NULL_PTR(version->GetCountry(ancientBooksContainer));
        }

        if (0 < version->GetReignTitle())
        {
            ASSERT_UNEQUAL_NULL_PTR(version->GetReignTitle(ancientBooksContainer));
        }

        if (0 < version->GetYear())
        {
            ASSERT_UNEQUAL_NULL_PTR(version->GetYear(ancientBooksContainer));
        }

        ASSERT_EQUAL(version->GetOtherAuthor().size(), version->GetOtherAuthor(ancientBooksContainer).size());
    }
}

void DatabaseGenerateServerBaseTesting::VersionTesting::EffectiveTest()
{
    const auto versionContainer = ancientBooksContainer.GetVersionContainer();

    for (const auto& version : versionContainer->GetContainer())
    {
        ASSERT_EQUAL(version->GetId(), version->GetBook() * 10 + version->GetSource());
    }
}