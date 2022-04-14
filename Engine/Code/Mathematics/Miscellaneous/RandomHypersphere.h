///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/24 22:00)

#ifndef MATHEMATICS_MISCELLANEOUS_RANDOM_HYPERSPHERE_H
#define MATHEMATICS_MISCELLANEOUS_RANDOM_HYPERSPHERE_H

#include "Mathematics/MathematicsDll.h"

#include <vector>

namespace Mathematics
{
    void RandomPointOnHypersphere(int dimension, std::vector<double>& point);

    void Histogram(int dimension, double angle, int numPoints, std::vector<std::vector<double>>& points, std::vector<int>& histogram);
}

#endif  // MATHEMATICS_MISCELLANEOUS_RANDOM_HYPERSPHERE_H
