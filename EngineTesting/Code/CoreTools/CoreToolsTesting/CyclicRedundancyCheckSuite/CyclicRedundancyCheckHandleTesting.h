///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 14:11)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SUITE_CYCLIC_REDUNDANCY_CHECK_HANDLE_TESTING_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SUITE_CYCLIC_REDUNDANCY_CHECK_HANDLE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CyclicRedundancyCheckHandleTesting : public UnitTest
    {
    public:
        using ClassType = CyclicRedundancyCheckHandleTesting;
        using ParentType = UnitTest;

    public:
        explicit CyclicRedundancyCheckHandleTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void HandleTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SUITE_CYCLIC_REDUNDANCY_CHECK_HANDLE_TESTING_H
