/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/08 09:57)

#ifndef SYSTEM_TESTING_HELPER_SUITE_MAKE_WORD_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_MAKE_WORD_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>

namespace System
{
    /// @brief ����MakeWord��GetLowWord��GetHighWord������
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
        void DoMakeWordTest(int high, int low);

        void MakeWordTest();
        NODISCARD bool ReverseMakeWordTest();

    private:
        using DistributionType = std::uniform_int_distribution<WindowsWord>;

    private:
        static constexpr WindowsWord makeWordShiftNum{ 8 };
        static constexpr WindowsDWord reverseMakeWordShiftNum{ 16 };
        static constexpr WindowsDWord maxReverseMakeWord{ 1 << reverseMakeWordShiftNum };

        std::default_random_engine randomEngine;
        DistributionType distribution;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_MAKE_WORD_TESTING_H
