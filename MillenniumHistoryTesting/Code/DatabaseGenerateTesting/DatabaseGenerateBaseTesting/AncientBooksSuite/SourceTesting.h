/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/22 23:12)

#ifndef DATABASE_GENERATE_BASE_TESTING_ANCIENT_BOOKS_SUITE_SOURCE_TESTING_H
#define DATABASE_GENERATE_BASE_TESTING_ANCIENT_BOOKS_SUITE_SOURCE_TESTING_H

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/AncientBooksContainer.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateBaseTesting
{
    class SourceTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SourceTesting;
        using ParentType = UnitTest;

        using AncientBooksContainer = AncientBooks::AncientBooksContainer;

    public:
        SourceTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Source = AncientBooks::SourceBase;
        using ConstSourceContainerSharedPtr = AncientBooksContainer::ConstSourceContainerSharedPtr;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void EffectiveTest();

        void NameTest(const Source& source);

    private:
        AncientBooksContainer ancientBooksContainer;
        ConstSourceContainerSharedPtr sourceContainer;
    };
}

#endif  // DATABASE_GENERATE_BASE_TESTING_ANCIENT_BOOKS_SUITE_SOURCE_TESTING_H