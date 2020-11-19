// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 13:25)

#ifndef MATHEMATICS_MISCELLANEOUS_PERS_PPROJ_ELLIPSOID_DETAIL_H
#define MATHEMATICS_MISCELLANEOUS_PERS_PPROJ_ELLIPSOID_DETAIL_H

#include "PerspProjEllipsoid.h"

namespace Mathematics
{

	template <typename Real>
	void PerspectiveProjectEllipsoid(const Ellipsoid3<Real>& ellipsoid,const Vector3D<Real>& eye, const Plane3<Real>& plane,
									 const Vector3D<Real>& U, const Vector3D<Real>& V, Vector3D<Real>& P,Ellipse2<Real>& ellipse)
	{
		// Get coefficients for ellipsoid as X^T*A*X + B^T*X + C = 0.

		Ellipsoid3Coefficients<Real> ellipsoid3Coefficients = ellipsoid.ToCoefficients();
		Matrix3<Real> A = ellipsoid3Coefficients.GetMatrix();
		Vector3D<Real> B = ellipsoid3Coefficients.GetVector();
		Real C = ellipsoid3Coefficients.GetConstants();

		// Compute matrix M (see PerspectiveProjectionEllipsoid.pdf).
		Vector3D<Real> AE = A * eye;
		Real EAE = Vector3DTools<Real>::DotProduct(eye, AE);
		Real BE = Vector3DTools<Real>::DotProduct(B, eye);
		Real QuadE = ((Real)4)*(EAE + BE + C);
		Vector3D<Real> Bp2AE = B + (Math::GetValue(2))*AE;
		Matrix3<Real> mat = Matrix3<Real>(Bp2AE, Bp2AE) - QuadE * A;

		// Compute coefficients for projected ellipse.
		Vector3D<Real> MU = mat * U;
		Vector3D<Real> MV = mat * V;
		Vector3D<Real> MN = mat * plane.GetNormal();
		Real DmNdE = -plane.DistanceTo(eye);
		P = eye + DmNdE * plane.GetNormal();

		Matrix2<Real> AOut;
		Vector2D<Real> BOut;
		Real COut;
		AOut[0][0] = Vector3DTools<Real>::DotProduct(U, MU);
		AOut[0][1] = Vector3DTools<Real>::DotProduct(U, MV);
		AOut[1][1] = Vector3DTools<Real>::DotProduct(V, MV);
		AOut[1][0] = AOut[0][1];
		BOut[0] = (Math::GetValue(2))*DmNdE*(Vector3DTools<Real>::DotProduct(U, MN));
		BOut[1] = (Math::GetValue(2))*DmNdE*(Vector3DTools<Real>::DotProduct(V, MN));
		COut = DmNdE * DmNdE*(Vector3DTools<Real>::DotProduct(plane.GetNormal(), MN));

		Ellipse2Coefficients<Real>  ellipsoid3Coefficients1(AOut, BOut, COut);
		ellipse.FromCoefficients(ellipsoid3Coefficients1);
	} 
}


#endif // MATHEMATICS_MISCELLANEOUS_PERS_PPROJ_ELLIPSOID_DETAIL_H