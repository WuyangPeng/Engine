// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 10:46)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_FRUSTUM3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_FRUSTUM3_DETAIL_H

#include "StaticTestIntersectorBox3Frustum3.h"

template <typename Real>
Mathematics::StaticTestIntersectorBox3Frustum3<Real>
	::StaticTestIntersectorBox3Frustum3 (const Box3& box, const Frustum3& frustum)
	:m_Box{ box }, mFrustum{ frustum }
{
	Test();
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::StaticTestIntersectorBox3Frustum3<Real>
	::GetBox () const
{
    return m_Box;
}

template <typename Real>
const Mathematics::Frustum3<Real> Mathematics::StaticTestIntersectorBox3Frustum3<Real>
	::GetFrustum () const
{
    return mFrustum;
}

template <typename Real>
void Mathematics::StaticTestIntersectorBox3Frustum3<Real>
	::Test ()
{
    // for convenience
	const Vector3D axes[] { m_Box.GetAxis0(),m_Box.GetAxis1(),m_Box.GetAxis2() };
	const Real extents[]{ m_Box.GetExtent0(),m_Box.GetExtent1(),m_Box.GetExtent2() };

    auto diff = m_Box.GetCenter() - mFrustum.GetOrigin();  // C-E

    Real A[3];      // Dot(Real,A[i])
    Real B[3];      // Dot(U,A[i])
    Real C[3];      // Dot(D,A[i])
    Real D[3];      // (Dot(Real,C-E),Dot(U,C-E),Dot(D,C-E))
    Real NA[3];     // dmin*Dot(Real,A[i])
    Real NB[3];     // dmin*Dot(U,A[i])
    Real NC[3];     // dmin*Dot(D,A[i])
    Real ND[3];     // dmin*(Dot(Real,C-E),Dot(U,C-E),?)
    Real RC[3];     // rmax*Dot(D,A[i])
    Real RD[3];     // rmax*(?,?,Dot(D,C-E))
    Real UC[3];     // umax*Dot(D,A[i])
    Real UD[3];     // umax*(?,?,Dot(D,C-E))
    Real NApRC[3];  // dmin*Dot(Real,A[i]) + rmax*Dot(D,A[i])
    Real NAmRC[3];  // dmin*Dot(Real,A[i]) - rmax*Dot(D,A[i])
    Real NBpUC[3];  // dmin*Dot(U,A[i]) + umax*Dot(D,A[i])
    Real NBmUC[3];  // dmin*Dot(U,A[i]) - umax*Dot(D,A[i])
    Real RBpUA[3];  // rmax*Dot(U,A[i]) + umax*Dot(Real,A[i])
    Real RBmUA[3];  // rmax*Dot(U,A[i]) - umax*Dot(Real,A[i])
    Real DdD, radius, p, fmin, fmax, MTwoUF, MTwoRF, tmp;
    int i, j;

    // M = D
    D[2] = Vector3DTools::DotProduct(diff,mFrustum.GetDirectionVector());
    for (i = 0; i < 3; ++i)
    {
        C[i] = Vector3DTools::DotProduct(axes[i],mFrustum.GetDirectionVector());
    }
    radius = extents[0]*Math::FAbs(C[0]) + extents[1]*Math::FAbs(C[1]) + extents[2]*Math::FAbs(C[2]);
    if (D[2] + radius < mFrustum.GetDirectionMin() ||  D[2] - radius > mFrustum.GetDirectionMax())
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // M = n*Real - r*D
    for (i = 0; i < 3; ++i)
    {
        A[i] = Vector3DTools::DotProduct(axes[i],mFrustum.GetRightVector());
        RC[i] = mFrustum.GetRightBound()*C[i];
        NA[i] = mFrustum.GetDirectionMin()*A[i];
        NAmRC[i] = NA[i] - RC[i];
    }
    D[0] = Vector3DTools::DotProduct(diff,mFrustum.GetRightVector());
    radius = extents[0]*Math::FAbs(NAmRC[0]) + extents[1]*Math::FAbs(NAmRC[1]) + extents[2]*Math::FAbs(NAmRC[2]);
    ND[0] = mFrustum.GetDirectionMin()*D[0];
    RD[2] = mFrustum.GetRightBound()*D[2];
    DdD = ND[0] - RD[2];
    MTwoRF = mFrustum.GetMTwoRF();
    if (DdD + radius < MTwoRF || DdD > radius)
    {
		this->SetIntersectionType(IntersectionType::Empty);
		return;
    }

    // M = -n*Real - r*D
    for (i = 0; i < 3; ++i)
    {
        NApRC[i] = NA[i] + RC[i];
    }
    radius = extents[0]*Math::FAbs(NApRC[0]) + extents[1]*Math::FAbs(NApRC[1]) + extents[2]*Math::FAbs(NApRC[2]);
    DdD = -(ND[0] + RD[2]);
    if (DdD + radius < MTwoRF || DdD > radius)
    {
		this->SetIntersectionType(IntersectionType::Empty);
		return;
    }

    // M = n*U - u*D
    for (i = 0; i < 3; ++i)
    {
        B[i] = Vector3DTools::DotProduct(axes[i],mFrustum.GetUpVector());
        UC[i] = mFrustum.GetUpBound()*C[i];
        NB[i] = mFrustum.GetDirectionMin()*B[i];
        NBmUC[i] = NB[i] - UC[i];
    }
    D[1] = Vector3DTools::DotProduct(diff,mFrustum.GetUpVector());
    radius = extents[0]*Math::FAbs(NBmUC[0]) + extents[1]*Math::FAbs(NBmUC[1]) + extents[2]*Math::FAbs(NBmUC[2]);
    ND[1] = mFrustum.GetDirectionMin()*D[1];
    UD[2] = mFrustum.GetUpBound()*D[2];
    DdD = ND[1] - UD[2];
    MTwoUF = mFrustum.GetMTwoUF();
    if (DdD + radius < MTwoUF || DdD > radius)
    {
		this->SetIntersectionType(IntersectionType::Empty);
		return;
    }

    // M = -n*U - u*D
    for (i = 0; i < 3; ++i)
    {
        NBpUC[i] = NB[i] + UC[i];
    }
    radius = extents[0]*Math::FAbs(NBpUC[0]) + extents[1]*Math::FAbs(NBpUC[1]) + extents[2]*Math::FAbs(NBpUC[2]);
    DdD = -(ND[1] + UD[2]);
    if (DdD + radius < MTwoUF || DdD > radius)
    {
		this->SetIntersectionType(IntersectionType::Empty);
		return;
    }

    // M = A[i]
    for (i = 0; i < 3; ++i)
    {
        p = mFrustum.GetRightBound()*Math::FAbs(A[i]) + mFrustum.GetUpBound()*Math::FAbs(B[i]);
        NC[i] = mFrustum.GetDirectionMin()*C[i];
        fmin = NC[i] - p;
        if (fmin < Math<Real>::GetZero())
        {
            fmin *= mFrustum.GetDirectionRatio();
        }
        fmax = NC[i] + p;
        if (fmax > Math<Real>::GetZero())
        {
            fmax *= mFrustum.GetDirectionRatio();
        }
        DdD = A[i]*D[0] + B[i]*D[1] + C[i]*D[2];
        if (DdD + extents[i] < fmin || DdD - extents[i] > fmax)
        {
			this->SetIntersectionType(IntersectionType::Empty);
			return;
        }
    }

    // M = Cross(Real,A[i])
    for (i = 0; i < 3; ++i)
    {
        p = mFrustum.GetUpBound()*Math::FAbs(C[i]);
        fmin = -NB[i] - p;
        if (fmin < Math<Real>::GetZero())
        {
            fmin *= mFrustum.GetDirectionRatio();
        }
        fmax = -NB[i] + p;
        if (fmax > Math<Real>::GetZero())
        {
            fmax *= mFrustum.GetDirectionRatio();
        }
        DdD = C[i]*D[1] - B[i]*D[2];
        radius =  extents[0]*Math::FAbs(B[i]*C[0]-B[0]*C[i]) + extents[1]*Math::FAbs(B[i]*C[1]-B[1]*C[i]) + extents[2]*Math::FAbs(B[i]*C[2]-B[2]*C[i]);
        if (DdD + radius < fmin || DdD - radius > fmax)
        {
			this->SetIntersectionType(IntersectionType::Empty);
			return;
        }
    }

    // M = Cross(U,A[i])
    for (i = 0; i < 3; ++i)
    {
        p = mFrustum.GetRightBound()*Math::FAbs(C[i]);
        fmin = NA[i] - p;
        if (fmin < Math<Real>::GetZero())
        {
            fmin *= mFrustum.GetDirectionRatio();
        }
        fmax = NA[i] + p;
        if (fmax > Math<Real>::GetZero())
        {
            fmax *= mFrustum.GetDirectionRatio();
        }
        DdD = -C[i]*D[0] + A[i]*D[2];
        radius = extents[0]*Math::FAbs(A[i]*C[0]-A[0]*C[i]) + extents[1]*Math::FAbs(A[i]*C[1]-A[1]*C[i]) + extents[2]*Math::FAbs(A[i]*C[2]-A[2]*C[i]);
        if (DdD + radius < fmin || DdD - radius > fmax)
        {
			this->SetIntersectionType(IntersectionType::Empty);
			return;
        }
    }

    // M = Cross(n*D+r*Real+u*U,A[i])
    for (i = 0; i < 3; ++i)
    {
		auto fRB = mFrustum.GetRightBound()*B[i];
		auto fUA = mFrustum.GetUpBound()*A[i];
        RBpUA[i] = fRB + fUA;
        RBmUA[i] = fRB - fUA;
    }
    for (i = 0; i < 3; ++i)
    {
        p = mFrustum.GetRightBound()*Math::FAbs(NBmUC[i]) + mFrustum.GetUpBound()*Math::FAbs(NAmRC[i]);
        tmp = -mFrustum.GetDirectionMin()*RBmUA[i];
        fmin = tmp - p;
        if (fmin < Math<Real>::GetZero())
        {
            fmin *= mFrustum.GetDirectionRatio();
        }
        fmax = tmp + p;
        if (fmax > Math<Real>::GetZero())
        {
            fmax *= mFrustum.GetDirectionRatio();
        }
        DdD = D[0]*NBmUC[i] - D[1]*NAmRC[i] - D[2]*RBmUA[i];
        radius = Math<Real>::GetZero();
        for (j = 0; j < 3; j++)
        {
            radius += extents[j]*Math::FAbs(A[j]*NBmUC[i] - B[j]*NAmRC[i] - C[j]*RBmUA[i]);
        }
        if (DdD + radius < fmin || DdD - radius > fmax)
        {
			this->SetIntersectionType(IntersectionType::Empty);
			return;
        }
    }

    // M = Cross(n*D+r*Real-u*U,A[i])
    for (i = 0; i < 3; ++i)
    {
        p = mFrustum.GetRightBound()*Math::FAbs(NBpUC[i]) + mFrustum.GetUpBound()*Math::FAbs(NAmRC[i]);
        tmp = -mFrustum.GetDirectionMin()*RBpUA[i];
        fmin = tmp - p;
        if (fmin < Math<Real>::GetZero())
        {
            fmin *= mFrustum.GetDirectionRatio();
        }
        fmax = tmp + p;
        if (fmax > Math<Real>::GetZero())
        {
            fmax *= mFrustum.GetDirectionRatio();
        }
        DdD = D[0]*NBpUC[i] - D[1]*NAmRC[i] - D[2]*RBpUA[i];
        radius = Math<Real>::GetZero();
        for (j = 0; j < 3; ++j)
        {
            radius += extents[j]*Math::FAbs(A[j]*NBpUC[i] - B[j]*NAmRC[i] - C[j]*RBpUA[i]);
        }
        if (DdD + radius < fmin || DdD - radius > fmax)
        {
			this->SetIntersectionType(IntersectionType::Empty);
			return;
        }
    }

    // M = Cross(n*D-r*Real+u*U,A[i])
    for (i = 0; i < 3; ++i)
    {
        p = mFrustum.GetRightBound()*Math::FAbs(NBmUC[i]) + mFrustum.GetUpBound()*Math::FAbs(NApRC[i]);
        tmp = mFrustum.GetDirectionMin()*RBpUA[i];
        fmin = tmp - p;
        if (fmin < Math<Real>::GetZero())
        {
            fmin *= mFrustum.GetDirectionRatio();
        }
        fmax = tmp + p;
        if (fmax > Math<Real>::GetZero())
        {
            fmax *= mFrustum.GetDirectionRatio();
        }
        DdD = D[0]*NBmUC[i] - D[1]*NApRC[i] + D[2]*RBpUA[i];
        radius = Math<Real>::GetZero();
        for (j = 0; j < 3; ++j)
        {
            radius += extents[j]*Math::FAbs(A[j]*NBmUC[i] - B[j]*NApRC[i] + C[j]*RBpUA[i]);
        }
        if (DdD + radius < fmin || DdD - radius > fmax)
        {
			this->SetIntersectionType(IntersectionType::Empty);
			return;
        }
    }

    // M = Cross(n*D-r*Real-u*U,A[i])
    for (i = 0; i < 3; ++i)
    {
        p = mFrustum.GetRightBound()*Math::FAbs(NBpUC[i]) + mFrustum.GetUpBound()*Math::FAbs(NApRC[i]);
        tmp = mFrustum.GetDirectionMin()*RBmUA[i];
        fmin = tmp - p;
        if (fmin < Math<Real>::GetZero())
        {
            fmin *= mFrustum.GetDirectionRatio();
        }
        fmax = tmp + p;
        if (fmax > Math<Real>::GetZero())
        {
            fmax *= mFrustum.GetDirectionRatio();
        }
        DdD = D[0]*NBpUC[i] - D[1]*NApRC[i] + D[2]*RBmUA[i];
        radius = Math<Real>::GetZero();
        for (j = 0; j < 3; ++j)
        {
            radius += extents[j]*Math::FAbs(A[j]*NBpUC[i] - B[j]*NApRC[i] + C[j]*RBmUA[i]);
        }
        if (DdD + radius < fmin || DdD - radius > fmax)
        {
			this->SetIntersectionType(IntersectionType::Empty);
			return;
        }
    }

	this->SetIntersectionType(IntersectionType::Point);
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_FRUSTUM3_DETAIL_H