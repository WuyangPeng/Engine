/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:23)

#include "DatabaseEntityTestingDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Day.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/DayContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DayEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "DayEntityTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateBaseTesting::DayEntityTesting::DayEntityTesting(const OStreamShared& stream, DayContainer dayContainer)
    : ParentType{ stream }, dayContainer{ std::move(dayContainer) }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, DayEntityTesting)

void DatabaseGenerateBaseTesting::DayEntityTesting::SelectOneTest(DatabaseFlush& databaseFlush)
{
    auto index = 0;
    for (const auto& day : dayContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoSelectOneTest, databaseFlush, *day);

        ++index;
        if (index == GetTestLoopCount())
        {
            break;
        }
    }

    databaseFlush.Wait();
}

void DatabaseGenerateBaseTesting::DayEntityTesting::SelectAllTest(DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(DayEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  DayEntity::GetDatabaseFieldContainer());

    const auto entityContainer = GetEntityContainer<int32_t, DayEntity>(database);

    for (const auto& day : dayContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_3(DoSelectAllTest, databaseFlush, *day, entityContainer);
    }

    databaseFlush.Wait();
}

void DatabaseGenerateBaseTesting::DayEntityTesting::SelectAllSizeTest(const DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(DayEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  DayEntity::GetDatabaseFieldContainer());

    ASSERT_EQUAL(boost::numeric_cast<int>(database.size()), dayContainer.GetContainerSize());

    const auto entityContainer = GetEntityContainer<int32_t, DayEntity>(database);

    for (const auto& day : dayContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *day, entityContainer);
    }
}

void DatabaseGenerateBaseTesting::DayEntityTesting::SetEntity(DayEntity& dayEntity, const Day& day)
{
    dayEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(day.GetName()));
}

void DatabaseGenerateBaseTesting::DayEntityTesting::DoSelectOneTest(DatabaseFlush& databaseFlush, const Day& day)
{
    const auto database = databaseFlush.SelectOne(DayEntity::GetSelect(databaseFlush.GetWrappersStrategy(), day.GetId()),
                                                  DayEntity::GetDatabaseFieldContainer());

    auto dayEntity = DayEntity::Create(database, databaseFlush.GetWrappersStrategy(), day.GetId());

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, dayEntity, day);

    databaseFlush.ChangeDatabase(day.GetId(), dayEntity.GetModify());
}

void DatabaseGenerateBaseTesting::DayEntityTesting::DoSelectAllTest(DatabaseFlush& databaseFlush, const Day& day, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(day.GetId());
    auto dayEntity = result != entityContainer.cend() ? result->second : DayEntity{ databaseFlush.GetWrappersStrategy(), day.GetId() };

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, dayEntity, day);

    databaseFlush.ChangeDatabase(day.GetId(), dayEntity.GetModify());
}

void DatabaseGenerateBaseTesting::DayEntityTesting::EqualTest(const Day& day, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(day.GetId());

    ASSERT_UNEQUAL_FAILURE_THROW(result, entityContainer.cend(), "数据库中未找到对应数据。id = " + std::to_string(day.GetId()));

    const auto& dayEntity = result->second;

    ASSERT_EQUAL(dayEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(day.GetName()));
}
