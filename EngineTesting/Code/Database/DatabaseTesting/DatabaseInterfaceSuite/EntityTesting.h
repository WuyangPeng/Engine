///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/14 16:30)

#ifndef DATABASE_TESTING_DATABASE_INTERFACE_SUITE_ENTITY_TESTING_H
#define DATABASE_TESTING_DATABASE_INTERFACE_SUITE_ENTITY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Database
{
    class EntityTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EntityTesting;
        using ParentType = UnitTest;

    public:
        explicit EntityTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void EntityTest();

        void DoRunUnitTest() override;
    };
}

#endif  // DATABASE_TESTING_DATABASE_INTERFACE_SUITE_ENTITY_TESTING_H