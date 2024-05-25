/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/22 16:53)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_NAME_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_NAME_TESTING_H

#include "CoreTools/ObjectSystems/ObjectName.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ObjectNameTesting final : public UnitTest
    {
    public:
        using ClassType = ObjectNameTesting;
        using ParentType = UnitTest;

    public:
        explicit ObjectNameTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void NameTest();
        void SetNameTest(const ObjectName& objectName0, ObjectName& objectName1, const ObjectName& objectName2);
        void IsExactlyTest(const ObjectName& objectName0, const ObjectName& objectName1, const ObjectName& objectName2);

    private:
        std::string string0;
        std::string string1;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_NAME_TESTING_H