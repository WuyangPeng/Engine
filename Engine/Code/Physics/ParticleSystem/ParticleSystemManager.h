// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 18:13)

#ifndef PHYSICS_PARTICLE_SYSTEM_PARTICLE_SYSTEM_MANAGER_H
#define PHYSICS_PARTICLE_SYSTEM_PARTICLE_SYSTEM_MANAGER_H

#include "Physics/PhysicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Vector3D.h" 

namespace Physics
{
	template <typename Real, typename TVector>
	class   ParticleSystemManager
	{
	public:
		// Construction and destruction.  If a particle is to be immovable, set
		// its mass to Math<Real>::sm_MaxReal.
		ParticleSystemManager (int numParticles, Real step);
		virtual ~ParticleSystemManager ();

		int GetNumParticles () const;
		void SetMass (int i, Real mass);
		Real GetMass (int i) const;
		TVector* Positions () const;
		TVector& Position (int i);
		TVector* Velocities () const;
		TVector& Velocity (int i);
		void SetStep (Real step);
		Real GetStep () const;

		// Callback for acceleration (ODE solver uses x" = F/m) applied to
		// particle i.  The positions and velocities are not necessarily
		// mPositions and mVelocities since the ODE solver evaluates the
		// impulse function at intermediate positions.
		virtual TVector Acceleration (int i, Real time, const TVector* positions, const TVector* velocities) = 0;

		// Update the particle positions based on current time and particle state.
		// The Acceleration(...) function is called in this update for each
		// particle.  This function is virtual so that derived classes can
		// perform pre-update and/or post-update semantics.
		virtual void Update (Real time);

	protected:
		int mNumParticles;
		Real* mMasses;
		Real* mInvMasses;
		TVector* mPositions;
		TVector* mVelocities;
		Real mStep, mHalfStep, mSixthStep;

		// Temporary storage for solver.
		typedef TVector* TVectorPtr;
		TVectorPtr mPTmp, mDPTmp1, mDPTmp2, mDPTmp3, mDPTmp4;
		TVectorPtr mVTmp, mDVTmp1, mDVTmp2, mDVTmp3, mDVTmp4;
	};

	using ParticleSystem2f = ParticleSystemManager<float,Mathematics::FloatVector2D>;
	using ParticleSystem2d = ParticleSystemManager<double,Mathematics::DoubleVector2D>;
	using ParticleSystem3f = ParticleSystemManager<float,Mathematics::FloatVector3D>;
	using ParticleSystem3d = ParticleSystemManager<double,Mathematics::DoubleVector3D>;
}

#endif // PHYSICS_PARTICLE_SYSTEM_PARTICLE_SYSTEM_MANAGER_H
