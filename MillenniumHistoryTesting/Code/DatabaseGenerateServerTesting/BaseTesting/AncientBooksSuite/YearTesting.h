///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/24 12:16)

#ifndef DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_YEAR_TESTING_H
#define DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_YEAR_TESTING_H

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/AncientBooksContainer.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateServerBaseTesting
{
    class YearTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = YearTesting;
        using ParentType = UnitTest;

        using AncientBooksContainer = AncientBooks::AncientBooksContainer;

    public:
        YearTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Year = AncientBooks::YearBase;
        using ConstYearContainerSharedPtr = AncientBooksContainer::ConstYearContainerSharedPtr;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void MappingTest();

        void SexagenaryCycleMappingTest(const Year& year);
        void ReignTitleMappingTest(const Year& year);
        void UnorthodoxReignTitleMappingTest(const Year& year);
        void UnorthodoxYearMappingTest(const Year& year);

    private:
        AncientBooksContainer ancientBooksContainer;
        ConstYearContainerSharedPtr yearContainer;
    };
}

#endif  // DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_YEAR_TESTING_H