///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 13:09)

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
        using ComparesWStringCollection = std::vector<std::wstring>;

    private:
        ComparesWStringCollection wComparesString;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_ORDINAL_USE_BINARY_TESTING_H