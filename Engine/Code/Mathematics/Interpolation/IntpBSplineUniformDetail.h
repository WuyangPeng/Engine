// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 10:19)

#ifndef MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM_DETAIL_H

#include "IntpBSplineUniform.h"

namespace Mathematics
{
    template <typename Real>
    IntpBSplineUniform<Real>::IntpBSplineUniform(int dims, int degree, const int* dim, Real* data)
    {
        // Get input data.
        MATHEMATICS_ASSERTION_0(dims > 0 && degree > 0 && dim && data, "Invalid input\n");
        int i;
        for (i = 0; i < dims; ++i)
        {
            MATHEMATICS_ASSERTION_0(dim[i] > degree + 1, "Invalid input\n");
        }

        mDims = dims;
        mDegree = degree;
        mDim = nullptr;  //  NEW1<int>(mDims);
        memcpy(mDim, dim, mDims * sizeof(int));
        mData = data;

        // Setup degree constants.
        mDp1 = mDegree + 1;
        mDp1ToN = 1;
        for (i = 0; i < mDims; ++i)
        {
            mDp1ToN *= mDp1;
        }
        mDp1To2N = mDp1ToN * mDp1ToN;

        // Compute domain [min,max] for B-spline.
        mDomMin = nullptr;  //NEW1<Real>(mDims);
        mDomMax = nullptr;  //NEW1<Real>(mDims);
        for (i = 0; i < mDims; ++i)
        {
            Real domSup = (Real)(mDim[i] - mDegree + 1);
            Real next = (Math::GetRational(1, 2)) * (Math::GetValue(1) + domSup);
            do
            {
                mDomMax[i] = next;
                next = (Math::GetRational(1, 2)) * (next + domSup);
            } while (next < domSup);
            mDomMin[i] = Math::GetValue(1);
        }

        // Initialize grid extremes.
        mGridMin = nullptr;  // NEW1<int>(mDims);
        mGridMax = nullptr;  // NEW1<int>(mDims);
        for (i = 0; i < mDims; ++i)
        {
            mGridMin[i] = -1;
            mGridMax[i] = -1;
        }

        // Initialize base indices.
        mBase = nullptr;  //  NEW1<int>(mDims);
        mOldBase = nullptr;  //  NEW1<int>(mDims);
        for (i = 0; i < mDims; ++i)
        {
            mOldBase[i] = -1;
        }

        // Generate spline blending matrix.
        mMatrix = BlendMatrix(mDegree);

        // Cache for optimizing ComputeIntermediate().
        mCache = nullptr;  // NEW1<Real>(mDp1ToN);

        // Storage for intermediate tensor product.
        mInter = nullptr;  // NEW1<Real>(mDp1ToN);

        // Polynomial allocations.
        mPoly = nullptr;  // NEW1<Real*>(mDims);
        for (i = 0; i < mDims; ++i)
        {
            mPoly[i] = nullptr;  //  NEW1<Real>(mDp1);
        }

        // Coefficients for polynomial calculations.
        mCoeff = nullptr;  //  NEW1<Real*>(mDp1);
        for (int row = 0; row <= mDegree; ++row)
        {
            mCoeff[row] = nullptr;  // NEW1<Real>(mDp1);
            for (int col = row; col <= mDegree; ++col)
            {
                mCoeff[row][col] = Math::GetValue(1);
                for (i = 0; i <= row - 1; ++i)
                {
                    mCoeff[row][col] *= (Real)(col - i);
                }
            }
        }

        // Tensor product of m with itself N times.
        mProduct = nullptr;  // NEW1<Real>(mDp1To2N);
        mSkip = nullptr;  // NEW1<int>(mDp1To2N);
        int* coord = nullptr;  //  NEW1<int>(2 * mDims);  // for address decoding
        int j;
        for (j = 0; j < mDp1To2N; ++j)
        {
            int temp = j;
            for (i = 0; i < 2 * mDims; ++i)
            {
                coord[i] = temp % mDp1;
                temp /= mDp1;
            }

            mProduct[j] = Math::GetValue(1);
            for (i = 0; i < mDims; ++i)
            {
                mProduct[j] *= mMatrix[coord[i]][coord[i + mDims]];
            }

            mSkip[j] = 1;
        }
        // DELETE1(coord);

        // Compute increments to skip zero values of mtensor.
        for (i = 0; i < mDp1To2N; /**/)
        {
            for (j = i + 1; j < mDp1To2N && mProduct[j] == Math<Real>::GetValue(0); ++j)
            {
                mSkip[i]++;
            }
            i = j;
        }

        mEvaluateCallback = 0;
    }

    template <typename Real>
    IntpBSplineUniform<Real>::~IntpBSplineUniform()
    {
        // 		DELETE1(mDim);
        // 		DELETE1(mDomMin);
        // 		DELETE1(mDomMax);
        // 		DELETE1(mGridMin);
        // 		DELETE1(mGridMax);
        // 		DELETE1(mBase);
        // 		DELETE1(mOldBase);
        // 		DELETE1(mCache);
        // 		DELETE1(mInter);
        // 		DELETE1(mProduct);
        // 		DELETE1(mSkip);

        int i;
        for (i = 0; i < mDims; ++i)
        {
            //DELETE1(mPoly[i]);
        }
        //DELETE1(mPoly);

        for (i = 0; i <= mDegree; ++i)
        {
            // 			DELETE1(mMatrix[i]);
            // 			DELETE1(mCoeff[i]);
        }
        /*DELETE1(mMatrix);*/
        //DELETE1(mCoeff);
    }

