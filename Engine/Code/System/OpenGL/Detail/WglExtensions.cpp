///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/29 23:39)

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

int System::ChoosePixelFormat(WindowsHdc hDc, const PixelFormatDescriptor* pPfd) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::ChoosePixelFormat(hDc, pPfd);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDc, pPfd);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::DescribePixelFormat(WindowsHdc hdc, int ipfd, WindowsUInt cjpfd, PixelFormatDescriptor* ppfd) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::DescribePixelFormat(hdc, ipfd, cjpfd, ppfd);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, ipfd, cjpfd, ppfd);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsUInt System::GetEnhMetaFilePixelFormat(HEnhMetaFile hemf, WindowsUInt cbBuffer, PixelFormatDescriptor* ppfd) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::GetEnhMetaFilePixelFormat(hemf, cbBuffer, ppfd);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hemf, cbBuffer, ppfd);

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

System::WindowsBool System::SetPixelFormat(WindowsHdc hdc, int ipfd, const PixelFormatDescriptor* ppfd) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::SetPixelFormat(hdc, ipfd, ppfd);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, ipfd, ppfd);

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

System::WindowsBool System::WglCopyContext(OpenGLHglrc hglrcSrc, OpenGLHglrc hglrcDst, WindowsUInt mask) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglCopyContext(hglrcSrc, hglrcDst, mask);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hglrcSrc, hglrcDst, mask);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::OpenGLHglrc System::WglCreateContext(WindowsHdc hDc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglCreateContext(hDc);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDc);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::OpenGLHglrc System::WglCreateLayerContext(WindowsHdc hDc, int level) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglCreateLayerContext(hDc, level);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDc, level);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDeleteContext(OpenGLHglrc oldContext) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglDeleteContext(oldContext);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(oldContext);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDescribeLayerPlane(WindowsHdc hDc, int pixelFormat, int layerPlane, WindowsUInt nBytes, LayerPlaneDescriptor* plpd) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglDescribeLayerPlane(hDc, pixelFormat, layerPlane, nBytes, plpd);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDc, pixelFormat, layerPlane, nBytes, plpd);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::OpenGLHglrc System::WglGetCurrentContext() noexcept
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

int System::WglGetLayerPaletteEntries(WindowsHdc hdc, int iLayerPlane, int iStart, int cEntries, OpenGLColorref* pcr) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglGetLayerPaletteEntries(hdc, iLayerPlane, iStart, cEntries, pcr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, iLayerPlane, iStart, cEntries, pcr);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::OpenGLProc System::WglGetProcAddress(const char* lpszProc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglGetProcAddress(lpszProc);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(lpszProc);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglMakeCurrent(WindowsHdc hDc, OpenGLHglrc newContext) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglMakeCurrent(hDc, newContext);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDc, newContext);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglRealizeLayerPalette(WindowsHdc hdc, int iLayerPlane, WindowsBool bRealize) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglRealizeLayerPalette(hdc, iLayerPlane, bRealize);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, iLayerPlane, bRealize);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::WglSetLayerPaletteEntries(WindowsHdc hdc, int iLayerPlane, int iStart, int cEntries, const OpenGLColorref* pcr) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglSetLayerPaletteEntries(hdc, iLayerPlane, iStart, cEntries, pcr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, iLayerPlane, iStart, cEntries, pcr);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglShareLists(OpenGLHglrc hrcSrvShare, OpenGLHglrc hrcSrvSource) noexcept
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

System::WindowsBool System::WglUseFontBitmaps(WindowsHdc hDC, WindowsDWord first, WindowsDWord count, WindowsDWord listBase) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglUseFontBitmaps(hDC, first, count, listBase);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, first, count, listBase);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglUseFontBitmapsA(WindowsHdc hDC, WindowsDWord first, WindowsDWord count, WindowsDWord listBase) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglUseFontBitmapsA(hDC, first, count, listBase);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, first, count, listBase);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglUseFontBitmapsW(WindowsHdc hDC, WindowsDWord first, WindowsDWord count, WindowsDWord listBase) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglUseFontBitmapsW(hDC, first, count, listBase);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, first, count, listBase);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglUseFontOutlines(WindowsHdc hDC, WindowsDWord first, WindowsDWord count, WindowsDWord listBase, float deviation, float extrusion, int format, GlyphMetricsFloatPtr lpgmf) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglUseFontOutlines(hDC, first, count, listBase, deviation, extrusion, format, lpgmf);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, first, count, listBase, deviation, extrusion, format, lpgmf);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglUseFontOutlinesA(WindowsHdc hDC, WindowsDWord first, WindowsDWord count, WindowsDWord listBase, float deviation, float extrusion, int format, GlyphMetricsFloatPtr lpgmf) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglUseFontOutlinesA(hDC, first, count, listBase, deviation, extrusion, format, lpgmf);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, first, count, listBase, deviation, extrusion, format, lpgmf);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglUseFontOutlinesW(WindowsHdc hDC, WindowsDWord first, WindowsDWord count, WindowsDWord listBase, float deviation, float extrusion, int format, GlyphMetricsFloatPtr lpgmf) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglUseFontOutlinesW(hDC, first, count, listBase, deviation, extrusion, format, lpgmf);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, first, count, listBase, deviation, extrusion, format, lpgmf);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

// ARB 扩展

// WGL_ARB_buffer_region

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

