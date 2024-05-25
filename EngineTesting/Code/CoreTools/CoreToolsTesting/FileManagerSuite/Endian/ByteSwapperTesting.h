/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 16:40)

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
        void DoRunUnitTest() override;
        void MainTest();

        void ByteSwap2Test();
        void ByteSwap4Test();
        void ByteSwap8Test();

        void DoByteSwap2Test();
        void ByteSwap2Original();
        void DoByteSwap4Test();
        void ByteSwap4Original();
        void DoByteSwap8Test();
        void ByteSwap8Original();
    };
}

#endif  // CORE_TOOLS_TESTING_BYTE_SWAPPER_TESTING_H