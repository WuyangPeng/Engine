// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/07 23:36)

#ifndef SYSTEM_HELPER_WGL_FLAGS_H
#define SYSTEM_HELPER_WGL_FLAGS_H

#include "System/Helper/UserMacro.h"

namespace System
{
	enum class WGLARBBufferRegion
	{
		CreateBufferRegionARB,
		DeleteBufferRegionARB,
		SaveBufferRegionARB,
		RestoreBufferRegionARB,
	};

	enum class WGLARBExtensionsString
	{
		GetExtensionsStringARB,
	};

	enum class WGLARBPixelFormat
	{
		GetPixelFormatAttribivARB,
		GetPixelFormatAttribfvARB,
		ChoosePixelFormatARB
	};

	enum class WGLARBMakeCurrentRead
	{
		MakeContextCurrentARB,
		GetCurrentReadDCARB,
	};

	enum class WGLARBPbuffer
	{
		CreatePbufferARB,
		GetPbufferDCARB,
		ReleasePbufferDCARB,
		DestroyPbufferARB,
		QueryPbufferARB
	};

	enum class WGLARBRenderTexture
	{
		BindTexImageARB,
		ReleaseTexImageARB,
		SetPbufferAttribARB,
	};

	enum class WGLARBCreateContext
	{
		CreateContextAttribsARB
	};

	enum class WGLEXTDisplayColorTable
	{
		CreateDisplayColorTableEXT,
		LoadDisplayColorTableEXT,
		BindDisplayColorTableEXT,
		DestroyDisplayColorTableEXT
	};

	enum class WGLEXTExtensionsString
	{
		GetExtensionsStringEXT,
	};

	enum class WGLEXTMakeCurrentRead
	{
		MakeContextCurrentEXT,
		GetCurrentReadDCEXT,
	};

	enum class WGLEXTPixelFormat
	{
		GetPixelFormatAttribivEXT,
		GetPixelFormatAttribfvEXT,
		ChoosePixelFormatEXT,
	};

	enum class WGLEXTPbuffer
	{
		CreatePbufferEXT,
		GetPbufferDCEXT,
		ReleasePbufferDCEXT,
		DestroyPbufferEXT,
		QueryPbufferEXT
	};

	enum class WGLEXTSwapControl
	{
		SwapIntervalEXT,
		GetSwapIntervalEXT
	};
}

#endif // SYSTEM_HELPER_WGL_FLAGS_H
