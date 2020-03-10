// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 16:21)

#ifndef PHYSICS_FLUID_FLUID3DB_H
#define PHYSICS_FLUID_FLUID3DB_H

#include "Physics/PhysicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

// This class is an implementation based on the ideas in "Real-Time Fluid
// Dynamics for Games", by Jos Stam (GDC 2003 Proceedings), but the code
// is faster in that it processes the source, diffusion, and advection
// terms all at the same time.  The only Gauss-Seidel iteration is in the
// Poisson solver.

namespace Physics
{
	template <typename Real>
	class PHYSICS_TEMPLATE_DEFAULT_DECLARE Fluid3Db
	{
	public:
		using Vector3D = Mathematics::Vector3D<Real>;

	public:
		// Construction and destruction.
		Fluid3Db(Real x0, Real y0, Real z0, Real x1, Real y1, Real z1, Real dt,
				 Real denViscosity, Real velViscosity, int imax, int jmax, int kmax,
				 int numGaussSeidelIterations, bool densityDirichlet);

		virtual ~Fluid3Db();

		// Member access.
		Real GetX0() const;
		Real GetY0() const;
		Real GetZ0() const;
		Real GetX1() const;
		Real GetY1() const;
		Real GetZ1() const;
		Real GetDt() const;
		Real GetDx() const;
		Real GetDy() const;
		Real GetDz() const;
		Real GetTime() const;
		int GetIMax() const;
		int GetJMax() const;
		int GetKMax() const;
		const Real* GetX() const;
		const Real* GetY() const;
		const Real* GetZ() const;
		Real*** GetDensity() const;
		Vector3D*** GetVelocity() const;

		// Derived classes must provide initialization at time 0.
		virtual Real InitialDensity(Real x, Real y, Real z, int i, int j, int k) = 0;

		virtual Vector3D InitialVelocity(Real x, Real y, Real z, int i, int j, int k) = 0;

		// Derived classes must provide source terms.  The density has a
		// source-sink function.  The velocity has a force (impulse) function.
		virtual Real SourceDensity(Real t, Real x, Real y, Real z, int i, int j, int k) = 0;

		virtual Vector3D SourceVelocity(Real t, Real x, Real y, Real z, int i, int j, int k) = 0;

		void Initialize();
		void DoSimulationStep();

	protected:
		// Update the boundary values after the interior values have been
		// assigned.
		void DirichletBoundaryZero(Real*** data);
		void NeumannBoundaryZero(Real*** data);
		void UpdateDensityBoundary();
		void UpdateVelocityBoundary();

		// Swap the buffer pointers.
		void SwapDensityBuffers();
		void SwapVelocityBuffers();

		// Constructor inputs.
		Real mX0, mY0, mZ0, mX1, mY1, mZ1;
		Real mDt;
		Real mDenViscosity, mVelViscosity;
		int mIMax, mJMax, mKMax, mNumGaussSeidelIterations;
		bool mDensityDirichlet;

		// Derived quantities;
		int mIMaxM1, mJMaxM1, mKMaxM1, mIMaxP1, mJMaxP1, mKMaxP1, mNumVoxels;
		Real mDx, mDy, mDz;
		Real mDxDx, mDyDy, mDzDz;
		Real mHalfDivDx, mHalfDivDy, mHalfDivDz;
		Real mDtDivDx, mDtDivDy, mDtDivDz, mDtDivDxDx, mDtDivDyDy, mDtDivDzDz;
		Real mEpsilon0, mEpsilonX, mEpsilonY, mEpsilonZ;
		Real mDenLambdaX, mDenLambdaY, mDenLambdaZ;
		Real mVelLambdaX, mVelLambdaY, mVelLambdaZ;
		Real mDenGamma0, mDenGammaX, mDenGammaY, mDenGammaZ;
		Real mVelGamma0, mVelGammaX, mVelGammaY, mVelGammaZ;

		// Current simulation time.
		Real mTime;

		// Lattice cell centers.
		Real* mX;
		Real* mY;
		Real* mZ;

		// State arrays.
		Real*** mDensity0;
		Real*** mDensity1;
		Vector3D*** mVelocity0;
		Vector3D*** mVelocity1;
		Real*** mDivergence;
		Real*** mPoisson;
	}; 
}

#endif // PHYSICS_FLUID_FLUID3DB_H
