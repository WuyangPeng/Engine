///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 21:24)

#ifndef DATABASE_GENERATE_SERVER_CONFIGURATION_TESTING_DATABASE_ENTITY_SUITE_DAY_ENTITY_TESTING_H
#define DATABASE_GENERATE_SERVER_CONFIGURATION_TESTING_DATABASE_ENTITY_SUITE_DAY_ENTITY_TESTING_H

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/AncientBooksContainer.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateServerBaseTesting
{
    class DayEntityTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = DayEntityTesting;
        using ParentType = UnitTest;

        using AncientBooksContainer = AncientBooks::AncientBooksContainer;

    public:
        DayEntityTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void InitEnvironmentTest();
        void DatabaseFlushTest();

    private:
        AncientBooksContainer ancientBooksContainer;
    };
}

#endif  // DATABASE_GENERATE_SERVER_CONFIGURATION_TESTING_DATABASE_ENTITY_SUITE_DAY_ENTITY_TESTING_H