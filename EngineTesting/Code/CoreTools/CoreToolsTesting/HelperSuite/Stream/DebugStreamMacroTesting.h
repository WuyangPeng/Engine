/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/14 00:02)

#ifndef CORE_TOOLS_HELPER_SUITE_DEBUG_STREAM_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_DEBUG_STREAM_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class DebugStreamMacroTesting final : public UnitTest
    {
    public:
        using ClassType = DebugStreamMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit DebugStreamMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        static constexpr auto bufferSize = 256;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SaveStreamTest();
        void LoadStreamTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_DEBUG_STREAM_MACRO_TESTING_H