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

#include <vector>

namespace System
{
    NODISCARD OpenGLUnsignedIntIntContainer SYSTEM_DEFAULT_DECLARE GetGLGenBuffers(OpenGLSize n);
    void SYSTEM_DEFAULT_DECLARE GetGLGenBuffers(OpenGLSize n, OpenGLUnsignedInt* buffers) noexcept;
    NODISCARD OpenGLUnsignedInt SYSTEM_DEFAULT_DECLARE GetGLGenBuffers() noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteBuffers(OpenGLSize n, const OpenGLUnsignedInt* buffers) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteBuffers(OpenGLUnsignedInt buffers) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLBindBuffer(BindBuffer type, OpenGLUnsignedInt buffer) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBufferData(BindBuffer target, OpenGLSizePtr size, const void* data, BufferUsage usage) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBufferSubData(BindBuffer target, OpenGLIntPtr offset, OpenGLSizePtr size, const void* data) noexcept;
    void SYSTEM_DEFAULT_DECLARE GetGLBufferSubData(BindBuffer target, OpenGLIntPtr offset, OpenGLSizePtr size, void* data) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBindBufferBase(BindBuffer target, OpenGLUnsignedInt index, OpenGLUnsignedInt buffer) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBindBufferRange(BindBuffer target, OpenGLUnsignedInt index, OpenGLUnsignedInt buffer, OpenGLIntPtr offset, OpenGLSizePtr size) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLCopyBufferSubData(BindBuffer readTarget, BindBuffer writeTarget, OpenGLIntPtr readOffset, OpenGLIntPtr writeOffset, OpenGLSizePtr size) noexcept;

    NODISCARD OpenGLUnsignedIntIntContainer SYSTEM_DEFAULT_DECLARE GetGLGenFrameBuffers(OpenGLSize n);
    void SYSTEM_DEFAULT_DECLARE GetGLGenFrameBuffers(OpenGLSize n, OpenGLUnsignedInt* frameBuffers) noexcept;
    NODISCARD OpenGLUnsignedInt SYSTEM_DEFAULT_DECLARE GetGLGenFrameBuffers() noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBindFrameBuffer(FrameBufferType target, OpenGLUnsignedInt frameBuffer) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteFrameBuffers(OpenGLSize n, const OpenGLUnsignedInt* frameBuffers) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteFrameBuffers(OpenGLUnsignedInt frameBuffers) noexcept;

    NODISCARD OpenGLUnsignedIntIntContainer SYSTEM_DEFAULT_DECLARE GetGLGenVertexArrays(OpenGLSize n);
    void SYSTEM_DEFAULT_DECLARE GetGLGenVertexArrays(OpenGLSize n, OpenGLUnsignedInt* arrays) noexcept;
    NODISCARD OpenGLUnsignedInt SYSTEM_DEFAULT_DECLARE GetGLGenVertexArrays() noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBindVertexArray(OpenGLUnsignedInt array) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteVertexArrays(OpenGLSize n, const OpenGLUnsignedInt* arrays) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteVertexArrays(OpenGLUnsignedInt arrays) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLEnableVertexAttributeArray(OpenGLUnsignedInt index) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBindVertexBuffer(OpenGLUnsignedInt bindingIndex, OpenGLUnsignedInt buffer, OpenGLIntPtr offset, OpenGLSize stride) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLVertexAttributeFormat(OpenGLUnsignedInt attributeIndex, OpenGLInt size, OpenGLData type, bool normalized, OpenGLUnsignedInt relativeOffset) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLVertexAttributeBinding(OpenGLUnsignedInt attributeIndex, OpenGLUnsignedInt bindingIndex) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLDrawBuffers(const OpenGLEnumContainer& buffers);
    void SYSTEM_DEFAULT_DECLARE SetGLDrawBuffers(OpenGLSize n, const OpenGLEnum* buffers) noexcept;

    SYSTEM_DEFAULT_DECLARE void SetGLVertexAttributePointer(OpenGLUnsignedInt index, OpenGLInt size, OpenGLData type, bool normalized, OpenGLSize stride, const void* pointer) noexcept;

    MAYBE_NULLPTR SYSTEM_DEFAULT_DECLARE void* GetGLMapForWrite(BindBuffer target, OpenGLUnsignedInt buffer) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetGLUnmap(BindBuffer target, OpenGLUnsignedInt buffer) noexcept;
}

#endif  // SYSTEM_OPENGL_OPENGL_BUFFERS_H