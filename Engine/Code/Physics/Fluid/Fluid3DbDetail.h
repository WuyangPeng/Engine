// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 16:29)

#ifndef PHYSICS_FLUID_FLUID3DB_DETAIL_H
#define PHYSICS_FLUID_FLUID3DB_DETAIL_H

#include "Fluid3Db.h"

#if !defined(PHYSICS_EXPORT_TEMPLATE) || defined(PHYSICS_INCLUDED_FLUID3DB_DETAIL)

    #include "System/Helper/PragmaWarning.h"
    #include "CoreTools/Helper/MemoryMacro.h"
    #include "Mathematics/Algebra/Vector3DDetail.h"
    #include "Mathematics/Base/MathDetail.h"
    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26481)
    #include SYSTEM_WARNING_DISABLE(26489)
    #include SYSTEM_WARNING_DISABLE(26493)
 #include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26487)
namespace Physics
{
    template <typename Real>
    Fluid3Db<Real>::Fluid3Db(Real x0, Real y0, Real z0, Real x1, Real y1,
                             Real z1, Real dt, Real denViscosity, Real velViscosity, int imax,
                             int jmax, int kmax, int numGaussSeidelIterations, bool densityDirichlet)
        : mX0(x0), mY0(y0), mZ0(z0), mX1(x1), mY1(y1), mZ1(z1), mDt(dt),
          mDenViscosity(denViscosity), mVelViscosity(velViscosity),
          mIMax(imax), mJMax(jmax), mKMax(kmax),
          mNumGaussSeidelIterations(numGaussSeidelIterations),
          mDensityDirichlet(densityDirichlet)
    {
        mIMaxM1 = mIMax - 1;
        mJMaxM1 = mJMax - 1;
        mKMaxM1 = mKMax - 1;
        mIMaxP1 = mIMax + 1;
        mJMaxP1 = mJMax + 1;
        mKMaxP1 = mKMax + 1;
        mNumVoxels = mIMaxP1 * mJMaxP1 * mKMaxP1;
        mDx = (mX1 - mX0) / (Real)mIMax;
        mDy = (mY1 - mY0) / (Real)mJMax;
        mDz = (mZ1 - mZ0) / (Real)mKMax;
        mDxDx = mDx * mDx;
        mDyDy = mDy * mDy;
        mDzDz = mDz * mDz;
        mHalfDivDx = ((Real)0.5) / mDx;
        mHalfDivDy = ((Real)0.5) / mDy;
        mHalfDivDz = ((Real)0.5) / mDz;
        mDtDivDx = mDt / mDx;
        mDtDivDy = mDt / mDy;
        mDtDivDz = mDt / mDz;
        mDtDivDxDx = mDt / mDxDx;
        mDtDivDyDy = mDt / mDyDy;
        mDtDivDzDz = mDt / mDzDz;
        mEpsilon0 = ((Real)0.5) * mDxDx * mDyDy * mDzDz / (mDxDx + mDyDy + mDzDz);
        mEpsilonX = mEpsilon0 / mDxDx;
        mEpsilonY = mEpsilon0 / mDyDy;
        mEpsilonZ = mEpsilon0 / mDzDz;
        mDenLambdaX = mDenViscosity * mDtDivDxDx;
        mDenLambdaY = mDenViscosity * mDtDivDyDy;
        mDenLambdaZ = mDenViscosity * mDtDivDzDz;
        mVelLambdaX = mVelViscosity * mDtDivDxDx;
        mVelLambdaY = mVelViscosity * mDtDivDyDy;
        mVelLambdaZ = mVelViscosity * mDtDivDzDz;
        mDenGamma0 = ((Real)1) / ((Real)1 + ((Real)2) * (mDenLambdaX + mDenLambdaY + mDenLambdaZ));
        mDenGammaX = mDenLambdaX * mDenGamma0;
        mDenGammaY = mDenLambdaY * mDenGamma0;
        mDenGammaZ = mDenLambdaZ * mDenGamma0;
        mVelGamma0 = ((Real)1) / ((Real)1 + ((Real)2) * (mVelLambdaX + mVelLambdaY + mVelLambdaZ));
        mVelGammaX = mVelLambdaX * mVelGamma0;
        mVelGammaY = mVelLambdaY * mVelGamma0;
        mVelGammaZ = mVelLambdaZ * mVelGamma0;
        mTime = (Real)0;

        mX = NEW1<Real>(mIMaxP1);
        mY = NEW1<Real>(mJMaxP1);
        mZ = NEW1<Real>(mKMaxP1);
        mDensity0 = NEW3<Real>(mIMaxP1, mJMaxP1, mKMaxP1);
        mDensity1 = NEW3<Real>(mIMaxP1, mJMaxP1, mKMaxP1);
        mVelocity0 = NEW3<Vector3D>(mIMaxP1, mJMaxP1, mKMaxP1);
        mVelocity1 = NEW3<Vector3D>(mIMaxP1, mJMaxP1, mKMaxP1);
        mDivergence = NEW3<Real>(mIMaxP1, mJMaxP1, mKMaxP1);
        mPoisson = NEW3<Real>(mIMaxP1, mJMaxP1, mKMaxP1);

        for (int i = 0; i <= mIMax; ++i)
        {
            mX[i] = mX0 + mDx * (Real)i;
        }
        for (int j = 0; j <= mJMax; ++j)
        {
            mY[j] = mY0 + mDy * (Real)j;
        }
        for (int k = 0; k <= mKMax; ++k)
        {
            mZ[k] = mZ0 + mDz * (Real)k;
        }

        size_t numBytes = mNumVoxels * sizeof(Real);
        memset(mDensity0[0][0], 0, numBytes);
        memset(mDensity1[0][0], 0, numBytes);
        memset(mDivergence[0][0], 0, numBytes);
        memset(mPoisson[0][0], 0, numBytes);

        numBytes = mNumVoxels * sizeof(Vector3D);
        memset(mVelocity0[0][0], 0, numBytes);
        memset(mVelocity1[0][0], 0, numBytes);
    }

