///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.0 (2023/01/12 22:41)

#ifndef SYSTEM_OPENGL_OPENGL_WGL_PROTOTYPES_FLAGS_H
#define SYSTEM_OPENGL_OPENGL_WGL_PROTOTYPES_FLAGS_H

#include "System/Helper/EnumOperator.h"
#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class PixelFormatDescriptorFlags : uint32_t
    {
        DoubleBuffer = PFD_DOUBLEBUFFER,
        Stereo = PFD_STEREO,
        DrawToWindow = PFD_DRAW_TO_WINDOW,
        DrawToBitmap = PFD_DRAW_TO_BITMAP,
        SupportGdi = PFD_SUPPORT_GDI,
        SupportOpengl = PFD_SUPPORT_OPENGL,
        GenericFormat = PFD_GENERIC_FORMAT,
        NeedPalette = PFD_NEED_PALETTE,
        NeedSystemPalette = PFD_NEED_SYSTEM_PALETTE,
        SwapExchange = PFD_SWAP_EXCHANGE,
        SwapCopy = PFD_SWAP_COPY,
        SwapLayerBuffers = PFD_SWAP_LAYER_BUFFERS,
        GenericAccelerated = PFD_GENERIC_ACCELERATED,
        SupportDirectdraw = PFD_SUPPORT_DIRECTDRAW,
        Direct3dAccelerated = PFD_DIRECT3D_ACCELERATED,
        SupportComposition = PFD_SUPPORT_COMPOSITION,
        DepthDontcare = PFD_DEPTH_DONTCARE,
        DoublebufferDontcare = PFD_DOUBLEBUFFER_DONTCARE,
        StereoDontcare = PFD_STEREO_DONTCARE,
    };

    enum class PixelTypes
    {
        TypeRGBA = PFD_TYPE_RGBA,
        TypeColorIndex = PFD_TYPE_COLORINDEX,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class PixelFormatDescriptorFlags : uint32_t
    {
        DoubleBuffer = 0x00000001,
        Stereo = 0x00000002,
        DrawToWindow = 0x00000004,
        DrawToBitmap = 0x00000008,
        SupportGdi = 0x00000010,
        SupportOpengl = 0x00000020,
        GenericFormat = 0x00000040,
        NeedPalette = 0x00000080,
        NeedSystemPalette = 0x00000100,
        SwapExchange = 0x00000200,
        SwapCopy = 0x00000400,
        SwapLayerBuffers = 0x00000800,
        GenericAccelerated = 0x00001000,
        SupportDirectdraw = 0x00002000,
        Direct3dAccelerated = 0x00004000,
        SupportComposition = 0x00008000,
        DepthDontcare = 0x20000000,
        DoublebufferDontcare = 0x40000000,
        StereoDontcare = 0x80000000,
    };

    enum class PixelTypes
    {
        TypeRGBA = 0,
        TypeColorIndex = 1,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_OPENGL_OPENGL_WGL_PROTOTYPES_FLAGS_H