// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 10:22)

#ifndef MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE3_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE3_DETAIL_H

#include "IntpThinPlateSpline3.h"

namespace Mathematics
{
    template <typename Real>
    IntpThinPlateSpline3<Real>::IntpThinPlateSpline3(int quantity, Real* X, Real* Y, Real* Z, Real* F, Real smooth, bool owner, bool transformToUnitCube)
        : mSmooth(smooth)
    {
        MATHEMATICS_ASSERTION_0(quantity >= 4 && X && Y && Z && F && smooth >= Math<Real>::GetValue(0), "Invalid input\n");

        mInitialized = false;
        quantity = quantity;
        mX = nullptr;  // NEW1<Real>(quantity);
        mY = nullptr;  // NEW1<Real>(quantity);
        mZ = nullptr;  // NEW1<Real>(quantity);
        mA = nullptr;  // NEW1<Real>(quantity);

        int i, row, col;

        if (transformToUnitCube)
        {
            // Map input (x,y,z) to unit cube.  This is not part of the classical
            // thin-plate spline algorithm, because the interpolation is not
            // invariant to scalings.
            mXMin = X[0];
            mXMax = mXMin;
            for (i = 1; i < quantity; ++i)
            {
                if (X[i] < mXMin)
                {
                    mXMin = X[i];
                }
                if (X[i] > mXMax)
                {
                    mXMax = X[i];
                }
            }
            mXInvRange = (Math::GetValue(1)) / (mXMax - mXMin);
            for (i = 0; i < quantity; ++i)
            {
                mX[i] = (X[i] - mXMin) * mXInvRange;
            }

            mYMin = Y[0];
            mYMax = mYMin;
            for (i = 1; i < quantity; ++i)
            {
                if (Y[i] < mYMin)
                {
                    mYMin = Y[i];
                }
                if (Y[i] > mYMax)
                {
                    mYMax = Y[i];
                }
            }
            mYInvRange = (Math::GetValue(1)) / (mYMax - mYMin);
            for (i = 0; i < quantity; ++i)
            {
                mY[i] = (Y[i] - mYMin) * mYInvRange;
            }

            mZMin = Z[0];
            mZMax = mZMin;
            for (i = 1; i < quantity; ++i)
            {
                if (Z[i] < mZMin)
                {
                    mZMin = Z[i];
                }
                if (Z[i] > mZMax)
                {
                    mZMax = Z[i];
                }
            }
            mZInvRange = (Math::GetValue(1)) / (mZMax - mZMin);
            for (i = 0; i < quantity; ++i)
            {
                mZ[i] = (Z[i] - mZMin) * mZInvRange;
            }
        }
        else
        {
            // The classical thin-plate spline uses the data as is.  The values
            // mXMax, mYMax, and mZMax are not used, but they are initialized
            // anyway (to irrelevant numbers).
            mXMin = Math<Real>::GetValue(0);
            mXMax = Math::GetValue(1);
            mXInvRange = Math::GetValue(1);
            mYMin = Math<Real>::GetValue(0);
            mYMax = Math::GetValue(1);
            mYInvRange = Math::GetValue(1);
            mZMin = Math<Real>::GetValue(0);
            mZMax = Math::GetValue(1);
            mZInvRange = Math::GetValue(1);
            memcpy(mX, X, quantity * sizeof(Real));
            memcpy(mY, Y, quantity * sizeof(Real));
            memcpy(mZ, Z, quantity * sizeof(Real));
        }

        // Compute matrix A = M + lambda*I [NxN matrix].
        VariableMatrix<Real> AMat(quantity, quantity);
        for (row = 0; row < quantity; ++row)
        {
            for (col = 0; col < quantity; ++col)
            {
                if (row == col)
                {
                    AMat[row][col] = mSmooth;
                }
                else
                {
                    Real dx = mX[row] - mX[col];
                    Real dy = mY[row] - mY[col];
                    Real dz = mZ[row] - mZ[col];
                    Real t = Math<Real>::Sqrt(dx * dx + dy * dy + dz * dz);
                    AMat[row][col] = Kernel(t);
                }
            }
        }

        // Compute matrix B [Nx4 matrix].
        VariableMatrix<Real> BMat(quantity, 4);
        for (row = 0; row < quantity; ++row)
        {
            BMat[row][0] = Math::GetValue(1);
            BMat[row][1] = mX[row];
            BMat[row][2] = mY[row];
            BMat[row][3] = mZ[row];
        }

        // Compute A^{-1}.
        VariableMatrix<Real> invAMat(quantity, quantity);
        invAMat = LinearSystem<Real>().Inverse(AMat);  //  ß∞‹≈◊≥ˆ“Ï≥£

        // Compute P = B^t A^{-1} [4xN matrix].
        VariableMatrix<Real> PMat = TransposeTimes(BMat, invAMat);

        // Compute Q = P B = B^t A^{-1} B  [4x4 matrix].
        VariableMatrix<Real> QMat = PMat * BMat;

        // Compute Q^{-1}.
        VariableMatrix<Real> invQMat(4, 4);
        invQMat = LinearSystem<Real>().Inverse(QMat);  //  ß∞‹≈◊≥ˆ“Ï≥£

        // Compute P*w.
        Real prod[4];
        for (row = 0; row < 4; ++row)
        {
            prod[row] = Math<Real>::GetValue(0);
            for (i = 0; i < quantity; ++i)
            {
                prod[row] += PMat[row][i] * F[i];
            }
        }

        // Compute 'b' vector for smooth thin plate spline.
        for (row = 0; row < 4; ++row)
        {
            mB[row] = Math<Real>::GetValue(0);
            for (i = 0; i < 4; ++i)
            {
                mB[row] += invQMat[row][i] * prod[i];
            }
        }

        // Compute w-B*b.
        Real* tmp = nullptr;  // NEW1<Real>(quantity);
        for (row = 0; row < quantity; ++row)
        {
            tmp[row] = F[row];
            for (i = 0; i < 4; ++i)
            {
                tmp[row] -= BMat[row][i] * mB[i];
            }
        }

        // Compute 'a' vector for smooth thin plate spline.
        for (row = 0; row < quantity; ++row)
        {
            mA[row] = Math<Real>::GetValue(0);
            for (i = 0; i < quantity; ++i)
            {
                mA[row] += invAMat[row][i] * tmp[i];
            }
        }
        DELETE1(tmp);

        mInitialized = true;

        if (owner)
        {
            DELETE1(X);
            DELETE1(Y);
            DELETE1(Z);
            DELETE1(F);
        }
    }

