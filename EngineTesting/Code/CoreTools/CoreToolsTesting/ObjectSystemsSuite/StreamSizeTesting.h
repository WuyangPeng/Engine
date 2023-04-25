///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/24 15:33)

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
        void MainTest();
        void StreamSizeTest();

        void DoRunUnitTest() override;

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