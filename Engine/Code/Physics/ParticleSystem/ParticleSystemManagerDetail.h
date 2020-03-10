// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 18:11)

#ifndef PHYSICS_PARTICLE_SYSTEM_PARTICLE_SYSTEM_MANAGER_DETAIL_H
#define PHYSICS_PARTICLE_SYSTEM_PARTICLE_SYSTEM_MANAGER_DETAIL_H

#include "ParticleSystemManager.h" 

namespace Physics
{
	template <typename Real, typename TVector>
	ParticleSystemManager<Real, TVector>::ParticleSystemManager(int numParticles, Real step)
	{
		mNumParticles = numParticles;
		SetStep(step);

		mMasses = NEW1<Real>(mNumParticles);
		mInvMasses = NEW1<Real>(mNumParticles);
		mPositions = NEW1<TVector>(mNumParticles);
		mVelocities = NEW1<TVector>(mNumParticles);

		memset(mMasses, 0, mNumParticles * sizeof(Real));
		memset(mInvMasses, 0, mNumParticles * sizeof(Real));
		memset(mPositions, 0, mNumParticles * sizeof(TVector));
		memset(mVelocities, 0, mNumParticles * sizeof(TVector));

		mPTmp = NEW1<TVector>(mNumParticles);
		mDPTmp1 = NEW1<TVector>(mNumParticles);
		mDPTmp2 = NEW1<TVector>(mNumParticles);
		mDPTmp3 = NEW1<TVector>(mNumParticles);
		mDPTmp4 = NEW1<TVector>(mNumParticles);
		mVTmp = NEW1<TVector>(mNumParticles);
		mDVTmp1 = NEW1<TVector>(mNumParticles);
		mDVTmp2 = NEW1<TVector>(mNumParticles);
		mDVTmp3 = NEW1<TVector>(mNumParticles);
		mDVTmp4 = NEW1<TVector>(mNumParticles);
	}

	template <typename Real, typename TVector>
	ParticleSystemManager<Real, TVector>::~ParticleSystemManager()
	{
		DELETE1(mMasses);
		DELETE1(mInvMasses);
		DELETE1(mPositions);
		DELETE1(mVelocities);
		DELETE1(mPTmp);
		DELETE1(mDPTmp1);
		DELETE1(mDPTmp2);
		DELETE1(mDPTmp3);
		DELETE1(mDPTmp4);
		DELETE1(mVTmp);
		DELETE1(mDVTmp1);
		DELETE1(mDVTmp2);
		DELETE1(mDVTmp3);
		DELETE1(mDVTmp4);
	}

	template <typename Real, typename TVector>
	int ParticleSystemManager<Real, TVector>::GetNumParticles() const
	{
		return mNumParticles;
	}

	template <typename Real, typename TVector>
	void ParticleSystemManager<Real, TVector>::SetMass(int i, Real mass)
	{
		if ((Real)0 < mass && mass < Mathematics::Math<Real>::sm_MaxReal)
		{
			mMasses[i] = mass;
			mInvMasses[i] = ((Real)1) / mass;
		}
		else
		{
			mMasses[i] = Mathematics::Math<Real>::sm_MaxReal;
			mInvMasses[i] = (Real)0;
		}
	}

	template <typename Real, typename TVector>
	Real ParticleSystemManager<Real, TVector>::GetMass(int i) const
	{
		return mMasses[i];
	}

	template <typename Real, typename TVector>
	TVector* ParticleSystemManager<Real, TVector>::Positions() const
	{
		return mPositions;
	}

	template <typename Real, typename TVector>
	TVector& ParticleSystemManager<Real, TVector>::Position(int i)
	{
		return mPositions[i];
	}

	template <typename Real, typename TVector>
	TVector* ParticleSystemManager<Real, TVector>::Velocities() const
	{
		return mVelocities;
	}

	template <typename Real, typename TVector>
	TVector& ParticleSystemManager<Real, TVector>::Velocity(int i)
	{
		return mVelocities[i];
	}

