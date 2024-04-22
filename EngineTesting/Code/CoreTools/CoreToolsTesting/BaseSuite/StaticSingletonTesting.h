/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/15 14:42)

#ifndef CORE_TOOLS_BASE_SUITE_STATIC_SINGLETON_TESTING_H
#define CORE_TOOLS_BASE_SUITE_STATIC_SINGLETON_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class StaticSingletonTesting final : public UnitTest
    {
    public:
        using ClassType = StaticSingletonTesting;
        using ParentType = UnitTest;

    public:
        explicit StaticSingletonTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void StaticSingletonTest();
    };
}

#endif  // CORE_TOOLS_BASE_SUITE_STATIC_SINGLETON_TESTING_H