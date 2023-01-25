///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.0 (2023/01/15 23:35)

#ifndef SYSTEM_OPENGL_OPENGL_BUFFERS_H
#define SYSTEM_OPENGL_OPENGL_BUFFERS_H

#include "System/SystemDll.h"

#include "Fwd/OpenGLFlagsFwd.h"
#include "Using/OpenGLUsing.h"
#include "System/Helper/GLExtensionsMacro.h"

namespace System
{
    void SYSTEM_DEFAULT_DECLARE GetGLGenBuffers(OpenGLSize n, OpenGLUInt* buffers) noexcept;
    NODISCARD OpenGLUInt SYSTEM_DEFAULT_DECLARE GetGLGenBuffers() noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteBuffers(OpenGLSize n, const OpenGLUInt* buffers) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteBuffers(OpenGLUInt buffers) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLBindBuffer(BindBuffer type, OpenGLUInt buffer) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBufferData(BindBuffer target, OpenGLSizePtr size, const void* data, BufferUsage usage) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBufferSubData(BindBuffer target, OpenGLIntPtr offset, OpenGLSizePtr size, const void* data) noexcept;
    void SYSTEM_DEFAULT_DECLARE GetGLBufferSubData(BindBuffer target, OpenGLIntPtr offset, OpenGLSizePtr size, void* data) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBindBufferBase(BindBuffer target, OpenGLUInt index, OpenGLUInt buffer) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBindBufferRange(BindBuffer target, OpenGLUInt index, OpenGLUInt buffer, OpenGLIntPtr offset, OpenGLSizePtr size) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLCopyBufferSubData(BindBuffer readTarget, BindBuffer writeTarget, OpenGLIntPtr readOffset, OpenGLIntPtr writeOffset, OpenGLSizePtr size) noexcept;

    void SYSTEM_DEFAULT_DECLARE GetGLGenFramebuffers(OpenGLSize n, OpenGLUInt* framebuffers) noexcept;
    NODISCARD OpenGLUInt SYSTEM_DEFAULT_DECLARE GetGLGenFramebuffers() noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBindFramebuffer(FrameBufferType target, OpenGLUInt framebuffer) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteFramebuffers(OpenGLSize n, const OpenGLUInt* framebuffers) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteFramebuffers(OpenGLUInt framebuffers) noexcept;

    void SYSTEM_DEFAULT_DECLARE GetGLGenVertexArrays(OpenGLSize n, OpenGLUInt* arrays) noexcept;
    NODISCARD OpenGLUInt SYSTEM_DEFAULT_DECLARE GetGLGenVertexArrays() noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBindVertexArray(OpenGLUInt array) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteVertexArrays(OpenGLSize n, const OpenGLUInt* arrays) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteVertexArrays(OpenGLUInt arrays) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLEnableVertexAttribArray(OpenGLUInt index) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBindVertexBuffer(OpenGLUInt bindingIndex, OpenGLUInt buffer, OpenGLIntPtr offset, OpenGLSize stride) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLVertexAttribFormat(OpenGLUInt attribIndex, OpenGLInt size, OpenGLData type, OpenGLBoolean normalized, OpenGLUInt relativeOffset) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLVertexAttribBinding(OpenGLUInt attribIndex, OpenGLUInt bindingIndex) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLDrawBuffers(OpenGLSize n, const OpenGLEnum* bufs) noexcept;
}

#endif  // SYSTEM_OPENGL_OPENGL_BUFFERS_H