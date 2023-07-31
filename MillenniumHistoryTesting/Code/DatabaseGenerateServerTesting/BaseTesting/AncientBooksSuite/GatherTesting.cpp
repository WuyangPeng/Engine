///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/23 17:42)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Gather.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/GatherContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "GatherTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerBaseTesting::GatherTesting::GatherTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream },
      ancientBooksContainer{ ancientBooksContainer },
      gatherContainer{ ancientBooksContainer.GetGatherContainer() }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, GatherTesting)

void DatabaseGenerateServerBaseTesting::GatherTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateServerBaseTesting::GatherTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateServerBaseTesting::GatherTesting::EffectiveTest()
{
    for (const auto& gather : gatherContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(GatherTest, *gather);
    }
}

void DatabaseGenerateServerBaseTesting::GatherTesting::GatherTest(const Gather& gather)
{
    ASSERT_FALSE(gather.GetGather().empty());
}
