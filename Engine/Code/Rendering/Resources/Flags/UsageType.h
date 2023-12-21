/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/08 13:53)

#ifndef RENDERING_RESOURCES_USAGE_TYPE_H
#define RENDERING_RESOURCES_USAGE_TYPE_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    // 资源使用情况。这些控制如何创建GPU版本。在将资源绑定到引擎之前，必须设置使用类型。
    enum class UsageType
    {
        Immutable,
        DynamicUpdate,
        ShaderOutput
    };
}

#endif  // RENDERING_RESOURCES_USAGE_TYPE_H
