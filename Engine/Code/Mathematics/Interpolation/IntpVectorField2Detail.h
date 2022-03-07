// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 10:24)

#ifndef MATHEMATICS_INTERPOLATION_INTP_VECTOR_FIELD2_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_VECTOR_FIELD2_DETAIL_H

#include "IntpVectorField2.h"

namespace Mathematics
{
    template <typename Real>
    IntpVectorField2<Real>::IntpVectorField2(const std::vector<Vector2<Real>>& domain, Vector2<Real>* range, bool owner, QueryType queryType)
    {
        int quantity = domain.size();
        // Repackage the output vectors into individual components.  This is
        // required because of the format that the quadratic interpolator expects
        // for its input data.
        Real* xOutput = nullptr;  // NEW1<Real>(quantity);
        Real* yOutput = nullptr;  //  NEW1<Real>(quantity);
        for (int i = 0; i < quantity; ++i)
        {
            xOutput[i] = range[i][0];
            yOutput[i] = range[i][1];
        }

        if (owner)
        {
            // DELETE1(range);
        }

        // Common triangulator for the interpolators.
        mDT = nullptr;  // NEW0 Delaunay2<Real>(domain, Real{ 0.001 }, owner,queryType);

        // Create interpolator for x-coordinate of vector field.
        mXInterp = nullptr;  // NEW0 IntpQdrNonuniform2<Real>(*mDT, xOutput, true);

        // Create interpolator for y-coordinate of vector field, but share the
        // already created triangulation for the x-interpolator.
        mYInterp = nullptr;  // NEW0 IntpQdrNonuniform2<Real>(*mDT, yOutput, true);
    }

    template <typename Real>
    IntpVectorField2<Real>::~IntpVectorField2()
    {
        DELETE0(mDT);
        DELETE0(mXInterp);
        DELETE0(mYInterp);
    }

    template <typename Real>
    bool IntpVectorField2<Real>::Evaluate(const Vector2<Real>& input,
                                          Vector2<Real>& output)
    {
        Real xDeriv, yDeriv;
        return mXInterp->Evaluate(input, output[0], xDeriv, yDeriv) && mYInterp->Evaluate(input, output[1], xDeriv, yDeriv);
    }
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_VECTOR_FIELD2_DETAIL_H