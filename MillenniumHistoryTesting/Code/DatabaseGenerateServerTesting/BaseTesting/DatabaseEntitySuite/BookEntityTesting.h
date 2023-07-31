///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/26 23:05)

#ifndef DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_BOOK_ENTITY_TESTING_H
#define DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_BOOK_ENTITY_TESTING_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/BookContainer.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/DatabaseEntityFwd.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

namespace DatabaseGenerateServerBaseTesting
{
    class BookEntityTesting final : public DatabaseEntityTesting
    {
    public:
        using ClassType = BookEntityTesting;
        using ParentType = DatabaseEntityTesting;

        using BookContainer = AncientBooks::BookContainer;

    public:
        BookEntityTesting(const OStreamShared& stream, const BookContainer& bookContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Book = AncientBooks::BookBase;
        using BookEntity = DatabaseEntity::BookEntity;
        using EntityContainer = std::map<int32_t, BookEntity>;

    private:
        void SelectOneTest(DatabaseFlush& databaseFlush) override;
        void SelectAllTest(DatabaseFlush& databaseFlush) override;
        void SelectAllSizeTest(const DatabaseFlush& databaseFlush) override;

        void SetEntity(BookEntity& bookEntity, const Book& book);

        void DoSelectOneTest(DatabaseFlush& databaseFlush, const Book& book);
        void DoSelectAllTest(DatabaseFlush& databaseFlush, const Book& book, const EntityContainer& entityContainer);
        void EqualTest(const Book& book, const EntityContainer& entityContainer);

    private:
        BookContainer bookContainer;
    };
}

#endif  // DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_BOOK_ENTITY_TESTING_H