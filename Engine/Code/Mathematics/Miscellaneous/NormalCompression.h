///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 10:23)

#ifndef MATHEMATICS_MISCELLANEOUS_NORMAL_COMPRESSION_H
#define MATHEMATICS_MISCELLANEOUS_NORMAL_COMPRESSION_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
    void CompressNormal(double x, double y, double z, uint16_t& index);

    void UncompressNormal(uint16_t index, double& x, double& y, double& z);
}

#endif  // MATHEMATICS_MISCELLANEOUS_NORMAL_COMPRESSION_H
