// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 10:53)

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
