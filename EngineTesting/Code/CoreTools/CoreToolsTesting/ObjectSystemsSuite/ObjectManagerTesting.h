/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/22 16:53)

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
        void DoRunUnitTest() override;
        void MainTest();

        void SucceedTest();
        void ExceptionTest();
        void InsertTest();
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_MANAGER_TESTING_H
