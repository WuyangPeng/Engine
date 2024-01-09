/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/25 22:18)

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Identity.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/IdentityContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/IdentityEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Convert/ConvertEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "IdentityConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateCoreTesting::IdentityConvertTesting::IdentityConvertTesting(const OStreamShared& stream, IdentityContainer identityContainer)
    : ParentType{ stream }, identityContainer{ std::move(identityContainer) }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateCoreTesting, IdentityConvertTesting)

void DatabaseGenerateCoreTesting::IdentityConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& identity : identityContainer.GetContainer())
    {
        const auto identityEntity = convertEntity.Convert(*identity);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *identity, identityEntity);
    }
}

void DatabaseGenerateCoreTesting::IdentityConvertTesting::EqualTest(const Identity& identity, const IdentityEntity& identityEntity)
{
    ASSERT_EQUAL(identityEntity.GetIdentity(), CoreTools::StringConversion::StandardConversionUtf8(identity.GetIdentity()));
}
