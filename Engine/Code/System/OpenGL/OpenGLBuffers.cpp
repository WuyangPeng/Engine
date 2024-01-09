/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 17:23)

#include "System/SystemExport.h"

#include "OpenGLBuffers.h"
#include "Flags/OpenGLFlags.h"
#include "Detail/GL15Extensions.h"
#include "Detail/GL20Extensions.h"
#include "Detail/GL30Extensions.h"
#include "Detail/GL31Extensions.h"
#include "Detail/GL43Extensions.h"
#include "System/Helper/EnumCast.h"

void System::GetGLGenBuffers(OpenGLSize n, OpenGLUInt* buffers) noexcept
{
    GLGenBuffers(n, buffers);
}

System::OpenGLUInt System::GetGLGenBuffers() noexcept
{
    OpenGLUInt buffers{};
    GetGLGenBuffers(1, &buffers);

    return buffers;
}

void System::SetGLDeleteBuffers(OpenGLSize n, const OpenGLUInt* buffers) noexcept
{
    GLDeleteBuffers(n, buffers);
}

void System::SetGLDeleteBuffers(OpenGLUInt buffers) noexcept
{
    SetGLDeleteBuffers(1, &buffers);
}

void System::SetGLBindBuffer(BindBuffer type, OpenGLUInt buffer) noexcept
{
    GLBindBuffer(EnumCastUnderlying(type), buffer);
}

void System::SetGLBufferData(BindBuffer target, OpenGLSizePtr size, const void* data, BufferUsage usage) noexcept
{
    GLBufferData(EnumCastUnderlying(target), size, data, EnumCastUnderlying(usage));
}

void System::SetGLBufferSubData(BindBuffer target, OpenGLIntPtr offset, OpenGLSizePtr size, const void* data) noexcept
{
    GLBufferSubData(EnumCastUnderlying(target), offset, size, data);
}

void System::GetGLBufferSubData(BindBuffer target, OpenGLIntPtr offset, OpenGLSizePtr size, void* data) noexcept
{
    GLGetBufferSubData(EnumCastUnderlying(target), offset, size, data);
}

void System::SetGLBindBufferBase(BindBuffer target, OpenGLUInt index, OpenGLUInt buffer) noexcept
{
    GLBindBufferBase(EnumCastUnderlying(target), index, buffer);
}

void System::SetGLBindBufferRange(BindBuffer target, OpenGLUInt index, OpenGLUInt buffer, OpenGLIntPtr offset, OpenGLSizePtr size) noexcept
{
    GLBindBufferRange(EnumCastUnderlying(target), index, buffer, offset, size);
}

void System::SetGLCopyBufferSubData(BindBuffer readTarget, BindBuffer writeTarget, OpenGLIntPtr readOffset, OpenGLIntPtr writeOffset, OpenGLSizePtr size) noexcept
{
    GLCopyBufferSubData(EnumCastUnderlying(readTarget), EnumCastUnderlying(writeTarget), readOffset, writeOffset, size);
}

void System::GetGLGenFrameBuffers(OpenGLSize n, OpenGLUInt* frameBuffers) noexcept
{
    GLGenFramebuffers(n, frameBuffers);
}

System::OpenGLUInt System::GetGLGenFrameBuffers() noexcept
{
    OpenGLUInt frameBuffers{};
    GetGLGenFrameBuffers(1, &frameBuffers);

    return frameBuffers;
}

void System::SetGLDeleteFrameBuffers(OpenGLSize n, const OpenGLUInt* frameBuffers) noexcept
{
    GLDeleteFramebuffers(n, frameBuffers);
}

void System::SetGLDeleteFrameBuffers(OpenGLUInt frameBuffers) noexcept
{
    SetGLDeleteFrameBuffers(1, &frameBuffers);
}

void System::SetGLBindFrameBuffer(FrameBufferType target, OpenGLUInt frameBuffer) noexcept
{
    GLBindFramebuffer(EnumCastUnderlying(target), frameBuffer);
}

void System::SetGLDrawBuffers(OpenGLSize n, const OpenGLEnum* buffers) noexcept
{
    GLDrawBuffers(n, buffers);
}

void System::SetGLBindVertexArray(OpenGLUInt array) noexcept
{
    GLBindVertexArray(array);
}

void System::SetGLDeleteVertexArrays(OpenGLSize n, const OpenGLUInt* arrays) noexcept
{
    GLDeleteVertexArrays(n, arrays);
}

void System::SetGLDeleteVertexArrays(OpenGLUInt arrays) noexcept
{
    SetGLDeleteVertexArrays(1, &arrays);
}

void System::GetGLGenVertexArrays(OpenGLSize n, OpenGLUInt* arrays) noexcept
{
    GLGenVertexArrays(n, arrays);
}

System::OpenGLUInt System::GetGLGenVertexArrays() noexcept
{
    OpenGLUInt arrays{};
    GetGLGenVertexArrays(1, &arrays);

    return arrays;
}

void System::SetGLEnableVertexAttributeArray(OpenGLUInt index) noexcept
{
    GLEnableVertexAttribArray(index);
}

void System::SetGLBindVertexBuffer(OpenGLUInt bindingIndex, OpenGLUInt buffer, OpenGLIntPtr offset, OpenGLSize stride) noexcept
{
    GLBindVertexBuffer(bindingIndex, buffer, offset, stride);
}

void System::SetGLVertexAttributeFormat(OpenGLUInt attributeIndex, OpenGLInt size, OpenGLData type, OpenGLBoolean normalized, OpenGLUInt relativeOffset) noexcept
{
    GLVertexAttribFormat(attributeIndex, size, EnumCastUnderlying(type), normalized, relativeOffset);
}

void System::SetGLVertexAttributeBinding(OpenGLUInt attributeIndex, OpenGLUInt bindingIndex) noexcept
{
    GLVertexAttribBinding(attributeIndex, bindingIndex);
}

void* System::GetGLMapForWrite(BindBuffer target, OpenGLUInt buffer) noexcept
{
    SetGLBindBuffer(target, buffer);
    const auto mapped = GLMapBuffer(EnumCastUnderlying(target), EnumCastUnderlying(BufferLocking::WriteOnly));
    SetGLBindBuffer(target, 0);

    return mapped;
}

void System::SetGLUnmap(BindBuffer target, OpenGLUInt buffer) noexcept
{
    SetGLBindBuffer(target, buffer);
    MAYBE_UNUSED const auto result = GLUnmapBuffer(EnumCastUnderlying(target));
    SetGLBindBuffer(target, 0);
}

void System::SetGLUniformBlockBinding(OpenGLUInt program, OpenGLUInt uniformBlockIndex, OpenGLUInt uniformBlockBinding) noexcept
{
    GLUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding);
}

