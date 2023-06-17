///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	ǧ��ʷ�߲��԰汾��0.9.0.12 (2023/06/14 21:01)

#ifndef DATABASE_GENERATE_SERVER_CONFIGURATION_TESTING_ANCIENT_BOOKS_SUITE_ANCIENT_BOOKS_CONTAINER_TESTING_H
#define DATABASE_GENERATE_SERVER_CONFIGURATION_TESTING_ANCIENT_BOOKS_SUITE_ANCIENT_BOOKS_CONTAINER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateServerBaseTesting
{
    class AncientBooksContainerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AncientBooksContainerTesting;
        using ParentType = UnitTest;

    public:
        explicit AncientBooksContainerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void ContainerTest();
    };
}

#endif  // DATABASE_GENERATE_SERVER_CONFIGURATION_TESTING_ANCIENT_BOOKS_SUITE_ANCIENT_BOOKS_CONTAINER_TESTING_H