/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/29 09:34)

#ifndef SYSTEM_OPENGL_WGL_EXTENSIONS_H
#define SYSTEM_OPENGL_WGL_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/Detail/OpenGL/WglExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/WglExtensionsUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    /// WGL 1.0
    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWgl10() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWgl10() noexcept;

    NODISCARD int SYSTEM_HIDDEN_DECLARE ChoosePixelFormat(WindowsHdc hdc, const PixelFormatDescriptor* pixelFormatDescriptor) noexcept;
    NODISCARD int SYSTEM_HIDDEN_DECLARE DescribePixelFormat(WindowsHdc hdc, int iPixelFormat, WindowsUInt nBytes, PixelFormatDescriptor* pixelFormatDescriptor) noexcept;
    NODISCARD WindowsUInt SYSTEM_HIDDEN_DECLARE GetEnhMetaFilePixelFormat(HEnhMetaFile hEnhMetaFile, WindowsUInt cbBuffer, PixelFormatDescriptor* pixelFormatDescriptor) noexcept;
    NODISCARD int SYSTEM_HIDDEN_DECLARE GetPixelFormat(WindowsHdc hdc) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE SetPixelFormat(WindowsHdc hdc, int format, const PixelFormatDescriptor* pixelFormatDescriptor) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE SwapBuffers(WindowsHdc hdc) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglCopyContext(OpenGLRcHandle hGlRcSrc, OpenGLRcHandle hGlRcDst, WindowsUInt mask) noexcept;
    NODISCARD OpenGLRcHandle SYSTEM_HIDDEN_DECLARE WglCreateContext(WindowsHdc hdc) noexcept;
    NODISCARD OpenGLRcHandle SYSTEM_HIDDEN_DECLARE WglCreateLayerContext(WindowsHdc hdc, int level) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDeleteContext(OpenGLRcHandle oldContext) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDescribeLayerPlane(WindowsHdc hdc, int pixelFormat, int layerPlane, WindowsUInt bytes, LayerPlaneDescriptor* layerPlaneDescriptor) noexcept;
    NODISCARD OpenGLRcHandle SYSTEM_HIDDEN_DECLARE WglGetCurrentContext() noexcept;
    NODISCARD WindowsHdc SYSTEM_HIDDEN_DECLARE WglGetCurrentDC() noexcept;
    NODISCARD int SYSTEM_HIDDEN_DECLARE WglGetLayerPaletteEntries(WindowsHdc hdc, int layerPlane, int start, int entries, OpenGLColorRef* pcr) noexcept;
    NODISCARD OpenGLProc SYSTEM_HIDDEN_DECLARE WglGetProcAddress(const char* proc) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglMakeCurrent(WindowsHdc hdc, OpenGLRcHandle newContext) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglRealizeLayerPalette(WindowsHdc hdc, int layerPlane, WindowsBool realize) noexcept;
    NODISCARD int SYSTEM_HIDDEN_DECLARE WglSetLayerPaletteEntries(WindowsHdc hdc, int layerPlane, int start, int entries, const OpenGLColorRef* pcr) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglShareLists(OpenGLRcHandle hrcSrvShare, OpenGLRcHandle hrcSrvSource) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglSwapLayerBuffers(WindowsHdc hdc, WindowsUInt fuFlags) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglUseFontBitmaps(WindowsHdc hdc, WindowsDWord first, WindowsDWord count, WindowsDWord listBase) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglUseFontBitmapsA(WindowsHdc hdc, WindowsDWord first, WindowsDWord count, WindowsDWord listBase) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglUseFontBitmapsW(WindowsHdc hdc, WindowsDWord first, WindowsDWord count, WindowsDWord listBase) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglUseFontOutlines(WindowsHdc hdc, WindowsDWord first, WindowsDWord count, WindowsDWord listBase, float deviation, float extrusion, int format, GlyphMetricsFloatPtr glyphMetricsFloat) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglUseFontOutlinesA(WindowsHdc hdc, WindowsDWord first, WindowsDWord count, WindowsDWord listBase, float deviation, float extrusion, int format, GlyphMetricsFloatPtr glyphMetricsFloat) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglUseFontOutlinesW(WindowsHdc hdc, WindowsDWord first, WindowsDWord count, WindowsDWord listBase, float deviation, float extrusion, int format, GlyphMetricsFloatPtr glyphMetricsFloat) noexcept;

    /// ARB 扩展

    /// WGL_ARB_buffer_region

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbBufferRegion() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbBufferRegion();

    NODISCARD WindowsHandle SYSTEM_HIDDEN_DECLARE WglCreateBufferRegionARB(WindowsHdc hdc, int layerPlane, WindowsUInt type) noexcept;
    void SYSTEM_HIDDEN_DECLARE WglDeleteBufferRegionARB(WindowsHandle region) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglSaveBufferRegionARB(WindowsHandle region, int x, int y, int width, int height) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglRestoreBufferRegionARB(WindowsHandle region, int x, int y, int width, int height, int xSrc, int ySrc) noexcept;

    /// WGL_ARB_context_flush_control

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbContextFlushControl() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbContextFlushControl();

    /// WGL_ARB_create_context

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbCreateContext() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbCreateContext();

    NODISCARD OpenGLRcHandle SYSTEM_HIDDEN_DECLARE WglCreateContextAttribSArb(WindowsHdc hdc, OpenGLRcHandle shareContext, const int* attribList) noexcept;

    /// WGL_ARB_create_context_no_error

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbCreateContextNoError() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbCreateContextNoError();

    /// WGL_ARB_create_context_profile

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbCreateContextProfile() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbCreateContextProfile();

    /// WGL_ARB_create_context_robustness

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbCreateContextRobustness() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbCreateContextRobustness();

    /// WGL_ARB_extensions_string

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbExtensionsString() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbExtensionsString() noexcept;

    NODISCARD const char* SYSTEM_HIDDEN_DECLARE WglGetExtensionsStringARB(WindowsHdc hdc) noexcept;

    /// WGL_ARB_framebuffer_sRGB

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbFrameBuffersRGB() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbFrameBuffersRGB();

    /// WGL_ARB_make_current_read

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbMakeCurrentRead() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbMakeCurrentRead();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglMakeContextCurrentARB(WindowsHdc drawDC, WindowsHdc readDC, OpenGLRcHandle hGlRc) noexcept;
    NODISCARD WindowsHdc SYSTEM_HIDDEN_DECLARE WglGetCurrentReadDcARB() noexcept;

    /// WGL_ARB_multisample

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbMultiSample() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbMultiSample();

    /// WGL_ARB_pbuffer

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbPBuffer() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbPBuffer();

    NODISCARD WglHpBufferArb SYSTEM_HIDDEN_DECLARE WglCreatePBufferARB(WindowsHdc hdC, int pixelFormat, int width, int height, const int* piAttribList) noexcept;
    NODISCARD WindowsHdc SYSTEM_HIDDEN_DECLARE WglGetPBufferDcARB(WglHpBufferArb hPBuffer) noexcept;
    NODISCARD int SYSTEM_HIDDEN_DECLARE WglReleasePBufferDcARB(WglHpBufferArb hPBuffer, WindowsHdc hdc) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDestroyPBufferARB(WglHpBufferArb hPBuffer) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglQueryPBufferARB(WglHpBufferArb hPBuffer, int attribute, int* piValue) noexcept;

    /// WGL_ARB_pixel_format

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbPixelFormat() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbPixelFormat();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetPixelFormatAttribIvARB(WindowsHdc hdc, int pixelFormat, int layerPlane, WindowsUInt attributes, const int* piAttributes, int* piValues) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetPixelFormatAttribFvARB(WindowsHdc hdc, int pixelFormat, int layerPlane, WindowsUInt attributes, const int* piAttributes, float* pfValues) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglChoosePixelFormatARB(WindowsHdc hdc, const int* piAttribIList, const float* pfAttribFList, WindowsUInt maxFormats, int* piFormats, WindowsUInt* numFormats) noexcept;

    /// WGL_ARB_pixel_format_float

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbPixelFormatFloat() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbPixelFormatFloat();

    /// WGL_ARB_render_texture

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbRenderTexture() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbRenderTexture();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglBindTexImageARB(WglHpBufferArb hPBuffer, int buffer) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglReleaseTexImageARB(WglHpBufferArb hPBuffer, int buffer) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglSetPBufferAttribARB(WglHpBufferArb hPBuffer, const int* piAttribList) noexcept;

    /// WGL_ARB_robustness_application_isolation

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbRobustnessApplicationIsolation() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbRobustnessApplicationIsolation();

    /// WGL_ARB_robustness_share_group_isolation

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglArbRobustnessShareGroupIsolation() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglArbRobustnessShareGroupIsolation();

    /// 3DFX 扩展

    /// WGL_3DFX_multisample

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWgl3DfxMultiSample() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWgl3DfxMultiSample();

    /// 3DL 扩展

    /// WGL_3DL_stereo_control

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWgl3DlStereoControl() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWgl3DlStereoControl();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglSetStereoEmitterState3Dl(WindowsHdc hdC, WindowsUInt state) noexcept;

    /// AMD 扩展

    /// WGL_AMD_gpu_association

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglAMDGpuAssociation() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglAMDGpuAssociation();

    NODISCARD WindowsUInt SYSTEM_HIDDEN_DECLARE WglGetGpuIdsAMD(WindowsUInt maxCount, WindowsUInt* ids) noexcept;
    NODISCARD WindowsInt SYSTEM_HIDDEN_DECLARE WglGetGpuInfoAMD(WindowsUInt id, WindowsInt property, GLenum dataType, WindowsUInt size, void* data) noexcept;
    NODISCARD WindowsUInt SYSTEM_HIDDEN_DECLARE WglGetContextGpuIdAMD(OpenGLRcHandle hGlRc) noexcept;
    NODISCARD OpenGLRcHandle SYSTEM_HIDDEN_DECLARE WglCreateAssociatedContextAMD(WindowsUInt id) noexcept;
    NODISCARD OpenGLRcHandle SYSTEM_HIDDEN_DECLARE WglCreateAssociatedContextAttribSAmd(WindowsUInt id, OpenGLRcHandle hShareContext, const int* attribList) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDeleteAssociatedContextAMD(OpenGLRcHandle hGlRc) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglMakeAssociatedContextCurrentAMD(OpenGLRcHandle hGlRc) noexcept;
    NODISCARD OpenGLRcHandle SYSTEM_HIDDEN_DECLARE WglGetCurrentAssociatedContextAMD() noexcept;
    void SYSTEM_HIDDEN_DECLARE WglBlitContextFrameBufferAMD(OpenGLRcHandle dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) noexcept;

    /// ATI 扩展

    /// WGL_ATI_pixel_format_float

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglATIPixelFormatFloat() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglATIPixelFormatFloat();

    /// WGL_ATI_render_texture_rectangle

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglATIRenderTextureRectangle() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglATIRenderTextureRectangle();

    /// EXT 扩展

    /// WGL_EXT_colorspace

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtColorSpace() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtColorSpace();

    /// WGL_EXT_create_context_es2_profile

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtCreateContextEs2Profile() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtCreateContextEs2Profile();

    /// WGL_EXT_create_context_es_profile

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtCreateContextEsProfile() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtCreateContextEsProfile();

    /// WGL_EXT_depth_float

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtDepthFloat() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtDepthFloat();

    /// WGL_EXT_display_color_table

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtDisplayColorTable() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtDisplayColorTable();

    NODISCARD GLboolean SYSTEM_HIDDEN_DECLARE WglCreateDisplayColorTableEXT(GLushort id) noexcept;
    NODISCARD GLboolean SYSTEM_HIDDEN_DECLARE WglLoadDisplayColorTableEXT(const GLushort* table, GLuint length) noexcept;
    NODISCARD GLboolean SYSTEM_HIDDEN_DECLARE WglBindDisplayColorTableEXT(GLushort id) noexcept;
    void SYSTEM_HIDDEN_DECLARE WglDestroyDisplayColorTableEXT(GLushort id) noexcept;

    /// WGL_EXT_extensions_string

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtExtensionsString() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtExtensionsString() noexcept;

    MAYBE_NULLPTR const char* SYSTEM_HIDDEN_DECLARE WglGetExtensionsStringEXT() noexcept;

    /// WGL_EXT_framebuffer_sRGB

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtFrameBuffersRGB() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtFrameBuffersRGB();

    /// WGL_EXT_make_current_read

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtMakeCurrentRead() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtMakeCurrentRead();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglMakeContextCurrentEXT(WindowsHdc drawDC, WindowsHdc readDC, OpenGLRcHandle hGlRc) noexcept;
    NODISCARD WindowsHdc SYSTEM_HIDDEN_DECLARE WglGetCurrentReadDcEXT() noexcept;

    /// WGL_EXT_multisample

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtMultiSample() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtMultiSample();

    /// WGL_EXT_pbuffer

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtPBuffer() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtPBuffer();

    NODISCARD WglHpBufferExt SYSTEM_HIDDEN_DECLARE WglCreatePBufferEXT(WindowsHdc hdc, int pixelFormat, int width, int height, const int* piAttribList) noexcept;
    NODISCARD WindowsHdc SYSTEM_HIDDEN_DECLARE WglGetPBufferDcEXT(WglHpBufferExt hPBuffer) noexcept;
    NODISCARD int SYSTEM_HIDDEN_DECLARE WglReleasePBufferDcEXT(WglHpBufferExt hPBuffer, WindowsHdc hdc) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDestroyPBufferEXT(WglHpBufferExt hPBuffer) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglQueryPBufferEXT(WglHpBufferExt hPBuffer, int attribute, int* piValue) noexcept;

    /// WGL_EXT_pixel_format

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtPixelFormat() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtPixelFormat();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetPixelFormatAttribIvEXT(WindowsHdc hdc, int pixelFormat, int layerPlane, WindowsUInt attributes, int* piAttributes, int* piValues) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetPixelFormatAttribFvEXT(WindowsHdc hdc, int pixelFormat, int layerPlane, WindowsUInt attributes, int* piAttributes, float* pfValues) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglChoosePixelFormatEXT(WindowsHdc hdc, const int* piAttribIList, const float* pfAttribFList, WindowsUInt maxFormats, int* piFormats, WindowsUInt* numFormats) noexcept;

    /// WGL_EXT_pixel_format_packed_float

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtPixelFormatPackedFloat() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtPixelFormatPackedFloat();

    /// WGL_EXT_swap_control

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtSwapControl() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtSwapControl();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglSwapIntervalEXT(int interval) noexcept;
    NODISCARD int SYSTEM_HIDDEN_DECLARE WglGetSwapIntervalEXT() noexcept;

    /// WGL_EXT_swap_control_tear

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglExtSwapControlTear() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglExtSwapControlTear();

    /// I3D 扩展

    /// WGL_I3D_digital_video_control

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglI3DDigitalVideoControl() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglI3DDigitalVideoControl();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetDigitalVideoParametersI3D(WindowsHdc hdc, int attribute, int* piValue) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglSetDigitalVideoParametersI3D(WindowsHdc hdc, int attribute, const int* piValue) noexcept;

    /// WGL_I3D_gamma

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglI3DGamma() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglI3DGamma();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetGammaTableParametersI3D(WindowsHdc hdc, int attribute, int* piValue) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglSetGammaTableParametersI3D(WindowsHdc hdc, int attribute, const int* piValue) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetGammaTableI3D(WindowsHdc hdc, int iEntries, WindowsUShort* puRed, WindowsUShort* puGreen, WindowsUShort* puBlue) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglSetGammaTableI3D(WindowsHdc hdc, int iEntries, const WindowsUShort* puRed, const WindowsUShort* puGreen, const WindowsUShort* puBlue) noexcept;

    /// WGL_I3D_genlock

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglI3DGenLock() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglI3DGenLock();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglEnableGenLockI3D(WindowsHdc hdc) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDisableGenLockI3D(WindowsHdc hdc) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglIsEnabledGenLockI3D(WindowsHdc hdc, WindowsBool* flag) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGenLockSourceI3D(WindowsHdc hdc, WindowsUInt source) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetGenLockSourceI3D(WindowsHdc hdc, WindowsUInt* source) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGenLockSourceEdgeI3D(WindowsHdc hdc, WindowsUInt edge) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetGenLockSourceEdgeI3D(WindowsHdc hdc, WindowsUInt* edge) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGenLockSampleRateI3D(WindowsHdc hdc, WindowsUInt rate) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetGenLockSampleRateI3D(WindowsHdc hdc, WindowsUInt* rate) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGenLockSourceDelayI3D(WindowsHdc hdc, WindowsUInt delay) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetGenLockSourceDelayI3D(WindowsHdc hdc, WindowsUInt* delay) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglQueryGenLockMaxSourceDelayI3D(WindowsHdc hdc, WindowsUInt* maxLineDelay, WindowsUInt* maxPixelDelay) noexcept;

    /// WGL_I3D_image_buffer

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglI3DImageBuffer() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglI3DImageBuffer();

    MAYBE_NULLPTR WindowsVoidPtr SYSTEM_HIDDEN_DECLARE WglCreateImageBufferI3D(WindowsHdc hdc, WindowsDWord size, WindowsUInt flags) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDestroyImageBufferI3D(WindowsHdc hdc, WindowsVoidPtr address) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglAssociateImageBufferEventsI3D(WindowsHdc hdc, const WindowsHandle* event, const WindowsVoidPtr* address, const WindowsDWord* size, WindowsUInt count) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglReleaseImageBufferEventsI3D(WindowsHdc hdc, const WindowsVoidPtr* address, WindowsUInt count) noexcept;

    /// WGL_I3D_swap_frame_lock

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglI3DSwapFrameLock() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglI3DSwapFrameLock();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglEnableFrameLockI3D() noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDisableFrameLockI3D() noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglIsEnabledFrameLockI3D(WindowsBool* flag) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglQueryFrameLockMasterI3D(WindowsBool* flag) noexcept;

    /// WGL_I3D_swap_frame_usage

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglI3DSwapFrameUsage() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglI3DSwapFrameUsage();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetFrameUsageI3D(float* usage) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglBeginFrameTrackingI3D() noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglEndFrameTrackingI3D() noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglQueryFrameTrackingI3D(WindowsDWord* frameCount, WindowsDWord* missedFrames, float* lastMissedUsage) noexcept;

    /// NV 扩展

    /// WGL_NV_DX_interop

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNvDxInterop() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNvDxInterop();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDxSetResourceShareHandleNv(void* dxObject, WindowsHandle shareHandle) noexcept;
    NODISCARD WindowsHandle SYSTEM_HIDDEN_DECLARE WglDxOpenDeviceNv(void* dxDevice) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDxCloseDeviceNv(WindowsHandle hDevice) noexcept;
    NODISCARD WindowsHandle SYSTEM_HIDDEN_DECLARE WglDxRegisterObjectNv(WindowsHandle hDevice, void* dxObject, GLuint name, GLenum type, GLenum access) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDxUnregisterObjectNv(WindowsHandle hDevice, WindowsHandle hObject) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDxObjectAccessNv(WindowsHandle hObject, GLenum access) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDxLockObjectsNv(WindowsHandle hDevice, GLint count, WindowsHandle* hObjects) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDxUnlockObjectsNv(WindowsHandle hDevice, GLint count, WindowsHandle* hObjects) noexcept;

    /// WGL_NV_DX_interop2

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNvDxInterop2() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNvDxInterop2();

    /// WGL_NV_copy_image

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNvCopyImage() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNvCopyImage();

    WindowsBool SYSTEM_HIDDEN_DECLARE WglCopyImageSubDataNv(OpenGLRcHandle hSrcRc, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, OpenGLRcHandle hDstRc, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth) noexcept;

    /// WGL_NV_delay_before_swap

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNvDelayBeforeSwap() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNvDelayBeforeSwap();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDelayBeforeSwapNv(WindowsHdc hDC, GLfloat seconds) noexcept;

    /// WGL_NV_float_buffer

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNvFloatBuffer() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNvFloatBuffer();

    /// WGL_NV_gpu_affinity

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNvGpuAffinity() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNvGpuAffinity();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglEnumGpusNv(WindowsUInt gpuIndex, WglHGpuNv* phGpu) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglEnumGpuDevicesNv(WglHGpuNv hGpu, WindowsUInt deviceIndex, WglGpuDevicePtr gpuDevice) noexcept;
    NODISCARD WindowsHdc SYSTEM_HIDDEN_DECLARE WglCreateAffinityDcNv(const WglHGpuNv* phGpuList) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglEnumGpusFromAffinityDcNv(WindowsHdc hAffinityDC, WindowsUInt gpuIndex, WglHGpuNv* hGpu) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglDeleteDcNv(WindowsHdc hdc) noexcept;

    /// WGL_NV_multigpu_context

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNvMultiGpuContext() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNvMultiGpuContext();

    /// WGL_NV_multisample_coverage

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNvMultiSampleCoverage() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNvMultiSampleCoverage();

    /// WGL_NV_present_video

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNvPresentVideo() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNvPresentVideo();

    NODISCARD int SYSTEM_HIDDEN_DECLARE WglEnumerateVideoDevicesNv(WindowsHdc hdc, WglHVideoOutputDeviceNv* phDeviceList) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglBindVideoDeviceNv(WindowsHdc hdc, unsigned int videoSlot, WglHVideoOutputDeviceNv videoDevice, const int* piAttribList) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglQueryCurrentContextNv(int attribute, int* piValue) noexcept;

    /// WGL_NV_render_depth_texture

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNvRenderDepthTexture() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNvRenderDepthTexture();

    /// WGL_NV_render_texture_rectangle

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNvRenderTextureRectangle() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNvRenderTextureRectangle();

    /// WGL_NV_swap_group

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNvSwapGroup() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNvSwapGroup();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglJoinSwapGroupNv(WindowsHdc hdc, GLuint group) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglBindSwapBarrierNv(GLuint group, GLuint barrier) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglQuerySwapGroupNv(WindowsHdc hdc, GLuint* group, GLuint* barrier) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglQueryMaxSwapGroupsNv(WindowsHdc hdc, GLuint* maxGroups, GLuint* maxBarriers) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglQueryFrameCountNv(WindowsHdc hdc, GLuint* count) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglResetFrameCountNv(WindowsHdc hdc) noexcept;

    /// WGL_NV_vertex_array_range

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNvVertexArrayRange() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNvVertexArrayRange();

    MAYBE_NULLPTR void* SYSTEM_HIDDEN_DECLARE WglAllocateMemoryNv(GLsizei size, GLfloat readFreq, GLfloat writeFreq, GLfloat priority) noexcept;
    void SYSTEM_HIDDEN_DECLARE WglFreeMemoryNv(void* pointer) noexcept;

    /// WGL_NV_video_capture

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNvVideoCapture() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNvVideoCapture();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglBindVideoCaptureDeviceNv(WindowsUInt videoSlot, WglHVideoInputDeviceNv hDevice) noexcept;
    NODISCARD WindowsUInt SYSTEM_HIDDEN_DECLARE WglEnumerateVideoCaptureDevicesNv(WindowsHdc hdc, WglHVideoInputDeviceNv* phDeviceList) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglLockVideoCaptureDeviceNv(WindowsHdc hdc, WglHVideoInputDeviceNv hDevice) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglQueryVideoCaptureDeviceNv(WindowsHdc hdc, WglHVideoInputDeviceNv hDevice, int attribute, int* piValue) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglReleaseVideoCaptureDeviceNv(WindowsHdc hdc, WglHVideoInputDeviceNv hDevice) noexcept;

    /// WGL_NV_video_output

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglNvVideoOutput() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglNvVideoOutput();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetVideoDeviceNv(WindowsHdc hdc, int numDevices, WglHpVideoDev* videoDevice) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglReleaseVideoDeviceNv(WglHpVideoDev videoDevice) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglBindVideoImageNv(WglHpVideoDev videoDevice, WglHpBufferArb hPBuffer, int videoBuffer) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglReleaseVideoImageNv(WglHpBufferArb hPBuffer, int videoBuffer) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglSendPBufferToVideoNv(WglHpBufferArb hPBuffer, int bufferType, unsigned long* pulCounterPBuffer, WindowsBool block) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetVideoInfoNv(WglHpVideoDev hpVideoDevice, unsigned long* pulCounterOutputPBuffer, unsigned long* pulCounterOutputVideo) noexcept;

    /// OML 扩展

    /// WGL_OML_sync_control

    NODISCARD SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsWglOMLSyncControl() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitWglOMLSyncControl();

    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetSyncValuesOML(WindowsHdc hdc, WindowsInt64* ust, WindowsInt64* msc, WindowsInt64* sbc) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglGetMscRateOML(WindowsHdc hdc, WindowsInt32* numerator, WindowsInt32* denominator) noexcept;
    NODISCARD WindowsInt64 SYSTEM_HIDDEN_DECLARE WglSwapBuffersMscOML(WindowsHdc hdc, WindowsInt64 targetMsc, WindowsInt64 divisor, WindowsInt64 remainder) noexcept;
    NODISCARD WindowsInt64 SYSTEM_HIDDEN_DECLARE WglSwapLayerBuffersMscOML(WindowsHdc hdc, WindowsInt fuPlanes, WindowsInt64 targetMsc, WindowsInt64 divisor, WindowsInt64 remainder) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglWaitForMscOML(WindowsHdc hdc, WindowsInt64 targetMsc, WindowsInt64 divisor, WindowsInt64 remainder, WindowsInt64* ust, WindowsInt64* msc, WindowsInt64* sbc) noexcept;
    NODISCARD WindowsBool SYSTEM_HIDDEN_DECLARE WglWaitForSbcOML(WindowsHdc hdc, WindowsInt64 targetSbc, WindowsInt64* ust, WindowsInt64* msc, WindowsInt64* sbc) noexcept;

    NODISCARD SYSTEM_HIDDEN_DECLARE bool InitWgl();
    MAYBE_NULLPTR SYSTEM_HIDDEN_DECLARE const char* GetWglExtensionString() noexcept;
    NODISCARD SYSTEM_HIDDEN_DECLARE bool SupportsWglExtension(const char* wglExtension);
}

#endif  // SYSTEM_OPENGL_WGL_EXTENSIONS_H
