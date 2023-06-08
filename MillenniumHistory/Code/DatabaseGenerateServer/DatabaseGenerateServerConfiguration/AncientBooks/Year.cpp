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
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVRowDetail.h"

using namespace std::literals;

AncientBooks::Year::Year(const CoreTools::CSVRow& csvRow)
    : ParentType{},
      id{ csvRow.GetInt(SYSTEM_TEXT("id"s)) },
      name{ csvRow.GetString(SYSTEM_TEXT("name"s)) },
      sexagenaryCycle{ csvRow.GetInt(SYSTEM_TEXT("sexagenaryCycle"s)) },
      reignTitle{ csvRow.GetInt64(SYSTEM_TEXT("reignTitle"s)) },
      year{ csvRow.GetInt(SYSTEM_TEXT("year"s)) },
      unorthodoxReignTitle{ csvRow.GetIntArray(SYSTEM_TEXT("unorthodoxReignTitle"s)) },
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

std::shared_ptr<const AncientBooks::SexagenaryCycleMappingType> AncientBooks::Year::GetSexagenaryCycle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetSexagenaryCycleContainer()->GetSexagenaryCycle(sexagenaryCycle);
}

int64_t AncientBooks::Year::GetReignTitle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return reignTitle;
}

std::shared_ptr<const AncientBooks::ReignTitleMappingType> AncientBooks::Year::GetReignTitle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetReignTitleContainer()->GetReignTitle(reignTitle);
}

int AncientBooks::Year::GetYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return year;
}

std::vector<int> AncientBooks::Year::GetUnorthodoxReignTitle() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return unorthodoxReignTitle;
}

int AncientBooks::Year::GetUnorthodoxReignTitleCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(unorthodoxReignTitle.size());
}

int AncientBooks::Year::GetUnorthodoxReignTitle(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return unorthodoxReignTitle.at(index);
}

std::vector<int>::const_iterator AncientBooks::Year::GetUnorthodoxReignTitleBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return unorthodoxReignTitle.cbegin();
}

std::vector<int>::const_iterator AncientBooks::Year::GetUnorthodoxReignTitleEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return unorthodoxReignTitle.cend();
}

std::vector<int> AncientBooks::Year::GetUnorthodoxYear() const
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

std::vector<int>::const_iterator AncientBooks::Year::GetUnorthodoxYearBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return unorthodoxYear.cbegin();
}

std::vector<int>::const_iterator AncientBooks::Year::GetUnorthodoxYearEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return unorthodoxYear.cend();
}

