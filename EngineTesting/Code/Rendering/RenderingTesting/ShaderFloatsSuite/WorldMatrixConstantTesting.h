///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:16)

#ifndef RENDERING_SHADER_FLOATS_SUITE_WORLD_MATRIX_CONSTANT_TESTING_H
#define RENDERING_SHADER_FLOATS_SUITE_WORLD_MATRIX_CONSTANT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class WorldMatrixConstantTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = WorldMatrixConstantTesting;
        using ParentType = UnitTest;

    public:
        explicit WorldMatrixConstantTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void InitTest();
        void CopyTest();
        void StreamTest() noexcept;
        void UpdateTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_SHADER_FLOATS_SUITE_WORLD_MATRIX_CONSTANT_TESTING_H