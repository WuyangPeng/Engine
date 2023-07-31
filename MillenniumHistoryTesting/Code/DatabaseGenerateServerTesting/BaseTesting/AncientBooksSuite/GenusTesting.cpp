///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/23 17:44)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Genus.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/GenusContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "GenusTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerBaseTesting::GenusTesting::GenusTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream },
      ancientBooksContainer{ ancientBooksContainer },
      genusContainer{ ancientBooksContainer.GetGenusContainer() }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, GenusTesting)

void DatabaseGenerateServerBaseTesting::GenusTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateServerBaseTesting::GenusTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MappingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateServerBaseTesting::GenusTesting::MappingTest()
{
    for (const auto& genus : genusContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(GategoryMappingTest, *genus);
        ASSERT_NOT_THROW_EXCEPTION_1(FatherMappingTest, *genus);
    }
}

void DatabaseGenerateServerBaseTesting::GenusTesting::GategoryMappingTest(const Genus& genus)
{
    ASSERT_GREATER(genus.GetCategory(), 0);
    ASSERT_UNEQUAL_NULL_PTR(genus.GetCategory(ancientBooksContainer));
}

void DatabaseGenerateServerBaseTesting::GenusTesting::FatherMappingTest(const Genus& genus)
{
    if (0 < genus.GetFather())
    {
        ASSERT_UNEQUAL_NULL_PTR(genus.GetFather(ancientBooksContainer));
    }
}

void DatabaseGenerateServerBaseTesting::GenusTesting::EffectiveTest()
{
    for (const auto& genus : genusContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(NameTest, *genus);
        ASSERT_NOT_THROW_EXCEPTION_1(IdTest, *genus);
    }
}

void DatabaseGenerateServerBaseTesting::GenusTesting::NameTest(const Genus& genus)
{
    ASSERT_FALSE(genus.GetName().empty());
}

void DatabaseGenerateServerBaseTesting::GenusTesting::IdTest(const Genus& genus)
{
    ASSERT_EQUAL(genus.GetId() / 1000, genus.GetCategory());
}
