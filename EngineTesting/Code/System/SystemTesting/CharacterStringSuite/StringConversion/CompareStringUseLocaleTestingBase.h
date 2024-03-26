/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:05)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_USE_LOCALE_TESTING_BASE_H
#define SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_USE_LOCALE_TESTING_BASE_H

#include "CompareStringTesting.h"

#include <random>
#include <vector>

namespace System
{
    class CompareStringUseLocaleTestingBase : public CompareStringTesting
    {
    public:
        using ClassType = CompareStringUseLocaleTestingBase;
        using ParentType = CompareStringTesting;

    public:
        explicit CompareStringUseLocaleTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        NODISCARD size_t GetComparesSize() const noexcept;
        void RandomShuffleCompares(std::default_random_engine& randomEngine);
        NODISCARD Compares GetCompares(size_t index) const;

    private:
        using ComparesContainer = std::vector<Compares>;

    private:
        ComparesContainer compares;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_USE_LOCALE_TESTING_BASE_H