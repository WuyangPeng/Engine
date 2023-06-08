/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "AncientBooksContainer.h"
#include "Book.h"
#include "GenusContainer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVRowDetail.h"

using namespace std::literals;

AncientBooks::Book::Book(const CoreTools::CSVRow& csvRow)
    : ParentType{},
      id{ csvRow.GetInt(SYSTEM_TEXT("id"s)) },
      genus{ csvRow.GetInt(SYSTEM_TEXT("genus"s)) },
      name{ csvRow.GetString(SYSTEM_TEXT("name"s)) },
      alias{ csvRow.GetStringArray(SYSTEM_TEXT("alias"s)) },
      volume{ csvRow.GetInt(SYSTEM_TEXT("volume"s)) },
      author{ csvRow.GetIntArray(SYSTEM_TEXT("author"s)) },
      authorDescribe{ csvRow.GetStringArray(SYSTEM_TEXT("authorDescribe"s)) },
      annotator{ csvRow.GetIntArray(SYSTEM_TEXT("annotator"s)) },
      annotateDescribe{ csvRow.GetStringArray(SYSTEM_TEXT("annotateDescribe"s)) },
      country{ csvRow.GetIntArray(SYSTEM_TEXT("country"s)) },
      person{ csvRow.GetIntArray(SYSTEM_TEXT("person"s)) },
      unansweredQuestion{ csvRow.GetStringArray(SYSTEM_TEXT("unansweredQuestion"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, Book)

int AncientBooks::Book::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int AncientBooks::Book::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int AncientBooks::Book::GetGenus() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return genus;
}

std::shared_ptr<const AncientBooks::GenusMappingType> AncientBooks::Book::GetGenus(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetGenusContainer()->GetGenus(genus);
}

System::String AncientBooks::Book::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name;
}

std::vector<System::String> AncientBooks::Book::GetAlias() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return alias;
}

int AncientBooks::Book::GetAliasCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(alias.size());
}

System::String AncientBooks::Book::GetAlias(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return alias.at(index);
}

std::vector<System::String>::const_iterator AncientBooks::Book::GetAliasBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return alias.cbegin();
}

std::vector<System::String>::const_iterator AncientBooks::Book::GetAliasEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return alias.cend();
}

int AncientBooks::Book::GetVolume() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return volume;
}

std::vector<int> AncientBooks::Book::GetAuthor() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return author;
}

int AncientBooks::Book::GetAuthorCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(author.size());
}

int AncientBooks::Book::GetAuthor(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return author.at(index);
}

std::vector<int>::const_iterator AncientBooks::Book::GetAuthorBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return author.cbegin();
}

std::vector<int>::const_iterator AncientBooks::Book::GetAuthorEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return author.cend();
}

std::vector<System::String> AncientBooks::Book::GetAuthorDescribe() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return authorDescribe;
}

int AncientBooks::Book::GetAuthorDescribeCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(authorDescribe.size());
}

System::String AncientBooks::Book::GetAuthorDescribe(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return authorDescribe.at(index);
}

std::vector<System::String>::const_iterator AncientBooks::Book::GetAuthorDescribeBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return authorDescribe.cbegin();
}

std::vector<System::String>::const_iterator AncientBooks::Book::GetAuthorDescribeEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return authorDescribe.cend();
}

std::vector<int> AncientBooks::Book::GetAnnotator() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return annotator;
}

int AncientBooks::Book::GetAnnotatorCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(annotator.size());
}

int AncientBooks::Book::GetAnnotator(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return annotator.at(index);
}

std::vector<int>::const_iterator AncientBooks::Book::GetAnnotatorBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return annotator.cbegin();
}

std::vector<int>::const_iterator AncientBooks::Book::GetAnnotatorEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return annotator.cend();
}

std::vector<System::String> AncientBooks::Book::GetAnnotateDescribe() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return annotateDescribe;
}

int AncientBooks::Book::GetAnnotateDescribeCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(annotateDescribe.size());
}

System::String AncientBooks::Book::GetAnnotateDescribe(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return annotateDescribe.at(index);
}

std::vector<System::String>::const_iterator AncientBooks::Book::GetAnnotateDescribeBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return annotateDescribe.cbegin();
}

std::vector<System::String>::const_iterator AncientBooks::Book::GetAnnotateDescribeEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return annotateDescribe.cend();
}

std::vector<int> AncientBooks::Book::GetCountry() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return country;
}

int AncientBooks::Book::GetCountryCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(country.size());
}

int AncientBooks::Book::GetCountry(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return country.at(index);
}

std::vector<int>::const_iterator AncientBooks::Book::GetCountryBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return country.cbegin();
}

std::vector<int>::const_iterator AncientBooks::Book::GetCountryEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return country.cend();
}

std::vector<int> AncientBooks::Book::GetPerson() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return person;
}

int AncientBooks::Book::GetPersonCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(person.size());
}

int AncientBooks::Book::GetPerson(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return person.at(index);
}

std::vector<int>::const_iterator AncientBooks::Book::GetPersonBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return person.cbegin();
}

std::vector<int>::const_iterator AncientBooks::Book::GetPersonEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return person.cend();
}

std::vector<System::String> AncientBooks::Book::GetUnansweredQuestion() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return unansweredQuestion;
}

int AncientBooks::Book::GetUnansweredQuestionCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(unansweredQuestion.size());
}

System::String AncientBooks::Book::GetUnansweredQuestion(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return unansweredQuestion.at(index);
}

std::vector<System::String>::const_iterator AncientBooks::Book::GetUnansweredQuestionBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return unansweredQuestion.cbegin();
}

std::vector<System::String>::const_iterator AncientBooks::Book::GetUnansweredQuestionEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return unansweredQuestion.cend();
}

