/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/03 00:10)

#include "System/SystemExport.h"

#include "OpenGLBuffers.h"
#include "Flags/OpenGLFlags.h"
#include "Detail/GL15Extensions.h"
#include "Detail/GL20Extensions.h"
#include "Detail/GL30Extensions.h"
#include "Detail/GL31Extensions.h"
#include "Detail/GL43Extensions.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

System::OpenGLUnsignedIntIntContainer System::GetGLGenBuffers(OpenGLSize n)
{
    OpenGLUnsignedIntIntContainer buffers(n);
    GetGLGenBuffers(n, buffers.data());

    return buffers;
}

void System::GetGLGenBuffers(OpenGLSize n, OpenGLUnsignedInt* buffers) noexcept
{
    GLGenBuffers(n, buffers);
}

System::OpenGLUnsignedInt System::GetGLGenBuffers() noexcept
{
    OpenGLUnsignedInt buffers{};
    GetGLGenBuffers(1, &buffers);

    return buffers;
}

void System::SetGLDeleteBuffers(OpenGLSize n, const OpenGLUnsignedInt* buffers) noexcept
{
    GLDeleteBuffers(n, buffers);
}

void System::SetGLDeleteBuffers(OpenGLUnsignedInt buffers) noexcept
{
    SetGLDeleteBuffers(1, &buffers);
}

void System::SetGLBindBuffer(BindBuffer type, OpenGLUnsignedInt buffer) noexcept
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

void System::SetGLBindBufferBase(BindBuffer target, OpenGLUnsignedInt index, OpenGLUnsignedInt buffer) noexcept
{
    GLBindBufferBase(EnumCastUnderlying(target), index, buffer);
}

void System::SetGLBindBufferRange(BindBuffer target, OpenGLUnsignedInt index, OpenGLUnsignedInt buffer, OpenGLIntPtr offset, OpenGLSizePtr size) noexcept
{
    GLBindBufferRange(EnumCastUnderlying(target), index, buffer, offset, size);
}

void System::SetGLCopyBufferSubData(BindBuffer readTarget, BindBuffer writeTarget, OpenGLIntPtr readOffset, OpenGLIntPtr writeOffset, OpenGLSizePtr size) noexcept
{
    GLCopyBufferSubData(EnumCastUnderlying(readTarget), EnumCastUnderlying(writeTarget), readOffset, writeOffset, size);
}

System::OpenGLUnsignedIntIntContainer System::GetGLGenFrameBuffers(OpenGLSize n)
{
    OpenGLUnsignedIntIntContainer frameBuffers(n);
    GetGLGenFrameBuffers(n, frameBuffers.data());

    return frameBuffers;
}

void System::GetGLGenFrameBuffers(OpenGLSize n, OpenGLUnsignedInt* frameBuffers) noexcept
{
    GLGenFrameBuffers(n, frameBuffers);
}

System::OpenGLUnsignedInt System::GetGLGenFrameBuffers() noexcept
{
    OpenGLUnsignedInt frameBuffers{};
    GetGLGenFrameBuffers(1, &frameBuffers);

    return frameBuffers;
}

void System::SetGLDeleteFrameBuffers(OpenGLSize n, const OpenGLUnsignedInt* frameBuffers) noexcept
{
    GLDeleteFrameBuffers(n, frameBuffers);
}

void System::SetGLDeleteFrameBuffers(OpenGLUnsignedInt frameBuffers) noexcept
{
    SetGLDeleteFrameBuffers(1, &frameBuffers);
}

void System::SetGLBindFrameBuffer(FrameBufferType target, OpenGLUnsignedInt frameBuffer) noexcept
{
    GLBindFrameBuffer(EnumCastUnderlying(target), frameBuffer);
}

void System::SetGLDrawBuffers(const OpenGLEnumContainer& buffers)
{
    SetGLDrawBuffers(boost::numeric_cast<OpenGLSize>(buffers.size()), buffers.data());
}

void System::SetGLDrawBuffers(OpenGLSize n, const OpenGLEnum* buffers) noexcept
{
    GLDrawBuffers(n, buffers);
}

void System::SetGLBindVertexArray(OpenGLUnsignedInt array) noexcept
{
    GLBindVertexArray(array);
}

void System::SetGLDeleteVertexArrays(OpenGLSize n, const OpenGLUnsignedInt* arrays) noexcept
{
    GLDeleteVertexArrays(n, arrays);
}

void System::SetGLDeleteVertexArrays(OpenGLUnsignedInt arrays) noexcept
{
    SetGLDeleteVertexArrays(1, &arrays);
}

System::OpenGLUnsignedIntIntContainer System::GetGLGenVertexArrays(OpenGLSize n)
{
    OpenGLUnsignedIntIntContainer result(n);
    GetGLGenVertexArrays(n, result.data());

    return result;
}

void System::GetGLGenVertexArrays(OpenGLSize n, OpenGLUnsignedInt* arrays) noexcept
{
    GLGenVertexArrays(n, arrays);
}

System::OpenGLUnsignedInt System::GetGLGenVertexArrays() noexcept
{
    OpenGLUnsignedInt arrays{};
    GetGLGenVertexArrays(1, &arrays);

    return arrays;
}

void System::SetGLEnableVertexAttributeArray(OpenGLUnsignedInt index) noexcept
{
    GLEnableVertexAttribArray(index);
}

void System::SetGLBindVertexBuffer(OpenGLUnsignedInt bindingIndex, OpenGLUnsignedInt buffer, OpenGLIntPtr offset, OpenGLSize stride) noexcept
{
    GLBindVertexBuffer(bindingIndex, buffer, offset, stride);
}

void System::SetGLVertexAttributeFormat(OpenGLUnsignedInt attributeIndex, OpenGLInt size, OpenGLData type, bool normalized, OpenGLUnsignedInt relativeOffset) noexcept
{
    GLVertexAttribFormat(attributeIndex, size, EnumCastUnderlying(type), normalized ? GL_TRUE : GL_FALSE, relativeOffset);
}

void System::SetGLVertexAttributeBinding(OpenGLUnsignedInt attributeIndex, OpenGLUnsignedInt bindingIndex) noexcept
{
    GLVertexAttribBinding(attributeIndex, bindingIndex);
}

void System::SetGLVertexAttributePointer(OpenGLUnsignedInt index, OpenGLInt size, OpenGLData type, bool normalized, OpenGLSize stride, const void* pointer) noexcept
{
    GLVertexAttribPointer(index, size, EnumCastUnderlying(type), normalized ? GL_TRUE : GL_FALSE, stride, pointer);
}

void* System::GetGLMapForWrite(BindBuffer target, OpenGLUnsignedInt buffer) noexcept
{
    SetGLBindBuffer(target, buffer);
    const auto mapped = GLMapBuffer(EnumCastUnderlying(target), EnumCastUnderlying(BufferLocking::WriteOnly));
    SetGLBindBuffer(target, 0);

    return mapped;
}

bool System::SetGLUnmap(BindBuffer target, OpenGLUnsignedInt buffer) noexcept
{
    SetGLBindBuffer(target, buffer);
    const auto result = GLUnmapBuffer(EnumCastUnderlying(target));
    SetGLBindBuffer(target, 0);

    return result != GL_FALSE;
}
