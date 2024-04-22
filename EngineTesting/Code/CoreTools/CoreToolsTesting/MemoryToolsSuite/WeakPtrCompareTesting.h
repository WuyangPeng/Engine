﻿/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/22 15:46)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_WEAK_PTR_COMPARE_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_WEAK_PTR_COMPARE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class WeakPtrCompareTesting final : public UnitTest
    {
    public:
        using ClassType = WeakPtrCompareTesting;
        using ParentType = UnitTest;

    public:
        explicit WeakPtrCompareTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void WeakPtrCompareTest();
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_WEAK_PTR_COMPARE_TESTING_H