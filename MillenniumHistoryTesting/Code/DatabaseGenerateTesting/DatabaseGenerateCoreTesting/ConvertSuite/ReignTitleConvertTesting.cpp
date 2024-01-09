/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/25 22:18)

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/ReignTitle.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/ReignTitleContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/ReignTitleEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Convert/ConvertEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "ReignTitleConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateCoreTesting::ReignTitleConvertTesting::ReignTitleConvertTesting(const OStreamShared& stream, ReignTitleContainer reignTitleContainer)
    : ParentType{ stream }, reignTitleContainer{ std::move(reignTitleContainer) }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateCoreTesting, ReignTitleConvertTesting)

void DatabaseGenerateCoreTesting::ReignTitleConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& reignTitle : reignTitleContainer.GetContainer())
    {
        const auto reignTitleEntity = convertEntity.Convert(*reignTitle);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *reignTitle, reignTitleEntity);
    }
}

void DatabaseGenerateCoreTesting::ReignTitleConvertTesting::EqualTest(const ReignTitle& reignTitle, const ReignTitleEntity& reignTitleEntity)
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
