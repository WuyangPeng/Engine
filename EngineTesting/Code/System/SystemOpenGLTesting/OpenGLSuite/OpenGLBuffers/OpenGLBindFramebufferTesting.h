///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/19 22:12)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_BIND_FRAMEBUFFER_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_BIND_FRAMEBUFFER_TESTING_H

#include "OpenGLBuffersTestingBase.h" 

namespace System
{
    class OpenGLBindFramebufferTesting final : public OpenGLBuffersTestingBase
    {
    public:
        using ClassType = OpenGLBindFramebufferTesting;
        using ParentType = OpenGLBuffersTestingBase;

    public:
        explicit OpenGLBindFramebufferTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void OpenGLBindFramebufferTest();
        void DoOpenGLBindFramebufferTest(OpenGLUInt framebuffers) noexcept;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_BIND_FRAMEBUFFER_TESTING_H