    template <typename Real>
    IntpThinPlateSpline3<Real>::~IntpThinPlateSpline3()
    {
        DELETE1(mX);
        DELETE1(mY);
        DELETE1(mZ);
        DELETE1(mA);
    }

    template <typename Real>
    bool IntpThinPlateSpline3<Real>::IsInitialized() const
    {
        return mInitialized;
    }

    template <typename Real>
    const Real* IntpThinPlateSpline3<Real>::GetACoefficients() const
    {
        return mA;
    }

    template <typename Real>
    const Real* IntpThinPlateSpline3<Real>::GetBCoefficients() const
    {
        return mB;
    }

    template <typename Real>
    Real IntpThinPlateSpline3<Real>::GetSmooth() const
    {
        return mSmooth;
    }

    template <typename Real>
    Real IntpThinPlateSpline3<Real>::operator()(Real x, Real y, Real z)
    {
        if (mInitialized)
        {
            // Map (x,y,z) to the unit cube.
            x = (x - mXMin) * mXInvRange;
            y = (y - mYMin) * mYInvRange;
            z = (z - mZMin) * mZInvRange;

            Real result = mB[0] + mB[1] * x + mB[2] * y + mB[3] * z;
            for (int i = 0; i < quantity; ++i)
            {
                Real dx = x - mX[i];
                Real dy = y - mY[i];
                Real dz = z - mZ[i];
                Real t = Math<Real>::Sqrt(dx * dx + dy * dy + dz * dz);
                result += mA[i] * Kernel(t);
            }
            return result;
        }

        return Math<Real>::maxReal;
    }

    template <typename Real>
    Real IntpThinPlateSpline3<Real>::ComputeFunctional() const
    {
        Real functional = Math<Real>::GetValue(0);
        for (int row = 0; row < quantity; ++row)
        {
            for (int col = 0; col < quantity; ++col)
            {
                if (row == col)
                {
                    functional += mSmooth * mA[row] * mA[col];
                }
                else
                {
                    Real dx = mX[row] - mX[col];
                    Real dy = mY[row] - mY[col];
                    Real dz = mZ[row] - mZ[col];
                    Real t = Math<Real>::Sqrt(dx * dx + dy * dy + dz * dz);
                    Real k = Kernel(t);
                    functional += k * mA[row] * mA[col];
                }
            }
        }

        if (mSmooth > Math<Real>::GetValue(0))
        {
            functional *= mSmooth;
        }

        return functional;
    }

    template <typename Real>
    Real IntpThinPlateSpline3<Real>::Kernel(Real t)
    {
        return -Math<Real>::FAbs(t);
    }
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE3_DETAIL_H