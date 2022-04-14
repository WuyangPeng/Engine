///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/24 22:02)

#include "Mathematics/MathematicsExport.h"

#include "RandomHypersphere.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Base/RandomDetail.h"

static void RecurseRandomPoint(int dimension, std::vector<double>& point, int index)
{
    const auto angle = Mathematics::RandomD::IntervalRandom(0.0, Mathematics::MathD::GetTwoPI());
    const auto cs = Mathematics::MathD::Cos(angle);
    const auto sn = Mathematics::MathD::Sin(angle);

    if (dimension > 3)
    {
        const auto half = dimension / 2;
        for (auto i = 0; i < half; ++i)
        {
            const auto pointIndex = index + i;
            point.at(pointIndex) *= cs;
        }
        for (auto i = half; i < dimension; ++i)
        {
            const auto pointIndex = index + i;
            point.at(pointIndex) *= sn;
        }

        RecurseRandomPoint(half, point, index);
        RecurseRandomPoint(dimension - half, point, index + half);
    }
    else if (dimension == 3)
    {
        const auto value = Mathematics::RandomD::SymmetricRandom();
        const auto complement = Mathematics::MathD::Sqrt(Mathematics::MathD::FAbs(1.0 - value * value));
        point.at(index) *= value;
        point.at(boost::numeric_cast<size_t>(index) + 1) *= complement * cs;
        point.at(boost::numeric_cast<size_t>(index) + 2) *= complement * sn;
    }
    else if (dimension == 2)
    {
        point.at(index) *= cs;
        point.at(boost::numeric_cast<size_t>(index) + 1) *= sn;
    }
}

void Mathematics::RandomPointOnHypersphere(int dimension, std::vector<double>& point)
{
    for (auto i = 0; i < dimension; ++i)
    {
        point.at(i) = 1.0;
    }

    RecurseRandomPoint(dimension, point, 0);
}

void Mathematics::Histogram(int dimension, double angle, int numPoints, std::vector<std::vector<double>>& points, std::vector<int>& histogram)
{
    const auto cs = MathD::Cos(angle);

    for (auto i = 0; i < numPoints; ++i)
    {
        histogram.at(i) = 0;
        for (auto j = 0; j < numPoints; ++j)
        {
            auto dot = 0.0;
            for (auto k = 0; k < dimension; ++k)
            {
                dot += points.at(i).at(k) * points.at(j).at(k);
            }
            if (dot >= cs)
            {
                ++histogram.at(i);
            }
        }
    }
}
