/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/22 23:11)

#ifndef DATABASE_GENERATE_BASE_TESTING_ANCIENT_BOOKS_SUITE_IDENTITY_TESTING_H
#define DATABASE_GENERATE_BASE_TESTING_ANCIENT_BOOKS_SUITE_IDENTITY_TESTING_H

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/AncientBooksContainer.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateBaseTesting
{
    class IdentityTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = IdentityTesting;
        using ParentType = UnitTest;

        using AncientBooksContainer = AncientBooks::AncientBooksContainer;

    public:
        IdentityTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Identity = AncientBooks::IdentityBase;
        using ConstIdentityContainerSharedPtr = AncientBooksContainer::ConstIdentityContainerSharedPtr;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void EffectiveTest();

        void IdentityTest(const Identity& identity);

    private:
        AncientBooksContainer ancientBooksContainer;
        ConstIdentityContainerSharedPtr identityContainer;
    };
}

#endif  // DATABASE_GENERATE_BASE_TESTING_ANCIENT_BOOKS_SUITE_IDENTITY_TESTING_H