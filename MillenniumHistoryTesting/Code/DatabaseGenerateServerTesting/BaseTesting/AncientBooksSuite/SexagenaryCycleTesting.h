///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/23 19:04)

#ifndef DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_SEXAGENARY_CYCLE_ENTITY_TESTING_H
#define DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_SEXAGENARY_CYCLE_ENTITY_TESTING_H

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/AncientBooksContainer.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateServerBaseTesting
{
    class SexagenaryCycleTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SexagenaryCycleTesting;
        using ParentType = UnitTest;

        using AncientBooksContainer = AncientBooks::AncientBooksContainer;

    public:
        SexagenaryCycleTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using SexagenaryCycle = AncientBooks::SexagenaryCycleBase;
        using ConstSexagenaryCycleContainerSharedPtr = AncientBooksContainer::ConstSexagenaryCycleContainerSharedPtr;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void EffectiveTest();

        void HeavenlyTest(const SexagenaryCycle& sexagenaryCycle);
        void BranchTest(const SexagenaryCycle& sexagenaryCycle);
        void NameTest(const SexagenaryCycle& sexagenaryCycle);

    private:
        AncientBooksContainer ancientBooksContainer;
        ConstSexagenaryCycleContainerSharedPtr sexagenaryCycleContainer;
    };
}

#endif  // DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_SEXAGENARY_CYCLE_ENTITY_TESTING_H