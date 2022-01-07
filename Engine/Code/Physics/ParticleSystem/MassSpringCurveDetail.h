// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 18:09)

#ifndef PHYSICS_PARTICLE_SYSTEM_MASS_SPRING_CURVE_DETAIL_H
#define PHYSICS_PARTICLE_SYSTEM_MASS_SPRING_CURVE_DETAIL_H

#include "MassSpringCurve.h"

namespace Physics
{
    template <typename Real, typename TVector>
    MassSpringCurve<Real, TVector>::MassSpringCurve(int numParticles, Real step)
        : ParticleSystemManager<Real, TVector>(numParticles, step)
    {
        mNumSprings = mNumParticles - 1;
        mConstants = nullptr;  //NEW1<Real>(mNumSprings);
        mLengths = nullptr;  //NEW1<Real>(mNumSprings);
        memset(mConstants, 0, mNumSprings * sizeof(Real));
        memset(mLengths, 0, mNumSprings * sizeof(Real));
    }

    template <typename Real, typename TVector>
    MassSpringCurve<Real, TVector>::~MassSpringCurve()
    {
        DELETE1(mConstants);
        DELETE1(mLengths);
    }

    template <typename Real, typename TVector>
    int MassSpringCurve<Real, TVector>::GetNumSprings() const
    {
        return mNumSprings;
    }

    template <typename Real, typename TVector>
    Real& MassSpringCurve<Real, TVector>::Constant(int i)
    {
        return mConstants[i];
    }

    template <typename Real, typename TVector>
    Real& MassSpringCurve<Real, TVector>::Length(int i)
    {
        return mLengths[i];
    }

    template <typename Real, typename TVector>
    TVector MassSpringCurve<Real, TVector>::Acceleration(int i, Real time, const TVector* positions, const TVector* velocities)
    {
        // Compute spring forces on position X[i].  The positions are not
        // necessarily m_akPosition since the RK4 solver in ParticleSystem
        // evaluates the acceleration function at intermediate positions.  The end
        // points of the curve of masses must be handled separately since each
        // has only one spring attached to it.

        TVector acceleration = ExternalAcceleration(i, time, positions, velocities);

        TVector diff, force;
        Real ratio;

        if (i > 0)
        {
            int iM1 = i - 1;
            diff = positions[iM1] - positions[i];
            ratio = mLengths[iM1] / TVector::ToolsType::VectorMagnitude(diff);
            force = mConstants[iM1] * ((Real)1 - ratio) * diff;
            acceleration += mInvMasses[i] * force;
        }

        int iP1 = i + 1;
        if (iP1 < mNumParticles)
        {
            diff = positions[iP1] - positions[i];
            ratio = mLengths[i] / TVector::ToolsType::VectorMagnitude(diff);
            force = mConstants[i] * ((Real)1 - ratio) * diff;
            acceleration += mInvMasses[i] * force;
        }

        return acceleration;
    }

    template <typename Real, typename TVector>
    TVector MassSpringCurve<Real, TVector>::ExternalAcceleration(int, Real,
                                                                 const TVector*, const TVector*)
    {
        return TVector::sm_Zero;
    }
}

#endif  // PHYSICS_PARTICLE_SYSTEM_MASS_SPRING_CURVE_DETAIL_H