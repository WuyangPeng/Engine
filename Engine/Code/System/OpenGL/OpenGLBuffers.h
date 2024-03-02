/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/03/01 17:35)

#ifndef SYSTEM_OPENGL_OPENGL_BUFFERS_H
#define SYSTEM_OPENGL_OPENGL_BUFFERS_H

#include "System/SystemDll.h"

#include "Fwd/OpenGLFlagsFwd.h"
#include "Using/OpenGLUsing.h"

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

    void SYSTEM_DEFAULT_DECLARE GetGLGenFrameBuffers(OpenGLSize n, OpenGLUInt* frameBuffers) noexcept;
    NODISCARD OpenGLUInt SYSTEM_DEFAULT_DECLARE GetGLGenFrameBuffers() noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBindFrameBuffer(FrameBufferType target, OpenGLUInt frameBuffer) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteFrameBuffers(OpenGLSize n, const OpenGLUInt* frameBuffers) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteFrameBuffers(OpenGLUInt frameBuffers) noexcept;

    void SYSTEM_DEFAULT_DECLARE GetGLGenVertexArrays(OpenGLSize n, OpenGLUInt* arrays) noexcept;
    NODISCARD OpenGLUInt SYSTEM_DEFAULT_DECLARE GetGLGenVertexArrays() noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBindVertexArray(OpenGLUInt array) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteVertexArrays(OpenGLSize n, const OpenGLUInt* arrays) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteVertexArrays(OpenGLUInt arrays) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLEnableVertexAttributeArray(OpenGLUInt index) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBindVertexBuffer(OpenGLUInt bindingIndex, OpenGLUInt buffer, OpenGLIntPtr offset, OpenGLSize stride) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLVertexAttributeFormat(OpenGLUInt attributeIndex, OpenGLInt size, OpenGLData type, OpenGLBoolean normalized, OpenGLUInt relativeOffset) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLVertexAttributeBinding(OpenGLUInt attributeIndex, OpenGLUInt bindingIndex) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLDrawBuffers(OpenGLSize n, const OpenGLEnum* buffers) noexcept;

    MAYBE_NULLPTR SYSTEM_DEFAULT_DECLARE void* GetGLMapForWrite(BindBuffer target, OpenGLUInt buffer) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLUnmap(BindBuffer target, OpenGLUInt buffer) noexcept;

    SYSTEM_DEFAULT_DECLARE void SetGLUniformBlockBinding(OpenGLUInt program, OpenGLUInt uniformBlockIndex, OpenGLUInt uniformBlockBinding) noexcept;
}

#endif  // SYSTEM_OPENGL_OPENGL_BUFFERS_H