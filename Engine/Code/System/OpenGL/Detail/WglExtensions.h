//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 15:41)

#ifndef SYSTEM_OPENGL_WGL_EXTENSIONS_H
#define SYSTEM_OPENGL_WGL_EXTENSIONS_H

#include "System/Helper/Detail/OpenGL/WglExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/GL11ExtensionsUsing.h"
#include "System/OpenGL/Using/WglExtensionsUsing.h"

namespace System
{
    // ARB 扩展

    // (ARB 04) WGL_ARB_buffer_region

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbBufferRegion() noexcept;

    HANDLE WglCreateBufferRegionARB(WglHDC hdc, int layerPlane, WglUInt type) noexcept;
    SYSTEM_HIDDEN_DECLARE void WglDeleteBufferRegionARB(WglHandle region) noexcept;
    SYSTEM_HIDDEN_DECLARE WglBool WglSaveBufferRegionARB(WglHandle region, int x, int y, int width, int height) noexcept;
    SYSTEM_HIDDEN_DECLARE WglBool WglRestoreBufferRegionARB(WglHandle region, int x, int y, int width, int height, int xSrc, int ySrc) noexcept;

    // (ARB 05) WGL_ARB_multisample

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbMultisample() noexcept;

    // (ARB 08) WGL_ARB_extensions_string

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbExtensionsString() noexcept;

    SYSTEM_HIDDEN_DECLARE const char* WglGetExtensionsStringARB(WglHDC hdc) noexcept;

    // (ARB 09) WGL_ARB_pixel_format

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbPixelFormat() noexcept;

    SYSTEM_HIDDEN_DECLARE WglBool WglGetPixelFormatAttribivARB(WglHDC hdc, int pixelFormat, int layerPlane, WglUInt numAttributes, const int* attribute, int* value) noexcept;
    SYSTEM_HIDDEN_DECLARE WglBool WglGetPixelFormatAttribfvARB(WglHDC hdc, int pixelFormat, int layerPlane, WglUInt numAttributes, const int* attribute, WglFloat* value) noexcept;

    SYSTEM_HIDDEN_DECLARE WglBool WglChoosePixelFormatARB(WglHDC hdc, const int* attribIList, const WglFloat* attribFList, WglUInt maxFormats, int* format, WglUInt* numFormats) noexcept;

    // (ARB 10) WGL_ARB_make_current_read

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbMakeCurrentRead() noexcept;

    SYSTEM_HIDDEN_DECLARE WglBool WglMakeContextCurrentARB(WglHDC drawDC, WglHDC readDC, WglHGLRC windowRC) noexcept;
    SYSTEM_HIDDEN_DECLARE WglHDC WglGetCurrentReadDCARB() noexcept;

    // (ARB 11) WGL_ARB_pbuffer

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbPBuffer() noexcept;