System::WindowsHandle System::WglCreateBufferRegionARB(WindowsHdc hDC, int iLayerPlane, WindowsUInt uType) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglCreateBufferRegionARB, hDC, iLayerPlane, uType, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, iLayerPlane, uType);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::WglDeleteBufferRegionARB(WindowsHandle hRegion) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1(wglDeleteBufferRegionARB, hRegion);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hRegion);

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglSaveBufferRegionARB(WindowsHandle hRegion, int x, int y, int width, int height) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_5_RESULT(wglSaveBufferRegionARB, hRegion, x, y, width, height, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hRegion, x, y, width, height);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglRestoreBufferRegionARB(WindowsHandle hRegion, int x, int y, int width, int height, int xSrc, int ySrc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_7_RESULT(wglRestoreBufferRegionARB, hRegion, x, y, width, height, xSrc, ySrc, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hRegion, x, y, width, height, xSrc, ySrc);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_ARB_context_flush_control

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

// WGL_ARB_create_context

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

System::OpenGLHglrc System::WglCreateContextAttribsARB(WindowsHdc hDC, OpenGLHglrc hShareContext, const int* attribList) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglCreateContextAttribsARB, hDC, hShareContext, attribList, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, hShareContext, attribList);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_ARB_create_context_no_error

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

// WGL_ARB_create_context_robustness

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

// WGL_ARB_extensions_string

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

// WGL_ARB_framebuffer_sRGB

namespace System
{
    auto existsWglArbFramebufferSRGB = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglArbFramebufferSRGB() noexcept
{
    return existsWglArbFramebufferSRGB;
}

void System::InitWglArbFramebufferSRGB()
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

// WGL_ARB_make_current_read

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

System::WindowsBool System::WglMakeContextCurrentARB(WindowsHdc hDrawDC, WindowsHdc hReadDC, OpenGLHglrc hglrc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglMakeContextCurrentARB, hDrawDC, hReadDC, hglrc, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDrawDC, hReadDC, hglrc);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHdc System::WglGetCurrentReadDCARB() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_0_RESULT(wglGetCurrentReadDCARB, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_ARB_multisample

namespace System
{
    auto existsWglArbMultisample = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglArbMultisample() noexcept
{
    return existsWglArbMultisample;
}

void System::InitWglArbMultisample()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_ARB_multisample") || IsOpenGLSupportsExtension("WGL_ARB_multisample"))
    {
        existsWglArbMultisample = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglArbMultisample = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglArbMultisample = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_ARB_pbuffer

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

System::WglHPBufferArb System::WglCreatePbufferARB(WindowsHdc hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_5_RESULT(wglCreatePbufferARB, hDC, iPixelFormat, iWidth, iHeight, piAttribList, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, iPixelFormat, iWidth, iHeight, piAttribList);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHdc System::WglGetPbufferDCARB(WglHPBufferArb hPbuffer) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglGetPbufferDCARB, hPbuffer, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hPbuffer);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::WglReleasePbufferDCARB(WglHPBufferArb hPbuffer, WindowsHdc hDC) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglReleasePbufferDCARB, hPbuffer, hDC, 0);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hPbuffer, hDC);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDestroyPbufferARB(WglHPBufferArb hPbuffer) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglDestroyPbufferARB, hPbuffer, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hPbuffer);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglQueryPbufferARB(WglHPBufferArb hPbuffer, int iAttribute, int* piValue) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglQueryPbufferARB, hPbuffer, iAttribute, piValue, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hPbuffer, iAttribute, piValue);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_ARB_pixel_format

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

System::WindowsBool System::WglGetPixelFormatAttribivARB(WindowsHdc hdc, int iPixelFormat, int iLayerPlane, WindowsUInt nAttributes, const int* piAttributes, int* piValues) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_6_RESULT(wglGetPixelFormatAttribivARB, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGetPixelFormatAttribfvARB(WindowsHdc hdc, int iPixelFormat, int iLayerPlane, WindowsUInt nAttributes, const int* piAttributes, float* pfValues) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_6_RESULT(wglGetPixelFormatAttribfvARB, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglChoosePixelFormatARB(WindowsHdc hdc, const int* piAttribIList, const float* pfAttribFList, WindowsUInt nMaxFormats, int* piFormats, WindowsUInt* nNumFormats) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_6_RESULT(wglChoosePixelFormatARB, hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_ARB_pixel_format_float

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

// WGL_ARB_render_texture

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

System::WindowsBool System::WglBindTexImageARB(WglHPBufferArb hPbuffer, int iBuffer) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglBindTexImageARB, hPbuffer, iBuffer, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hPbuffer, iBuffer);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglReleaseTexImageARB(WglHPBufferArb hPbuffer, int iBuffer) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglReleaseTexImageARB, hPbuffer, iBuffer, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hPbuffer, iBuffer);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglSetPbufferAttribARB(WglHPBufferArb hPbuffer, const int* piAttribList) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglSetPbufferAttribARB, hPbuffer, piAttribList, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hPbuffer, piAttribList);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_ARB_robustness_application_isolation

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

// WGL_ARB_robustness_share_group_isolation

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

// 3DFX 扩展

// WGL_3DFX_multisample

namespace System
{
    auto existsWgl3DFXMultisample = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWgl3DFXMultisample() noexcept
{
    return existsWgl3DFXMultisample;
}

void System::InitWgl3DFXMultisample()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_3DFX_multisample") || IsOpenGLSupportsExtension("WGL_3DFX_multisample"))
    {
        existsWgl3DFXMultisample = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWgl3DFXMultisample = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWgl3DFXMultisample = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

// 3DL 扩展

// WGL_3DL_stereo_control

namespace System
{
    auto existsWgl3DLStereoControl = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLSETSTEREOEMITTERSTATE3DLPROC wglSetStereoEmitterState3DL{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWgl3DLStereoControl() noexcept
{
    return existsWgl3DLStereoControl;
}

void System::InitWgl3DLStereoControl()
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

System::WindowsBool System::WglSetStereoEmitterState3DL(WindowsHdc hDC, WindowsUInt uState) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglSetStereoEmitterState3DL, hDC, uState, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, uState);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

// AMD 扩展

// WGL_AMD_gpu_association

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

System::WindowsUInt System::WglGetGPUIDsAMD(WindowsUInt maxCount, WindowsUInt* ids) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglGetGPUIDsAMD, maxCount, ids, 0u);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(maxCount, ids);

    return 0u;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsInt System::WglGetGPUInfoAMD(WindowsUInt id, WindowsInt property, GLenum dataType, WindowsUInt size, void* data) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_5_RESULT(wglGetGPUInfoAMD, id, property, dataType, size, data, 0);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(id, property, dataType, size, data);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsUInt System::WglGetContextGPUIDAMD(OpenGLHglrc hglrc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglGetContextGPUIDAMD, hglrc, 0u);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hglrc);

