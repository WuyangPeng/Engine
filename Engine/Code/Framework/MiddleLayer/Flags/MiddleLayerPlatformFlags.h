///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/05 16:11)

#ifndef FRAMEWORK_MODEL_VIEW_CONTROLLER_FLAGS_H
#define FRAMEWORK_MODEL_VIEW_CONTROLLER_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace Framework
{
    enum class MiddleLayerPlatform
    {
        Windows,
        Macintosh,
        Android,
        Linux,

        Count,
    };
}

#endif  // FRAMEWORK_MODEL_VIEW_CONTROLLER_FLAGS_H