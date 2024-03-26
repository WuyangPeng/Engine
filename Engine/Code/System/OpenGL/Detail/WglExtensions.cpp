/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/02 23:20)

#include "System/SystemExport.h"

#include "GLExtensions.h"
#include "WglExtensions.h"
#include "System/CharacterString/FormatString.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "System/OpenGL/OpenGLWglPrototypes.h"

namespace System
{
    auto existsWgl10 = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWgl10() noexcept
{
    return existsWgl10;
}

void System::InitWgl10() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    existsWgl10 = ExistsOpenGLExtensions::Exists;

#else  // !SYSTEM_PLATFORM_WIN32

    existsWgl10 = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::ChoosePixelFormat(WindowsHdc hdc, const PixelFormatDescriptor* pixelFormatDescriptor) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::ChoosePixelFormat(hdc, pixelFormatDescriptor);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, pixelFormatDescriptor);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::DescribePixelFormat(WindowsHdc hdc, int iPixelFormat, WindowsUInt nBytes, PixelFormatDescriptor* pixelFormatDescriptor) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::DescribePixelFormat(hdc, iPixelFormat, nBytes, pixelFormatDescriptor);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, iPixelFormat, nBytes, pixelFormatDescriptor);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsUInt System::GetEnhMetaFilePixelFormat(HEnhMetaFile hEnhMetaFile, WindowsUInt cbBuffer, PixelFormatDescriptor* pixelFormatDescriptor) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::GetEnhMetaFilePixelFormat(hEnhMetaFile, cbBuffer, pixelFormatDescriptor);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hEnhMetaFile, cbBuffer, pixelFormatDescriptor);

    return 0u;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::GetPixelFormat(WindowsHdc hdc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::GetPixelFormat(hdc);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc);

    return 0u;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::SetPixelFormat(WindowsHdc hdc, int format, const PixelFormatDescriptor* pixelFormatDescriptor) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::SetPixelFormat(hdc, format, pixelFormatDescriptor);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, format, pixelFormatDescriptor);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::SwapBuffers(WindowsHdc hdc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::SwapBuffers(hdc);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglCopyContext(OpenGLRcHandle hGlRcSrc, OpenGLRcHandle hGlRcDst, WindowsUInt mask) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglCopyContext(hGlRcSrc, hGlRcDst, mask);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hGlRcSrc, hGlRcDst, mask);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::OpenGLRcHandle System::WglCreateContext(WindowsHdc hdc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglCreateContext(hdc);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::OpenGLRcHandle System::WglCreateLayerContext(WindowsHdc hdc, int level) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglCreateLayerContext(hdc, level);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, level);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDeleteContext(OpenGLRcHandle oldContext) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglDeleteContext(oldContext);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(oldContext);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDescribeLayerPlane(WindowsHdc hdc, int pixelFormat, int layerPlane, WindowsUInt bytes, LayerPlaneDescriptor* layerPlaneDescriptor) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglDescribeLayerPlane(hdc, pixelFormat, layerPlane, bytes, layerPlaneDescriptor);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, pixelFormat, layerPlane, bytes, layerPlaneDescriptor);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::OpenGLRcHandle System::WglGetCurrentContext() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglGetCurrentContext();

#else  // !SYSTEM_PLATFORM_WIN32

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHdc System::WglGetCurrentDC() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglGetCurrentDC();

#else  // !SYSTEM_PLATFORM_WIN32

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::WglGetLayerPaletteEntries(WindowsHdc hdc, int layerPlane, int start, int entries, OpenGLColorRef* pcr) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglGetLayerPaletteEntries(hdc, layerPlane, start, entries, pcr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, layerPlane, start, entries, pcr);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::OpenGLProc System::WglGetProcAddress(const char* proc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglGetProcAddress(proc);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(proc);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglMakeCurrent(WindowsHdc hdc, OpenGLRcHandle newContext) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglMakeCurrent(hdc, newContext);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, newContext);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglRealizeLayerPalette(WindowsHdc hdc, int layerPlane, WindowsBool realize) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglRealizeLayerPalette(hdc, layerPlane, realize);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, layerPlane, realize);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::WglSetLayerPaletteEntries(WindowsHdc hdc, int layerPlane, int start, int entries, const OpenGLColorRef* pcr) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglSetLayerPaletteEntries(hdc, layerPlane, start, entries, pcr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, layerPlane, start, entries, pcr);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglShareLists(OpenGLRcHandle hrcSrvShare, OpenGLRcHandle hrcSrvSource) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglShareLists(hrcSrvShare, hrcSrvSource);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hrcSrvShare, hrcSrvSource);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglSwapLayerBuffers(WindowsHdc hdc, WindowsUInt fuFlags) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglSwapLayerBuffers(hdc, fuFlags);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, fuFlags);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglUseFontBitmaps(WindowsHdc hdc, WindowsDWord first, WindowsDWord count, WindowsDWord listBase) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglUseFontBitmaps(hdc, first, count, listBase);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, first, count, listBase);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglUseFontBitmapsA(WindowsHdc hdc, WindowsDWord first, WindowsDWord count, WindowsDWord listBase) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglUseFontBitmapsA(hdc, first, count, listBase);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, first, count, listBase);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglUseFontBitmapsW(WindowsHdc hdc, WindowsDWord first, WindowsDWord count, WindowsDWord listBase) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglUseFontBitmapsW(hdc, first, count, listBase);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, first, count, listBase);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglUseFontOutlines(WindowsHdc hdc, WindowsDWord first, WindowsDWord count, WindowsDWord listBase, float deviation, float extrusion, int format, GlyphMetricsFloatPtr glyphMetricsFloat) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglUseFontOutlines(hdc, first, count, listBase, deviation, extrusion, format, glyphMetricsFloat);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, first, count, listBase, deviation, extrusion, format, glyphMetricsFloat);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglUseFontOutlinesA(WindowsHdc hdc, WindowsDWord first, WindowsDWord count, WindowsDWord listBase, float deviation, float extrusion, int format, GlyphMetricsFloatPtr glyphMetricsFloat) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglUseFontOutlinesA(hdc, first, count, listBase, deviation, extrusion, format, glyphMetricsFloat);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, first, count, listBase, deviation, extrusion, format, glyphMetricsFloat);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglUseFontOutlinesW(WindowsHdc hdc, WindowsDWord first, WindowsDWord count, WindowsDWord listBase, float deviation, float extrusion, int format, GlyphMetricsFloatPtr glyphMetricsFloat) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglUseFontOutlinesW(hdc, first, count, listBase, deviation, extrusion, format, glyphMetricsFloat);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, first, count, listBase, deviation, extrusion, format, glyphMetricsFloat);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// ARB 扩展

/// WGL_ARB_buffer_region

