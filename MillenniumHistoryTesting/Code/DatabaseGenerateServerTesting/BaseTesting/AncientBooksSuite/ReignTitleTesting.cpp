///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/23 18:59)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/ReignTitle.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/ReignTitleContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "ReignTitleTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerBaseTesting::ReignTitleTesting::ReignTitleTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream },
      ancientBooksContainer{ ancientBooksContainer },
      reignTitleContainer{ ancientBooksContainer.GetReignTitleContainer() }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, ReignTitleTesting)

void DatabaseGenerateServerBaseTesting::ReignTitleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateServerBaseTesting::ReignTitleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MappingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateServerBaseTesting::ReignTitleTesting::MappingTest()
{
    for (const auto& reignTitle : reignTitleContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(EmperorMappingTest, *reignTitle);
        ASSERT_NOT_THROW_EXCEPTION_1(BeginMappingTest, *reignTitle);
        ASSERT_NOT_THROW_EXCEPTION_1(EndMappingTest, *reignTitle);
    }
}

void DatabaseGenerateServerBaseTesting::ReignTitleTesting::EmperorMappingTest(const ReignTitle& reignTitle)
{
    ASSERT_FALSE(reignTitle.GetEmperor().empty());
    ASSERT_EQUAL(reignTitle.GetEmperor().size(), reignTitle.GetEmperor(ancientBooksContainer).size());
}

void DatabaseGenerateServerBaseTesting::ReignTitleTesting::BeginMappingTest(const ReignTitle& reignTitle)
{
    if (0 < reignTitle.GetBeginYear())
    {
        ASSERT_UNEQUAL_NULL_PTR(reignTitle.GetBeginYear(ancientBooksContainer));
    }

    if (0 < reignTitle.GetBeginMonth())
    {
        ASSERT_UNEQUAL_NULL_PTR(reignTitle.GetBeginMonth(ancientBooksContainer));
    }

    if (0 < reignTitle.GetBeginSexagenaryCycle())
    {
        ASSERT_UNEQUAL_NULL_PTR(reignTitle.GetBeginSexagenaryCycle(ancientBooksContainer));
    }

    if (0 < reignTitle.GetBeginDay())
    {
        ASSERT_UNEQUAL_NULL_PTR(reignTitle.GetBeginDay(ancientBooksContainer));
    }
}

void DatabaseGenerateServerBaseTesting::ReignTitleTesting::EndMappingTest(const ReignTitle& reignTitle)
{
    if (0 < reignTitle.GetEndYear())
    {
        ASSERT_UNEQUAL_NULL_PTR(reignTitle.GetEndYear(ancientBooksContainer));
    }

    if (0 < reignTitle.GetEndMonth())
    {
        ASSERT_UNEQUAL_NULL_PTR(reignTitle.GetEndMonth(ancientBooksContainer));
    }

    if (0 < reignTitle.GetEndSexagenaryCycle())
    {
        ASSERT_UNEQUAL_NULL_PTR(reignTitle.GetEndSexagenaryCycle(ancientBooksContainer));
    }

    if (0 < reignTitle.GetEndDay())
    {
        ASSERT_UNEQUAL_NULL_PTR(reignTitle.GetEndDay(ancientBooksContainer));
    }
}

void DatabaseGenerateServerBaseTesting::ReignTitleTesting::EffectiveTest()
{
    for (const auto& reignTitle : reignTitleContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(NameTest, *reignTitle);
        ASSERT_NOT_THROW_EXCEPTION_1(IdTest, *reignTitle);
    }
}

void DatabaseGenerateServerBaseTesting::ReignTitleTesting::NameTest(const ReignTitle& reignTitle)
{
    ASSERT_FALSE(reignTitle.GetName().empty());
}

void DatabaseGenerateServerBaseTesting::ReignTitleTesting::IdTest(const ReignTitle& reignTitle)
{
    ASSERT_EQUAL(reignTitle.GetId(), reignTitle.GetEmperor(0) * 100LL + reignTitle.GetSerial());
}