    template <typename Real>
    Fluid3Db<Real>::~Fluid3Db()
    {
        EXCEPTION_TRY
        {
            DELETE1(mX);
            DELETE1(mY);
            DELETE1(mZ);
            DELETE3(mDensity0);
            DELETE3(mDensity1);
            DELETE3(mVelocity0);
            DELETE3(mVelocity1);
            DELETE3(mDivergence);
            DELETE3(mPoisson);
        }
        EXCEPTION_ALL_CATCH(Physics)
    }

    template <typename Real>
    void Fluid3Db<Real>::Initialize()
    {
        for (int k = 1; k < mKMax; ++k)
        {
            for (int j = 1; j < mJMax; ++j)
            {
                for (int i = 1; i < mIMax; ++i)
                {
                    mDensity1[k][j][i] = InitialDensity(mX[i], mY[j], mZ[k], i, j, k);

                    mVelocity1[k][j][i] = InitialVelocity(mX[i], mY[j], mZ[k], i, j, k);
                }
            }
        }

        UpdateDensityBoundary();
        UpdateVelocityBoundary();

        size_t numBytes = mNumVoxels * sizeof(Real);
        memcpy(mDensity0[0][0], mDensity1[0][0], numBytes);
        numBytes = mNumVoxels * sizeof(Vector3D);
        for (int i = 0; i < mNumVoxels; ++i)
        {
            mVelocity0[i] = mVelocity1[i];
        }
    }

