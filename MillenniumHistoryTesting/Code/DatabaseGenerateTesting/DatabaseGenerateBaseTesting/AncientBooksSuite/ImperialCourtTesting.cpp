/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:12)

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/ImperialCourt.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/ImperialCourtContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "ImperialCourtTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateBaseTesting::ImperialCourtTesting::ImperialCourtTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream },
      ancientBooksContainer{ ancientBooksContainer },
      imperialCourtContainer{ ancientBooksContainer.GetImperialCourtContainer() }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, ImperialCourtTesting)

void DatabaseGenerateBaseTesting::ImperialCourtTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateBaseTesting::ImperialCourtTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MappingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateBaseTesting::ImperialCourtTesting::MappingTest()
{
    for (const auto& imperialCourt : imperialCourtContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(BeginMappingTest, *imperialCourt);
        ASSERT_NOT_THROW_EXCEPTION_1(EndMappingTest, *imperialCourt);
    }
}

void DatabaseGenerateBaseTesting::ImperialCourtTesting::BeginMappingTest(const ImperialCourt& imperialCourt)
{
    if (0 < imperialCourt.GetBegin())
    {
        ASSERT_UNEQUAL_NULL_PTR(imperialCourt.GetBegin(ancientBooksContainer));
    }
}

void DatabaseGenerateBaseTesting::ImperialCourtTesting::EndMappingTest(const ImperialCourt& imperialCourt)
{
    if (0 < imperialCourt.GetEnd())
    {
        ASSERT_UNEQUAL_NULL_PTR(imperialCourt.GetEnd(ancientBooksContainer));
    }
}

void DatabaseGenerateBaseTesting::ImperialCourtTesting::EffectiveTest()
{
    for (const auto& imperialCourt : imperialCourtContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(CategoryTest, *imperialCourt);
    }
}

void DatabaseGenerateBaseTesting::ImperialCourtTesting::CategoryTest(const ImperialCourt& imperialCourt)
{
    ASSERT_FALSE(imperialCourt.GetCategory().empty());
}
