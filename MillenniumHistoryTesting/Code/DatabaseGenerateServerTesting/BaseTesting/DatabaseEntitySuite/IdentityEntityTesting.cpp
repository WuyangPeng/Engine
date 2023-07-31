///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 22:42)

#include "DatabaseEntityTestingDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Identity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/IdentityContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/IdentityEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "IdentityEntityTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateServerBaseTesting::IdentityEntityTesting::IdentityEntityTesting(const OStreamShared& stream, const IdentityContainer& identityContainer)
    : ParentType{ stream }, identityContainer{ identityContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, IdentityEntityTesting)

void DatabaseGenerateServerBaseTesting::IdentityEntityTesting::SelectOneTest(DatabaseFlush& databaseFlush)
{
    auto index = 0;
    for (const auto& identity : identityContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoSelectOneTest, databaseFlush, *identity);

        ++index;
        if (index == GetTestLoopCount())
        {
            break;
        }
    }

    databaseFlush.Wait();
}

void DatabaseGenerateServerBaseTesting::IdentityEntityTesting::SelectAllTest(DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(IdentityEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  IdentityEntity::GetDatabaseFieldContainer());

    const auto entityContainer = GetEntityContainer<int32_t, IdentityEntity>(database);

    for (const auto& identity : identityContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_3(DoSelectAllTest, databaseFlush, *identity, entityContainer);
    }

    databaseFlush.Wait();
}

void DatabaseGenerateServerBaseTesting::IdentityEntityTesting::SelectAllSizeTest(const DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(IdentityEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  IdentityEntity::GetDatabaseFieldContainer());

    ASSERT_EQUAL(boost::numeric_cast<int>(database.size()), identityContainer.GetContainerSize());

    const auto entityContainer = GetEntityContainer<int32_t, IdentityEntity>(database);

    for (const auto& identity : identityContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *identity, entityContainer);
    }
}

void DatabaseGenerateServerBaseTesting::IdentityEntityTesting::SetEntity(IdentityEntity& identityEntity, const Identity& identity)
{
    identityEntity.SetIdentity(CoreTools::StringConversion::StandardConversionUtf8(identity.GetIdentity()));
}

void DatabaseGenerateServerBaseTesting::IdentityEntityTesting::DoSelectOneTest(DatabaseFlush& databaseFlush, const Identity& identity)
{
    const auto database = databaseFlush.SelectOne(IdentityEntity::GetSelect(databaseFlush.GetWrappersStrategy(), identity.GetId()),
                                                  IdentityEntity::GetDatabaseFieldContainer());

    auto identityEntity = IdentityEntity::Create(database, databaseFlush.GetWrappersStrategy(), identity.GetId());

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, identityEntity, identity);

    databaseFlush.ChangeDatabase(identity.GetId(), identityEntity.GetModify());
}

void DatabaseGenerateServerBaseTesting::IdentityEntityTesting::DoSelectAllTest(DatabaseFlush& databaseFlush, const Identity& identity, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(identity.GetId());
    auto identityEntity = result != entityContainer.cend() ? result->second : IdentityEntity{ databaseFlush.GetWrappersStrategy(), identity.GetId() };

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, identityEntity, identity);

    databaseFlush.ChangeDatabase(identity.GetId(), identityEntity.GetModify());
}

void DatabaseGenerateServerBaseTesting::IdentityEntityTesting::EqualTest(const Identity& identity, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(identity.GetId());

    ASSERT_UNEQUAL_FAILURE_THROW(result, entityContainer.cend(), "数据库中未找到对应数据。id = " + std::to_string(identity.GetId()));

    const auto& identityEntity = result->second;

    ASSERT_EQUAL(identityEntity.GetIdentity(), CoreTools::StringConversion::StandardConversionUtf8(identity.GetIdentity()));
}
