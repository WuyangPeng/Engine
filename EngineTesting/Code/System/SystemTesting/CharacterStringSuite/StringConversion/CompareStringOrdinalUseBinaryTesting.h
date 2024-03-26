/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:05)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_ORDINAL_USE_BINARY_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_ORDINAL_USE_BINARY_TESTING_H

#include "CompareStringTesting.h"

#include <random>
#include <vector>

namespace System
{
    class CompareStringOrdinalUseBinaryTesting final : public CompareStringTesting
    {
    public:
        using ClassType = CompareStringOrdinalUseBinaryTesting;
        using ParentType = CompareStringTesting;

    public:
        explicit CompareStringOrdinalUseBinaryTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void CompareStringOrdinalUseBinaryTest();
        void CompareStringTest(size_t index);

        void CompareStringEqualTest(const std::wstring& comparesWString);
        void CompareStringOppositeTest(const std::wstring& lhsComparesWString, const std::wstring& rhsComparesWString);

    private:
        using ComparesWStringContainer = std::vector<std::wstring>;

    private:
        ComparesWStringContainer comparesWStrings;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_ORDINAL_USE_BINARY_TESTING_H