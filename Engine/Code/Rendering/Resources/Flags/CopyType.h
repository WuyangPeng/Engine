///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/08 16:14)

#ifndef RENDERING_RESOURCES_COPY_TYPE_H
#define RENDERING_RESOURCES_COPY_TYPE_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    enum class CopyType
    {
        None,
        CpuToStaging,
        StagingToCpu,
        Bidirectional
    };
}

#endif  // RENDERING_RESOURCES_COPY_TYPE_H
