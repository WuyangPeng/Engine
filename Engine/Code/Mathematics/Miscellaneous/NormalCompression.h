///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.4 (2022/03/24 21:42)

#ifndef MATHEMATICS_MISCELLANEOUS_NORMAL_COMPRESSION_H
#define MATHEMATICS_MISCELLANEOUS_NORMAL_COMPRESSION_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
    void CompressNormal(double x, double y, double z, uint16_t& index);

    void UncompressNormal(uint16_t index, double& x, double& y, double& z);
}

#endif  // MATHEMATICS_MISCELLANEOUS_NORMAL_COMPRESSION_H
