/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/08 13:53)

#ifndef RENDERING_RESOURCES_COPY_TYPE_H
#define RENDERING_RESOURCES_COPY_TYPE_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    /// 内部暂存缓冲区生成。这些控制临时缓冲区的创建，以支持CPU、临时缓冲区和GPU之间的复制。
    /// 在将资源绑定到引擎之前，必须设置副本类型。
    enum class CopyType
    {
        None,
        CpuToStaging,
        StagingToCpu,
        Bidirectional
    };
}

#endif  // RENDERING_RESOURCES_COPY_TYPE_H
