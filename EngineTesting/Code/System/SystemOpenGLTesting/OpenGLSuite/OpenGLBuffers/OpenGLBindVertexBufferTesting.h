///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 13:55)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_BIND_VERTEX_BUFFER_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_BIND_VERTEX_BUFFER_TESTING_H

#include "OpenGLBuffersTestingBase.h"

namespace System
{
    class OpenGLBindVertexBufferTesting final : public OpenGLBuffersTestingBase
    {
    public:
        using ClassType = OpenGLBindVertexBufferTesting;
        using ParentType = OpenGLBuffersTestingBase;

    public:
        explicit OpenGLBindVertexBufferTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void OpenGLBindVertexBufferTest();

        void DoOpenGLBindVertexBufferTest(OpenGLUInt buffers);
        void BindVertexBufferTest(OpenGLUInt vertexArray, OpenGLUInt buffers, OpenGLBoolean normalized) noexcept;

        template <OpenGLData Data, typename Stride>
        void DoBindVertexBufferTest(OpenGLUInt vertexArray, OpenGLUInt buffers, OpenGLBoolean normalized) noexcept;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_BIND_VERTEX_BUFFER_TESTING_H