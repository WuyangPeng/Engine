/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:12)

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Emperor.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/EmperorContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "EmperorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateBaseTesting::EmperorTesting::EmperorTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream },
      ancientBooksContainer{ ancientBooksContainer },
      emperorContainer{ ancientBooksContainer.GetEmperorContainer() }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, EmperorTesting)

void DatabaseGenerateBaseTesting::EmperorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateBaseTesting::EmperorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MappingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateBaseTesting::EmperorTesting::MappingTest()
{
    for (const auto& emperor : emperorContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(CharacterMappingTest, *emperor);
        ASSERT_NOT_THROW_EXCEPTION_1(BeginMappingTest, *emperor);
        ASSERT_NOT_THROW_EXCEPTION_1(EndMappingTest, *emperor);
        ASSERT_NOT_THROW_EXCEPTION_1(AgainBeginMappingTest, *emperor);
        ASSERT_NOT_THROW_EXCEPTION_1(AgainEndMappingTest, *emperor);
    }
}

void DatabaseGenerateBaseTesting::EmperorTesting::CharacterMappingTest(const Emperor& emperor)
{
    ASSERT_GREATER(emperor.GetCharacter(), 0);
    ASSERT_UNEQUAL_NULL_PTR(emperor.GetCharacter(ancientBooksContainer));
}

void DatabaseGenerateBaseTesting::EmperorTesting::BeginMappingTest(const Emperor& emperor)
{
    if (0 < emperor.GetBeginYear())
    {
        ASSERT_UNEQUAL_NULL_PTR(emperor.GetBeginYear(ancientBooksContainer));
    }

    if (0 < emperor.GetBeginMonth())
    {
        ASSERT_UNEQUAL_NULL_PTR(emperor.GetBeginMonth(ancientBooksContainer));
    }

    if (0 < emperor.GetBeginSexagenaryCycle())
    {
        ASSERT_UNEQUAL_NULL_PTR(emperor.GetBeginSexagenaryCycle(ancientBooksContainer));
    }

    if (0 < emperor.GetBeginDay())
    {
        ASSERT_UNEQUAL_NULL_PTR(emperor.GetBeginDay(ancientBooksContainer));
    }
}

void DatabaseGenerateBaseTesting::EmperorTesting::EndMappingTest(const Emperor& emperor)
{
    if (0 < emperor.GetEndYear())
    {
        ASSERT_UNEQUAL_NULL_PTR(emperor.GetEndYear(ancientBooksContainer));
    }

    if (0 < emperor.GetEndMonth())
    {
        ASSERT_UNEQUAL_NULL_PTR(emperor.GetEndMonth(ancientBooksContainer));
    }

    if (0 < emperor.GetEndSexagenaryCycle())
    {
        ASSERT_UNEQUAL_NULL_PTR(emperor.GetEndSexagenaryCycle(ancientBooksContainer));
    }

    if (0 < emperor.GetEndDay())
    {
        ASSERT_UNEQUAL_NULL_PTR(emperor.GetEndDay(ancientBooksContainer));
    }
}

void DatabaseGenerateBaseTesting::EmperorTesting::AgainBeginMappingTest(const Emperor& emperor)
{
    if (0 < emperor.GetAgainBeginYear())
    {
        ASSERT_UNEQUAL_NULL_PTR(emperor.GetAgainBeginYear(ancientBooksContainer));
    }

    if (0 < emperor.GetAgainBeginMonth())
    {
        ASSERT_UNEQUAL_NULL_PTR(emperor.GetAgainBeginMonth(ancientBooksContainer));
    }

    if (0 < emperor.GetAgainBeginSexagenaryCycle())
    {
        ASSERT_UNEQUAL_NULL_PTR(emperor.GetAgainBeginSexagenaryCycle(ancientBooksContainer));
    }

    if (0 < emperor.GetAgainBeginDay())
    {
        ASSERT_UNEQUAL_NULL_PTR(emperor.GetAgainBeginDay(ancientBooksContainer));
    }
}

void DatabaseGenerateBaseTesting::EmperorTesting::AgainEndMappingTest(const Emperor& emperor)
{
    if (0 < emperor.GetAgainEndYear())
    {
        ASSERT_UNEQUAL_NULL_PTR(emperor.GetAgainEndYear(ancientBooksContainer));
    }

    if (0 < emperor.GetAgainEndMonth())
    {
        ASSERT_UNEQUAL_NULL_PTR(emperor.GetAgainEndMonth(ancientBooksContainer));
    }

    if (0 < emperor.GetAgainEndSexagenaryCycle())
    {
        ASSERT_UNEQUAL_NULL_PTR(emperor.GetAgainEndSexagenaryCycle(ancientBooksContainer));
    }

    if (0 < emperor.GetAgainEndDay())
    {
        ASSERT_UNEQUAL_NULL_PTR(emperor.GetAgainEndDay(ancientBooksContainer));
    }
}

void DatabaseGenerateBaseTesting::EmperorTesting::EffectiveTest()
{
    for (const auto& emperor : emperorContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(IdTest, *emperor);
        ASSERT_NOT_THROW_EXCEPTION_1(UnansweredQuestionTest, *emperor);
    }
}

void DatabaseGenerateBaseTesting::EmperorTesting::IdTest(const Emperor& emperor)
{
    ASSERT_EQUAL(emperor.GetId(), emperor.GetCharacter());
}

void DatabaseGenerateBaseTesting::EmperorTesting::UnansweredQuestionTest(const Emperor& emperor)
{
    for (const auto unansweredQuestion = emperor.GetUnansweredQuestion();
         const auto& element : unansweredQuestion)
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
