///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/23 19:06)

#ifndef DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_SOURCE_TESTING_H
#define DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_SOURCE_TESTING_H

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/AncientBooksContainer.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateServerBaseTesting
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

#endif  // DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_SOURCE_TESTING_H