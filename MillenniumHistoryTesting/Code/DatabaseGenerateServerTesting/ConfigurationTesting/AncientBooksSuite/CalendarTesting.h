///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/27 22:45)

#ifndef DATABASE_GENERATE_SERVER_CONFIGURATION_TESTING_ANCIENT_BOOKS_SUITE_CALENDAR_TESTING_H
#define DATABASE_GENERATE_SERVER_CONFIGURATION_TESTING_ANCIENT_BOOKS_SUITE_CALENDAR_TESTING_H

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/AncientBooksContainer.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateServerBaseTesting
{
    class CalendarTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CalendarTesting;
        using ParentType = UnitTest;

        using AncientBooksContainer = AncientBooks::AncientBooksContainer;

    public:
        CalendarTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void MappingTest();
        void EffectiveTest();

    private:
        AncientBooksContainer ancientBooksContainer;
    };
}

#endif  // DATABASE_GENERATE_SERVER_CONFIGURATION_TESTING_ANCIENT_BOOKS_SUITE_CALENDAR_TESTING_H