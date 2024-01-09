/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/22 23:11)

#ifndef DATABASE_GENERATE_BASE_TESTING_ANCIENT_BOOKS_SUITE_CHARACTER_TESTING_H
#define DATABASE_GENERATE_BASE_TESTING_ANCIENT_BOOKS_SUITE_CHARACTER_TESTING_H

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/AncientBooksContainer.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateBaseTesting
{
    class CharacterTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CharacterTesting;
        using ParentType = UnitTest;

        using AncientBooksContainer = AncientBooks::AncientBooksContainer;

    public:
        CharacterTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Character = AncientBooks::CharacterBase;
        using ConstCharacterContainerSharedPtr = AncientBooksContainer::ConstCharacterContainerSharedPtr;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void MappingTest();
        void EffectiveTest();

        void CountryMappingTest(const Character& character);
        void IdentityMappingTest(const Character& character);
        void ParentsMappingTest(const Character& character);
        void BirthMappingTest(const Character& character);
        void DeathMappingTest(const Character& character);

        void FullNameTest(const Character& character);
        void UnansweredQuestionTest(const Character& character);
        void IdTest(const Character& character);
        void SexTest(const Character& character);

    private:
        AncientBooksContainer ancientBooksContainer;
        ConstCharacterContainerSharedPtr characterContainer;
    };
}

#endif  // DATABASE_GENERATE_BASE_TESTING_ANCIENT_BOOKS_SUITE_CHARACTER_TESTING_H