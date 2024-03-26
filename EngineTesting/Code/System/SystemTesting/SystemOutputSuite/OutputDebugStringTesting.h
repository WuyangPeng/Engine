/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 12:19)

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
        void DoRunUnitTest() override;
        void MainTest();

        void OutputCharToDebugTest() const noexcept;
        void OutputWCharToDebugTest() const noexcept;
        void OutputTCharToDebugTest() const noexcept;
    };
}

#endif  // SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_OUTPUT_DEBUG_STRING_TESTING_H