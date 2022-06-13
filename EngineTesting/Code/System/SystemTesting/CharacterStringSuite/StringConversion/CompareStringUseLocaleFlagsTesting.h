///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 13:09)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_USE_LOCALE_FLAGS_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_USE_LOCALE_FLAGS_TESTING_H

#include "CompareStringTesting.h"
#include "System/CharacterString/Fwd/CharacterStringFlagsFwd.h"

#include <random>
#include <vector>

namespace System
{
    class CompareStringUseLocaleFlagsTesting final : public CompareStringTesting
    {
    public:
        using ClassType = CompareStringUseLocaleFlagsTesting;
        using ParentType = CompareStringTesting;

    public:
        explicit CompareStringUseLocaleFlagsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void CompareStringUseLocaleFlagsTest();

    private:
        using LanguageLocaleFlagsCollection = std::vector<LanguageLocale>;
        using ComparesFlagsCollection = std::vector<Compares>;
        using ComparesStringCollection = std::vector<String>;

    private:
        LanguageLocaleFlagsCollection languageLocaleFlags;
        ComparesFlagsCollection comparesFlags;
        ComparesStringCollection comparesString;
        size_t maxSize;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_USE_LOCALE_FLAGS_TESTING_H