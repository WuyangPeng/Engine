///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.0 (2023/01/12 19:00)

#include "System/SystemExport.h"

#include "GLExtensions.h"
#include "GLUtility.h"
#include "WglExtensions.h"
#include "System/CharacterString/FormatString.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "System/OpenGL/OpenGLWglPrototypes.h"

using std::string;

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

int System::ChoosePixelFormat(WindowsHDC hDc, const PixelFormatDescriptor* pPfd) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::ChoosePixelFormat(hDc, pPfd);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDc, pPfd);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::DescribePixelFormat(WindowsHDC hdc, int ipfd, WindowsUInt cjpfd, PixelFormatDescriptor* ppfd) noexcept
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

int System::GetPixelFormat(WindowsHDC hdc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::GetPixelFormat(hdc);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc);

    return 0u;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::SetPixelFormat(WindowsHDC hdc, int ipfd, const PixelFormatDescriptor* ppfd) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::SetPixelFormat(hdc, ipfd, ppfd);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, ipfd, ppfd);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::SwapBuffers(WindowsHDC hdc) noexcept
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

System::OpenGLHglrc System::WglCreateContext(WindowsHDC hDc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglCreateContext(hDc);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDc);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::OpenGLHglrc System::WglCreateLayerContext(WindowsHDC hDc, int level) noexcept
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

System::WindowsBool System::WglDescribeLayerPlane(WindowsHDC hDc, int pixelFormat, int layerPlane, WindowsUInt nBytes, LayerPlaneDescriptor* plpd) noexcept
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

System::WindowsHDC System::WglGetCurrentDC() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglGetCurrentDC();

#else  // !SYSTEM_PLATFORM_WIN32

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::WglGetLayerPaletteEntries(WindowsHDC hdc, int iLayerPlane, int iStart, int cEntries, OpenGLColorref* pcr) noexcept
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

System::WindowsBool System::WglMakeCurrent(WindowsHDC hDc, OpenGLHglrc newContext) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglMakeCurrent(hDc, newContext);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDc, newContext);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglRealizeLayerPalette(WindowsHDC hdc, int iLayerPlane, WindowsBool bRealize) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglRealizeLayerPalette(hdc, iLayerPlane, bRealize);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, iLayerPlane, bRealize);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::WglSetLayerPaletteEntries(WindowsHDC hdc, int iLayerPlane, int iStart, int cEntries, const OpenGLColorref* pcr) noexcept
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

System::WindowsBool System::WglSwapLayerBuffers(WindowsHDC hdc, WindowsUInt fuFlags) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglSwapLayerBuffers(hdc, fuFlags);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc, fuFlags);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglUseFontBitmaps(WindowsHDC hDC, WindowsDWord first, WindowsDWord count, WindowsDWord listBase) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglUseFontBitmaps(hDC, first, count, listBase);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, first, count, listBase);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglUseFontBitmapsA(WindowsHDC hDC, WindowsDWord first, WindowsDWord count, WindowsDWord listBase) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglUseFontBitmapsA(hDC, first, count, listBase);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, first, count, listBase);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglUseFontBitmapsW(WindowsHDC hDC, WindowsDWord first, WindowsDWord count, WindowsDWord listBase) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglUseFontBitmapsW(hDC, first, count, listBase);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, first, count, listBase);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglUseFontOutlines(WindowsHDC hDC, WindowsDWord first, WindowsDWord count, WindowsDWord listBase, float deviation, float extrusion, int format, GlyphMetricsFloatPtr lpgmf) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglUseFontOutlines(hDC, first, count, listBase, deviation, extrusion, format, lpgmf);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, first, count, listBase, deviation, extrusion, format, lpgmf);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglUseFontOutlinesA(WindowsHDC hDC, WindowsDWord first, WindowsDWord count, WindowsDWord listBase, float deviation, float extrusion, int format, GlyphMetricsFloatPtr lpgmf) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::wglUseFontOutlinesA(hDC, first, count, listBase, deviation, extrusion, format, lpgmf);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hDC, first, count, listBase, deviation, extrusion, format, lpgmf);

    return gFalse;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsBool System::WglUseFontOutlinesW(WindowsHDC hDC, WindowsDWord first, WindowsDWord count, WindowsDWord listBase, float deviation, float extrusion, int format, GlyphMetricsFloatPtr lpgmf) noexcept
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

    PFNWGLCREATEBUFFERREGIONARBPROC wglCreateBufferRegionARB{ nullptr };
    PFNWGLDELETEBUFFERREGIONARBPROC wglDeleteBufferRegionARB{ nullptr };
    PFNWGLSAVEBUFFERREGIONARBPROC wglSaveBufferRegionARB{ nullptr };
    PFNWGLRESTOREBUFFERREGIONARBPROC wglRestoreBufferRegionARB{ nullptr };
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

    g_ExistsWglArbBufferRegion = ExistsOpenGLExtensions::NotExist;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHandle System::WglCreateBufferRegionARB(WindowsHDC hDC, int iLayerPlane, WindowsUInt uType) noexcept
{
    SYSTEM_BODY_3_RESULT(wglCreateBufferRegionARB, hDC, iLayerPlane, uType, nullptr);
}

void System::WglDeleteBufferRegionARB(WindowsHandle hRegion) noexcept
{
    SYSTEM_BODY_1(wglDeleteBufferRegionARB, hRegion);
}

System::WindowsBool System::WglSaveBufferRegionARB(WindowsHandle hRegion, int x, int y, int width, int height) noexcept
{
    SYSTEM_BODY_5_RESULT(wglSaveBufferRegionARB, hRegion, x, y, width, height, gFalse);
}

