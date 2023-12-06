/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:35)

#include "CategoryTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Category.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/CategoryContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateBaseTesting::CategoryTesting::CategoryTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream },
      ancientBooksContainer{ ancientBooksContainer },
      categoryContainer{ ancientBooksContainer.GetCategoryContainer() }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, CategoryTesting)

void DatabaseGenerateBaseTesting::CategoryTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateBaseTesting::CategoryTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MappingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateBaseTesting::CategoryTesting::MappingTest()
{
    for (const auto& category : categoryContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(GatherMappingTest, *category);
    }
}

void DatabaseGenerateBaseTesting::CategoryTesting::GatherMappingTest(const Category& category)
{
    ASSERT_GREATER(category.GetGather(), 0);
    ASSERT_UNEQUAL_NULL_PTR(category.GetGather(ancientBooksContainer));
}

void DatabaseGenerateBaseTesting::CategoryTesting::EffectiveTest()
{
    for (const auto& category : categoryContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(CategoryTest, *category);
    }
}

void DatabaseGenerateBaseTesting::CategoryTesting::CategoryTest(const Category& category)
{
    ASSERT_FALSE(category.GetCategory().empty());
}
