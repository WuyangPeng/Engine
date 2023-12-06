/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:42)

#include "DatabaseEntityTestingDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Gather.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/GatherContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/GatherEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "GatherEntityTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateBaseTesting::GatherEntityTesting::GatherEntityTesting(const OStreamShared& stream, const GatherContainer& gatherContainer)
    : ParentType{ stream }, gatherContainer{ gatherContainer }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, GatherEntityTesting)

void DatabaseGenerateBaseTesting::GatherEntityTesting::SelectOneTest(DatabaseFlush& databaseFlush)
{
    auto index = 0;
    for (const auto& gather : gatherContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoSelectOneTest, databaseFlush, *gather);

        ++index;
        if (index == GetTestLoopCount())
        {
            break;
        }
    }

    databaseFlush.Wait();
}

void DatabaseGenerateBaseTesting::GatherEntityTesting::SelectAllTest(DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(GatherEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  GatherEntity::GetDatabaseFieldContainer());

    const auto entityContainer = GetEntityContainer<int32_t, GatherEntity>(database);

    for (const auto& gather : gatherContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_3(DoSelectAllTest, databaseFlush, *gather, entityContainer);
    }

    databaseFlush.Wait();
}

void DatabaseGenerateBaseTesting::GatherEntityTesting::SelectAllSizeTest(const DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(GatherEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  GatherEntity::GetDatabaseFieldContainer());

    ASSERT_EQUAL(boost::numeric_cast<int>(database.size()), gatherContainer.GetContainerSize());

    const auto entityContainer = GetEntityContainer<int32_t, GatherEntity>(database);

    for (const auto& gather : gatherContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *gather, entityContainer);
    }
}

void DatabaseGenerateBaseTesting::GatherEntityTesting::SetEntity(GatherEntity& gatherEntity, const Gather& gather)
{
    gatherEntity.SetGather(CoreTools::StringConversion::StandardConversionUtf8(gather.GetGather()));
}

void DatabaseGenerateBaseTesting::GatherEntityTesting::DoSelectOneTest(DatabaseFlush& databaseFlush, const Gather& gather)
{
    const auto database = databaseFlush.SelectOne(GatherEntity::GetSelect(databaseFlush.GetWrappersStrategy(), gather.GetId()),
                                                  GatherEntity::GetDatabaseFieldContainer());

    auto gatherEntity = GatherEntity::Create(database, databaseFlush.GetWrappersStrategy(), gather.GetId());

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, gatherEntity, gather);

    databaseFlush.ChangeDatabase(gather.GetId(), gatherEntity.GetModify());
}

void DatabaseGenerateBaseTesting::GatherEntityTesting::DoSelectAllTest(DatabaseFlush& databaseFlush, const Gather& gather, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(gather.GetId());
    auto gatherEntity = result != entityContainer.cend() ? result->second : GatherEntity{ databaseFlush.GetWrappersStrategy(), gather.GetId() };

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, gatherEntity, gather);

    databaseFlush.ChangeDatabase(gather.GetId(), gatherEntity.GetModify());
}

void DatabaseGenerateBaseTesting::GatherEntityTesting::EqualTest(const Gather& gather, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(gather.GetId());

    ASSERT_UNEQUAL_FAILURE_THROW(result, entityContainer.cend(), "数据库中未找到对应数据。id = " + std::to_string(gather.GetId()));

    const auto& gatherEntity = result->second;

    ASSERT_EQUAL(gatherEntity.GetGather(), CoreTools::StringConversion::StandardConversionUtf8(gather.GetGather()));
}
