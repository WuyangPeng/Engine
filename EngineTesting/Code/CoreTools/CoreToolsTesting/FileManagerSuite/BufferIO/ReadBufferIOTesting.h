///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.3 (2021/09/08 13:20)

#ifndef CORE_TOOLS_TESTING_READ_BUFFERIO_TESTING_H
#define CORE_TOOLS_TESTING_READ_BUFFERIO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

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
        void DoRunUnitTest() final;
        void MainTest();

        void ReadBufferIOBasisTest();
        void ReadBufferIOReadTest();
        void GetTextTest();

        NODISCARD static std::string GetBufferIOContent();
    };
}

#endif  // CORE_TOOLS_TESTING_READ_BUFFERIO_TESTING_H