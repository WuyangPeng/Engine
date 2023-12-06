/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:36)

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Geographic.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/GeographicContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "GeographicTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateBaseTesting::GeographicTesting::GeographicTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream },
      ancientBooksContainer{ ancientBooksContainer },
      geographicContainer{ ancientBooksContainer.GetGeographicContainer() }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, GeographicTesting)

void DatabaseGenerateBaseTesting::GeographicTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateBaseTesting::GeographicTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateBaseTesting::GeographicTesting::EffectiveTest()
{
    for (const auto& geographic : geographicContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(NameTest, *geographic);
    }
}

void DatabaseGenerateBaseTesting::GeographicTesting::NameTest(const Geographic& geographic)
{
    ASSERT_FALSE(geographic.GetName().empty());
}
