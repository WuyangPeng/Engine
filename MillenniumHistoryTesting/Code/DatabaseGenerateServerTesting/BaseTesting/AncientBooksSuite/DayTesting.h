///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/23 17:00)

#ifndef DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_DAY_TESTING_H
#define DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_DAY_TESTING_H

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
        using Day = AncientBooks::DayBase;
        using ConstDayContainerSharedPtr = AncientBooksContainer::ConstDayContainerSharedPtr;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void EffectiveTest();

        void NameTest(const Day& day);

    private:
        AncientBooksContainer ancientBooksContainer;
        ConstDayContainerSharedPtr dayContainer;
    };
}

#endif  // DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_DAY_TESTING_H