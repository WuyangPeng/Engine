/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/22 16:55)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_STREAM_SIZE_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_STREAM_SIZE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class StreamSizeTesting final : public UnitTest
    {
    public:
        using ClassType = StreamSizeTesting;
        using ParentType = UnitTest;

    public:
        explicit StreamSizeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void StreamSizeTest();

        void Int16StreamTest();
        void ObjectAssociatedTest();
        void BoolStreamTest();
        void EnumStreamTest();
        void StringStreamTest();
        void ConstCharStreamTest();
        void VectorStreamTest();
        void VectorStringStreamTest();
        void VectorConstCharStreamTest();
        void VectorObjectAssociatedTest();
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_STREAM_SIZE_TESTING_H