System::WindowsBool System::WglRestoreBufferRegionARB(WindowsHandle hRegion, int x, int y, int width, int height, int xSrc, int ySrc) noexcept
{
    SYSTEM_BODY_7_RESULT(wglRestoreBufferRegionARB, hRegion, x, y, width, height, xSrc, ySrc, gFalse);
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

    PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB{ nullptr };
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

System::OpenGLHglrc System::WglCreateContextAttribsARB(WindowsHDC hDC, OpenGLHglrc hShareContext, const int* attribList) noexcept
{
    SYSTEM_BODY_3_RESULT(wglCreateContextAttribsARB, hDC, hShareContext, attribList, nullptr);
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

    PFNWGLGETEXTENSIONSSTRINGARBPROC wglGetExtensionsStringARB{ nullptr };
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

const char* System::WglGetExtensionsStringARB(WindowsHDC hdc) noexcept
{
    SYSTEM_BODY_1_RESULT(wglGetExtensionsStringARB, hdc, "");
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

    PFNWGLMAKECONTEXTCURRENTARBPROC wglMakeContextCurrentARB{ nullptr };
    PFNWGLGETCURRENTREADDCARBPROC wglGetCurrentReadDCARB{ nullptr };
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

System::WindowsBool System::WglMakeContextCurrentARB(WindowsHDC hDrawDC, WindowsHDC hReadDC, OpenGLHglrc hglrc) noexcept
{
    SYSTEM_BODY_3_RESULT(wglMakeContextCurrentARB, hDrawDC, hReadDC, hglrc, gFalse);
}

System::WindowsHDC System::WglGetCurrentReadDCARB() noexcept
{
    SYSTEM_BODY_0_RESULT(wglGetCurrentReadDCARB, nullptr);
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

    PFNWGLCREATEPBUFFERARBPROC wglCreatePbufferARB{ nullptr };
    PFNWGLGETPBUFFERDCARBPROC wglGetPbufferDCARB{ nullptr };
    PFNWGLRELEASEPBUFFERDCARBPROC wglReleasePbufferDCARB{ nullptr };
    PFNWGLDESTROYPBUFFERARBPROC wglDestroyPbufferARB{ nullptr };
    PFNWGLQUERYPBUFFERARBPROC wglQueryPbufferARB{ nullptr };
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

System::WglHPBufferARB System::WglCreatePbufferARB(WindowsHDC hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList) noexcept
{
    SYSTEM_BODY_5_RESULT(wglCreatePbufferARB, hDC, iPixelFormat, iWidth, iHeight, piAttribList, nullptr);
}

System::WindowsHDC System::WglGetPbufferDCARB(WglHPBufferARB hPbuffer) noexcept
{
    SYSTEM_BODY_1_RESULT(wglGetPbufferDCARB, hPbuffer, nullptr);
}

int System::WglReleasePbufferDCARB(WglHPBufferARB hPbuffer, WindowsHDC hDC) noexcept
{
    SYSTEM_BODY_2_RESULT(wglReleasePbufferDCARB, hPbuffer, hDC, 0);
}

System::WindowsBool System::WglDestroyPbufferARB(WglHPBufferARB hPbuffer) noexcept
{
    SYSTEM_BODY_1_RESULT(wglDestroyPbufferARB, hPbuffer, gFalse);
}

System::WindowsBool System::WglQueryPbufferARB(WglHPBufferARB hPbuffer, int iAttribute, int* piValue) noexcept
{
    SYSTEM_BODY_3_RESULT(wglQueryPbufferARB, hPbuffer, iAttribute, piValue, gFalse);
}

// WGL_ARB_pixel_format

namespace System
{
    auto existsWglArbPixelFormat = ExistsOpenGLExtensions::Unknown;

    PFNWGLGETPIXELFORMATATTRIBIVARBPROC wglGetPixelFormatAttribivARB{ nullptr };
    PFNWGLGETPIXELFORMATATTRIBFVARBPROC wglGetPixelFormatAttribfvARB{ nullptr };
    PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB{ nullptr };
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

System::WindowsBool System::WglGetPixelFormatAttribivARB(WindowsHDC hdc, int iPixelFormat, int iLayerPlane, WindowsUInt nAttributes, const int* piAttributes, int* piValues) noexcept
{
    SYSTEM_BODY_6_RESULT(wglGetPixelFormatAttribivARB, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues, gFalse);
}

System::WindowsBool System::WglGetPixelFormatAttribfvARB(WindowsHDC hdc, int iPixelFormat, int iLayerPlane, WindowsUInt nAttributes, const int* piAttributes, float* pfValues) noexcept
{
    SYSTEM_BODY_6_RESULT(wglGetPixelFormatAttribfvARB, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues, gFalse);
}

System::WindowsBool System::WglChoosePixelFormatARB(WindowsHDC hdc, const int* piAttribIList, const float* pfAttribFList, WindowsUInt nMaxFormats, int* piFormats, WindowsUInt* nNumFormats) noexcept
{
    SYSTEM_BODY_6_RESULT(wglChoosePixelFormatARB, hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats, gFalse);
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

    PFNWGLBINDTEXIMAGEARBPROC wglBindTexImageARB{ nullptr };
    PFNWGLRELEASETEXIMAGEARBPROC wglReleaseTexImageARB{ nullptr };
    PFNWGLSETPBUFFERATTRIBARBPROC wglSetPbufferAttribARB{ nullptr };
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

System::WindowsBool System::WglBindTexImageARB(WglHPBufferARB hPbuffer, int iBuffer) noexcept
{
    SYSTEM_BODY_2_RESULT(wglBindTexImageARB, hPbuffer, iBuffer, gFalse);
}

System::WindowsBool System::WglReleaseTexImageARB(WglHPBufferARB hPbuffer, int iBuffer) noexcept
{
    SYSTEM_BODY_2_RESULT(wglReleaseTexImageARB, hPbuffer, iBuffer, gFalse);
}

System::WindowsBool System::WglSetPbufferAttribARB(WglHPBufferARB hPbuffer, const int* piAttribList) noexcept
{
    SYSTEM_BODY_2_RESULT(wglSetPbufferAttribARB, hPbuffer, piAttribList, gFalse);
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

    PFNWGLSETSTEREOEMITTERSTATE3DLPROC wglSetStereoEmitterState3DL{ nullptr };
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

System::WindowsBool System::WglSetStereoEmitterState3DL(WindowsHDC hDC, WindowsUInt uState) noexcept
{
    SYSTEM_BODY_2_RESULT(wglSetStereoEmitterState3DL, hDC, uState, gFalse);
}

// AMD 扩展

// WGL_AMD_gpu_association

namespace System
{
    auto existsWglAMDGpuAssociation = ExistsOpenGLExtensions::Unknown;

    PFNWGLGETGPUIDSAMDPROC wglGetGPUIDsAMD{ nullptr };
    PFNWGLGETGPUINFOAMDPROC wglGetGPUInfoAMD{ nullptr };
    PFNWGLGETCONTEXTGPUIDAMDPROC wglGetContextGPUIDAMD{ nullptr };
    PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC wglCreateAssociatedContextAMD{ nullptr };
    PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC wglCreateAssociatedContextAttribsAMD{ nullptr };
    PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC wglDeleteAssociatedContextAMD{ nullptr };
    PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC wglMakeAssociatedContextCurrentAMD{ nullptr };
    PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC wglGetCurrentAssociatedContextAMD{ nullptr };
    PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC wglBlitContextFramebufferAMD{ nullptr };
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
    SYSTEM_BODY_2_RESULT(wglGetGPUIDsAMD, maxCount, ids, 0u);
}

System::WindowsInt System::WglGetGPUInfoAMD(WindowsUInt id, WindowsInt property, GLenum dataType, WindowsUInt size, void* data) noexcept
{
    SYSTEM_BODY_5_RESULT(wglGetGPUInfoAMD, id, property, dataType, size, data, 0);
}

System::WindowsUInt System::WglGetContextGPUIDAMD(OpenGLHglrc hglrc) noexcept
{
    SYSTEM_BODY_1_RESULT(wglGetContextGPUIDAMD, hglrc, 0u);
}

System::OpenGLHglrc System::WglCreateAssociatedContextAMD(WindowsUInt id) noexcept
{
    SYSTEM_BODY_1_RESULT(wglCreateAssociatedContextAMD, id, nullptr);
}

System::OpenGLHglrc System::WglCreateAssociatedContextAttribsAMD(WindowsUInt id, OpenGLHglrc hShareContext, const int* attribList) noexcept
{
    SYSTEM_BODY_3_RESULT(wglCreateAssociatedContextAttribsAMD, id, hShareContext, attribList, nullptr);
}

System::WindowsBool System::WglDeleteAssociatedContextAMD(OpenGLHglrc hglrc) noexcept
{
    SYSTEM_BODY_1_RESULT(wglDeleteAssociatedContextAMD, hglrc, gFalse);
}

System::WindowsBool System::WglMakeAssociatedContextCurrentAMD(OpenGLHglrc hglrc) noexcept
{
    SYSTEM_BODY_1_RESULT(wglMakeAssociatedContextCurrentAMD, hglrc, gFalse);
}

System::OpenGLHglrc System::WglGetCurrentAssociatedContextAMD() noexcept
{
    SYSTEM_BODY_0_RESULT(wglGetCurrentAssociatedContextAMD, nullptr);
}

void System::WglBlitContextFramebufferAMD(OpenGLHglrc dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) noexcept
{
    SYSTEM_BODY_11(wglBlitContextFramebufferAMD, dstCtx, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
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

    PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC wglCreateDisplayColorTableEXT{ nullptr };
    PFNWGLLOADDISPLAYCOLORTABLEEXTPROC wglLoadDisplayColorTableEXT{ nullptr };
    PFNWGLBINDDISPLAYCOLORTABLEEXTPROC wglBindDisplayColorTableEXT{ nullptr };
    PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC wglDestroyDisplayColorTableEXT{ nullptr };
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
    SYSTEM_BODY_1_RESULT(wglCreateDisplayColorTableEXT, id, gFalse);
}

GLboolean System::WglLoadDisplayColorTableEXT(const GLushort* table, GLuint length) noexcept
{
    SYSTEM_BODY_2_RESULT(wglLoadDisplayColorTableEXT, table, length, gFalse);
}

GLboolean System::WglBindDisplayColorTableEXT(GLushort id) noexcept
{
    SYSTEM_BODY_1_RESULT(wglBindDisplayColorTableEXT, id, gFalse);
}

void System::WglDestroyDisplayColorTableEXT(GLushort id) noexcept
{
    SYSTEM_BODY_1(wglBindDisplayColorTableEXT, id);
}

// WGL_EXT_extensions_string

namespace System
{
    auto existsWglExtExtensionsString = ExistsOpenGLExtensions::Unknown;

    PFNWGLGETEXTENSIONSSTRINGEXTPROC wglGetExtensionsStringEXT{ nullptr };
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
    SYSTEM_BODY_0_RESULT(wglGetExtensionsStringEXT, "");
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

    PFNWGLMAKECONTEXTCURRENTEXTPROC wglMakeContextCurrentEXT{ nullptr };
    PFNWGLGETCURRENTREADDCEXTPROC wglGetCurrentReadDCEXT{ nullptr };
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

System::WindowsBool System::WglMakeContextCurrentEXT(WindowsHDC hDrawDC, WindowsHDC hReadDC, OpenGLHglrc hglrc) noexcept
{
    SYSTEM_BODY_3_RESULT(wglMakeContextCurrentEXT, hDrawDC, hReadDC, hglrc, gFalse);
}

System::WindowsHDC System::WglGetCurrentReadDCEXT() noexcept
{
    SYSTEM_BODY_0_RESULT(wglGetCurrentReadDCEXT, nullptr);
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

    PFNWGLCREATEPBUFFEREXTPROC wglCreatePbufferEXT{ nullptr };
    PFNWGLGETPBUFFERDCEXTPROC wglGetPbufferDCEXT{ nullptr };
    PFNWGLRELEASEPBUFFERDCEXTPROC wglReleasePbufferDCEXT{ nullptr };
    PFNWGLDESTROYPBUFFEREXTPROC wglDestroyPbufferEXT{ nullptr };
    PFNWGLQUERYPBUFFEREXTPROC wglQueryPbufferEXT{ nullptr };
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

System::WglHPBufferEXT System::WglCreatePbufferEXT(WindowsHDC hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList) noexcept
{
    SYSTEM_BODY_5_RESULT(wglCreatePbufferEXT, hDC, iPixelFormat, iWidth, iHeight, piAttribList, nullptr);
}

System::WindowsHDC System::WglGetPbufferDCEXT(WglHPBufferEXT hPbuffer) noexcept
{
    SYSTEM_BODY_1_RESULT(wglGetPbufferDCEXT, hPbuffer, nullptr);
}

int System::WglReleasePbufferDCEXT(WglHPBufferEXT hPbuffer, WindowsHDC hDC) noexcept
{
    SYSTEM_BODY_2_RESULT(wglReleasePbufferDCEXT, hPbuffer, hDC, 0);
}

System::WindowsBool System::WglDestroyPbufferEXT(WglHPBufferEXT hPbuffer) noexcept
{
    SYSTEM_BODY_1_RESULT(wglDestroyPbufferEXT, hPbuffer, gFalse);
}

System::WindowsBool System::WglQueryPbufferEXT(WglHPBufferEXT hPbuffer, int iAttribute, int* piValue) noexcept
{
    SYSTEM_BODY_3_RESULT(wglQueryPbufferEXT, hPbuffer, iAttribute, piValue, gFalse);
}

// WGL_EXT_pixel_format

namespace System
{
    auto existsWglExtPixelFormat = ExistsOpenGLExtensions::Unknown;

    PFNWGLGETPIXELFORMATATTRIBIVEXTPROC wglGetPixelFormatAttribivEXT{ nullptr };
    PFNWGLGETPIXELFORMATATTRIBFVEXTPROC wglGetPixelFormatAttribfvEXT{ nullptr };
    PFNWGLCHOOSEPIXELFORMATEXTPROC wglChoosePixelFormatEXT{ nullptr };
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

System::WindowsBool System::WglGetPixelFormatAttribivEXT(WindowsHDC hdc, int iPixelFormat, int iLayerPlane, WindowsUInt nAttributes, int* piAttributes, int* piValues) noexcept
{
    SYSTEM_BODY_6_RESULT(wglGetPixelFormatAttribivEXT, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues, gFalse);
}

System::WindowsBool System::WglGetPixelFormatAttribfvEXT(WindowsHDC hdc, int iPixelFormat, int iLayerPlane, WindowsUInt nAttributes, int* piAttributes, float* pfValues) noexcept
{
    SYSTEM_BODY_6_RESULT(wglGetPixelFormatAttribfvEXT, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues, gFalse);
}

System::WindowsBool System::WglChoosePixelFormatEXT(WindowsHDC hdc, const int* piAttribIList, const float* pfAttribFList, WindowsUInt nMaxFormats, int* piFormats, WindowsUInt* nNumFormats) noexcept
{
    SYSTEM_BODY_6_RESULT(wglChoosePixelFormatEXT, hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats, gFalse);
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

    PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT{ nullptr };
    PFNWGLGETSWAPINTERVALEXTPROC wglGetSwapIntervalEXT{ nullptr };
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
    SYSTEM_BODY_1_RESULT(wglSwapIntervalEXT, interval, gFalse);
}

int System::WglGetSwapIntervalEXT() noexcept
{
    SYSTEM_BODY_0_RESULT(wglGetSwapIntervalEXT, 0);
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

    PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC wglGetDigitalVideoParametersI3D{ nullptr };
    PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC wglSetDigitalVideoParametersI3D{ nullptr };
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

System::WindowsBool System::WglGetDigitalVideoParametersI3D(WindowsHDC hDC, int iAttribute, int* piValue) noexcept
{
    SYSTEM_BODY_3_RESULT(wglGetDigitalVideoParametersI3D, hDC, iAttribute, piValue, gFalse);
}

System::WindowsBool System::WglSetDigitalVideoParametersI3D(WindowsHDC hDC, int iAttribute, const int* piValue) noexcept
{
    SYSTEM_BODY_3_RESULT(wglSetDigitalVideoParametersI3D, hDC, iAttribute, piValue, gFalse);
}

// WGL_I3D_gamma

namespace System
{
    auto existsWglI3DGamma = ExistsOpenGLExtensions::Unknown;

    PFNWGLGETGAMMATABLEPARAMETERSI3DPROC wglGetGammaTableParametersI3D{ nullptr };
    PFNWGLSETGAMMATABLEPARAMETERSI3DPROC wglSetGammaTableParametersI3D{ nullptr };
    PFNWGLGETGAMMATABLEI3DPROC wglGetGammaTableI3D{ nullptr };
    PFNWGLSETGAMMATABLEI3DPROC wglSetGammaTableI3D{ nullptr };
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

System::WindowsBool System::WglGetGammaTableParametersI3D(WindowsHDC hDC, int iAttribute, int* piValue) noexcept
{
    SYSTEM_BODY_3_RESULT(wglGetGammaTableParametersI3D, hDC, iAttribute, piValue, gFalse);
}

System::WindowsBool System::WglSetGammaTableParametersI3D(WindowsHDC hDC, int iAttribute, const int* piValue) noexcept
{
    SYSTEM_BODY_3_RESULT(wglSetGammaTableParametersI3D, hDC, iAttribute, piValue, gFalse);
}

System::WindowsBool System::WglGetGammaTableI3D(WindowsHDC hDC, int iEntries, WindowsUShort* puRed, WindowsUShort* puGreen, WindowsUShort* puBlue) noexcept
{
    SYSTEM_BODY_5_RESULT(wglGetGammaTableI3D, hDC, iEntries, puRed, puGreen, puBlue, gFalse);
}

System::WindowsBool System::WglSetGammaTableI3D(WindowsHDC hDC, int iEntries, const WindowsUShort* puRed, const WindowsUShort* puGreen, const WindowsUShort* puBlue) noexcept
{
    SYSTEM_BODY_5_RESULT(wglSetGammaTableI3D, hDC, iEntries, puRed, puGreen, puBlue, gFalse);
}

// WGL_I3D_genlock

namespace System
{
    auto existsWglI3DGenlock = ExistsOpenGLExtensions::Unknown;

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

System::WindowsBool System::WglEnableGenlockI3D(WindowsHDC hDC) noexcept
{
    SYSTEM_BODY_1_RESULT(wglEnableGenlockI3D, hDC, gFalse);
}

System::WindowsBool System::WglDisableGenlockI3D(WindowsHDC hDC) noexcept
{
    SYSTEM_BODY_1_RESULT(wglDisableGenlockI3D, hDC, gFalse);
}

System::WindowsBool System::WglIsEnabledGenlockI3D(WindowsHDC hDC, WindowsBool* pFlag) noexcept
{
    SYSTEM_BODY_2_RESULT(wglIsEnabledGenlockI3D, hDC, pFlag, gFalse);
}

System::WindowsBool System::WglGenlockSourceI3D(WindowsHDC hDC, WindowsUInt uSource) noexcept
{
    SYSTEM_BODY_2_RESULT(wglGenlockSourceI3D, hDC, uSource, gFalse);
}

System::WindowsBool System::WglGetGenlockSourceI3D(WindowsHDC hDC, WindowsUInt* uSource) noexcept
{
    SYSTEM_BODY_2_RESULT(wglGetGenlockSourceI3D, hDC, uSource, gFalse);
}

System::WindowsBool System::WglGenlockSourceEdgeI3D(WindowsHDC hDC, WindowsUInt uEdge) noexcept
{
    SYSTEM_BODY_2_RESULT(wglGenlockSourceEdgeI3D, hDC, uEdge, gFalse);
}

System::WindowsBool System::WglGetGenlockSourceEdgeI3D(WindowsHDC hDC, WindowsUInt* uEdge) noexcept
{
    SYSTEM_BODY_2_RESULT(wglGetGenlockSourceEdgeI3D, hDC, uEdge, gFalse);
}

System::WindowsBool System::WglGenlockSampleRateI3D(WindowsHDC hDC, WindowsUInt uRate) noexcept
{
    SYSTEM_BODY_2_RESULT(wglGenlockSampleRateI3D, hDC, uRate, gFalse);
}

System::WindowsBool System::WglGetGenlockSampleRateI3D(WindowsHDC hDC, WindowsUInt* uRate) noexcept
{
    SYSTEM_BODY_2_RESULT(wglGetGenlockSampleRateI3D, hDC, uRate, gFalse);
}

System::WindowsBool System::WglGenlockSourceDelayI3D(WindowsHDC hDC, WindowsUInt uDelay) noexcept
{
    SYSTEM_BODY_2_RESULT(wglGenlockSourceDelayI3D, hDC, uDelay, gFalse);
}

System::WindowsBool System::WglGetGenlockSourceDelayI3D(WindowsHDC hDC, WindowsUInt* uDelay) noexcept
{
    SYSTEM_BODY_2_RESULT(wglGetGenlockSourceDelayI3D, hDC, uDelay, gFalse);
}

System::WindowsBool System::WglQueryGenlockMaxSourceDelayI3D(WindowsHDC hDC, WindowsUInt* uMaxLineDelay, WindowsUInt* uMaxPixelDelay) noexcept
{
    SYSTEM_BODY_3_RESULT(wglQueryGenlockMaxSourceDelayI3D, hDC, uMaxLineDelay, uMaxPixelDelay, gFalse);
}

// WGL_I3D_image_buffer

namespace System
{
    auto existsWglI3DImageBuffer = ExistsOpenGLExtensions::Unknown;

    PFNWGLCREATEIMAGEBUFFERI3DPROC wglCreateImageBufferI3D{ nullptr };
    PFNWGLDESTROYIMAGEBUFFERI3DPROC wglDestroyImageBufferI3D{ nullptr };
    PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC wglAssociateImageBufferEventsI3D{ nullptr };
    PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC wglReleaseImageBufferEventsI3D{ nullptr };
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

System::WindowsVoidPtr System::WglCreateImageBufferI3D(WindowsHDC hDC, WindowsDWord dwSize, WindowsUInt uFlags) noexcept
{
    SYSTEM_BODY_3_RESULT(wglCreateImageBufferI3D, hDC, dwSize, uFlags, nullptr);
}

System::WindowsBool System::WglDestroyImageBufferI3D(WindowsHDC hDC, WindowsVoidPtr pAddress) noexcept
{
    SYSTEM_BODY_2_RESULT(wglDestroyImageBufferI3D, hDC, pAddress, gFalse);
}

System::WindowsBool System::WglAssociateImageBufferEventsI3D(WindowsHDC hDC, const WindowsHandle* pEvent, const WindowsVoidPtr* pAddress, const WindowsDWord* pSize, WindowsUInt count) noexcept
{
    SYSTEM_BODY_5_RESULT(wglAssociateImageBufferEventsI3D, hDC, pEvent, pAddress, pSize, count, gFalse);
}

System::WindowsBool System::WglReleaseImageBufferEventsI3D(WindowsHDC hDC, const WindowsVoidPtr* pAddress, WindowsUInt count) noexcept
{
    SYSTEM_BODY_3_RESULT(wglReleaseImageBufferEventsI3D, hDC, pAddress, count, gFalse);
}

// WGL_I3D_swap_frame_lock

namespace System
{
    auto existsWglI3DSwapFrameLock = ExistsOpenGLExtensions::Unknown;

    PFNWGLENABLEFRAMELOCKI3DPROC wglEnableFrameLockI3D{ nullptr };
    PFNWGLDISABLEFRAMELOCKI3DPROC wglDisableFrameLockI3D{ nullptr };
    PFNWGLISENABLEDFRAMELOCKI3DPROC wglIsEnabledFrameLockI3D{ nullptr };
    PFNWGLQUERYFRAMELOCKMASTERI3DPROC wglQueryFrameLockMasterI3D{ nullptr };
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
    SYSTEM_BODY_0_RESULT(wglEnableFrameLockI3D, gFalse);
}

System::WindowsBool System::WglDisableFrameLockI3D() noexcept
{
    SYSTEM_BODY_0_RESULT(wglDisableFrameLockI3D, gFalse);
}

System::WindowsBool System::WglIsEnabledFrameLockI3D(WindowsBool* pFlag) noexcept
{
    SYSTEM_BODY_1_RESULT(wglIsEnabledFrameLockI3D, pFlag, gFalse);
}

System::WindowsBool System::WglQueryFrameLockMasterI3D(WindowsBool* pFlag) noexcept
{
    SYSTEM_BODY_1_RESULT(wglQueryFrameLockMasterI3D, pFlag, gFalse);
}

// WGL_I3D_swap_frame_usage

namespace System
{
    auto existsWglI3DSwapFrameUsage = ExistsOpenGLExtensions::Unknown;

    PFNWGLGETFRAMEUSAGEI3DPROC wglGetFrameUsageI3D{ nullptr };
    PFNWGLBEGINFRAMETRACKINGI3DPROC wglBeginFrameTrackingI3D{ nullptr };
    PFNWGLENDFRAMETRACKINGI3DPROC wglEndFrameTrackingI3D{ nullptr };
    PFNWGLQUERYFRAMETRACKINGI3DPROC wglQueryFrameTrackingI3D{ nullptr };
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
    SYSTEM_BODY_1_RESULT(wglGetFrameUsageI3D, pUsage, gFalse);
}

System::WindowsBool System::WglBeginFrameTrackingI3D() noexcept
{
    SYSTEM_BODY_0_RESULT(wglBeginFrameTrackingI3D, gFalse);
}

System::WindowsBool System::WglEndFrameTrackingI3D() noexcept
{
    SYSTEM_BODY_0_RESULT(wglEndFrameTrackingI3D, gFalse);
}

System::WindowsBool System::WglQueryFrameTrackingI3D(WindowsDWord* pFrameCount, WindowsDWord* pMissedFrames, float* pLastMissedUsage) noexcept
{
    SYSTEM_BODY_3_RESULT(wglQueryFrameTrackingI3D, pFrameCount, pMissedFrames, pLastMissedUsage, gFalse);
}

// NV 扩展

// WGL_NV_DX_interop

namespace System
{
    auto existsWglNVDXInterop = ExistsOpenGLExtensions::Unknown;

    PFNWGLDXSETRESOURCESHAREHANDLENVPROC wglDXSetResourceShareHandleNV{ nullptr };
    PFNWGLDXOPENDEVICENVPROC wglDXOpenDeviceNV{ nullptr };
    PFNWGLDXCLOSEDEVICENVPROC wglDXCloseDeviceNV{ nullptr };
    PFNWGLDXREGISTEROBJECTNVPROC wglDXRegisterObjectNV{ nullptr };
    PFNWGLDXUNREGISTEROBJECTNVPROC wglDXUnregisterObjectNV{ nullptr };
    PFNWGLDXOBJECTACCESSNVPROC wglDXObjectAccessNV{ nullptr };
    PFNWGLDXLOCKOBJECTSNVPROC wglDXLockObjectsNV{ nullptr };
    PFNWGLDXUNLOCKOBJECTSNVPROC wglDXUnlockObjectsNV{ nullptr };
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
    SYSTEM_BODY_2_RESULT(wglDXSetResourceShareHandleNV, dxObject, shareHandle, gFalse);
}

System::WindowsHandle System::WglDXOpenDeviceNV(void* dxDevice) noexcept
{
    SYSTEM_BODY_1_RESULT(wglDXOpenDeviceNV, dxDevice, nullptr);
}

System::WindowsBool System::WglDXCloseDeviceNV(WindowsHandle hDevice) noexcept
{
    SYSTEM_BODY_1_RESULT(wglDXCloseDeviceNV, hDevice, gFalse);
}

System::WindowsHandle System::WglDXRegisterObjectNV(WindowsHandle hDevice, void* dxObject, GLuint name, GLenum type, GLenum access) noexcept
{
    SYSTEM_BODY_5_RESULT(wglDXRegisterObjectNV, hDevice, dxObject, name, type, access, nullptr);
}

System::WindowsBool System::WglDXUnregisterObjectNV(WindowsHandle hDevice, WindowsHandle hObject) noexcept
{
    SYSTEM_BODY_2_RESULT(wglDXUnregisterObjectNV, hDevice, hObject, gFalse);
}

System::WindowsBool System::WglDXObjectAccessNV(WindowsHandle hObject, GLenum access) noexcept
{
    SYSTEM_BODY_2_RESULT(wglDXObjectAccessNV, hObject, access, gFalse);
}

System::WindowsBool System::WglDXLockObjectsNV(WindowsHandle hDevice, GLint count, WindowsHandle* hObjects) noexcept
{
    SYSTEM_BODY_3_RESULT(wglDXLockObjectsNV, hDevice, count, hObjects, gFalse);
}

System::WindowsBool System::WglDXUnlockObjectsNV(WindowsHandle hDevice, GLint count, WindowsHandle* hObjects) noexcept
{
    SYSTEM_BODY_3_RESULT(wglDXUnlockObjectsNV, hDevice, count, hObjects, gFalse);
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

    PFNWGLCOPYIMAGESUBDATANVPROC wglCopyImageSubDataNV{ nullptr };
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
    SYSTEM_BODY_17_RESULT(wglCopyImageSubDataNV, hSrcRC, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, hDstRC, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth, gFalse);
}

// WGL_NV_delay_before_swap

namespace System
{
    auto existsWglNVDelayBeforeSwap = ExistsOpenGLExtensions::Unknown;

    PFNWGLDELAYBEFORESWAPNVPROC wglDelayBeforeSwapNV{ nullptr };
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

System::WindowsBool System::WglDelayBeforeSwapNV(WindowsHDC hDC, GLfloat seconds) noexcept
{
    SYSTEM_BODY_2_RESULT(wglDelayBeforeSwapNV, hDC, seconds, gFalse);
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

    PFNWGLENUMGPUSNVPROC wglEnumGpusNV{ nullptr };
    PFNWGLENUMGPUDEVICESNVPROC wglEnumGpuDevicesNV{ nullptr };
    PFNWGLCREATEAFFINITYDCNVPROC wglCreateAffinityDCNV{ nullptr };
    PFNWGLENUMGPUSFROMAFFINITYDCNVPROC wglEnumGpusFromAffinityDCNV{ nullptr };
    PFNWGLDELETEDCNVPROC wglDeleteDCNV{ nullptr };
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

System::WindowsBool System::WglEnumGpusNV(WindowsUInt iGpuIndex, WglHGpuNV* phGpu) noexcept
{
    SYSTEM_BODY_2_RESULT(wglEnumGpusNV, iGpuIndex, phGpu, gFalse);
}

System::WindowsBool System::WglEnumGpuDevicesNV(WglHGpuNV hGpu, WindowsUInt iDeviceIndex, WglGpuDevicePtr lpGpuDevice) noexcept
{
    SYSTEM_BODY_3_RESULT(wglEnumGpuDevicesNV, hGpu, iDeviceIndex, lpGpuDevice, gFalse);
}

System::WindowsHDC System::WglCreateAffinityDCNV(const WglHGpuNV* phGpuList) noexcept
{
    SYSTEM_BODY_1_RESULT(wglCreateAffinityDCNV, phGpuList, nullptr);
}

System::WindowsBool System::WglEnumGpusFromAffinityDCNV(WindowsHDC hAffinityDC, WindowsUInt iGpuIndex, WglHGpuNV* hGpu) noexcept
{
    SYSTEM_BODY_3_RESULT(wglEnumGpusFromAffinityDCNV, hAffinityDC, iGpuIndex, hGpu, gFalse);
}

System::WindowsBool System::WglDeleteDCNV(WindowsHDC hdc) noexcept
{
    SYSTEM_BODY_1_RESULT(wglDeleteDCNV, hdc, gFalse);
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

    PFNWGLENUMERATEVIDEODEVICESNVPROC wglEnumerateVideoDevicesNV{ nullptr };
    PFNWGLBINDVIDEODEVICENVPROC wglBindVideoDeviceNV{ nullptr };
    PFNWGLQUERYCURRENTCONTEXTNVPROC wglQueryCurrentContextNV{ nullptr };
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

int System::WglEnumerateVideoDevicesNV(WindowsHDC hDc, WglHVideoOutputDeviceNV* phDeviceList) noexcept
{
    SYSTEM_BODY_2_RESULT(wglEnumerateVideoDevicesNV, hDc, phDeviceList, 0);
}

System::WindowsBool System::WglBindVideoDeviceNV(WindowsHDC hDc, unsigned int uVideoSlot, WglHVideoOutputDeviceNV hVideoDevice, const int* piAttribList) noexcept
{
    SYSTEM_BODY_4_RESULT(wglBindVideoDeviceNV, hDc, uVideoSlot, hVideoDevice, piAttribList, gFalse);
}

System::WindowsBool System::WglQueryCurrentContextNV(int iAttribute, int* piValue) noexcept
{
    SYSTEM_BODY_2_RESULT(wglQueryCurrentContextNV, iAttribute, piValue, gFalse);
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

    PFNWGLJOINSWAPGROUPNVPROC wglJoinSwapGroupNV{ nullptr };
    PFNWGLBINDSWAPBARRIERNVPROC wglBindSwapBarrierNV{ nullptr };
    PFNWGLQUERYSWAPGROUPNVPROC wglQuerySwapGroupNV{ nullptr };
    PFNWGLQUERYMAXSWAPGROUPSNVPROC wglQueryMaxSwapGroupsNV{ nullptr };
    PFNWGLQUERYFRAMECOUNTNVPROC wglQueryFrameCountNV{ nullptr };
    PFNWGLRESETFRAMECOUNTNVPROC wglResetFrameCountNV{ nullptr };
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

System::WindowsBool System::WglJoinSwapGroupNV(WindowsHDC hDC, GLuint group) noexcept
{
    SYSTEM_BODY_2_RESULT(wglJoinSwapGroupNV, hDC, group, gFalse);
}

System::WindowsBool System::WglBindSwapBarrierNV(GLuint group, GLuint barrier) noexcept
{
    SYSTEM_BODY_2_RESULT(wglBindSwapBarrierNV, group, barrier, gFalse);
}

System::WindowsBool System::WglQuerySwapGroupNV(WindowsHDC hDC, GLuint* group, GLuint* barrier) noexcept
{
    SYSTEM_BODY_3_RESULT(wglQuerySwapGroupNV, hDC, group, barrier, gFalse);
}

System::WindowsBool System::WglQueryMaxSwapGroupsNV(WindowsHDC hDC, GLuint* maxGroups, GLuint* maxBarriers) noexcept
{
    SYSTEM_BODY_3_RESULT(wglQueryMaxSwapGroupsNV, hDC, maxGroups, maxBarriers, gFalse);
}

System::WindowsBool System::WglQueryFrameCountNV(WindowsHDC hDC, GLuint* count) noexcept
{
    SYSTEM_BODY_2_RESULT(wglQueryFrameCountNV, hDC, count, gFalse);
}

System::WindowsBool System::WglResetFrameCountNV(WindowsHDC hDC) noexcept
{
    SYSTEM_BODY_1_RESULT(wglResetFrameCountNV, hDC, gFalse);
}

// WGL_NV_vertex_array_range

namespace System
{
    auto existsWglNVVertexArrayRange = ExistsOpenGLExtensions::Unknown;

    PFNWGLALLOCATEMEMORYNVPROC wglAllocateMemoryNV{ nullptr };
    PFNWGLFREEMEMORYNVPROC wglFreeMemoryNV{ nullptr };
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
    SYSTEM_BODY_4_RESULT(wglAllocateMemoryNV, size, readfreq, writefreq, priority, nullptr);
}

void System::WglFreeMemoryNV(void* pointer) noexcept
{
    SYSTEM_BODY_1(wglFreeMemoryNV, pointer);
}

// WGL_NV_video_capture

namespace System
{
    auto existsWglNVVideoCapture = ExistsOpenGLExtensions::Unknown;

    PFNWGLBINDVIDEOCAPTUREDEVICENVPROC wglBindVideoCaptureDeviceNV{ nullptr };
    PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC wglEnumerateVideoCaptureDevicesNV{ nullptr };
    PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC wglLockVideoCaptureDeviceNV{ nullptr };
    PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC wglQueryVideoCaptureDeviceNV{ nullptr };
    PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC wglReleaseVideoCaptureDeviceNV{ nullptr };
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

System::WindowsBool System::WglBindVideoCaptureDeviceNV(WindowsUInt uVideoSlot, WglHVideoInputDeviceNV hDevice) noexcept
{
    SYSTEM_BODY_2_RESULT(wglBindVideoCaptureDeviceNV, uVideoSlot, hDevice, gFalse);
}

System::WindowsUInt System::WglEnumerateVideoCaptureDevicesNV(WindowsHDC hDc, WglHVideoInputDeviceNV* phDeviceList) noexcept
{
    SYSTEM_BODY_2_RESULT(wglEnumerateVideoCaptureDevicesNV, hDc, phDeviceList, 0u);
}

System::WindowsBool System::WglLockVideoCaptureDeviceNV(WindowsHDC hDc, WglHVideoInputDeviceNV hDevice) noexcept
{
    SYSTEM_BODY_2_RESULT(wglLockVideoCaptureDeviceNV, hDc, hDevice, gFalse);
}

System::WindowsBool System::WglQueryVideoCaptureDeviceNV(WindowsHDC hDc, WglHVideoInputDeviceNV hDevice, int iAttribute, int* piValue) noexcept
{
    SYSTEM_BODY_4_RESULT(wglQueryVideoCaptureDeviceNV, hDc, hDevice, iAttribute, piValue, gFalse);
}

System::WindowsBool System::WglReleaseVideoCaptureDeviceNV(WindowsHDC hDc, WglHVideoInputDeviceNV hDevice) noexcept
{
    SYSTEM_BODY_2_RESULT(wglReleaseVideoCaptureDeviceNV, hDc, hDevice, gFalse);
}

// WGL_NV_video_output

namespace System
{
    auto existsWglNVVideoOutput = ExistsOpenGLExtensions::Unknown;

    PFNWGLGETVIDEODEVICENVPROC wglGetVideoDeviceNV{ nullptr };
    PFNWGLRELEASEVIDEODEVICENVPROC wglReleaseVideoDeviceNV{ nullptr };
    PFNWGLBINDVIDEOIMAGENVPROC wglBindVideoImageNV{ nullptr };
    PFNWGLRELEASEVIDEOIMAGENVPROC wglReleaseVideoImageNV{ nullptr };
    PFNWGLSENDPBUFFERTOVIDEONVPROC wglSendPbufferToVideoNV{ nullptr };
    PFNWGLGETVIDEOINFONVPROC wglGetVideoInfoNV{ nullptr };
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

System::WindowsBool System::WglGetVideoDeviceNV(WindowsHDC hDC, int numDevices, WglHPVideoDEV* hVideoDevice) noexcept
{
    SYSTEM_BODY_3_RESULT(wglGetVideoDeviceNV, hDC, numDevices, hVideoDevice, gFalse);
}

System::WindowsBool System::WglReleaseVideoDeviceNV(WglHPVideoDEV hVideoDevice) noexcept
{
    SYSTEM_BODY_1_RESULT(wglReleaseVideoDeviceNV, hVideoDevice, gFalse);
}

System::WindowsBool System::WglBindVideoImageNV(WglHPVideoDEV hVideoDevice, WglHPBufferARB hPbuffer, int iVideoBuffer) noexcept
{
    SYSTEM_BODY_3_RESULT(wglBindVideoImageNV, hVideoDevice, hPbuffer, iVideoBuffer, gFalse);
}

System::WindowsBool System::WglReleaseVideoImageNV(WglHPBufferARB hPbuffer, int iVideoBuffer) noexcept
{
    SYSTEM_BODY_2_RESULT(wglReleaseVideoImageNV, hPbuffer, iVideoBuffer, gFalse);
}

System::WindowsBool System::WglSendPbufferToVideoNV(WglHPBufferARB hPbuffer, int iBufferType, unsigned long* pulCounterPbuffer, WindowsBool bBlock) noexcept
{
    SYSTEM_BODY_4_RESULT(wglSendPbufferToVideoNV, hPbuffer, iBufferType, pulCounterPbuffer, bBlock, gFalse);
}

System::WindowsBool System::WglGetVideoInfoNV(WglHPVideoDEV hpVideoDevice, unsigned long* pulCounterOutputPbuffer, unsigned long* pulCounterOutputVideo) noexcept
{
    SYSTEM_BODY_3_RESULT(wglGetVideoInfoNV, hpVideoDevice, pulCounterOutputPbuffer, pulCounterOutputVideo, gFalse);
}

// OML 扩展

// WGL_OML_sync_control

namespace System
{
    auto existsWglOMLSyncControl = ExistsOpenGLExtensions::Unknown;

    PFNWGLGETSYNCVALUESOMLPROC wglGetSyncValuesOML{ nullptr };
    PFNWGLGETMSCRATEOMLPROC wglGetMscRateOML{ nullptr };
    PFNWGLSWAPBUFFERSMSCOMLPROC wglSwapBuffersMscOML{ nullptr };
    PFNWGLSWAPLAYERBUFFERSMSCOMLPROC wglSwapLayerBuffersMscOML{ nullptr };
    PFNWGLWAITFORMSCOMLPROC wglWaitForMscOML{ nullptr };
    PFNWGLWAITFORSBCOMLPROC wglWaitForSbcOML{ nullptr };
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

System::WindowsBool System::WglGetSyncValuesOML(WindowsHDC hdc, WindowsInt64* ust, WindowsInt64* msc, WindowsInt64* sbc) noexcept
{
    SYSTEM_BODY_4_RESULT(wglGetSyncValuesOML, hdc, ust, msc, sbc, gFalse);
}

System::WindowsBool System::WglGetMscRateOML(WindowsHDC hdc, WindowsInt32* numerator, WindowsInt32* denominator) noexcept
{
    SYSTEM_BODY_3_RESULT(wglGetMscRateOML, hdc, numerator, denominator, gFalse);
}

System::WindowsInt64 System::WglSwapBuffersMscOML(WindowsHDC hdc, WindowsInt64 target_msc, WindowsInt64 divisor, WindowsInt64 remainder) noexcept
{
    SYSTEM_BODY_4_RESULT(wglSwapBuffersMscOML, hdc, target_msc, divisor, remainder, 0);
}

System::WindowsInt64 System::WglSwapLayerBuffersMscOML(WindowsHDC hdc, INT fuPlanes, WindowsInt64 target_msc, WindowsInt64 divisor, WindowsInt64 remainder) noexcept
{
    SYSTEM_BODY_5_RESULT(wglSwapLayerBuffersMscOML, hdc, fuPlanes, target_msc, divisor, remainder, 0);
}

System::WindowsBool System::WglWaitForMscOML(WindowsHDC hdc, WindowsInt64 target_msc, WindowsInt64 divisor, WindowsInt64 remainder, WindowsInt64* ust, WindowsInt64* msc, WindowsInt64* sbc) noexcept
{
    SYSTEM_BODY_7_RESULT(wglWaitForMscOML, hdc, target_msc, divisor, remainder, ust, msc, sbc, gFalse);
}

System::WindowsBool System::WglWaitForSbcOML(WindowsHDC hdc, WindowsInt64 target_sbc, WindowsInt64* ust, WindowsInt64* msc, WindowsInt64* sbc) noexcept
{
    SYSTEM_BODY_5_RESULT(wglWaitForSbcOML, hdc, target_sbc, ust, msc, sbc, gFalse);
}

bool System::InitWGL()
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

    auto wglExtensionString = GetWglExtensionString();
    if (wglExtensionString == nullptr)
    {
        return false;
    }

    string extension{ wglExtensionString };

    const auto pos = extension.find(wglExtension);

    if (pos == string::npos)
    {
        return false;
    }

    const auto endPos = pos + Strlen(wglExtension);

    if (extension.size() <= endPos)
    {
        return true;
    }

    auto end = extension.at(endPos);

    // 扩展被发现,但确保它不是另一个扩展的合适子串。
    return end == ' ' || end == 0 || end == '\t' || end == '\n';
}
