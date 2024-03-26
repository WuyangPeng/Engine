/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:32)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_BIND_VERTEX_BUFFER_TESTING_DETAIL_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_BIND_VERTEX_BUFFER_TESTING_DETAIL_H

#include "OpenGLBindVertexBufferTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBuffers.h"

template <System::OpenGLData Data, typename Stride>
void System::OpenGLBindVertexBufferTesting::DoBindVertexBufferTest(OpenGLUnsignedInt vertexArray, OpenGLUnsignedInt buffers, bool normalized) noexcept
{
    SetGLBindVertexArray(vertexArray);
    SetGLEnableVertexAttributeArray(bindingIndex);
    SetGLBindVertexBuffer(bindingIndex, buffers, 0, sizeof(Stride) * size);
    SetGLVertexAttributeFormat(attributeIndex, size, Data, normalized, 0);
    SetGLVertexAttributeBinding(attributeIndex, bindingIndex);
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_BIND_VERTEX_BUFFER_TESTING_DETAIL_H