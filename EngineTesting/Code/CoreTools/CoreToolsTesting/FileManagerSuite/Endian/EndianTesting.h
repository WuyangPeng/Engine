///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.3 (2023/03/02 11:31)

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
        void DoRunUnitTest() override;
        void MainTest();

        void ByteOrderTest();
        void Swap2ByteOrderTest();
        void Swap4ByteOrderTest();
        void Swap8ByteOrderTest();
    };
}

#endif  // CORE_TOOLS_TESTING_ENDIAN_TESTING_H