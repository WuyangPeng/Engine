///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/27 21:37)

#include "DatabaseEntityTestingDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Day.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/DayContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/DayEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "DayEntityTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateServerBaseTesting::DayEntityTesting::DayEntityTesting(const OStreamShared& stream, const DayContainer& dayContainer)
    : ParentType{ stream }, dayContainer{ dayContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, DayEntityTesting)

void DatabaseGenerateServerBaseTesting::DayEntityTesting::SelectOneTest(DatabaseFlush& databaseFlush)
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

void DatabaseGenerateServerBaseTesting::DayEntityTesting::SelectAllTest(DatabaseFlush& databaseFlush)
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

void DatabaseGenerateServerBaseTesting::DayEntityTesting::SelectAllSizeTest(const DatabaseFlush& databaseFlush)
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

void DatabaseGenerateServerBaseTesting::DayEntityTesting::SetEntity(DayEntity& dayEntity, const Day& day)
{
    dayEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(day.GetName()));
}

void DatabaseGenerateServerBaseTesting::DayEntityTesting::DoSelectOneTest(DatabaseFlush& databaseFlush, const Day& day)
{
    const auto database = databaseFlush.SelectOne(DayEntity::GetSelect(databaseFlush.GetWrappersStrategy(), day.GetId()),
                                                  DayEntity::GetDatabaseFieldContainer());

    auto dayEntity = DayEntity::Create(database, databaseFlush.GetWrappersStrategy(), day.GetId());

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, dayEntity, day);

    databaseFlush.ChangeDatabase(day.GetId(), dayEntity.GetModify());
}

void DatabaseGenerateServerBaseTesting::DayEntityTesting::DoSelectAllTest(DatabaseFlush& databaseFlush, const Day& day, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(day.GetId());
    auto dayEntity = result != entityContainer.cend() ? result->second : DayEntity{ databaseFlush.GetWrappersStrategy(), day.GetId() };

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, dayEntity, day);

    databaseFlush.ChangeDatabase(day.GetId(), dayEntity.GetModify());
}

void DatabaseGenerateServerBaseTesting::DayEntityTesting::EqualTest(const Day& day, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(day.GetId());

    ASSERT_UNEQUAL_FAILURE_THROW(result, entityContainer.cend(), "数据库中未找到对应数据。id = " + std::to_string(day.GetId()));

    const auto& dayEntity = result->second;

    ASSERT_EQUAL(dayEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(day.GetName()));
}
