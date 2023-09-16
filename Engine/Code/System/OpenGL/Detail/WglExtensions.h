///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ�����������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/29 23:21)

#ifndef SYSTEM_OPENGL_WGL_EXTENSIONS_H
#define SYSTEM_OPENGL_WGL_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/Detail/OpenGL/WglExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/WglExtensionsUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    // WGL 1.0

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWgl10() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWgl10() noexcept;

    NODISCARD int SYSTEM_HIDDEN_DECLARE ChoosePixelFormat(WindowsHdc hDc, const PixelFormatDescriptor* pPfd) noexcept;
    NODISCARD int SYSTEM_HIDDEN_DECLARE DescribePixelFormat(WindowsHdc hdc, int ipfd, WindowsUInt cjpfd, PixelFormatDescriptor* ppfd) noexcept;
    NODISCARD WindowsUInt SYSTEM_HIDDEN_DECLARE GetEnhMetaFilePixelFormat(HEnhMetaFile hemf, WindowsUInt cbBuffer, PixelFormatDescriptor* ppfd) noexcept;
    NODISCARD int SYSTEM_HIDDEN_DECLARE GetPixelFormat(WindowsHdc hdc) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE SetPixelFormat(WindowsHdc hdc, int ipfd, const PixelFormatDescriptor* ppfd) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE SwapBuffers(WindowsHdc hdc) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglCopyContext(OpenGLHglrc hglrcSrc, OpenGLHglrc hglrcDst, WindowsUInt mask) noexcept;
    NODISCARD OpenGLHglrc SYSTEM_HIDDEN_DECLARE WglCreateContext(WindowsHdc hDc) noexcept;
    NODISCARD OpenGLHglrc SYSTEM_HIDDEN_DECLARE WglCreateLayerContext(WindowsHdc hDc, int level) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDeleteContext(OpenGLHglrc oldContext) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDescribeLayerPlane(WindowsHdc hDc, int pixelFormat, int layerPlane, WindowsUInt nBytes, LayerPlaneDescriptor* plpd) noexcept;
    NODISCARD OpenGLHglrc SYSTEM_HIDDEN_DECLARE WglGetCurrentContext() noexcept;
    NODISCARD WindowsHdc SYSTEM_HIDDEN_DECLARE WglGetCurrentDC() noexcept;
    NODISCARD int SYSTEM_HIDDEN_DECLARE WglGetLayerPaletteEntries(WindowsHdc hdc, int iLayerPlane, int iStart, int cEntries, OpenGLColorref* pcr) noexcept;
    NODISCARD OpenGLProc SYSTEM_HIDDEN_DECLARE WglGetProcAddress(const char* lpszProc) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglMakeCurrent(WindowsHdc hDc, OpenGLHglrc newContext) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglRealizeLayerPalette(WindowsHdc hdc, int iLayerPlane, WindowsBool bRealize) noexcept;
    NODISCARD int SYSTEM_HIDDEN_DECLARE WglSetLayerPaletteEntries(WindowsHdc hdc, int iLayerPlane, int iStart, int cEntries, const OpenGLColorref* pcr) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglShareLists(OpenGLHglrc hrcSrvShare, OpenGLHglrc hrcSrvSource) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglSwapLayerBuffers(WindowsHdc hdc, WindowsUInt fuFlags) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglUseFontBitmaps(WindowsHdc hDC, WindowsDWord first, WindowsDWord count, WindowsDWord listBase) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglUseFontBitmapsA(WindowsHdc hDC, WindowsDWord first, WindowsDWord count, WindowsDWord listBase) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglUseFontBitmapsW(WindowsHdc hDC, WindowsDWord first, WindowsDWord count, WindowsDWord listBase) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglUseFontOutlines(WindowsHdc hDC, WindowsDWord first, WindowsDWord count, WindowsDWord listBase, float deviation, float extrusion, int format, GlyphMetricsFloatPtr lpgmf) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglUseFontOutlinesA(WindowsHdc hDC, WindowsDWord first, WindowsDWord count, WindowsDWord listBase, float deviation, float extrusion, int format, GlyphMetricsFloatPtr lpgmf) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglUseFontOutlinesW(WindowsHdc hDC, WindowsDWord first, WindowsDWord count, WindowsDWord listBase, float deviation, float extrusion, int format, GlyphMetricsFloatPtr lpgmf) noexcept;

    // ARB ��չ

    // WGL_ARB_buffer_region

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbBufferRegion() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbBufferRegion();

    NODISCARD WindowsHandle SYSTEM_HIDDEN_DECLARE WglCreateBufferRegionARB(WindowsHdc hDC, int iLayerPlane, WindowsUInt uType) noexcept;
    void SYSTEM_HIDDEN_DECLARE WglDeleteBufferRegionARB(WindowsHandle hRegion) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglSaveBufferRegionARB(WindowsHandle hRegion, int x, int y, int width, int height) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglRestoreBufferRegionARB(WindowsHandle hRegion, int x, int y, int width, int height, int xSrc, int ySrc) noexcept;

    // WGL_ARB_context_flush_control

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbContextFlushControl() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbContextFlushControl();

    // WGL_ARB_create_context

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbCreateContext() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbCreateContext();

    NODISCARD OpenGLHglrc SYSTEM_HIDDEN_DECLARE WglCreateContextAttribsARB(WindowsHdc hDC, OpenGLHglrc hShareContext, const int* attribList) noexcept;

    // WGL_ARB_create_context_no_error

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbCreateContextNoError() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbCreateContextNoError();

    // WGL_ARB_create_context_profile

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbCreateContextProfile() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbCreateContextProfile();

    // WGL_ARB_create_context_robustness

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbCreateContextRobustness() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbCreateContextRobustness();

    // WGL_ARB_extensions_string

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbExtensionsString() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbExtensionsString() noexcept;

    NODISCARD const char* SYSTEM_HIDDEN_DECLARE WglGetExtensionsStringARB(WindowsHdc hdc) noexcept;

    // WGL_ARB_framebuffer_sRGB

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbFramebufferSRGB() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbFramebufferSRGB();

    // WGL_ARB_make_current_read

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbMakeCurrentRead() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbMakeCurrentRead();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglMakeContextCurrentARB(WindowsHdc hDrawDC, WindowsHdc hReadDC, OpenGLHglrc hglrc) noexcept;
    NODISCARD WindowsHdc SYSTEM_HIDDEN_DECLARE WglGetCurrentReadDCARB() noexcept;

    // WGL_ARB_multisample

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbMultisample() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbMultisample();

    // WGL_ARB_pbuffer

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbPBuffer() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbPBuffer();

    NODISCARD WglHPBufferArb SYSTEM_HIDDEN_DECLARE WglCreatePbufferARB(WindowsHdc hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList) noexcept;
    NODISCARD WindowsHdc SYSTEM_HIDDEN_DECLARE WglGetPbufferDCARB(WglHPBufferArb hPbuffer) noexcept;
    NODISCARD int SYSTEM_HIDDEN_DECLARE WglReleasePbufferDCARB(WglHPBufferArb hPbuffer, WindowsHdc hDC) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDestroyPbufferARB(WglHPBufferArb hPbuffer) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglQueryPbufferARB(WglHPBufferArb hPbuffer, int iAttribute, int* piValue) noexcept;

    // WGL_ARB_pixel_format

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbPixelFormat() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbPixelFormat();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetPixelFormatAttribivARB(WindowsHdc hdc, int iPixelFormat, int iLayerPlane, WindowsUInt nAttributes, const int* piAttributes, int* piValues) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetPixelFormatAttribfvARB(WindowsHdc hdc, int iPixelFormat, int iLayerPlane, WindowsUInt nAttributes, const int* piAttributes, float* pfValues) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglChoosePixelFormatARB(WindowsHdc hdc, const int* piAttribIList, const float* pfAttribFList, WindowsUInt nMaxFormats, int* piFormats, WindowsUInt* nNumFormats) noexcept;

    // WGL_ARB_pixel_format_float

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbPixelFormatFloat() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbPixelFormatFloat();

    // WGL_ARB_render_texture

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbRenderTexture() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbRenderTexture();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglBindTexImageARB(WglHPBufferArb hPbuffer, int iBuffer) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglReleaseTexImageARB(WglHPBufferArb hPbuffer, int iBuffer) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglSetPbufferAttribARB(WglHPBufferArb hPbuffer, const int* piAttribList) noexcept;

    // WGL_ARB_robustness_application_isolation

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbRobustnessApplicationIsolation() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbRobustnessApplicationIsolation();

    // WGL_ARB_robustness_share_group_isolation

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbRobustnessShareGroupIsolation() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbRobustnessShareGroupIsolation();

    // 3DFX ��չ

    // WGL_3DFX_multisample

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWgl3DFXMultisample() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWgl3DFXMultisample();

    // 3DL ��չ

    // WGL_3DL_stereo_control

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWgl3DLStereoControl() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWgl3DLStereoControl();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglSetStereoEmitterState3DL(WindowsHdc hDC, WindowsUInt uState) noexcept;

    // AMD ��չ

    // WGL_AMD_gpu_association

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglAMDGpuAssociation() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglAMDGpuAssociation();

    NODISCARD WindowsUInt SYSTEM_HIDDEN_DECLARE WglGetGPUIDsAMD(WindowsUInt maxCount, WindowsUInt* ids) noexcept;
    NODISCARD WindowsInt SYSTEM_HIDDEN_DECLARE WglGetGPUInfoAMD(WindowsUInt id, WindowsInt property, GLenum dataType, WindowsUInt size, void* data) noexcept;
    NODISCARD WindowsUInt SYSTEM_HIDDEN_DECLARE WglGetContextGPUIDAMD(OpenGLHglrc hglrc) noexcept;
    NODISCARD OpenGLHglrc SYSTEM_HIDDEN_DECLARE WglCreateAssociatedContextAMD(WindowsUInt id) noexcept;
    NODISCARD OpenGLHglrc SYSTEM_HIDDEN_DECLARE WglCreateAssociatedContextAttribsAMD(WindowsUInt id, OpenGLHglrc hShareContext, const int* attribList) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDeleteAssociatedContextAMD(OpenGLHglrc hglrc) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglMakeAssociatedContextCurrentAMD(OpenGLHglrc hglrc) noexcept;
    NODISCARD OpenGLHglrc SYSTEM_HIDDEN_DECLARE WglGetCurrentAssociatedContextAMD() noexcept;
    void SYSTEM_HIDDEN_DECLARE WglBlitContextFramebufferAMD(OpenGLHglrc dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) noexcept;

    // ATI ��չ

    // WGL_ATI_pixel_format_float

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglATIPixelFormatFloat() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglATIPixelFormatFloat();

    // WGL_ATI_render_texture_rectangle

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglATIRenderTextureRectangle() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglATIRenderTextureRectangle();

    // EXT ��չ

    // WGL_EXT_colorspace

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtColorspace() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtColorspace();

    // WGL_EXT_create_context_es2_profile

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtCreateContextEs2Profile() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtCreateContextEs2Profile();

    // WGL_EXT_create_context_es_profile

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtCreateContextEsProfile() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtCreateContextEsProfile();

    // WGL_EXT_depth_float

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtDepthFloat() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtDepthFloat();

    // WGL_EXT_display_color_table

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtDisplayColorTable() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtDisplayColorTable();

    NODISCARD GLboolean SYSTEM_HIDDEN_DECLARE WglCreateDisplayColorTableEXT(GLushort id) noexcept;
    NODISCARD GLboolean SYSTEM_HIDDEN_DECLARE WglLoadDisplayColorTableEXT(const GLushort* table, GLuint length) noexcept;
    NODISCARD GLboolean SYSTEM_HIDDEN_DECLARE WglBindDisplayColorTableEXT(GLushort id) noexcept;
    void SYSTEM_HIDDEN_DECLARE WglDestroyDisplayColorTableEXT(GLushort id) noexcept;

    // WGL_EXT_extensions_string

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtExtensionsString() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtExtensionsString() noexcept;

    MAYBE_NULLPTR const char* SYSTEM_HIDDEN_DECLARE WglGetExtensionsStringEXT() noexcept;

    // WGL_EXT_framebuffer_sRGB

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtFramebufferSRGB() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtFramebufferSRGB();

    // WGL_EXT_make_current_read

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtMakeCurrentRead() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtMakeCurrentRead();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglMakeContextCurrentEXT(WindowsHdc hDrawDC, WindowsHdc hReadDC, OpenGLHglrc hglrc) noexcept;
    NODISCARD WindowsHdc SYSTEM_HIDDEN_DECLARE WglGetCurrentReadDCEXT() noexcept;

    // WGL_EXT_multisample

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtMultisample() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtMultisample();

    // WGL_EXT_pbuffer

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtPBuffer() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtPBuffer();

    NODISCARD WglHPBufferExt SYSTEM_HIDDEN_DECLARE WglCreatePbufferEXT(WindowsHdc hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList) noexcept;
    NODISCARD WindowsHdc SYSTEM_HIDDEN_DECLARE WglGetPbufferDCEXT(WglHPBufferExt hPbuffer) noexcept;
    NODISCARD int SYSTEM_HIDDEN_DECLARE WglReleasePbufferDCEXT(WglHPBufferExt hPbuffer, WindowsHdc hDC) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDestroyPbufferEXT(WglHPBufferExt hPbuffer) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglQueryPbufferEXT(WglHPBufferExt hPbuffer, int iAttribute, int* piValue) noexcept;

    // WGL_EXT_pixel_format

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtPixelFormat() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtPixelFormat();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetPixelFormatAttribivEXT(WindowsHdc hdc, int iPixelFormat, int iLayerPlane, WindowsUInt nAttributes, int* piAttributes, int* piValues) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetPixelFormatAttribfvEXT(WindowsHdc hdc, int iPixelFormat, int iLayerPlane, WindowsUInt nAttributes, int* piAttributes, float* pfValues) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglChoosePixelFormatEXT(WindowsHdc hdc, const int* piAttribIList, const float* pfAttribFList, WindowsUInt nMaxFormats, int* piFormats, WindowsUInt* nNumFormats) noexcept;

    // WGL_EXT_pixel_format_packed_float

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtPixelFormatPackedFloat() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtPixelFormatPackedFloat();

    // WGL_EXT_swap_control

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtSwapControl() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtSwapControl();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglSwapIntervalEXT(int interval) noexcept;
    NODISCARD int SYSTEM_HIDDEN_DECLARE WglGetSwapIntervalEXT() noexcept;

    // WGL_EXT_swap_control_tear

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtSwapControlTear() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtSwapControlTear();

    // I3D ��չ

    // WGL_I3D_digital_video_control

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglI3DDigitalVideoControl() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglI3DDigitalVideoControl();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetDigitalVideoParametersI3D(WindowsHdc hDC, int iAttribute, int* piValue) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglSetDigitalVideoParametersI3D(WindowsHdc hDC, int iAttribute, const int* piValue) noexcept;

    // WGL_I3D_gamma

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglI3DGamma() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglI3DGamma();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetGammaTableParametersI3D(WindowsHdc hDC, int iAttribute, int* piValue) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglSetGammaTableParametersI3D(WindowsHdc hDC, int iAttribute, const int* piValue) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetGammaTableI3D(WindowsHdc hDC, int iEntries, WindowsUShort* puRed, WindowsUShort* puGreen, WindowsUShort* puBlue) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglSetGammaTableI3D(WindowsHdc hDC, int iEntries, const WindowsUShort* puRed, const WindowsUShort* puGreen, const WindowsUShort* puBlue) noexcept;

    // WGL_I3D_genlock

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglI3DGenlock() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglI3DGenlock();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglEnableGenlockI3D(WindowsHdc hDC) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDisableGenlockI3D(WindowsHdc hDC) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglIsEnabledGenlockI3D(WindowsHdc hDC, WindowsBool* pFlag) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGenlockSourceI3D(WindowsHdc hDC, WindowsUInt uSource) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetGenlockSourceI3D(WindowsHdc hDC, WindowsUInt* uSource) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGenlockSourceEdgeI3D(WindowsHdc hDC, WindowsUInt uEdge) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetGenlockSourceEdgeI3D(WindowsHdc hDC, WindowsUInt* uEdge) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGenlockSampleRateI3D(WindowsHdc hDC, WindowsUInt uRate) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetGenlockSampleRateI3D(WindowsHdc hDC, WindowsUInt* uRate) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGenlockSourceDelayI3D(WindowsHdc hDC, WindowsUInt uDelay) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetGenlockSourceDelayI3D(WindowsHdc hDC, WindowsUInt* uDelay) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglQueryGenlockMaxSourceDelayI3D(WindowsHdc hDC, WindowsUInt* uMaxLineDelay, WindowsUInt* uMaxPixelDelay) noexcept;

    // WGL_I3D_image_buffer

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglI3DImageBuffer() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglI3DImageBuffer();

    MAYBE_NULLPTR WindowsVoidPtr SYSTEM_HIDDEN_DECLARE WglCreateImageBufferI3D(WindowsHdc hDC, WindowsDWord dwSize, WindowsUInt uFlags) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDestroyImageBufferI3D(WindowsHdc hDC, WindowsVoidPtr pAddress) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglAssociateImageBufferEventsI3D(WindowsHdc hDC, const WindowsHandle* pEvent, const WindowsVoidPtr* pAddress, const WindowsDWord* pSize, WindowsUInt count) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglReleaseImageBufferEventsI3D(WindowsHdc hDC, const WindowsVoidPtr* pAddress, WindowsUInt count) noexcept;

    // WGL_I3D_swap_frame_lock

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglI3DSwapFrameLock() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglI3DSwapFrameLock();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglEnableFrameLockI3D() noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDisableFrameLockI3D() noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglIsEnabledFrameLockI3D(WindowsBool* pFlag) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglQueryFrameLockMasterI3D(WindowsBool* pFlag) noexcept;

    // WGL_I3D_swap_frame_usage

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglI3DSwapFrameUsage() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglI3DSwapFrameUsage();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetFrameUsageI3D(float* pUsage) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglBeginFrameTrackingI3D() noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglEndFrameTrackingI3D() noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglQueryFrameTrackingI3D(WindowsDWord* pFrameCount, WindowsDWord* pMissedFrames, float* pLastMissedUsage) noexcept;

    // NV ��չ

    // WGL_NV_DX_interop

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNVDXInterop() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNVDXIntero();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDXSetResourceShareHandleNV(void* dxObject, WindowsHandle shareHandle) noexcept;
    NODISCARD WindowsHandle SYSTEM_HIDDEN_DECLARE WglDXOpenDeviceNV(void* dxDevice) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDXCloseDeviceNV(WindowsHandle hDevice) noexcept;
    NODISCARD WindowsHandle SYSTEM_HIDDEN_DECLARE WglDXRegisterObjectNV(WindowsHandle hDevice, void* dxObject, GLuint name, GLenum type, GLenum access) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDXUnregisterObjectNV(WindowsHandle hDevice, WindowsHandle hObject) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDXObjectAccessNV(WindowsHandle hObject, GLenum access) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDXLockObjectsNV(WindowsHandle hDevice, GLint count, WindowsHandle* hObjects) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDXUnlockObjectsNV(WindowsHandle hDevice, GLint count, WindowsHandle* hObjects) noexcept;

    // WGL_NV_DX_interop2

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNVDXInterop2() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNVDXIntero2();

    // WGL_NV_copy_image

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNVCopyImage() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNVCopyImage();

    WindowsBool SYSTEM_HIDDEN_DECLARE WglCopyImageSubDataNV(OpenGLHglrc hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, OpenGLHglrc hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth) noexcept;

    // WGL_NV_delay_before_swap

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNVDelayBeforeSwap() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNVDelayBeforeSwap();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDelayBeforeSwapNV(WindowsHdc hDC, GLfloat seconds) noexcept;

    // WGL_NV_float_buffer

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNVFloatBuffer() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNVFloatBuffer();

    // WGL_NV_gpu_affinity

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNVGpuAffinity() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNVGpuAffinity();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglEnumGpusNV(WindowsUInt iGpuIndex, WglHGpuNv* phGpu) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglEnumGpuDevicesNV(WglHGpuNv hGpu, WindowsUInt iDeviceIndex, WglGpuDevicePtr lpGpuDevice) noexcept;
    NODISCARD WindowsHdc SYSTEM_HIDDEN_DECLARE WglCreateAffinityDCNV(const WglHGpuNv* phGpuList) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglEnumGpusFromAffinityDCNV(WindowsHdc hAffinityDC, WindowsUInt iGpuIndex, WglHGpuNv* hGpu) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDeleteDCNV(WindowsHdc hdc) noexcept;

    // WGL_NV_multigpu_context

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNVMultigpuContext() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNVMultigpuContext();

    // WGL_NV_multisample_coverage

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNVMultisampleCoverage() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNVMultisampleCoverage();

    // WGL_NV_present_video

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNVPresentVideo() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNVPresentVideo();

    NODISCARD int SYSTEM_HIDDEN_DECLARE WglEnumerateVideoDevicesNV(WindowsHdc hDc, WglHVideoOutputDeviceNv* phDeviceList) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglBindVideoDeviceNV(WindowsHdc hDc, unsigned int uVideoSlot, WglHVideoOutputDeviceNv hVideoDevice, const int* piAttribList) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglQueryCurrentContextNV(int iAttribute, int* piValue) noexcept;

    // WGL_NV_render_depth_texture

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNVRenderDepthTexture() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNVRenderDepthTexture();

    // WGL_NV_render_texture_rectangle

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNVRenderTextureRectangle() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNVRenderTextureRectangle();

    // WGL_NV_swap_group

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNVSwapGroup() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNVSwapGroup();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglJoinSwapGroupNV(WindowsHdc hDC, GLuint group) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglBindSwapBarrierNV(GLuint group, GLuint barrier) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglQuerySwapGroupNV(WindowsHdc hDC, GLuint* group, GLuint* barrier) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglQueryMaxSwapGroupsNV(WindowsHdc hDC, GLuint* maxGroups, GLuint* maxBarriers) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglQueryFrameCountNV(WindowsHdc hDC, GLuint* count) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglResetFrameCountNV(WindowsHdc hDC) noexcept;

    // WGL_NV_vertex_array_range

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNVVertexArrayRange() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNVVertexArrayRange();

    MAYBE_NULLPTR void* SYSTEM_HIDDEN_DECLARE WglAllocateMemoryNV(GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority) noexcept;
    void SYSTEM_HIDDEN_DECLARE WglFreeMemoryNV(void* pointer) noexcept;

    // WGL_NV_video_capture

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNVVideoCapture() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNVVideoCapture();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglBindVideoCaptureDeviceNV(WindowsUInt uVideoSlot, WglHVideoInputDeviceNv hDevice) noexcept;
    NODISCARD WindowsUInt SYSTEM_HIDDEN_DECLARE WglEnumerateVideoCaptureDevicesNV(WindowsHdc hDc, WglHVideoInputDeviceNv* phDeviceList) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglLockVideoCaptureDeviceNV(WindowsHdc hDc, WglHVideoInputDeviceNv hDevice) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglQueryVideoCaptureDeviceNV(WindowsHdc hDc, WglHVideoInputDeviceNv hDevice, int iAttribute, int* piValue) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglReleaseVideoCaptureDeviceNV(WindowsHdc hDc, WglHVideoInputDeviceNv hDevice) noexcept;

    // WGL_NV_video_output

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNVVideoOutput() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNVVideoOutput();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetVideoDeviceNV(WindowsHdc hDC, int numDevices, WglHPVideoDev* hVideoDevice) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglReleaseVideoDeviceNV(WglHPVideoDev hVideoDevice) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglBindVideoImageNV(WglHPVideoDev hVideoDevice, WglHPBufferArb hPbuffer, int iVideoBuffer) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglReleaseVideoImageNV(WglHPBufferArb hPbuffer, int iVideoBuffer) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglSendPbufferToVideoNV(WglHPBufferArb hPbuffer, int iBufferType, unsigned long* pulCounterPbuffer, WindowsBool bBlock) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetVideoInfoNV(WglHPVideoDev hpVideoDevice, unsigned long* pulCounterOutputPbuffer, unsigned long* pulCounterOutputVideo) noexcept;

    // OML ��չ

    // WGL_OML_sync_control

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglOMLSyncControl() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglOMLSyncControl();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetSyncValuesOML(WindowsHdc hdc, WindowsInt64* ust, WindowsInt64* msc, WindowsInt64* sbc) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetMscRateOML(WindowsHdc hdc, WindowsInt32* numerator, WindowsInt32* denominator) noexcept;
    NODISCARD WindowsInt64 SYSTEM_HIDDEN_DECLARE WglSwapBuffersMscOML(WindowsHdc hdc, WindowsInt64 target_msc, WindowsInt64 divisor, WindowsInt64 remainder) noexcept;
    NODISCARD WindowsInt64 SYSTEM_HIDDEN_DECLARE WglSwapLayerBuffersMscOML(WindowsHdc hdc, INT fuPlanes, WindowsInt64 target_msc, WindowsInt64 divisor, WindowsInt64 remainder) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglWaitForMscOML(WindowsHdc hdc, WindowsInt64 target_msc, WindowsInt64 divisor, WindowsInt64 remainder, WindowsInt64* ust, WindowsInt64* msc, WindowsInt64* sbc) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglWaitForSbcOML(WindowsHdc hdc, WindowsInt64 target_sbc, WindowsInt64* ust, WindowsInt64* msc, WindowsInt64* sbc) noexcept;

    NODISCARD SYSTEM_HIDDEN_DECLARE bool InitWgl();
    MAYBE_NULLPTR SYSTEM_HIDDEN_DECLARE const char* GetWglExtensionString() noexcept;
    NODISCARD SYSTEM_HIDDEN_DECLARE bool SupportsWglExtension(const char* wglExtension);
}

#endif  // SYSTEM_OPENGL_WGL_EXTENSIONS_H
