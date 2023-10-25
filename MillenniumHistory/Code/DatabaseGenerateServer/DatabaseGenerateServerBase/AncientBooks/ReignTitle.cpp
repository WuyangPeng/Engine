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
#include "MonthContainer.h"
#include "ReignTitle.h"
#include "SexagenaryCycleContainer.h"
#include "YearContainer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVRowDetail.h"

using namespace std::literals; 

AncientBooks::ReignTitle::ReignTitle(const CSVRow& csvRow)
    : ParentType{},
      id{ csvRow.GetInt64(SYSTEM_TEXT("id"s)) },
      name{ csvRow.GetString(SYSTEM_TEXT("name"s)) },
      emperor{ csvRow.GetIntArray(SYSTEM_TEXT("emperor"s)) },
      serial{ csvRow.GetInt(SYSTEM_TEXT("serial"s)) },
      beginYear{ csvRow.GetInt(SYSTEM_TEXT("beginYear"s)) },
      beginMonth{ csvRow.GetInt(SYSTEM_TEXT("beginMonth"s)) },
      beginSexagenaryCycle{ csvRow.GetInt(SYSTEM_TEXT("beginSexagenaryCycle"s)) },
      beginDay{ csvRow.GetInt(SYSTEM_TEXT("beginDay"s)) },
      endYear{ csvRow.GetInt(SYSTEM_TEXT("endYear"s)) },
      endMonth{ csvRow.GetInt(SYSTEM_TEXT("endMonth"s)) },
      endSexagenaryCycle{ csvRow.GetInt(SYSTEM_TEXT("endSexagenaryCycle"s)) },
      endDay{ csvRow.GetInt(SYSTEM_TEXT("endDay"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, ReignTitle)

int64_t AncientBooks::ReignTitle::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int64_t AncientBooks::ReignTitle::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

System::String AncientBooks::ReignTitle::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name;
}

AncientBooks::ReignTitle::IntContainer AncientBooks::ReignTitle::GetEmperor() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return emperor;
}

int AncientBooks::ReignTitle::GetEmperorCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(emperor.size());
}

int AncientBooks::ReignTitle::GetEmperor(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return emperor.at(index);
}

AncientBooks::ReignTitle::IntContainerConstIter AncientBooks::ReignTitle::GetEmperorBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return emperor.cbegin();
}

AncientBooks::ReignTitle::IntContainerConstIter AncientBooks::ReignTitle::GetEmperorEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return emperor.cend();
}

AncientBooks::ReignTitle::CharacterContainer AncientBooks::ReignTitle::GetEmperor(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    CharacterContainer result{};

    const auto container = csvContainer.GetCharacterContainer();

    for (const auto& element : emperor)
    {
        result.emplace_back(container->GetCharacter(element));
    }

    return result;
}

int AncientBooks::ReignTitle::GetSerial() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return serial;
}

int AncientBooks::ReignTitle::GetBeginYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return beginYear;
}

AncientBooks::ReignTitle::ConstYearSharedPtr AncientBooks::ReignTitle::GetBeginYear(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetYearContainer()->GetYear(beginYear);
}

int AncientBooks::ReignTitle::GetBeginMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return beginMonth;
}

AncientBooks::ReignTitle::ConstMonthSharedPtr AncientBooks::ReignTitle::GetBeginMonth(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetMonthContainer()->GetMonth(beginMonth);
}

int AncientBooks::ReignTitle::GetBeginSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return beginSexagenaryCycle;
}

AncientBooks::ReignTitle::ConstSexagenaryCycleSharedPtr AncientBooks::ReignTitle::GetBeginSexagenaryCycle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetSexagenaryCycleContainer()->GetSexagenaryCycle(beginSexagenaryCycle);
}

int AncientBooks::ReignTitle::GetBeginDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return beginDay;
}

AncientBooks::ReignTitle::ConstDaySharedPtr AncientBooks::ReignTitle::GetBeginDay(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetDayContainer()->GetDay(beginDay);
}

int AncientBooks::ReignTitle::GetEndYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return endYear;
}

AncientBooks::ReignTitle::ConstYearSharedPtr AncientBooks::ReignTitle::GetEndYear(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetYearContainer()->GetYear(endYear);
}

int AncientBooks::ReignTitle::GetEndMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return endMonth;
}

AncientBooks::ReignTitle::ConstMonthSharedPtr AncientBooks::ReignTitle::GetEndMonth(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetMonthContainer()->GetMonth(endMonth);
}

int AncientBooks::ReignTitle::GetEndSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return endSexagenaryCycle;
}

AncientBooks::ReignTitle::ConstSexagenaryCycleSharedPtr AncientBooks::ReignTitle::GetEndSexagenaryCycle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetSexagenaryCycleContainer()->GetSexagenaryCycle(endSexagenaryCycle);
}

int AncientBooks::ReignTitle::GetEndDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return endDay;
}

AncientBooks::ReignTitle::ConstDaySharedPtr AncientBooks::ReignTitle::GetEndDay(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetDayContainer()->GetDay(endDay);
}

