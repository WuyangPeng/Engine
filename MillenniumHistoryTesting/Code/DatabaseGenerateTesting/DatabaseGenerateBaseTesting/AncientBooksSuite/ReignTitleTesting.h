/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/22 23:12)

#ifndef DATABASE_GENERATE_BASE_TESTING_ANCIENT_BOOKS_SUITE_REIGN_TITLE_TESTING_H
#define DATABASE_GENERATE_BASE_TESTING_ANCIENT_BOOKS_SUITE_REIGN_TITLE_TESTING_H

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/AncientBooksContainer.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateBaseTesting
{
    class ReignTitleTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ReignTitleTesting;
        using ParentType = UnitTest;

        using AncientBooksContainer = AncientBooks::AncientBooksContainer;

    public:
        ReignTitleTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using ReignTitle = AncientBooks::ReignTitleBase;
        using ConstReignTitleContainerSharedPtr = AncientBooksContainer::ConstReignTitleContainerSharedPtr;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void MappingTest();
        void EffectiveTest();

        void EmperorMappingTest(const ReignTitle& reignTitle);
        void BeginMappingTest(const ReignTitle& reignTitle);
        void EndMappingTest(const ReignTitle& reignTitle);

        void NameTest(const ReignTitle& reignTitle);
        void IdTest(const ReignTitle& reignTitle);

    private:
        AncientBooksContainer ancientBooksContainer;
        ConstReignTitleContainerSharedPtr reignTitleContainer;
    };
}

#endif  // DATABASE_GENERATE_BASE_TESTING_ANCIENT_BOOKS_SUITE_REIGN_TITLE_TESTING_H