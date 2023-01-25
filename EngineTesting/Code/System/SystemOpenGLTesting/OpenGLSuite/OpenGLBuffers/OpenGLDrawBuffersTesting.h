///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/19 21:46)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_DRAW_BUFFERS_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_DRAW_BUFFERS_TESTING_H

#include "OpenGLBuffersTestingBase.h"

namespace System
{
    class OpenGLDrawBuffersTesting final : public OpenGLBuffersTestingBase
    {
    public:
        using ClassType = OpenGLDrawBuffersTesting;
        using ParentType = OpenGLBuffersTestingBase;

    public:
        explicit OpenGLDrawBuffersTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void BackDrawBuffersTest();

        void OpenGLBindFramebufferTest();
        void DoOpenGLBindFramebufferTest(OpenGLUInt framebuffers) noexcept;

        void FramebufferDrawBuffersTest();

    private:
        using OpenGLEnumContainer = std::vector<OpenGLEnum>;

    private:
        OpenGLEnumContainer back;
        OpenGLEnumContainer attachment;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_DRAW_BUFFERS_TESTING_H