// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/07 23:36)

#ifndef SYSTEM_HELPER_GLX_FLAGS_H
#define SYSTEM_HELPER_GLX_FLAGS_H

#include "System/Helper/UserMacro.h"

namespace System
{
	enum class GLX10
	{
		QueryExtension,
		QueryVersion,
		GetConfig,
		ChooseVisual,
		CreateGLXPixmap,
		DestroyGLXPixmap,
		CreateContext,
		DestroyContext,
		IsDirect,
		CopyContext,
		MakeCurrent,
		GetCurrentContext,
		GetCurrentDrawable,
		WaitGL,
		WaitX,
		SwapBuffers,
		UseXFont
	};

	enum class GLX11
	{
		QueryExtensionsString,
		GetClientString,
		QueryServerString
	};

	enum class GLX12
	{
		GetCurrentDisplay,
	};

	enum class GLX13
	{
		GetFBConfigs,
		ChooseFBConfig,
		GetFBConfigAttrib,
		GetVisualFromFBConfig,
		CreateWindow,
		DestroyWindow,
		CreatePixmap,
		DestroyPixmap,
		CreatePbuffer,
		DestroyPbuffer,
		QueryDrawable,
		CreateNewContext,
		MakeContextCurrent,
		GetCurrentReadDrawable,
		QueryContext,
		SelectEvent,
		GetSelectedEvent
	};

	enum class GLXARBCreateContext
	{
		CreateContextAttribsARB,
	};

	enum class GLXEXTSwapControl
	{
		SwapIntervalEXT,
	};

	enum class GLXEXTImportContext
	{
		GetCurrentDisplayEXT,
		QueryContextInfoEXT,
		GetContextIDEXT,
		ImportContextEXT,
		FreeContextEXT
	};

	enum class GLXEXTTextureFromPixmap
	{
		BindTexImageEXT,
		ReleaseTexImageEXT
	};

	enum class GLXSGIXFbconfig
	{
		GetFBConfigAttribSGIX,
		ChooseFBConfigSGIX,
		CreateGLXPixmapWithConfigSGIX,
		CreateContextWithConfigSGIX,
		GetVisualFromFBConfigSGIX,
		GetFBConfigFromVisualSGIX
	};

	enum class GLXSGIXPbuffer
	{
		CreateGLXPbufferSGIX,
		DestroyGLXPbufferSGIX,
		QueryGLXPbufferSGIX,
		SelectEventSGIX,
		GetSelectedEventSGIX
	};

	enum class GLXSGIXVideoResize
	{
		BindChannelToWindowSGIX,
		ChannelRectSGIX,
		ChannelRectSyncSGIX,
		QueryChannelDeltasSGIX,
		QueryChannelRectSGIX
	};

	enum class GLXSGIXSwapGroup
	{
		JoinSwapGroupSGIX,
	};

	enum class GLXSGIXSwapBarrier
	{
		BindSwapBarrierSGIX,
		QueryMaxSwapBarriersSGIX,
	};

	enum class GLXSGIXHyperpipe
	{
		BindHyperpipeSGIX,
		DestroyHyperpipeConfigSGIX,
		HyperpipeAttribSGIX,
		HyperpipeConfigSGIX,
		QueryHyperpipeAttribSGIX,
		QueryHyperpipeBestAttribSGIX,
		QueryHyperpipeConfigSGIX,
		QueryHyperpipeNetworkSGIX
	};
}

#endif // SYSTEM_HELPER_GLX_FLAGS_H
