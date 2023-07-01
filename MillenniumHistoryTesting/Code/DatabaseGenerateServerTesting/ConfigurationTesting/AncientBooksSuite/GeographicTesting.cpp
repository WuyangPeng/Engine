///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/24 12:17)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Geographic.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/GeographicContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "GeographicTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerBaseTesting::GeographicTesting::GeographicTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream }, ancientBooksContainer{ ancientBooksContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, GeographicTesting)

void DatabaseGenerateServerBaseTesting::GeographicTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateServerBaseTesting::GeographicTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateServerBaseTesting::GeographicTesting::EffectiveTest()
{
    const auto geographicContainer = ancientBooksContainer.GetGeographicContainer();

    for (const auto& geographic : geographicContainer->GetContainer())
    {
        ASSERT_FALSE(geographic->GetName().empty());
    }
}