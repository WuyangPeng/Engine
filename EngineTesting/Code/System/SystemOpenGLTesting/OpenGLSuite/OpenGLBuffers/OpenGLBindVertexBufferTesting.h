/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:34)

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

    private:
        static constexpr auto size = 3;
        static constexpr auto bindingIndex = 0;
        static constexpr auto attributeIndex = 0;

    private:
        void OpenGLBindVertexBufferTest();

        void DoOpenGLBindVertexBufferTest(OpenGLUnsignedInt buffers);
        void BindVertexBufferTest(OpenGLUnsignedInt vertexArray, OpenGLUnsignedInt buffers, bool normalized) const noexcept;

        template <OpenGLData Data, typename Stride>
        static void DoBindVertexBufferTest(OpenGLUnsignedInt vertexArray, OpenGLUnsignedInt buffers, bool normalized) noexcept;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_BIND_VERTEX_BUFFER_TESTING_H