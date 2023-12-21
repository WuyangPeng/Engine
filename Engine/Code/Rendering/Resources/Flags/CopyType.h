/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/08 13:53)

#ifndef RENDERING_RESOURCES_COPY_TYPE_H
#define RENDERING_RESOURCES_COPY_TYPE_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    /// �ڲ��ݴ滺�������ɡ���Щ������ʱ�������Ĵ�������֧��CPU����ʱ��������GPU֮��ĸ��ơ�
    /// �ڽ���Դ�󶨵�����֮ǰ���������ø������͡�
    enum class CopyType
    {
        None,
        CpuToStaging,
        StagingToCpu,
        Bidirectional
    };
}

#endif  // RENDERING_RESOURCES_COPY_TYPE_H
