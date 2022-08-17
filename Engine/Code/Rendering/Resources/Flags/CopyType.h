///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/08 16:14)

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
