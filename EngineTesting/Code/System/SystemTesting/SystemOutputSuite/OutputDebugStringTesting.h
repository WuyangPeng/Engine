///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/30 0:02)

#ifndef SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_OUTPUT_DEBUG_STRING_TESTING_H
#define SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_OUTPUT_DEBUG_STRING_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class OutputDebugStringTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OutputDebugStringTesting;
        using ParentType = UnitTest;

    public:
        explicit OutputDebugStringTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void OutputCharToDebugTest() noexcept;
        void OutputWCharToDebugTest() noexcept;
        void OutputTCharToDebugTest() noexcept;
    };
}

#endif  // SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_OUTPUT_DEBUG_STRING_TESTING_H