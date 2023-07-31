///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 23:05)

#include "DatabaseEntityTestingDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/SexagenaryCycle.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/SexagenaryCycleContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/SexagenaryCycleEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "SexagenaryCycleEntityTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateServerBaseTesting::SexagenaryCycleEntityTesting::SexagenaryCycleEntityTesting(const OStreamShared& stream, const SexagenaryCycleContainer& sexagenaryCycleContainer)
    : ParentType{ stream }, sexagenaryCycleContainer{ sexagenaryCycleContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, SexagenaryCycleEntityTesting)

void DatabaseGenerateServerBaseTesting::SexagenaryCycleEntityTesting::SelectOneTest(DatabaseFlush& databaseFlush)
{
    auto index = 0;
    for (const auto& sexagenaryCycle : sexagenaryCycleContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoSelectOneTest, databaseFlush, *sexagenaryCycle);

        ++index;
        if (index == GetTestLoopCount())
        {
            break;
        }
    }

    databaseFlush.Wait();
}

void DatabaseGenerateServerBaseTesting::SexagenaryCycleEntityTesting::SelectAllTest(DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(SexagenaryCycleEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  SexagenaryCycleEntity::GetDatabaseFieldContainer());

    const auto entityContainer = GetEntityContainer<int32_t, SexagenaryCycleEntity>(database);

    for (const auto& sexagenaryCycle : sexagenaryCycleContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_3(DoSelectAllTest, databaseFlush, *sexagenaryCycle, entityContainer);
    }

    databaseFlush.Wait();
}

void DatabaseGenerateServerBaseTesting::SexagenaryCycleEntityTesting::SelectAllSizeTest(const DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(SexagenaryCycleEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  SexagenaryCycleEntity::GetDatabaseFieldContainer());

    ASSERT_EQUAL(boost::numeric_cast<int>(database.size()), sexagenaryCycleContainer.GetContainerSize());

    const auto entityContainer = GetEntityContainer<int32_t, SexagenaryCycleEntity>(database);

    for (const auto& sexagenaryCycle : sexagenaryCycleContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *sexagenaryCycle, entityContainer);
    }
}

void DatabaseGenerateServerBaseTesting::SexagenaryCycleEntityTesting::SetEntity(SexagenaryCycleEntity& sexagenaryCycleEntity, const SexagenaryCycle& sexagenaryCycle)
{
    sexagenaryCycleEntity.SetHeavenly(CoreTools::StringConversion::StandardConversionUtf8(sexagenaryCycle.GetHeavenly()));
    sexagenaryCycleEntity.SetBranch(CoreTools::StringConversion::StandardConversionUtf8(sexagenaryCycle.GetBranch()));
    sexagenaryCycleEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(sexagenaryCycle.GetName()));
}

void DatabaseGenerateServerBaseTesting::SexagenaryCycleEntityTesting::DoSelectOneTest(DatabaseFlush& databaseFlush, const SexagenaryCycle& sexagenaryCycle)
{
    const auto database = databaseFlush.SelectOne(SexagenaryCycleEntity::GetSelect(databaseFlush.GetWrappersStrategy(), sexagenaryCycle.GetId()),
                                                  SexagenaryCycleEntity::GetDatabaseFieldContainer());

    auto sexagenaryCycleEntity = SexagenaryCycleEntity::Create(database, databaseFlush.GetWrappersStrategy(), sexagenaryCycle.GetId());

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, sexagenaryCycleEntity, sexagenaryCycle);

    databaseFlush.ChangeDatabase(sexagenaryCycle.GetId(), sexagenaryCycleEntity.GetModify());
}

void DatabaseGenerateServerBaseTesting::SexagenaryCycleEntityTesting::DoSelectAllTest(DatabaseFlush& databaseFlush, const SexagenaryCycle& sexagenaryCycle, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(sexagenaryCycle.GetId());
    auto sexagenaryCycleEntity = result != entityContainer.cend() ? result->second : SexagenaryCycleEntity{ databaseFlush.GetWrappersStrategy(), sexagenaryCycle.GetId() };

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, sexagenaryCycleEntity, sexagenaryCycle);

    databaseFlush.ChangeDatabase(sexagenaryCycle.GetId(), sexagenaryCycleEntity.GetModify());
}

void DatabaseGenerateServerBaseTesting::SexagenaryCycleEntityTesting::EqualTest(const SexagenaryCycle& sexagenaryCycle, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(sexagenaryCycle.GetId());

    ASSERT_UNEQUAL_FAILURE_THROW(result, entityContainer.cend(), "数据库中未找到对应数据。id = " + std::to_string(sexagenaryCycle.GetId()));

    const auto& sexagenaryCycleEntity = result->second;

    ASSERT_EQUAL(sexagenaryCycleEntity.GetHeavenly(), CoreTools::StringConversion::StandardConversionUtf8(sexagenaryCycle.GetHeavenly()));
    ASSERT_EQUAL(sexagenaryCycleEntity.GetBranch(), CoreTools::StringConversion::StandardConversionUtf8(sexagenaryCycle.GetBranch()));
    ASSERT_EQUAL(sexagenaryCycleEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(sexagenaryCycle.GetName()));
}