    return 0u;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::OpenGLHglrc System::WglCreateAssociatedContextAMD(WindowsUInt id) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglCreateAssociatedContextAMD, id, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(id);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::OpenGLHglrc System::WglCreateAssociatedContextAttribsAMD(WindowsUInt id, OpenGLHglrc hShareContext, const int* attribList) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglCreateAssociatedContextAttribsAMD, id, hShareContext, attribList, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(id, hShareContext, attribList);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDeleteAssociatedContextAMD(OpenGLHglrc hglrc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglDeleteAssociatedContextAMD, hglrc, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hglrc);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglMakeAssociatedContextCurrentAMD(OpenGLHglrc hglrc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglMakeAssociatedContextCurrentAMD, hglrc, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hglrc);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::OpenGLHglrc System::WglGetCurrentAssociatedContextAMD() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_0_RESULT(wglGetCurrentAssociatedContextAMD, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::WglBlitContextFramebufferAMD(OpenGLHglrc dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_11(wglBlitContextFramebufferAMD, dstCtx, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(dstCtx, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);

#endif  // SYSTEM_PLATFORM_WIN32
}

// ATI 扩展

// WGL_ATI_pixel_format_float

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

// WGL_ATI_render_texture_rectangle

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

// EXT 扩展

// WGL_EXT_colorspace

namespace System
{
    auto existsWglExtColorspace = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglExtColorspace() noexcept
{
    return existsWglExtColorspace;
}

void System::InitWglExtColorspace()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_EXT_colorspace") || IsOpenGLSupportsExtension("WGL_EXT_colorspace"))
    {
        existsWglExtColorspace = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglExtColorspace = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglExtColorspace = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_EXT_create_context_es2_profile

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

// WGL_EXT_create_context_es_profile

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

// WGL_EXT_depth_float

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

// WGL_EXT_display_color_table

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

// WGL_EXT_extensions_string

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

// WGL_EXT_framebuffer_sRGB

namespace System
{
    auto existsWglExtFramebufferSRGB = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglExtFramebufferSRGB() noexcept
{
    return existsWglExtFramebufferSRGB;
}

void System::InitWglExtFramebufferSRGB()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_EXT_framebuffer_sRGB") || IsOpenGLSupportsExtension("WGL_EXT_framebuffer_sRGB"))
    {
        existsWglExtFramebufferSRGB = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglExtFramebufferSRGB = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglExtFramebufferSRGB = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_EXT_make_current_read

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

System::WindowsBool System::WglMakeContextCurrentEXT(WindowsHdc hDrawDC, WindowsHdc hReadDC, OpenGLHglrc hglrc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglMakeContextCurrentEXT, hDrawDC, hReadDC, hglrc, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDrawDC, hReadDC, hglrc);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHdc System::WglGetCurrentReadDCEXT() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_0_RESULT(wglGetCurrentReadDCEXT, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_EXT_multisample

namespace System
{
    auto existsWglExtMultisample = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglExtMultisample() noexcept
{
    return existsWglExtMultisample;
}

void System::InitWglExtMultisample()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_EXT_multisample") || IsOpenGLSupportsExtension("WGL_EXT_multisample"))
    {
        existsWglExtMultisample = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglExtMultisample = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglExtMultisample = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_EXT_pbuffer

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

System::WglHPBufferExt System::WglCreatePbufferEXT(WindowsHdc hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_5_RESULT(wglCreatePbufferEXT, hDC, iPixelFormat, iWidth, iHeight, piAttribList, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, iPixelFormat, iWidth, iHeight, piAttribList);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHdc System::WglGetPbufferDCEXT(WglHPBufferExt hPbuffer) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglGetPbufferDCEXT, hPbuffer, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hPbuffer);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::WglReleasePbufferDCEXT(WglHPBufferExt hPbuffer, WindowsHdc hDC) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglReleasePbufferDCEXT, hPbuffer, hDC, 0);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hPbuffer, hDC);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDestroyPbufferEXT(WglHPBufferExt hPbuffer) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglDestroyPbufferEXT, hPbuffer, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hPbuffer);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglQueryPbufferEXT(WglHPBufferExt hPbuffer, int iAttribute, int* piValue) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglQueryPbufferEXT, hPbuffer, iAttribute, piValue, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hPbuffer, iAttribute, piValue);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_EXT_pixel_format

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

System::WindowsBool System::WglGetPixelFormatAttribivEXT(WindowsHdc hdc, int iPixelFormat, int iLayerPlane, WindowsUInt nAttributes, int* piAttributes, int* piValues) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_6_RESULT(wglGetPixelFormatAttribivEXT, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGetPixelFormatAttribfvEXT(WindowsHdc hdc, int iPixelFormat, int iLayerPlane, WindowsUInt nAttributes, int* piAttributes, float* pfValues) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_6_RESULT(wglGetPixelFormatAttribfvEXT, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglChoosePixelFormatEXT(WindowsHdc hdc, const int* piAttribIList, const float* pfAttribFList, WindowsUInt nMaxFormats, int* piFormats, WindowsUInt* nNumFormats) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_6_RESULT(wglChoosePixelFormatEXT, hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_EXT_pixel_format_packed_float

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

// WGL_EXT_swap_control

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

// WGL_EXT_swap_control_tear

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

// I3D 扩展

// WGL_I3D_digital_video_control

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

System::WindowsBool System::WglGetDigitalVideoParametersI3D(WindowsHdc hDC, int iAttribute, int* piValue) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglGetDigitalVideoParametersI3D, hDC, iAttribute, piValue, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, iAttribute, piValue);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglSetDigitalVideoParametersI3D(WindowsHdc hDC, int iAttribute, const int* piValue) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglSetDigitalVideoParametersI3D, hDC, iAttribute, piValue, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, iAttribute, piValue);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_I3D_gamma

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

System::WindowsBool System::WglGetGammaTableParametersI3D(WindowsHdc hDC, int iAttribute, int* piValue) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglGetGammaTableParametersI3D, hDC, iAttribute, piValue, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, iAttribute, piValue);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglSetGammaTableParametersI3D(WindowsHdc hDC, int iAttribute, const int* piValue) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglSetGammaTableParametersI3D, hDC, iAttribute, piValue, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, iAttribute, piValue);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGetGammaTableI3D(WindowsHdc hDC, int iEntries, WindowsUShort* puRed, WindowsUShort* puGreen, WindowsUShort* puBlue) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_5_RESULT(wglGetGammaTableI3D, hDC, iEntries, puRed, puGreen, puBlue, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, iEntries, puRed, puGreen, puBlue);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglSetGammaTableI3D(WindowsHdc hDC, int iEntries, const WindowsUShort* puRed, const WindowsUShort* puGreen, const WindowsUShort* puBlue) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_5_RESULT(wglSetGammaTableI3D, hDC, iEntries, puRed, puGreen, puBlue, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, iEntries, puRed, puGreen, puBlue);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_I3D_genlock

namespace System
{
    auto existsWglI3DGenlock = ExistsOpenGLExtensions::Unknown;

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

System::ExistsOpenGLExtensions System::IsExistsWglI3DGenlock() noexcept
{
    return existsWglI3DGenlock;
}

void System::InitWglI3DGenlock()
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

        existsWglI3DGenlock = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglI3DGenlock = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglI3DGenlock = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglEnableGenlockI3D(WindowsHdc hDC) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglEnableGenlockI3D, hDC, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDisableGenlockI3D(WindowsHdc hDC) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglDisableGenlockI3D, hDC, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglIsEnabledGenlockI3D(WindowsHdc hDC, WindowsBool* pFlag) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglIsEnabledGenlockI3D, hDC, pFlag, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, pFlag);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGenlockSourceI3D(WindowsHdc hDC, WindowsUInt uSource) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglGenlockSourceI3D, hDC, uSource, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, uSource);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGetGenlockSourceI3D(WindowsHdc hDC, WindowsUInt* uSource) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglGetGenlockSourceI3D, hDC, uSource, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, uSource);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGenlockSourceEdgeI3D(WindowsHdc hDC, WindowsUInt uEdge) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglGenlockSourceEdgeI3D, hDC, uEdge, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, uEdge);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGetGenlockSourceEdgeI3D(WindowsHdc hDC, WindowsUInt* uEdge) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglGetGenlockSourceEdgeI3D, hDC, uEdge, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, uEdge);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGenlockSampleRateI3D(WindowsHdc hDC, WindowsUInt uRate) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglGenlockSampleRateI3D, hDC, uRate, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, uRate);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGetGenlockSampleRateI3D(WindowsHdc hDC, WindowsUInt* uRate) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglGetGenlockSampleRateI3D, hDC, uRate, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, uRate);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGenlockSourceDelayI3D(WindowsHdc hDC, WindowsUInt uDelay) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglGenlockSourceDelayI3D, hDC, uDelay, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, uDelay);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGetGenlockSourceDelayI3D(WindowsHdc hDC, WindowsUInt* uDelay) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglGetGenlockSourceDelayI3D, hDC, uDelay, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, uDelay);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglQueryGenlockMaxSourceDelayI3D(WindowsHdc hDC, WindowsUInt* uMaxLineDelay, WindowsUInt* uMaxPixelDelay) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglQueryGenlockMaxSourceDelayI3D, hDC, uMaxLineDelay, uMaxPixelDelay, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, uMaxLineDelay, uMaxPixelDelay);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_I3D_image_buffer

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

