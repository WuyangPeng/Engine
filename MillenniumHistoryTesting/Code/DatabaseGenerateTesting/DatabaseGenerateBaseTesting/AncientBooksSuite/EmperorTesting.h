/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/22 23:11)

#ifndef DATABASE_GENERATE_BASE_TESTING_ANCIENT_BOOKS_SUITE_EMPEROR_TESTING_H
#define DATABASE_GENERATE_BASE_TESTING_ANCIENT_BOOKS_SUITE_EMPEROR_TESTING_H

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/AncientBooksContainer.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateBaseTesting
{
    class EmperorTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EmperorTesting;
        using ParentType = UnitTest;

        using AncientBooksContainer = AncientBooks::AncientBooksContainer;

    public:
        EmperorTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Emperor = AncientBooks::EmperorBase;
        using ConstEmperorContainerSharedPtr = AncientBooksContainer::ConstEmperorContainerSharedPtr;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void MappingTest();
        void EffectiveTest();

        void CharacterMappingTest(const Emperor& emperor);
        void BeginMappingTest(const Emperor& emperor);
        void EndMappingTest(const Emperor& emperor);
        void AgainBeginMappingTest(const Emperor& emperor);
        void AgainEndMappingTest(const Emperor& emperor);

        void IdTest(const Emperor& emperor);
        void UnansweredQuestionTest(const Emperor& emperor);

    private:
        AncientBooksContainer ancientBooksContainer;
        ConstEmperorContainerSharedPtr emperorContainer;
    };
}

#endif  // DATABASE_GENERATE_BASE_TESTING_ANCIENT_BOOKS_SUITE_EMPEROR_TESTING_H