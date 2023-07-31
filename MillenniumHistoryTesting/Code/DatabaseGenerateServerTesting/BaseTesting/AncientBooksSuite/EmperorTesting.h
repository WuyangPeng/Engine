///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/23 17:34)

#ifndef DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_EMPEROR_TESTING_H
#define DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_EMPEROR_TESTING_H

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/AncientBooksContainer.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateServerBaseTesting
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

#endif  // DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_EMPEROR_TESTING_H