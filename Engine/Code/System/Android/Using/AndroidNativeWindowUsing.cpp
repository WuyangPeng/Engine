/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 17:19)

#include "System/SystemExport.h"

#include "AndroidNativeWindowUsing.h"
#include "System/Android/Flags/AndroidNativeWindowFlags.h"
#include "System/Helper/EnumCast.h"

#ifndef SYSTEM_PLATFORM_ANDROID

System::AndroidNativeWindowBuffer::AndroidNativeWindowBuffer() noexcept
    : width{ 0 }, height{ 0 }, stride{ 0 }, format{ EnumCastUnderlying(WindowFormat::Rgba8888) }, bits{}, reserved{}
{
}

int32_t System::AndroidNativeWindowBuffer::GetWidth() const noexcept
{
    return width;
}

void System::AndroidNativeWindowBuffer::SetWidth(int32_t aWidth) noexcept
{
    width = aWidth;
}

int32_t System::AndroidNativeWindowBuffer::GetHeight() const noexcept
{
    return height;
}

void System::AndroidNativeWindowBuffer::SetHeight(int32_t aHeight) noexcept
{
    height = aHeight;
}

int32_t System::AndroidNativeWindowBuffer::GetStride() const noexcept
{
    return stride;
}

void System::AndroidNativeWindowBuffer::SetStride(int32_t aStride) noexcept
{
    stride = aStride;
}

int32_t System::AndroidNativeWindowBuffer::GetFormat() const noexcept
{
    return format;
}

void System::AndroidNativeWindowBuffer::SetFormat(int32_t aFormat) noexcept
{
    format = aFormat;
}

void* System::AndroidNativeWindowBuffer::GetBits() noexcept
{
    return bits;
}

void System::AndroidNativeWindowBuffer::SetBits(void* aBits) noexcept
{
    bits = aBits;
}

System::AndroidNativeWindowBuffer::ReservedType System::AndroidNativeWindowBuffer::GetReserved() const noexcept
{
    return reserved;
}

void System::AndroidNativeWindowBuffer::SetReserved(const ReservedType& aReserved) noexcept
{
    reserved = aReserved;
}

System::AndroidRect::AndroidRect() noexcept
    : left{ 0 }, top{ 0 }, right{ 0 }, bottom{ 0 }
{
}

int System::AndroidRect::GetLeft() const noexcept
{
    return left;
}

int System::AndroidRect::GetTop() const noexcept
{
    return top;
}

int System::AndroidRect::GetRight() const noexcept
{
    return right;
}

int System::AndroidRect::GetBottom() const noexcept
{
    return bottom;
}

#endif  // SYSTEM_PLATFORM_ANDROID