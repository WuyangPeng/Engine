///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.1 (2023/02/02 14:36)

#ifndef SYSTEM_WINDOWS_WINDOWS_CLASS_STYLE_FLAGS_H
#define SYSTEM_WINDOWS_WINDOWS_CLASS_STYLE_FLAGS_H

#include "System/Helper/EnumOperator.h"
#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class WindowsClassStyle
    {
        /// 如果移动或调整窗口的高度，重绘整个窗口。
        VerticalRedraw = CS_VREDRAW,
        /// 如果移动或调整窗口的宽度，重绘整个窗口。
        HorizontalRedraw = CS_HREDRAW,

        Redraw = VerticalRedraw | HorizontalRedraw,

        /// 允许向窗口发送双击鼠标键的消息
        DoubleClicks = CS_DBLCLKS,

        /// 该窗口类的每个窗口实例都分配一个唯一的窗口类DC。
        OwnDC = CS_OWNDC,
        /// 该窗口类的所有窗口实例都共享一个窗口类DC。
        ClassDC = CS_CLASSDC,
        /// 将子窗口的裁剪区域设置到父窗口的DC中去，这样子窗口便可以在父窗口上绘制自身。
        ParentDC = CS_PARENTDC,

        /// 禁止系统菜单的关闭选项
        NoClose = CS_NOCLOSE,

        /// 以位图形式保存被该窗口遮挡的屏幕部分（该特性对于菜单类型的窗口比较合适）
        SaveBits = CS_SAVEBITS,

        /// 在字节边界上（在x方向上）定位窗口的用户区域的位置
        ByteAlignClient = CS_BYTEALIGNCLIENT,
        /// 在字节边界上（在x方向上）定位窗口的位置
        ByteAlignWindow = CS_BYTEALIGNWINDOW,

        /// 表示该窗口类是一个应用程序全局类，
        /// 允许调用CreateWindow或CreateWindowEx函数和传递给RegisterClass的instance参数不同，
        /// 如果不指定该风格则这两个instance必须相同。
        GlobalWindow = CS_GLOBALCLASS,

        /// 使一个窗口有阴影效果，
        /// 当效果被激活时，
        /// 通过SPI_SETDROPSHADOW关闭。
        /// (该特性对于小且短暂的窗口比较合适，
        /// 比如菜单用来强调自己和其他窗口的z顺序关系。)
        DropShadow = CS_DROPSHADOW,

        CommonUse = Redraw | OwnDC | DoubleClicks,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class WindowsClassStyle
    {
        VerticalRedraw = 0x0001,
        HorizontalRedraw = 0x0002,

        Redraw = VerticalRedraw | HorizontalRedraw,

        DoubleClicks = 0x0008,
        OwnDC = 0x0020,
        ClassDC = 0x0040,
        ParentDC = 0x0080,
        NoClose = 0x0200,
        SaveBits = 0x0800,
        ByteAlignClient = 0x1000,
        ByteAlignWindow = 0x2000,
        GlobalWindow = 0x4000,
        DropShadow = 0x00020000,

        CommonUse = Redraw | OwnDC | DoubleClicks,
    };

#endif  // SYSTEM_PLATFORM_WIN32

}

#endif  // SYSTEM_WINDOWS_WINDOW_CLASS_STYLE_FLAGS_H
