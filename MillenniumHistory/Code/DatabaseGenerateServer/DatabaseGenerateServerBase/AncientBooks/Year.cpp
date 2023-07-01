/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "AncientBooksContainer.h"
#include "ReignTitleContainer.h"
#include "SexagenaryCycleContainer.h"
#include "Year.h"
#include "YearContainer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVRowDetail.h"

using namespace std::literals;

AncientBooks::Year::Year(const CSVRow& csvRow)
    : ParentType{},
      id{ csvRow.GetInt(SYSTEM_TEXT("id"s)) },
      name{ csvRow.GetString(SYSTEM_TEXT("name"s)) },
      sexagenaryCycle{ csvRow.GetInt(SYSTEM_TEXT("sexagenaryCycle"s)) },
      reignTitle{ csvRow.GetInt64(SYSTEM_TEXT("reignTitle"s)) },
      year{ csvRow.GetInt(SYSTEM_TEXT("year"s)) },
      unorthodoxReignTitle{ csvRow.GetInt64Array(SYSTEM_TEXT("unorthodoxReignTitle"s)) },
      unorthodoxYear{ csvRow.GetIntArray(SYSTEM_TEXT("unorthodoxYear"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, Year)

int AncientBooks::Year::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int AncientBooks::Year::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

System::String AncientBooks::Year::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name;
}

int AncientBooks::Year::GetSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return sexagenaryCycle;
}

AncientBooks::Year::ConstSexagenaryCycleSharedPtr AncientBooks::Year::GetSexagenaryCycle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetSexagenaryCycleContainer()->GetSexagenaryCycle(sexagenaryCycle);
}

int64_t AncientBooks::Year::GetReignTitle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return reignTitle;
}

AncientBooks::Year::ConstReignTitleSharedPtr AncientBooks::Year::GetReignTitle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetReignTitleContainer()->GetReignTitle(reignTitle);
}

int AncientBooks::Year::GetYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return year;
}

AncientBooks::Year::Int64Container AncientBooks::Year::GetUnorthodoxReignTitle() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return unorthodoxReignTitle;
}

int AncientBooks::Year::GetUnorthodoxReignTitleCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(unorthodoxReignTitle.size());
}

int64_t AncientBooks::Year::GetUnorthodoxReignTitle(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return unorthodoxReignTitle.at(index);
}

AncientBooks::Year::Int64ContainerConstIter AncientBooks::Year::GetUnorthodoxReignTitleBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return unorthodoxReignTitle.cbegin();
}

AncientBooks::Year::Int64ContainerConstIter AncientBooks::Year::GetUnorthodoxReignTitleEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return unorthodoxReignTitle.cend();
}

AncientBooks::Year::ReignTitleContainer AncientBooks::Year::GetUnorthodoxReignTitle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    ReignTitleContainer result{};

    const auto container = csvContainer.GetReignTitleContainer();

    for (const auto& element : unorthodoxReignTitle)
    {
        result.emplace_back(container->GetReignTitle(element));
    }

    return result;
}

AncientBooks::Year::IntContainer AncientBooks::Year::GetUnorthodoxYear() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return unorthodoxYear;
}

int AncientBooks::Year::GetUnorthodoxYearCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(unorthodoxYear.size());
}

int AncientBooks::Year::GetUnorthodoxYear(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return unorthodoxYear.at(index);
}

AncientBooks::Year::IntContainerConstIter AncientBooks::Year::GetUnorthodoxYearBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return unorthodoxYear.cbegin();
}

AncientBooks::Year::IntContainerConstIter AncientBooks::Year::GetUnorthodoxYearEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return unorthodoxYear.cend();
}

AncientBooks::Year::YearContainer AncientBooks::Year::GetUnorthodoxYear(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    YearContainer result{};

    const auto container = csvContainer.GetYearContainer();

    for (const auto& element : unorthodoxYear)
    {
        result.emplace_back(container->GetYear(element));
    }

    return result;
}