    template <typename Real>
    int IntpBSplineUniform<Real>::GetDimension() const
    {
        return mDims;
    }

    template <typename Real>
    int IntpBSplineUniform<Real>::GetDegree() const
    {
        return mDegree;
    }

    template <typename Real>
    Real IntpBSplineUniform<Real>::GetDomainMin(int i) const
    {
        return mDomMin[i];
    }

    template <typename Real>
    Real IntpBSplineUniform<Real>::GetDomainMax(int i) const
    {
        return mDomMax[i];
    }

    template <typename Real>
    int IntpBSplineUniform<Real>::GetGridMin(int i) const
    {
        return mGridMin[i];
    }

    template <typename Real>
    int IntpBSplineUniform<Real>::GetGridMax(int i) const
    {
        return mGridMax[i];
    }

    template <typename Real>
    void IntpBSplineUniform<Real>::SetPolynomial(int order, Real diff, Real* poly)
    {
        Real diffPower = Math::GetValue(1);
        for (int i = order; i <= mDegree; ++i)
        {
            poly[i] = mCoeff[order][i] * diffPower;
            diffPower *= diff;
        }
    }

    template <typename Real>
    int IntpBSplineUniform<Real>::Choose(int n, int k)
    {
        // Computes combination "n choose k".
        if (n <= 1 || k >= n)
        {
            return 1;
        }

        int result = 1;
        int i;
        for (i = 0; i < k; ++i)
        {
            result *= n - i;
        }
        for (i = 1; i <= k; ++i)
        {
            result /= i;
        }

        return result;
    }

    template <typename Real>
    Real** IntpBSplineUniform<Real>::BlendMatrix(int degree)
    {
        int degP1 = degree + 1;
        int row, col, i, j, k;

        // Allocate triple arrays.
        int*** AMat = nullptr;  //  NEW1<int**>(degP1);
        int*** BMat = nullptr;  // NEW1<int**>(degP1);
        for (k = 0; k <= degree; ++k)
        {
            AMat[k] = nullptr;  //NEW1<int*>(degP1);
            BMat[k] = nullptr;  // NEW1<int*>(degP1);
            for (row = 0; row <= degree; ++row)
            {
                AMat[k][row] = nullptr;  // NEW1<int>(degP1);
                BMat[k][row] = nullptr;  //NEW1<int>(degP1);
                for (col = 0; col <= degree; ++col)
                {
                    AMat[k][row][col] = 0;
                    BMat[k][row][col] = 0;
                }
            }
        }

        AMat[0][0][0] = 1;
        BMat[0][0][0] = 1;

        for (k = 1; k <= degree; ++k)
        {
            // Compute A[].
            for (row = 0; row <= k; ++row)
            {
                for (col = 0; col <= k; ++col)
                {
                    AMat[k][row][col] = 0;
                    if (col >= 1)
                    {
                        AMat[k][row][col] += AMat[k - 1][row][col - 1];
                        if (row >= 1)
                        {
                            AMat[k][row][col] -= BMat[k - 1][row - 1][col - 1];
                        }
                    }
                    if (row >= 1)
                    {
                        AMat[k][row][col] += (k + 1) * BMat[k - 1][row - 1][col];
                    }
                }
            }

            // Compute B[].
            for (row = 0; row <= k; ++row)
            {
                for (col = 0; col <= k; ++col)
                {
                    BMat[k][row][col] = 0;
                    for (i = col; i <= k; ++i)
                    {
                        if ((i - col) % 2)
                        {
                            BMat[k][row][col] -= Choose(i, col) * AMat[k][row][i];
                        }
                        else
                        {
                            BMat[k][row][col] += Choose(i, col) * AMat[k][row][i];
                        }
                    }
                }
            }
        }

        Real** CMat = nullptr;  // NEW1<Real*>(degP1);
        for (row = 0; row <= degree; ++row)
        {
            CMat[row] = nullptr;  // NEW1<Real>(degP1);
            for (col = 0; col <= degree; ++col)
            {
                CMat[row][col] = 0;
                for (i = col; i <= degree; ++i)
                {
                    int prod = 1;
                    for (j = 1; j <= i - col; ++j)
                    {
                        prod *= degree - row;
                    }
                    CMat[row][col] += prod * Choose(i, col) *
                                      AMat[degree][degree - row][i];
                }
            }
        }

        Real factorial = 1;
        for (k = 1; k <= degree; ++k)
        {
            factorial *= k;
        }
        Real invFactorial = (Math::GetValue(1)) / factorial;
        Real** matrix = nullptr;  //NEW1<Real*>(degP1);
        for (row = 0; row <= degree; ++row)
        {
            matrix[row] = nullptr;  // NEW1<Real>(degP1);
            for (col = 0; col <= degree; ++col)
            {
                matrix[row][col] = CMat[row][col] * invFactorial;
            }
        }

        // Deallocate triple arrays.
        for (k = 0; k <= degree; ++k)
        {
            for (row = 0; row <= degree; ++row)
            {
//                 DELETE1(BMat[k][row]);
//                 DELETE1(AMat[k][row]);
            }
//             DELETE1(BMat[k]);
//             DELETE1(AMat[k]);
        }
//         DELETE1(BMat);
//         DELETE1(AMat);

        // Deallocate integer matrix.
        for (k = 0; k <= degree; ++k)
        {
           // DELETE1(CMat[k]);
        }
       // DELETE1(CMat);

        return matrix;
    }
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM_DETAIL_H