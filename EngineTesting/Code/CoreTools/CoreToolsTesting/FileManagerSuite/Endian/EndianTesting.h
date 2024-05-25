/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/30 22:55)

#ifndef CORE_TOOLS_TESTING_ENDIAN_TESTING_H
#define CORE_TOOLS_TESTING_ENDIAN_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <array>

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
        static constexpr auto uint16ArraySize = 5;
        static constexpr auto uint32ArraySize = 4;
        static constexpr auto uint64ArraySize = 3;

        using UInt16Array = std::array<uint16_t, uint16ArraySize>;
        using UInt32Array = std::array<uint32_t, uint32ArraySize>;
        using UInt64Array = std::array<uint64_t, uint64ArraySize>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ByteOrderTest();
        void Swap2ByteOrderTest();
        void Swap4ByteOrderTest();
        void Swap8ByteOrderTest();

        void Swap2ByteOrder0Test(UInt16Array& value);
        void Swap2ByteOrder1Test(UInt16Array& value);
        void Swap2ByteOrder2Test(UInt16Array& value);
        void Swap2ByteOrder3Test(UInt16Array& value);
        void Swap2ByteOrder4Test(const UInt16Array& value);

        void Swap4ByteOrder0Test(UInt32Array& value);
        void Swap4ByteOrder1Test(UInt32Array& value);
        void Swap4ByteOrder2Test(UInt32Array& value);
        void Swap4ByteOrder3Test(UInt32Array& value);
        void Swap4ByteOrder4Test(const UInt32Array& value);

        void Swap8ByteOrder0Test(UInt64Array& value);
        void Swap8ByteOrder1Test(UInt64Array& value);
        void Swap8ByteOrder2Test(UInt64Array& value);
        void Swap8ByteOrder3Test(UInt64Array& value);
        void Swap8ByteOrder4Test(const UInt64Array& value);

    private:
        UInt16Array originalUInt16;
        UInt16Array swapUInt16;
        UInt32Array originalUInt32;
        UInt32Array swapUInt32;
        UInt64Array originalUInt64;
        UInt64Array swapUInt64;
    };
}

#endif  // CORE_TOOLS_TESTING_ENDIAN_TESTING_H