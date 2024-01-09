/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/29 13:54)

#ifndef RENDERING_RESOURCES_USAGE_TYPE_H
#define RENDERING_RESOURCES_USAGE_TYPE_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    // ��Դʹ���������Щ������δ���GPU�汾���ڽ���Դ�󶨵�����֮ǰ����������ʹ�����͡�
    enum class UsageType
    {
        Immutable,
        DynamicUpdate,
        ShaderOutput
    };
}

#endif  // RENDERING_RESOURCES_USAGE_TYPE_H
