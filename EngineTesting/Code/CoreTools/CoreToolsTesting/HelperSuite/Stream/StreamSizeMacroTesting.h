///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/19 14:08)

#ifndef CORE_TOOLS_HELPER_SUITE_STREAM_SIZE_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_STREAM_SIZE_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class StreamSizeMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = StreamSizeMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit StreamSizeMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void Int16StreamTest();
        void PtrStreamTest();
        void SharedPtrStreamTest();
        void BoolStreamTest();
        void EnumStreamTest();
        void StringStreamTest();
        void ConstCharStreamTest();
        void VectorStreamTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_STREAM_SIZE_MACRO_TESTING_H