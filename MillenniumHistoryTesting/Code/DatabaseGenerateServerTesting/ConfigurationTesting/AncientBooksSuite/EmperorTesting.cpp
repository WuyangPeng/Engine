///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 22:26)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Emperor.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/EmperorContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "EmperorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerBaseTesting::EmperorTesting::EmperorTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream }, ancientBooksContainer{ ancientBooksContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, EmperorTesting)

void DatabaseGenerateServerBaseTesting::EmperorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateServerBaseTesting::EmperorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MappingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateServerBaseTesting::EmperorTesting::MappingTest()
{
    const auto emperorContainer = ancientBooksContainer.GetEmperorContainer();

    for (const auto& emperor : emperorContainer->GetContainer())
    {
        ASSERT_GREATER(emperor->GetCharacter(), 0);
        ASSERT_UNEQUAL_NULL_PTR(emperor->GetCharacter(ancientBooksContainer));

        if (0 < emperor->GetBeginYear())
        {
            ASSERT_UNEQUAL_NULL_PTR(emperor->GetBeginYear(ancientBooksContainer));
        }

        if (0 < emperor->GetBeginMonth())
        {
            ASSERT_UNEQUAL_NULL_PTR(emperor->GetBeginMonth(ancientBooksContainer));
        }

        if (0 < emperor->GetBeginSexagenaryCycle())
        {
            ASSERT_UNEQUAL_NULL_PTR(emperor->GetBeginSexagenaryCycle(ancientBooksContainer));
        }

        if (0 < emperor->GetBeginDay())
        {
            ASSERT_UNEQUAL_NULL_PTR(emperor->GetBeginDay(ancientBooksContainer));
        }

        if (0 < emperor->GetEndYear())
        {
            ASSERT_UNEQUAL_NULL_PTR(emperor->GetEndYear(ancientBooksContainer));
        }

        if (0 < emperor->GetEndMonth())
        {
            ASSERT_UNEQUAL_NULL_PTR(emperor->GetEndMonth(ancientBooksContainer));
        }

        if (0 < emperor->GetEndSexagenaryCycle())
        {
            ASSERT_UNEQUAL_NULL_PTR(emperor->GetEndSexagenaryCycle(ancientBooksContainer));
        }

        if (0 < emperor->GetEndDay())
        {
            ASSERT_UNEQUAL_NULL_PTR(emperor->GetEndDay(ancientBooksContainer));
        }

        if (0 < emperor->GetAgainBeginYear())
        {
            ASSERT_UNEQUAL_NULL_PTR(emperor->GetAgainBeginYear(ancientBooksContainer));
        }

        if (0 < emperor->GetAgainBeginMonth())
        {
            ASSERT_UNEQUAL_NULL_PTR(emperor->GetAgainBeginMonth(ancientBooksContainer));
        }

        if (0 < emperor->GetAgainBeginSexagenaryCycle())
        {
            ASSERT_UNEQUAL_NULL_PTR(emperor->GetAgainBeginSexagenaryCycle(ancientBooksContainer));
        }

        if (0 < emperor->GetAgainBeginDay())
        {
            ASSERT_UNEQUAL_NULL_PTR(emperor->GetAgainBeginDay(ancientBooksContainer));
        }

        if (0 < emperor->GetAgainEndYear())
        {
            ASSERT_UNEQUAL_NULL_PTR(emperor->GetAgainEndYear(ancientBooksContainer));
        }

        if (0 < emperor->GetAgainEndMonth())
        {
            ASSERT_UNEQUAL_NULL_PTR(emperor->GetAgainEndMonth(ancientBooksContainer));
        }

        if (0 < emperor->GetAgainEndSexagenaryCycle())
        {
            ASSERT_UNEQUAL_NULL_PTR(emperor->GetAgainEndSexagenaryCycle(ancientBooksContainer));
        }

        if (0 < emperor->GetAgainEndDay())
        {
            ASSERT_UNEQUAL_NULL_PTR(emperor->GetAgainEndDay(ancientBooksContainer));
        }
    }
}

void DatabaseGenerateServerBaseTesting::EmperorTesting::EffectiveTest()
{
    const auto emperorContainer = ancientBooksContainer.GetEmperorContainer();

    for (const auto& emperor : emperorContainer->GetContainer())
    {
        ASSERT_EQUAL(emperor->GetId(), emperor->GetCharacter());

        const auto unansweredQuestion = emperor->GetUnansweredQuestion();

        for (const auto& element : unansweredQuestion)
        {
            ASSERT_TRUE(element == SYSTEM_TEXT("beginYear") ||
                        element == SYSTEM_TEXT("beginMonth") ||
                        element == SYSTEM_TEXT("beginSexagenaryCycle") ||
                        element == SYSTEM_TEXT("beginDay") ||
                        element == SYSTEM_TEXT("endYear") ||
                        element == SYSTEM_TEXT("endMonth") ||
                        element == SYSTEM_TEXT("endSexagenaryCycle") ||
                        element == SYSTEM_TEXT("endDay") ||
                        element == SYSTEM_TEXT("againBeginYear") ||
                        element == SYSTEM_TEXT("againBeginMonth") ||
                        element == SYSTEM_TEXT("againBeginSexagenaryCycle") ||
                        element == SYSTEM_TEXT("againBeginDay") ||
                        element == SYSTEM_TEXT("againEndYear") ||
                        element == SYSTEM_TEXT("againEndMonth") ||
                        element == SYSTEM_TEXT("againEndSexagenaryCycle") ||
                        element == SYSTEM_TEXT("againEndDay"));
        }
    }
}