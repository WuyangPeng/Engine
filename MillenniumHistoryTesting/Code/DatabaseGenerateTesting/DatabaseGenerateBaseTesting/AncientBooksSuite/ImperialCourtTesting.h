/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:14)

#ifndef DATABASE_GENERATE_BASE_TESTING_ANCIENT_BOOKS_SUITE_IMPERIAL_COURT_TESTING_H
#define DATABASE_GENERATE_BASE_TESTING_ANCIENT_BOOKS_SUITE_IMPERIAL_COURT_TESTING_H

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/AncientBooksContainer.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateBaseTesting
{
    class ImperialCourtTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ImperialCourtTesting;
        using ParentType = UnitTest;

        using AncientBooksContainer = AncientBooks::AncientBooksContainer;

    public:
        ImperialCourtTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using ImperialCourt = AncientBooks::ImperialCourtBase;
        using ConstImperialCourtContainerSharedPtr = AncientBooksContainer::ConstImperialCourtContainerSharedPtr;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void MappingTest();
        void EffectiveTest();

        void BeginMappingTest(const ImperialCourt& imperialCourt);
        void EndMappingTest(const ImperialCourt& imperialCourt);

        void CategoryTest(const ImperialCourt& imperialCourt);

    private:
        AncientBooksContainer ancientBooksContainer;
        ConstImperialCourtContainerSharedPtr imperialCourtContainer;
    };
}

#endif  // DATABASE_GENERATE_BASE_TESTING_ANCIENT_BOOKS_SUITE_IMPERIAL_COURT_TESTING_H