namespace System
{
    auto existsWglArbBufferRegion = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLCREATEBUFFERREGIONARBPROC wglCreateBufferRegionARB{ nullptr };
    PFNWGLDELETEBUFFERREGIONARBPROC wglDeleteBufferRegionARB{ nullptr };
    PFNWGLSAVEBUFFERREGIONARBPROC wglSaveBufferRegionARB{ nullptr };
    PFNWGLRESTOREBUFFERREGIONARBPROC wglRestoreBufferRegionARB{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglArbBufferRegion() noexcept
{
    return existsWglArbBufferRegion;
}

void System::InitWglArbBufferRegion()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_ARB_buffer_region") || IsOpenGLSupportsExtension("WGL_ARB_buffer_region"))
    {
        existsWglArbBufferRegion = ExistsOpenGLExtensions::Exists;

        SYSTEM_GET_FUNCTION(wglCreateBufferRegionARB);
        SYSTEM_GET_FUNCTION(wglDeleteBufferRegionARB);
        SYSTEM_GET_FUNCTION(wglSaveBufferRegionARB);
        SYSTEM_GET_FUNCTION(wglRestoreBufferRegionARB);
    }
    else
    {
        existsWglArbBufferRegion = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglArbBufferRegion = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHandle System::WglCreateBufferRegionARB(WindowsHdc hdc, int layerPlane, WindowsUInt type) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglCreateBufferRegionARB, hdc, layerPlane, type, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, layerPlane, type);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::WglDeleteBufferRegionARB(WindowsHandle region) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1(wglDeleteBufferRegionARB, region);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(region);

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglSaveBufferRegionARB(WindowsHandle region, int x, int y, int width, int height) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_5_RESULT(wglSaveBufferRegionARB, region, x, y, width, height, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(region, x, y, width, height);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglRestoreBufferRegionARB(WindowsHandle region, int x, int y, int width, int height, int xSrc, int ySrc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_7_RESULT(wglRestoreBufferRegionARB, region, x, y, width, height, xSrc, ySrc, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(region, x, y, width, height, xSrc, ySrc);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_ARB_context_flush_control

namespace System
{
    auto existsWglArbContextFlushControl = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglArbContextFlushControl() noexcept
{
    return existsWglArbContextFlushControl;
}

void System::InitWglArbContextFlushControl()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_ARB_context_flush_control") || IsOpenGLSupportsExtension("WGL_ARB_context_flush_control"))
    {
        existsWglArbContextFlushControl = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglArbContextFlushControl = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglArbContextFlushControl = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_ARB_create_context

namespace System
{
    auto existsWglArbCreateContext = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglArbCreateContext() noexcept
{
    return existsWglArbCreateContext;
}

void System::InitWglArbCreateContext()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_ARB_create_context") || IsOpenGLSupportsExtension("WGL_ARB_create_context"))
    {
        SYSTEM_GET_FUNCTION(wglCreateContextAttribsARB);

        existsWglArbCreateContext = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglArbCreateContext = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglArbCreateContext = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::OpenGLRcHandle System::WglCreateContextAttribSArb(WindowsHdc hdc, OpenGLRcHandle shareContext, const int* attribList) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglCreateContextAttribsARB, hdc, shareContext, attribList, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, shareContext, attribList);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_ARB_create_context_no_error

namespace System
{
    auto existsWglArbCreateContextNoError = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglArbCreateContextNoError() noexcept
{
    return existsWglArbCreateContextNoError;
}

void System::InitWglArbCreateContextNoError()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_ARB_create_context_no_error") || IsOpenGLSupportsExtension("WGL_ARB_create_context_no_error"))
    {
        existsWglArbCreateContextNoError = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglArbCreateContextNoError = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglArbCreateContextNoError = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_ARB_create_context_profile

namespace System
{
    auto existsWglArbCreateContextProfile = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglArbCreateContextProfile() noexcept
{
    return existsWglArbCreateContextProfile;
}

void System::InitWglArbCreateContextProfile()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_ARB_create_context_profile") || IsOpenGLSupportsExtension("WGL_ARB_create_context_profile"))
    {
        existsWglArbCreateContextProfile = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglArbCreateContextProfile = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglArbCreateContextProfile = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_ARB_create_context_robustness

namespace System
{
    auto existsWglArbCreateContextRobustness = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglArbCreateContextRobustness() noexcept
{
    return existsWglArbCreateContextRobustness;
}

void System::InitWglArbCreateContextRobustness()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_ARB_create_context_robustness") || IsOpenGLSupportsExtension("WGL_ARB_create_context_robustness"))
    {
        existsWglArbCreateContextRobustness = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglArbCreateContextRobustness = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglArbCreateContextRobustness = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_ARB_extensions_string

namespace System
{
    auto existsWglArbExtensionsString = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLGETEXTENSIONSSTRINGARBPROC wglGetExtensionsStringARB{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglArbExtensionsString() noexcept
{
    return existsWglArbExtensionsString;
}

void System::InitWglArbExtensionsString() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_GET_FUNCTION(wglGetExtensionsStringARB);

    if (wglGetExtensionsStringARB != nullptr)
    {
        existsWglArbExtensionsString = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglArbExtensionsString = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglArbExtensionsString = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

const char* System::WglGetExtensionsStringARB(WindowsHdc hdc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglGetExtensionsStringARB, hdc, "");

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc);

    return "";

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_ARB_framebuffer_sRGB

namespace System
{
    auto existsWglArbFramebufferSRGB = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglArbFrameBuffersRGB() noexcept
{
    return existsWglArbFramebufferSRGB;
}

void System::InitWglArbFrameBuffersRGB()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_ARB_framebuffer_sRGB") || IsOpenGLSupportsExtension("WGL_ARB_framebuffer_sRGB"))
    {
        existsWglArbFramebufferSRGB = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglArbFramebufferSRGB = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglArbFramebufferSRGB = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_ARB_make_current_read

namespace System
{
    auto existsWglArbMakeCurrentRead = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLMAKECONTEXTCURRENTARBPROC wglMakeContextCurrentARB{ nullptr };
    PFNWGLGETCURRENTREADDCARBPROC wglGetCurrentReadDCARB{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglArbMakeCurrentRead() noexcept
{
    return existsWglArbMakeCurrentRead;
}

void System::InitWglArbMakeCurrentRead()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_ARB_make_current_read") || IsOpenGLSupportsExtension("WGL_ARB_make_current_read"))
    {
        SYSTEM_GET_FUNCTION(wglMakeContextCurrentARB);
        SYSTEM_GET_FUNCTION(wglGetCurrentReadDCARB);

        existsWglArbMakeCurrentRead = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglArbMakeCurrentRead = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglArbMakeCurrentRead = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglMakeContextCurrentARB(WindowsHdc drawDC, WindowsHdc readDC, OpenGLRcHandle hGlRc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglMakeContextCurrentARB, drawDC, readDC, hGlRc, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(drawDC, readDC, hGlRc);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHdc System::WglGetCurrentReadDcARB() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_0_RESULT(wglGetCurrentReadDCARB, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_ARB_multisample

namespace System
{
    auto existsWglArbMultiSample = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglArbMultiSample() noexcept
{
    return existsWglArbMultiSample;
}

void System::InitWglArbMultiSample()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_ARB_multisample") || IsOpenGLSupportsExtension("WGL_ARB_multisample"))
    {
        existsWglArbMultiSample = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglArbMultiSample = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglArbMultiSample = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_ARB_pbuffer

namespace System
{
    auto existsWglArbPBuffer = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLCREATEPBUFFERARBPROC wglCreatePbufferARB{ nullptr };
    PFNWGLGETPBUFFERDCARBPROC wglGetPbufferDCARB{ nullptr };
    PFNWGLRELEASEPBUFFERDCARBPROC wglReleasePbufferDCARB{ nullptr };
    PFNWGLDESTROYPBUFFERARBPROC wglDestroyPbufferARB{ nullptr };
    PFNWGLQUERYPBUFFERARBPROC wglQueryPbufferARB{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglArbPBuffer() noexcept
{
    return existsWglArbPBuffer;
}

void System::InitWglArbPBuffer()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_ARB_pbuffer") || IsOpenGLSupportsExtension("WGL_ARB_pbuffer"))
    {
        SYSTEM_GET_FUNCTION(wglCreatePbufferARB);
        SYSTEM_GET_FUNCTION(wglGetPbufferDCARB);
        SYSTEM_GET_FUNCTION(wglReleasePbufferDCARB);
        SYSTEM_GET_FUNCTION(wglDestroyPbufferARB);
        SYSTEM_GET_FUNCTION(wglQueryPbufferARB);

        existsWglArbPBuffer = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglArbPBuffer = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglArbPBuffer = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WglHpBufferArb System::WglCreatePBufferARB(WindowsHdc hdC, int pixelFormat, int width, int height, const int* piAttribList) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_5_RESULT(wglCreatePbufferARB, hdC, pixelFormat, width, height, piAttribList, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdC, pixelFormat, width, height, piAttribList);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHdc System::WglGetPBufferDcARB(WglHpBufferArb hPBuffer) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglGetPbufferDCARB, hPBuffer, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hPBuffer);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::WglReleasePBufferDcARB(WglHpBufferArb hPBuffer, WindowsHdc hdc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglReleasePbufferDCARB, hPBuffer, hdc, 0);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hPBuffer, hdc);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDestroyPBufferARB(WglHpBufferArb hPBuffer) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglDestroyPbufferARB, hPBuffer, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hPBuffer);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglQueryPBufferARB(WglHpBufferArb hPBuffer, int attribute, int* piValue) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglQueryPbufferARB, hPBuffer, attribute, piValue, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hPBuffer, attribute, piValue);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_ARB_pixel_format

namespace System
{
    auto existsWglArbPixelFormat = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLGETPIXELFORMATATTRIBIVARBPROC wglGetPixelFormatAttribivARB{ nullptr };
    PFNWGLGETPIXELFORMATATTRIBFVARBPROC wglGetPixelFormatAttribfvARB{ nullptr };
    PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglArbPixelFormat() noexcept
{
    return existsWglArbPixelFormat;
}

void System::InitWglArbPixelFormat()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_ARB_pixel_format") || IsOpenGLSupportsExtension("WGL_ARB_pixel_format"))
    {
        SYSTEM_GET_FUNCTION(wglGetPixelFormatAttribivARB);
        SYSTEM_GET_FUNCTION(wglGetPixelFormatAttribfvARB);
        SYSTEM_GET_FUNCTION(wglChoosePixelFormatARB);

        existsWglArbPixelFormat = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglArbPixelFormat = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglArbPixelFormat = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGetPixelFormatAttribIvARB(WindowsHdc hdc, int pixelFormat, int layerPlane, WindowsUInt attributes, const int* piAttributes, int* piValues) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_6_RESULT(wglGetPixelFormatAttribivARB, hdc, pixelFormat, layerPlane, attributes, piAttributes, piValues, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, pixelFormat, layerPlane, attributes, piAttributes, piValues);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGetPixelFormatAttribFvARB(WindowsHdc hdc, int pixelFormat, int layerPlane, WindowsUInt attributes, const int* piAttributes, float* pfValues) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_6_RESULT(wglGetPixelFormatAttribfvARB, hdc, pixelFormat, layerPlane, attributes, piAttributes, pfValues, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, pixelFormat, layerPlane, attributes, piAttributes, pfValues);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglChoosePixelFormatARB(WindowsHdc hdc, const int* piAttribIList, const float* pfAttribFList, WindowsUInt maxFormats, int* piFormats, WindowsUInt* numFormats) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_6_RESULT(wglChoosePixelFormatARB, hdc, piAttribIList, pfAttribFList, maxFormats, piFormats, numFormats, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, piAttribIList, pfAttribFList, maxFormats, piFormats, numFormats);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_ARB_pixel_format_float

namespace System
{
    auto existsWglArbPixelFormatFloat = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglArbPixelFormatFloat() noexcept
{
    return existsWglArbPixelFormatFloat;
}

void System::InitWglArbPixelFormatFloat()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_ARB_pixel_format_float") || IsOpenGLSupportsExtension("WGL_ARB_pixel_format_float"))
    {
        existsWglArbPixelFormatFloat = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglArbPixelFormatFloat = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglArbPixelFormatFloat = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_ARB_render_texture

namespace System
{
    auto existsWglArbRenderTexture = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLBINDTEXIMAGEARBPROC wglBindTexImageARB{ nullptr };
    PFNWGLRELEASETEXIMAGEARBPROC wglReleaseTexImageARB{ nullptr };
    PFNWGLSETPBUFFERATTRIBARBPROC wglSetPbufferAttribARB{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglArbRenderTexture() noexcept
{
    return existsWglArbRenderTexture;
}

void System::InitWglArbRenderTexture()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_ARB_render_texture") || IsOpenGLSupportsExtension("WGL_ARB_render_texture"))
    {
        SYSTEM_GET_FUNCTION(wglBindTexImageARB);
        SYSTEM_GET_FUNCTION(wglReleaseTexImageARB);
        SYSTEM_GET_FUNCTION(wglSetPbufferAttribARB);

        existsWglArbRenderTexture = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglArbRenderTexture = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglArbRenderTexture = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglBindTexImageARB(WglHpBufferArb hPBuffer, int buffer) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglBindTexImageARB, hPBuffer, buffer, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hPBuffer, buffer);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglReleaseTexImageARB(WglHpBufferArb hPBuffer, int buffer) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglReleaseTexImageARB, hPBuffer, buffer, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hPBuffer, buffer);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglSetPBufferAttribARB(WglHpBufferArb hPBuffer, const int* piAttribList) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglSetPbufferAttribARB, hPBuffer, piAttribList, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hPBuffer, piAttribList);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_ARB_robustness_application_isolation

namespace System
{
    auto existsWglArbRobustnessApplicationIsolation = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglArbRobustnessApplicationIsolation() noexcept
{
    return existsWglArbRobustnessApplicationIsolation;
}

void System::InitWglArbRobustnessApplicationIsolation()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_ARB_robustness_application_isolation") || IsOpenGLSupportsExtension("WGL_ARB_robustness_application_isolation"))
    {
        existsWglArbRobustnessApplicationIsolation = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglArbRobustnessApplicationIsolation = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglArbRobustnessApplicationIsolation = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_ARB_robustness_share_group_isolation

namespace System
{
    auto existsWglArbRobustnessShareGroupIsolation = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglArbRobustnessShareGroupIsolation() noexcept
{
    return existsWglArbRobustnessShareGroupIsolation;
}

void System::InitWglArbRobustnessShareGroupIsolation()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_ARB_robustness_share_group_isolation") || IsOpenGLSupportsExtension("WGL_ARB_robustness_share_group_isolation"))
    {
        existsWglArbRobustnessShareGroupIsolation = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglArbRobustnessShareGroupIsolation = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglArbRobustnessShareGroupIsolation = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// 3DFX 扩展

/// WGL_3DFX_multisample

namespace System
{
    auto existsWgl3DFXMultiSample = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWgl3DfxMultiSample() noexcept
{
    return existsWgl3DFXMultiSample;
}

void System::InitWgl3DfxMultiSample()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_3DFX_multisample") || IsOpenGLSupportsExtension("WGL_3DFX_multisample"))
    {
        existsWgl3DFXMultiSample = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWgl3DFXMultiSample = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWgl3DFXMultiSample = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// 3DL 扩展

/// WGL_3DL_stereo_control

namespace System
{
    auto existsWgl3DLStereoControl = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLSETSTEREOEMITTERSTATE3DLPROC wglSetStereoEmitterState3DL{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWgl3DlStereoControl() noexcept
{
    return existsWgl3DLStereoControl;
}

void System::InitWgl3DlStereoControl()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_3DL_stereo_control") || IsOpenGLSupportsExtension("WGL_3DL_stereo_control"))
    {
        SYSTEM_GET_FUNCTION(wglSetStereoEmitterState3DL);

        existsWgl3DLStereoControl = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWgl3DLStereoControl = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWgl3DLStereoControl = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglSetStereoEmitterState3Dl(WindowsHdc hdC, WindowsUInt state) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglSetStereoEmitterState3DL, hdC, state, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdC, state);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// AMD 扩展

/// WGL_AMD_gpu_association

namespace System
{
    auto existsWglAMDGpuAssociation = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLGETGPUIDSAMDPROC wglGetGPUIDsAMD{ nullptr };
    PFNWGLGETGPUINFOAMDPROC wglGetGPUInfoAMD{ nullptr };
    PFNWGLGETCONTEXTGPUIDAMDPROC wglGetContextGPUIDAMD{ nullptr };
    PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC wglCreateAssociatedContextAMD{ nullptr };
    PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC wglCreateAssociatedContextAttribsAMD{ nullptr };
    PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC wglDeleteAssociatedContextAMD{ nullptr };
    PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC wglMakeAssociatedContextCurrentAMD{ nullptr };
    PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC wglGetCurrentAssociatedContextAMD{ nullptr };
    PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC wglBlitContextFramebufferAMD{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglAMDGpuAssociation() noexcept
{
    return existsWglAMDGpuAssociation;
}

void System::InitWglAMDGpuAssociation()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_AMD_gpu_association") || IsOpenGLSupportsExtension("WGL_AMD_gpu_association"))
    {
        SYSTEM_GET_FUNCTION(wglGetGPUIDsAMD);
        SYSTEM_GET_FUNCTION(wglGetGPUInfoAMD);
        SYSTEM_GET_FUNCTION(wglGetContextGPUIDAMD);
        SYSTEM_GET_FUNCTION(wglCreateAssociatedContextAMD);
        SYSTEM_GET_FUNCTION(wglCreateAssociatedContextAttribsAMD);
        SYSTEM_GET_FUNCTION(wglDeleteAssociatedContextAMD);
        SYSTEM_GET_FUNCTION(wglMakeAssociatedContextCurrentAMD);
        SYSTEM_GET_FUNCTION(wglGetCurrentAssociatedContextAMD);
        SYSTEM_GET_FUNCTION(wglBlitContextFramebufferAMD);

        existsWglAMDGpuAssociation = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglAMDGpuAssociation = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglAMDGpuAssociation = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsUInt System::WglGetGpuIdsAMD(WindowsUInt maxCount, WindowsUInt* ids) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglGetGPUIDsAMD, maxCount, ids, 0u);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(maxCount, ids);

    return 0u;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsInt System::WglGetGpuInfoAMD(WindowsUInt id, WindowsInt property, GLenum dataType, WindowsUInt size, void* data) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_5_RESULT(wglGetGPUInfoAMD, id, property, dataType, size, data, 0);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(id, property, dataType, size, data);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsUInt System::WglGetContextGpuIdAMD(OpenGLRcHandle hGlRc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglGetContextGPUIDAMD, hGlRc, 0u);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hGlRc);

    return 0u;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::OpenGLRcHandle System::WglCreateAssociatedContextAMD(WindowsUInt id) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglCreateAssociatedContextAMD, id, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(id);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::OpenGLRcHandle System::WglCreateAssociatedContextAttribSAmd(WindowsUInt id, OpenGLRcHandle hShareContext, const int* attribList) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglCreateAssociatedContextAttribsAMD, id, hShareContext, attribList, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(id, hShareContext, attribList);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDeleteAssociatedContextAMD(OpenGLRcHandle hGlRc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglDeleteAssociatedContextAMD, hGlRc, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hGlRc);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglMakeAssociatedContextCurrentAMD(OpenGLRcHandle hGlRc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglMakeAssociatedContextCurrentAMD, hGlRc, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hGlRc);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::OpenGLRcHandle System::WglGetCurrentAssociatedContextAMD() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_0_RESULT(wglGetCurrentAssociatedContextAMD, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::WglBlitContextFrameBufferAMD(OpenGLRcHandle dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_11(wglBlitContextFramebufferAMD, dstCtx, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(dstCtx, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);

#endif  // SYSTEM_PLATFORM_WIN32
}

/// ATI 扩展

/// WGL_ATI_pixel_format_float

namespace System
{
    auto existsWglATIPixelFormatFloat = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglATIPixelFormatFloat() noexcept
{
    return existsWglATIPixelFormatFloat;
}

void System::InitWglATIPixelFormatFloat()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_ATI_pixel_format_float") || IsOpenGLSupportsExtension("WGL_ATI_pixel_format_float"))
    {
        existsWglATIPixelFormatFloat = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglATIPixelFormatFloat = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglATIPixelFormatFloat = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_ATI_render_texture_rectangle

namespace System
{
    auto existsWglATIRenderTextureRectangle = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglATIRenderTextureRectangle() noexcept
{
    return existsWglATIRenderTextureRectangle;
}

void System::InitWglATIRenderTextureRectangle()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_ATI_render_texture_rectangle") || IsOpenGLSupportsExtension("WGL_ATI_render_texture_rectangle"))
    {
        existsWglATIRenderTextureRectangle = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglATIRenderTextureRectangle = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglATIRenderTextureRectangle = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// EXT 扩展

/// WGL_EXT_colorspace

namespace System
{
    auto existsWglExtColorSpace = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglExtColorSpace() noexcept
{
    return existsWglExtColorSpace;
}

void System::InitWglExtColorSpace()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_EXT_colorspace") || IsOpenGLSupportsExtension("WGL_EXT_colorspace"))
    {
        existsWglExtColorSpace = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglExtColorSpace = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglExtColorSpace = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_EXT_create_context_es2_profile

namespace System
{
    auto existsWglExtCreateContextEs2Profile = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglExtCreateContextEs2Profile() noexcept
{
    return existsWglExtCreateContextEs2Profile;
}

void System::InitWglExtCreateContextEs2Profile()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_EXT_create_context_es2_profile") || IsOpenGLSupportsExtension("WGL_EXT_create_context_es2_profile"))
    {
        existsWglExtCreateContextEs2Profile = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglExtCreateContextEs2Profile = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglExtCreateContextEs2Profile = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_EXT_create_context_es_profile

namespace System
{
    auto existsWglExtCreateContextEsProfile = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglExtCreateContextEsProfile() noexcept
{
    return existsWglExtCreateContextEsProfile;
}

void System::InitWglExtCreateContextEsProfile()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_EXT_create_context_es_profile") || IsOpenGLSupportsExtension("WGL_EXT_create_context_es_profile"))
    {
        existsWglExtCreateContextEsProfile = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglExtCreateContextEsProfile = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglExtCreateContextEsProfile = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_EXT_depth_float

namespace System
{
    auto existsWglExtDepthFloat = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglExtDepthFloat() noexcept
{
    return existsWglExtDepthFloat;
}

void System::InitWglExtDepthFloat()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_EXT_depth_float") || IsOpenGLSupportsExtension("WGL_EXT_depth_float"))
    {
        existsWglExtDepthFloat = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglExtDepthFloat = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglExtDepthFloat = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_EXT_display_color_table

namespace System
{
    auto existsWglExtDisplayColorTable = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC wglCreateDisplayColorTableEXT{ nullptr };
    PFNWGLLOADDISPLAYCOLORTABLEEXTPROC wglLoadDisplayColorTableEXT{ nullptr };
    PFNWGLBINDDISPLAYCOLORTABLEEXTPROC wglBindDisplayColorTableEXT{ nullptr };
    PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC wglDestroyDisplayColorTableEXT{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglExtDisplayColorTable() noexcept
{
    return existsWglExtDisplayColorTable;
}

void System::InitWglExtDisplayColorTable()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_EXT_display_color_table") || IsOpenGLSupportsExtension("WGL_EXT_display_color_table"))
    {
        SYSTEM_GET_FUNCTION(wglCreateDisplayColorTableEXT);
        SYSTEM_GET_FUNCTION(wglLoadDisplayColorTableEXT);
        SYSTEM_GET_FUNCTION(wglBindDisplayColorTableEXT);
        SYSTEM_GET_FUNCTION(wglDestroyDisplayColorTableEXT);

        existsWglExtDisplayColorTable = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglExtDisplayColorTable = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglExtDisplayColorTable = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

GLboolean System::WglCreateDisplayColorTableEXT(GLushort id) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglCreateDisplayColorTableEXT, id, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(id);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

GLboolean System::WglLoadDisplayColorTableEXT(const GLushort* table, GLuint length) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglLoadDisplayColorTableEXT, table, length, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(table, length);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

GLboolean System::WglBindDisplayColorTableEXT(GLushort id) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglBindDisplayColorTableEXT, id, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(id);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::WglDestroyDisplayColorTableEXT(GLushort id) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1(wglBindDisplayColorTableEXT, id);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(id);

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_EXT_extensions_string

namespace System
{
    auto existsWglExtExtensionsString = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLGETEXTENSIONSSTRINGEXTPROC wglGetExtensionsStringEXT{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglExtExtensionsString() noexcept
{
    return existsWglExtExtensionsString;
}

void System::InitWglExtExtensionsString() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_GET_FUNCTION(wglGetExtensionsStringEXT);

    if (wglGetExtensionsStringEXT != nullptr)
    {
        existsWglExtExtensionsString = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglExtExtensionsString = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglExtExtensionsString = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

const char* System::WglGetExtensionsStringEXT() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_0_RESULT(wglGetExtensionsStringEXT, "");

#else  // !SYSTEM_PLATFORM_WIN32

    return "";

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_EXT_framebuffer_sRGB

namespace System
{
    auto existsWglExtFrameBuffersRGB = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglExtFrameBuffersRGB() noexcept
{
    return existsWglExtFrameBuffersRGB;
}

void System::InitWglExtFrameBuffersRGB()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_EXT_framebuffer_sRGB") || IsOpenGLSupportsExtension("WGL_EXT_framebuffer_sRGB"))
    {
        existsWglExtFrameBuffersRGB = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglExtFrameBuffersRGB = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglExtFrameBuffersRGB = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_EXT_make_current_read

namespace System
{
    auto existsWglExtMakeCurrentRead = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLMAKECONTEXTCURRENTEXTPROC wglMakeContextCurrentEXT{ nullptr };
    PFNWGLGETCURRENTREADDCEXTPROC wglGetCurrentReadDCEXT{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglExtMakeCurrentRead() noexcept
{
    return existsWglExtMakeCurrentRead;
}

void System::InitWglExtMakeCurrentRead()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_EXT_make_current_read") || IsOpenGLSupportsExtension("WGL_EXT_make_current_read"))
    {
        SYSTEM_GET_FUNCTION(wglMakeContextCurrentEXT);
        SYSTEM_GET_FUNCTION(wglGetCurrentReadDCEXT);

        existsWglExtMakeCurrentRead = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglExtMakeCurrentRead = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglExtMakeCurrentRead = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglMakeContextCurrentEXT(WindowsHdc drawDC, WindowsHdc readDC, OpenGLRcHandle hGlRc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglMakeContextCurrentEXT, drawDC, readDC, hGlRc, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(drawDC, readDC, hGlRc);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHdc System::WglGetCurrentReadDcEXT() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_0_RESULT(wglGetCurrentReadDCEXT, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_EXT_multisample

namespace System
{
    auto existsWglExtMultiSample = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglExtMultiSample() noexcept
{
    return existsWglExtMultiSample;
}

void System::InitWglExtMultiSample()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_EXT_multisample") || IsOpenGLSupportsExtension("WGL_EXT_multisample"))
    {
        existsWglExtMultiSample = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglExtMultiSample = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglExtMultiSample = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_EXT_pbuffer

namespace System
{
    auto existsWglExtPBuffer = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLCREATEPBUFFEREXTPROC wglCreatePbufferEXT{ nullptr };
    PFNWGLGETPBUFFERDCEXTPROC wglGetPbufferDCEXT{ nullptr };
    PFNWGLRELEASEPBUFFERDCEXTPROC wglReleasePbufferDCEXT{ nullptr };
    PFNWGLDESTROYPBUFFEREXTPROC wglDestroyPbufferEXT{ nullptr };
    PFNWGLQUERYPBUFFEREXTPROC wglQueryPbufferEXT{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglExtPBuffer() noexcept
{
    return existsWglExtPBuffer;
}

void System::InitWglExtPBuffer()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_EXT_pbuffer") || IsOpenGLSupportsExtension("WGL_EXT_pbuffer"))
    {
        SYSTEM_GET_FUNCTION(wglCreatePbufferEXT);
        SYSTEM_GET_FUNCTION(wglGetPbufferDCEXT);
        SYSTEM_GET_FUNCTION(wglReleasePbufferDCEXT);
        SYSTEM_GET_FUNCTION(wglDestroyPbufferEXT);
        SYSTEM_GET_FUNCTION(wglQueryPbufferEXT);

        existsWglExtPBuffer = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglExtPBuffer = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglExtPBuffer = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WglHpBufferExt System::WglCreatePBufferEXT(WindowsHdc hdc, int pixelFormat, int width, int height, const int* piAttribList) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_5_RESULT(wglCreatePbufferEXT, hdc, pixelFormat, width, height, piAttribList, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, pixelFormat, width, height, piAttribList);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHdc System::WglGetPBufferDcEXT(WglHpBufferExt hPBuffer) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglGetPbufferDCEXT, hPBuffer, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hPBuffer);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::WglReleasePBufferDcEXT(WglHpBufferExt hPBuffer, WindowsHdc hdc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglReleasePbufferDCEXT, hPBuffer, hdc, 0);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hPBuffer, hdc);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDestroyPBufferEXT(WglHpBufferExt hPBuffer) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglDestroyPbufferEXT, hPBuffer, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hPBuffer);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglQueryPBufferEXT(WglHpBufferExt hPBuffer, int attribute, int* piValue) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglQueryPbufferEXT, hPBuffer, attribute, piValue, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hPBuffer, attribute, piValue);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_EXT_pixel_format

namespace System
{
    auto existsWglExtPixelFormat = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLGETPIXELFORMATATTRIBIVEXTPROC wglGetPixelFormatAttribivEXT{ nullptr };
    PFNWGLGETPIXELFORMATATTRIBFVEXTPROC wglGetPixelFormatAttribfvEXT{ nullptr };
    PFNWGLCHOOSEPIXELFORMATEXTPROC wglChoosePixelFormatEXT{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglExtPixelFormat() noexcept
{
    return existsWglExtPixelFormat;
}

void System::InitWglExtPixelFormat()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_EXT_pixel_format") || IsOpenGLSupportsExtension("WGL_EXT_pixel_format"))
    {
        SYSTEM_GET_FUNCTION(wglGetPixelFormatAttribivEXT);
        SYSTEM_GET_FUNCTION(wglGetPixelFormatAttribfvEXT);
        SYSTEM_GET_FUNCTION(wglChoosePixelFormatEXT);

        existsWglExtPixelFormat = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglExtPixelFormat = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglExtPixelFormat = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGetPixelFormatAttribIvEXT(WindowsHdc hdc, int pixelFormat, int layerPlane, WindowsUInt attributes, int* piAttributes, int* piValues) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_6_RESULT(wglGetPixelFormatAttribivEXT, hdc, pixelFormat, layerPlane, attributes, piAttributes, piValues, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, pixelFormat, layerPlane, attributes, piAttributes, piValues);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGetPixelFormatAttribFvEXT(WindowsHdc hdc, int pixelFormat, int layerPlane, WindowsUInt attributes, int* piAttributes, float* pfValues) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_6_RESULT(wglGetPixelFormatAttribfvEXT, hdc, pixelFormat, layerPlane, attributes, piAttributes, pfValues, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, pixelFormat, layerPlane, attributes, piAttributes, pfValues);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglChoosePixelFormatEXT(WindowsHdc hdc, const int* piAttribIList, const float* pfAttribFList, WindowsUInt maxFormats, int* piFormats, WindowsUInt* numFormats) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_6_RESULT(wglChoosePixelFormatEXT, hdc, piAttribIList, pfAttribFList, maxFormats, piFormats, numFormats, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, piAttribIList, pfAttribFList, maxFormats, piFormats, numFormats);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_EXT_pixel_format_packed_float

namespace System
{
    auto existsWglExtPixelFormatPackedFloat = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglExtPixelFormatPackedFloat() noexcept
{
    return existsWglExtPixelFormatPackedFloat;
}

void System::InitWglExtPixelFormatPackedFloat()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_EXT_pixel_format_packed_float") || IsOpenGLSupportsExtension("WGL_EXT_pixel_format_packed_float"))
    {
        existsWglExtPixelFormatPackedFloat = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglExtPixelFormatPackedFloat = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglExtPixelFormatPackedFloat = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_EXT_swap_control

namespace System
{
    auto existsWglExtSwapControl = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT{ nullptr };
    PFNWGLGETSWAPINTERVALEXTPROC wglGetSwapIntervalEXT{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglExtSwapControl() noexcept
{
    return existsWglExtSwapControl;
}

void System::InitWglExtSwapControl()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_EXT_swap_control") || IsOpenGLSupportsExtension("WGL_EXT_swap_control"))
    {
        SYSTEM_GET_FUNCTION(wglSwapIntervalEXT);
        SYSTEM_GET_FUNCTION(wglGetSwapIntervalEXT);

        existsWglExtSwapControl = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglExtSwapControl = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglExtSwapControl = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglSwapIntervalEXT(int interval) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglSwapIntervalEXT, interval, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(interval);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::WglGetSwapIntervalEXT() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_0_RESULT(wglGetSwapIntervalEXT, 0);

#else  // !SYSTEM_PLATFORM_WIN32

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_EXT_swap_control_tear

namespace System
{
    auto existsWglExtSwapControlTear = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglExtSwapControlTear() noexcept
{
    return existsWglExtSwapControlTear;
}

void System::InitWglExtSwapControlTear()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_EXT_swap_control_tear") || IsOpenGLSupportsExtension("WGL_EXT_swap_control_tear"))
    {
        existsWglExtSwapControlTear = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglExtSwapControlTear = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglExtSwapControlTear = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// I3D 扩展

/// WGL_I3D_digital_video_control

namespace System
{
    auto existsWglI3DDigitalVideoControl = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC wglGetDigitalVideoParametersI3D{ nullptr };
    PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC wglSetDigitalVideoParametersI3D{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglI3DDigitalVideoControl() noexcept
{
    return existsWglI3DDigitalVideoControl;
}

void System::InitWglI3DDigitalVideoControl()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_I3D_digital_video_control") || IsOpenGLSupportsExtension("WGL_I3D_digital_video_control"))
    {
        SYSTEM_GET_FUNCTION(wglGetDigitalVideoParametersI3D);
        SYSTEM_GET_FUNCTION(wglSetDigitalVideoParametersI3D);

        existsWglI3DDigitalVideoControl = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglI3DDigitalVideoControl = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglI3DDigitalVideoControl = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGetDigitalVideoParametersI3D(WindowsHdc hdc, int attribute, int* piValue) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglGetDigitalVideoParametersI3D, hdc, attribute, piValue, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, attribute, piValue);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglSetDigitalVideoParametersI3D(WindowsHdc hdc, int attribute, const int* piValue) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglSetDigitalVideoParametersI3D, hdc, attribute, piValue, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, attribute, piValue);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_I3D_gamma

namespace System
{
    auto existsWglI3DGamma = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLGETGAMMATABLEPARAMETERSI3DPROC wglGetGammaTableParametersI3D{ nullptr };
    PFNWGLSETGAMMATABLEPARAMETERSI3DPROC wglSetGammaTableParametersI3D{ nullptr };
    PFNWGLGETGAMMATABLEI3DPROC wglGetGammaTableI3D{ nullptr };
    PFNWGLSETGAMMATABLEI3DPROC wglSetGammaTableI3D{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglI3DGamma() noexcept
{
    return existsWglI3DGamma;
}

void System::InitWglI3DGamma()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_I3D_gamma") || IsOpenGLSupportsExtension("WGL_I3D_gamma"))
    {
        SYSTEM_GET_FUNCTION(wglGetGammaTableParametersI3D);
        SYSTEM_GET_FUNCTION(wglSetGammaTableParametersI3D);
        SYSTEM_GET_FUNCTION(wglGetGammaTableI3D);
        SYSTEM_GET_FUNCTION(wglSetGammaTableI3D);

        existsWglI3DGamma = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglI3DGamma = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglI3DGamma = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGetGammaTableParametersI3D(WindowsHdc hdc, int attribute, int* piValue) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglGetGammaTableParametersI3D, hdc, attribute, piValue, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, attribute, piValue);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglSetGammaTableParametersI3D(WindowsHdc hdc, int attribute, const int* piValue) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglSetGammaTableParametersI3D, hdc, attribute, piValue, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, attribute, piValue);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGetGammaTableI3D(WindowsHdc hdc, int iEntries, WindowsUShort* puRed, WindowsUShort* puGreen, WindowsUShort* puBlue) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_5_RESULT(wglGetGammaTableI3D, hdc, iEntries, puRed, puGreen, puBlue, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, iEntries, puRed, puGreen, puBlue);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglSetGammaTableI3D(WindowsHdc hdc, int iEntries, const WindowsUShort* puRed, const WindowsUShort* puGreen, const WindowsUShort* puBlue) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_5_RESULT(wglSetGammaTableI3D, hdc, iEntries, puRed, puGreen, puBlue, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, iEntries, puRed, puGreen, puBlue);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_I3D_genlock

namespace System
{
    auto existsWglI3DGenLock = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLENABLEGENLOCKI3DPROC wglEnableGenlockI3D{ nullptr };
    PFNWGLDISABLEGENLOCKI3DPROC wglDisableGenlockI3D{ nullptr };
    PFNWGLISENABLEDGENLOCKI3DPROC wglIsEnabledGenlockI3D{ nullptr };
    PFNWGLGENLOCKSOURCEI3DPROC wglGenlockSourceI3D{ nullptr };
    PFNWGLGETGENLOCKSOURCEI3DPROC wglGetGenlockSourceI3D{ nullptr };
    PFNWGLGENLOCKSOURCEEDGEI3DPROC wglGenlockSourceEdgeI3D{ nullptr };
    PFNWGLGETGENLOCKSOURCEEDGEI3DPROC wglGetGenlockSourceEdgeI3D{ nullptr };
    PFNWGLGENLOCKSAMPLERATEI3DPROC wglGenlockSampleRateI3D{ nullptr };
    PFNWGLGETGENLOCKSAMPLERATEI3DPROC wglGetGenlockSampleRateI3D{ nullptr };
    PFNWGLGENLOCKSOURCEDELAYI3DPROC wglGenlockSourceDelayI3D{ nullptr };
    PFNWGLGETGENLOCKSOURCEDELAYI3DPROC wglGetGenlockSourceDelayI3D{ nullptr };
    PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC wglQueryGenlockMaxSourceDelayI3D{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglI3DGenLock() noexcept
{
    return existsWglI3DGenLock;
}

void System::InitWglI3DGenLock()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_I3D_genlock") || IsOpenGLSupportsExtension("WGL_I3D_genlock"))
    {
        SYSTEM_GET_FUNCTION(wglEnableGenlockI3D);
        SYSTEM_GET_FUNCTION(wglDisableGenlockI3D);
        SYSTEM_GET_FUNCTION(wglIsEnabledGenlockI3D);
        SYSTEM_GET_FUNCTION(wglGenlockSourceI3D);
        SYSTEM_GET_FUNCTION(wglGetGenlockSourceI3D);
        SYSTEM_GET_FUNCTION(wglGenlockSourceEdgeI3D);
        SYSTEM_GET_FUNCTION(wglGetGenlockSourceEdgeI3D);
        SYSTEM_GET_FUNCTION(wglGenlockSampleRateI3D);
        SYSTEM_GET_FUNCTION(wglGetGenlockSampleRateI3D);
        SYSTEM_GET_FUNCTION(wglGenlockSourceDelayI3D);
        SYSTEM_GET_FUNCTION(wglGetGenlockSourceDelayI3D);
        SYSTEM_GET_FUNCTION(wglQueryGenlockMaxSourceDelayI3D);

        existsWglI3DGenLock = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglI3DGenLock = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglI3DGenLock = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglEnableGenLockI3D(WindowsHdc hdc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglEnableGenlockI3D, hdc, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDisableGenLockI3D(WindowsHdc hdc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglDisableGenlockI3D, hdc, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglIsEnabledGenLockI3D(WindowsHdc hdc, WindowsBool* flag) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglIsEnabledGenlockI3D, hdc, flag, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, flag);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGenLockSourceI3D(WindowsHdc hdc, WindowsUInt source) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglGenlockSourceI3D, hdc, source, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, source);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGetGenLockSourceI3D(WindowsHdc hdc, WindowsUInt* source) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglGetGenlockSourceI3D, hdc, source, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, source);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGenLockSourceEdgeI3D(WindowsHdc hdc, WindowsUInt edge) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglGenlockSourceEdgeI3D, hdc, edge, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, edge);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGetGenLockSourceEdgeI3D(WindowsHdc hdc, WindowsUInt* edge) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglGetGenlockSourceEdgeI3D, hdc, edge, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, edge);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGenLockSampleRateI3D(WindowsHdc hdc, WindowsUInt rate) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglGenlockSampleRateI3D, hdc, rate, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, rate);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGetGenLockSampleRateI3D(WindowsHdc hdc, WindowsUInt* rate) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglGetGenlockSampleRateI3D, hdc, rate, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, rate);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGenLockSourceDelayI3D(WindowsHdc hdc, WindowsUInt delay) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglGenlockSourceDelayI3D, hdc, delay, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, delay);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGetGenLockSourceDelayI3D(WindowsHdc hdc, WindowsUInt* delay) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglGetGenlockSourceDelayI3D, hdc, delay, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, delay);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglQueryGenLockMaxSourceDelayI3D(WindowsHdc hdc, WindowsUInt* maxLineDelay, WindowsUInt* maxPixelDelay) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglQueryGenlockMaxSourceDelayI3D, hdc, maxLineDelay, maxPixelDelay, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, maxLineDelay, maxPixelDelay);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_I3D_image_buffer

namespace System
{
    auto existsWglI3DImageBuffer = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLCREATEIMAGEBUFFERI3DPROC wglCreateImageBufferI3D{ nullptr };
    PFNWGLDESTROYIMAGEBUFFERI3DPROC wglDestroyImageBufferI3D{ nullptr };
    PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC wglAssociateImageBufferEventsI3D{ nullptr };
    PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC wglReleaseImageBufferEventsI3D{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglI3DImageBuffer() noexcept
{
    return existsWglI3DImageBuffer;
}

void System::InitWglI3DImageBuffer()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_I3D_image_buffer") || IsOpenGLSupportsExtension("WGL_I3D_image_buffer"))
    {
        SYSTEM_GET_FUNCTION(wglCreateImageBufferI3D);
        SYSTEM_GET_FUNCTION(wglDestroyImageBufferI3D);
        SYSTEM_GET_FUNCTION(wglAssociateImageBufferEventsI3D);
        SYSTEM_GET_FUNCTION(wglReleaseImageBufferEventsI3D);

        existsWglI3DImageBuffer = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglI3DImageBuffer = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglI3DImageBuffer = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsVoidPtr System::WglCreateImageBufferI3D(WindowsHdc hdc, WindowsDWord size, WindowsUInt flags) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglCreateImageBufferI3D, hdc, size, flags, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, size, flags);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDestroyImageBufferI3D(WindowsHdc hdc, WindowsVoidPtr address) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglDestroyImageBufferI3D, hdc, address, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, address);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglAssociateImageBufferEventsI3D(WindowsHdc hdc, const WindowsHandle* event, const WindowsVoidPtr* address, const WindowsDWord* size, WindowsUInt count) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_5_RESULT(wglAssociateImageBufferEventsI3D, hdc, event, address, size, count, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, event, address, size, count);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglReleaseImageBufferEventsI3D(WindowsHdc hdc, const WindowsVoidPtr* address, WindowsUInt count) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglReleaseImageBufferEventsI3D, hdc, address, count, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, address, count);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_I3D_swap_frame_lock

namespace System
{
    auto existsWglI3DSwapFrameLock = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLENABLEFRAMELOCKI3DPROC wglEnableFrameLockI3D{ nullptr };
    PFNWGLDISABLEFRAMELOCKI3DPROC wglDisableFrameLockI3D{ nullptr };
    PFNWGLISENABLEDFRAMELOCKI3DPROC wglIsEnabledFrameLockI3D{ nullptr };
    PFNWGLQUERYFRAMELOCKMASTERI3DPROC wglQueryFrameLockMasterI3D{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglI3DSwapFrameLock() noexcept
{
    return existsWglI3DSwapFrameLock;
}

void System::InitWglI3DSwapFrameLock()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_I3D_swap_frame_lock") || IsOpenGLSupportsExtension("WGL_I3D_swap_frame_lock"))
    {
        SYSTEM_GET_FUNCTION(wglEnableFrameLockI3D);
        SYSTEM_GET_FUNCTION(wglDisableFrameLockI3D);
        SYSTEM_GET_FUNCTION(wglIsEnabledFrameLockI3D);
        SYSTEM_GET_FUNCTION(wglQueryFrameLockMasterI3D);

        existsWglI3DSwapFrameLock = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglI3DSwapFrameLock = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglI3DSwapFrameLock = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglEnableFrameLockI3D() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_0_RESULT(wglEnableFrameLockI3D, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDisableFrameLockI3D() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_0_RESULT(wglDisableFrameLockI3D, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglIsEnabledFrameLockI3D(WindowsBool* flag) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglIsEnabledFrameLockI3D, flag, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(flag);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglQueryFrameLockMasterI3D(WindowsBool* flag) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglQueryFrameLockMasterI3D, flag, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(flag);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_I3D_swap_frame_usage

namespace System
{
    auto existsWglI3DSwapFrameUsage = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLGETFRAMEUSAGEI3DPROC wglGetFrameUsageI3D{ nullptr };
    PFNWGLBEGINFRAMETRACKINGI3DPROC wglBeginFrameTrackingI3D{ nullptr };
    PFNWGLENDFRAMETRACKINGI3DPROC wglEndFrameTrackingI3D{ nullptr };
    PFNWGLQUERYFRAMETRACKINGI3DPROC wglQueryFrameTrackingI3D{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglI3DSwapFrameUsage() noexcept
{
    return existsWglI3DSwapFrameUsage;
}

void System::InitWglI3DSwapFrameUsage()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_I3D_swap_frame_usage") || IsOpenGLSupportsExtension("WGL_I3D_swap_frame_usage"))
    {
        SYSTEM_GET_FUNCTION(wglGetFrameUsageI3D);
        SYSTEM_GET_FUNCTION(wglBeginFrameTrackingI3D);
        SYSTEM_GET_FUNCTION(wglEndFrameTrackingI3D);
        SYSTEM_GET_FUNCTION(wglQueryFrameTrackingI3D);

        existsWglI3DSwapFrameUsage = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglI3DSwapFrameUsage = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglI3DSwapFrameUsage = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGetFrameUsageI3D(float* usage) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglGetFrameUsageI3D, usage, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(usage);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglBeginFrameTrackingI3D() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_0_RESULT(wglBeginFrameTrackingI3D, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglEndFrameTrackingI3D() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_0_RESULT(wglEndFrameTrackingI3D, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglQueryFrameTrackingI3D(WindowsDWord* frameCount, WindowsDWord* missedFrames, float* lastMissedUsage) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglQueryFrameTrackingI3D, frameCount, missedFrames, lastMissedUsage, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(frameCount, missedFrames, lastMissedUsage);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// NV 扩展

/// WGL_NV_DX_interop

namespace System
{
    auto existsWglNvDxInterop = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLDXSETRESOURCESHAREHANDLENVPROC wglDXSetResourceShareHandleNV{ nullptr };
    PFNWGLDXOPENDEVICENVPROC wglDXOpenDeviceNV{ nullptr };
    PFNWGLDXCLOSEDEVICENVPROC wglDXCloseDeviceNV{ nullptr };
    PFNWGLDXREGISTEROBJECTNVPROC wglDXRegisterObjectNV{ nullptr };
    PFNWGLDXUNREGISTEROBJECTNVPROC wglDXUnregisterObjectNV{ nullptr };
    PFNWGLDXOBJECTACCESSNVPROC wglDXObjectAccessNV{ nullptr };
    PFNWGLDXLOCKOBJECTSNVPROC wglDXLockObjectsNV{ nullptr };
    PFNWGLDXUNLOCKOBJECTSNVPROC wglDXUnlockObjectsNV{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglNvDxInterop() noexcept
{
    return existsWglNvDxInterop;
}

void System::InitWglNvDxInterop()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_NV_DX_interop") || IsOpenGLSupportsExtension("WGL_NV_DX_interop"))
    {
        SYSTEM_GET_FUNCTION(wglDXSetResourceShareHandleNV);
        SYSTEM_GET_FUNCTION(wglDXOpenDeviceNV);
        SYSTEM_GET_FUNCTION(wglDXCloseDeviceNV);
        SYSTEM_GET_FUNCTION(wglDXRegisterObjectNV);
        SYSTEM_GET_FUNCTION(wglDXUnregisterObjectNV);
        SYSTEM_GET_FUNCTION(wglDXObjectAccessNV);
        SYSTEM_GET_FUNCTION(wglDXLockObjectsNV);
        SYSTEM_GET_FUNCTION(wglDXUnlockObjectsNV);

        existsWglNvDxInterop = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNvDxInterop = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNvDxInterop = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDxSetResourceShareHandleNv(void* dxObject, WindowsHandle shareHandle) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglDXSetResourceShareHandleNV, dxObject, shareHandle, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(dxObject, shareHandle);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHandle System::WglDxOpenDeviceNv(void* dxDevice) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglDXOpenDeviceNV, dxDevice, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(dxDevice);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDxCloseDeviceNv(WindowsHandle hDevice) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglDXCloseDeviceNV, hDevice, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDevice);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHandle System::WglDxRegisterObjectNv(WindowsHandle hDevice, void* dxObject, GLuint name, GLenum type, GLenum access) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_5_RESULT(wglDXRegisterObjectNV, hDevice, dxObject, name, type, access, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDevice, dxObject, name, type, access);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDxUnregisterObjectNv(WindowsHandle hDevice, WindowsHandle hObject) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglDXUnregisterObjectNV, hDevice, hObject, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDevice, hObject);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDxObjectAccessNv(WindowsHandle hObject, GLenum access) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglDXObjectAccessNV, hObject, access, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hObject, access);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDxLockObjectsNv(WindowsHandle hDevice, GLint count, WindowsHandle* hObjects) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglDXLockObjectsNV, hDevice, count, hObjects, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDevice, count, hObjects);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDxUnlockObjectsNv(WindowsHandle hDevice, GLint count, WindowsHandle* hObjects) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglDXUnlockObjectsNV, hDevice, count, hObjects, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDevice, count, hObjects);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_NV_DX_interop2

namespace System
{
    auto existsWglNvDxInterop2 = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglNvDxInterop2() noexcept
{
    return existsWglNvDxInterop2;
}

void System::InitWglNvDxInterop2()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_NV_DX_interop2") || IsOpenGLSupportsExtension("WGL_NV_DX_interop2"))
    {
        existsWglNvDxInterop2 = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNvDxInterop2 = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNvDxInterop2 = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_NV_copy_image

namespace System
{
    auto existsWglNvCopyImage = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLCOPYIMAGESUBDATANVPROC wglCopyImageSubDataNV{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglNvCopyImage() noexcept
{
    return existsWglNvCopyImage;
}

void System::InitWglNvCopyImage()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_NV_copy_image") || IsOpenGLSupportsExtension("WGL_NV_copy_image"))
    {
        SYSTEM_GET_FUNCTION(wglCopyImageSubDataNV);

        existsWglNvCopyImage = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNvCopyImage = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNvCopyImage = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglCopyImageSubDataNv(OpenGLRcHandle hSrcRc, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, OpenGLRcHandle hDstRc, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_17_RESULT(wglCopyImageSubDataNV, hSrcRc, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, hDstRc, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hSrcRc, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, hDstRc, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_NV_delay_before_swap

namespace System
{
    auto existsWglNvDelayBeforeSwap = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLDELAYBEFORESWAPNVPROC wglDelayBeforeSwapNV{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglNvDelayBeforeSwap() noexcept
{
    return existsWglNvDelayBeforeSwap;
}

void System::InitWglNvDelayBeforeSwap()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_NV_delay_before_swap") || IsOpenGLSupportsExtension("WGL_NV_delay_before_swap"))
    {
        SYSTEM_GET_FUNCTION(wglDelayBeforeSwapNV);

        existsWglNvDelayBeforeSwap = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNvDelayBeforeSwap = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNvDelayBeforeSwap = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDelayBeforeSwapNv(WindowsHdc hDC, GLfloat seconds) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglDelayBeforeSwapNV, hDC, seconds, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, seconds);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_NV_float_buffer

namespace System
{
    auto existsWglNvFloatBuffer = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglNvFloatBuffer() noexcept
{
    return existsWglNvFloatBuffer;
}

void System::InitWglNvFloatBuffer()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_NV_float_buffer") || IsOpenGLSupportsExtension("WGL_NV_float_buffer"))
    {
        existsWglNvFloatBuffer = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNvFloatBuffer = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNvFloatBuffer = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_NV_gpu_affinity

namespace System
{
    auto existsWglNvGpuAffinity = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLENUMGPUSNVPROC wglEnumGpusNV{ nullptr };
    PFNWGLENUMGPUDEVICESNVPROC wglEnumGpuDevicesNV{ nullptr };
    PFNWGLCREATEAFFINITYDCNVPROC wglCreateAffinityDCNV{ nullptr };
    PFNWGLENUMGPUSFROMAFFINITYDCNVPROC wglEnumGpusFromAffinityDCNV{ nullptr };
    PFNWGLDELETEDCNVPROC wglDeleteDCNV{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglNvGpuAffinity() noexcept
{
    return existsWglNvGpuAffinity;
}

void System::InitWglNvGpuAffinity()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_NV_gpu_affinity") || IsOpenGLSupportsExtension("WGL_NV_gpu_affinity"))
    {
        SYSTEM_GET_FUNCTION(wglEnumGpusNV);
        SYSTEM_GET_FUNCTION(wglEnumGpuDevicesNV);
        SYSTEM_GET_FUNCTION(wglCreateAffinityDCNV);
        SYSTEM_GET_FUNCTION(wglEnumGpusFromAffinityDCNV);
        SYSTEM_GET_FUNCTION(wglDeleteDCNV);

        existsWglNvGpuAffinity = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNvGpuAffinity = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNvGpuAffinity = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglEnumGpusNv(WindowsUInt gpuIndex, WglHGpuNv* phGpu) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglEnumGpusNV, gpuIndex, phGpu, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(gpuIndex, phGpu);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglEnumGpuDevicesNv(WglHGpuNv hGpu, WindowsUInt deviceIndex, WglGpuDevicePtr gpuDevice) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglEnumGpuDevicesNV, hGpu, deviceIndex, gpuDevice, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hGpu, deviceIndex, gpuDevice);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHdc System::WglCreateAffinityDcNv(const WglHGpuNv* phGpuList) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglCreateAffinityDCNV, phGpuList, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(phGpuList);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglEnumGpusFromAffinityDcNv(WindowsHdc hAffinityDC, WindowsUInt gpuIndex, WglHGpuNv* hGpu) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglEnumGpusFromAffinityDCNV, hAffinityDC, gpuIndex, hGpu, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hAffinityDC, gpuIndex, hGpu);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDeleteDcNv(WindowsHdc hdc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglDeleteDCNV, hdc, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_NV_multigpu_context

namespace System
{
    auto existsWglNVMultiGpuContext = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglNvMultiGpuContext() noexcept
{
    return existsWglNVMultiGpuContext;
}

void System::InitWglNvMultiGpuContext()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_NV_multigpu_context") || IsOpenGLSupportsExtension("WGL_NV_multigpu_context"))
    {
        existsWglNVMultiGpuContext = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNVMultiGpuContext = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNVMultiGpuContext = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_NV_multisample_coverage

namespace System
{
    auto existsWglNVMultiSampleCoverage = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglNvMultiSampleCoverage() noexcept
{
    return existsWglNVMultiSampleCoverage;
}

void System::InitWglNvMultiSampleCoverage()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_NV_multisample_coverage") || IsOpenGLSupportsExtension("WGL_NV_multisample_coverage"))
    {
        existsWglNVMultiSampleCoverage = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNVMultiSampleCoverage = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNVMultiSampleCoverage = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_NV_present_video

namespace System
{
    auto existsWglNvPresentVideo = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLENUMERATEVIDEODEVICESNVPROC wglEnumerateVideoDevicesNV{ nullptr };
    PFNWGLBINDVIDEODEVICENVPROC wglBindVideoDeviceNV{ nullptr };
    PFNWGLQUERYCURRENTCONTEXTNVPROC wglQueryCurrentContextNV{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglNvPresentVideo() noexcept
{
    return existsWglNvPresentVideo;
}

void System::InitWglNvPresentVideo()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_NV_present_video") || IsOpenGLSupportsExtension("WGL_NV_present_video"))
    {
        SYSTEM_GET_FUNCTION(wglEnumerateVideoDevicesNV);
        SYSTEM_GET_FUNCTION(wglBindVideoDeviceNV);
        SYSTEM_GET_FUNCTION(wglQueryCurrentContextNV);

        existsWglNvPresentVideo = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNvPresentVideo = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNvPresentVideo = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::WglEnumerateVideoDevicesNv(WindowsHdc hdc, WglHVideoOutputDeviceNv* phDeviceList) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglEnumerateVideoDevicesNV, hdc, phDeviceList, 0);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, phDeviceList);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglBindVideoDeviceNv(WindowsHdc hdc, unsigned int videoSlot, WglHVideoOutputDeviceNv videoDevice, const int* piAttribList) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_4_RESULT(wglBindVideoDeviceNV, hdc, videoSlot, videoDevice, piAttribList, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, videoSlot, videoDevice, piAttribList);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglQueryCurrentContextNv(int attribute, int* piValue) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglQueryCurrentContextNV, attribute, piValue, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(attribute, piValue);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_NV_render_depth_texture

namespace System
{
    auto existsWglNvRenderDepthTexture = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglNvRenderDepthTexture() noexcept
{
    return existsWglNvRenderDepthTexture;
}

void System::InitWglNvRenderDepthTexture()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_NV_render_depth_texture") || IsOpenGLSupportsExtension("WGL_NV_render_depth_texture"))
    {
        existsWglNvRenderDepthTexture = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNvRenderDepthTexture = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNvRenderDepthTexture = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_NV_render_texture_rectangle

namespace System
{
    auto existsWglNvRenderTextureRectangle = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglNvRenderTextureRectangle() noexcept
{
    return existsWglNvRenderTextureRectangle;
}

void System::InitWglNvRenderTextureRectangle()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_NV_render_texture_rectangle") || IsOpenGLSupportsExtension("WGL_NV_render_texture_rectangle"))
    {
        existsWglNvRenderTextureRectangle = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNvRenderTextureRectangle = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNvRenderTextureRectangle = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_NV_swap_group

namespace System
{
    auto existsWglNvSwapGroup = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLJOINSWAPGROUPNVPROC wglJoinSwapGroupNV{ nullptr };
    PFNWGLBINDSWAPBARRIERNVPROC wglBindSwapBarrierNV{ nullptr };
    PFNWGLQUERYSWAPGROUPNVPROC wglQuerySwapGroupNV{ nullptr };
    PFNWGLQUERYMAXSWAPGROUPSNVPROC wglQueryMaxSwapGroupsNV{ nullptr };
    PFNWGLQUERYFRAMECOUNTNVPROC wglQueryFrameCountNV{ nullptr };
    PFNWGLRESETFRAMECOUNTNVPROC wglResetFrameCountNV{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglNvSwapGroup() noexcept
{
    return existsWglNvSwapGroup;
}

void System::InitWglNvSwapGroup()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_NV_swap_group") || IsOpenGLSupportsExtension("WGL_NV_swap_group"))
    {
        SYSTEM_GET_FUNCTION(wglJoinSwapGroupNV);
        SYSTEM_GET_FUNCTION(wglBindSwapBarrierNV);
        SYSTEM_GET_FUNCTION(wglQuerySwapGroupNV);
        SYSTEM_GET_FUNCTION(wglQueryMaxSwapGroupsNV);
        SYSTEM_GET_FUNCTION(wglQueryFrameCountNV);
        SYSTEM_GET_FUNCTION(wglResetFrameCountNV);

        existsWglNvSwapGroup = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNvSwapGroup = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNvSwapGroup = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglJoinSwapGroupNv(WindowsHdc hdc, GLuint group) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglJoinSwapGroupNV, hdc, group, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, group);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglBindSwapBarrierNv(GLuint group, GLuint barrier) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglBindSwapBarrierNV, group, barrier, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(group, barrier);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglQuerySwapGroupNv(WindowsHdc hdc, GLuint* group, GLuint* barrier) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglQuerySwapGroupNV, hdc, group, barrier, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, group, barrier);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglQueryMaxSwapGroupsNv(WindowsHdc hdc, GLuint* maxGroups, GLuint* maxBarriers) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglQueryMaxSwapGroupsNV, hdc, maxGroups, maxBarriers, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, maxGroups, maxBarriers);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglQueryFrameCountNv(WindowsHdc hdc, GLuint* count) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglQueryFrameCountNV, hdc, count, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, count);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglResetFrameCountNv(WindowsHdc hdc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglResetFrameCountNV, hdc, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_NV_vertex_array_range

namespace System
{
    auto existsWglNVVertexArrayRange = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLALLOCATEMEMORYNVPROC wglAllocateMemoryNV{ nullptr };
    PFNWGLFREEMEMORYNVPROC wglFreeMemoryNV{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglNvVertexArrayRange() noexcept
{
    return existsWglNVVertexArrayRange;
}

void System::InitWglNvVertexArrayRange()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_NV_vertex_array_range") || IsOpenGLSupportsExtension("WGL_NV_vertex_array_range"))
    {
        SYSTEM_GET_FUNCTION(wglAllocateMemoryNV);
        SYSTEM_GET_FUNCTION(wglFreeMemoryNV);

        existsWglNVVertexArrayRange = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNVVertexArrayRange = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNVVertexArrayRange = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

void* System::WglAllocateMemoryNv(GLsizei size, GLfloat readFreq, GLfloat writeFreq, GLfloat priority) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_4_RESULT(wglAllocateMemoryNV, size, readFreq, writeFreq, priority, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(size, readFreq, writeFreq, priority);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::WglFreeMemoryNv(void* pointer) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1(wglFreeMemoryNV, pointer);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(pointer);

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_NV_video_capture

namespace System
{
    auto existsWglNvVideoCapture = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLBINDVIDEOCAPTUREDEVICENVPROC wglBindVideoCaptureDeviceNV{ nullptr };
    PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC wglEnumerateVideoCaptureDevicesNV{ nullptr };
    PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC wglLockVideoCaptureDeviceNV{ nullptr };
    PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC wglQueryVideoCaptureDeviceNV{ nullptr };
    PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC wglReleaseVideoCaptureDeviceNV{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglNvVideoCapture() noexcept
{
    return existsWglNvVideoCapture;
}

void System::InitWglNvVideoCapture()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_NV_video_capture") || IsOpenGLSupportsExtension("WGL_NV_video_capture"))
    {
        SYSTEM_GET_FUNCTION(wglBindVideoCaptureDeviceNV);
        SYSTEM_GET_FUNCTION(wglEnumerateVideoCaptureDevicesNV);
        SYSTEM_GET_FUNCTION(wglLockVideoCaptureDeviceNV);
        SYSTEM_GET_FUNCTION(wglQueryVideoCaptureDeviceNV);
        SYSTEM_GET_FUNCTION(wglReleaseVideoCaptureDeviceNV);

        existsWglNvVideoCapture = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNvVideoCapture = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNvVideoCapture = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglBindVideoCaptureDeviceNv(WindowsUInt videoSlot, WglHVideoInputDeviceNv hDevice) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglBindVideoCaptureDeviceNV, videoSlot, hDevice, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(videoSlot, hDevice);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsUInt System::WglEnumerateVideoCaptureDevicesNv(WindowsHdc hdc, WglHVideoInputDeviceNv* phDeviceList) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglEnumerateVideoCaptureDevicesNV, hdc, phDeviceList, 0u);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, phDeviceList);

    return 0u;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglLockVideoCaptureDeviceNv(WindowsHdc hdc, WglHVideoInputDeviceNv hDevice) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglLockVideoCaptureDeviceNV, hdc, hDevice, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, hDevice);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglQueryVideoCaptureDeviceNv(WindowsHdc hdc, WglHVideoInputDeviceNv hDevice, int attribute, int* piValue) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_4_RESULT(wglQueryVideoCaptureDeviceNV, hdc, hDevice, attribute, piValue, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, hDevice, attribute, piValue);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglReleaseVideoCaptureDeviceNv(WindowsHdc hdc, WglHVideoInputDeviceNv hDevice) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglReleaseVideoCaptureDeviceNV, hdc, hDevice, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, hDevice);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// WGL_NV_video_output

namespace System
{
    auto existsWglNvVideoOutput = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLGETVIDEODEVICENVPROC wglGetVideoDeviceNV{ nullptr };
    PFNWGLRELEASEVIDEODEVICENVPROC wglReleaseVideoDeviceNV{ nullptr };
    PFNWGLBINDVIDEOIMAGENVPROC wglBindVideoImageNV{ nullptr };
    PFNWGLRELEASEVIDEOIMAGENVPROC wglReleaseVideoImageNV{ nullptr };
    PFNWGLSENDPBUFFERTOVIDEONVPROC wglSendPbufferToVideoNV{ nullptr };
    PFNWGLGETVIDEOINFONVPROC wglGetVideoInfoNV{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglNvVideoOutput() noexcept
{
    return existsWglNvVideoOutput;
}

void System::InitWglNvVideoOutput()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_NV_video_output") || IsOpenGLSupportsExtension("WGL_NV_video_output"))
    {
        SYSTEM_GET_FUNCTION(wglGetVideoDeviceNV);
        SYSTEM_GET_FUNCTION(wglReleaseVideoDeviceNV);
        SYSTEM_GET_FUNCTION(wglBindVideoImageNV);
        SYSTEM_GET_FUNCTION(wglReleaseVideoImageNV);
        SYSTEM_GET_FUNCTION(wglSendPbufferToVideoNV);
        SYSTEM_GET_FUNCTION(wglGetVideoInfoNV);

        existsWglNvVideoOutput = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNvVideoOutput = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNvVideoOutput = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGetVideoDeviceNv(WindowsHdc hdc, int numDevices, WglHpVideoDev* videoDevice) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglGetVideoDeviceNV, hdc, numDevices, videoDevice, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, numDevices, videoDevice);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglReleaseVideoDeviceNv(WglHpVideoDev videoDevice) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglReleaseVideoDeviceNV, videoDevice, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(videoDevice);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglBindVideoImageNv(WglHpVideoDev videoDevice, WglHpBufferArb hPBuffer, int videoBuffer) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglBindVideoImageNV, videoDevice, hPBuffer, videoBuffer, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(videoDevice, hPBuffer, videoBuffer);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglReleaseVideoImageNv(WglHpBufferArb hPBuffer, int videoBuffer) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglReleaseVideoImageNV, hPBuffer, videoBuffer, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hPBuffer, videoBuffer);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglSendPBufferToVideoNv(WglHpBufferArb hPBuffer, int bufferType, unsigned long* pulCounterPBuffer, WindowsBool block) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_4_RESULT(wglSendPbufferToVideoNV, hPBuffer, bufferType, pulCounterPBuffer, block, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hPBuffer, bufferType, pulCounterPBuffer, block);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGetVideoInfoNv(WglHpVideoDev hpVideoDevice, unsigned long* pulCounterOutputPBuffer, unsigned long* pulCounterOutputVideo) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglGetVideoInfoNV, hpVideoDevice, pulCounterOutputPBuffer, pulCounterOutputVideo, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hpVideoDevice, pulCounterOutputPBuffer, pulCounterOutputVideo);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// OML 扩展

/// WGL_OML_sync_control

namespace System
{
    auto existsWglOMLSyncControl = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLGETSYNCVALUESOMLPROC wglGetSyncValuesOML{ nullptr };
    PFNWGLGETMSCRATEOMLPROC wglGetMscRateOML{ nullptr };
    PFNWGLSWAPBUFFERSMSCOMLPROC wglSwapBuffersMscOML{ nullptr };
    PFNWGLSWAPLAYERBUFFERSMSCOMLPROC wglSwapLayerBuffersMscOML{ nullptr };
    PFNWGLWAITFORMSCOMLPROC wglWaitForMscOML{ nullptr };
    PFNWGLWAITFORSBCOMLPROC wglWaitForSbcOML{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglOMLSyncControl() noexcept
{
    return existsWglOMLSyncControl;
}

void System::InitWglOMLSyncControl()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_OML_sync_control") || IsOpenGLSupportsExtension("WGL_OML_sync_control"))
    {
        SYSTEM_GET_FUNCTION(wglGetSyncValuesOML);
        SYSTEM_GET_FUNCTION(wglGetMscRateOML);
        SYSTEM_GET_FUNCTION(wglSwapBuffersMscOML);
        SYSTEM_GET_FUNCTION(wglSwapLayerBuffersMscOML);
        SYSTEM_GET_FUNCTION(wglWaitForMscOML);
        SYSTEM_GET_FUNCTION(wglWaitForSbcOML);

        existsWglOMLSyncControl = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglOMLSyncControl = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglOMLSyncControl = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGetSyncValuesOML(WindowsHdc hdc, WindowsInt64* ust, WindowsInt64* msc, WindowsInt64* sbc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_4_RESULT(wglGetSyncValuesOML, hdc, ust, msc, sbc, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, ust, msc, sbc);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGetMscRateOML(WindowsHdc hdc, WindowsInt32* numerator, WindowsInt32* denominator) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglGetMscRateOML, hdc, numerator, denominator, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, numerator, denominator);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsInt64 System::WglSwapBuffersMscOML(WindowsHdc hdc, WindowsInt64 targetMsc, WindowsInt64 divisor, WindowsInt64 remainder) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_4_RESULT(wglSwapBuffersMscOML, hdc, targetMsc, divisor, remainder, 0);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, targetMsc, divisor, remainder);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsInt64 System::WglSwapLayerBuffersMscOML(WindowsHdc hdc, WindowsInt fuPlanes, WindowsInt64 targetMsc, WindowsInt64 divisor, WindowsInt64 remainder) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_5_RESULT(wglSwapLayerBuffersMscOML, hdc, fuPlanes, targetMsc, divisor, remainder, 0);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, fuPlanes, targetMsc, divisor, remainder);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglWaitForMscOML(WindowsHdc hdc, WindowsInt64 targetMsc, WindowsInt64 divisor, WindowsInt64 remainder, WindowsInt64* ust, WindowsInt64* msc, WindowsInt64* sbc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_7_RESULT(wglWaitForMscOML, hdc, targetMsc, divisor, remainder, ust, msc, sbc, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, targetMsc, divisor, remainder, ust, msc, sbc);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglWaitForSbcOML(WindowsHdc hdc, WindowsInt64 targetSbc, WindowsInt64* ust, WindowsInt64* msc, WindowsInt64* sbc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_5_RESULT(wglWaitForSbcOML, hdc, targetSbc, ust, msc, sbc, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, targetSbc, ust, msc, sbc);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::InitWgl()
{
    if (!InitGL())
    {
        return false;
    }

    InitWgl10();

    InitWglArbExtensionsString();
    InitWglExtExtensionsString();

    InitWglArbBufferRegion();
    InitWglArbContextFlushControl();
    InitWglArbCreateContext();
    InitWglArbCreateContextNoError();
    InitWglArbCreateContextProfile();
    InitWglArbCreateContextRobustness();
    InitWglArbFrameBuffersRGB();
    InitWglArbMakeCurrentRead();
    InitWglArbMultiSample();
    InitWglArbPBuffer();
    InitWglArbPixelFormat();
    InitWglArbPixelFormatFloat();
    InitWglArbRenderTexture();
    InitWglArbRobustnessApplicationIsolation();
    InitWglArbRobustnessShareGroupIsolation();

    InitWgl3DfxMultiSample();

    InitWgl3DlStereoControl();

    InitWglAMDGpuAssociation();

    InitWglATIPixelFormatFloat();
    InitWglATIRenderTextureRectangle();

    InitWglExtColorSpace();
    InitWglExtCreateContextEs2Profile();
    InitWglExtCreateContextEsProfile();
    InitWglExtDepthFloat();
    InitWglExtDisplayColorTable();
    InitWglExtFrameBuffersRGB();
    InitWglExtMakeCurrentRead();
    InitWglExtMultiSample();
    InitWglExtPBuffer();
    InitWglExtPixelFormat();
    InitWglExtPixelFormatPackedFloat();
    InitWglExtSwapControl();
    InitWglExtSwapControlTear();

    InitWglI3DDigitalVideoControl();
    InitWglI3DGamma();
    InitWglI3DGenLock();
    InitWglI3DImageBuffer();
    InitWglI3DSwapFrameUsage();

    InitWglNvDxInterop();
    InitWglNvDxInterop2();
    InitWglNvCopyImage();
    InitWglNvDelayBeforeSwap();
    InitWglNvFloatBuffer();
    InitWglNvGpuAffinity();
    InitWglNvMultiGpuContext();
    InitWglNvMultiSampleCoverage();
    InitWglNvPresentVideo();
    InitWglNvRenderDepthTexture();
    InitWglNvRenderTextureRectangle();
    InitWglNvSwapGroup();
    InitWglNvVertexArrayRange();
    InitWglNvVideoCapture();
    InitWglNvVideoOutput();

    InitWglOMLSyncControl();

    return true;
}

const char* System::GetWglExtensionString() noexcept
{
    if (existsWglExtExtensionsString == ExistsOpenGLExtensions::Exists)
    {
        return WglGetExtensionsStringEXT();
    }
    else if (existsWglArbExtensionsString == ExistsOpenGLExtensions::Exists)
    {
        return WglGetExtensionsStringARB(WglGetCurrentDC());
    }
    else
    {
        return "";
    }
}

bool System::SupportsWglExtension(const char* wglExtension)
{
    if (wglExtension == nullptr)
    {
        return false;
    }

    const auto wglExtensionString = GetWglExtensionString();
    if (wglExtensionString == nullptr)
    {
        return false;
    }

    const std::string extension{ wglExtensionString };

    const auto pos = extension.find(wglExtension);

    if (pos == std::string::npos)
    {
        return false;
    }

    const auto endPos = pos + StringLength(wglExtension);

    if (extension.size() <= endPos)
    {
        return true;
    }

    const auto end = extension.at(endPos);

    /// 扩展被发现,但确保它不是另一个扩展的合适子串。
    return end == ' ' || end == 0 || end == '\t' || end == '\n';
}
