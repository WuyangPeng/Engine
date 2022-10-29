///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/14 1:16)

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
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void CompareStringOrdinalUseBinaryTest();

    private:
        using ComparesWStringContainer = std::vector<std::wstring>;

    private:
        ComparesWStringContainer wComparesString;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_ORDINAL_USE_BINARY_TESTING_H