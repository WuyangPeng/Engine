/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:50)

#include "CategoryConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Category.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/CategoryContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/CategoryEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Convert/ConvertEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateCoreTesting::CategoryConvertTesting::CategoryConvertTesting(const OStreamShared& stream, const CategoryContainer& categoryContainer)
    : ParentType{ stream }, categoryContainer{ categoryContainer }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateCoreTesting, CategoryConvertTesting)

void DatabaseGenerateCoreTesting::CategoryConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& category : categoryContainer.GetContainer())
    {
        const auto categoryEntity = convertEntity.Convert(*category);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *category, categoryEntity);
    }
}

void DatabaseGenerateCoreTesting::CategoryConvertTesting::EqualTest(const Category& category, const CategoryEntity& categoryEntity)
{
    ASSERT_EQUAL(categoryEntity.GetGather(), category.GetGather());
    ASSERT_EQUAL(categoryEntity.GetCategory(), CoreTools::StringConversion::StandardConversionUtf8(category.GetCategory()));
}
