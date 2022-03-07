// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 18:12)

#ifndef PHYSICS_PARTICLE_SYSTEM_MASS_SPRING_SURFACE_H
#define PHYSICS_PARTICLE_SYSTEM_MASS_SPRING_SURFACE_H

#include "Physics/PhysicsDll.h"

#include "ParticleSystemManager.h"

namespace Physics
{
	template <typename Real, typename TVector>
	class   MassSpringSurface : public ParticleSystemManager<Real,TVector>
	{
	public:
		// Construction and destruction.  This class represents an RxC array of
		// masses lying on a surface and connected by an array of springs.  The
		// masses are indexed by mass[r][c] for 0 <= r < R and 0 <= c < C.  The
		// mass at interior position X[r][c] is connected by springs to the
		// masses at positions X[r-1][c], X[r+1][c], X[r][c-1], and X[r][c+1].
		// Boundary masses have springs connecting them to the obvious neighbors
		// ("edge" mass has 3 neighbors, "corner" mass has 2 neighbors).  The
		// masses are arranged in row-major order:  position[c+C*r] = X[r][c]
		// for 0 <= r < R and 0 <= c < C.  The other arrays are stored similarly.
		MassSpringSurface (int numRows, int numCols, Real step);
		virtual ~MassSpringSurface ();

		int GetNumRows () const;
		int GetNumCols () const;
		void SetMass (int row, int col, Real mass);
		Real GetMass (int row, int col) const;
		TVector** Positions2D () const;
		TVector& Position (int row, int col);
		TVector** Velocities2D () const;
		TVector& Velocity (int row, int col);

		// The interior mass at (r,c) has springs to the left, right, bottom, and
		// top.  Edge masses have only three neighbors and corner masses have only
		// two neighbors.  The mass at (r,c) provides access to the springs
		// connecting to locations (r,c+1) and (r+1,c).  Edge and corner masses
		// provide access to only a subset of these.  The caller is responsible
		// for ensuring the validity of the (r,c) inputs.
		Real& ConstantR (int row, int col);  // spring to (r+1,c)
		Real& LengthR (int row, int col);    // spring to (r+1,c)
		Real& ConstantC (int row, int col);  // spring to (r,c+1)
		Real& LengthC (int row, int col);    // spring to (r,c+1)

		// Callback for acceleration (ODE solver uses x" = F/m) applied to
		// particle i.  The positions and velocities are not necessarily
		// mPositions and mVelocities since the ODE solver evaluates the
		// impulse function at intermediate positions.
		virtual TVector Acceleration (int i, Real time, const TVector* positions, const TVector* velocities);

		// The default external force is zero.  Derive a class from this one to
		// provide nonzero external forces such as gravity, wind, friction,
		// and so on.  This function is called by Acceleration(...) to append the
		// acceleration F/m generated by the external force F.
		virtual TVector ExternalAcceleration (int i, Real time, const TVector* positions, const TVector* velocities);

	protected:
		using ParticleSystemManager<Real,TVector>::mInvMasses;
		using ParticleSystemManager<Real,TVector>::mPositions;
		using ParticleSystemManager<Real,TVector>::mVelocities;

		int GetIndex (int row, int col) const;
		void GetCoordinates (int i, int& row, int& col) const;

		int mNumRows;             // R
		int mNumCols;             // C
		TVector** mPositionGrid;  // R-by-C
		TVector** mVelocityGrid;  // R-by-C

		int mNumRowsM1;           // R-1
		int mNumColsM1;           // C-1
		Real** mConstantsR;       // (R-1)-by-C
		Real** mLengthsR;         // (R-1)-by-C
		Real** mConstantsC;       // R-by-(C-1)
		Real** mLengthsC;         // R-by-(C-1)
	};

	using MassSpringSurface2f = MassSpringSurface<float,Mathematics::Vector2F>;
	using MassSpringSurface2d = MassSpringSurface<double,Mathematics::Vector2D>;
	using MassSpringSurface3f = MassSpringSurface<float,Mathematics::Vector3F>;
	using MassSpringSurface3d = MassSpringSurface<double,Mathematics::Vector3D>;
}

#endif // PHYSICS_PARTICLE_SYSTEM_MASS_SPRING_SURFACE_H
