/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/25 22:17)

#include "BookConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Book.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/BookContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Convert/ConvertEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateCoreTesting::BookConvertTesting::BookConvertTesting(const OStreamShared& stream, BookContainer bookContainer)
    : ParentType{ stream }, bookContainer{ std::move(bookContainer) }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateCoreTesting, BookConvertTesting)

void DatabaseGenerateCoreTesting::BookConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& book : bookContainer.GetContainer())
    {
        const auto bookEntity = convertEntity.Convert(*book);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *book, bookEntity);
    }
}

void DatabaseGenerateCoreTesting::BookConvertTesting::EqualTest(const Book& book, const BookEntity& bookEntity)
{
    ASSERT_EQUAL(bookEntity.GetGenus(), book.GetGenus());
    ASSERT_EQUAL(bookEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(book.GetName()));
    ASSERT_EQUAL(bookEntity.GetAlias(), Convert(book.GetAliasBegin(), book.GetAliasEnd()));
    ASSERT_EQUAL(bookEntity.GetVolume(), book.GetVolume());
    ASSERT_EQUAL(bookEntity.GetAuthor(), book.GetAuthor());
    ASSERT_EQUAL(bookEntity.GetAuthorNotes(), Convert(book.GetAuthorNotesBegin(), book.GetAuthorNotesEnd()));
    ASSERT_EQUAL(bookEntity.GetAnnotator(), book.GetAnnotator());
    ASSERT_EQUAL(bookEntity.GetAnnotateNotes(), Convert(book.GetAnnotateNotesBegin(), book.GetAnnotateNotesEnd()));
    ASSERT_EQUAL(bookEntity.GetCountry(), book.GetCountry());
    ASSERT_EQUAL(bookEntity.GetPerson(), book.GetPerson());
    ASSERT_EQUAL(bookEntity.GetUnansweredQuestion(), Convert(book.GetUnansweredQuestionBegin(), book.GetUnansweredQuestionEnd()));
}
