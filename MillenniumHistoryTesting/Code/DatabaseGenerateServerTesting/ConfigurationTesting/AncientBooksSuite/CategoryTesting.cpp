///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/24 12:17)

#include "CategoryTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Category.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/CategoryContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerBaseTesting::CategoryTesting::CategoryTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream }, ancientBooksContainer{ ancientBooksContainer }
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
    const auto categoryContainer = ancientBooksContainer.GetCategoryContainer();

    for (const auto& category : categoryContainer->GetContainer())
    {
        ASSERT_GREATER(category->GetGather(), 0);
        ASSERT_UNEQUAL_NULL_PTR(category->GetGather(ancientBooksContainer));
    }
}

void DatabaseGenerateServerBaseTesting::CategoryTesting::EffectiveTest()
{
    const auto categoryContainer = ancientBooksContainer.GetCategoryContainer();

    for (const auto& category : categoryContainer->GetContainer())
    {
        ASSERT_FALSE(category->GetCategory().empty());
    }
}
