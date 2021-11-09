///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.3 (2021/09/03 16:22)

#ifndef CORE_TOOLS_TESTING_BYTE_SWAP_TESTING_H
#define CORE_TOOLS_TESTING_BYTE_SWAP_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ByteSwapTesting final : public UnitTest
    {
    public:
        using ClassType = ByteSwapTesting;
        using ParentType = UnitTest;

    public:
        explicit ByteSwapTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ByteSwap2Test() noexcept;
        void ByteSwap4Test() noexcept;
        void ByteSwap8Test() noexcept;
    };
}

#endif  // CORE_TOOLS_TESTING_BYTE_SWAP_TESTING_H