System::WindowsVoidPtr System::WglCreateImageBufferI3D(WindowsHdc hDC, WindowsDWord dwSize, WindowsUInt uFlags) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglCreateImageBufferI3D, hDC, dwSize, uFlags, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, dwSize, uFlags);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDestroyImageBufferI3D(WindowsHdc hDC, WindowsVoidPtr pAddress) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglDestroyImageBufferI3D, hDC, pAddress, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, pAddress);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglAssociateImageBufferEventsI3D(WindowsHdc hDC, const WindowsHandle* pEvent, const WindowsVoidPtr* pAddress, const WindowsDWord* pSize, WindowsUInt count) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_5_RESULT(wglAssociateImageBufferEventsI3D, hDC, pEvent, pAddress, pSize, count, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, pEvent, pAddress, pSize, count);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglReleaseImageBufferEventsI3D(WindowsHdc hDC, const WindowsVoidPtr* pAddress, WindowsUInt count) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglReleaseImageBufferEventsI3D, hDC, pAddress, count, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, pAddress, count);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_I3D_swap_frame_lock

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

System::WindowsBool System::WglIsEnabledFrameLockI3D(WindowsBool* pFlag) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglIsEnabledFrameLockI3D, pFlag, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(pFlag);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglQueryFrameLockMasterI3D(WindowsBool* pFlag) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglQueryFrameLockMasterI3D, pFlag, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(pFlag);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_I3D_swap_frame_usage

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

