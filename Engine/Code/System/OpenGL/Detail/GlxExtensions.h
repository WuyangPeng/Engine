// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:35)

#ifndef SYSTEM_OPENGL_GLX_EXT_EXTENSIONS_H
#define SYSTEM_OPENGL_GLX_EXT_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/OpenGL/Using/GlxExtensionsUsing.h" 
#include "System/OpenGL/Using/GL11ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GlxExtensionsMacro.h"

namespace System
{
	// GLX 1.0

	enum class ExistsOpenGLExtensions;

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlx10() noexcept;

	SYSTEM_HIDDEN_DECLARE GLXBool GlXQueryExtension(Display* display, int* errorBase, int* eventBase) noexcept;
	SYSTEM_HIDDEN_DECLARE GLXBool GlXQueryVersion(Display* display, int* major, int* minor) noexcept;
	SYSTEM_HIDDEN_DECLARE int GlXGetConfig(Display* display, XVisualInfo* visualInfo, int attribute, int* value) noexcept;
	SYSTEM_HIDDEN_DECLARE XVisualInfo* GlXChooseVisual(Display* display, int screen, int* attributeList) noexcept;
	SYSTEM_HIDDEN_DECLARE GLXPixmap GlXCreateGLXPixmap(Display* display, XVisualInfo* visualInfo, Pixmap pixmap) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlXDestroyGLXPixmap(Display* display, GLXPixmap pixmap) noexcept;
	SYSTEM_HIDDEN_DECLARE GLXContext GlXCreateContext(Display* display, XVisualInfo* visualInfo, GLXContext shareList, GLXBool direct) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlXDestroyContext(Display* display, GLXContext context) noexcept;
	SYSTEM_HIDDEN_DECLARE GLXBool GlXIsDirect(Display* display, GLXContext context) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlXCopyContext(Display* display, GLXContext srcContext, GLXContext dstContext, GLulong mask) noexcept;
	SYSTEM_HIDDEN_DECLARE GLXBool GlXMakeCurrent(Display* display, GLXDrawable drawable, GLXContext context) noexcept;
	SYSTEM_HIDDEN_DECLARE GLXContext GlXGetCurrentContext() noexcept;
	SYSTEM_HIDDEN_DECLARE GLXDrawable GlXGetCurrentDrawable() noexcept;
	SYSTEM_HIDDEN_DECLARE void GlXWaitGL() noexcept;
	SYSTEM_HIDDEN_DECLARE void GlXWaitX() noexcept;
	SYSTEM_HIDDEN_DECLARE void GlXSwapBuffers(Display* display, GLXDrawable drawable) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlXUseXFont(Font font, int first, int count, int listBase) noexcept;

	// GLX 1.1
	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlx11() noexcept;

	SYSTEM_HIDDEN_DECLARE const char* GlXQueryExtensionsString(Display* display, int screen) noexcept;
	SYSTEM_HIDDEN_DECLARE const char* GlXGetClientString(Display* display, int name) noexcept;
	SYSTEM_HIDDEN_DECLARE const char* GlXQueryServerString(Display* display, int screen, int name) noexcept;

	// GLX 1.2
	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlx12() noexcept;

	SYSTEM_HIDDEN_DECLARE Display* GlXGetCurrentDisplay() noexcept;

	// GLX 1.3

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlx13() noexcept;

