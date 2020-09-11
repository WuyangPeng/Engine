// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.2 (2019/07/16 13:36)

#include "Mathematics/MathematicsExport.h"

#include "RandomHypersphere.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Base/RandomDetail.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26487)
#include SYSTEM_WARNING_DISABLE(26489)
#include SYSTEM_WARNING_DISABLE(26461)
static void RecurseRandomPoint (int dimension, double* point)
{
    // Select random point on circle.
    const double angle = Mathematics::Randomd::IntervalRandom(0.0,Mathematics::DoubleMath::GetTwoPI());
    const double cs = Mathematics::DoubleMath::Cos(angle);
   const  double sn = Mathematics::DoubleMath::Sin(angle);

    if (dimension > 3)
    {
        // Split components into two sets and adjust values.
        int i = 0;
		int half = dimension/2;
        for (i = 0; i < half; ++i)
        {
            point[i] *= cs;
        }
        for (i = half; i < dimension; ++i)
        {
            point[i] *= sn;
        }

        // Recurse on each half of the components.
        RecurseRandomPoint(half, point);
        RecurseRandomPoint(dimension - half, point + half);
    }
    else if (dimension == 3)
    {
        const double value = Mathematics::Randomd::SymmetricRandom();
        const double complement = Mathematics::DoubleMath::Sqrt(Mathematics::DoubleMath::FAbs(1.0 - value*value));
        point[0] *= value;
        point[1] *= complement*cs;
        point[2] *= complement*sn;
    }
    else if (dimension == 2)
    {
        point[0] *= cs;
        point[1] *= sn;
    }
}

void Mathematics::RandomPointOnHypersphere (int dimension, double* point)
{
    for (int i = 0; i < dimension; ++i)
    {
        point[i] = 1.0;
    }

    RecurseRandomPoint(dimension, point);
}

void Mathematics::Histogram (int dimension, double angle, int numPoints,double** points, int* histogram) noexcept
{
    // Count the number of points located in the cone of specified angle
    // about each of the samples.
    const double cs = DoubleMath::Cos(angle);

    for (int i = 0; i < numPoints; ++i)
    {
        histogram[i] = 0;
        for (int j = 0; j < numPoints; ++j)
        {
            // Compute dot product between points P[i] and P[j].
            double dot = 0;
            for (int k = 0; k < dimension; ++k)
            {
                dot += points[i][k]*points[j][k];
            }
            if (dot >= cs)
            {
                histogram[i]++;
            }
        }
    }
}

#include STSTEM_WARNING_POP