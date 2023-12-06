/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/30 22:04)

#ifndef DATABASE_GENERATE_BASE_TESTING_ANCIENT_BOOKS_SUITE_ANCIENT_BOOKS_CONTAINER_TESTING_H
#define DATABASE_GENERATE_BASE_TESTING_ANCIENT_BOOKS_SUITE_ANCIENT_BOOKS_CONTAINER_TESTING_H

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/AncientBooksContainer.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateBaseTesting
{
    class AncientBooksContainerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AncientBooksContainerTesting;
        using ParentType = UnitTest;

        using AncientBooksContainer = AncientBooks::AncientBooksContainer;

    public:
        explicit AncientBooksContainerTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void ContainerTest();

    private:
        AncientBooksContainer ancientBooksContainer;
    };
}

#endif  // DATABASE_GENERATE_BASE_TESTING_ANCIENT_BOOKS_SUITE_ANCIENT_BOOKS_CONTAINER_TESTING_H