    template <typename Real>
    void Fluid3Db<Real>::DoSimulationStep()
    {
        int i = 0, j = 0, k = 0;
        for (k = 1; k < mKMax; ++k)
        {
            for (j = 1; j < mJMax; ++j)
            {
                for (i = 1; i < mIMax; ++i)
                {
                    // Compute the weights for the advection bilinear interpolation.
                    Real iPrevious = i - mDtDivDx * mVelocity0[k][j][i][0];
                    if (iPrevious < (Real)0.5)
                    {
                        iPrevious = (Real)0.5;
                    }
                    else if (iPrevious > (Real)mIMax - (Real)0.5)
                    {
                        iPrevious = (Real)mIMax - (Real)0.5;
                    }

                   const  int i0 = (int)Mathematics::Math<Real>::Floor(iPrevious);
                    const int i1 = i0 + 1;
                    Real a1 = iPrevious - i0;
                    Real a0 = (Real)1 - a1;

                    Real jPrevious = j - mDtDivDy * mVelocity0[k][j][i][1];
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

                    Real kPrevious = k - mDtDivDz * mVelocity0[k][j][i][2];
                    if (kPrevious < (Real)0.5)
                    {
                        kPrevious = (Real)0.5;
                    }
                    else if (kPrevious > (Real)mKMax - (Real)0.5)
                    {
                        kPrevious = (Real)mKMax - (Real)0.5;
                    }

                 const int k0 = (int)Mathematics::Math<Real>::Floor(kPrevious);
                    const int k1 = k0 + 1;
                    Real c1 = kPrevious - k0;
                    Real c0 = (Real)1 - c1;

                    // Compute the advected density.
                    Real d000 = mDensity0[k0][j0][i0];
                    Real d100 = mDensity0[k0][j0][i1];
                    Real d010 = mDensity0[k0][j1][i0];
                    Real d110 = mDensity0[k0][j1][i1];
                    Real d001 = mDensity0[k1][j0][i0];
                    Real d101 = mDensity0[k1][j0][i1];
                    Real d011 = mDensity0[k1][j1][i0];
                    Real d111 = mDensity0[k1][j1][i1];
                    Real denAdvect = c0 * (b0 * (a0 * d000 + a1 * d100) + b1 * (a0 * d010 + a1 * d110)) + c1 * (b0 * (a0 * d001 + a1 * d101) + b1 * (a0 * d011 + a1 * d111));

                    // Compute the advected velocity.
                    const Vector3D v000 = mVelocity0[k0][j0][i0];
                    const Vector3D v100 = mVelocity0[k0][j0][i1];
                    const Vector3D v010 = mVelocity0[k0][j1][i0];
                    const Vector3D v110 = mVelocity0[k0][j1][i1];
                    const Vector3D v001 = mVelocity0[k1][j0][i0];
                    const Vector3D v101 = mVelocity0[k1][j0][i1];
                    const Vector3D v011 = mVelocity0[k1][j1][i0];
                    const Vector3D v111 = mVelocity0[k1][j1][i1];
                    const Vector3D velAdvect = c0 * (b0 * (a0 * v000 + a1 * v100) + b1 * (a0 * v010 + a1 * v110)) + c1 * (b0 * (a0 * v001 + a1 * v101) + b1 * (a0 * v011 + a1 * v111));

                    Real sumX = mDensity1[k][j][i + 1] + mDensity1[k][j][i - 1];
                    Real sumY = mDensity1[k][j + 1][i] + mDensity1[k][j - 1][i];
                    Real sumZ = mDensity1[k + 1][j][i] + mDensity1[k - 1][j][i];

                    mDensity1[k][j][i] = mDenGamma0 * mDensity0[k][j][i] + mDenGammaX * sumX + mDenGammaY * sumY + mDenGammaZ * sumZ;

                    // Compute the density at the next time step.
                    Real twoDen00 = ((Real)2) * mDensity0[k][j][i];
                    Real denXX = mDensity0[k][j][i + 1] - twoDen00 + mDensity0[k][j][i - 1];
                    Real denYY = mDensity0[k][j + 1][i] - twoDen00 + mDensity0[k][j - 1][i];
                    Real denZZ = mDensity0[k + 1][j][i] - twoDen00 + mDensity0[k - 1][j][i];
                    Real denSource = SourceDensity(mTime, mX[i], mY[j], mZ[k], i, j, k);

                    mDensity1[k][j][i] = denAdvect + ((Real)2) * (mDenLambdaX * denXX + mDenLambdaY * denYY + mDenLambdaZ * denZZ + mDt * denSource);

                    if (mDensity1[k][j][i] < (Real)0)
                    {
                        mDensity1[k][j][i] = (Real)0;
                    }

                    // Compute the velocity at the next time step.
                    const Vector3D twoVel00 = ((Real)2) * mVelocity0[k][j][i];
                    const Vector3D velXX = mVelocity0[k][j][i + 1] - twoVel00 + mVelocity0[k][j][i - 1];
                    const Vector3D velYY = mVelocity0[k][j + 1][i] - twoVel00 + mVelocity0[k][j - 1][i];
                    const Vector3D velZZ = mVelocity0[k + 1][j][i] - twoVel00 + mVelocity0[k - 1][j][i];
                    const Vector3D velSource = SourceVelocity(mTime, mX[i], mY[j], mZ[k], i, j, k);

                    mVelocity1[k][j][i] = velAdvect + ((Real)2) * (mVelLambdaX * velXX + mVelLambdaY * velYY + mVelLambdaX * velZZ + mDt * velSource);
                }
            }
        }

        // Approximate the divergence of velocity.
        for (k = 1; k < mKMax; ++k)
        {
            for (j = 1; j < mJMax; ++j)
            {
                for (i = 1; i < mIMax; ++i)
                {
                    Real diffX = mVelocity1[k][j][i + 1][0] - mVelocity1[k][j][i - 1][0];

                    Real diffY = mVelocity1[k][j + 1][i][1] - mVelocity1[k][j - 1][i][1];

                    Real diffZ = mVelocity1[k + 1][j][i][2] - mVelocity1[k - 1][j][i][2];

                    mDivergence[k][j][i] = mHalfDivDx * diffX + mHalfDivDy * diffY + mHalfDivDz * diffZ;
                }
            }
        }

        // Use zero-valued derivative on boundary to assign divergence.
        NeumannBoundaryZero(mDivergence);

        // Initialize Poisson solution.
        memset(mPoisson[0][0], 0, mNumVoxels * sizeof(Real));

        // Numerically solve Poissonís equation. The boundary values remain zero,
        // so there is no need to call a boundary update function.
        for (int iter = 0; iter < mNumGaussSeidelIterations; ++iter)
        {
            for (k = 1; k < mKMax; ++k)
            {
                for (j = 1; j < mJMax; ++j)
                {
                    for (i = 1; i < mIMax; ++i)
                    {
                        Real sumX = mPoisson[k][j][i + 1] + mPoisson[k][j][i - 1];
                        Real sumY = mPoisson[k][j + 1][i] + mPoisson[k][j - 1][i];
                        Real sumZ = mPoisson[k + 1][j][i] + mPoisson[k - 1][j][i];

                        mPoisson[k][j][i] = mEpsilon0 * mDivergence[k][j][i] + mEpsilonX * sumX + mEpsilonY * sumY + mEpsilonZ * sumZ;
                    }
                }
            }
        }

        // Adjust the velocity v?= v + gradient(poisson).
        for (k = 1; k < mKMax; ++k)
        {
            for (j = 1; j < mJMax; ++j)
            {
                for (i = 1; i < mIMax; ++i)
                {
                    Real diffX = mPoisson[k][j][i + 1] - mPoisson[k][j][i - 1];
                    Real diffY = mPoisson[k][j + 1][i] - mPoisson[k][j - 1][i];
                    Real diffZ = mPoisson[k + 1][j][i] - mPoisson[k - 1][j][i];

                    mVelocity1[k][j][i][0] += mHalfDivDx * diffX;
                    mVelocity1[k][j][i][1] += mHalfDivDy * diffY;
                    mVelocity1[k][j][i][2] += mHalfDivDz * diffZ;
                }
            }
        }

        UpdateDensityBoundary();
        UpdateVelocityBoundary();
        SwapDensityBuffers();
        SwapVelocityBuffers();

        mTime += mDt;
    }

