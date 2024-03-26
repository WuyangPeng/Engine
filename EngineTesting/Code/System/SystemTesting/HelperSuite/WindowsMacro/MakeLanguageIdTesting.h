/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/08 09:57)

#ifndef SYSTEM_TESTING_HELPER_SUITE_MAKE_LANGUAGE_ID_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_MAKE_LANGUAGE_ID_TESTING_H

#include "System/Helper/WindowsMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>

namespace System
{
    /// @brief MakeLanguageId��GetPrimaryLanguageId��GetSubLanguageId�����Ĳ����׼���
    class MakeLanguageIdTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MakeLanguageIdTesting;
        using ParentType = UnitTest;

    public:
        explicit MakeLanguageIdTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool MakeLanguageIdTest();
        void MakeMaxLanguageIdTest();

    private:
        using DistributionType = std::uniform_int_distribution<WindowsWord>;

    private:
        static constexpr WindowsWord maxPrimaryShiftNum{ 10 };
        static constexpr WindowsWord maxPrimaryId{ (1 << maxPrimaryShiftNum) - 1 };
        static constexpr WindowsWord maxSubId{ 0x15 };

        std::default_random_engine randomEngine;
        DistributionType primaryDistribution;
        DistributionType subDistribution;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_MAKE_LANGUAGE_ID_TESTING_H
