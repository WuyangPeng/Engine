/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/22 16:52)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_OBJECT_INTERFACE_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_OBJECT_INTERFACE_TESTING_H

#include "Detail/TestObject.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ObjectInterfaceTesting final : public UnitTest
    {
    public:
        using ClassType = ObjectInterfaceTesting;
        using ParentType = UnitTest;

    public:
        explicit ObjectInterfaceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        static constexpr auto uniqueId = 11;
        using TestObjectSharedPtr = std::shared_ptr<TestObject>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ObjectInterfaceTest();

        void BaseTest(const TestObject& testObject);
        void GetObjectByNameTest(const TestObjectSharedPtr& testObject);
        void UniqueIdTest(TestObject& testObject);
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_OBJECT_INTERFACE_TESTING_H