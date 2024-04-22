/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/19 15:39)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_THREAD_SAFE_MAP_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_THREAD_SAFE_MAP_TESTING_H

#include "CoreTools/DataTypes/ThreadSafeMap.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ThreadSafeMapTesting final : public UnitTest
    {
    public:
        using ClassType = ThreadSafeMapTesting;
        using ParentType = UnitTest;

    public:
        explicit ThreadSafeMapTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ThreadSafeMapTest();
        void ThreadSafeMapRemoveTest();

    private:
        using ThreadSafeMapType = ThreadSafeMap<int, int>;

    private:
        ThreadSafeMapType threadSafeMap;
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_THREAD_SAFE_MAP_TESTING_H