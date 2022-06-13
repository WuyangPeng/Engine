///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:57)

#ifndef CORE_TOOLS_TESTING_FILE_BUFFER_TESTING_H
#define CORE_TOOLS_TESTING_FILE_BUFFER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class FileBufferTesting final : public UnitTest
    {
    public:
        using ClassType = FileBufferTesting;
        using ParentType = UnitTest;

    public:
        explicit FileBufferTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ValueTest();
        void DelayCopyTest();
        void BufferTest();
        void ForEachTest();
    };
}

#endif  // CORE_TOOLS_TESTING_FILE_BUFFER_TESTING_H