///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.5 (2021/06/24 23:26)

#include "System/SystemExport.h"

#include "OpenGLAPI.h"
#include "Flags/GLExtensionsFlags.h"
#include "Flags/OpenGLFlags.h"
#include "Detail/GL10Extensions.h"
#include "Detail/GL11Extensions.h"
#include "Detail/GL12Extensions.h"
#include "Detail/GL13Extensions.h"
#include "Detail/GL14Extensions.h"
#include "Detail/GL15Extensions.h"
#include "Detail/GL20Extensions.h"
#include "Detail/GL30Extensions.h"
#include "System/Helper/EnumCast.h"

void System::ClearAllGLBufferBit() noexcept
{
    GLClear(EnumCastUnderlying(OpenGLClearMask::ColorBufferBit | OpenGLClearMask::DepthBufferBit | OpenGLClearMask::StencilBufferBit));
}

void System::SetGLViewport(OpenGLInt x, OpenGLInt y, OpenGLSize width, OpenGLSize height) noexcept
{
    GLViewport(x, y, width, height);
}

void System::SetupRenderStatus() noexcept
{
    GLClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    GLClearStencil(0);
    GLClearDepth(1.0);

    GLEnable(GL_DEPTH_TEST);
    GLFrontFace(GL_CCW);
    GLEnable(GL_CULL_FACE);
}

void System::SetGLDepthRange(OpenGLDouble nearDepthRange, OpenGLDouble farDepthRange) noexcept
{
    GLDepthRange(nearDepthRange, farDepthRange);
}

System::OpenGLInt System::GetGLInteger(OpenGLQuery name) noexcept
{
    OpenGLInt params{};
    GLGetIntegerv(EnumCastUnderlying(name), &params);

    return params;
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
