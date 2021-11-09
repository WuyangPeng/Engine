///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.3 (2021/09/03 16:22)

#ifndef CORE_TOOLS_TESTING_BYTE_SWAPPER_TESTING_H
#define CORE_TOOLS_TESTING_BYTE_SWAPPER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ByteSwapperTesting final : public UnitTest
    {
    public:
        using ClassType = ByteSwapperTesting;
        using ParentType = UnitTest;

    public:
        explicit ByteSwapperTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ByteSwap2Test();
        void ByteSwap4Test();
        void ByteSwap8Test();
    };
}

#endif  // CORE_TOOLS_TESTING_BYTE_SWAPPER_TESTING_H