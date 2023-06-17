///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:23)

#ifndef MATHEMATICS_MISCELLANEOUS_NORMAL_COMPRESSION_H
#define MATHEMATICS_MISCELLANEOUS_NORMAL_COMPRESSION_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
    void CompressNormal(double x, double y, double z, uint16_t& index);

    void UncompressNormal(uint16_t index, double& x, double& y, double& z);
}

#endif  // MATHEMATICS_MISCELLANEOUS_NORMAL_COMPRESSION_H
