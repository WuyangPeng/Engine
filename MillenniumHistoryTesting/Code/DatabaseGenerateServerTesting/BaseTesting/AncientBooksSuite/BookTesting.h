///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/21 22:47)

#ifndef DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_BOOK_TESTING_H
#define DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_BOOK_TESTING_H

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/AncientBooksContainer.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateServerBaseTesting
{
    class BookTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = BookTesting;
        using ParentType = UnitTest;

        using AncientBooksContainer = AncientBooks::AncientBooksContainer;

    public:
        BookTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Book = AncientBooks::BookBase;
        using ConstBookContainerSharedPtr = AncientBooksContainer::ConstBookContainerSharedPtr;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void MappingTest();
        void EffectiveTest();

        void GenusMappingTest(const Book& book);
        void AuthorMappingTest(const Book& book);
        void ContainerMappingTest(const Book& book);

        void BookTest(const Book& book);
        void UnansweredQuestionTest(const Book& book);
        void IdTest(const Book& book);

    private:
        AncientBooksContainer ancientBooksContainer;
        ConstBookContainerSharedPtr bookContainer;
    };
}

#endif  // DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_BOOK_TESTING_H