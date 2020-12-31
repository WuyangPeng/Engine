//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 17:50)

#ifndef SYSTEM_HELPER_GLX_EXTENSIONS_MACRO_H
#define SYSTEM_HELPER_GLX_EXTENSIONS_MACRO_H

#include "System/Helper/GLExtensionsMacro.h"

#if defined(SYSTEM_PLATFORM_LINUX)

    #ifdef __glxext_h_
        #error "glxext.h包含在GLExtensionsMacro.h之前"
    #endif  // __glxext_h_

    #define __glxext_h_

    #include <X11/Xlib.h>
    #include <X11/Xutil.h>
    #include <X11/Xmd.h>

#endif  // SYSTEM_PLATFORM_LINUX

// GLX 1.0

#define GLX_USE_GL 1
#define GLX_BUFFER_SIZE 2
#define GLX_LEVEL 3
#define GLX_RGBA 4
#define GLX_DOUBLEBUFFER 5
#define GLX_STEREO 6
#define GLX_AUX_BUFFERS 7
#define GLX_RED_SIZE 8
#define GLX_GREEN_SIZE 9
#define GLX_BLUE_SIZE 10
#define GLX_ALPHA_SIZE 11
#define GLX_DEPTH_SIZE 12
#define GLX_STENCIL_SIZE 13
#define GLX_ACCUM_RED_SIZE 14
#define GLX_ACCUM_GREEN_SIZE 15
#define GLX_ACCUM_BLUE_SIZE 16
#define GLX_ACCUM_ALPHA_SIZE 17
#define GLX_BAD_SCREEN 1
#define GLX_BAD_ATTRIBUTE 2
#define GLX_NO_EXTENSION 3
#define GLX_BAD_VISUAL 4
#define GLX_BAD_CONTEXT 5
#define GLX_BAD_VALUE 6
#define GLX_BAD_ENUM 7

#define glXQueryExtension System::GlXQueryExtension
#define glXQueryVersion System::GlXQueryVersion
#define glXGetConfig System::GlXGetConfig
#define glXChooseVisual System::GlXChooseVisual
#define glXCreateGLXPixmap System::GlXCreateGLXPixmap
#define glXDestroyGLXPixmap System::GlXDestroyGLXPixmap
#define glXCreateContext System::GlXCreateContext
#define glXDestroyContext System::GlXDestroyContext
#define glXIsDirect System::GlXIsDirect
#define glXCopyContext System::GlXCopyContext
#define glXMakeCurrent System::GlXMakeCurrent
#define glXGetCurrentContext System::GlXGetCurrentContext
#define glXGetCurrentDrawable System::GlXGetCurrentDrawable
#define glXWaitGL System::GlXWaitGL
#define glXWaitX System::GlXWaitX
#define glXSwapBuffers System::GlXSwapBuffers
#define glXUseXFont System::GlXUseXFont

// GLX 1.1

#define GLX_VENDOR 1
#define GLX_VERSION 2
#define GLX_EXTENSIONS 3

#define glXQueryExtensionsString System::GlXQueryExtensionsString
#define glXGetClientString System::GlXGetClientString
#define glXQueryServerString System::GlXQueryServerString

// GLX 1.2
#define glXGetCurrentDisplay System::GlXGetCurrentDisplay

