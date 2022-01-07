///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/13 22:59)

#include "System/SystemExport.h"

#include "AndroidNativeWindowUsing.h"
#include "System/Android/Flags/AndroidNativeWindowFlags.h"
#include "System/Helper/EnumCast.h"

#ifndef SYSTEM_PLATFORM_ANDROID

System::AndroidNativeWindowBuffer::AndroidNativeWindowBuffer() noexcept
    : width{ 0 }, height{ 0 }, stride{ 0 }, format{ EnumCastUnderlying(WindowFormat::RGBA8888) }, bits{}, reserved{}
{
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