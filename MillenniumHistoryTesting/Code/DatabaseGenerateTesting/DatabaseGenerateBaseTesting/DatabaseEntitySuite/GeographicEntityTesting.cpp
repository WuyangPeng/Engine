/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/30 22:42)

#include "DatabaseEntityTestingDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Geographic.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/GeographicContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/GeographicEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "GeographicEntityTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateBaseTesting::GeographicEntityTesting::GeographicEntityTesting(const OStreamShared& stream, const GeographicContainer& geographicContainer)
    : ParentType{ stream }, geographicContainer{ geographicContainer }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, GeographicEntityTesting)

void DatabaseGenerateBaseTesting::GeographicEntityTesting::SelectOneTest(DatabaseFlush& databaseFlush)
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

void DatabaseGenerateBaseTesting::GeographicEntityTesting::SelectAllTest(DatabaseFlush& databaseFlush)
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

void DatabaseGenerateBaseTesting::GeographicEntityTesting::SelectAllSizeTest(const DatabaseFlush& databaseFlush)
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

void DatabaseGenerateBaseTesting::GeographicEntityTesting::SetEntity(GeographicEntity& geographicEntity, const Geographic& geographic)
{
    geographicEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(geographic.GetName()));
}

void DatabaseGenerateBaseTesting::GeographicEntityTesting::DoSelectOneTest(DatabaseFlush& databaseFlush, const Geographic& geographic)
{
    const auto database = databaseFlush.SelectOne(GeographicEntity::GetSelect(databaseFlush.GetWrappersStrategy(), geographic.GetId()),
                                                  GeographicEntity::GetDatabaseFieldContainer());

    auto geographicEntity = GeographicEntity::Create(database, databaseFlush.GetWrappersStrategy(), geographic.GetId());

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, geographicEntity, geographic);

    databaseFlush.ChangeDatabase(geographic.GetId(), geographicEntity.GetModify());
}

void DatabaseGenerateBaseTesting::GeographicEntityTesting::DoSelectAllTest(DatabaseFlush& databaseFlush, const Geographic& geographic, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(geographic.GetId());
    auto geographicEntity = result != entityContainer.cend() ? result->second : GeographicEntity{ databaseFlush.GetWrappersStrategy(), geographic.GetId() };

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, geographicEntity, geographic);

    databaseFlush.ChangeDatabase(geographic.GetId(), geographicEntity.GetModify());
}

void DatabaseGenerateBaseTesting::GeographicEntityTesting::EqualTest(const Geographic& geographic, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(geographic.GetId());

    ASSERT_UNEQUAL_FAILURE_THROW(result, entityContainer.cend(), "���ݿ���δ�ҵ���Ӧ���ݡ�id = " + std::to_string(geographic.GetId()));

    const auto& geographicEntity = result->second;

    ASSERT_EQUAL(geographicEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(geographic.GetName()));
}
