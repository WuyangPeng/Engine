/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/22 16:53)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_TESTING_H

#include "Detail/TestObject.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ObjectTesting final : public UnitTest
    {
    public:
        using ClassType = ObjectTesting;
        using ParentType = UnitTest;

    public:
        explicit ObjectTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ObjectTest();

        void GetNameTest(const TestObject& testObject);
        void GetObjectByNameTest(const TestObjectSharedPtr& testObject);
        void SetNameTest(TestObject& testObject);
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_TESTING_H