	SYSTEM_HIDDEN_DECLARE GLXFBConfig* GlXGetFBConfigs(Display* display, int screen, int* numElements) noexcept;
	SYSTEM_HIDDEN_DECLARE GLXFBConfig* GlXChooseFBConfig(Display* display, int screen, const int* attributeList, int* numElements) noexcept;
	SYSTEM_HIDDEN_DECLARE int GlXGetFBConfigAttrib(Display* display, GLXFBConfig config, int attribute, int* value) noexcept;
	SYSTEM_HIDDEN_DECLARE XVisualInfo* GlXGetVisualFromFBConfig(Display* display, GLXFBConfig config) noexcept;
	SYSTEM_HIDDEN_DECLARE GLXWindow GlXCreateWindow(Display* display, GLXFBConfig config, Window window, const int* attributeList) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlXDestroyWindow(Display* display, GLXWindow window) noexcept;
	SYSTEM_HIDDEN_DECLARE GLXPixmap GlXCreatePixmap(Display* display, GLXFBConfig config, Pixmap pixmap, const int* attributeList) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlXDestroyPixmap(Display* display, GLXPixmap pixmap) noexcept;
	SYSTEM_HIDDEN_DECLARE GLXPbuffer GlXCreatePbuffer(Display* display, GLXFBConfig config, const int* attributeList) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlXDestroyPbuffer(Display* display, GLXPbuffer buffer) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlXQueryDrawable(Display* display, GLXDrawable drawable, int attribute, unsigned int* value) noexcept;
	SYSTEM_HIDDEN_DECLARE GLXContext GlXCreateNewContext(Display* display, GLXFBConfig config, int renderType, GLXContext shareList, GLXBool direct) noexcept;
	SYSTEM_HIDDEN_DECLARE GLXBool GlXMakeContextCurrent(Display* display, GLXDrawable draw, GLXDrawable read, GLXContext context) noexcept;
	SYSTEM_HIDDEN_DECLARE GLXDrawable GlXGetCurrentReadDrawable() noexcept;
	SYSTEM_HIDDEN_DECLARE int GlXQueryContext(Display* display, GLXContext context, int attribute, int* value) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlXSelectEvent(Display* display, GLXDrawable drawable, unsigned long eventMask) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlXGetSelectedEvent(Display* display, GLXDrawable drawable, unsigned long* eventMask) noexcept;

	// GLX 1.4

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlx14() noexcept;

	// ARB ¿©’π

	// (ARB 02) GLX_ARB_get_proc_address

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxArbGetProcAddress() noexcept;

	// (ARB 05) GLX_ARB_multisample    

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxArbMultisample() noexcept;

	// (ARB 28) GLX_ARB_vertex_buffer_object

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxArbVertexBufferObject() noexcept;


	// (ARB 39) GLX_ARB_fbconfig_float

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxArbFBConfigFloat() noexcept;


	// (ARB 46) GLX_ARB_framebuffer_sRGB

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxArbFramebufferSRGB() noexcept;

	// (ARB 56) GLX_ARB_create_context

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxArbCreateContext() noexcept;

	SYSTEM_HIDDEN_DECLARE GLXContext GlXCreateContextAttribsARB(Display* dpy, GLXFBConfig config, GLXContext shareContext, GLXBool direct, const int* attribList) noexcept;


	// (ARB 75) GLX_ARB_create_context_profile

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxArbCreateContextProfile() noexcept;

	// (ARB 101) GLX_ARB_create_context_robustness

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxArbCreateContextRobustness() noexcept;

	// (ARB 142) GLX_ARB_robustness_application_isolation

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxArbRobustnessApplicationIsolation() noexcept;

	// (ARB 142) GLX_ARB_robustness_share_group_isolation

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxArbRobustnessShareGroupIsolation() noexcept;

	// (ARB 168) GLX_ARB_context_flush_control

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxArbContextFlushControl() noexcept;

	// EXT ¿©’π

	// (EXT 028) GLX_EXT_visual_info

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxExtVisualInfo() noexcept;


	// (EXT 040) GLX_EXT_swap_control

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxExtSwapControl() noexcept;

	SYSTEM_HIDDEN_DECLARE void GlXSwapIntervalEXT(Display* dpy, GLXDrawable drawable, int interval) noexcept;

	// (EXT 044) GLX_EXT_visual_rating

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxExtVisualRating() noexcept;

	// (EXT 047) GLX_EXT_import_context

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxExtImportContext() noexcept;

	SYSTEM_HIDDEN_DECLARE Display* GlXGetCurrentDisplayEXT() noexcept;
	SYSTEM_HIDDEN_DECLARE int GlXQueryContextInfoEXT(Display* display, GLXContext context, int attribute, int* value) noexcept;
	SYSTEM_HIDDEN_DECLARE GLXContextID GlXGetContextIDEXT(const GLXContext context) noexcept;
	SYSTEM_HIDDEN_DECLARE GLXContext GlXImportContextEXT(Display* display, GLXContextID contextID) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlXFreeContextEXT(Display* display, GLXContext context) noexcept;


