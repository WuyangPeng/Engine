///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 10:23)

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
