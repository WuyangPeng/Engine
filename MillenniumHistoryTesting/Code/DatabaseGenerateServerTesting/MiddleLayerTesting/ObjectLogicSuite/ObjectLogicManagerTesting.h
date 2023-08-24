///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/01 21:51)

#ifndef DATABASE_GENERATE_SERVER_MIDDLE_LAYER_TESTING_OBJECT_LOGIC_MANAGER_TESTING_H
#define DATABASE_GENERATE_SERVER_MIDDLE_LAYER_TESTING_OBJECT_LOGIC_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateServerMiddleLayerTesting
{
    class ObjectLogicManagerTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = ObjectLogicManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit ObjectLogicManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void ObjectLogicManagerTest();
    };
}

#endif  // DATABASE_GENERATE_SERVER_MIDDLE_LAYER_TESTING_OBJECT_LOGIC_MANAGER_TESTING_H