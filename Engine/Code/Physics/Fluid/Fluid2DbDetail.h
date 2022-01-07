// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 16:23)

#ifndef PHYSICS_FLUID_FLUID2DB_DETAIL_H
#define PHYSICS_FLUID_FLUID2DB_DETAIL_H

#include "Fluid2Db.h"

#if !defined(PHYSICS_EXPORT_TEMPLATE) || defined(PHYSICS_INCLUDED_FLUID2DB_DETAIL)

    #include "System/Helper/PragmaWarning.h"

    #include "Mathematics/Algebra/Vector2DDetail.h"
    #include "Mathematics/Base/MathDetail.h"
    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26481)
    #include SYSTEM_WARNING_DISABLE(26489)
    #include SYSTEM_WARNING_DISABLE(26493)
    #include SYSTEM_WARNING_DISABLE(26487)
namespace Physics
{
    template <typename Real>
    Fluid2Db<Real>::Fluid2Db(Real x0, Real y0, Real x1, Real y1, Real dt,
                             Real denViscosity, Real velViscosity, int imax, int jmax,
                             int numGaussSeidelIterations, bool densityDirichlet)
        : mX0(x0), mY0(y0), mX1(x1), mY1(y1), mDt(dt), mDenViscosity(denViscosity),
          mVelViscosity(velViscosity), mIMax(imax), mJMax(jmax), mNumGaussSeidelIterations(numGaussSeidelIterations), mDensityDirichlet(densityDirichlet)
    {
        mIMaxM1 = mIMax - 1;
        mJMaxM1 = mJMax - 1;
        mIMaxP1 = mIMax + 1;
        mJMaxP1 = mJMax + 1;
        mNumPixels = mIMaxP1 * mJMaxP1;
        mDx = (mX1 - mX0) / (Real)mIMax;
        mDy = (mY1 - mY0) / (Real)mJMax;
        mDxDx = mDx * mDx;
        mDyDy = mDy * mDy;
        mHalfDivDx = ((Real)0.5) / mDx;
        mHalfDivDy = ((Real)0.5) / mDy;
        mDtDivDx = mDt / mDx;
        mDtDivDy = mDt / mDy;
        mDtDivDxDx = mDt / mDxDx;
        mDtDivDyDy = mDt / mDyDy;
        mEpsilon0 = ((Real)0.5) * mDxDx * mDyDy / (mDxDx + mDyDy);
        mEpsilonX = mEpsilon0 / mDxDx;
        mEpsilonY = mEpsilon0 / mDyDy;
        mDenLambdaX = mDenViscosity * mDtDivDxDx;
        mDenLambdaY = mDenViscosity * mDtDivDyDy;
        mVelLambdaX = mVelViscosity * mDtDivDxDx;
        mVelLambdaY = mVelViscosity * mDtDivDyDy;
        mDenGamma0 = ((Real)1) / ((Real)1 + ((Real)2) * (mDenLambdaX + mDenLambdaY));
        mDenGammaX = mDenLambdaX * mDenGamma0;
        mDenGammaY = mDenLambdaY * mDenGamma0;
        mVelGamma0 = ((Real)1) / ((Real)1 + ((Real)2) * (mVelLambdaX + mVelLambdaY));
        mVelGammaX = mVelLambdaX * mVelGamma0;
        mVelGammaY = mVelLambdaY * mVelGamma0;
        mTime = (Real)0;

        mX = nullptr;  //NEW1<Real>(mIMaxP1);
        mY = nullptr;  //NEW1<Real>(mJMaxP1);
        mDensity0 = nullptr;  //NEW2<Real>(mIMaxP1, mJMaxP1);
        mDensity1 = nullptr;  //NEW2<Real>(mIMaxP1, mJMaxP1);
        mVelocity0 = nullptr;  // NEW2<Vector2D>(mIMaxP1, mJMaxP1);
        mVelocity1 = nullptr;  //NEW2<Vector2D>(mIMaxP1, mJMaxP1);
        mDivergence = nullptr;  //NEW2<Real>(mIMaxP1, mJMaxP1);
        mPoisson = nullptr;  //NEW2<Real>(mIMaxP1, mJMaxP1);

        for (int i = 0; i <= mIMax; ++i)
        {
            mX[i] = mX0 + mDx * (Real)i;
        }
        for (int j = 0; j <= mJMax; ++j)
        {
            mY[j] = mY0 + mDy * (Real)j;
        }

        size_t numBytes = mNumPixels * sizeof(Real);
        memset(mDensity0[0], 0, numBytes);
        memset(mDensity1[0], 0, numBytes);
        memset(mDivergence[0], 0, numBytes);
        memset(mPoisson[0], 0, numBytes);

        numBytes = mNumPixels * sizeof(Vector2D);
        memset(mVelocity0[0], 0, numBytes);
        memset(mVelocity1[0], 0, numBytes);
    }

