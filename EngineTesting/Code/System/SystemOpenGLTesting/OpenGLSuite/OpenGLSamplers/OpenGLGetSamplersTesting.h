/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:38)

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

        void GetSamplerTest();
        void GetSamplersTest();
        void BindSamplerTest();

        void DoGetSamplersTest(const SamplersType& samplers);
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_GET_SAMPLERS_TESTING_H