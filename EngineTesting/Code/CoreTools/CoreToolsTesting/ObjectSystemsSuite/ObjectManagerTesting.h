///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/24 14:30)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_MANAGER_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_MANAGER_TESTING_H

#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ObjectManagerTesting final : public UnitTest
    {
    public:
        using ClassType = ObjectManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit ObjectManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void SucceedTest();
        void ExceptionTest();
        void InsertTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_MANAGER_TESTING_H
