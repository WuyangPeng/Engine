/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/03/01 17:35)

#ifndef SYSTEM_OPENGL_OPENGL_BASE_H
#define SYSTEM_OPENGL_OPENGL_BASE_H

#include "System/SystemDll.h"

#include "Fwd/OpenGLFlagsFwd.h"
#include "Using/OpenGLUsing.h"

namespace System
{
    void SYSTEM_DEFAULT_DECLARE SetupRenderStatus() noexcept;

    void SYSTEM_DEFAULT_DECLARE ClearAllGLBufferBit() noexcept;
    NODISCARD ViewportQueryType SYSTEM_DEFAULT_DECLARE GetGLViewport() noexcept;
    NODISCARD DepthRangeQueryType SYSTEM_DEFAULT_DECLARE GetGLDepthRange() noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLViewport(OpenGLInt x, OpenGLInt y, OpenGLSize width, OpenGLSize height) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDepthRange(OpenGLDouble nearDepthRange, OpenGLDouble farDepthRange) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLClearColor(OpenGLFloat red, OpenGLFloat green, OpenGLFloat blue, OpenGLFloat alpha) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLClearStencil(OpenGLInt stencil) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLClearDepth(OpenGLDouble depth) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLClear(OpenGLClearMask openGLClearMask) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLFrontFace(OpenGLFrontFace mode) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLCullFace(RasterizerStateCullFace mode) noexcept;

    NODISCARD OpenGLInt SYSTEM_DEFAULT_DECLARE GetGLInteger(TextureTargetBinding name) noexcept;

    NODISCARD OpenGLInt SYSTEM_DEFAULT_DECLARE GetGLInteger(OpenGLQuery name) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetGLBoolean(OpenGLQuery name) noexcept;
    NODISCARD OpenGLFloat SYSTEM_DEFAULT_DECLARE GetGLFloat(OpenGLQuery name) noexcept;
    NODISCARD OpenGLDouble SYSTEM_DEFAULT_DECLARE GetGLDouble(OpenGLQuery name) noexcept;

    void SYSTEM_DEFAULT_DECLARE GetGLInteger(OpenGLQuery name, OpenGLInt* data) noexcept;
    void SYSTEM_DEFAULT_DECLARE GetGLDouble(OpenGLQuery name, OpenGLDouble* data) noexcept;

    void SYSTEM_DEFAULT_DECLARE EnableGLState(OpenGLEnable cap) noexcept;
    void SYSTEM_DEFAULT_DECLARE DisableGLState(OpenGLEnable cap) noexcept;
    void SYSTEM_DEFAULT_DECLARE EnableGLState(OpenGLEnable target, OpenGLUnsignedInt index) noexcept;
    void SYSTEM_DEFAULT_DECLARE DisableGLState(OpenGLEnable target, OpenGLUnsignedInt index) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLBlendColor(OpenGLFloat red, OpenGLFloat green, OpenGLFloat blue, OpenGLFloat alpha) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBlendFuncSeparate(BlendStateMode sourceFactorRGB, BlendStateMode destinationFactorRGB, BlendStateMode sourceFactorAlpha, BlendStateMode destinationFactorAlpha) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBlendFuncSeparate(OpenGLUnsignedInt index, BlendStateMode sourceFactorRGB, BlendStateMode destinationFactorRGB, BlendStateMode sourceFactorAlpha, BlendStateMode destinationFactorAlpha) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBlendEquationSeparate(BlendStateOperation modeRGB, BlendStateOperation modeAlpha) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBlendEquationSeparate(OpenGLUnsignedInt index, BlendStateOperation modeRGB, BlendStateOperation modeAlpha) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLDepthFunc(DepthStencilStateMode depthStencilStateMode) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDepthMask(DepthStencilStateWriteMask flag) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLStencilFuncSeparate(RasterizerStateCullFace face, DepthStencilStateMode func, OpenGLInt ref, OpenGLUnsignedInt mask) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLStencilMaskSeparate(RasterizerStateCullFace face, OpenGLUnsignedInt mask) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLStencilOpSeparate(RasterizerStateCullFace face, DepthStencilStateOperation sFail, DepthStencilStateOperation dpFail, DepthStencilStateOperation dpPass) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLColorMask(bool red, bool green, bool blue, bool alpha) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLColorMask(OpenGLUnsignedInt index, bool red, bool green, bool blue, bool alpha) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLSampleMask(OpenGLUnsignedInt maskNumber, OpenGLBitfield mask) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLFlush() noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLDrawRangeElements(PrimitiveType mode, OpenGLUnsignedInt start, OpenGLUnsignedInt end, OpenGLSize count, OpenGLData type, const void* indices) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDrawArrays(PrimitiveType mode, OpenGLInt first, OpenGLSize count) noexcept;
}

#endif  // SYSTEM_OPENGL_OPENGL_BASE_H