System::WindowsBool System::WglGetFrameUsageI3D(float* pUsage) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglGetFrameUsageI3D, pUsage, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(pUsage);

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

System::WindowsBool System::WglQueryFrameTrackingI3D(WindowsDWord* pFrameCount, WindowsDWord* pMissedFrames, float* pLastMissedUsage) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglQueryFrameTrackingI3D, pFrameCount, pMissedFrames, pLastMissedUsage, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(pFrameCount, pMissedFrames, pLastMissedUsage);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

// NV 扩展

// WGL_NV_DX_interop

namespace System
{
    auto existsWglNVDXInterop = ExistsOpenGLExtensions::Unknown;

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

System::ExistsOpenGLExtensions System::IsExistsWglNVDXInterop() noexcept
{
    return existsWglNVDXInterop;
}

void System::InitWglNVDXIntero()
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

        existsWglNVDXInterop = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNVDXInterop = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNVDXInterop = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDXSetResourceShareHandleNV(void* dxObject, WindowsHandle shareHandle) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglDXSetResourceShareHandleNV, dxObject, shareHandle, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(dxObject, shareHandle);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHandle System::WglDXOpenDeviceNV(void* dxDevice) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglDXOpenDeviceNV, dxDevice, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(dxDevice);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDXCloseDeviceNV(WindowsHandle hDevice) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglDXCloseDeviceNV, hDevice, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDevice);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHandle System::WglDXRegisterObjectNV(WindowsHandle hDevice, void* dxObject, GLuint name, GLenum type, GLenum access) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_5_RESULT(wglDXRegisterObjectNV, hDevice, dxObject, name, type, access, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDevice, dxObject, name, type, access);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDXUnregisterObjectNV(WindowsHandle hDevice, WindowsHandle hObject) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglDXUnregisterObjectNV, hDevice, hObject, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDevice, hObject);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDXObjectAccessNV(WindowsHandle hObject, GLenum access) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglDXObjectAccessNV, hObject, access, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hObject, access);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDXLockObjectsNV(WindowsHandle hDevice, GLint count, WindowsHandle* hObjects) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglDXLockObjectsNV, hDevice, count, hObjects, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDevice, count, hObjects);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDXUnlockObjectsNV(WindowsHandle hDevice, GLint count, WindowsHandle* hObjects) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglDXUnlockObjectsNV, hDevice, count, hObjects, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDevice, count, hObjects);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_NV_DX_interop2

