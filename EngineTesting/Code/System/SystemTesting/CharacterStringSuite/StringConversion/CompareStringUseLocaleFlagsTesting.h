///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/02 14:40)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_USE_LOCALE_FLAGS_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_USE_LOCALE_FLAGS_TESTING_H

#include "CompareStringUseLocaleTestingBase.h"
#include "System/CharacterString/Fwd/CharacterStringFlagsFwd.h"

namespace System
{
    class CompareStringUseLocaleFlagsTesting final : public CompareStringUseLocaleTestingBase
    {
    public:
        using ClassType = CompareStringUseLocaleFlagsTesting;
        using ParentType = CompareStringUseLocaleTestingBase;

    public:
        explicit CompareStringUseLocaleFlagsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void CompareStringUseLocaleFlagsTest();
        void CompareStringTest(size_t index);

        void CompareStringEqualTest(LanguageLocale languageLocale, Compares compare, const String& comparesString);
        void CompareStringOppositeTest(LanguageLocale languageLocale, Compares compare, const String& lhsComparesString, const String& rhsComparesString);

    private:
        using LanguageLocaleContainer = std::vector<LanguageLocale>;
        using ComparesStringContainer = std::vector<String>;

    private:
        LanguageLocaleContainer languageLocales;
        ComparesStringContainer comparesStrings;
        size_t maxSize;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_USE_LOCALE_FLAGS_TESTING_H