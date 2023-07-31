///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/27 21:56)

#include "DatabaseEntityTestingDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Geographic.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/GeographicContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/GeographicEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "GeographicEntityTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateServerBaseTesting::GeographicEntityTesting::GeographicEntityTesting(const OStreamShared& stream, const GeographicContainer& geographicContainer)
    : ParentType{ stream }, geographicContainer{ geographicContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, GeographicEntityTesting)

void DatabaseGenerateServerBaseTesting::GeographicEntityTesting::SelectOneTest(DatabaseFlush& databaseFlush)
{
    auto index = 0;
    for (const auto& geographic : geographicContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoSelectOneTest, databaseFlush, *geographic);

        ++index;
        if (index == GetTestLoopCount())
        {
            break;
        }
    }

    databaseFlush.Wait();
}

void DatabaseGenerateServerBaseTesting::GeographicEntityTesting::SelectAllTest(DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(GeographicEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  GeographicEntity::GetDatabaseFieldContainer());

    const auto entityContainer = GetEntityContainer<int32_t, GeographicEntity>(database);

    for (const auto& geographic : geographicContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_3(DoSelectAllTest, databaseFlush, *geographic, entityContainer);
    }

    databaseFlush.Wait();
}

void DatabaseGenerateServerBaseTesting::GeographicEntityTesting::SelectAllSizeTest(const DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(GeographicEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  GeographicEntity::GetDatabaseFieldContainer());

    ASSERT_EQUAL(boost::numeric_cast<int>(database.size()), geographicContainer.GetContainerSize());

    const auto entityContainer = GetEntityContainer<int32_t, GeographicEntity>(database);

    for (const auto& geographic : geographicContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *geographic, entityContainer);
    }
}

void DatabaseGenerateServerBaseTesting::GeographicEntityTesting::SetEntity(GeographicEntity& geographicEntity, const Geographic& geographic)
{
    geographicEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(geographic.GetName()));
}

void DatabaseGenerateServerBaseTesting::GeographicEntityTesting::DoSelectOneTest(DatabaseFlush& databaseFlush, const Geographic& geographic)
{
    const auto database = databaseFlush.SelectOne(GeographicEntity::GetSelect(databaseFlush.GetWrappersStrategy(), geographic.GetId()),
                                                  GeographicEntity::GetDatabaseFieldContainer());

    auto geographicEntity = GeographicEntity::Create(database, databaseFlush.GetWrappersStrategy(), geographic.GetId());

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, geographicEntity, geographic);

    databaseFlush.ChangeDatabase(geographic.GetId(), geographicEntity.GetModify());
}

void DatabaseGenerateServerBaseTesting::GeographicEntityTesting::DoSelectAllTest(DatabaseFlush& databaseFlush, const Geographic& geographic, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(geographic.GetId());
    auto geographicEntity = result != entityContainer.cend() ? result->second : GeographicEntity{ databaseFlush.GetWrappersStrategy(), geographic.GetId() };

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, geographicEntity, geographic);

    databaseFlush.ChangeDatabase(geographic.GetId(), geographicEntity.GetModify());
}

void DatabaseGenerateServerBaseTesting::GeographicEntityTesting::EqualTest(const Geographic& geographic, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(geographic.GetId());

    ASSERT_UNEQUAL_FAILURE_THROW(result, entityContainer.cend(), "数据库中未找到对应数据。id = " + std::to_string(geographic.GetId()));

    const auto& geographicEntity = result->second;

    ASSERT_EQUAL(geographicEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(geographic.GetName()));
}
