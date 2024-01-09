/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:24)

#include "DatabaseEntityTestingDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Identity.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/IdentityContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/IdentityEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "IdentityEntityTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateBaseTesting::IdentityEntityTesting::IdentityEntityTesting(const OStreamShared& stream, IdentityContainer identityContainer)
    : ParentType{ stream }, identityContainer{ std::move(identityContainer) }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, IdentityEntityTesting)

void DatabaseGenerateBaseTesting::IdentityEntityTesting::SelectOneTest(DatabaseFlush& databaseFlush)
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

void DatabaseGenerateBaseTesting::IdentityEntityTesting::SelectAllTest(DatabaseFlush& databaseFlush)
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

void DatabaseGenerateBaseTesting::IdentityEntityTesting::SelectAllSizeTest(const DatabaseFlush& databaseFlush)
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

void DatabaseGenerateBaseTesting::IdentityEntityTesting::SetEntity(IdentityEntity& identityEntity, const Identity& identity)
{
    identityEntity.SetIdentity(CoreTools::StringConversion::StandardConversionUtf8(identity.GetIdentity()));
}

void DatabaseGenerateBaseTesting::IdentityEntityTesting::DoSelectOneTest(DatabaseFlush& databaseFlush, const Identity& identity)
{
    const auto database = databaseFlush.SelectOne(IdentityEntity::GetSelect(databaseFlush.GetWrappersStrategy(), identity.GetId()),
                                                  IdentityEntity::GetDatabaseFieldContainer());

    auto identityEntity = IdentityEntity::Create(database, databaseFlush.GetWrappersStrategy(), identity.GetId());

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, identityEntity, identity);

    databaseFlush.ChangeDatabase(identity.GetId(), identityEntity.GetModify());
}

void DatabaseGenerateBaseTesting::IdentityEntityTesting::DoSelectAllTest(DatabaseFlush& databaseFlush, const Identity& identity, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(identity.GetId());
    auto identityEntity = result != entityContainer.cend() ? result->second : IdentityEntity{ databaseFlush.GetWrappersStrategy(), identity.GetId() };

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, identityEntity, identity);

    databaseFlush.ChangeDatabase(identity.GetId(), identityEntity.GetModify());
}

void DatabaseGenerateBaseTesting::IdentityEntityTesting::EqualTest(const Identity& identity, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(identity.GetId());

    ASSERT_UNEQUAL_FAILURE_THROW(result, entityContainer.cend(), "数据库中未找到对应数据。id = " + std::to_string(identity.GetId()));

    const auto& identityEntity = result->second;

    ASSERT_EQUAL(identityEntity.GetIdentity(), CoreTools::StringConversion::StandardConversionUtf8(identity.GetIdentity()));
}
