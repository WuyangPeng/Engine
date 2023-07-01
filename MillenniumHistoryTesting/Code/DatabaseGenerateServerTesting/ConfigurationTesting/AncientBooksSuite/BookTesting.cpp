///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/26 23:05)

#include "BookTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Book.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/BookContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerBaseTesting::BookTesting::BookTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream }, ancientBooksContainer{ ancientBooksContainer }
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
    const auto bookContainer = ancientBooksContainer.GetBookContainer();

    for (const auto& article : bookContainer->GetContainer())
    {
        ASSERT_GREATER(article->GetGenus(), 0);
        ASSERT_UNEQUAL_NULL_PTR(article->GetGenus(ancientBooksContainer));

        ASSERT_FALSE_USE_MESSAGE(article->GetAuthor().empty(), "id = " + std::to_string(article->GetId()));
        ASSERT_FALSE(article->GetAuthor(ancientBooksContainer).empty());
        ASSERT_EQUAL(article->GetAuthor(ancientBooksContainer).size(), article->GetAuthor().size());

        ASSERT_EQUAL(article->GetAnnotator(ancientBooksContainer).size(), article->GetAnnotator().size());
        ASSERT_EQUAL(article->GetCountry(ancientBooksContainer).size(), article->GetCountry().size());
        ASSERT_EQUAL(article->GetPerson(ancientBooksContainer).size(), article->GetPerson().size());
    }
}

void DatabaseGenerateServerBaseTesting::BookTesting::EffectiveTest()
{
    const auto bookContainer = ancientBooksContainer.GetBookContainer();

    for (const auto& article : bookContainer->GetContainer())
    {
        ASSERT_FALSE(article->GetName().empty());
        ASSERT_GREATER_EQUAL(article->GetVolume(), -2);

        ASSERT_GREATER_EQUAL_USE_MESSAGE(article->GetAuthor().size(), article->GetAuthorDescribe().size(), "id = " + std::to_string(article->GetId()));

        ASSERT_GREATER_EQUAL_USE_MESSAGE(article->GetAnnotator().size(), article->GetAnnotateDescribe().size(), "id = " + std::to_string(article->GetId()));

        const auto unansweredQuestion = article->GetUnansweredQuestion();

        for (const auto& element : unansweredQuestion)
        {
            ASSERT_TRUE(element == SYSTEM_TEXT("author") || element == SYSTEM_TEXT("annotator"));
        }

        ASSERT_EQUAL(article->GetId() / 1000, article->GetGenus());
    }
}
