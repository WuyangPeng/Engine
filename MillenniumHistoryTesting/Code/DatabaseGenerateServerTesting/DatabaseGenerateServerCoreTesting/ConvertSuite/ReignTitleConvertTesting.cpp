///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/05 21:05)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/ReignTitle.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/ReignTitleContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/ReignTitleEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Convert/ConvertEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "ReignTitleConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerCoreTesting::ReignTitleConvertTesting::ReignTitleConvertTesting(const OStreamShared& stream, const ReignTitleContainer& reignTitleContainer)
    : ParentType{ stream }, reignTitleContainer{ reignTitleContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerCoreTesting, ReignTitleConvertTesting)

void DatabaseGenerateServerCoreTesting::ReignTitleConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateServerCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& reignTitle : reignTitleContainer.GetContainer())
    {
        const auto reignTitleEntity = convertEntity.Convert(*reignTitle);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *reignTitle, reignTitleEntity);
    }
}

void DatabaseGenerateServerCoreTesting::ReignTitleConvertTesting::EqualTest(const ReignTitle& reignTitle, const ReignTitleEntity& reignTitleEntity)
{
    ASSERT_EQUAL(reignTitleEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(reignTitle.GetName()));
    ASSERT_EQUAL(reignTitleEntity.GetEmperor(), reignTitle.GetEmperor());
    ASSERT_EQUAL(reignTitleEntity.GetSerial(), reignTitle.GetSerial());
    ASSERT_EQUAL(reignTitleEntity.GetBeginYear(), reignTitle.GetBeginYear());
    ASSERT_EQUAL(reignTitleEntity.GetBeginMonth(), reignTitle.GetBeginMonth());
    ASSERT_EQUAL(reignTitleEntity.GetBeginSexagenaryCycle(), reignTitle.GetBeginSexagenaryCycle());
    ASSERT_EQUAL(reignTitleEntity.GetBeginDay(), reignTitle.GetBeginDay());
    ASSERT_EQUAL(reignTitleEntity.GetEndYear(), reignTitle.GetEndYear());
    ASSERT_EQUAL(reignTitleEntity.GetEndMonth(), reignTitle.GetEndMonth());
    ASSERT_EQUAL(reignTitleEntity.GetEndSexagenaryCycle(), reignTitle.GetEndSexagenaryCycle());
    ASSERT_EQUAL(reignTitleEntity.GetEndDay(), reignTitle.GetEndDay());
}
