///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/23 19:08)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Source.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/SourceContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "SourceTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerBaseTesting::SourceTesting::SourceTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream },
      ancientBooksContainer{ ancientBooksContainer },
      sourceContainer{ ancientBooksContainer.GetSourceContainer() }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, SourceTesting)

void DatabaseGenerateServerBaseTesting::SourceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateServerBaseTesting::SourceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateServerBaseTesting::SourceTesting::EffectiveTest()
{
    for (const auto& source : sourceContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(NameTest, *source);
    }
}

void DatabaseGenerateServerBaseTesting::SourceTesting::NameTest(const Source& source)
{
    ASSERT_FALSE(source.GetName().empty());
}
