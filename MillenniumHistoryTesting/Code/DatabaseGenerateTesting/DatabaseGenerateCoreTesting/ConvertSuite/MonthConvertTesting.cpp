/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/25 22:18)

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Month.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/MonthContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/MonthEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Convert/ConvertEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "MonthConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateCoreTesting::MonthConvertTesting::MonthConvertTesting(const OStreamShared& stream, MonthContainer monthContainer)
    : ParentType{ stream }, monthContainer{ std::move(monthContainer) }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateCoreTesting, MonthConvertTesting)

void DatabaseGenerateCoreTesting::MonthConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& month : monthContainer.GetContainer())
    {
        const auto monthEntity = convertEntity.Convert(*month);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *month, monthEntity);
    }
}

void DatabaseGenerateCoreTesting::MonthConvertTesting::EqualTest(const Month& month, const MonthEntity& monthEntity)
{
    ASSERT_EQUAL(monthEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(month.GetName()));
}
