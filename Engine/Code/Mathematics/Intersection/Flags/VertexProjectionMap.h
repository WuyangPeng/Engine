///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 14:45)

#ifndef MATHEMATICS_INTERSECTION_VERTEX_PROJECTION_MAP_H
#define MATHEMATICS_INTERSECTION_VERTEX_PROJECTION_MAP_H

#include "System/Helper/EnumOperator.h"

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
