///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/04 21:19)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Identity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/IdentityContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/IdentityEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Convert/ConvertEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "IdentityConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerCoreTesting::IdentityConvertTesting::IdentityConvertTesting(const OStreamShared& stream, const IdentityContainer& identityContainer)
    : ParentType{ stream }, identityContainer{ identityContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerCoreTesting, IdentityConvertTesting)

void DatabaseGenerateServerCoreTesting::IdentityConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateServerCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& identity : identityContainer.GetContainer())
    {
        const auto identityEntity = convertEntity.Convert(*identity);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *identity, identityEntity);
    }
}

void DatabaseGenerateServerCoreTesting::IdentityConvertTesting::EqualTest(const Identity& identity, const IdentityEntity& identityEntity)
{
    ASSERT_EQUAL(identityEntity.GetIdentity(), CoreTools::StringConversion::StandardConversionUtf8(identity.GetIdentity()));
}
