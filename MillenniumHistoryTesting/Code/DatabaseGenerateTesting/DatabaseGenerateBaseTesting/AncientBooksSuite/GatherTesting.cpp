/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:36)

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Gather.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/GatherContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "GatherTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateBaseTesting::GatherTesting::GatherTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream },
      ancientBooksContainer{ ancientBooksContainer },
      gatherContainer{ ancientBooksContainer.GetGatherContainer() }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, GatherTesting)

void DatabaseGenerateBaseTesting::GatherTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateBaseTesting::GatherTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateBaseTesting::GatherTesting::EffectiveTest()
{
    for (const auto& gather : gatherContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(GatherTest, *gather);
    }
}

void DatabaseGenerateBaseTesting::GatherTesting::GatherTest(const Gather& gather)
{
    ASSERT_FALSE(gather.GetGather().empty());
}
