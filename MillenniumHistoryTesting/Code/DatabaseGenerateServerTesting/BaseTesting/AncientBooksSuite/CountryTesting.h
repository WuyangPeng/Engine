///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/23 16:42)

#ifndef DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_COUNTRY_TESTING_H
#define DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_COUNTRY_TESTING_H

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/AncientBooksContainer.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateServerBaseTesting
{
    class CountryTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CountryTesting;
        using ParentType = UnitTest;

        using AncientBooksContainer = AncientBooks::AncientBooksContainer;

    public:
        CountryTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Country = AncientBooks::CountryBase;
        using ConstCountryContainerSharedPtr = AncientBooksContainer::ConstCountryContainerSharedPtr;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void MappingTest();
        void EffectiveTest();

        void ImperialCourtMappingTest(const Country& country);
        void BeginMappingTest(const Country& country);
        void EndMappingTest(const Country& country);

        void CategoryTest(const Country& country);
        void UnansweredQuestionTest(const Country& country);
        void IdTest(const Country& country);

    private:
        AncientBooksContainer ancientBooksContainer;
        ConstCountryContainerSharedPtr countryContainer;
    };
}

#endif  // DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_COUNTRY_TESTING_H