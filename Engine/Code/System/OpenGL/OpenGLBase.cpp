/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/03 00:10)

#include "System/SystemExport.h"

#include "OpenGLBase.h"
#include "Flags/GLExtensionsFlags.h"
#include "Flags/OpenGLFlags.h"
#include "Detail/GL10Extensions.h"
#include "Detail/GL11Extensions.h"
#include "Detail/GL12Extensions.h"
#include "Detail/GL14Extensions.h"
#include "Detail/GL20Extensions.h"
#include "Detail/GL30Extensions.h"
#include "Detail/GL32Extensions.h"
#include "Detail/GL40Extensions.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/EnumOperator.h"

void System::SetupRenderStatus() noexcept
{
    SetGLClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    SetGLClearStencil(0);
    SetGLClearDepth(1.0);

    EnableGLState(OpenGLEnable::DepthTest);
    SetGLFrontFace(OpenGLFrontFace::CCW);
    EnableGLState(OpenGLEnable::CullFace);
}

void System::ClearAllGLBufferBit() noexcept
{
    GLClear(EnumCastUnderlying(OpenGLClearMask::ColorBufferBit | OpenGLClearMask::DepthBufferBit | OpenGLClearMask::StencilBufferBit));
}

System::ViewportQueryType System::GetGLViewport() noexcept
{
    ViewportQueryType viewport{};
    GetGLInteger(OpenGLQuery::Viewport, viewport.data());

    return viewport;
}

System::DepthRangeQueryType System::GetGLDepthRange() noexcept
{
    DepthRangeQueryType depthRange{};
    GetGLDouble(OpenGLQuery::DepthRange, depthRange.data());

    return depthRange;
}

void System::SetGLClear(OpenGLClearMask openGLClearMask) noexcept
{
    GLClear(EnumCastUnderlying(openGLClearMask));
}

void System::SetGLViewport(OpenGLInt x, OpenGLInt y, OpenGLSize width, OpenGLSize height) noexcept
{
    GLViewport(x, y, width, height);
}

void System::SetGLDepthRange(OpenGLDouble nearDepthRange, OpenGLDouble farDepthRange) noexcept
{
    GLDepthRange(nearDepthRange, farDepthRange);
}

void System::SetGLClearColor(OpenGLFloat red, OpenGLFloat green, OpenGLFloat blue, OpenGLFloat alpha) noexcept
{
    GLClearColor(red, green, blue, alpha);
}

void System::SetGLClearStencil(OpenGLInt stencil) noexcept
{
    GLClearStencil(stencil);
}

void System::SetGLClearDepth(OpenGLDouble depth) noexcept
{
    GLClearDepth(depth);
}

System::OpenGLInt System::GetGLInteger(OpenGLQuery name) noexcept
{
    OpenGLInt params{};
    GLGetIntegerV(EnumCastUnderlying(name), &params);

    return params;
}

System::OpenGLInt System::GetGLInteger(TextureTargetBinding name) noexcept
{
    OpenGLInt params{};
    GLGetIntegerV(EnumCastUnderlying(name), &params);

    return params;
}

void System::GetGLInteger(OpenGLQuery name, OpenGLInt* data) noexcept
{
    GLGetIntegerV(EnumCastUnderlying(name), data);
}

bool System::GetGLBoolean(OpenGLQuery name) noexcept
{
    OpenGLBoolean params{};
    GLGetBooleanV(EnumCastUnderlying(name), &params);

    return params != GL_FALSE;
}

System::OpenGLFloat System::GetGLFloat(OpenGLQuery name) noexcept
{
    OpenGLFloat params{};
    GLGetFloatV(EnumCastUnderlying(name), &params);

    return params;
}

System::OpenGLDouble System::GetGLDouble(OpenGLQuery name) noexcept
{
    OpenGLDouble params{};
    GLGetDoubleV(EnumCastUnderlying(name), &params);

    return params;
}

void System::GetGLDouble(OpenGLQuery name, OpenGLDouble* data) noexcept
{
    GLGetDoubleV(EnumCastUnderlying(name), data);
}

void System::EnableGLState(OpenGLEnable cap) noexcept
{
    GLEnable(EnumCastUnderlying(cap));
}

void System::EnableGLState(OpenGLEnable target, OpenGLUnsignedInt index) noexcept
{
    GLEnableI(EnumCastUnderlying(target), index);
}

void System::DisableGLState(OpenGLEnable cap) noexcept
{
    GLDisable(EnumCastUnderlying(cap));
}

void System::DisableGLState(OpenGLEnable target, OpenGLUnsignedInt index) noexcept
{
    GLDisableI(EnumCastUnderlying(target), index);
}

void System::SetGLBlendColor(OpenGLFloat red, OpenGLFloat green, OpenGLFloat blue, OpenGLFloat alpha) noexcept
{
    GLBlendColor(red, green, blue, alpha);
}