// GLX 1.3
#define GLX_WINDOW_BIT 0x00000001
#define GLX_PIXMAP_BIT 0x00000002
#define GLX_PBUFFER_BIT 0x00000004
#define GLX_RGBA_BIT 0x00000001
#define GLX_COLOR_INDEX_BIT 0x00000002
#define GLX_PBUFFER_CLOBBER_MASK 0x08000000
#define GLX_FRONT_LEFT_BUFFER_BIT 0x00000001
#define GLX_FRONT_RIGHT_BUFFER_BIT 0x00000002
#define GLX_BACK_LEFT_BUFFER_BIT 0x00000004
#define GLX_BACK_RIGHT_BUFFER_BIT 0x00000008
#define GLX_AUX_BUFFERS_BIT 0x00000010
#define GLX_DEPTH_BUFFER_BIT 0x00000020
#define GLX_STENCIL_BUFFER_BIT 0x00000040
#define GLX_ACCUM_BUFFER_BIT 0x00000080
#define GLX_CONFIG_CAVEAT 0x20
#define GLX_X_VISUAL_TYPE 0x22
#define GLX_TRANSPARENT_TYPE 0x23
#define GLX_TRANSPARENT_INDEX_VALUE 0x24
#define GLX_TRANSPARENT_RED_VALUE 0x25
#define GLX_TRANSPARENT_GREEN_VALUE 0x26
#define GLX_TRANSPARENT_BLUE_VALUE 0x27
#define GLX_TRANSPARENT_ALPHA_VALUE 0x28
#define GLX_DONT_CARE 0xFFFFFFFF
#define GLX_NONE 0x8000
#define GLX_SLOW_CONFIG 0x8001
#define GLX_TRUE_COLOR 0x8002
#define GLX_DIRECT_COLOR 0x8003
#define GLX_PSEUDO_COLOR 0x8004
#define GLX_STATIC_COLOR 0x8005
#define GLX_GRAY_SCALE 0x8006
#define GLX_STATIC_GRAY 0x8007
#define GLX_TRANSPARENT_RGB 0x8008
#define GLX_TRANSPARENT_INDEX 0x8009
#define GLX_VISUAL_ID 0x800B
#define GLX_SCREEN 0x800C
#define GLX_NON_CONFORMANT_CONFIG 0x800D
#define GLX_DRAWABLE_TYPE 0x8010
#define GLX_RENDER_TYPE 0x8011
#define GLX_X_RENDERABLE 0x8012
#define GLX_FBCONFIG_ID 0x8013
#define GLX_RGBA_TYPE 0x8014
#define GLX_COLOR_INDEX_TYPE 0x8015
#define GLX_MAX_PBUFFER_WIDTH 0x8016
#define GLX_MAX_PBUFFER_HEIGHT 0x8017
#define GLX_MAX_PBUFFER_PIXELS 0x8018
#define GLX_PRESERVED_CONTENTS 0x801B
#define GLX_LARGEST_PBUFFER 0x801C
#define GLX_WIDTH 0x801D
#define GLX_HEIGHT 0x801E
#define GLX_EVENT_MASK 0x801F
#define GLX_DAMAGED 0x8020
#define GLX_SAVED 0x8021
#define GLX_WINDOW 0x8022
#define GLX_PBUFFER 0x8023
#define GLX_PBUFFER_HEIGHT 0x8040
#define GLX_PBUFFER_WIDTH 0x8041

#define glXGetFBConfigs System::GlXGetFBConfigs
#define glXChooseFBConfig System::GlXChooseFBConfig
#define glXGetFBConfigAttrib System::GlXGetFBConfigAttrib
#define glXGetVisualFromFBConfig System::GlXGetVisualFromFBConfig
#define glXCreateWindow System::GlXCreateWindow
#define glXDestroyWindow System::GlXDestroyWindow
#define glXCreatePixmap System::GlXCreatePixmap
#define glXDestroyPixmap System::GlXDestroyPixmap
#define glXCreatePbuffer System::GlXCreatePbuffer
#define glXDestroyPbuffer System::GlXDestroyPbuffer
#define glXQueryDrawable System::GlXQueryDrawable
#define glXCreateNewContext System::GlXCreateNewContext
#define glXMakeContextCurrent System::GlXMakeContextCurrent
#define glXGetCurrentReadDrawable System::GlXGetCurrentReadDrawable
#define glXQueryContext System::GlXQueryContext
#define glXSelectEvent System::GlXSelectEvent
#define glXGetSelectedEvent System::GlXGetSelectedEvent

// GLX 1.4

#define GLX_SAMPLE_BUFFERS 100000
#define GLX_SAMPLES 100001

// ARB 扩展

// (ARB 05) GLX_ARB_multisample

#define GLX_SAMPLE_BUFFERS_ARB 100000
#define GLX_SAMPLES_ARB 100001

// (ARB 28) GLX_ARB_vertex_buffer_object

#define GLX_CONTEXT_ALLOW_BUFFER_BYTE_ORDER_MISMATCH_ARB 0x2095

// (ARB 39) GLX_ARB_fbconfig_float

#define GLX_RGBA_FLOAT_TYPE_ARB 0x20B9
#define GLX_RGBA_FLOAT_BIT_ARB 0x00000004

// (ARB 46) GLX_ARB_framebuffer_sRGB

#define GLX_FRAMEBUFFER_SRGB_CAPABLE_ARB 0x20B2

// (ARB 56) GLX_ARB_create_context

#define GLX_CONTEXT_DEBUG_BIT_ARB 0x0001
#define GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB 0x0002
#define GLX_CONTEXT_MAJOR_VERSION_ARB 0x2091
#define GLX_CONTEXT_MINOR_VERSION_ARB 0x2092
#define GLX_CONTEXT_FLAGS_ARB 0x2094

#define glXCreateContextAttribsARB System::GlXCreateContextAttribsARB

// (ARB 75) GLX_ARB_create_context_profile

