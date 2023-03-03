///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.3 (2023/03/02 11:30)

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
        void DoRunUnitTest() override;
        void MainTest();

        void ByteSwap2Test() noexcept;
        void ByteSwap4Test() noexcept;
        void ByteSwap8Test() noexcept;
    };
}

#endif  // CORE_TOOLS_TESTING_BYTE_SWAP_TESTING_H