///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/16 14:23)

#ifndef RENDERING_DATA_TYPES_SUITE_SPECIALIZED_IO_TESTING_H
#define RENDERING_DATA_TYPES_SUITE_SPECIALIZED_IO_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
    class SpecializedIOTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(SpecializedIOTesting);

    private:
        void MainTest();
        void StreamSizeTest() noexcept;
        void TransformTest() noexcept;
        void BoundTest() noexcept;
        void IntColourTest() noexcept;
        void FloatColourTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_DATA_TYPES_SUITE_SPECIALIZED_IO_TESTING_H