/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "AncientBooksContainer.h"
#include "BookContainer.h"
#include "CountryContainer.h"
#include "ReignTitleContainer.h"
#include "Version.h"
#include "YearContainer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVRowDetail.h"

using namespace std::literals;

AncientBooks::Version::Version(const CoreTools::CSVRow& csvRow)
    : ParentType{},
      id{ csvRow.GetInt(SYSTEM_TEXT("id"s)) },
      book{ csvRow.GetInt(SYSTEM_TEXT("book"s)) },
      source{ csvRow.GetInt(SYSTEM_TEXT("source"s)) },
      sourceName{ csvRow.GetString(SYSTEM_TEXT("sourceName"s)) },
      country{ csvRow.GetInt(SYSTEM_TEXT("country"s)) },
      reignTitle{ csvRow.GetInt64(SYSTEM_TEXT("reignTitle"s)) },
      year{ csvRow.GetInt(SYSTEM_TEXT("year"s)) },
      version{ csvRow.GetString(SYSTEM_TEXT("version"s)) },
      otherAuthor{ csvRow.GetIntArray(SYSTEM_TEXT("otherAuthor"s)) },
      authorDescribe{ csvRow.GetStringArray(SYSTEM_TEXT("authorDescribe"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, Version)

int AncientBooks::Version::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int AncientBooks::Version::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int AncientBooks::Version::GetBook() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return book;
}

std::shared_ptr<const AncientBooks::BookMappingType> AncientBooks::Version::GetBook(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetBookContainer()->GetBook(book);
}

int AncientBooks::Version::GetSource() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return source;
}

System::String AncientBooks::Version::GetSourceName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return sourceName;
}

int AncientBooks::Version::GetCountry() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return country;
}

std::shared_ptr<const AncientBooks::CountryMappingType> AncientBooks::Version::GetCountry(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetCountryContainer()->GetCountry(country);
}

int64_t AncientBooks::Version::GetReignTitle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return reignTitle;
}

std::shared_ptr<const AncientBooks::ReignTitleMappingType> AncientBooks::Version::GetReignTitle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetReignTitleContainer()->GetReignTitle(reignTitle);
}

int AncientBooks::Version::GetYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return year;
}

std::shared_ptr<const AncientBooks::YearMappingType> AncientBooks::Version::GetYear(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetYearContainer()->GetYear(year);
}

System::String AncientBooks::Version::GetVersion() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return version;
}

std::vector<int> AncientBooks::Version::GetOtherAuthor() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return otherAuthor;
}

int AncientBooks::Version::GetOtherAuthorCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(otherAuthor.size());
}

int AncientBooks::Version::GetOtherAuthor(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return otherAuthor.at(index);
}

std::vector<int>::const_iterator AncientBooks::Version::GetOtherAuthorBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return otherAuthor.cbegin();
}

std::vector<int>::const_iterator AncientBooks::Version::GetOtherAuthorEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return otherAuthor.cend();
}

std::vector<System::String> AncientBooks::Version::GetAuthorDescribe() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return authorDescribe;
}

int AncientBooks::Version::GetAuthorDescribeCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(authorDescribe.size());
}

System::String AncientBooks::Version::GetAuthorDescribe(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return authorDescribe.at(index);
}

std::vector<System::String>::const_iterator AncientBooks::Version::GetAuthorDescribeBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return authorDescribe.cbegin();
}

std::vector<System::String>::const_iterator AncientBooks::Version::GetAuthorDescribeEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return authorDescribe.cend();
}

