/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/14 00:04)

#ifndef CORE_TOOLS_HELPER_SUITE_TESTING_OBJECT_SIZE_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_TESTING_OBJECT_SIZE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class TestingObjectSizeTesting final : public UnitTest
    {
    public:
        using ClassType = TestingObjectSizeTesting;
        using ParentType = UnitTest;

    public:
        explicit TestingObjectSizeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SaveStreamTest();
        void LoadStreamTest();
        void LinkStreamTest();
        void GetStreamingSizeTest();

    private:
        static constexpr auto bufferSize = 256;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_TESTING_OBJECT_SIZE_TESTING_H