    template <typename Real>
    void Fluid3Db<Real>::DirichletBoundaryZero(Real*** data) noexcept
    {
        int i = 0, j = 0, k = 0;

        // x-face-interior
        for (k = 1; k < mKMax; ++k)
        {
            for (j = 1; j < mJMax; ++j)
            {
                // data = 0 on x-face i=0
                data[k][j][0] = (Real)0;

                // data = 0 on x-face i=imax
                data[k][j][mIMax] = (Real)0;
            }
        }

        // y-face-interior
        for (k = 0; k <= mKMax; ++k)
        {
            for (i = 0; i <= mIMax; ++i)
            {
                // data = 0 on y-face j=0
                data[k][0][i] = (Real)0;

                // data = 0 on y-face j=jmax
                data[k][mJMax][i] = (Real)0;
            }
        }

        // z-face-interior
        for (j = 0; j <= mJMax; ++j)
        {
            for (i = 0; i <= mIMax; ++i)
            {
                // data = 0 on z-face k=0
                data[0][j][i] = (Real)0;

                // data = 0 on z-face k=kmax
                data[mKMax][j][i] = (Real)0;
            }
        }

        // x-edge-interior
        for (i = 1; i < mIMax; ++i)
        {
            // data = 0 on x-edge (j,k)=(0,0)
            data[0][0][i] = (Real)0;

            // data = 0 on x-edge (j,k)=(jmax,0)
            data[0][mJMax][i] = (Real)0;

            // data = 0 on x-edge (j,k)=(0,kmax)
            data[mKMax][0][i] = (Real)0;

            // data = 0 on x-edge (j,k)=(jmax,kmax)
            data[mKMax][mJMax][i] = (Real)0;
        }

        // y-edge-interior
        for (j = 1; j < mJMax; ++j)
        {
            // data = 0 on y-edge (i,k)=(0,0)
            data[0][j][0] = (Real)0;

            // data = 0 on y-edge (i,k)=(imax,0)
            data[0][j][mIMax] = (Real)0;

            // data = 0 on y-edge (i,k)=(0,kmax)
            data[mKMax][j][0] = (Real)0;

            // data = 0 on y-edge (i,k)=(imax,kmax)
            data[mKMax][j][mIMax] = (Real)0;
        }

        // z-edge-interior
        for (k = 1; k < mKMax; ++k)
        {
            // data = 0 on z-edge (i,j)=(0,0)
            data[k][0][0] = (Real)0;

            // data = 0 on z-edge (i,j)=(imax,0)
            data[k][0][mIMax] = (Real)0;

            // data = 0 on z-edge (i,j)=(0,jmax)
            data[k][mJMax][0] = (Real)0;

            // data = 0 on z-edge (i,j)=(imax,jmax)
            data[k][mJMax][mIMax] = (Real)0;
        }

        // data = 0 at corner (0,0,0)
        data[0][0][0] = (Real)0;

        // data = 0 at corner (imax,0,0)
        data[0][0][mIMax] = (Real)0;

        // data = 0 at corner (0,jmax,0)
        data[0][mJMax][0] = (Real)0;

        // data = 0 at corner (imax,jmax,0)
        data[0][mJMax][mIMax] = (Real)0;

        // data = 0 at corner (0,0,kmax)
        data[mKMax][0][0] = (Real)0;

        // data = 0 at corner (imax,0,kmax)
        data[mKMax][0][mIMax] = (Real)0;

        // data = 0 at corner (0,jmax,kmax)
        data[mKMax][mJMax][0] = (Real)0;

        // data = 0 at corner (imax,jmax,kmax)
        data[mKMax][mJMax][mIMax] = (Real)0;
    }