void System::SetGLColorMask(bool red, bool green, bool blue, bool alpha) noexcept
{
    GLColorMask(red ? GL_TRUE : GL_FALSE, green ? GL_TRUE : GL_FALSE, blue ? GL_TRUE : GL_FALSE, alpha ? GL_TRUE : GL_FALSE);
}

void System::SetGLSampleMask(OpenGLUnsignedInt maskNumber, OpenGLBitfield mask) noexcept
{
    GLSampleMaskI(maskNumber, mask);
}

void System::SetGLBlendFuncSeparate(BlendStateMode sourceFactorRGB, BlendStateMode destinationFactorRGB, BlendStateMode sourceFactorAlpha, BlendStateMode destinationFactorAlpha) noexcept
{
    GLBlendFuncSeparate(EnumCastUnderlying(sourceFactorRGB), EnumCastUnderlying(destinationFactorRGB), EnumCastUnderlying(sourceFactorAlpha), EnumCastUnderlying(destinationFactorAlpha));
}

void System::SetGLBlendEquationSeparate(BlendStateOperation modeRGB, BlendStateOperation modeAlpha) noexcept
{
    GLBlendEquationSeparate(EnumCastUnderlying(modeRGB), EnumCastUnderlying(modeAlpha));
}

void System::SetGLBlendEquationSeparate(OpenGLUnsignedInt index, BlendStateOperation modeRGB, BlendStateOperation modeAlpha) noexcept
{
    GLBlendEquationSeparateI(index, EnumCastUnderlying(modeRGB), EnumCastUnderlying(modeAlpha));
}

void System::SetGLBlendFuncSeparate(OpenGLUnsignedInt index, BlendStateMode sourceFactorRGB, BlendStateMode destinationFactorRGB, BlendStateMode sourceFactorAlpha, BlendStateMode destinationFactorAlpha) noexcept
{
    GLBlendFuncSeparateI(index, EnumCastUnderlying(sourceFactorRGB), EnumCastUnderlying(destinationFactorRGB), EnumCastUnderlying(sourceFactorAlpha), EnumCastUnderlying(destinationFactorAlpha));
}

void System::SetGLColorMask(OpenGLUnsignedInt index, bool red, bool green, bool blue, bool alpha) noexcept
{
    GLColorMaskI(index, red ? GL_TRUE : GL_FALSE, green ? GL_TRUE : GL_FALSE, blue ? GL_TRUE : GL_FALSE, alpha ? GL_TRUE : GL_FALSE);
}

void System::SetGLDepthFunc(DepthStencilStateMode depthStencilStateMode) noexcept
{
    GLDepthFunc(EnumCastUnderlying(depthStencilStateMode));
}

void System::SetGLDepthMask(DepthStencilStateWriteMask flag) noexcept
{
    GLDepthMask(EnumCastUnderlying<OpenGLBoolean>(flag));
}

void System::SetGLStencilFuncSeparate(RasterizerStateCullFace face, DepthStencilStateMode func, OpenGLInt ref, OpenGLUnsignedInt mask) noexcept
{
    GLStencilFuncSeparate(EnumCastUnderlying(face), EnumCastUnderlying(func), ref, mask);
}

void System::SetGLStencilMaskSeparate(RasterizerStateCullFace face, OpenGLUnsignedInt mask) noexcept
{
    GLStencilMaskSeparate(EnumCastUnderlying(face), mask);
}

void System::SetGLStencilOpSeparate(RasterizerStateCullFace face, DepthStencilStateOperation sFail, DepthStencilStateOperation dpFail, DepthStencilStateOperation dpPass) noexcept
{
    GLStencilOpSeparate(EnumCastUnderlying(face), EnumCastUnderlying(sFail), EnumCastUnderlying(dpFail), EnumCastUnderlying(dpPass));
}

void System::SetGLFrontFace(OpenGLFrontFace mode) noexcept
{
    GLFrontFace(EnumCastUnderlying(mode));
}

void System::SetGLCullFace(RasterizerStateCullFace mode) noexcept
{
    GLCullFace(EnumCastUnderlying(mode));
}

void System::SetGLFlush() noexcept
{
    GLFlush();
}

void System::SetGLDrawRangeElements(PrimitiveType mode, OpenGLUnsignedInt start, OpenGLUnsignedInt end, OpenGLSize count, OpenGLData type, const void* indices) noexcept
{
    GLDrawRangeElements(EnumCastUnderlying(mode), start, end, count, EnumCastUnderlying(type), indices);
}

void System::SetGLDrawArrays(PrimitiveType mode, OpenGLInt first, OpenGLSize count) noexcept
{
    GLDrawArrays(EnumCastUnderlying(mode), first, count);
}
