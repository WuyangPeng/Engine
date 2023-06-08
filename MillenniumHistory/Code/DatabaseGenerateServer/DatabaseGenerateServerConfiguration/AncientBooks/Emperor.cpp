/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "AncientBooksContainer.h"
#include "CharacterContainer.h"
#include "DayContainer.h"
#include "Emperor.h"
#include "MonthContainer.h"
#include "SexagenaryCycleContainer.h"
#include "YearContainer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVRowDetail.h"

using namespace std::literals;

AncientBooks::Emperor::Emperor(const CoreTools::CSVRow& csvRow)
    : ParentType{},
      id{ csvRow.GetInt(SYSTEM_TEXT("id"s)) },
      character{ csvRow.GetInt(SYSTEM_TEXT("character"s)) },
      name{ csvRow.GetString(SYSTEM_TEXT("name"s)) },
      dynasticTitle{ csvRow.GetString(SYSTEM_TEXT("dynasticTitle"s)) },
      dynasticTitleAlias{ csvRow.GetStringArray(SYSTEM_TEXT("dynasticTitleAlias"s)) },
      posthumousTitle{ csvRow.GetString(SYSTEM_TEXT("posthumousTitle"s)) },
      posthumousTitleAlias{ csvRow.GetStringArray(SYSTEM_TEXT("posthumousTitleAlias"s)) },
      beginYear{ csvRow.GetInt(SYSTEM_TEXT("beginYear"s)) },
      beginMonth{ csvRow.GetInt(SYSTEM_TEXT("beginMonth"s)) },
      beginSexagenaryCycle{ csvRow.GetInt(SYSTEM_TEXT("beginSexagenaryCycle"s)) },
      beginDay{ csvRow.GetInt(SYSTEM_TEXT("beginDay"s)) },
      endYear{ csvRow.GetInt(SYSTEM_TEXT("endYear"s)) },
      endMonth{ csvRow.GetInt(SYSTEM_TEXT("endMonth"s)) },
      endSexagenaryCycle{ csvRow.GetInt(SYSTEM_TEXT("endSexagenaryCycle"s)) },
      endDay{ csvRow.GetInt(SYSTEM_TEXT("endDay"s)) },
      againBeginYear{ csvRow.GetInt(SYSTEM_TEXT("againBeginYear"s)) },
      againBeginMonth{ csvRow.GetInt(SYSTEM_TEXT("againBeginMonth"s)) },
      againBeginSexagenaryCycle{ csvRow.GetInt(SYSTEM_TEXT("againBeginSexagenaryCycle"s)) },
      againBeginDay{ csvRow.GetInt(SYSTEM_TEXT("againBeginDay"s)) },
      againEndYear{ csvRow.GetInt(SYSTEM_TEXT("againEndYear"s)) },
      againEndMonth{ csvRow.GetInt(SYSTEM_TEXT("againEndMonth"s)) },
      againEndSexagenaryCycle{ csvRow.GetInt(SYSTEM_TEXT("againEndSexagenaryCycle"s)) },
      againEndDay{ csvRow.GetInt(SYSTEM_TEXT("againEndDay"s)) },
      unansweredQuestion{ csvRow.GetStringArray(SYSTEM_TEXT("unansweredQuestion"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, Emperor)

int AncientBooks::Emperor::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int AncientBooks::Emperor::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int AncientBooks::Emperor::GetCharacter() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return character;
}

std::shared_ptr<const AncientBooks::CharacterMappingType> AncientBooks::Emperor::GetCharacter(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetCharacterContainer()->GetCharacter(character);
}

System::String AncientBooks::Emperor::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name;
}

System::String AncientBooks::Emperor::GetDynasticTitle() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return dynasticTitle;
}

std::vector<System::String> AncientBooks::Emperor::GetDynasticTitleAlias() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return dynasticTitleAlias;
}

int AncientBooks::Emperor::GetDynasticTitleAliasCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(dynasticTitleAlias.size());
}

System::String AncientBooks::Emperor::GetDynasticTitleAlias(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return dynasticTitleAlias.at(index);
}

std::vector<System::String>::const_iterator AncientBooks::Emperor::GetDynasticTitleAliasBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return dynasticTitleAlias.cbegin();
}

std::vector<System::String>::const_iterator AncientBooks::Emperor::GetDynasticTitleAliasEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return dynasticTitleAlias.cend();
}

System::String AncientBooks::Emperor::GetPosthumousTitle() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return posthumousTitle;
}

std::vector<System::String> AncientBooks::Emperor::GetPosthumousTitleAlias() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return posthumousTitleAlias;
}

int AncientBooks::Emperor::GetPosthumousTitleAliasCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(posthumousTitleAlias.size());
}

System::String AncientBooks::Emperor::GetPosthumousTitleAlias(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return posthumousTitleAlias.at(index);
}

std::vector<System::String>::const_iterator AncientBooks::Emperor::GetPosthumousTitleAliasBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return posthumousTitleAlias.cbegin();
}

std::vector<System::String>::const_iterator AncientBooks::Emperor::GetPosthumousTitleAliasEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return posthumousTitleAlias.cend();
}

