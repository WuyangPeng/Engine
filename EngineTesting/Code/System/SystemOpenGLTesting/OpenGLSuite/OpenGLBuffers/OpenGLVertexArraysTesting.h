/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:35)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_VERTEX_ARRAYS_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_VERTEX_ARRAYS_TESTING_H

#include "OpenGLBuffersTestingBase.h"

namespace System
{
    class OpenGLVertexArraysTesting final : public OpenGLBuffersTestingBase
    {
    public:
        using ClassType = OpenGLVertexArraysTesting;
        using ParentType = OpenGLBuffersTestingBase;

    public:
        explicit OpenGLVertexArraysTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void VertexArrayTest();
        void VertexArraysTest();
        void VertexArrayContainerTest();
        void BindBufferTest() const;

        void BufferValidTest(const BufferType& buffers);
        void BufferContainerValidTest(const OpenGLUnsignedIntIntContainer& buffers);
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_VERTEX_ARRAYS_TESTING_H