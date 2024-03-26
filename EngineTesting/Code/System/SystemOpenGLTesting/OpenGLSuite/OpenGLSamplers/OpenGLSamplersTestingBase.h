/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:38)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SAMPLERS_TESTING_BASE_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SAMPLERS_TESTING_BASE_H

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class OpenGLSamplersTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLSamplersTestingBase;
        using ParentType = UnitTest;

    public:
        explicit OpenGLSamplersTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        static constexpr auto bufferSize = 12;
        using SamplersType = std::array<OpenGLUnsignedInt, bufferSize>;

    protected:
        void DeleteSamplerTest(OpenGLInt sampler) const noexcept;
        void DeleteSamplersTest(const SamplersType& samplers) const noexcept;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SAMPLERS_TESTING_BASE_H