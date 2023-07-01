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
#include "CharacterContainer.h"
#include "CountryContainer.h"
#include "GenusContainer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVRowDetail.h"

using namespace std::literals;

AncientBooks::Book::Book(const CSVRow& csvRow)
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

AncientBooks::Book::ConstGenusSharedPtr AncientBooks::Book::GetGenus(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetGenusContainer()->GetGenus(genus);
}

System::String AncientBooks::Book::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name;
}

AncientBooks::Book::StringContainer AncientBooks::Book::GetAlias() const
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

AncientBooks::Book::StringContainerConstIter AncientBooks::Book::GetAliasBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return alias.cbegin();
}

AncientBooks::Book::StringContainerConstIter AncientBooks::Book::GetAliasEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return alias.cend();
}

int AncientBooks::Book::GetVolume() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return volume;
}

AncientBooks::Book::IntContainer AncientBooks::Book::GetAuthor() const
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

AncientBooks::Book::IntContainerConstIter AncientBooks::Book::GetAuthorBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return author.cbegin();
}

AncientBooks::Book::IntContainerConstIter AncientBooks::Book::GetAuthorEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return author.cend();
}

AncientBooks::Book::CharacterContainer AncientBooks::Book::GetAuthor(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    CharacterContainer result{};

    const auto container = csvContainer.GetCharacterContainer();

    for (const auto& element : author)
    {
        result.emplace_back(container->GetCharacter(element));
    }

    return result;
}

AncientBooks::Book::StringContainer AncientBooks::Book::GetAuthorDescribe() const
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

AncientBooks::Book::StringContainerConstIter AncientBooks::Book::GetAuthorDescribeBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return authorDescribe.cbegin();
}

AncientBooks::Book::StringContainerConstIter AncientBooks::Book::GetAuthorDescribeEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return authorDescribe.cend();
}

AncientBooks::Book::IntContainer AncientBooks::Book::GetAnnotator() const
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

AncientBooks::Book::IntContainerConstIter AncientBooks::Book::GetAnnotatorBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return annotator.cbegin();
}

AncientBooks::Book::IntContainerConstIter AncientBooks::Book::GetAnnotatorEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return annotator.cend();
}

AncientBooks::Book::CharacterContainer AncientBooks::Book::GetAnnotator(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    CharacterContainer result{};

    const auto container = csvContainer.GetCharacterContainer();

    for (const auto& element : annotator)
    {
        result.emplace_back(container->GetCharacter(element));
    }

    return result;
}

AncientBooks::Book::StringContainer AncientBooks::Book::GetAnnotateDescribe() const
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

AncientBooks::Book::StringContainerConstIter AncientBooks::Book::GetAnnotateDescribeBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return annotateDescribe.cbegin();
}

AncientBooks::Book::StringContainerConstIter AncientBooks::Book::GetAnnotateDescribeEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return annotateDescribe.cend();
}

AncientBooks::Book::IntContainer AncientBooks::Book::GetCountry() const
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

AncientBooks::Book::IntContainerConstIter AncientBooks::Book::GetCountryBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return country.cbegin();
}

AncientBooks::Book::IntContainerConstIter AncientBooks::Book::GetCountryEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return country.cend();
}

AncientBooks::Book::CountryContainer AncientBooks::Book::GetCountry(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    CountryContainer result{};

    const auto container = csvContainer.GetCountryContainer();

    for (const auto& element : country)
    {
        result.emplace_back(container->GetCountry(element));
    }

    return result;
}

AncientBooks::Book::IntContainer AncientBooks::Book::GetPerson() const
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

AncientBooks::Book::IntContainerConstIter AncientBooks::Book::GetPersonBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return person.cbegin();
}

AncientBooks::Book::IntContainerConstIter AncientBooks::Book::GetPersonEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return person.cend();
}

AncientBooks::Book::CharacterContainer AncientBooks::Book::GetPerson(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    CharacterContainer result{};

    const auto container = csvContainer.GetCharacterContainer();

    for (const auto& element : person)
    {
        result.emplace_back(container->GetCharacter(element));
    }

    return result;
}

AncientBooks::Book::StringContainer AncientBooks::Book::GetUnansweredQuestion() const
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

AncientBooks::Book::StringContainerConstIter AncientBooks::Book::GetUnansweredQuestionBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return unansweredQuestion.cbegin();
}

AncientBooks::Book::StringContainerConstIter AncientBooks::Book::GetUnansweredQuestionEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return unansweredQuestion.cend();
}