    template <typename Real>
    Fluid2Db<Real>::~Fluid2Db()
    {
        EXCEPTION_TRY
        {
//             DELETE1(mX);
//             DELETE1(mY);
//             DELETE2(mDensity0);
//             DELETE2(mDensity1);
//             DELETE2(mVelocity0);
//             DELETE2(mVelocity1);
//             DELETE2(mDivergence);
//             DELETE2(mPoisson);
        }
        EXCEPTION_ALL_CATCH(Physics)
    }

    template <typename Real>
    void Fluid2Db<Real>::Initialize()
    {
        for (int j = 1; j < mJMax; ++j)
        {
            for (int i = 1; i < mIMax; ++i)
            {
                mDensity1[j][i] = InitialDensity(mX[i], mY[j], i, j);
                mVelocity1[j][i] = InitialVelocity(mX[i], mY[j], i, j);
            }
        }

        UpdateDensityBoundary();
        UpdateVelocityBoundary();

        size_t numBytes = mNumPixels * sizeof(Real);
        memcpy(mDensity0[0], mDensity1[0], numBytes);
        numBytes = mNumPixels * sizeof(Vector2D);
        for (int i = 0; i < mNumPixels; ++i)
        {
            mVelocity0[i] = mVelocity1[i];
        }
    }

    template <typename Real>
    void Fluid2Db<Real>::DoSimulationStep()
    {
        int i = 0, j = 0;
        for (j = 1; j < mJMax; ++j)
        {
            for (i = 1; i < mIMax; ++i)
            {
                // Compute the weights for the advection bilinear interpolation.
                Real iPrevious = i - mDtDivDx * mVelocity0[j][i][0];
                if (iPrevious < (Real)0.5)
                {
                    iPrevious = (Real)0.5;
                }
                else if (iPrevious > (Real)mIMax - (Real)0.5)
                {
                    iPrevious = (Real)mIMax - (Real)0.5;
                }
                const int i0 = (int)Mathematics::Math<Real>::Floor(iPrevious);
                const int i1 = i0 + 1;
                Real a1 = iPrevious - i0;
                Real a0 = (Real)1 - a1;

                Real jPrevious = j - mDtDivDy * mVelocity0[j][i][1];
                if (jPrevious < (Real)0.5)
                {
                    jPrevious = (Real)0.5;
                }
                else if (jPrevious > (Real)mJMax - (Real)0.5)
                {
                    jPrevious = (Real)mJMax - (Real)0.5;
                }
                const int j0 = (int)Mathematics::Math<Real>::Floor(jPrevious);
                const int j1 = j0 + 1;
                Real b1 = jPrevious - j0;
                Real b0 = (Real)1 - b1;

                // Compute the advected density.
                Real d00 = mDensity0[j0][i0];
                Real d10 = mDensity0[j0][i1];
                Real d01 = mDensity0[j1][i0];
                Real d11 = mDensity0[j1][i1];
                Real denAdvect = b0 * (a0 * d00 + a1 * d10) + b1 * (a0 * d01 + a1 * d11);

                // Compute the advected velocity.
                const Vector2D v00 = mVelocity0[j0][i0];
                const Vector2D v10 = mVelocity0[j0][i1];
                const Vector2D v01 = mVelocity0[j1][i0];
                const Vector2D v11 = mVelocity0[j1][i1];
                const Vector2D velAdvect = b0 * (a0 * v00 + a1 * v10) + b1 * (a0 * v01 + a1 * v11);

                // Compute the density at the next time step.
                Real twoDen00 = ((Real)2) * mDensity0[j][i];
                Real denXX = mDensity0[j][i + 1] - twoDen00 + mDensity0[j][i - 1];
                Real denYY = mDensity0[j + 1][i] - twoDen00 + mDensity0[j - 1][i];
                Real denSource = SourceDensity(mTime, mX[i], mY[j], i, j);

                mDensity1[j][i] = denAdvect + ((Real)2) * (mDenLambdaX * denXX + mDenLambdaY * denYY + mDt * denSource);

                if (mDensity1[j][i] < (Real)0)
                {
                    mDensity1[j][i] = (Real)0;
                }

                // Compute the velocity at the next time step.
                const Vector2D twoVel00 = ((Real)2) * mVelocity0[j][i];
                const Vector2D velXX = mVelocity0[j][i + 1] - twoVel00 + mVelocity0[j][i - 1];
                const Vector2D velYY = mVelocity0[j + 1][i] - twoVel00 + mVelocity0[j - 1][i];
                const Vector2D velSource = SourceVelocity(mTime, mX[i], mY[j], i, j);

                mVelocity1[j][i] = velAdvect + ((Real)2) * (mVelLambdaX * velXX + mVelLambdaY * velYY + mDt * velSource);
            }
        }

        // Approximate the divergence of velocity.
        for (j = 1; j < mJMax; ++j)
        {
            for (i = 1; i < mIMax; ++i)
            {
                Real diffX = mVelocity1[j][i + 1][0] - mVelocity1[j][i - 1][0];
                Real diffY = mVelocity1[j + 1][i][1] - mVelocity1[j - 1][i][1];

                mDivergence[j][i] = mHalfDivDx * diffX + mHalfDivDy * diffY;
            }
        }

        // Use zero-valued derivative on boundary to assign divergence.
        NeumannBoundaryZero(mDivergence);

        // Initialize Poisson solution.
        memset(mPoisson[0], 0, mNumPixels * sizeof(Real));

        // Numerically solve Poissonís equation. The boundary values remain zero,
        // so there is no need to call a boundary update function.
        for (int iter = 0; iter < mNumGaussSeidelIterations; ++iter)
        {
            for (j = 1; j < mJMax; ++j)
            {
                for (i = 1; i < mIMax; ++i)
                {
                    Real sumX = mPoisson[j][i + 1] + mPoisson[j][i - 1];
                    Real sumY = mPoisson[j + 1][i] + mPoisson[j - 1][i];

                    mPoisson[j][i] = mEpsilon0 * mDivergence[j][i] + mEpsilonX * sumX + mEpsilonY * sumY;
                }
            }
        }

        // Adjust the velocity v?= v + gradient(poisson).
        for (j = 1; j < mJMax; ++j)
        {
            for (i = 1; i < mIMax; ++i)
            {
                Real diffX = mPoisson[j][i + 1] - mPoisson[j][i - 1];
                Real diffY = mPoisson[j + 1][i] - mPoisson[j - 1][i];

                mVelocity1[j][i][0] += mHalfDivDx * diffX;
                mVelocity1[j][i][1] += mHalfDivDy * diffY;
            }
        }

        UpdateDensityBoundary();
        UpdateVelocityBoundary();
        SwapDensityBuffers();
        SwapVelocityBuffers();

        mTime += mDt;
    }

