///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/26 23:05)

#include "BookEntityTesting.h"
#include "DatabaseEntityTestingDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Book.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/BookContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/BookEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateServerBaseTesting::BookEntityTesting::BookEntityTesting(const OStreamShared& stream, const BookContainer& bookContainer)
    : ParentType{ stream }, bookContainer{ bookContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, BookEntityTesting)

void DatabaseGenerateServerBaseTesting::BookEntityTesting::SelectOneTest(DatabaseFlush& databaseFlush)
{
    auto index = 0;
    for (const auto& book : bookContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoSelectOneTest, databaseFlush, *book);

        ++index;
        if (index == GetTestLoopCount())
        {
            break;
        }
    }

    databaseFlush.Wait();
}

void DatabaseGenerateServerBaseTesting::BookEntityTesting::SelectAllTest(DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(BookEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  BookEntity::GetDatabaseFieldContainer());

    const auto entityContainer = GetEntityContainer<int32_t, BookEntity>(database);

    for (const auto& book : bookContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_3(DoSelectAllTest, databaseFlush, *book, entityContainer);
    }

    databaseFlush.Wait();
}

void DatabaseGenerateServerBaseTesting::BookEntityTesting::SelectAllSizeTest(const DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(BookEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  BookEntity::GetDatabaseFieldContainer());

    ASSERT_EQUAL(boost::numeric_cast<int>(database.size()), bookContainer.GetContainerSize());

    const auto entityContainer = GetEntityContainer<int32_t, BookEntity>(database);

    for (const auto& book : bookContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *book, entityContainer);
    }
}

void DatabaseGenerateServerBaseTesting::BookEntityTesting::SetEntity(BookEntity& bookEntity, const Book& book)
{
    bookEntity.SetGenus(book.GetGenus());
    bookEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(book.GetName()));
    bookEntity.SetAlias(Convert(book.GetAliasBegin(), book.GetAliasEnd()));
    bookEntity.SetVolume(book.GetVolume());
    bookEntity.SetAuthor(book.GetAuthor());
    bookEntity.SetAuthorNotes(Convert(book.GetAuthorNotesBegin(), book.GetAuthorNotesEnd()));
    bookEntity.SetAnnotator(book.GetAnnotator());
    bookEntity.SetAnnotateNotes(Convert(book.GetAnnotateNotesBegin(), book.GetAnnotateNotesEnd()));
    bookEntity.SetCountry(book.GetCountry());
    bookEntity.SetPerson(book.GetPerson());
    bookEntity.SetUnansweredQuestion(Convert(book.GetUnansweredQuestionBegin(), book.GetUnansweredQuestionEnd()));
}

void DatabaseGenerateServerBaseTesting::BookEntityTesting::DoSelectOneTest(DatabaseFlush& databaseFlush, const Book& book)
{
    const auto database = databaseFlush.SelectOne(BookEntity::GetSelect(databaseFlush.GetWrappersStrategy(), book.GetId()),
                                                  BookEntity::GetDatabaseFieldContainer());

    auto bookEntity = BookEntity::Create(database, databaseFlush.GetWrappersStrategy(), book.GetId());

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, bookEntity, book);

    databaseFlush.ChangeDatabase(book.GetId(), bookEntity.GetModify());
}

void DatabaseGenerateServerBaseTesting::BookEntityTesting::DoSelectAllTest(DatabaseFlush& databaseFlush, const Book& book, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(book.GetId());
    auto bookEntity = result != entityContainer.cend() ? result->second : BookEntity{ databaseFlush.GetWrappersStrategy(), book.GetId() };

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, bookEntity, book);

    databaseFlush.ChangeDatabase(book.GetId(), bookEntity.GetModify());
}

void DatabaseGenerateServerBaseTesting::BookEntityTesting::EqualTest(const Book& book, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(book.GetId());

    ASSERT_UNEQUAL_FAILURE_THROW(result, entityContainer.cend(), "数据库中未找到对应数据。id = " + std::to_string(book.GetId()));

    const auto& bookEntity = result->second;

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
