/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:25)

#include "DatabaseEntityTestingDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/ReignTitle.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/ReignTitleContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/ReignTitleEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "ReignTitleEntityTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateBaseTesting::ReignTitleEntityTesting::ReignTitleEntityTesting(const OStreamShared& stream, ReignTitleContainer reignTitleContainer)
    : ParentType{ stream }, reignTitleContainer{ std::move(reignTitleContainer) }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, ReignTitleEntityTesting)

void DatabaseGenerateBaseTesting::ReignTitleEntityTesting::SelectOneTest(DatabaseFlush& databaseFlush)
{
    auto index = 0;
    for (const auto& reignTitle : reignTitleContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoSelectOneTest, databaseFlush, *reignTitle);

        ++index;
        if (index == GetTestLoopCount())
        {
            break;
        }
    }

    databaseFlush.Wait();
}

void DatabaseGenerateBaseTesting::ReignTitleEntityTesting::SelectAllTest(DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(ReignTitleEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  ReignTitleEntity::GetDatabaseFieldContainer());

    const auto entityContainer = GetEntityContainer<int64_t, ReignTitleEntity>(database);

    for (const auto& reignTitle : reignTitleContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_3(DoSelectAllTest, databaseFlush, *reignTitle, entityContainer);
    }

    databaseFlush.Wait();
}

void DatabaseGenerateBaseTesting::ReignTitleEntityTesting::SelectAllSizeTest(const DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(ReignTitleEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  ReignTitleEntity::GetDatabaseFieldContainer());

    ASSERT_EQUAL(boost::numeric_cast<int>(database.size()), reignTitleContainer.GetContainerSize());

    const auto entityContainer = GetEntityContainer<int64_t, ReignTitleEntity>(database);

    for (const auto& reignTitle : reignTitleContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *reignTitle, entityContainer);
    }
}

void DatabaseGenerateBaseTesting::ReignTitleEntityTesting::SetEntity(ReignTitleEntity& reignTitleEntity, const ReignTitle& reignTitle)
{
    reignTitleEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(reignTitle.GetName()));
    reignTitleEntity.SetEmperor(reignTitle.GetEmperor());
    reignTitleEntity.SetSerial(reignTitle.GetSerial());
    reignTitleEntity.SetBeginYear(reignTitle.GetBeginYear());
    reignTitleEntity.SetBeginMonth(reignTitle.GetBeginMonth());
    reignTitleEntity.SetBeginSexagenaryCycle(reignTitle.GetBeginSexagenaryCycle());
    reignTitleEntity.SetBeginDay(reignTitle.GetBeginDay());
    reignTitleEntity.SetEndYear(reignTitle.GetEndYear());
    reignTitleEntity.SetEndMonth(reignTitle.GetEndMonth());
    reignTitleEntity.SetEndSexagenaryCycle(reignTitle.GetEndSexagenaryCycle());
    reignTitleEntity.SetEndDay(reignTitle.GetEndDay());
}

void DatabaseGenerateBaseTesting::ReignTitleEntityTesting::DoSelectOneTest(DatabaseFlush& databaseFlush, const ReignTitle& reignTitle)
{
    const auto database = databaseFlush.SelectOne(ReignTitleEntity::GetSelect(databaseFlush.GetWrappersStrategy(), reignTitle.GetId()),
                                                  ReignTitleEntity::GetDatabaseFieldContainer());

    auto reignTitleEntity = ReignTitleEntity::Create(database, databaseFlush.GetWrappersStrategy(), reignTitle.GetId());

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, reignTitleEntity, reignTitle);

    databaseFlush.ChangeDatabase(reignTitle.GetId(), reignTitleEntity.GetModify());
}

void DatabaseGenerateBaseTesting::ReignTitleEntityTesting::DoSelectAllTest(DatabaseFlush& databaseFlush, const ReignTitle& reignTitle, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(reignTitle.GetId());
    auto reignTitleEntity = result != entityContainer.cend() ? result->second : ReignTitleEntity{ databaseFlush.GetWrappersStrategy(), reignTitle.GetId() };

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, reignTitleEntity, reignTitle);

    databaseFlush.ChangeDatabase(reignTitle.GetId(), reignTitleEntity.GetModify());
}

void DatabaseGenerateBaseTesting::ReignTitleEntityTesting::EqualTest(const ReignTitle& reignTitle, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(reignTitle.GetId());

    ASSERT_UNEQUAL_FAILURE_THROW(result, entityContainer.cend(), "数据库中未找到对应数据。id = " + std::to_string(reignTitle.GetId()));

    const auto& reignTitleEntity = result->second;

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
