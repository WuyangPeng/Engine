///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/28 21:24)

#ifndef DATABASE_GENERATE_SERVER_CONFIGURATION_TESTING_ANCIENT_BOOKS_SUITE_DAY_TESTING_H
#define DATABASE_GENERATE_SERVER_CONFIGURATION_TESTING_ANCIENT_BOOKS_SUITE_DAY_TESTING_H

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/AncientBooksContainer.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateServerBaseTesting
{
    class DayTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = DayTesting;
        using ParentType = UnitTest;

        using AncientBooksContainer = AncientBooks::AncientBooksContainer;

    public:
        DayTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void EffectiveTest();

    private:
        AncientBooksContainer ancientBooksContainer;
    };
}

#endif  // DATABASE_GENERATE_SERVER_CONFIGURATION_TESTING_ANCIENT_BOOKS_SUITE_DAY_TESTING_H