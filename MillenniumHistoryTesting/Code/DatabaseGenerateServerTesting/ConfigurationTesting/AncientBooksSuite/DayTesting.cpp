///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 21:24)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Day.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/DayContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "DayTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerBaseTesting::DayTesting::DayTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream }, ancientBooksContainer{ ancientBooksContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, DayTesting)

void DatabaseGenerateServerBaseTesting::DayTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateServerBaseTesting::DayTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateServerBaseTesting::DayTesting::EffectiveTest()
{
    const auto dayContainer = ancientBooksContainer.GetDayContainer();

    for (const auto& day : dayContainer->GetContainer())
    {
        ASSERT_FALSE(day->GetName().empty());
    }
}
