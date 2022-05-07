///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/04 15:34)

#ifndef RENDERING_CONTROLLERS_CONTROLLER_FLAGS_H
#define RENDERING_CONTROLLERS_CONTROLLER_FLAGS_H

namespace Rendering
{
	// 时间管理。一个控制器可以使用自己的时间比例和它指定时间是如何被映射到应用程序时间。
    enum class ControllerRepeatType
    {
        Clamp,
        Wrap,
        ClampCycle
    };
}

#endif // RENDERING_CONTROLLERS_CONTROLLER_FLAGS_H
