///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/23 16:24)

#include "CategoryTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Category.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/CategoryContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerBaseTesting::CategoryTesting::CategoryTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream },
      ancientBooksContainer{ ancientBooksContainer },
      categoryContainer{ ancientBooksContainer.GetCategoryContainer() }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, CategoryTesting)

void DatabaseGenerateServerBaseTesting::CategoryTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateServerBaseTesting::CategoryTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MappingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateServerBaseTesting::CategoryTesting::MappingTest()
{
    for (const auto& category : categoryContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(GatherMappingTest, *category);
    }
}

void DatabaseGenerateServerBaseTesting::CategoryTesting::GatherMappingTest(const Category& category)
{
    ASSERT_GREATER(category.GetGather(), 0);
    ASSERT_UNEQUAL_NULL_PTR(category.GetGather(ancientBooksContainer));
}

void DatabaseGenerateServerBaseTesting::CategoryTesting::EffectiveTest()
{
    for (const auto& category : categoryContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(CategoryTest, *category);
    }
}

void DatabaseGenerateServerBaseTesting::CategoryTesting::CategoryTest(const Category& category)
{
    ASSERT_FALSE(category.GetCategory().empty());
}