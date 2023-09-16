///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:03)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_GET_SAMPLERS_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_GET_SAMPLERS_TESTING_H

#include "OpenGLSamplersTestingBase.h"

namespace System
{
    class OpenGLGetSamplersTesting final : public OpenGLSamplersTestingBase
    {
    public:
        using ClassType = OpenGLGetSamplersTesting;
        using ParentType = OpenGLSamplersTestingBase;

    public:
        explicit OpenGLGetSamplersTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void OpenGLGetSamplerTest();
        void OpenGLGetSamplersTest();

        void DoOpenGLGetSamplersTest(const SamplersType& samplers);
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_GET_SAMPLERS_TESTING_H