    SYSTEM_HIDDEN_DECLARE WglHPBufferARB WglCreatePbufferARB(WglHDC hdc, int pixelFormat, int width, int height, const int* attribList) noexcept;
    SYSTEM_HIDDEN_DECLARE WglHDC WglGetPbufferDCARB(WglHPBufferARB buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE int WglReleasePbufferDCARB(WglHPBufferARB buffer, WglHDC hdc) noexcept;
    SYSTEM_HIDDEN_DECLARE WglBool WglDestroyPbufferARB(WglHPBufferARB buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE WglBool WglQueryPbufferARB(WglHPBufferARB buffer, int attribute, int* value) noexcept;

    // (ARB 20) WGL_ARB_render_texture

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbRenderTexture() noexcept;

    SYSTEM_HIDDEN_DECLARE WglBool WglBindTexImageARB(WglHPBufferARB buffer, int bufferIndex) noexcept;
    SYSTEM_HIDDEN_DECLARE WglBool WglReleaseTexImageARB(WglHPBufferARB buffer, int bufferIndex) noexcept;
    SYSTEM_HIDDEN_DECLARE WglBool WglSetPbufferAttribARB(WglHPBufferARB buffer, const int* attribList) noexcept;

    // (ARB 39) WGL_ARB_pixel_format_float

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbPixelFormatFloat() noexcept;

    // (ARB 46) WGL_ARB_framebuffer_sRGB
    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbFramebufferSRGB() noexcept;

    // (ARB 55) WGL_ARB_create_context

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbCreateContext() noexcept;

    SYSTEM_HIDDEN_DECLARE WglHGLRC WglCreateContextAttribsARB(WglHDC hdc, WglHGLRC shareContext, const int* attribList) noexcept;

    // (ARB 74) WGL_ARB_create_context_profile

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbCreateContextProfile() noexcept;

    // (ARB 102) WGL_ARB_create_context_robustness

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbCreateContextRobustness() noexcept;

    // (ARB 143) WGL_ARB_robustness_application_isolation

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbRobustnessApplicationIsolation() noexcept;

    // (ARB 143) WGL_ARB_robustness_share_group_isolation

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbRobustnessShareGroupIsolation() noexcept;

    // (ARB 168) WGL_ARB_context_flush_control

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbContextFlushControl() noexcept;

    // EXT 扩展

    // (EXT 167) WGL_EXT_display_color_table

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtDisplayColorTable() noexcept;

    SYSTEM_HIDDEN_DECLARE GLboolean WglCreateDisplayColorTableEXT(GLushort id) noexcept;
    SYSTEM_HIDDEN_DECLARE GLboolean WglLoadDisplayColorTableEXT(const GLushort* table, GLuint length) noexcept;
    SYSTEM_HIDDEN_DECLARE GLboolean WglBindDisplayColorTableEXT(GLushort id) noexcept;
    SYSTEM_HIDDEN_DECLARE void WglDestroyDisplayColorTableEXT(GLushort id) noexcept;

    // (EXT 168) WGL_EXT_extensions_string

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtExtensionsString() noexcept;

    SYSTEM_HIDDEN_DECLARE const char* WglGetExtensionsStringEXT() noexcept;

    // (EXT 169) WGL_EXT_make_current_read

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtMakeCurrentRead() noexcept;

    SYSTEM_HIDDEN_DECLARE WglBool WglMakeContextCurrentEXT(WglHDC drawDC, WglHDC readDC, WglHGLRC windowRC) noexcept;
    SYSTEM_HIDDEN_DECLARE WglHDC WglGetCurrentReadDCEXT() noexcept;

    // (EXT 170) WGL_EXT_pixel_format

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtPixelFormat() noexcept;

    SYSTEM_HIDDEN_DECLARE WglBool WglGetPixelFormatAttribivEXT(WglHDC hdc, int pixelFormat, int layerPlane, WglUInt numAttributes, const int* attribute, int* value) noexcept;
    SYSTEM_HIDDEN_DECLARE WglBool WglGetPixelFormatAttribfvEXT(WglHDC hdc, int pixelFormat, int layerPlane, WglUInt numAttributes, const int* attribute, WglFloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE WglBool WglChoosePixelFormatEXT(WglHDC hdc, const int* attribIList, const WglFloat* attribFList, WglUInt maxFormats, int* format, WglUInt* numFormats) noexcept;

    // (EXT 171) WGL_EXT_pbuffer

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtPBuffer() noexcept;

    SYSTEM_HIDDEN_DECLARE WglHPBufferEXT WglCreatePbufferEXT(WglHDC hdc, int pixelFormat, int width, int height, const int* attribList) noexcept;
    SYSTEM_HIDDEN_DECLARE WglHDC WglGetPbufferDCEXT(WglHPBufferEXT buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE int WglReleasePbufferDCEXT(WglHPBufferEXT buffer, WglHDC hdc) noexcept;
    SYSTEM_HIDDEN_DECLARE WglBool WglDestroyPbufferEXT(WglHPBufferEXT buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE WglBool WglQueryPbufferEXT(WglHPBufferEXT buffer, int attribute, int* value) noexcept;

    // (EXT 172) WGL_EXT_swap_control

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtSwapControl() noexcept;

    SYSTEM_HIDDEN_DECLARE WglBool WglSwapIntervalEXT(int iInterval) noexcept;
    SYSTEM_HIDDEN_DECLARE int WglGetSwapIntervalEXT() noexcept;

    // (EXT 177) WGL_EXT_depth_float

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtDepthFloat() noexcept;

    // (EXT 209) WGL_EXT_multisample

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtMultisample() noexcept;

    // (EXT 328) WGL_EXT_pixel_format_packed_float

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtPixelFormatPackedFloat() noexcept;

    // (EXT 337) WGL_EXT_framebuffer_sRGB

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtFramebufferSRGB() noexcept;

    // (EXT 400) WGL_EXT_create_context_es2_profile

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtCreateContextEs2Profile() noexcept;

    // (EXT 400) WGL_EXT_create_context_es_profile

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtCreateContextEsProfile() noexcept;

    // (EXT 415) WGL_EXT_swap_control_tear

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtSwapControlTear() noexcept;

    SYSTEM_HIDDEN_DECLARE bool InitWGL(bool printInfo = true);
    SYSTEM_HIDDEN_DECLARE const char* GetWglExtensionString() noexcept;
    SYSTEM_HIDDEN_DECLARE bool SupportsWglExtension(const char* wglExtension);
    SYSTEM_HIDDEN_DECLARE void PrintWglExtensionsInfo();

    SYSTEM_HIDDEN_DECLARE void InitWglArbExtensionsString() noexcept;
    SYSTEM_HIDDEN_DECLARE void InitWglExtExtensionsString() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbBufferRegion();
    SYSTEM_HIDDEN_DECLARE void InitWglArbMultisample();
    SYSTEM_HIDDEN_DECLARE void InitWglArbPixelFormat();
    SYSTEM_HIDDEN_DECLARE void InitWglArbMakeCurrentRead();
    SYSTEM_HIDDEN_DECLARE void InitWglArbPBuffer();
    SYSTEM_HIDDEN_DECLARE void InitWglArbRenderTexture();
    SYSTEM_HIDDEN_DECLARE void InitWglArbPixelFormatFloat();
    SYSTEM_HIDDEN_DECLARE void InitWglArbFramebufferSRGB();
    SYSTEM_HIDDEN_DECLARE void InitWglArbCreateContext();
    SYSTEM_HIDDEN_DECLARE void InitWglArbCreateContextProfile();
    SYSTEM_HIDDEN_DECLARE void InitWglArbCreateContextRobustness();
    SYSTEM_HIDDEN_DECLARE void InitWglArbRobustnessApplicationIsolation();
    SYSTEM_HIDDEN_DECLARE void InitWglArbRobustnessShareGroupIsolation();
    SYSTEM_HIDDEN_DECLARE void InitWglArbContextFlushControl();

    SYSTEM_HIDDEN_DECLARE void InitWglExtDisplayColorTable();
    SYSTEM_HIDDEN_DECLARE void InitWglExtMakeCurrentRead();
    SYSTEM_HIDDEN_DECLARE void InitWglExtPixelFormat();
    SYSTEM_HIDDEN_DECLARE void InitWglExtPBuffer();
    SYSTEM_HIDDEN_DECLARE void InitWglExtSwapControl();
    SYSTEM_HIDDEN_DECLARE void InitWglExtDepthFloat();
    SYSTEM_HIDDEN_DECLARE void InitWglExtMultisample();
    SYSTEM_HIDDEN_DECLARE void InitWglExtPixelFormatPackedFloat();
    SYSTEM_HIDDEN_DECLARE void InitWglExtFramebufferSRGB();
    SYSTEM_HIDDEN_DECLARE void InitWglExtCreateContextEs2Profile();
    SYSTEM_HIDDEN_DECLARE void InitWglExtCreateContextEsProfile();
    SYSTEM_HIDDEN_DECLARE void InitWglExtSwapControlTear();
}

#endif  // SYSTEM_OPENGL_WGL_EXTENSIONS_H
