/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/08 09:55)

#ifndef SYSTEM_TESTING_HELPER_SUITE_MAKE_LANGUAGE_CID_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_MAKE_LANGUAGE_CID_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>

namespace System
{
    /// @brief MakeLanguageCid�����Ĳ����׼���
    class MakeLanguageCidTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MakeLanguageCidTesting;
        using ParentType = UnitTest;

    public:
        explicit MakeLanguageCidTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool MakeLanguageCidTest();

    private:
        using DistributionType = std::uniform_int_distribution<WindowsWord>;

    private:
        static constexpr WindowsWord maxSortId{ 0x4 };
        static constexpr WindowsWord maxLanguageShiftNum{ 16 };
        static constexpr WindowsWord maxLanguageId{ (1 << maxLanguageShiftNum) - 1 };

        std::default_random_engine randomEngine;
        DistributionType sortDistribution;
        DistributionType languageDistribution;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_MAKE_LANGUAGE_CID_TESTING_H
