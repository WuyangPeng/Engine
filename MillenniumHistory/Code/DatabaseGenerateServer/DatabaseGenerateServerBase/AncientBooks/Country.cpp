/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "AncientBooksContainer.h"
#include "Country.h"
#include "DayContainer.h"
#include "ImperialCourtContainer.h"
#include "MonthContainer.h"
#include "SexagenaryCycleContainer.h"
#include "YearContainer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVRowDetail.h"

using namespace std::literals;

AncientBooks::Country::Country(const CSVRow& csvRow)
    : ParentType{},
      id{ csvRow.GetInt(SYSTEM_TEXT("id"s)) },
      imperialCourt{ csvRow.GetInt(SYSTEM_TEXT("imperialCourt"s)) },
      category{ csvRow.GetString(SYSTEM_TEXT("category"s)) },
      beginYear{ csvRow.GetInt(SYSTEM_TEXT("beginYear"s)) },
      beginMonth{ csvRow.GetInt(SYSTEM_TEXT("beginMonth"s)) },
      beginSexagenaryCycle{ csvRow.GetInt(SYSTEM_TEXT("beginSexagenaryCycle"s)) },
      beginDay{ csvRow.GetInt(SYSTEM_TEXT("beginDay"s)) },
      endYear{ csvRow.GetInt(SYSTEM_TEXT("endYear"s)) },
      endMonth{ csvRow.GetInt(SYSTEM_TEXT("endMonth"s)) },
      endSexagenaryCycle{ csvRow.GetInt(SYSTEM_TEXT("endSexagenaryCycle"s)) },
      endDay{ csvRow.GetInt(SYSTEM_TEXT("endDay"s)) },
      unansweredQuestion{ csvRow.GetStringArray(SYSTEM_TEXT("unansweredQuestion"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, Country)

int AncientBooks::Country::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int AncientBooks::Country::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int AncientBooks::Country::GetImperialCourt() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return imperialCourt;
}

AncientBooks::Country::ConstImperialCourtSharedPtr AncientBooks::Country::GetImperialCourt(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetImperialCourtContainer()->GetImperialCourt(imperialCourt);
}

System::String AncientBooks::Country::GetCategory() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return category;
}

int AncientBooks::Country::GetBeginYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return beginYear;
}

AncientBooks::Country::ConstYearSharedPtr AncientBooks::Country::GetBeginYear(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetYearContainer()->GetYear(beginYear);
}

int AncientBooks::Country::GetBeginMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return beginMonth;
}

AncientBooks::Country::ConstMonthSharedPtr AncientBooks::Country::GetBeginMonth(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetMonthContainer()->GetMonth(beginMonth);
}

int AncientBooks::Country::GetBeginSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return beginSexagenaryCycle;
}

AncientBooks::Country::ConstSexagenaryCycleSharedPtr AncientBooks::Country::GetBeginSexagenaryCycle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetSexagenaryCycleContainer()->GetSexagenaryCycle(beginSexagenaryCycle);
}

int AncientBooks::Country::GetBeginDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return beginDay;
}

AncientBooks::Country::ConstDaySharedPtr AncientBooks::Country::GetBeginDay(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetDayContainer()->GetDay(beginDay);
}

int AncientBooks::Country::GetEndYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return endYear;
}

AncientBooks::Country::ConstYearSharedPtr AncientBooks::Country::GetEndYear(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetYearContainer()->GetYear(endYear);
}

int AncientBooks::Country::GetEndMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return endMonth;
}

AncientBooks::Country::ConstMonthSharedPtr AncientBooks::Country::GetEndMonth(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetMonthContainer()->GetMonth(endMonth);
}

int AncientBooks::Country::GetEndSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return endSexagenaryCycle;
}

AncientBooks::Country::ConstSexagenaryCycleSharedPtr AncientBooks::Country::GetEndSexagenaryCycle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetSexagenaryCycleContainer()->GetSexagenaryCycle(endSexagenaryCycle);
}

int AncientBooks::Country::GetEndDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return endDay;
}

AncientBooks::Country::ConstDaySharedPtr AncientBooks::Country::GetEndDay(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetDayContainer()->GetDay(endDay);
}

AncientBooks::Country::StringContainer AncientBooks::Country::GetUnansweredQuestion() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return unansweredQuestion;
}

int AncientBooks::Country::GetUnansweredQuestionCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(unansweredQuestion.size());
}

System::String AncientBooks::Country::GetUnansweredQuestion(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return unansweredQuestion.at(index);
}

AncientBooks::Country::StringContainerConstIter AncientBooks::Country::GetUnansweredQuestionBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return unansweredQuestion.cbegin();
}

AncientBooks::Country::StringContainerConstIter AncientBooks::Country::GetUnansweredQuestionEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return unansweredQuestion.cend();
}

