///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/06 14:24)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_USE_LOCALE_STRING_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_USE_LOCALE_STRING_TESTING_H

#include "CompareStringTesting.h"
#include "System/CharacterString/Fwd/CharacterStringFlagsFwd.h"

#include <random>
#include <vector>

namespace System
{
    class CompareStringUseLocaleStringTesting final : public CompareStringTesting
    {
    public:
        using ClassType = CompareStringUseLocaleStringTesting;
        using ParentType = CompareStringTesting;

    public:
        explicit CompareStringUseLocaleStringTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void CompareStringUseLocaleStringTest();

    private:
        using LanguageLocaleStringCollection = std::vector<const wchar_t*>;
        using ComparesFlagsCollection = std::vector<Compares>;
        using ComparesWStringCollection = std::vector<std::wstring>;

    private:
        LanguageLocaleStringCollection languageLocaleString;
        ComparesFlagsCollection comparesFlags;
        ComparesWStringCollection wComparesString;
        size_t maxSize;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_USE_LOCALE_STRING_TESTING_H