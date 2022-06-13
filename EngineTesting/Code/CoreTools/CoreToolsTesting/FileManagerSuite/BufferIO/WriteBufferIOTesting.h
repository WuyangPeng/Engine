///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:51)

#ifndef CORE_TOOLS_TESTING_WRITE_BUFFERIO_TESTING_H
#define CORE_TOOLS_TESTING_WRITE_BUFFERIO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include <vector>

namespace CoreTools
{
    class WriteBufferIOTesting final : public UnitTest
    {
    public:
        using ClassType = WriteBufferIOTesting;
        using ParentType = UnitTest;
        using String = System::String;

    public:
        explicit WriteBufferIOTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void WriteBufferIOBasisTest();
        void WriteBufferIOWriteTest();

        NODISCARD static std::string GetBufferIOContent();
    };
}

#endif  // CORE_TOOLS_TESTING_WRITE_BUFFERIO_TESTING_H