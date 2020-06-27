// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 13:25)

#ifndef MATHEMATICS_MISCELLANEOUS_QUAD_TO_QUAD_TRANSFORMS_DETAIL_H
#define MATHEMATICS_MISCELLANEOUS_QUAD_TO_QUAD_TRANSFORMS_DETAIL_H

#include "QuadToQuadTransforms.h"

namespace Mathematics
{
	template <typename Real>
	HmQuadToSqr<Real>::HmQuadToSqr(const Vector2D<Real>& P00,const Vector2D<Real>& P10, const Vector2D<Real>& P11,const Vector2D<Real>& P01)
	{
		// Translate to origin.
		mT = P00;
		Vector2D<Real> Q10 = P10 - P00;
		Vector2D<Real> Q11 = P11 - P00;
		Vector2D<Real> Q01 = P01 - P00;

		Matrix2<Real> invM(Q10.GetXCoordinate(), Q01.GetXCoordinate(), Q10.GetYCoordinate(), Q01.GetYCoordinate());
		mM = invM.Inverse();

		// Compute where p11 is mapped to.
		Vector2D<Real> corner = mM * Q11;  // = (a,b)

		// Compute homogeneous transform of quadrilateral
		// {(0,0),(1,0),(a,b),(0,1)} to square {(0,0),(1,0),(1,1),(0,1)}.
		mG[0] = (corner.GetYCoordinate() - static_cast<Real>(1)) / corner.GetXCoordinate();
		mG[1] = (corner.GetXCoordinate() - static_cast<Real>(1)) / corner.GetYCoordinate();
		mD[0] = static_cast<Real>(1) + mG.GetXCoordinate();
		mD[1] = static_cast<Real>(1) + mG.GetYCoordinate();
	}

	template <typename Real>
	Vector2D<Real> HmQuadToSqr<Real>::Transform(const Vector2D<Real>& P)
	{
		Vector2D<Real> prod = mM * (P - mT);
		Real invDenom = (static_cast<Real>(1)) / (static_cast<Real>(1) + Vector2DTools<Real>::DotProduct(mG, prod));
		Vector2D<Real> result = invDenom * prod;
		result[0] *= mD[0];
		result[1] *= mD[1];
		return result;
	}

	template <typename Real>
	HmSqrToQuad<Real>::HmSqrToQuad(const Vector2D<Real>& P00,const Vector2D<Real>& P10, const Vector2D<Real>& P11,const Vector2D<Real>& P01)
	{
		// Translate to origin.
		mT = P00;
		mM[0][0] = P10.GetXCoordinate() - P00.GetXCoordinate();
		mM[0][1] = P01.GetXCoordinate() - P00.GetXCoordinate();
		mM[1][0] = P10.GetYCoordinate() - P00.GetYCoordinate();
		mM[1][1] = P01.GetYCoordinate() - P00.GetYCoordinate();

		Matrix2<Real> invM = mM.Inverse();

		// Find point which is mapped to p11.
		Vector2D<Real> corner = invM * (P11 - P00);  // = (a,b)

		// Compute homogeneous transform of square {(0,0),(1,0),(1,1),(0,1)} to
		// quadrilateral {(0,0),(1,0),(a,b),(0,1)}.
		Real invDenom = (static_cast<Real>(1)) / (corner.GetXCoordinate() + corner.GetYCoordinate() - static_cast<Real>(1));
		mG[0] = invDenom * (static_cast<Real>(1) - corner.GetYCoordinate());
		mG[1] = invDenom * (static_cast<Real>(1) - corner.GetXCoordinate());
		mD[0] = invDenom * corner.GetXCoordinate();
		mD[1] = invDenom * corner.GetYCoordinate();
	}

	template <typename Real>
	Vector2D<Real> HmSqrToQuad<Real>::Transform(const Vector2D<Real>& P)
	{
		Real invDenom = (static_cast<Real>(1)) / (static_cast<Real>(1) + Vector2DTools<Real>::DotProduct(mG, P));
		Vector2D<Real> result(mD.GetXCoordinate()*P.GetXCoordinate(), mD.GetYCoordinate()*P.GetYCoordinate());
		Vector2D<Real> prod = mM * result;
		result[0] = invDenom * prod.GetXCoordinate() + mT.GetXCoordinate();
		result[1] = invDenom * prod.GetYCoordinate() + mT.GetYCoordinate();
		return result;
	}

	template <typename Real>
	BiQuadToSqr<Real>::BiQuadToSqr(const Vector2D<Real>& P00,const Vector2D<Real>& P10, const Vector2D<Real>& P11,const Vector2D<Real>& P01)
		:mP00(P00)
	{
		mB = P10 - P00;
		mC = P01 - P00;
		mD = P11 + P00 - P10 - P01;
		mBC = Vector2DTools<Real>::DotPerp(mB, mC);
		mBD = Vector2DTools<Real>::DotPerp(mB, mD);
		mCD = Vector2DTools<Real>::DotPerp(mC, mD);
	}

