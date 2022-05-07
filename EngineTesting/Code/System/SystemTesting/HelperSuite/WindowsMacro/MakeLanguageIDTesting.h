///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/16 19:49)

#ifndef SYSTEM_TESTING_HELPER_SUITE_MAKE_LANGUAGEID_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_MAKE_LANGUAGEID_TESTING_H

#include "System/Helper/WindowsMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>

namespace System
{
    class MakeLanguageIDTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MakeLanguageIDTesting;
        using ParentType = UnitTest;

    public:
        explicit MakeLanguageIDTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool MakeLanguageIDTest();
        void MakeMaxLanguageIDTest();

    private:
        static constexpr WindowsWord maxPrimaryShiftNum{ 10 };
        static constexpr WindowsWord maxPrimaryID{ (1 << maxPrimaryShiftNum) - 1 };
        static constexpr WindowsWord maxSubID{ 0x15 };

        std::default_random_engine randomEngine;
        std::uniform_int_distribution<WindowsWord> primaryDistribution;
        std::uniform_int_distribution<WindowsWord> subDistribution;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_MAKE_LANGUAGEID_TESTING_H