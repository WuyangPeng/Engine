/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:12)

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Identity.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/IdentityContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "IdentityTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateBaseTesting::IdentityTesting::IdentityTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream },
      ancientBooksContainer{ ancientBooksContainer },
      identityContainer{ ancientBooksContainer.GetIdentityContainer() }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, IdentityTesting)

void DatabaseGenerateBaseTesting::IdentityTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateBaseTesting::IdentityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateBaseTesting::IdentityTesting::EffectiveTest()
{
    for (const auto& identity : identityContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(IdentityTest, *identity);
    }
}

void DatabaseGenerateBaseTesting::IdentityTesting::IdentityTest(const Identity& identity)
{
    ASSERT_FALSE(identity.GetIdentity().empty());
}
