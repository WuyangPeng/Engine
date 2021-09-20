// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.2.3 (2020/03/06 18:23)

#ifndef CORE_TOOLS_BIT_ARRAY_SUITE_BIT_ARRAY_TESTING_H
#define CORE_TOOLS_BIT_ARRAY_SUITE_BIT_ARRAY_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class BitArrayTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(BitArrayTesting);

    private:
        void MainTest();
        void ConstBitArrayTest() noexcept;
        void NonConstBitArrayTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_BIT_ARRAY_SUITE_BIT_ARRAY_TESTING_H