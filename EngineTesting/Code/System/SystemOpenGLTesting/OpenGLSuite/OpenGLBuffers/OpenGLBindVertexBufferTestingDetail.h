///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/20 0:27)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_BIND_VERTEX_BUFFER_TESTING_DETAIL_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_BIND_VERTEX_BUFFER_TESTING_DETAIL_H

#include "OpenGLBindVertexBufferTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBuffers.h"

template <System::OpenGLData Data, typename Stride>
void System::OpenGLBindVertexBufferTesting::DoBindVertexBufferTest(OpenGLUInt vertexArray, OpenGLUInt buffers, OpenGLBoolean normalized) noexcept
{
    SetGLBindVertexArray(vertexArray);

    constexpr auto bindingIndex = 0;
    constexpr auto attribIndex = 0;

    SetGLEnableVertexAttribArray(bindingIndex);

    constexpr auto size = 3;

    SetGLBindVertexBuffer(bindingIndex, buffers, 0, sizeof(Stride) * size);
    SetGLVertexAttribFormat(attribIndex, size, Data, normalized, 0);
    SetGLVertexAttribBinding(attribIndex, bindingIndex);
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_BIND_VERTEX_BUFFER_TESTING_DETAIL_H