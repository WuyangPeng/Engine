///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/17 18:12)

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
