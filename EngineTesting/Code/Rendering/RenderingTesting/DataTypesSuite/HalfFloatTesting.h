///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/16 14:23)

#ifndef RENDERING_DATA_TYPES_SUITE_HALF_FLOAT_TESTING_H
#define RENDERING_DATA_TYPES_SUITE_HALF_FLOAT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
    class HalfFloatTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(HalfFloatTesting);

    private:
        void MainTest();
        void BigFloatTest();
        void SmallFloatTest();
        void UInt16Test() noexcept;
        void OperatorTest();

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_DATA_TYPES_SUITE_HALF_FLOAT_TESTING_H