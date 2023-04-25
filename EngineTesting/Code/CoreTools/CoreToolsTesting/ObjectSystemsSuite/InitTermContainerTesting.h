///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/24 10:22)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_INIT_TERM_CONTAINER_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_INIT_TERM_CONTAINER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class InitTermContainerTesting final : public UnitTest
    {
    public:
        using ClassType = InitTermContainerTesting;
        using ParentType = UnitTest;

    public:
        explicit InitTermContainerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();

        void DoRunUnitTest() override;

        static void Initializer() noexcept;
        static void Terminator() noexcept;

    private:
        static bool initializeCall;
        static bool terminateCall;
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_INIT_TERM_CONTAINER_TESTING_H