	// (EXT 120) GLX_EXT_scene_marker

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxExtSceneMarker() noexcept;

	// (EXT 328) GLX_EXT_fbconfig_packed_float

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxExtFbconfigPackedFloat() noexcept;

	// (EXT 337) GLX_EXT_framebuffer_sRGB

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxExtFramebufferSRGB() noexcept;

	// (EXT 344) GLX_EXT_texture_from_pixmap

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxExtTextureFromPixmap() noexcept;

	SYSTEM_HIDDEN_DECLARE void GlXBindTexImageEXT(Display* display, GLXDrawable drawable, int buffer, const int* attribList) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlXReleaseTexImageEXT(Display* display, GLXDrawable drawable, int buffer) noexcept;

	// (EXT 399) GLX_EXT_create_context_es2_profile

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxExtCreateContextEs2Profile() noexcept;

	// (EXT 399) GLX_EXT_create_context_es_profile

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxExtCreateContextEsProfile() noexcept;

	// (EXT 414) GLX_EXT_swap_control_tear

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxExtSwapControlTear() noexcept;

	// (EXT 427) GLX_EXT_buffer_age

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxExtBufferAge() noexcept;

	// (EXT 452) GLX_EXT_stereo_tree

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxExtStereoTree() noexcept;

	// SGIX¿©’π

	// (SGIX 49) GLX_SGIX_fbconfig    

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxSgixFBConfig() noexcept;

	SYSTEM_HIDDEN_DECLARE int GlXGetFBConfigAttribSGIX(Display* display, GLXFBConfigSGIX config, int attribute, int* value) noexcept;
	SYSTEM_HIDDEN_DECLARE GLXFBConfigSGIX* GlXChooseFBConfigSGIX(Display* display, int screen, int* attributeList, int* numElements) noexcept;
	SYSTEM_HIDDEN_DECLARE GLXPixmap GlXCreateGLXPixmapWithConfigSGIX(Display* display, GLXFBConfigSGIX config, Pixmap pixmap) noexcept;
	SYSTEM_HIDDEN_DECLARE GLXContext GlXCreateContextWithConfigSGIX(Display* display, GLXFBConfigSGIX config, int renderType, GLXContext shareList, GLXBool direct) noexcept;
	SYSTEM_HIDDEN_DECLARE XVisualInfo* GlXGetVisualFromFBConfigSGIX(Display* display, GLXFBConfigSGIX config) noexcept;
	SYSTEM_HIDDEN_DECLARE GLXFBConfigSGIX GlXGetFBConfigFromVisualSGIX(Display* display, XVisualInfo* visualInfo) noexcept;

	// (SGIX 50) GLX_SGIX_pbuffer    

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxSgixPBuffer() noexcept;

	SYSTEM_HIDDEN_DECLARE GLXPbufferSGIX GlXCreateGLXPbufferSGIX(Display* display, GLXFBConfigSGIX config, unsigned int width, unsigned int height, int* attributeList) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlXDestroyGLXPbufferSGIX(Display* display, GLXPbufferSGIX buffer) noexcept;
	SYSTEM_HIDDEN_DECLARE int GlXQueryGLXPbufferSGIX(Display* display, GLXPbufferSGIX buffer, int attribute, unsigned int* value) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlXSelectEventSGIX(Display* display, GLXDrawable drawable, unsigned long mask) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlXGetSelectedEventSGIX(Display* display, GLXDrawable drawable, unsigned long* mask) noexcept;

	// (SGIX 83)  GLX_SGIX_video_resize

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxSgixVideoResize() noexcept;

	SYSTEM_HIDDEN_DECLARE int GlXBindChannelToWindowSGIX(Display* display, int screen, int channel, Window window) noexcept;
	SYSTEM_HIDDEN_DECLARE int GlXChannelRectSGIX(Display* display, int screen, int channel, int x, int y, int w, int h) noexcept;
	SYSTEM_HIDDEN_DECLARE int GlXChannelRectSyncSGIX(Display* display, int screen, int channel, GLenum synctype) noexcept;
	SYSTEM_HIDDEN_DECLARE int GlXQueryChannelDeltasSGIX(Display* display, int screen, int channel, int* x, int* y, int* w, int* h) noexcept;
	SYSTEM_HIDDEN_DECLARE int GlXQueryChannelRectSGIX(Display* display, int screen, int channel, int* dx, int* dy, int* dw, int* dh) noexcept;

