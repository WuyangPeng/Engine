///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.2 (2022/09/20 20:36)

#ifndef SYSTEM_TESTING_HELPER_SUITE_MAKE_LCID_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_MAKE_LCID_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>

namespace System
{
    class MakeLanguageCIDTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MakeLanguageCIDTesting;
        using ParentType = UnitTest;

    public:
        explicit MakeLanguageCIDTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool MakeLanguageCIDTest();

    private:
        static constexpr WindowsWord maxSortID{ 0x4 };
        static constexpr WindowsWord maxLanguageShiftNum{ 16 };
        static constexpr WindowsWord maxLanguageID{ (1 << maxLanguageShiftNum) - 1 };

        std::default_random_engine randomEngine;
        std::uniform_int_distribution<WindowsWord> sortDistribution;
        std::uniform_int_distribution<WindowsWord> languageDistribution;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_MAKE_LCID_TESTING_H
