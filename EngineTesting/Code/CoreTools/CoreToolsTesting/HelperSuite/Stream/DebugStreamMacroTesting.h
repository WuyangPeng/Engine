///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/19 14:08)

#ifndef CORE_TOOLS_HELPER_SUITE_DEBUG_STREAM_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_DEBUG_STREAM_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class DebugStreamMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = DebugStreamMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit DebugStreamMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SaveStreamTest();
        void LoadStreamTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_DEBUG_STREAM_MACRO_TESTING_H