#define GLX_CONTEXT_CORE_PROFILE_BIT_ARB 0x00000001
#define GLX_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002
#define GLX_CONTEXT_PROFILE_MASK_ARB 0x9126

// (ARB 101) GLX_ARB_create_context_robustness

#define GLX_CONTEXT_ROBUST_ACCESS_BIT_ARB 0x00000004
#define GLX_LOSE_CONTEXT_ON_RESET_ARB 0x8252
#define GLX_CONTEXT_RESET_NOTIFICATION_STRATEGY_ARB 0x8256
#define GLX_NO_RESET_NOTIFICATION_ARB 0x8261

// (ARB 142) GLX_ARB_robustness_application_isolation

#define GLX_CONTEXT_RESET_ISOLATION_BIT_ARB 0x00000008

// (ARB 168) GLX_ARB_context_flush_control

#define GLX_CONTEXT_RELEASE_BEHAVIOR_NONE_ARB 0x0000
#define GLX_CONTEXT_RELEASE_BEHAVIOR_ARB 0x2097
#define GLX_CONTEXT_RELEASE_BEHAVIOR_FLUSH_ARB 0x2098

// EXT 扩展

// (EXT 028) GLX_EXT_visual_info

#define GLX_X_VISUAL_TYPE_EXT 0x22
#define GLX_TRANSPARENT_TYPE_EXT 0x23
#define GLX_TRANSPARENT_INDEX_VALUE_EXT 0x24
#define GLX_TRANSPARENT_RED_VALUE_EXT 0x25
#define GLX_TRANSPARENT_GREEN_VALUE_EXT 0x26
#define GLX_TRANSPARENT_BLUE_VALUE_EXT 0x27
#define GLX_TRANSPARENT_ALPHA_VALUE_EXT 0x28
#define GLX_NONE_EXT 0x8000
#define GLX_TRUE_COLOR_EXT 0x8002
#define GLX_DIRECT_COLOR_EXT 0x8003
#define GLX_PSEUDO_COLOR_EXT 0x8004
#define GLX_STATIC_COLOR_EXT 0x8005
#define GLX_GRAY_SCALE_EXT 0x8006
#define GLX_STATIC_GRAY_EXT 0x8007
#define GLX_TRANSPARENT_RGB_EXT 0x8008
#define GLX_TRANSPARENT_INDEX_EXT 0x8009

// (EXT 040) GLX_EXT_swap_control

#define GLX_SWAP_INTERVAL_EXT 0x20F1
#define GLX_MAX_SWAP_INTERVAL_EXT 0x20F2

#define glXSwapIntervalEXT System::GlXSwapIntervalEXT

// (EXT 044) GLX_EXT_visual_rating

#define GLX_VISUAL_CAVEAT_EXT 0x20
#define GLX_SLOW_VISUAL_EXT 0x8001
#define GLX_NON_CONFORMANT_VISUAL_EXT 0x800D

// (EXT 047) GLX_EXT_import_context

#define GLX_SHARE_CONTEXT_EXT 0x800A
#define GLX_VISUAL_ID_EXT 0x800B
#define GLX_SCREEN_EXT 0x800C

#define glXGetCurrentDisplayEXT System::GlXGetCurrentDisplayEXT
#define glXQueryContextInfoEXT System::GlXQueryContextInfoEXT
#define glXGetContextIDEXT System::GlXGetContextIDEXT
#define glXImportContextEXT System::GlXImportContextEXT
#define glXFreeContextEXT System::GlXFreeContextEXT

// (EXT 328) GLX_EXT_fbconfig_packed_float

#define GLX_RGBA_UNSIGNED_FLOAT_BIT_EXT 0x00000008
#define GLX_RGBA_UNSIGNED_FLOAT_TYPE_EXT 0x20B1

// (EXT 337) GLX_EXT_framebuffer_sRGB

#define GLX_FRAMEBUFFER_SRGB_CAPABLE_EXT 0x20B2

// (EXT 344) GLX_EXT_texture_from_pixmap