    template <typename Real>
    void Fluid2Db<Real>::DirichletBoundaryZero(Real** data) noexcept
    {
        // x-edge-interior
        for (int j = 1; j < mJMax; ++j)
        {
            // data = 0 on x-edge i=0
            data[j][0] = (Real)0;

            // data = 0 on x-edge i=imax
            data[j][mIMax] = (Real)0;
        }

        // y-edge-interior
        for (int i = 1; i < mIMax; ++i)
        {
            // data = 0 on y-edge j=0
            data[0][i] = (Real)0;

            // data = 0 on y-edge j=jmax
            data[mJMax][i] = (Real)0;
        }

        // data = 0 at corner (0,0)
        data[0][0] = (Real)0;

        // data = 0 at corner (imax,0)
        data[0][mIMax] = (Real)0;

        // data = 0 at corner (0,jmax)
        data[mJMax][0] = (Real)0;

        // data = 0 at corner (imax,jmax)
        data[mJMax][mIMax] = (Real)0;
    }

    template <typename Real>
    void Fluid2Db<Real>::NeumannBoundaryZero(Real** data) noexcept
    {
        // x-edge-interior
        for (int j = 1; j < mJMax; ++j)
        {
            // (-1,0)*grad(data) = 0 on x-edge i=0
            data[j][0] = data[j][1];

            // (+1,0)*grad(data) = 0 on x-edge i=imax
            data[j][mIMax] = data[j][mIMaxM1];
        }

        // y-edge-interior
        for (int i = 1; i < mIMax; ++i)
        {
            // (0,-1)*grad(data) = 0 on y-edge j=0
            data[0][i] = data[1][i];

            // (0,+1)*grad(data) = 0 on y-edge j=jmax
            data[mJMax][i] = data[mJMaxM1][i];
        }

        // (-1,-1)*grad(data) = 0 at corner (0,0)
        data[0][0] = data[1][1];

        // (+1,-1)*grad(data) = 0 at corner (imax,0)
        data[0][mIMax] = data[1][mIMaxM1];

        // (-1,+1)*grad(data) = 0 at corner (0,jmax)
        data[mJMax][0] = data[mJMaxM1][1];

        // (+1,+1)*grad(data) = 0 at corner (imax,jmax)
        data[mJMax][mIMax] = data[mJMaxM1][mIMaxM1];
    }

