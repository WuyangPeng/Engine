///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:03)

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

        void OpenGLSetSamplerParameterTest();

        void SetOpenGLSetSamplerParameterTest(OpenGLInt sampler);

        void MinFilterTest(OpenGLInt sampler) noexcept;
        void MagFilterTest(OpenGLInt sampler) noexcept;
        void LodTest(OpenGLInt sampler) noexcept;
        void WrapTest(OpenGLInt sampler) noexcept;
        void LodBiasTest(OpenGLInt sampler) noexcept;
        void BorderColorTest(OpenGLInt sampler) noexcept;

    private:
        using BorderColorType = std::array<OpenGLFloat, 4>;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SET_SAMPLER_PARAMETER_TESTING_H