#define GLX_TEXTURE_1D_BIT_EXT 0x00000001
#define GLX_TEXTURE_2D_BIT_EXT 0x00000002
#define GLX_TEXTURE_RECTANGLE_BIT_EXT 0x00000004
#define GLX_BIND_TO_TEXTURE_RGB_EXT 0x20D0
#define GLX_BIND_TO_TEXTURE_RGBA_EXT 0x20D1
#define GLX_BIND_TO_MIPMAP_TEXTURE_EXT 0x20D2
#define GLX_BIND_TO_TEXTURE_TARGETS_EXT 0x20D3
#define GLX_Y_INVERTED_EXT 0x20D4
#define GLX_TEXTURE_FORMAT_EXT 0x20D5
#define GLX_TEXTURE_TARGET_EXT 0x20D6
#define GLX_MIPMAP_TEXTURE_EXT 0x20D7
#define GLX_TEXTURE_FORMAT_NONE_EXT 0x20D8
#define GLX_TEXTURE_FORMAT_RGB_EXT 0x20D9
#define GLX_TEXTURE_FORMAT_RGBA_EXT 0x20DA
#define GLX_TEXTURE_1D_EXT 0x20DB
#define GLX_TEXTURE_2D_EXT 0x20DC
#define GLX_TEXTURE_RECTANGLE_EXT 0x20DD
#define GLX_FRONT_LEFT_EXT 0x20DE
#define GLX_FRONT_RIGHT_EXT 0x20DF
#define GLX_BACK_LEFT_EXT 0x20E0
#define GLX_BACK_RIGHT_EXT 0x20E1
#define GLX_AUX0_EXT 0x20E2
#define GLX_AUX1_EXT 0x20E3
#define GLX_AUX2_EXT 0x20E4
#define GLX_AUX3_EXT 0x20E5
#define GLX_AUX4_EXT 0x20E6
#define GLX_AUX5_EXT 0x20E7
#define GLX_AUX6_EXT 0x20E8
#define GLX_AUX7_EXT 0x20E9
#define GLX_AUX8_EXT 0x20EA
#define GLX_AUX9_EXT 0x20EB

#define glXBindTexImageEXT System::GlXBindTexImageEXT
#define glXReleaseTexImageEXT System::GlXReleaseTexImageEXT

// (EXT 399) GLX_EXT_create_context_es2_profile

#define GLX_CONTEXT_ES2_PROFILE_BIT_EXT 0x00000004

// (EXT 399) GLX_EXT_create_context_es_profile

#define GLX_CONTEXT_ES_PROFILE_BIT_EXT 0x00000004

// (EXT 414) GLX_EXT_swap_control_tear

#define GLX_LATE_SWAPS_TEAR_EXT 0x20F3

// (EXT 427) GLX_EXT_buffer_age
#define GLX_BACK_BUFFER_AGE_EXT 0x20F4

// (EXT 452) GLX_EXT_stereo_tree

#define GLX_STEREO_NOTIFY_EXT 0x00000000
#define GLX_STEREO_NOTIFY_MASK_EXT 0x00000001
#define GLX_STEREO_TREE_EXT 0x20F5

// SGIX扩展

// (SGIX 49) GLX_SGIX_fbconfig

#define GLX_WINDOW_BIT_SGIX 0x00000001
#define GLX_PIXMAP_BIT_SGIX 0x00000002
#define GLX_RGBA_BIT_SGIX 0x00000001
#define GLX_COLOR_INDEX_BIT_SGIX 0x00000002
#define GLX_DRAWABLE_TYPE_SGIX 0x8010
#define GLX_RENDER_TYPE_SGIX 0x8011
#define GLX_X_RENDERABLE_SGIX 0x8012
#define GLX_FBCONFIG_ID_SGIX 0x8013
#define GLX_RGBA_TYPE_SGIX 0x8014
#define GLX_COLOR_INDEX_TYPE_SGIX 0x8015

#define glXGetFBConfigAttribSGIX System::GlXGetFBConfigAttribSGIX
#define glXChooseFBConfigSGIX System::GlXChooseFBConfigSGIX
#define glXCreateGLXPixmapWithConfigSGIX System::GlXCreateGLXPixmapWithConfigSGIX
#define glXCreateContextWithConfigSGIX System::GlXCreateContextWithConfigSGIX
#define glXGetVisualFromFBConfigSGIX System::GlXGetVisualFromFBConfigSGIX
#define glXGetFBConfigFromVisualSGIX System::GlXGetFBConfigFromVisualSGIX

// (SGIX 50) GLX_SGIX_pbuffer

