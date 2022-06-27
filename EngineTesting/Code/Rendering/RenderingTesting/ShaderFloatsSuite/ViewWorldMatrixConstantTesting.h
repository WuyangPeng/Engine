///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/13 11:32)

#ifndef RENDERING_SHADER_FLOATS_SUITE_VIEW_WORLD_MATRIX_CONSTANT_TESTING_H
#define RENDERING_SHADER_FLOATS_SUITE_VIEW_WORLD_MATRIX_CONSTANT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
    class ViewWorldMatrixConstantTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ViewWorldMatrixConstantTesting);

    private:
        void MainTest();
        void InitTest();
        void CopyTest();
        void StreamTest() noexcept;
        void UpdateTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_SHADER_FLOATS_SUITE_VIEW_WORLD_MATRIX_CONSTANT_TESTING_H