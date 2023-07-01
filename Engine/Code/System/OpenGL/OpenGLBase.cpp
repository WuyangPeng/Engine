///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.0 (2023/01/12 22:44)

#include "System/SystemExport.h"

#include "OpenGLBase.h"
#include "Flags/GLExtensionsFlags.h"
#include "Flags/OpenGLFlags.h"
#include "Detail/GL10Extensions.h"
#include "Detail/GL14Extensions.h"
#include "Detail/GL20Extensions.h"
#include "Detail/GL30Extensions.h"
#include "Detail/GL32Extensions.h"
#include "Detail/GL40Extensions.h"
#include "System/Helper/EnumCast.h"

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
    GLGetIntegerv(EnumCastUnderlying(name), &params);

    return params;
}

System::OpenGLInt System::GetGLInteger(TextureTargetBinding name) noexcept
{
    OpenGLInt params{};
    GLGetIntegerv(EnumCastUnderlying(name), &params);

    return params;
}

void System::GetGLInteger(OpenGLQuery name, OpenGLInt* data) noexcept
{
    GLGetIntegerv(EnumCastUnderlying(name), data);
}

bool System::GetGLBoolean(OpenGLQuery name) noexcept
{
    OpenGLBoolean params{};
    GLGetBooleanv(EnumCastUnderlying(name), &params);

    return params != GL_FALSE;
}

System::OpenGLFloat System::GetGLFloat(OpenGLQuery name) noexcept
{
    OpenGLFloat params{};
    GLGetFloatv(EnumCastUnderlying(name), &params);

    return params;
}

System::OpenGLDouble System::GetGLDouble(OpenGLQuery name) noexcept
{
    OpenGLDouble params{};
    GLGetDoublev(EnumCastUnderlying(name), &params);

    return params;
}

void System::GetGLDouble(OpenGLQuery name, OpenGLDouble* data) noexcept
{
    GLGetDoublev(EnumCastUnderlying(name), data);
}

void System::EnableGLState(OpenGLEnable cap) noexcept
{
    GLEnable(EnumCastUnderlying(cap));
}

void System::EnableGLState(OpenGLEnable target, OpenGLUInt index) noexcept
{
    GLEnablei(EnumCastUnderlying(target), index);
}

void System::DisableGLState(OpenGLEnable cap) noexcept
{
    GLDisable(EnumCastUnderlying(cap));
}

void System::DisableGLState(OpenGLEnable target, OpenGLUInt index) noexcept
{
    GLDisablei(EnumCastUnderlying(target), index);
}

void System::SetGLBlendColor(OpenGLFloat red, OpenGLFloat green, OpenGLFloat blue, OpenGLFloat alpha) noexcept
{
    GLBlendColor(red, green, blue, alpha);
}

void System::SetGLColorMask(OpenGLBoolean red, OpenGLBoolean green, OpenGLBoolean blue, OpenGLBoolean alpha) noexcept
{
    GLColorMask(red, green, blue, alpha);
}

void System::SetGLSampleMask(OpenGLUInt maskNumber, OpenGLBitfield mask) noexcept
{
    GLSampleMaski(maskNumber, mask);
}

void System::SetGLBlendFuncSeparate(BlendStateMode sourceFactorRGB, BlendStateMode destinationFactorRGB, BlendStateMode sourceFactorAlpha, BlendStateMode destinationFactorAlpha) noexcept
{
    GLBlendFuncSeparate(EnumCastUnderlying(sourceFactorRGB), EnumCastUnderlying(destinationFactorRGB), EnumCastUnderlying(sourceFactorAlpha), EnumCastUnderlying(destinationFactorAlpha));
}

void System::SetGLBlendEquationSeparate(BlendStateOperation modeRGB, BlendStateOperation modeAlpha) noexcept
{
    GLBlendEquationSeparate(EnumCastUnderlying(modeRGB), EnumCastUnderlying(modeAlpha));
}

void System::SetGLBlendEquationSeparate(OpenGLUInt index, BlendStateOperation modeRGB, BlendStateOperation modeAlpha) noexcept
{
    GLBlendEquationSeparatei(index, EnumCastUnderlying(modeRGB), EnumCastUnderlying(modeAlpha));
}

void System::SetGLBlendFuncSeparate(OpenGLUInt index, BlendStateMode sourceFactorRGB, BlendStateMode destinationFactorRGB, BlendStateMode sourceFactorAlpha, BlendStateMode destinationFactorAlpha) noexcept
{
    GLBlendFuncSeparatei(index, EnumCastUnderlying(sourceFactorRGB), EnumCastUnderlying(destinationFactorRGB), EnumCastUnderlying(sourceFactorAlpha), EnumCastUnderlying(destinationFactorAlpha));
}

void System::SetGLColorMask(OpenGLUInt index, OpenGLBoolean red, OpenGLBoolean green, OpenGLBoolean blue, OpenGLBoolean alpha) noexcept
{
    GLColorMaski(index, red, green, blue, alpha);
}

void System::SetGLDepthFunc(DepthStencilStateMode depthStencilStateMode) noexcept
{
    GLDepthFunc(EnumCastUnderlying(depthStencilStateMode));
}

void System::SetGLDepthMask(DepthStencilStateWriteMask flag) noexcept
{
    GLDepthMask(EnumCastUnderlying<OpenGLBoolean>(flag));
}

void System::SetGLStencilFuncSeparate(RasterizerStateCullFace face, DepthStencilStateMode func, OpenGLInt ref, OpenGLUInt mask) noexcept
{
    GLStencilFuncSeparate(EnumCastUnderlying(face), EnumCastUnderlying(func), ref, mask);
}

void System::SetGLStencilMaskSeparate(RasterizerStateCullFace face, OpenGLUInt mask) noexcept
{
    GLStencilMaskSeparate(EnumCastUnderlying(face), mask);
}

void System::SetGLStencilOpSeparate(RasterizerStateCullFace face, DepthStencilStateOperation sfail, DepthStencilStateOperation dpfail, DepthStencilStateOperation dppass) noexcept
{
    GLStencilOpSeparate(EnumCastUnderlying(face), EnumCastUnderlying(sfail), EnumCastUnderlying(dpfail), EnumCastUnderlying(dppass));
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