    template <typename Real>
    void Fluid3Db<Real>::NeumannBoundaryZero(Real*** data) noexcept
    {
        int i = 0, j = 0, k = 0;

        // x-face-interior
        for (k = 1; k < mKMax; ++k)
        {
            for (j = 1; j < mJMax; ++j)
            {
                // (-1,0,0)*grad(data) = 0 on x-face i=0
                data[k][j][0] = data[k][j][1];

                // (+1,0,0)*grad(data) = 0 on x-face i=imax
                data[k][j][mIMax] = data[k][j][mIMaxM1];
            }
        }

        // y-face-interior
        for (k = 0; k <= mKMax; ++k)
        {
            for (i = 0; i <= mIMax; ++i)
            {
                // (0,-1,0)*grad(data) = 0 on y-face j=0
                data[k][0][i] = data[k][1][i];

                // (0,+1,0)*grad(data) = 0 on y-face j=jmax
                data[k][mJMax][i] = data[k][mJMaxM1][i];
            }
        }

        // z-face-interior
        for (j = 0; j <= mJMax; ++j)
        {
            for (i = 0; i <= mIMax; ++i)
            {
                // (0,0,-1)*grad(data) = 0 on z-face k=0
                data[0][j][i] = data[1][j][i];

                // (0,0,+1)*grad(data) = 0 on z-face k=kmax
                data[mKMax][j][i] = data[mKMaxM1][j][i];
            }
        }

        // x-edge-interior
        for (i = 1; i < mIMax; ++i)
        {
            // (0,-1,-1)*grad(data) = 0 on x-edge (j,k)=(0,0)
            data[0][0][i] = data[1][1][i];

            // (0,+1,-1)*grad(data) = 0 on x-edge (j,k)=(jmax,0)
            data[0][mJMax][i] = data[1][mJMaxM1][i];

            // (0,-1,+1)*grad(data) = 0 on x-edge (j,k)=(0,kmax)
            data[mKMax][0][i] = data[mKMaxM1][1][i];

            // (0,+1,+1)*grad(data) = 0 on x-edge (j,k)=(jmax,kmax)
            data[mKMax][mJMax][i] = data[mKMaxM1][mJMaxM1][i];
        }

        // y-edge-interior
        for (j = 1; j < mJMax; ++j)
        {
            // (-1,0,-1)*grad(data) = 0 on y-edge (i,k)=(0,0)
            data[0][j][0] = data[1][j][1];

            // (+1,0,-1)*grad(data) = 0 on y-edge (i,k)=(imax,0)
            data[0][j][mIMax] = data[1][j][mIMaxM1];

            // (-1,0,+1)*grad(data) = 0 on y-edge (i,k)=(0,kmax)
            data[mKMax][j][0] = data[mKMaxM1][j][1];

            // (+1,0,+1)*grad(data) = 0 on y-edge (i,k)=(imax,kmax)
            data[mKMax][j][mIMax] = data[mKMaxM1][j][mJMaxM1];
        }

        // z-edge-interior
        for (k = 1; k < mKMax; ++k)
        {
            // (-1,-1,0)*grad(data) = 0 on z-edge (i,j)=(0,0)
            data[k][0][0] = data[k][1][1];

            // (+1,-1,0)*grad(data) = 0 on z-edge (i,j)=(imax,0)
            data[k][0][mIMax] = data[k][1][mIMaxM1];

            // (-1,+1,0)*grad(data) = 0 on z-edge (i,j)=(0,jmax)
            data[k][mJMax][0] = data[k][mJMaxM1][1];

            // (+1,+1,0)*grad(data) = 0 on z-edge (i,j)=(imax,jmax)
            data[k][mJMax][mIMax] = data[k][mJMaxM1][mIMaxM1];
        }

        // (-1,-1,-1)*grad(data) = 0 at corner (0,0,0)
        data[0][0][0] = data[1][1][1];

        // (+1,-1,-1)*grad(data) = 0 at corner (imax,0,0)
        data[0][0][mIMax] = data[1][1][mIMaxM1];

        // (-1,+1,-1)*grad(data) = 0 at corner (0,jmax,0)
        data[0][mJMax][0] = data[1][mJMaxM1][1];

        // (+1,+1,-1)*grad(data) = 0 at corner (imax,jmax,0)
        data[0][mJMax][mIMax] = data[1][mJMaxM1][mIMaxM1];

        // (-1,-1,+1)*grad(data) = 0 at corner (0,0,kmax)
        data[mKMax][0][0] = data[mKMaxM1][1][1];

        // (+1,-1,+1)*grad(data) = 0 at corner (imax,0,kmax)
        data[mKMax][0][mIMax] = data[mKMaxM1][1][mIMaxM1];

        // (-1,+1,+1)*grad(data) = 0 at corner (0,jmax,kmax)
        data[mKMax][mJMax][0] = data[mKMaxM1][mJMaxM1][1];

        // (+1,+1,+1)*grad(data) = 0 at corner (imax,jmax,kmax)
        data[mKMax][mJMax][mIMax] = data[mKMaxM1][mJMaxM1][mIMaxM1];
    }

