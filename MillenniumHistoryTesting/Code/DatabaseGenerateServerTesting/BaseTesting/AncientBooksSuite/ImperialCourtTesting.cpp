///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/23 18:48)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/ImperialCourt.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/ImperialCourtContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "ImperialCourtTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerBaseTesting::ImperialCourtTesting::ImperialCourtTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream },
      ancientBooksContainer{ ancientBooksContainer },
      imperialCourtContainer{ ancientBooksContainer.GetImperialCourtContainer() }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, ImperialCourtTesting)

void DatabaseGenerateServerBaseTesting::ImperialCourtTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateServerBaseTesting::ImperialCourtTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MappingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateServerBaseTesting::ImperialCourtTesting::MappingTest()
{
    for (const auto& imperialCourt : imperialCourtContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(BeginMappingTest, *imperialCourt);
        ASSERT_NOT_THROW_EXCEPTION_1(EndMappingTest, *imperialCourt);
    }
}

void DatabaseGenerateServerBaseTesting::ImperialCourtTesting::BeginMappingTest(const ImperialCourt& imperialCourt)
{
    if (0 < imperialCourt.GetBegin())
    {
        ASSERT_UNEQUAL_NULL_PTR(imperialCourt.GetBegin(ancientBooksContainer));
    }
}

void DatabaseGenerateServerBaseTesting::ImperialCourtTesting::EndMappingTest(const ImperialCourt& imperialCourt)
{
    if (0 < imperialCourt.GetEnd())
    {
        ASSERT_UNEQUAL_NULL_PTR(imperialCourt.GetEnd(ancientBooksContainer));
    }
}

void DatabaseGenerateServerBaseTesting::ImperialCourtTesting::EffectiveTest()
{
    for (const auto& imperialCourt : imperialCourtContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(CategoryTest, *imperialCourt);
    }
}

void DatabaseGenerateServerBaseTesting::ImperialCourtTesting::CategoryTest(const ImperialCourt& imperialCourt)
{
    ASSERT_FALSE(imperialCourt.GetCategory().empty());
}
