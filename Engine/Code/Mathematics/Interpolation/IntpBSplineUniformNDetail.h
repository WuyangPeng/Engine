// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 10:20)

#ifndef MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORMN_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORMN_DETAIL_H

#include "IntpBSplineUniformN.h"

namespace Mathematics
{
    template <typename Real>
    IntpBSplineUniformN<Real>::IntpBSplineUniformN(int dims, int degree, const int* dim, Real* data)
        : IntpBSplineUniform<Real>(dims, degree, dim, data)
    {
        mEvI = nullptr;  // NEW1<int>(mDims);
        mCiLoop = nullptr;  //  NEW1<int>(mDims);
        mCiDelta = nullptr;  // NEW1<int>(mDims - 1);
        mOpI = nullptr;  //  NEW1<int>(mDims);
        mOpJ = nullptr;  //  NEW1<int>(mDims);
        mOpDelta = nullptr;  //  NEW1<int>(mDims - 1);

        int temp = 1;
        for (int i = 0; i < mDims - 1; ++i)
        {
            mCiDelta[i] = temp * (mDim[i] - mDp1);
            temp *= mDim[i];
        }
    }

    template <typename Real>
    IntpBSplineUniformN<Real>::~IntpBSplineUniformN()
    {
        // 		DELETE1(mEvI);
        // 		DELETE1(mCiLoop);
        // 		DELETE1(mOpI);
        // 		DELETE1(mOpJ);
        // 		DELETE1(mOpDelta);
        // 		DELETE1(mCiDelta);
    }

    template <typename Real>
    int IntpBSplineUniformN<Real>::Index(int* I) const
    {
        int index = I[mDims - 1];
        for (int dim = mDims - 2; dim >= 0; --dim)
        {
            index *= mDim[dim];
            index += I[dim];
        }
        return index;
    }

    template <typename Real>
    Real IntpBSplineUniformN<Real>::operator()(Real* X)
    {
        int dim;
        for (dim = 0; dim < mDims; ++dim)
        {
            mBase[dim] = (int)Math<Real>::Floor(X[dim]);
        }

        for (dim = 0; dim < mDims; ++dim)
        {
            if (mOldBase[dim] != mBase[dim])
            {
                // Switch to new local grid.
                for (int k = 0; k < mDims; ++k)
                {
                    mOldBase[k] = mBase[k];
                    mGridMin[k] = mBase[k] - 1;
                    mGridMax[k] = mGridMin[k] + mDegree;
                }

                // Fill in missing grid mData if necessary.
                if (mEvaluateCallback)
                {
                    EvaluateUnknownData();
                }

                ComputeIntermediate();
                break;
            }
        }

        for (dim = 0; dim < mDims; ++dim)
        {
            SetPolynomial(0, X[dim] - mBase[dim], mPoly[dim]);
        }

        for (dim = 0; dim < mDims; ++dim)
        {
            mOpI[dim] = 0;
        }

        Real result = Math<Real>::GetValue(0);
        int k;
        for (k = 0; k < mDp1ToN; ++k)
        {
            Real temp = mInter[k];
            for (dim = 0; dim < mDims; ++dim)
            {
                temp *= mPoly[dim][mOpI[dim]];
            }
            result += temp;

            for (dim = 0; dim < mDims; ++dim)
            {
                if (++mOpI[dim] <= mDegree)
                {
                    break;
                }
                mOpI[dim] = 0;
            }
        }
        return result;
    }

    template <typename Real>
    Real IntpBSplineUniformN<Real>::operator()(int* dx, Real* X)
    {
        int dim;
        for (dim = 0; dim < mDims; ++dim)
        {
            mBase[dim] = (int)Math<Real>::Floor(X[dim]);
        }

        for (dim = 0; dim < mDims; ++dim)
        {
            if (mOldBase[dim] != mBase[dim])
            {
                // Switch to new local grid.
                for (int k = 0; k < mDims; ++k)
                {
                    mOldBase[k] = mBase[k];
                    mGridMin[k] = mBase[k] - 1;
                    mGridMax[k] = mGridMin[k] + mDegree;
                }

                // Fill in missing grid mData if necessary.
                if (mEvaluateCallback)
                {
                    EvaluateUnknownData();
                }

                ComputeIntermediate();
                break;
            }
        }

        for (dim = 0; dim < mDims; ++dim)
        {
            SetPolynomial(dx[dim], X[dim] - mBase[dim], mPoly[dim]);
        }

        for (dim = 0; dim < mDims; ++dim)
        {
            mOpJ[dim] = dx[dim];
        }

        int temp = 1;
        for (dim = 0; dim < mDims - 1; ++dim)
        {
            mOpDelta[dim] = temp * dx[dim];
            temp *= mDp1;
        }

        Real result = Math<Real>::GetValue(0);
        int k = mOpJ[mDims - 1];
        for (dim = mDims - 2; dim >= 0; --dim)
        {
            k *= mDp1;
            k += mOpJ[dim];
        }
        for (/**/; k < mDp1ToN; ++k)
        {
            Real temp = mInter[k];
            for (dim = 0; dim < mDims; ++dim)
            {
                temp *= mPoly[dim][mOpJ[dim]];
            }
            result += temp;

            for (dim = 0; dim < mDims; ++dim)
            {
                if (++mOpJ[dim] <= mDegree)
                {
                    continue;
                }
                mOpJ[dim] = dx[dim];
                k += mOpDelta[dim];
            }
        }
        return result;
    }

    template <typename Real>
    void IntpBSplineUniformN<Real>::EvaluateUnknownData()
    {
        int dim;
        for (dim = 0; dim < mDims; ++dim)
        {
            mEvI[dim] = mGridMin[dim];
        }

        for (int j = 0; j < mDp1ToN; ++j)
        {
            int index = Index(mEvI);
            if (mData[index] == Math<Real>::sm_MaxReal)
            {
                mData[index] = mEvaluateCallback(index);
            }

            for (dim = 0; dim < mDims; ++dim)
            {
                if (++mEvI[dim] <= mGridMax[dim])
                {
                    break;
                }
                mEvI[dim] = mGridMin[dim];
            }
        }
    }

    template <typename Real>
    void IntpBSplineUniformN<Real>::ComputeIntermediate()
    {
        // Fetch subblock of mData to cache.
        int dim;
        for (dim = 0; dim < mDims; ++dim)
        {
            mCiLoop[dim] = mGridMin[dim];
        }
        int index = Index(mCiLoop);
        int k;
        for (k = 0; k < mDp1ToN; ++k, ++index)
        {
            mCache[k] = mData[index];

            for (dim = 0; dim < mDims; ++dim)
            {
                if (++mCiLoop[dim] <= mGridMax[dim])
                {
                    break;
                }
                mCiLoop[dim] = mGridMin[dim];
                index += mCiDelta[dim];
            }
        }

        // Compute and save the intermediate product.
        for (int i = 0, j = 0; i < mDp1ToN; ++i)
        {
            Real sum = Math<Real>::GetValue(0);
            for (k = 0; k < mDp1ToN; k += mSkip[j], j += mSkip[j])
            {
                sum += mProduct[j] * mCache[k];
            }
            mInter[i] = sum;
        }
    }
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORMN_DETAIL_H