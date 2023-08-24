///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/05 21:03)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Month.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/MonthContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/MonthEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Convert/ConvertEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "MonthConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerCoreTesting::MonthConvertTesting::MonthConvertTesting(const OStreamShared& stream, const MonthContainer& monthContainer)
    : ParentType{ stream }, monthContainer{ monthContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerCoreTesting, MonthConvertTesting)

void DatabaseGenerateServerCoreTesting::MonthConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateServerCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& month : monthContainer.GetContainer())
    {
        const auto monthEntity = convertEntity.Convert(*month);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *month, monthEntity);
    }
}

void DatabaseGenerateServerCoreTesting::MonthConvertTesting::EqualTest(const Month& month, const MonthEntity& monthEntity)
{
    ASSERT_EQUAL(monthEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(month.GetName()));
}
