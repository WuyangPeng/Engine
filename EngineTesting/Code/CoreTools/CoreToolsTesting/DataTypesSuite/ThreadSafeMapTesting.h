///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 11:30)

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
        void MainTest();

        void DoRunUnitTest() override;

        void ThreadSafeMapTest();
        void ThreadSafeMapRemoveTest();

    private:
        using ThreadSafeMapType = ThreadSafeMap<int, int>;

    private:
        ThreadSafeMapType threadSafeMap;
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_THREAD_SAFE_MAP_TESTING_H