	// (SGIX 91) GLX_SGIX_swap_group
	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxSgixSwapGroup() noexcept;

	SYSTEM_HIDDEN_DECLARE void GlXJoinSwapGroupSGIX(Display* dpy, GLXDrawable drawable, GLXDrawable member) noexcept;


	// (SGIX 92) GLX_SGIX_swap_barrier

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxSgixSwapBarrier() noexcept;

	SYSTEM_HIDDEN_DECLARE void GlXBindSwapBarrierSGIX(Display*  dpy, GLXDrawable drawable, int barrier) noexcept;

	SYSTEM_HIDDEN_DECLARE GLXBool GlXQueryMaxSwapBarriersSGIX(Display* dpy, int screen, int* max) noexcept;

	// (SGIX 234) GLX_SGIX_visual_select_group

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxSgixVisualSelectGroup() noexcept;

	// (SGIX 307) GLX_SGIX_hyperpipe

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlxSgixHyperpipe() noexcept;

	SYSTEM_HIDDEN_DECLARE int GlXBindHyperpipeSGIX(Display* dpy, int hpID) noexcept;
	SYSTEM_HIDDEN_DECLARE int GlXDestroyHyperpipeConfigSGIX(Display* dpy, int hpID) noexcept;
	SYSTEM_HIDDEN_DECLARE int GlXHyperpipeAttribSGIX(Display* dpy, int timeSlice, int attrib, int size, void* attribList) noexcept;
	SYSTEM_HIDDEN_DECLARE int GlXHyperpipeConfigSGIX(Display* dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX* cfg, int* hpID) noexcept;
	SYSTEM_HIDDEN_DECLARE int GlXQueryHyperpipeAttribSGIX(Display* dpy, int timeSlice, int attrib, int size, void* returnAttribList) noexcept;
	SYSTEM_HIDDEN_DECLARE int GlXQueryHyperpipeBestAttribSGIX(Display* dpy, int timeSlice, int attrib, int size, void* attribList, void* returnAttribList) noexcept;
	SYSTEM_HIDDEN_DECLARE GLXHyperpipeConfigSGIX* GlXQueryHyperpipeConfigSGIX(Display* dpy, int hpID, int* npipes) noexcept;
	SYSTEM_HIDDEN_DECLARE GLXHyperpipeNetworkSGIX* GlXQueryHyperpipeNetworkSGIX(Display* dpy, int* npipes) noexcept;


	SYSTEM_HIDDEN_DECLARE bool InitGLX(bool printInfo = true) noexcept;

	SYSTEM_HIDDEN_DECLARE void InitGlxArbGetProcAddress() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxArbGetMultisample() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxArbVertexBufferObject() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxArbFBConfigFloat() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxArbFramebufferSRGB() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxArbCreateContext() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxArbCreateContextProfile() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxArbCreateContextRobustness() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxArbRobustnessApplicationIsolation() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxArbRobustnessShareGroupIsolation() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxArbContextFlushControl() noexcept;

	SYSTEM_HIDDEN_DECLARE void InitGlxExtVisualInfo() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxExtSwapControl() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxExtVisualRating() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxExtImportContext() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxExtSceneMarker() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxExtFbconfigPackedFloat() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxExtFramebufferSRGB() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxExtTextureFromPixmap() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxExtCreateContextEs2Profile() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxExtCreateContextEsProfile() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxExtSwapControlTear() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxExtBufferAge() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxExtStereoTree() noexcept;

	SYSTEM_HIDDEN_DECLARE void InitGlxSgixFBConfig() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxSgixPBuffer() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxSgixVideoResize() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxSgixSwapGroup() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxSgixSwapBarrier() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxSgixVisualSelectGroup() noexcept;
	SYSTEM_HIDDEN_DECLARE void InitGlxSgixHyperpipe() noexcept;
}

#endif // SYSTEM_OPENGL_GLX_EXT_EXTENSIONS_H
