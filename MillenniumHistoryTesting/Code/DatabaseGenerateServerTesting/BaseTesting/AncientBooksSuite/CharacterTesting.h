///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/23 16:24)

#ifndef DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_CHARACTER_TESTING_H
#define DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_CHARACTER_TESTING_H

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/AncientBooksContainer.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateServerBaseTesting
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

#endif  // DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_CHARACTER_TESTING_H