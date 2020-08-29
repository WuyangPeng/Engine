// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 10:22)

#ifndef MATHEMATICS_INTERPOLATION_INTP_SPHERE2_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_SPHERE2_DETAIL_H

#include "IntpSphere2.h"

namespace Mathematics
{
	template <typename Real>
	IntpSphere2<Real>::IntpSphere2(int quantity, Real* theta, Real* phi,Real* F, bool owner, QueryType queryType)
	{
		// Copy the input data.  The larger arrays are used to support wrap-around
		// in the Delaunay triangulation for the interpolator.  The Vector2D<Real>
		// object V corresponds to (V.X(),V.Y()) = (theta,phi).
		int threeQuantity = 3 * quantity;
		std::vector< Vector2D<Real> > wrapAngles(threeQuantity);
		Real* wrapF = NEW1<Real>(threeQuantity);
		for (int i = 0; i < quantity; ++i)
		{
			wrapAngles[i][0] = theta[i];
			wrapAngles[i][1] = phi[i];
			wrapF[i] = F[i];
		}

		if (owner)
		{
			DELETE1(theta);
			DELETE1(phi);
			DELETE1(F);
		}

		// Use periodicity to get wrap-around in the Delaunay triangulation.
		int i0 = 0, i1 = quantity, i2 = 2 * quantity;
		for (/**/; i0 < quantity; ++i0, ++i1, ++i2)
		{
			wrapAngles[i1][0] = wrapAngles[i0][0] + Math<Real>::GetTwoPI();
			wrapAngles[i2][0] = wrapAngles[i0][0] - Math<Real>::GetTwoPI();
			wrapAngles[i1][1] = wrapAngles[i0][1];
			wrapAngles[i2][1] = wrapAngles[i0][1];
			wrapF[i1] = wrapF[i0];
			wrapF[i2] = wrapF[i0];
		}

		mDT = NEW0 Delaunay2<Real>(wrapAngles, Real{ 0.001 }, true,queryType);
		mInterp = NEW0 IntpQdrNonuniform2<Real>(*mDT, wrapF, true);
	}

	template <typename Real>
	IntpSphere2<Real>::~IntpSphere2()
	{
		DELETE0(mDT);
		DELETE0(mInterp);
	}

	template <typename Real>
	void IntpSphere2<Real>::GetSphericalCoords(Real x, Real y, Real z,Real& theta, Real& phi)
	{
		// Assumes (x,y,z) is unit length.  Returns -PI <= theta <= PI and
		// 0 <= phiAngle <= PI.

		if (z < static_cast<Real>(1))
		{
			if (z > -static_cast<Real>(1))
			{
				theta = Math<Real>::ATan2(y, x);
				phi = Math<Real>::ACos(z);
			}
			else
			{
				theta = -Math<Real>::GetPI();
				phi = Math<Real>::GetPI();
			}
		}
		else
		{
			theta = -Math<Real>::GetPI();
			phi = Math<Real>::GetValue(0);
		}
	}

	template <typename Real>
	bool IntpSphere2<Real>::Evaluate(Real theta, Real phi, Real& F)
	{
		Vector2D<Real> angles(theta, phi);
		Real thetaDeriv, phiDeriv;
		return mInterp->Evaluate(angles, F, thetaDeriv, phiDeriv);
	}
}

#endif // MATHEMATICS_INTERPOLATION_INTP_SPHERE2_DETAIL_H