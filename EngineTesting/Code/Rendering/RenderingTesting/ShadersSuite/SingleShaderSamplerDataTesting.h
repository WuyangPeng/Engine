///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:04)

#ifndef RENDERING_SHADERS_SUITE_SINGLE_SHADER_SAMPLER_DATA_TESTING_H
#define RENDERING_SHADERS_SUITE_SINGLE_SHADER_SAMPLER_DATA_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class SingleShaderSamplerDataTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = SingleShaderSamplerDataTesting;
        using ParentType = UnitTest;

    public:
        explicit SingleShaderSamplerDataTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void InitTest() noexcept;
        void CopyTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_SHADERS_SUITE_SINGLE_SHADER_SAMPLER_DATA_TESTING_H