	template <typename Real>
	Vector2D<Real> BiQuadToSqr<Real>::Transform(const Vector2D<Real>& P)
	{
		Vector2D<Real> A = mP00 - P;
		Real AB = Vector2DTools<Real>::DotPerp(A, mB);
		Real AC = Vector2DTools<Real>::DotPerp(A, mC);

		// 0 = ac*bc+(bc^2+ac*bd-ab*cd)*s+bc*bd*s^2 = k0 + k1*s + k2*s^2
		Real k0 = AC * mBC;
		Real k1 = mBC * mBC + AC * mBD - AB * mCD;
		Real k2 = mBC * mBD;

		if (Math<Real>::FAbs(k2) >= Math<Real>::sm_ZeroTolerance)
		{
			// The s-equation is quadratic.
			Real inv = (static_cast<Real>(0.5)) / k2;
			Real discr = k1 * k1 - ((Real)4)*k0*k2;
			Real root = Math<Real>::Sqrt(Math<Real>::FAbs(discr));

			Vector2D<Real> result0;
			result0[0] = (-k1 - root)*inv;
			result0[1] = AB / (mBC + mBD * result0[0]);
			Real deviation0 = Deviation(result0);
			if (deviation0 == Math<Real>::sm_Zero)
			{
				return result0;
			}

			Vector2D<Real> result1;
			result1[0] = (-k1 + root)*inv;
			result1[1] = AB / (mBC + mBD * result1.GetXCoordinate());
			Real deviation1 = Deviation(result1);
			if (deviation1 == Math<Real>::sm_Zero)
			{
				return result1;
			}

			if (deviation0 <= deviation1)
			{
				if (deviation0 <= Math<Real>::sm_ZeroTolerance)
				{
					return result0;
				}
			}
			else
			{
				if (deviation1 <= Math<Real>::sm_ZeroTolerance)
				{
					return result1;
				}
			}
		}
		else
		{
			// The s-equation is linear.
			Vector2D<Real> result;

			result[0] = -k0 / k1;
			result[1] = AB / (mBC + mBD * result.GetXCoordinate());
			Real deviation = Deviation(result);
			if (deviation <= Math<Real>::sm_ZeroTolerance)
			{
				return result;
			}
		}

		// Point is outside the quadrilateral, return invalid.
		return Vector2D<Real>(Math<Real>::sm_MaxReal, Math<Real>::sm_MaxReal);
	}

	template <typename Real>
	Real BiQuadToSqr<Real>::Deviation(const Vector2D<Real>& SPoint)
	{
		// Deviation is the squared distance of the point from the unit square.
		Real deviation = Math<Real>::sm_Zero;
		Real delta;

		if (SPoint.GetXCoordinate() < Math<Real>::sm_Zero)
		{
			deviation += SPoint.GetXCoordinate()*SPoint.GetXCoordinate();
		}
		else if (SPoint.GetXCoordinate() > static_cast<Real>(1))
		{
			delta = SPoint.GetXCoordinate() - static_cast<Real>(1);
			deviation += delta * delta;
		}

		if (SPoint.GetYCoordinate() < Math<Real>::sm_Zero)
		{
			deviation += SPoint.GetYCoordinate()*SPoint.GetYCoordinate();
		}
		else if (SPoint.GetYCoordinate() > static_cast<Real>(1))
		{
			delta = SPoint.GetYCoordinate() - static_cast<Real>(1);
			deviation += delta * delta;
		}

		return deviation;
	}

	template <typename Real>
	BiSqrToQuad<Real>::BiSqrToQuad(const Vector2D<Real>& P00,const Vector2D<Real>& P10, const Vector2D<Real>& P11,const Vector2D<Real>& P01)
	{
		mS00 = P00;
		mS10 = P10;
		mS11 = P11;
		mS01 = P01;
	}

	template <typename Real>
	Vector2D<Real> BiSqrToQuad<Real>::Transform(const Vector2D<Real>& P)
	{
		Vector2D<Real> oneMinusP(static_cast<Real>(1) - P.GetXCoordinate(), static_cast<Real>(1) - P.GetYCoordinate());
		Vector2D<Real> result;
		result[0] = oneMinusP.GetYCoordinate()*(oneMinusP.GetXCoordinate()*mS00.GetXCoordinate() + P.GetXCoordinate()*mS10.GetXCoordinate()) +
					P.GetYCoordinate()*(oneMinusP.GetXCoordinate()*mS01.GetXCoordinate() + P.GetXCoordinate()*mS11.GetXCoordinate());
		result[1] = oneMinusP.GetYCoordinate()*(oneMinusP.GetXCoordinate()*mS00.GetYCoordinate() + P.GetXCoordinate()*mS10.GetYCoordinate()) +
					P.GetYCoordinate()*(oneMinusP.GetXCoordinate()*mS01.GetYCoordinate() + P.GetXCoordinate()*mS11.GetYCoordinate());
		return result;
	}




}


#endif // MATHEMATICS_MISCELLANEOUS_QUAD_TO_QUAD_TRANSFORMS_DETAIL_H