#define GLX_PBUFFER_BIT_SGIX 0x00000004
#define GLX_BUFFER_CLOBBER_MASK_SGIX 0x08000000
#define GLX_FRONT_LEFT_BUFFER_BIT_SGIX 0x00000001
#define GLX_FRONT_RIGHT_BUFFER_BIT_SGIX 0x00000002
#define GLX_BACK_LEFT_BUFFER_BIT_SGIX 0x00000004
#define GLX_BACK_RIGHT_BUFFER_BIT_SGIX 0x00000008
#define GLX_AUX_BUFFERS_BIT_SGIX 0x00000010
#define GLX_DEPTH_BUFFER_BIT_SGIX 0x00000020
#define GLX_STENCIL_BUFFER_BIT_SGIX 0x00000040
#define GLX_ACCUM_BUFFER_BIT_SGIX 0x00000080
#define GLX_SAMPLE_BUFFERS_BIT_SGIX 0x00000100
#define GLX_MAX_PBUFFER_WIDTH_SGIX 0x8016
#define GLX_MAX_PBUFFER_HEIGHT_SGIX 0x8017
#define GLX_MAX_PBUFFER_PIXELS_SGIX 0x8018
#define GLX_OPTIMAL_PBUFFER_WIDTH_SGIX 0x8019
#define GLX_OPTIMAL_PBUFFER_HEIGHT_SGIX 0x801A
#define GLX_PRESERVED_CONTENTS_SGIX 0x801B
#define GLX_LARGEST_PBUFFER_SGIX 0x801C
#define GLX_WIDTH_SGIX 0x801D
#define GLX_HEIGHT_SGIX 0x801E
#define GLX_EVENT_MASK_SGIX 0x801F
#define GLX_DAMAGED_SGIX 0x8020
#define GLX_SAVED_SGIX 0x8021
#define GLX_WINDOW_SGIX 0x8022
#define GLX_PBUFFER_SGIX 0x8023

#define glXCreateGLXPbufferSGIX System::GlXCreateGLXPbufferSGIX
#define glXDestroyGLXPbufferSGIX System::GlXDestroyGLXPbufferSGIX
#define glXQueryGLXPbufferSGIX System::GlXQueryGLXPbufferSGIX
#define glXSelectEventSGIX System::GlXSelectEventSGIX
#define glXGetSelectedEventSGIX System::GlXGetSelectedEventSGIX

// (SGIX 83) GLX_SGIX_video_resize

#define GLX_SYNC_FRAME_SGIX 0x00000000
#define GLX_SYNC_SWAP_SGIX 0x00000001

#define glXBindChannelToWindowSGIX System::GlXBindChannelToWindowSGIX
#define glXChannelRectSGIX System::GlXChannelRectSGIX
#define glXChannelRectSyncSGIX System::GlXChannelRectSyncSGIX
#define glXQueryChannelDeltasSGIX System::GlXQueryChannelDeltasSGIX
#define glXQueryChannelRectSGIX System::GlXQueryChannelRectSGIX

// (SGIX 91) GLX_SGIX_swap_group

#define glXJoinSwapGroupSGIX System::GlXJoinSwapGroupSGIX

// (SGIX 92) GLX_SGIX_swap_barrier

#define glXBindSwapBarrierSGIX System::GlXBindSwapBarrierSGIX
#define glXQueryMaxSwapBarriersSGIX System::GlXQueryMaxSwapBarriersSGIX

// (SGIX 234) GLX_SGIX_visual_select_group

#define GLX_VISUAL_SELECT_GROUP_SGIX 0x8028

// (SGIX 307) GLX_SGIX_hyperpipe

#define GLX_HYPERPIPE_DISPLAY_PIPE_SGIX 0x00000001
#define GLX_PIPE_RECT_SGIX 0x00000001
#define GLX_HYPERPIPE_RENDER_PIPE_SGIX 0x00000002
#define GLX_PIPE_RECT_LIMITS_SGIX 0x00000002
#define GLX_HYPERPIPE_STEREO_SGIX 0x00000003
#define GLX_HYPERPIPE_PIXEL_AVERAGE_SGIX 0x00000004
#define GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX 80
#define GLX_BAD_HYPERPIPE_CONFIG_SGIX 91
#define GLX_BAD_HYPERPIPE_SGIX 92
#define GLX_HYPERPIPE_ID_SGIX 0x8030

#define glXBindHyperpipeSGIX System::GlXBindHyperpipeSGIX
#define glXDestroyHyperpipeConfigSGIX System::GlXDestroyHyperpipeConfigSGIX
#define glXHyperpipeAttribSGIX System::GlXHyperpipeAttribSGIX
#define glXHyperpipeConfigSGIX System::GlXHyperpipeConfigSGIX
#define glXQueryHyperpipeAttribSGIX System::GlXQueryHyperpipeAttribSGIX
#define glXQueryHyperpipeBestAttribSGIX System::GlXQueryHyperpipeBestAttribSGIX
#define glXQueryHyperpipeConfigSGIX System::GlXQueryHyperpipeConfigSGIX
#define glXQueryHyperpipeNetworkSGIX System::GlXQueryHyperpipeNetworkSGIX

#endif  // SYSTEM_HELPER_GLX_EXTENSIONS_MACRO_H