int AncientBooks::Emperor::GetBeginYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return beginYear;
}

std::shared_ptr<const AncientBooks::YearMappingType> AncientBooks::Emperor::GetBeginYear(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetYearContainer()->GetYear(beginYear);
}

int AncientBooks::Emperor::GetBeginMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return beginMonth;
}

std::shared_ptr<const AncientBooks::MonthMappingType> AncientBooks::Emperor::GetBeginMonth(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetMonthContainer()->GetMonth(beginMonth);
}

int AncientBooks::Emperor::GetBeginSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return beginSexagenaryCycle;
}

std::shared_ptr<const AncientBooks::SexagenaryCycleMappingType> AncientBooks::Emperor::GetBeginSexagenaryCycle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetSexagenaryCycleContainer()->GetSexagenaryCycle(beginSexagenaryCycle);
}

int AncientBooks::Emperor::GetBeginDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return beginDay;
}

std::shared_ptr<const AncientBooks::DayMappingType> AncientBooks::Emperor::GetBeginDay(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetDayContainer()->GetDay(beginDay);
}

int AncientBooks::Emperor::GetEndYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return endYear;
}

std::shared_ptr<const AncientBooks::YearMappingType> AncientBooks::Emperor::GetEndYear(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetYearContainer()->GetYear(endYear);
}

int AncientBooks::Emperor::GetEndMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return endMonth;
}

std::shared_ptr<const AncientBooks::MonthMappingType> AncientBooks::Emperor::GetEndMonth(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetMonthContainer()->GetMonth(endMonth);
}

int AncientBooks::Emperor::GetEndSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return endSexagenaryCycle;
}

std::shared_ptr<const AncientBooks::SexagenaryCycleMappingType> AncientBooks::Emperor::GetEndSexagenaryCycle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetSexagenaryCycleContainer()->GetSexagenaryCycle(endSexagenaryCycle);
}

int AncientBooks::Emperor::GetEndDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return endDay;
}

std::shared_ptr<const AncientBooks::DayMappingType> AncientBooks::Emperor::GetEndDay(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetDayContainer()->GetDay(endDay);
}

int AncientBooks::Emperor::GetAgainBeginYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return againBeginYear;
}

std::shared_ptr<const AncientBooks::YearMappingType> AncientBooks::Emperor::GetAgainBeginYear(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetYearContainer()->GetYear(againBeginYear);
}

int AncientBooks::Emperor::GetAgainBeginMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return againBeginMonth;
}

std::shared_ptr<const AncientBooks::MonthMappingType> AncientBooks::Emperor::GetAgainBeginMonth(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetMonthContainer()->GetMonth(againBeginMonth);
}

int AncientBooks::Emperor::GetAgainBeginSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return againBeginSexagenaryCycle;
}

std::shared_ptr<const AncientBooks::SexagenaryCycleMappingType> AncientBooks::Emperor::GetAgainBeginSexagenaryCycle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetSexagenaryCycleContainer()->GetSexagenaryCycle(againBeginSexagenaryCycle);
}

int AncientBooks::Emperor::GetAgainBeginDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return againBeginDay;
}

std::shared_ptr<const AncientBooks::DayMappingType> AncientBooks::Emperor::GetAgainBeginDay(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetDayContainer()->GetDay(againBeginDay);
}

int AncientBooks::Emperor::GetAgainEndYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return againEndYear;
}

std::shared_ptr<const AncientBooks::YearMappingType> AncientBooks::Emperor::GetAgainEndYear(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetYearContainer()->GetYear(againEndYear);
}

int AncientBooks::Emperor::GetAgainEndMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return againEndMonth;
}

std::shared_ptr<const AncientBooks::MonthMappingType> AncientBooks::Emperor::GetAgainEndMonth(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetMonthContainer()->GetMonth(againEndMonth);
}

int AncientBooks::Emperor::GetAgainEndSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return againEndSexagenaryCycle;
}

std::shared_ptr<const AncientBooks::SexagenaryCycleMappingType> AncientBooks::Emperor::GetAgainEndSexagenaryCycle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetSexagenaryCycleContainer()->GetSexagenaryCycle(againEndSexagenaryCycle);
}

int AncientBooks::Emperor::GetAgainEndDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return againEndDay;
}

std::shared_ptr<const AncientBooks::DayMappingType> AncientBooks::Emperor::GetAgainEndDay(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetDayContainer()->GetDay(againEndDay);
}

std::vector<System::String> AncientBooks::Emperor::GetUnansweredQuestion() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return unansweredQuestion;
}

int AncientBooks::Emperor::GetUnansweredQuestionCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(unansweredQuestion.size());
}

System::String AncientBooks::Emperor::GetUnansweredQuestion(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return unansweredQuestion.at(index);
}

std::vector<System::String>::const_iterator AncientBooks::Emperor::GetUnansweredQuestionBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return unansweredQuestion.cbegin();
}

std::vector<System::String>::const_iterator AncientBooks::Emperor::GetUnansweredQuestionEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return unansweredQuestion.cend();
}