    template <typename Real>
    void Fluid3Db<Real>::UpdateDensityBoundary() noexcept
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
    void Fluid3Db<Real>::UpdateVelocityBoundary()
    {
        // The velocity is (u(x,y,z), v(x,y,z), w(x,y,z)).
        int i = 0, j = 0, k = 0;

        // x-face-interior
        for (k = 1; k < mKMax; ++k)
        {
            for (j = 1; j < mJMax; ++j)
            {
                // u=0, (-1,0,0)*grad(v)=0, (-1,0,0)*grad(w)=0 on x-face i=0
                mVelocity1[k][j][0] = Vector3D((Real)0, mVelocity1[k][j][1][1], mVelocity1[k][j][1][2]);

                // u=0, (+1,0,0)*grad(v)=0, (-1,0,0)*grad(w)=0 on x-face i=imax
                mVelocity1[k][j][mIMax] = Vector3D((Real)0, mVelocity1[k][j][mIMaxM1][1], mVelocity1[k][j][mIMaxM1][2]);
            }
        }

        // y-face-interior
        for (k = 0; k <= mKMax; ++k)
        {
            for (i = 0; i <= mIMax; ++i)
            {
                // (0,-1,0)*grad(u)=0, v=0, (0,-1,0)*grad(w)=0 on y-face j=0
                mVelocity1[k][0][i] = Vector3D(mVelocity1[k][1][i][0], (Real)0, mVelocity1[k][1][i][2]);

                // (0,+1,0)*grad(u)=0, v=0, (0,+1,0)*grad(w) on y-face j=jmax
                mVelocity1[k][mJMax][i] = Vector3D(mVelocity1[k][mJMaxM1][i][0], (Real)0, mVelocity1[k][mJMaxM1][i][2]);
            }
        }

        // z-face-interior
        for (j = 0; j <= mJMax; ++j)
        {
            for (i = 0; i <= mIMax; ++i)
            {
                // (0,0,-1)*grad(u)=0, (0,0,-1)*grad(v)=0, w=0 on z-face k=0
                mVelocity1[0][j][i] = Vector3D(mVelocity1[1][j][i][0], mVelocity1[1][j][i][1], (Real)0);

                // (0,0,+1)*grad(u)=0, (0,0,+1)*grad(v)=0, w=0 on z-face k=kmax
                mVelocity1[mKMax][j][i] = Vector3D(mVelocity1[mKMaxM1][j][i][0], mVelocity1[mKMaxM1][j][i][1], (Real)0);
            }
        }

        // x-edge-interior
        for (i = 1; i < mIMax; ++i)
        {
            // (0,-1,-1)*grad(u)=0, v=0, w=0 on x-edge (j,k)=(0,0)
            mVelocity1[0][0][i] = Vector3D(mVelocity1[1][1][i][0], (Real)0, (Real)0);

            // (0,+1,-1)*grad(u)=0, v=0, w=0 on x-edge (j,k)=(jmax,0)
            mVelocity1[0][mJMax][i] = Vector3D(mVelocity1[1][mJMaxM1][i][0], (Real)0, (Real)0);

            // (0,-1,+1)*grad(u)=0, v=0, w=0 on x-edge (j,k)=(0,kmax)
            mVelocity1[mKMax][0][i] = Vector3D(mVelocity1[mKMaxM1][1][i][0], (Real)0, (Real)0);

            // (0,+1,+1)*grad(u)=0, v=0, w=0 on x-edge (j,k)=(jmax,kmax)
            mVelocity1[mKMax][mJMax][i] = Vector3D(mVelocity1[mKMaxM1][mJMaxM1][i][0], (Real)0, (Real)0);
        }

        // y-edge-interior
        for (j = 1; j < mJMax; ++j)
        {
            // u=0, (-1,0,-1)*grad(v)=0, w=0 on y-edge (i,k)=(0,0)
            mVelocity1[0][j][0] = Vector3D((Real)0, mVelocity1[1][j][1][1], (Real)0);

            // u=0, (+1,0,-1)*grad(v)=0, w=0 on y-edge (i,k)=(imax,0)
            mVelocity1[0][j][mIMax] = Vector3D((Real)0, mVelocity1[1][j][mIMaxM1][1], (Real)0);

            // u=0, (-1,0,+1)*grad(v)=0, w=0 on y-edge (i,k)=(0,kmax)
            mVelocity1[mKMax][j][0] = Vector3D((Real)0, mVelocity1[mKMaxM1][j][1][1], (Real)0);

            // u=0, (+1,0,+1)*grad(v)=0, w=0 on y-edge (i,k)=(imax,kmax)
            mVelocity1[mKMax][j][mIMax] = Vector3D((Real)0, mVelocity1[mKMaxM1][j][mJMaxM1][1], (Real)0);
        }

        // z-edge-interior
        for (k = 1; k < mKMax; ++k)
        {
            // u=0, v=0, (-1,-1,0)*grad(w)=0 on z-edge (i,j)=(0,0)
            mVelocity1[k][0][0] = Vector3D((Real)0, (Real)0, mVelocity1[k][1][1][2]);

            // u=0, v=0, (+1,-1,0)*grad(w)=0 on z-edge (i,j)=(imax,0)
            mVelocity1[k][0][mIMax] = Vector3D((Real)0, (Real)0, mVelocity1[k][1][mIMaxM1][2]);

            // u=0, v=0, (-1,+1,0)*grad(w)=0 on z-edge (i,j)=(0,jmax)
            mVelocity1[k][mJMax][0] = Vector3D((Real)0, (Real)0, mVelocity1[k][mJMaxM1][1][2]);

            // u=0, v=0, (+1,+1,0)*grad(w)=0 on z-edge (i,j)=(imax,jmax)
            mVelocity1[k][mJMax][mIMax] = Vector3D((Real)0, (Real)0, mVelocity1[k][mJMaxM1][mIMaxM1][2]);
        }

        // (u,v,w) = (0,0,0) at corner (0,0,0)
        mVelocity1[0][0][0] = Vector3D::sm_Zero;

        // (u,v,w) = (0,0,0) at corner (imax,0,0)
        mVelocity1[0][0][mIMax] = Vector3D::sm_Zero;

        // (u,v,w) = (0,0,0) at corner (0,jmax,0)
        mVelocity1[0][mJMax][0] = Vector3D::sm_Zero;

        // (u,v,w) = (0,0,0) at corner (imax,jmax,0)
        mVelocity1[0][mJMax][mIMax] = Vector3D::sm_Zero;

        // (u,v,w) = (0,0,0) at corner (0,0,kmax)
        mVelocity1[mKMax][0][0] = Vector3D::sm_Zero;

        // (u,v,w) = (0,0,0) at corner (imax,0,kmax)
        mVelocity1[mKMax][0][mIMax] = Vector3D::sm_Zero;

        // (u,v,w) = (0,0,0) at corner (0,jmax,kmax)
        mVelocity1[mKMax][mJMax][0] = Vector3D::sm_Zero;

        // (u,v,w) = (0,0,0) at corner (imax,jmax,kmax)
        mVelocity1[mKMax][mJMax][mIMax] = Vector3D::sm_Zero;
    }

