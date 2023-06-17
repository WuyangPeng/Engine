/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "AncientBooksContainer.h"
#include "Calendar.h"
#include "CountryContainer.h"
#include "YearContainer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVRowDetail.h"

using namespace std::literals;

AncientBooks::Calendar::Calendar(const CoreTools::CSVRow& csvRow)
    : ParentType{},
      id{ csvRow.GetInt(SYSTEM_TEXT("id"s)) },
      name{ csvRow.GetString(SYSTEM_TEXT("name"s)) },
      alias{ csvRow.GetStringArray(SYSTEM_TEXT("alias"s)) },
      source{ csvRow.GetIntArray(SYSTEM_TEXT("source"s)) },
      publication{ csvRow.GetString(SYSTEM_TEXT("publication"s)) },
      creator{ csvRow.GetIntArray(SYSTEM_TEXT("creator"s)) },
      formulate{ csvRow.GetInt(SYSTEM_TEXT("formulate"s)) },
      country{ csvRow.GetInt(SYSTEM_TEXT("country"s)) },
      begin{ csvRow.GetInt(SYSTEM_TEXT("begin"s)) },
      end{ csvRow.GetInt(SYSTEM_TEXT("end"s)) },
      againBegin{ csvRow.GetInt(SYSTEM_TEXT("againBegin"s)) },
      againEnd{ csvRow.GetInt(SYSTEM_TEXT("againEnd"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, Calendar)

int AncientBooks::Calendar::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int AncientBooks::Calendar::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

System::String AncientBooks::Calendar::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name;
}

std::vector<System::String> AncientBooks::Calendar::GetAlias() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return alias;
}

int AncientBooks::Calendar::GetAliasCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(alias.size());
}

System::String AncientBooks::Calendar::GetAlias(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return alias.at(index);
}

std::vector<System::String>::const_iterator AncientBooks::Calendar::GetAliasBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return alias.cbegin();
}

std::vector<System::String>::const_iterator AncientBooks::Calendar::GetAliasEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return alias.cend();
}

std::vector<int> AncientBooks::Calendar::GetSource() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return source;
}

int AncientBooks::Calendar::GetSourceCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(source.size());
}

int AncientBooks::Calendar::GetSource(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return source.at(index);
}

std::vector<int>::const_iterator AncientBooks::Calendar::GetSourceBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return source.cbegin();
}

std::vector<int>::const_iterator AncientBooks::Calendar::GetSourceEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return source.cend();
}

System::String AncientBooks::Calendar::GetPublication() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return publication;
}

std::vector<int> AncientBooks::Calendar::GetCreator() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return creator;
}

int AncientBooks::Calendar::GetCreatorCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(creator.size());
}

int AncientBooks::Calendar::GetCreator(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return creator.at(index);
}

std::vector<int>::const_iterator AncientBooks::Calendar::GetCreatorBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return creator.cbegin();
}

std::vector<int>::const_iterator AncientBooks::Calendar::GetCreatorEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return creator.cend();
}

int AncientBooks::Calendar::GetFormulate() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return formulate;
}

std::shared_ptr<const AncientBooks::YearMappingType> AncientBooks::Calendar::GetFormulate(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetYearContainer()->GetYear(formulate);
}

int AncientBooks::Calendar::GetCountry() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return country;
}

std::shared_ptr<const AncientBooks::CountryMappingType> AncientBooks::Calendar::GetCountry(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetCountryContainer()->GetCountry(country);
}

int AncientBooks::Calendar::GetBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return begin;
}

std::shared_ptr<const AncientBooks::YearMappingType> AncientBooks::Calendar::GetBegin(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetYearContainer()->GetYear(begin);
}

int AncientBooks::Calendar::GetEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return end;
}

std::shared_ptr<const AncientBooks::YearMappingType> AncientBooks::Calendar::GetEnd(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetYearContainer()->GetYear(end);
}

int AncientBooks::Calendar::GetAgainBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return againBegin;
}

std::shared_ptr<const AncientBooks::YearMappingType> AncientBooks::Calendar::GetAgainBegin(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetYearContainer()->GetYear(againBegin);
}

int AncientBooks::Calendar::GetAgainEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return againEnd;
}

std::shared_ptr<const AncientBooks::YearMappingType> AncientBooks::Calendar::GetAgainEnd(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetYearContainer()->GetYear(againEnd);
}

