// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2019/12/31 15:26)

#ifndef SYSTEM_ANDROID_ANDROID_WINDOW_TYPEDEF_H
#define SYSTEM_ANDROID_ANDROID_WINDOW_TYPEDEF_H

#include "System/SystemDll.h"

#ifdef SYSTEM_PLATFORM_ANDROID

#include <android/native_window.h>

namespace System
{
	using AndroidNativeWindow = ANativeWindow;
	using AndroidNativeWindowBuffer = ANativeWindow_Buffer;
	using AndroidRect = ARect;
}

#else // !SYSTEM_PLATFORM_ANDROID

#include <array>

namespace System
{
	struct SYSTEM_DEFAULT_DECLARE AndroidNativeWindow
	{

	};

	struct SYSTEM_DEFAULT_DECLARE AndroidNativeWindowBuffer
	{
	public:
		using ClassType = AndroidNativeWindowBuffer;

	public:
		AndroidNativeWindowBuffer() noexcept;

	private:
		static constexpr auto sm_Size = 6;

	private:
		int width;
		int height;
		int stride;
		int format;
		void* bits;
		std::array<uint32_t, sm_Size> reserved;
	};

	struct SYSTEM_DEFAULT_DECLARE AndroidRect
	{
	public:
		using ClassType = AndroidRect;

	public:
		AndroidRect() noexcept; 

		int GetLeft() const noexcept;
		int GetTop() const noexcept;
		int GetRight() const noexcept;
		int GetBottom() const noexcept;

	private:
		int left;
		int top;
		int right;
		int bottom;
	};
}

#endif // SYSTEM_PLATFORM_ANDROID

#endif // SYSTEM_ANDROID_ANDROID_WINDOW_TYPEDEF_H