	template <typename Real, typename TVector>
	void ParticleSystemManager<Real, TVector>::SetStep(Real step)
	{
		mStep = step;
		mHalfStep = ((Real)0.5)*mStep;
		mSixthStep = mStep / (Real)6;
	}

	template <typename Real, typename TVector>
	Real ParticleSystemManager<Real, TVector>::GetStep() const
	{
		return mStep;
	}

	template <typename Real, typename TVector>
	void ParticleSystemManager<Real, TVector>::Update(Real time)
	{
		// Runge-Kutta fourth-order solver.
		Real halfTime = time + mHalfStep;
		Real fullTime = time + mStep;

		// Compute the first step.
		int i;
		for (i = 0; i < mNumParticles; ++i)
		{
			if (mInvMasses[i] > (Real)0)
			{
				mDPTmp1[i] = mVelocities[i];
				mDVTmp1[i] = Acceleration(i, time, mPositions, mVelocities);
			}
		}
		for (i = 0; i < mNumParticles; ++i)
		{
			if (mInvMasses[i] > (Real)0)
			{
				mPTmp[i] = mPositions[i] + mHalfStep * mDPTmp1[i];
				mVTmp[i] = mVelocities[i] + mHalfStep * mDVTmp1[i];
			}
			else
			{
				mPTmp[i] = mPositions[i];
				mVTmp[i] = TVector::sm_Zero;
			}
		}

		// Compute the second step.
		for (i = 0; i < mNumParticles; ++i)
		{
			if (mInvMasses[i] > (Real)0)
			{
				mDPTmp2[i] = mVTmp[i];
				mDVTmp2[i] = Acceleration(i, halfTime, mPTmp, mVTmp);
			}
		}
		for (i = 0; i < mNumParticles; ++i)
		{
			if (mInvMasses[i] > (Real)0)
			{
				mPTmp[i] = mPositions[i] + mHalfStep * mDPTmp2[i];
				mVTmp[i] = mVelocities[i] + mHalfStep * mDVTmp2[i];
			}
			else
			{
				mPTmp[i] = mPositions[i];
				mVTmp[i] = TVector::sm_Zero;
			}
		}

		// Compute the third step.
		for (i = 0; i < mNumParticles; ++i)
		{
			if (mInvMasses[i] > (Real)0)
			{
				mDPTmp3[i] = mVTmp[i];
				mDVTmp3[i] = Acceleration(i, halfTime, mPTmp, mVTmp);
			}
		}
		for (i = 0; i < mNumParticles; ++i)
		{
			if (mInvMasses[i] > (Real)0)
			{
				mPTmp[i] = mPositions[i] + mStep * mDPTmp3[i];
				mVTmp[i] = mVelocities[i] + mStep * mDVTmp3[i];
			}
			else
			{
				mPTmp[i] = mPositions[i];
				mVTmp[i] = TVector::sm_Zero;
			}
		}

		// Compute the fourth step.
		for (i = 0; i < mNumParticles; ++i)
		{
			if (mInvMasses[i] > (Real)0)
			{
				mDPTmp4[i] = mVTmp[i];
				mDVTmp4[i] = Acceleration(i, fullTime, mPTmp, mVTmp);
			}
		}
		for (i = 0; i < mNumParticles; ++i)
		{
			if (mInvMasses[i] > (Real)0)
			{
				mPositions[i] += mSixthStep * (mDPTmp1[i] +	((Real)2)*(mDPTmp2[i] + mDPTmp3[i]) + mDPTmp4[i]);
				mVelocities[i] += mSixthStep * (mDVTmp1[i] +((Real)2)*(mDVTmp2[i] + mDVTmp3[i]) + mDVTmp4[i]);
			}
		}
	}
}

#endif // PHYSICS_PARTICLE_SYSTEM_PARTICLE_SYSTEM_MANAGER_DETAIL_H