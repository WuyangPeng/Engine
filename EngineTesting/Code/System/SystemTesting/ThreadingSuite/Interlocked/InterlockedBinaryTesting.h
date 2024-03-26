/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:03)

#ifndef SYSTEM_THREADING_SUITE_INTERLOCKED_BINARY_TESTING_H
#define SYSTEM_THREADING_SUITE_INTERLOCKED_BINARY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class InterlockedBinaryTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = InterlockedBinaryTesting;
        using ParentType = UnitTest;

    public:
        explicit InterlockedBinaryTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        template <typename T>
        void InterlockedBinaryTest();
    };
}

#endif  // SYSTEM_THREADING_SUITE_INTERLOCKED_BINARY_TESTING_H