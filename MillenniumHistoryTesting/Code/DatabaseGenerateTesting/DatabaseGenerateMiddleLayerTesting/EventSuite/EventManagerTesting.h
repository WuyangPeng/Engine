/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/30 23:01)

#ifndef DATABASE_GENERATE_MIDDLE_LAYER_TESTING_EVENT_MANAGER_TESTING_H
#define DATABASE_GENERATE_MIDDLE_LAYER_TESTING_EVENT_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateMiddleLayerTesting
{
    class EventManagerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EventManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit EventManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void EventManagerTest();
    };
}

#endif  // DATABASE_GENERATE_MIDDLE_LAYER_TESTING_EVENT_MANAGER_TESTING_H