namespace System
{
    auto existsWglNVDXInterop2 = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglNVDXInterop2() noexcept
{
    return existsWglNVDXInterop2;
}

void System::InitWglNVDXIntero2()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_NV_DX_interop2") || IsOpenGLSupportsExtension("WGL_NV_DX_interop2"))
    {
        existsWglNVDXInterop2 = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNVDXInterop2 = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNVDXInterop2 = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_NV_copy_image

namespace System
{
    auto existsWglNVCopyImage = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLCOPYIMAGESUBDATANVPROC wglCopyImageSubDataNV{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglNVCopyImage() noexcept
{
    return existsWglNVCopyImage;
}

void System::InitWglNVCopyImage()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_NV_copy_image") || IsOpenGLSupportsExtension("WGL_NV_copy_image"))
    {
        SYSTEM_GET_FUNCTION(wglCopyImageSubDataNV);

        existsWglNVCopyImage = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNVCopyImage = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNVCopyImage = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglCopyImageSubDataNV(OpenGLHglrc hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, OpenGLHglrc hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_17_RESULT(wglCopyImageSubDataNV, hSrcRC, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, hDstRC, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hSrcRC, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, hDstRC, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_NV_delay_before_swap

namespace System
{
    auto existsWglNVDelayBeforeSwap = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLDELAYBEFORESWAPNVPROC wglDelayBeforeSwapNV{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglNVDelayBeforeSwap() noexcept
{
    return existsWglNVDelayBeforeSwap;
}

void System::InitWglNVDelayBeforeSwap()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_NV_delay_before_swap") || IsOpenGLSupportsExtension("WGL_NV_delay_before_swap"))
    {
        SYSTEM_GET_FUNCTION(wglDelayBeforeSwapNV);

        existsWglNVDelayBeforeSwap = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNVDelayBeforeSwap = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNVDelayBeforeSwap = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDelayBeforeSwapNV(WindowsHdc hDC, GLfloat seconds) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglDelayBeforeSwapNV, hDC, seconds, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, seconds);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_NV_float_buffer

namespace System
{
    auto existsWglNVFloatBuffer = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglNVFloatBuffer() noexcept
{
    return existsWglNVFloatBuffer;
}

void System::InitWglNVFloatBuffer()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_NV_float_buffer") || IsOpenGLSupportsExtension("WGL_NV_float_buffer"))
    {
        existsWglNVFloatBuffer = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNVFloatBuffer = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNVFloatBuffer = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_NV_gpu_affinity

namespace System
{
    auto existsWglNVGpuAffinity = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLENUMGPUSNVPROC wglEnumGpusNV{ nullptr };
    PFNWGLENUMGPUDEVICESNVPROC wglEnumGpuDevicesNV{ nullptr };
    PFNWGLCREATEAFFINITYDCNVPROC wglCreateAffinityDCNV{ nullptr };
    PFNWGLENUMGPUSFROMAFFINITYDCNVPROC wglEnumGpusFromAffinityDCNV{ nullptr };
    PFNWGLDELETEDCNVPROC wglDeleteDCNV{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglNVGpuAffinity() noexcept
{
    return existsWglNVGpuAffinity;
}

void System::InitWglNVGpuAffinity()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_NV_gpu_affinity") || IsOpenGLSupportsExtension("WGL_NV_gpu_affinity"))
    {
        SYSTEM_GET_FUNCTION(wglEnumGpusNV);
        SYSTEM_GET_FUNCTION(wglEnumGpuDevicesNV);
        SYSTEM_GET_FUNCTION(wglCreateAffinityDCNV);
        SYSTEM_GET_FUNCTION(wglEnumGpusFromAffinityDCNV);
        SYSTEM_GET_FUNCTION(wglDeleteDCNV);

        existsWglNVGpuAffinity = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNVGpuAffinity = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNVGpuAffinity = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglEnumGpusNV(WindowsUInt iGpuIndex, WglHGpuNv* phGpu) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglEnumGpusNV, iGpuIndex, phGpu, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(iGpuIndex, phGpu);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglEnumGpuDevicesNV(WglHGpuNv hGpu, WindowsUInt iDeviceIndex, WglGpuDevicePtr lpGpuDevice) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglEnumGpuDevicesNV, hGpu, iDeviceIndex, lpGpuDevice, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hGpu, iDeviceIndex, lpGpuDevice);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHdc System::WglCreateAffinityDCNV(const WglHGpuNv* phGpuList) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglCreateAffinityDCNV, phGpuList, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(phGpuList);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglEnumGpusFromAffinityDCNV(WindowsHdc hAffinityDC, WindowsUInt iGpuIndex, WglHGpuNv* hGpu) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglEnumGpusFromAffinityDCNV, hAffinityDC, iGpuIndex, hGpu, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hAffinityDC, iGpuIndex, hGpu);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglDeleteDCNV(WindowsHdc hdc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglDeleteDCNV, hdc, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_NV_multigpu_context

namespace System
{
    auto existsWglNVMultigpuContext = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglNVMultigpuContext() noexcept
{
    return existsWglNVMultigpuContext;
}

void System::InitWglNVMultigpuContext()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_NV_multigpu_context") || IsOpenGLSupportsExtension("WGL_NV_multigpu_context"))
    {
        existsWglNVMultigpuContext = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNVMultigpuContext = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNVMultigpuContext = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_NV_multisample_coverage

namespace System
{
    auto existsWglNVMultisampleCoverage = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglNVMultisampleCoverage() noexcept
{
    return existsWglNVMultisampleCoverage;
}

void System::InitWglNVMultisampleCoverage()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_NV_multisample_coverage") || IsOpenGLSupportsExtension("WGL_NV_multisample_coverage"))
    {
        existsWglNVMultisampleCoverage = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNVMultisampleCoverage = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNVMultisampleCoverage = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_NV_present_video

namespace System
{
    auto existsWglNVPresentVideo = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLENUMERATEVIDEODEVICESNVPROC wglEnumerateVideoDevicesNV{ nullptr };
    PFNWGLBINDVIDEODEVICENVPROC wglBindVideoDeviceNV{ nullptr };
    PFNWGLQUERYCURRENTCONTEXTNVPROC wglQueryCurrentContextNV{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglNVPresentVideo() noexcept
{
    return existsWglNVPresentVideo;
}

void System::InitWglNVPresentVideo()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_NV_present_video") || IsOpenGLSupportsExtension("WGL_NV_present_video"))
    {
        SYSTEM_GET_FUNCTION(wglEnumerateVideoDevicesNV);
        SYSTEM_GET_FUNCTION(wglBindVideoDeviceNV);
        SYSTEM_GET_FUNCTION(wglQueryCurrentContextNV);

        existsWglNVPresentVideo = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNVPresentVideo = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNVPresentVideo = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::WglEnumerateVideoDevicesNV(WindowsHdc hDc, WglHVideoOutputDeviceNv* phDeviceList) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglEnumerateVideoDevicesNV, hDc, phDeviceList, 0);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDc, phDeviceList);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglBindVideoDeviceNV(WindowsHdc hDc, unsigned int uVideoSlot, WglHVideoOutputDeviceNv hVideoDevice, const int* piAttribList) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_4_RESULT(wglBindVideoDeviceNV, hDc, uVideoSlot, hVideoDevice, piAttribList, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDc, uVideoSlot, hVideoDevice, piAttribList);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglQueryCurrentContextNV(int iAttribute, int* piValue) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglQueryCurrentContextNV, iAttribute, piValue, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(iAttribute, piValue);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_NV_render_depth_texture

namespace System
{
    auto existsWglNVRenderDepthTexture = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglNVRenderDepthTexture() noexcept
{
    return existsWglNVRenderDepthTexture;
}

void System::InitWglNVRenderDepthTexture()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_NV_render_depth_texture") || IsOpenGLSupportsExtension("WGL_NV_render_depth_texture"))
    {
        existsWglNVRenderDepthTexture = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNVRenderDepthTexture = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNVRenderDepthTexture = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_NV_render_texture_rectangle

namespace System
{
    auto existsWglNVRenderTextureRectangle = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsWglNVRenderTextureRectangle() noexcept
{
    return existsWglNVRenderTextureRectangle;
}

void System::InitWglNVRenderTextureRectangle()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_NV_render_texture_rectangle") || IsOpenGLSupportsExtension("WGL_NV_render_texture_rectangle"))
    {
        existsWglNVRenderTextureRectangle = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNVRenderTextureRectangle = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNVRenderTextureRectangle = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_NV_swap_group

namespace System
{
    auto existsWglNVSwapGroup = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLJOINSWAPGROUPNVPROC wglJoinSwapGroupNV{ nullptr };
    PFNWGLBINDSWAPBARRIERNVPROC wglBindSwapBarrierNV{ nullptr };
    PFNWGLQUERYSWAPGROUPNVPROC wglQuerySwapGroupNV{ nullptr };
    PFNWGLQUERYMAXSWAPGROUPSNVPROC wglQueryMaxSwapGroupsNV{ nullptr };
    PFNWGLQUERYFRAMECOUNTNVPROC wglQueryFrameCountNV{ nullptr };
    PFNWGLRESETFRAMECOUNTNVPROC wglResetFrameCountNV{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglNVSwapGroup() noexcept
{
    return existsWglNVSwapGroup;
}

void System::InitWglNVSwapGroup()
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

        existsWglNVSwapGroup = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNVSwapGroup = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNVSwapGroup = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglJoinSwapGroupNV(WindowsHdc hDC, GLuint group) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglJoinSwapGroupNV, hDC, group, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, group);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglBindSwapBarrierNV(GLuint group, GLuint barrier) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglBindSwapBarrierNV, group, barrier, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(group, barrier);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglQuerySwapGroupNV(WindowsHdc hDC, GLuint* group, GLuint* barrier) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglQuerySwapGroupNV, hDC, group, barrier, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, group, barrier);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglQueryMaxSwapGroupsNV(WindowsHdc hDC, GLuint* maxGroups, GLuint* maxBarriers) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglQueryMaxSwapGroupsNV, hDC, maxGroups, maxBarriers, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, maxGroups, maxBarriers);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglQueryFrameCountNV(WindowsHdc hDC, GLuint* count) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglQueryFrameCountNV, hDC, count, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, count);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglResetFrameCountNV(WindowsHdc hDC) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglResetFrameCountNV, hDC, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_NV_vertex_array_range

namespace System
{
    auto existsWglNVVertexArrayRange = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLALLOCATEMEMORYNVPROC wglAllocateMemoryNV{ nullptr };
    PFNWGLFREEMEMORYNVPROC wglFreeMemoryNV{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglNVVertexArrayRange() noexcept
{
    return existsWglNVVertexArrayRange;
}

void System::InitWglNVVertexArrayRange()
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

void* System::WglAllocateMemoryNV(GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_4_RESULT(wglAllocateMemoryNV, size, readfreq, writefreq, priority, nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(size, readfreq, writefreq, priority);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::WglFreeMemoryNV(void* pointer) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1(wglFreeMemoryNV, pointer);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(pointer);

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_NV_video_capture

namespace System
{
    auto existsWglNVVideoCapture = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLBINDVIDEOCAPTUREDEVICENVPROC wglBindVideoCaptureDeviceNV{ nullptr };
    PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC wglEnumerateVideoCaptureDevicesNV{ nullptr };
    PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC wglLockVideoCaptureDeviceNV{ nullptr };
    PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC wglQueryVideoCaptureDeviceNV{ nullptr };
    PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC wglReleaseVideoCaptureDeviceNV{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglNVVideoCapture() noexcept
{
    return existsWglNVVideoCapture;
}

void System::InitWglNVVideoCapture()
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (SupportsWglExtension("WGL_NV_video_capture") || IsOpenGLSupportsExtension("WGL_NV_video_capture"))
    {
        SYSTEM_GET_FUNCTION(wglBindVideoCaptureDeviceNV);
        SYSTEM_GET_FUNCTION(wglEnumerateVideoCaptureDevicesNV);
        SYSTEM_GET_FUNCTION(wglLockVideoCaptureDeviceNV);
        SYSTEM_GET_FUNCTION(wglQueryVideoCaptureDeviceNV);
        SYSTEM_GET_FUNCTION(wglReleaseVideoCaptureDeviceNV);

        existsWglNVVideoCapture = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNVVideoCapture = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNVVideoCapture = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglBindVideoCaptureDeviceNV(WindowsUInt uVideoSlot, WglHVideoInputDeviceNv hDevice) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglBindVideoCaptureDeviceNV, uVideoSlot, hDevice, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(uVideoSlot, hDevice);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsUInt System::WglEnumerateVideoCaptureDevicesNV(WindowsHdc hDc, WglHVideoInputDeviceNv* phDeviceList) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglEnumerateVideoCaptureDevicesNV, hDc, phDeviceList, 0u);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDc, phDeviceList);

    return 0u;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglLockVideoCaptureDeviceNV(WindowsHdc hDc, WglHVideoInputDeviceNv hDevice) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglLockVideoCaptureDeviceNV, hDc, hDevice, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDc, hDevice);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglQueryVideoCaptureDeviceNV(WindowsHdc hDc, WglHVideoInputDeviceNv hDevice, int iAttribute, int* piValue) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_4_RESULT(wglQueryVideoCaptureDeviceNV, hDc, hDevice, iAttribute, piValue, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDc, hDevice, iAttribute, piValue);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglReleaseVideoCaptureDeviceNV(WindowsHdc hDc, WglHVideoInputDeviceNv hDevice) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglReleaseVideoCaptureDeviceNV, hDc, hDevice, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDc, hDevice);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

// WGL_NV_video_output

namespace System
{
    auto existsWglNVVideoOutput = ExistsOpenGLExtensions::Unknown;

#if defined(SYSTEM_PLATFORM_WIN32)

    PFNWGLGETVIDEODEVICENVPROC wglGetVideoDeviceNV{ nullptr };
    PFNWGLRELEASEVIDEODEVICENVPROC wglReleaseVideoDeviceNV{ nullptr };
    PFNWGLBINDVIDEOIMAGENVPROC wglBindVideoImageNV{ nullptr };
    PFNWGLRELEASEVIDEOIMAGENVPROC wglReleaseVideoImageNV{ nullptr };
    PFNWGLSENDPBUFFERTOVIDEONVPROC wglSendPbufferToVideoNV{ nullptr };
    PFNWGLGETVIDEOINFONVPROC wglGetVideoInfoNV{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsWglNVVideoOutput() noexcept
{
    return existsWglNVVideoOutput;
}

void System::InitWglNVVideoOutput()
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

        existsWglNVVideoOutput = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsWglNVVideoOutput = ExistsOpenGLExtensions::NotExist;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    existsWglNVVideoOutput = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGetVideoDeviceNV(WindowsHdc hDC, int numDevices, WglHPVideoDev* hVideoDevice) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglGetVideoDeviceNV, hDC, numDevices, hVideoDevice, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, numDevices, hVideoDevice);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglReleaseVideoDeviceNV(WglHPVideoDev hVideoDevice) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_1_RESULT(wglReleaseVideoDeviceNV, hVideoDevice, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hVideoDevice);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglBindVideoImageNV(WglHPVideoDev hVideoDevice, WglHPBufferArb hPbuffer, int iVideoBuffer) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglBindVideoImageNV, hVideoDevice, hPbuffer, iVideoBuffer, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hVideoDevice, hPbuffer, iVideoBuffer);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglReleaseVideoImageNV(WglHPBufferArb hPbuffer, int iVideoBuffer) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_2_RESULT(wglReleaseVideoImageNV, hPbuffer, iVideoBuffer, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hPbuffer, iVideoBuffer);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglSendPbufferToVideoNV(WglHPBufferArb hPbuffer, int iBufferType, unsigned long* pulCounterPbuffer, WindowsBool bBlock) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_4_RESULT(wglSendPbufferToVideoNV, hPbuffer, iBufferType, pulCounterPbuffer, bBlock, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hPbuffer, iBufferType, pulCounterPbuffer, bBlock);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglGetVideoInfoNV(WglHPVideoDev hpVideoDevice, unsigned long* pulCounterOutputPbuffer, unsigned long* pulCounterOutputVideo) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_3_RESULT(wglGetVideoInfoNV, hpVideoDevice, pulCounterOutputPbuffer, pulCounterOutputVideo, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hpVideoDevice, pulCounterOutputPbuffer, pulCounterOutputVideo);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

// OML 扩展

// WGL_OML_sync_control

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

System::WindowsInt64 System::WglSwapBuffersMscOML(WindowsHdc hdc, WindowsInt64 target_msc, WindowsInt64 divisor, WindowsInt64 remainder) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_4_RESULT(wglSwapBuffersMscOML, hdc, target_msc, divisor, remainder, 0);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, target_msc, divisor, remainder);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsInt64 System::WglSwapLayerBuffersMscOML(WindowsHdc hdc, WindowsInt fuPlanes, WindowsInt64 target_msc, WindowsInt64 divisor, WindowsInt64 remainder) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_5_RESULT(wglSwapLayerBuffersMscOML, hdc, fuPlanes, target_msc, divisor, remainder, 0);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, fuPlanes, target_msc, divisor, remainder);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglWaitForMscOML(WindowsHdc hdc, WindowsInt64 target_msc, WindowsInt64 divisor, WindowsInt64 remainder, WindowsInt64* ust, WindowsInt64* msc, WindowsInt64* sbc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_7_RESULT(wglWaitForMscOML, hdc, target_msc, divisor, remainder, ust, msc, sbc, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, target_msc, divisor, remainder, ust, msc, sbc);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglWaitForSbcOML(WindowsHdc hdc, WindowsInt64 target_sbc, WindowsInt64* ust, WindowsInt64* msc, WindowsInt64* sbc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    SYSTEM_BODY_5_RESULT(wglWaitForSbcOML, hdc, target_sbc, ust, msc, sbc, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, target_sbc, ust, msc, sbc);

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
    InitWglArbFramebufferSRGB();
    InitWglArbMakeCurrentRead();
    InitWglArbMultisample();
    InitWglArbPBuffer();
    InitWglArbPixelFormat();
    InitWglArbPixelFormatFloat();
    InitWglArbRenderTexture();
    InitWglArbRobustnessApplicationIsolation();
    InitWglArbRobustnessShareGroupIsolation();

    InitWgl3DFXMultisample();

    InitWgl3DLStereoControl();

    InitWglAMDGpuAssociation();

    InitWglATIPixelFormatFloat();
    InitWglATIRenderTextureRectangle();

    InitWglExtColorspace();
    InitWglExtCreateContextEs2Profile();
    InitWglExtCreateContextEsProfile();
    InitWglExtDepthFloat();
    InitWglExtDisplayColorTable();
    InitWglExtFramebufferSRGB();
    InitWglExtMakeCurrentRead();
    InitWglExtMultisample();
    InitWglExtPBuffer();
    InitWglExtPixelFormat();
    InitWglExtPixelFormatPackedFloat();
    InitWglExtSwapControl();
    InitWglExtSwapControlTear();

    InitWglI3DDigitalVideoControl();
    InitWglI3DGamma();
    InitWglI3DGenlock();
    InitWglI3DImageBuffer();
    InitWglI3DSwapFrameUsage();

    InitWglNVDXIntero();
    InitWglNVDXIntero2();
    InitWglNVCopyImage();
    InitWglNVDelayBeforeSwap();
    InitWglNVFloatBuffer();
    InitWglNVGpuAffinity();
    InitWglNVMultigpuContext();
    InitWglNVMultisampleCoverage();
    InitWglNVPresentVideo();
    InitWglNVRenderDepthTexture();
    InitWglNVRenderTextureRectangle();
    InitWglNVSwapGroup();
    InitWglNVVertexArrayRange();
    InitWglNVVideoCapture();
    InitWglNVVideoOutput();

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

    const auto endPos = pos + StrLen(wglExtension);

    if (extension.size() <= endPos)
    {
        return true;
    }

    const auto end = extension.at(endPos);

    // 扩展被发现,但确保它不是另一个扩展的合适子串。
    return end == ' ' || end == 0 || end == '\t' || end == '\n';
}
