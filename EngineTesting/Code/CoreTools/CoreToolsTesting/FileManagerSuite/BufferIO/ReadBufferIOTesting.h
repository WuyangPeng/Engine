///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/11 19:40)

#ifndef CORE_TOOLS_TESTING_READ_BUFFER_IO_TESTING_H
#define CORE_TOOLS_TESTING_READ_BUFFER_IO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ReadBufferIOTesting final : public UnitTest
    {
    public:
        using ClassType = ReadBufferIOTesting;
        using ParentType = UnitTest;
        using String = System::String;

    public:
        explicit ReadBufferIOTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ReadBufferIOBasisTest();
        void ReadBufferIOReadTest();
        void GetTextTest();

        NODISCARD static std::string GetBufferIOContent();

    private:
        using BufferType = std::vector<char>;
    };
}

#endif  // CORE_TOOLS_TESTING_READ_BUFFER_IO_TESTING_H