    template <typename Real>
    void Fluid3Db<Real>::SwapDensityBuffers() noexcept
    {
        Real*** save = mDensity0;
        mDensity0 = mDensity1;
        mDensity1 = save;
    }

    template <typename Real>
    void Fluid3Db<Real>::SwapVelocityBuffers() noexcept
    {
        Vector3D*** save = mVelocity0;
        mVelocity0 = mVelocity1;
        mVelocity1 = save;
    }

    template <typename Real>
    Real Fluid3Db<Real>::GetX0() const noexcept
    {
        return mX0;
    }

    template <typename Real>
    Real Fluid3Db<Real>::GetY0() const noexcept
    {
        return mY0;
    }

    template <typename Real>
    Real Fluid3Db<Real>::GetZ0() const noexcept
    {
        return mZ0;
    }

    template <typename Real>
    Real Fluid3Db<Real>::GetX1() const noexcept
    {
        return mX1;
    }

    template <typename Real>
    Real Fluid3Db<Real>::GetY1() const noexcept
    {
        return mY1;
    }

    template <typename Real>
    Real Fluid3Db<Real>::GetZ1() const noexcept
    {
        return mZ1;
    }

    template <typename Real>
    Real Fluid3Db<Real>::GetDt() const noexcept
    {
        return mDt;
    }

