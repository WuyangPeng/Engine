///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/23 18:58)

#ifndef DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_REIGN_TITLE_TESTING_H
#define DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_REIGN_TITLE_TESTING_H

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/AncientBooksContainer.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateServerBaseTesting
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

#endif  // DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_REIGN_TITLE_TESTING_H