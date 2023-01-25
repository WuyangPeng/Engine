///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/22 19:49)

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
        using SamplersType = std::array<OpenGLUInt, bufferSize>;

    protected:
        void SetGLDeleteSamplerTest(OpenGLInt sampler) noexcept;
        void SetGLDeleteSamplersTest(const SamplersType& samplers) noexcept;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SAMPLERS_TESTING_BASE_H