    template <typename Real>
    Real Fluid3Db<Real>::GetDx() const noexcept
    {
        return mDx;
    }

    template <typename Real>
    Real Fluid3Db<Real>::GetDy() const noexcept
    {
        return mDy;
    }

    template <typename Real>
    Real Fluid3Db<Real>::GetDz() const noexcept
    {
        return mDz;
    }

    template <typename Real>
    Real Fluid3Db<Real>::GetTime() const noexcept
    {
        return mTime;
    }

    template <typename Real>
    int Fluid3Db<Real>::GetIMax() const noexcept
    {
        return mIMax;
    }

    template <typename Real>
    int Fluid3Db<Real>::GetJMax() const noexcept
    {
        return mJMax;
    }

    template <typename Real>
    int Fluid3Db<Real>::GetKMax() const noexcept
    {
        return mKMax;
    }

    template <typename Real>
    const Real* Fluid3Db<Real>::GetX() const noexcept
    {
        return mX;
    }

    template <typename Real>
    const Real* Fluid3Db<Real>::GetY() const noexcept
    {
        return mY;
    }

    template <typename Real>
    const Real* Fluid3Db<Real>::GetZ() const noexcept
    {
        return mZ;
    }

    template <typename Real>
    Real*** Fluid3Db<Real>::GetDensity() const noexcept
    {
        return mDensity0;
    }

    template <typename Real>
    Mathematics::Vector3D<Real>*** Fluid3Db<Real>::GetVelocity() const noexcept
    {
        return mVelocity0;
    }
}
    #include STSTEM_WARNING_POP
#endif  //  !defined(PHYSICS_EXPORT_TEMPLATE) || defined(PHYSICS_INCLUDED_FLUID3DB_DETAIL)

#endif  // PHYSICS_FLUID_FLUID3DB_DETAIL_H