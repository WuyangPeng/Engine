// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:02)

#include "System/SystemExport.h"

#include "AndroidNativeWindowUsing.h"
#include "System/Helper/EnumCast.h"
#include "System/Android/Flags/AndroidNativeWindowFlags.h"

#ifndef SYSTEM_PLATFORM_ANDROID

System::AndroidNativeWindowBuffer
	::AndroidNativeWindowBuffer() noexcept
	:width{ 0 }, height{ 0 }, stride{ 0 }, format{ EnumCastUnderlying(WindowFormat::RGBA8888) }, bits{}, reserved{}
{

}

System::AndroidRect
	::AndroidRect() noexcept
	:left{ 0 }, top{ 0 }, right{ 0 }, bottom{ 0 }
{

}

int System::AndroidRect
	::GetLeft() const noexcept
{
	return left;
}

int System::AndroidRect
	::GetTop() const noexcept
{
	return top;
}

int System::AndroidRect
	::GetRight() const noexcept
{
	return right;
}

int System::AndroidRect
	::GetBottom() const noexcept
{
	return bottom;
}

#endif // SYSTEM_PLATFORM_ANDROID