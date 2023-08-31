///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/01 21:51)

#ifndef DATABASE_GENERATE_SERVER_MIDDLE_LAYER_TESTING_MESSAGE_MANAGER_TESTING_H
#define DATABASE_GENERATE_SERVER_MIDDLE_LAYER_TESTING_MESSAGE_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateServerMiddleLayerTesting
{
    class MessageManagerTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = MessageManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit MessageManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void MessageManagerTest();
    };
}

#endif  // DATABASE_GENERATE_SERVER_MIDDLE_LAYER_TESTING_MESSAGE_MANAGER_TESTING_H