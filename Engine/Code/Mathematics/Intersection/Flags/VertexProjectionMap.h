///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/25 11:22)

#ifndef MATHEMATICS_INTERSECTION_VERTEX_PROJECTION_MAP_H
#define MATHEMATICS_INTERSECTION_VERTEX_PROJECTION_MAP_H

#include "System/Helper/EnumMacro.h"

namespace Mathematics
{  
    // ����ͶӰͼ����ν�����ͶӰ���������С�����㣩��
    enum class VertexProjectionMap
    {
        M2,
        M11,  // �߶�
        M3,
        M21,
        M12,
        M111,  // ������
        M44,
        M2_2,
        M1_1  // ����
    };
}

#endif  // MATHEMATICS_INTERSECTION_VERTEX_PROJECTION_MAP_H
