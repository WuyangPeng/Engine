///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/25 16:15)

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