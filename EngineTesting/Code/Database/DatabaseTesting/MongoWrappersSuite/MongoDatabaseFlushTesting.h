///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.10 (2023/05/29 10:14)

#ifndef DATABASE_TESTING_DATABASE_INTERFACE_SUITE_MONGO_DATABASE_FLUSH_TESTING_H
#define DATABASE_TESTING_DATABASE_INTERFACE_SUITE_MONGO_DATABASE_FLUSH_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Database
{
    class MongoDatabaseFlushTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MongoDatabaseFlushTesting;
        using ParentType = UnitTest;

    public:
        explicit MongoDatabaseFlushTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void ChangeDatabaseTest();
        void DeleteDatabaseTest();
        void SelectOneTest();
        void SelectAllTest();

        void DoRunUnitTest() override;
    };
}

#endif  // DATABASE_TESTING_DATABASE_INTERFACE_SUITE_MONGO_DATABASE_FLUSH_TESTING_H