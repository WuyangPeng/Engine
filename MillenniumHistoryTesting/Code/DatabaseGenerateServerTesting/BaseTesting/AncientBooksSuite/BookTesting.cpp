///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/21 22:47)

#include "BookTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Book.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/BookContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerBaseTesting::BookTesting::BookTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream },
      ancientBooksContainer{ ancientBooksContainer },
      bookContainer{ ancientBooksContainer.GetBookContainer() }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, BookTesting)

void DatabaseGenerateServerBaseTesting::BookTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateServerBaseTesting::BookTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MappingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateServerBaseTesting::BookTesting::MappingTest()
{
    for (const auto& book : bookContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(GenusMappingTest, *book);
        ASSERT_NOT_THROW_EXCEPTION_1(AuthorMappingTest, *book);
        ASSERT_NOT_THROW_EXCEPTION_1(ContainerMappingTest, *book);
    }
}

void DatabaseGenerateServerBaseTesting::BookTesting::GenusMappingTest(const Book& book)
{
    ASSERT_GREATER(book.GetGenus(), 0);
    ASSERT_UNEQUAL_NULL_PTR(book.GetGenus(ancientBooksContainer));
}

void DatabaseGenerateServerBaseTesting::BookTesting::AuthorMappingTest(const Book& book)
{
    ASSERT_FALSE_USE_MESSAGE(book.GetAuthor().empty(), "id = " + std::to_string(book.GetId()));
    ASSERT_FALSE(book.GetAuthor(ancientBooksContainer).empty());
    ASSERT_EQUAL(book.GetAuthor(ancientBooksContainer).size(), book.GetAuthor().size());
}

void DatabaseGenerateServerBaseTesting::BookTesting::ContainerMappingTest(const Book& book)
{
    ASSERT_EQUAL(book.GetAnnotator(ancientBooksContainer).size(), book.GetAnnotator().size());
    ASSERT_EQUAL(book.GetCountry(ancientBooksContainer).size(), book.GetCountry().size());
    ASSERT_EQUAL(book.GetPerson(ancientBooksContainer).size(), book.GetPerson().size());
}

void DatabaseGenerateServerBaseTesting::BookTesting::EffectiveTest()
{
    for (const auto& book : bookContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(BookTest, *book);
        ASSERT_NOT_THROW_EXCEPTION_1(UnansweredQuestionTest, *book);
        ASSERT_NOT_THROW_EXCEPTION_1(IdTest, *book);
    }
}

void DatabaseGenerateServerBaseTesting::BookTesting::BookTest(const Book& book)
{
    ASSERT_FALSE(book.GetName().empty());
    ASSERT_GREATER_EQUAL(book.GetVolume(), -2);

    ASSERT_GREATER_EQUAL_USE_MESSAGE(book.GetAuthor().size(), book.GetAuthorNotes().size(), "id = " + std::to_string(book.GetId()));

    ASSERT_GREATER_EQUAL_USE_MESSAGE(book.GetAnnotator().size(), book.GetAnnotateNotes().size(), "id = " + std::to_string(book.GetId()));
}

void DatabaseGenerateServerBaseTesting::BookTesting::UnansweredQuestionTest(const Book& book)
{
    const auto unansweredQuestion = book.GetUnansweredQuestion();

    for (const auto& element : unansweredQuestion)
    {
        ASSERT_TRUE(element == SYSTEM_TEXT("author") || element == SYSTEM_TEXT("annotator"));
    }
}

void DatabaseGenerateServerBaseTesting::BookTesting::IdTest(const Book& book)
{
    ASSERT_EQUAL(book.GetId() / 1000, book.GetGenus());
}
