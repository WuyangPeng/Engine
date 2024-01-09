/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:12)

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Genus.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/GenusContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "GenusTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateBaseTesting::GenusTesting::GenusTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream },
      ancientBooksContainer{ ancientBooksContainer },
      genusContainer{ ancientBooksContainer.GetGenusContainer() }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, GenusTesting)

void DatabaseGenerateBaseTesting::GenusTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateBaseTesting::GenusTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MappingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateBaseTesting::GenusTesting::MappingTest()
{
    for (const auto& genus : genusContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(CategoryMappingTest, *genus);
        ASSERT_NOT_THROW_EXCEPTION_1(FatherMappingTest, *genus);
    }
}

void DatabaseGenerateBaseTesting::GenusTesting::CategoryMappingTest(const Genus& genus)
{
    ASSERT_GREATER(genus.GetCategory(), 0);
    ASSERT_UNEQUAL_NULL_PTR(genus.GetCategory(ancientBooksContainer));
}

void DatabaseGenerateBaseTesting::GenusTesting::FatherMappingTest(const Genus& genus)
{
    if (0 < genus.GetFather())
    {
        ASSERT_UNEQUAL_NULL_PTR(genus.GetFather(ancientBooksContainer));
    }
}

void DatabaseGenerateBaseTesting::GenusTesting::EffectiveTest()
{
    for (const auto& genus : genusContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(NameTest, *genus);
        ASSERT_NOT_THROW_EXCEPTION_1(IdTest, *genus);
    }
}

void DatabaseGenerateBaseTesting::GenusTesting::NameTest(const Genus& genus)
{
    ASSERT_FALSE(genus.GetName().empty());
}

void DatabaseGenerateBaseTesting::GenusTesting::IdTest(const Genus& genus)
{
    ASSERT_EQUAL(genus.GetId() / 1000, genus.GetCategory());
}
