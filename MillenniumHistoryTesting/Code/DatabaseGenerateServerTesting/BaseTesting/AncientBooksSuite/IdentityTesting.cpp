///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/23 18:47)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Identity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/IdentityContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "IdentityTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerBaseTesting::IdentityTesting::IdentityTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream },
      ancientBooksContainer{ ancientBooksContainer },
      identityContainer{ ancientBooksContainer.GetIdentityContainer() }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, IdentityTesting)

void DatabaseGenerateServerBaseTesting::IdentityTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateServerBaseTesting::IdentityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateServerBaseTesting::IdentityTesting::EffectiveTest()
{
    for (const auto& identity : identityContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(IdentityTest, *identity);
    }
}

void DatabaseGenerateServerBaseTesting::IdentityTesting::IdentityTest(const Identity& identity)
{
    ASSERT_FALSE(identity.GetIdentity().empty());
}
