/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/05/06 19:57)

#ifndef CORE_TOOLS_HELPER_SUITE_TESTING_OBJECT_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_TESTING_OBJECT_TESTING_H

#include "CoreTools/CoreToolsTesting/HelperSuite/Detail/TestingObject.h"
#include "CoreTools/ObjectSystems/ConstObjectAssociated.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class TestingObjectTesting final : public UnitTest
    {
    public:
        using ClassType = TestingObjectTesting;
        using ParentType = UnitTest;

    public:
        explicit TestingObjectTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using ConstObjectAssociated = ConstObjectAssociated<TestingObject>;
        static constexpr auto bufferSize = 256;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SaveStreamTest();
        void LoadStreamTest();
        void LinkStreamTest();
        void GetStreamingSizeTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_TESTING_OBJECT_TESTING_H