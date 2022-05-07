///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/16 19:53)

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
        void DoRunUnitTest() final;
        void MainTest();

        void MakeWordTest();
        NODISCARD bool ReverseMakeWordTest();

    private:
        static constexpr WindowsWord makeWordShiftNum{ 8 };
        static constexpr WindowsDWord reverseMakeWordShiftNum{ 16 };
        static constexpr WindowsDWord maxReverseMakeWord{ 1 << reverseMakeWordShiftNum };

        std::default_random_engine randomEngine;
        std::uniform_int_distribution<WindowsPtrDWord> distribution;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_MAKE_WORD_TESTING_H