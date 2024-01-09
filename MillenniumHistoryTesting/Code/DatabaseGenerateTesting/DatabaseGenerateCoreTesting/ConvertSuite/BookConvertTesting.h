/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/25 22:11)

#ifndef DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_BOOK_CONVERT_TESTING_H
#define DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_BOOK_CONVERT_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/BookContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateCoreTesting
{
    class BookConvertTesting final : public ConvertTesting
    {
    public:
        using ClassType = BookConvertTesting;
        using ParentType = ConvertTesting;

        using BookContainer = AncientBooks::BookContainer;

    public:
        BookConvertTesting(const OStreamShared& stream, BookContainer bookContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Book = AncientBooks::BookBase;
        using BookEntity = DatabaseEntity::BookEntity;

    private:
        void ConvertTest(const DatabaseFlushSharedPtr& databaseFlush) override;
        void EqualTest(const Book& book, const BookEntity& bookEntity);

    private:
        BookContainer bookContainer;
    };
}

#endif  // DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_BOOK_CONVERT_TESTING_H