    template <typename Real>
    void Fluid2Db<Real>::UpdateDensityBoundary() noexcept
    {
        if (mDensityDirichlet)
        {
            DirichletBoundaryZero(mDensity1);
        }
        else
        {
            NeumannBoundaryZero(mDensity1);
        }
    }

    template <typename Real>
    void Fluid2Db<Real>::UpdateVelocityBoundary()
    {
        // The velocity is (u(x,y), v(x,y)).

        // x-edge-interior
        for (int j = 1; j < mJMax; ++j)
        {
            // u = 0, (-1,0)*grad(v) = 0 on x-edge i=0
            mVelocity1[j][0] = Vector2D((Real)0, mVelocity1[j][1][1]);

            // u = 0, (+1,0)*grad(v) = 0 on x-edge i=imax
            mVelocity1[j][mIMax] = Vector2D((Real)0, mVelocity1[j][mIMaxM1][1]);
        }

        // y-edge-interior
        for (int i = 1; i < mIMax; ++i)
        {
            // (0,-1)*grad(u) = 0, v = 0 on y-edge j=0
            mVelocity1[0][i] = Vector2D(mVelocity1[1][i][0], (Real)0);

            // (0,+1)*grad(u) = 0, v = 0 on y-edge j=jmax
            mVelocity1[mJMax][i] = Vector2D(mVelocity1[mJMaxM1][i][0], (Real)0);
        }

        // (u,v) = (0,0) at corner (0,0)
        mVelocity1[0][0] = Vector2D::GetZero();

        // (u,v) = (0,0) at corner (imax,0)
        mVelocity1[0][mIMax] = Vector2D::GetZero();

        // (u,v) = (0,0) at corner (0,jmax)
        mVelocity1[mJMax][0] = Vector2D::GetZero();

        // (u,v) = (0,0) at corner (imax,jmax)
        mVelocity1[mJMax][mIMax] = Vector2D::GetZero();
    }

    template <typename Real>
    void Fluid2Db<Real>::SwapDensityBuffers() noexcept
    {
        Real** save = mDensity0;
        mDensity0 = mDensity1;
        mDensity1 = save;
    }

    template <typename Real>
    void Fluid2Db<Real>::SwapVelocityBuffers() noexcept
    {
        Vector2D** save = mVelocity0;
        mVelocity0 = mVelocity1;
        mVelocity1 = save;
    }

    template <typename Real>
    Real Fluid2Db<Real>::GetX0() const noexcept
    {
        return mX0;
    }

    template <typename Real>
    Real Fluid2Db<Real>::GetY0() const noexcept
    {
        return mY0;
    }

    template <typename Real>
    Real Fluid2Db<Real>::GetX1() const noexcept
    {
        return mX1;
    }

    template <typename Real>
    Real Fluid2Db<Real>::GetY1() const noexcept
    {
        return mY1;
    }

    template <typename Real>
    Real Fluid2Db<Real>::GetDt() const noexcept
    {
        return mDt;
    }

    template <typename Real>
    Real Fluid2Db<Real>::GetDx() const noexcept
    {
        return mDx;
    }

    template <typename Real>
    Real Fluid2Db<Real>::GetDy() const noexcept
    {
        return mDy;
    }

    template <typename Real>
    Real Fluid2Db<Real>::GetTime() const noexcept
    {
        return mTime;
    }

    template <typename Real>
    int Fluid2Db<Real>::GetIMax() const noexcept
    {
        return mIMax;
    }

    template <typename Real>
    int Fluid2Db<Real>::GetJMax() const noexcept
    {
        return mJMax;
    }

    template <typename Real>
    const Real* Fluid2Db<Real>::GetX() const noexcept
    {
        return mX;
    }

    template <typename Real>
    const Real* Fluid2Db<Real>::GetY() const noexcept
    {
        return mY;
    }

    template <typename Real>
    Real** Fluid2Db<Real>::GetDensity() const noexcept
    {
        return mDensity0;
    }

    template <typename Real>
    Mathematics::Vector2D<Real>** Fluid2Db<Real>::GetVelocity() const noexcept
    {
        return mVelocity0;
    }

}
    #include STSTEM_WARNING_POP
#endif  //  !defined(PHYSICS_EXPORT_TEMPLATE) || defined(PHYSICS_INCLUDED_FLUID2DB_DETAIL)

#endif  // PHYSICS_FLUID_FLUID2DA_DETAIL_H