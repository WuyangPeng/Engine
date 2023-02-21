///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 15:36)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_INIT_TERM_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_INIT_TERM_TESTING_H

#include "CoreTools/Helper/InitializeTerminatorMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class InitTermTesting : public UnitTest
    {
    public:
        using ClassType = InitTermTesting;
        using ParentType = UnitTest;

    public:
        explicit InitTermTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void InitTermTest() noexcept;

        void DoRunUnitTest() override;

    private:
        static bool initializeCall;
        static bool terminateCall;
        static bool testBegin;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_INIT_TERM_TESTING_H