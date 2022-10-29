///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/07 19:22)

#ifndef SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_LANGUAGE_ID_DATA_TESTING_H
#define SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_LANGUAGE_ID_DATA_TESTING_H

#include "System/SystemOutput/Fwd/SystemOutputFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class LanguageIDDataTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = LanguageIDDataTesting;
        using ParentType = UnitTest;

    public:
        explicit LanguageIDDataTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void FlagsTest();
        void DefaultFlagTest() noexcept;

    private:
        using PrimaryLanguageFlagsCollection = std::vector<PrimaryLanguage>;
        using SubLanguageFlagsCollection = std::vector<SubLanguage>;

    private:
        PrimaryLanguageFlagsCollection primaryLanguageFlags;
        SubLanguageFlagsCollection subLanguageFlags;
        size_t maxSize;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_LANGUAGE_ID_DATA_TESTING_H