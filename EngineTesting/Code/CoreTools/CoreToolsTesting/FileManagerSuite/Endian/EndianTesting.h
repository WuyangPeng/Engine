///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.3 (2021/09/03 21:10)

#ifndef CORE_TOOLS_TESTING_ENDIAN_TESTING_H
#define CORE_TOOLS_TESTING_ENDIAN_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class EndianTesting final : public UnitTest
    {
    public:
        using ClassType = EndianTesting;
        using ParentType = UnitTest;

    public:
        explicit EndianTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ByteOrderTest();
        void Swap2ByteOrderTest();
        void Swap4ByteOrderTest();
        void Swap8ByteOrderTest();
    };
}

#endif  // CORE_TOOLS_TESTING_ENDIAN_TESTING_H