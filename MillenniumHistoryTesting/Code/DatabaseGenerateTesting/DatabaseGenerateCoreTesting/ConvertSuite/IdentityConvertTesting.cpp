/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/30 22:52)

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Identity.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/IdentityContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/IdentityEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Convert/ConvertEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "IdentityConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateCoreTesting::IdentityConvertTesting::IdentityConvertTesting(const OStreamShared& stream, const IdentityContainer& identityContainer)
    : ParentType{ stream }, identityContainer{ identityContainer }
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
