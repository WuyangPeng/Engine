///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 16:15)

#ifndef DATABASE_TESTING_SQL_INTERFACE_SUITE_COLLECTION_TESTING_H
#define DATABASE_TESTING_SQL_INTERFACE_SUITE_COLLECTION_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Database
{
    class CollectionTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(CollectionTesting);

    private:
        void MainTest();

        void NullCollectionTest();

        void DoRunUnitTest() override;
    };
}

#endif  // DATABASE_TESTING_SQL_INTERFACE_SUITE_COLLECTION_TESTING_H