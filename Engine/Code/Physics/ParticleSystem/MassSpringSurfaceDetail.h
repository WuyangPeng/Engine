// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 18:10)

#ifndef PHYSICS_PARTICLE_SYSTEM_MASS_SPRING_SURFACE_DETAIL_H
#define PHYSICS_PARTICLE_SYSTEM_MASS_SPRING_SURFACE_DETAIL_H

#include "MassSpringSurface.h"

namespace Physics
{
    template <typename Real, typename TVector>
    MassSpringSurface<Real, TVector>::MassSpringSurface(int numRows, int numCols, Real step)
        : ParticleSystemManager<Real, TVector>(numRows * numCols, step)
    {
        mNumRows = numRows;
        mNumCols = numCols;
        mNumRowsM1 = mNumRows - 1;
        mNumColsM1 = mNumCols - 1;

        mPositionGrid = nullptr;  // NEW1<TVector*>(mNumRows);
        mVelocityGrid = nullptr;  // NEW1<TVector*>(mNumRows);
        for (int row = 0; row < mNumRows; ++row)
        {
            mPositionGrid[row] = &mPositions[mNumCols * row];
            mVelocityGrid[row] = &mVelocities[mNumCols * row];
        }

        mConstantsR = nullptr;  // NEW2<Real>(mNumCols, mNumRowsM1);
        mLengthsR = nullptr;  // NEW2<Real>(mNumCols, mNumRowsM1);
        mConstantsC = nullptr;  // NEW2<Real>(mNumColsM1, mNumRows);
        mLengthsC = nullptr;  //NEW2<Real>(mNumColsM1, mNumRows);
    }

    template <typename Real, typename TVector>
    MassSpringSurface<Real, TVector>::~MassSpringSurface()
    {
//         DELETE1(mPositionGrid);
//         DELETE1(mVelocityGrid);
//         DELETE2(mConstantsR);
//         DELETE2(mLengthsR);
//         DELETE2(mConstantsC);
//         DELETE2(mLengthsC);
    }

    template <typename Real, typename TVector>
    int MassSpringSurface<Real, TVector>::GetNumRows() const
    {
        return mNumRows;
    }

    template <typename Real, typename TVector>
    int MassSpringSurface<Real, TVector>::GetNumCols() const
    {
        return mNumCols;
    }

    template <typename Real, typename TVector>
    void MassSpringSurface<Real, TVector>::SetMass(int row, int col, Real mass)
    {
        ParticleSystemManager<Real, TVector>::SetMass(GetIndex(row, col), mass);
    }

    template <typename Real, typename TVector>
    Real MassSpringSurface<Real, TVector>::GetMass(int row, int col) const
    {
        return ParticleSystemManager<Real, TVector>::GetMass(GetIndex(row, col));
    }

    template <typename Real, typename TVector>
    TVector** MassSpringSurface<Real, TVector>::Positions2D() const
    {
        return mPositionGrid;
    }

    template <typename Real, typename TVector>
    TVector& MassSpringSurface<Real, TVector>::Position(int row, int col)
    {
        return ParticleSystemManager<Real, TVector>::Position(GetIndex(row, col));
    }

    template <typename Real, typename TVector>
    TVector** MassSpringSurface<Real, TVector>::Velocities2D() const
    {
        return mVelocityGrid;
    }

    template <typename Real, typename TVector>
    TVector& MassSpringSurface<Real, TVector>::Velocity(int row, int col)
    {
        return ParticleSystemManager<Real, TVector>::Velocity(GetIndex(row, col));
    }

    template <typename Real, typename TVector>
    Real& MassSpringSurface<Real, TVector>::ConstantR(int row, int col)
    {
        return mConstantsR[row][col];
    }

    template <typename Real, typename TVector>
    Real& MassSpringSurface<Real, TVector>::LengthR(int row, int col)
    {
        return mLengthsR[row][col];
    }

    template <typename Real, typename TVector>
    Real& MassSpringSurface<Real, TVector>::ConstantC(int row, int col)
    {
        return mConstantsC[row][col];
    }

    template <typename Real, typename TVector>
    Real& MassSpringSurface<Real, TVector>::LengthC(int row, int col)
    {
        return mLengthsC[row][col];
    }

    template <typename Real, typename TVector>
    TVector MassSpringSurface<Real, TVector>::Acceleration(int i, Real time, const TVector* positions, const TVector* velocities)
    {
        // Compute spring forces on position X[i].  The positions are not
        // necessarily mPositions since the RK4 solver in ParticleSystem
        // evaluates the acceleration function at intermediate positions.  The
        // edge and corner points of the surface of masses must be handled
        // separately since each has fewer than four springs attached to it.

        TVector acceleration = ExternalAcceleration(i, time, positions, velocities);

        TVector diff, force;
        Real ratio;

        int row, col, prev, next;
        GetCoordinates(i, row, col);

        if (row > 0)
        {
            prev = i - mNumCols;  // index to previous row-neighbor
            diff = positions[prev] - positions[i];
            ratio = LengthR(row - 1, col) / TVector::ToolsType::VectorMagnitude(diff);
            force = ConstantR(row - 1, col) * ((Real)1 - ratio) * diff;
            acceleration += mInvMasses[i] * force;
        }

        if (row < mNumRowsM1)
        {
            next = i + mNumCols;  // index to next row-neighbor
            diff = positions[next] - positions[i];
            ratio = LengthR(row, col) / TVector::ToolsType::VectorMagnitude(diff);
            force = ConstantR(row, col) * ((Real)1 - ratio) * diff;
            acceleration += mInvMasses[i] * force;
        }

        if (col > 0)
        {
            prev = i - 1;  // index to previous col-neighbor
            diff = positions[prev] - positions[i];
            ratio = LengthC(row, col - 1) / TVector::ToolsType::VectorMagnitude(diff);
            force = ConstantC(row, col - 1) * ((Real)1 - ratio) * diff;
            acceleration += mInvMasses[i] * force;
        }

        if (col < mNumColsM1)
        {
            next = i + 1;  // index to next col-neighbor
            diff = positions[next] - positions[i];
            ratio = LengthC(row, col) / TVector::ToolsType::VectorMagnitude(diff);
            force = ConstantC(row, col) * ((Real)1 - ratio) * diff;
            acceleration += mInvMasses[i] * force;
        }

        return acceleration;
    }

    template <typename Real, typename TVector>
    TVector MassSpringSurface<Real, TVector>::ExternalAcceleration(int, Real, const TVector*, const TVector*)
    {
        return TVector::sm_Zero;
    }

    template <typename Real, typename TVector>
    int MassSpringSurface<Real, TVector>::GetIndex(int row, int col) const
    {
        return col + mNumCols * row;
    }

    template <typename Real, typename TVector>
    void MassSpringSurface<Real, TVector>::GetCoordinates(int i, int& row, int& col) const
    {
        col = i % mNumCols;
        row = i / mNumCols;
    }
}

#endif  // PHYSICS_PARTICLE_SYSTEM_MASS_SPRING_SURFACE_DETAIL_H