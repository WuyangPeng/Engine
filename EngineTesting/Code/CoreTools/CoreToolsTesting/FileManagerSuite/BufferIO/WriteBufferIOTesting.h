///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 20:36)

#ifndef CORE_TOOLS_TESTING_WRITE_BUFFER_IO_TESTING_H
#define CORE_TOOLS_TESTING_WRITE_BUFFER_IO_TESTING_H

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

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
        void DoRunUnitTest() override;
        void MainTest();

        void WriteBufferIOBasisTest();
        void WriteBufferIOWriteTest();

        NODISCARD static std::string GetBufferIOContent();

    private:
        using BufferType = std::vector<char>;
    };
}

#endif  // CORE_TOOLS_TESTING_WRITE_BUFFER_IO_TESTING_H