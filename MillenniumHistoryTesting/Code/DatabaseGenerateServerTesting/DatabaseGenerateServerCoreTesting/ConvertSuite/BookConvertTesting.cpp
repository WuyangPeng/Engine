///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/02 22:34)

#include "BookConvertTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Book.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/BookContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Convert/ConvertEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerCoreTesting::BookConvertTesting::BookConvertTesting(const OStreamShared& stream, const BookContainer& bookContainer)
    : ParentType{ stream }, bookContainer{ bookContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerCoreTesting, BookConvertTesting)

void DatabaseGenerateServerCoreTesting::BookConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateServerCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& book : bookContainer.GetContainer())
    {
        const auto bookEntity = convertEntity.Convert(*book);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *book, bookEntity);
    }
}

void DatabaseGenerateServerCoreTesting::BookConvertTesting::EqualTest(const Book& book, const BookEntity& bookEntity)
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
