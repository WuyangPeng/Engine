///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 09:39)

#ifndef SYSTEM_TESTING_HELPER_SUITE_MAKE_WORD_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_MAKE_WORD_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>

namespace System
{
    class MakeWordTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MakeWordTesting;
        using ParentType = UnitTest;

    public:
        explicit MakeWordTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void MakeWordTest();
        NODISCARD bool ReverseMakeWordTest();

    private:
        static constexpr WindowsWord makeWordShiftNum{ 8 };
        static constexpr WindowsDWord reverseMakeWordShiftNum{ 16 };
        static constexpr WindowsDWord maxReverseMakeWord{ 1 << reverseMakeWordShiftNum };

        std::default_random_engine randomEngine;
        std::uniform_int_distribution<WindowsDWordPtrSizeType> distribution;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_MAKE_WORD_TESTING_H
