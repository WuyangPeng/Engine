// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:54)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_IMPLICIT_SURFACE_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_IMPLICIT_SURFACE_DETAIL_H

#include "ImplicitSurface.h"

namespace Mathematics
{

template <typename Real>
ImplicitSurface<Real>::ImplicitSurface ()
{
}

template <typename Real>
ImplicitSurface<Real>::~ImplicitSurface ()
{
}

template <typename Real>
bool ImplicitSurface<Real>::IsOnSurface (const Vector3D<Real>& pos, Real epsilon) const
{
    return Math<Real>::FAbs(F(pos)) <= epsilon;
}

template <typename Real>
Vector3D<Real> ImplicitSurface<Real>::GetGradient (const Vector3D<Real>& pos)  const
{
    Real fx = FX(pos);
    Real fy = FY(pos);
    Real fz = FZ(pos);
    return Vector3D<Real>(fx, fy, fz);
}

template <typename Real>
Matrix3<Real> ImplicitSurface<Real>::GetHessian (const Vector3D<Real>& pos)  const
{
	auto fxx = FXX(pos);
	auto fxy = FXY(pos);
	auto fxz = FXZ(pos);
	auto fyy = FYY(pos);
	auto fyz = FYZ(pos);
	auto fzz = FZZ(pos);
    return Matrix3<Real>(fxx, fxy, fxz, fxy, fyy, fyz, fxz, fyz, fzz);
}

template <typename Real>
void ImplicitSurface<Real>::GetFrame (const Vector3D<Real>& pos,Vector3D<Real>& tangent0, Vector3D<Real>& tangent1, Vector3D<Real>& normal) const
{
    normal = GetGradient(pos);
	auto vector3DOrthonormalBasis = Vector3DTools<Real>::GenerateOrthonormalBasis(normal);
	tangent0 = vector3DOrthonormalBasis.GetUVector();
	tangent1 = vector3DOrthonormalBasis.GetVVector();
}

template <typename Real>
bool ImplicitSurface<Real>::ComputePrincipalCurvatureInfo (const Vector3D<Real>& pos, Real& curv0, Real& curv1, Vector3D<Real>& dir0,Vector3D<Real>& dir1)
{
    // Principal curvatures and directions for implicitly defined surfaces
    // F(x,y,z) = 0.
    //
    // DF = (Fx,Fy,Fz), L = Length(DF)
    //
    // D^2 F = +-           -+
    //         | Fxx Fxy Fxz |
    //         | Fxy Fyy Fyz |
    //         | Fxz Fyz Fzz |
    //         +-           -+
    //
    // adj(D^2 F) = +-                                                 -+
    //              | Fyy*Fzz-Fyz*Fyz  Fyz*Fxz-Fxy*Fzz  Fxy*Fyz-Fxz*Fyy |
    //              | Fyz*Fxz-Fxy*Fzz  Fxx*Fzz-Fxz*Fxz  Fxy*Fxz-Fxx*Fyz |
    //              | Fxy*Fyz-Fxz*Fyy  Fxy*Fxz-Fxx*Fyz  Fxx*Fyy-Fxy*Fxy |
    //              +-                                                 -+
    //
    // Gaussian curvature = [DF^t adj(D^2 F) DF]/L^4
    // 
    // Mean curvature = 0.5*[trace(D^2 F)/L - (DF^t D^2 F DF)/L^3]

    // first derivatives
	auto fx = FX(pos);
	auto fy = FY(pos);
	auto fz = FZ(pos);
	auto fLength = Math<Real>::Sqrt(fx*fx + fy*fy + fz*fz);
    if (fLength <= Math<Real>::GetZeroTolerance())
    {
        return false;
    }

	auto fxfx = fx*fx;
	auto fxfy = fx*fy;
	auto fxfz = fx*fz;
	auto fyfy = fy*fy;
	auto fyfz = fy*fz;
	auto fzfz = fz*fz;

	auto invLength = (Math::GetValue(1))/fLength;
	auto invLength2 = invLength*invLength;
	auto invLength3 = invLength*invLength2;
	auto invLength4 = invLength2*invLength2;

    // second derivatives
	auto fxx = FXX(pos);
	auto fxy = FXY(pos);
	auto fxz = FXZ(pos);
	auto fyy = FYY(pos);
	auto fyz = FYZ(pos);
	auto fzz = FZZ(pos);

    // mean curvature
	auto meanCurv = (Real{0.5})*invLength3*(fxx*(fyfy + fzfz) + fyy*(fxfx + fzfz) + fzz*(fxfx + fyfy) - (Math::GetValue(2))*(fxy*fxfy + fxz*fxfz +  fyz*fyfz));

    // Gaussian curvature
	auto gaussCurv = invLength4*(fxfx*(fyy*fzz - fyz*fyz) + fyfy*(fxx*fzz - fxz*fxz) + fzfz*(fxx*fyy - fxy*fxy) + (Math::GetValue(2))*(fxfy*(fxz*fyz - fxy*fzz) + fxfz*(fxy*fyz - fxz*fyy)  + fyfz*(fxy*fxz - fxx*fyz)));

    // solve for principal curvatures
	auto discr = Math<Real>::Sqrt(Math<Real>::FAbs(meanCurv*meanCurv-gaussCurv));
    curv0 = meanCurv - discr;
    curv1 = meanCurv + discr;

	auto m00 = ((-Math::GetValue(1) + fxfx*invLength2)*fxx)*invLength + (fxfy*fxy)*invLength3 + (fxfz*fxz)*invLength3;
	auto m01 = ((-Math::GetValue(1) + fxfx*invLength2)*fxy)*invLength +  (fxfy*fyy)*invLength3 + (fxfz*fyz)*invLength3;
	auto m02 = ((-Math::GetValue(1) + fxfx*invLength2)*fxz)*invLength + (fxfy*fyz)*invLength3 + (fxfz*fzz)*invLength3;
	auto m10 = (fxfy*fxx)*invLength3 + ((-Math::GetValue(1) + fyfy*invLength2)*fxy)*invLength + (fyfz*fxz)*invLength3;
	auto m11 = (fxfy*fxy)*invLength3 + ((-Math::GetValue(1) + fyfy*invLength2)*fyy)*invLength + (fyfz*fyz)*invLength3;
	auto m12 = (fxfy*fxz)*invLength3 + ((-Math::GetValue(1) + fyfy*invLength2)*fyz)*invLength + (fyfz*fzz)*invLength3;
	auto m20 = (fxfz*fxx)*invLength3 + (fyfz*fxy)*invLength3 +  ((-Math::GetValue(1) + fzfz*invLength2)*fxz)*invLength;
	auto m21 = (fxfz*fxy)*invLength3 + (fyfz*fyy)*invLength3 +  ((-Math::GetValue(1) + fzfz*invLength2)*fyz)*invLength;
	auto m22 = (fxfz*fxz)*invLength3 + (fyfz*fyz)*invLength3 +  ((-Math::GetValue(1) + fzfz*invLength2)*fzz)*invLength;

    // solve for principal directions
	auto tmp1 = m00 + curv0;
	auto tmp2 = m11 + curv0;
	auto tmp3 = m22 + curv0;

    Vector3D<Real> U[3];
    Real lengths[3];

    U[0][0] = m01*m12-m02*tmp2;
    U[0][1] = m02*m10-m12*tmp1;
    U[0][2] = tmp1*tmp2-m01*m10;
    lengths[0] = Vector3DTools<Real>::VectorMagnitude(U[0]);

	U[1][0] = m01*tmp3 - m02*m21;
	U[1][1] = m02*m20 - tmp1*tmp3;
	U[1][2] = tmp1*m21 - m01*m20;
	lengths[1] = Vector3DTools<Real>::VectorMagnitude(U[1]);

	U[2][0] = tmp2*tmp3 - m12*m21;
	U[2][1] = m12*m20 - m10*tmp3;
	U[2][2] = m10*m21 - m20*tmp2;
	lengths[2] = Vector3DTools<Real>::VectorMagnitude(U[2]);

	auto maxIndex = 0;
	auto maxValue = lengths[0];
    if (lengths[1] > maxValue)
    {
        maxIndex = 1;
        maxValue = lengths[1];
    }
    if (lengths[2] > maxValue)
    {
        maxIndex = 2;
    }

    invLength = (Math::GetValue(1))/lengths[maxIndex];
    U[maxIndex] *= invLength;

    dir1 = U[maxIndex];
	dir0 = Vector3DTools<Real>::UnitCrossProduct(dir1, (Vector3D<Real>(fx, fy, fz)));

    return true;
}

}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_IMPLICIT_SURFACE_DETAIL_H