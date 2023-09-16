///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/29 23:28)

#ifndef SYSTEM_OPENGL_WGL_EXTENSIONS_USING_H
#define SYSTEM_OPENGL_WGL_EXTENSIONS_USING_H

#include "System/SystemDll.h"

#include "System/Helper/Detail/OpenGL/WglExtensionsMacro.h"
#include "System/Helper/Platform.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
#if defined(SYSTEM_PLATFORM_WIN32)

    using PixelFormatDescriptor = PIXELFORMATDESCRIPTOR;
    using HEnhMetaFile = HENHMETAFILE;
    using OpenGLHglrc = HGLRC;
    using OpenGLColorref = COLORREF;
    using LayerPlaneDescriptor = LAYERPLANEDESCRIPTOR;
    using PointFloat = POINTFLOAT;
    using GlyphMetricsFloat = GLYPHMETRICSFLOAT;
    using GlyphMetricsFloatPtr = LPGLYPHMETRICSFLOAT;
    using OpenGLProc = PROC;
    using WglHPBufferArb = HPBUFFERARB;
    using WglHPBufferExt = HPBUFFEREXT;
    using WglHGpuNv = HGPUNV;
    using WglGpuDevicePtr = PGPU_DEVICE;
    using WglHVideoOutputDeviceNv = HVIDEOOUTPUTDEVICENV;
    using WglHVideoInputDeviceNv = HVIDEOINPUTDEVICENV;
    using WglHPVideoDev = HPVIDEODEV;

#else  // !SYSTEM_PLATFORM_WIN32

    struct PixelFormatDescriptor
    {
        int16_t nSize;
        int16_t nVersion;
        uint32_t dwFlags;
        uint8_t iPixelType;
        uint8_t cColorBits;
        uint8_t cRedBits;
        uint8_t cRedShift;
        uint8_t cGreenBits;
        uint8_t cGreenShift;
        uint8_t cBlueBits;
        uint8_t cBlueShift;
        uint8_t cAlphaBits;
        uint8_t cAlphaShift;
        uint8_t cAccumBits;
        uint8_t cAccumRedBits;
        uint8_t cAccumGreenBits;
        uint8_t cAccumBlueBits;
        uint8_t cAccumAlphaBits;
        uint8_t cDepthBits;
        uint8_t cStencilBits;
        uint8_t cAuxBuffers;
        uint8_t iLayerType;
        uint8_t bReserved;
        uint32_t dwLayerMask;
        uint32_t dwVisibleMask;
        uint32_t dwDamageMask;
    };

    struct HEnhMetaFileDeclare
    {
        int unused;
    };
    using HEnhMetaFile = struct HEnhMetaFileDeclare*;

    struct OpenGLHglrcDeclare
    {
        int unused;
    };
    using OpenGLHglrc = OpenGLHglrcDeclare*;

    using OpenGLColorref = uint32_t;

    struct LayerPlaneDescriptor
    {
        int16_t nSize;
        int16_t nVersion;
        uint32_t dwFlags;
        uint8_t iPixelType;
        uint8_t cColorBits;
        uint8_t cRedBits;
        uint8_t cRedShift;
        uint8_t cGreenBits;
        uint8_t cGreenShift;
        uint8_t cBlueBits;
        uint8_t cBlueShift;
        uint8_t cAlphaBits;
        uint8_t cAlphaShift;
        uint8_t cAccumBits;
        uint8_t cAccumRedBits;
        uint8_t cAccumGreenBits;
        uint8_t cAccumBlueBits;
        uint8_t cAccumAlphaBits;
        uint8_t cDepthBits;
        uint8_t cStencilBits;
        uint8_t cAuxBuffers;
        uint8_t layerPlane;
        uint8_t bReserved;
        OpenGLColorref crTransparent;
    };

    struct PointFloat
    {
        float x;
        float y;
    };

    struct GlyphMetricsFloat
    {
        float gmfBlackBoxX;
        float gmfBlackBoxY;
        PointFloat gmfptGlyphOrigin;
        float gmfCellIncX;
        float gmfCellIncY;
    };
    using GlyphMetricsFloatPtr = GlyphMetricsFloat*;

    using OpenGLProc = int (*)();

    struct WglHPBufferARBDeclare
    {
        int unused;
    };
    using WglHPBufferArb = WglHPBufferARBDeclare*;
    using WglHPBufferExt = WglHPBufferArb;

    struct WglHGPUNVDeclare
    {
        int unused;
    };
    using WglHGpuNv = WglHGPUNVDeclare*;

    struct WglGpuDevice
    {
        unsigned int cb;
        char DeviceName[32];
        char DeviceString[128];
        unsigned int Flags;
        WindowsRect rcVirtualScreen;
    };
    using WglGpuDevicePtr = WglGpuDevice*;

    struct WglHVideoOutputDeviceNVDeclare
    {
        int unused;
    };
    using WglHVideoOutputDeviceNv = WglHVideoOutputDeviceNVDeclare*;

    struct WglHVideoInputDeviceNVDeclare
    {
        int unused;
    };
    using WglHVideoInputDeviceNv = WglHVideoInputDeviceNVDeclare*;

    struct WglHPVideoDEVDeclare
    {
        int unused;
    };
    using WglHPVideoDev = WglHPVideoDEVDeclare*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_OPENGL_WGL_EXTENSIONS_USING_H
