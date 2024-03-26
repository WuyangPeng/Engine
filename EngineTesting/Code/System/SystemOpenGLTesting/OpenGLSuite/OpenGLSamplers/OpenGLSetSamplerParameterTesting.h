/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:39)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SET_SAMPLER_PARAMETER_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SET_SAMPLER_PARAMETER_TESTING_H

#include "OpenGLSamplersTestingBase.h"

namespace System
{
    class OpenGLSetSamplerParameterTesting final : public OpenGLSamplersTestingBase
    {
    public:
        using ClassType = OpenGLSetSamplerParameterTesting;
        using ParentType = OpenGLSamplersTestingBase;

    public:
        explicit OpenGLSetSamplerParameterTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SetSamplerParameterTest();

        void DoSetSamplerParameterTest(OpenGLInt sampler);

        void MinFilterTest(OpenGLInt sampler) const noexcept;
        void MagFilterTest(OpenGLInt sampler) const noexcept;
        void LodTest(OpenGLInt sampler) const noexcept;
        void WrapTest(OpenGLInt sampler) const noexcept;
        void LodBiasTest(OpenGLInt sampler) const noexcept;
        void BorderColorTest(OpenGLInt sampler) const noexcept;

    private:
        using BorderColorType = std::array<OpenGLFloat, 4>;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SET_SAMPLER_PARAMETER_TESTING_H