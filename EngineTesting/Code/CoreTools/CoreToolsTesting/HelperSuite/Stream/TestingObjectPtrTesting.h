/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/06 19:55)

#ifndef CORE_TOOLS_HELPER_SUITE_TESTING_OBJECT_PTR_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_TESTING_OBJECT_PTR_TESTING_H

#include "CoreTools/CoreToolsTesting/HelperSuite/Detail/TestingObjectPtr.h"
#include "CoreTools/ObjectSystems/ConstObjectAssociated.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class TestingObjectPtrTesting final : public UnitTest
    {
    public:
        using ClassType = TestingObjectPtrTesting;
        using ParentType = UnitTest;

    public:
        explicit TestingObjectPtrTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using ConstObjectAssociated = ConstObjectAssociated<TestingObjectPtr>;
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

#endif  // CORE_TOOLS_HELPER_SUITE_TESTING_OBJECT_PTR_TESTING_H