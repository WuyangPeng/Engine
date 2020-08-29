// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 17:22)

#ifndef MATHEMATICS_CONTAINMENT_CONT_SCRIBE_CIRCLE3_SPHERE3_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_SCRIBE_CIRCLE3_SPHERE3_DETAIL_H

#include "ContScribeCircle3Sphere3.h"
#include "Mathematics/NumericalAnalysis/LinearSystem.h"

template <typename Real>
bool Mathematics
	::Circumscribe(const Vector3D<Real>& v0, const Vector3D<Real>& v1, const Vector3D<Real>& v2, Circle3<Real>& circle)
{
    auto E02 = v0 - v2;
	auto E12 = v1 - v2;
	auto e02e02 = Vector3DTools<Real>::DotProduct(E02,E02);
	auto e02e12 = Vector3DTools<Real>::DotProduct(E02,E12);
	auto e12e12 = Vector3DTools<Real>::DotProduct(E12,E12);
	auto det = e02e02*e12e12 - e02e12*e02e12;
    if (Math<Real>::FAbs(det) < Math<Real>::GetZeroTolerance())
    {
        return false;
    }

	auto halfInvDet = (Real{0.5})/det;
	auto u0 = halfInvDet*e12e12*(e02e02 - e02e12);
	auto u1 = halfInvDet*e02e02*(e12e12 - e02e12);
	auto tmp = u0*E02 + u1*E12;

	auto center = v2 + tmp;
	auto radius = Vector3DTools<Real>::VectorMagnitude(tmp);

	auto normal = Vector3DTools<Real>::UnitCrossProduct(E02, E12);
	Vector3D<Real> direction0;

	if (Math<Real>::FAbs(normal.GetXCoordinate()) >= Math<Real>::FAbs(normal.GetYCoordinate())&& Math<Real>::FAbs(normal.GetXCoordinate()) >= Math<Real>::FAbs(normal.GetZCoordinate()))
    {
		 
		direction0.SetXCoordinate(-normal.GetYCoordinate());
		direction0.SetYCoordinate(normal.GetXCoordinate());
		direction0.SetZCoordinate(Math<Real>::GetValue(0));
    }
    else
    {
		direction0.SetXCoordinate(Math<Real>::GetValue(0));
		direction0.SetYCoordinate(normal.GetZCoordinate());
		direction0.SetZCoordinate(-normal.GetYCoordinate());        
    }

	direction0.Normalize();
	auto direction1 = Vector3DTools<Real>::CrossProduct(normal, direction0);

	circle = Circle3<Real>{ center, direction0, direction1, normal, radius };

    return true;
}

template <typename Real>
bool Mathematics
	::Circumscribe(const Vector3D<Real>& v0, const Vector3D<Real>& v1,const Vector3D<Real>& v2, const Vector3D<Real>& v3,Sphere3<Real>& sphere)
{
	auto E10 = v1 - v0;
	auto E20 = v2 - v0;
	auto E30 = v3 - v0;

    Real A[3][3]
    {
        {E10.GetXCoordinate(), E10.GetYCoordinate(), E10.GetZCoordinate()},
		{ E20.GetXCoordinate(), E20.GetYCoordinate(), E20.GetZCoordinate() },
		{ E30.GetXCoordinate(), E30.GetYCoordinate(), E30.GetZCoordinate() }
    };

    Real B[3] 
    {
		(Real{0.5})*Vector3DTools<Real>::VectorMagnitudeSquared(E10),
		(Real{0.5})*Vector3DTools<Real>::VectorMagnitudeSquared(E20),
		(Real{0.5})*Vector3DTools<Real>::VectorMagnitudeSquared(E30)
    };

    Vector3D<Real> solution;
	try
	{
		LinearSystem<Real>().Solve3(A, B, (Real*)&solution);
	
		sphere.SetSphere(v0 + solution, Vector3DTools<Real>::VectorMagnitude(solution));

		return true;
	}
	catch (CoreTools::Error&)
	{
		return false;
	}    
}

template <typename Real>
bool Mathematics
	::Inscribe(const Vector3D<Real>& v0, const Vector3D<Real>& v1, const Vector3D<Real>& v2, Circle3<Real>& circle)
{
    // Edges.
	auto E0 = v1 - v0;
	auto E1 = v2 - v1;
	auto E2 = v0 - v2;

    // Plane normal.
	auto normal = Vector3DTools<Real>::CrossProduct(E1, E0);

    // Edge normals within the plane.
	auto N0 = Vector3DTools<Real>::UnitCrossProduct(normal,E0);
	auto N1 = Vector3DTools<Real>::UnitCrossProduct(normal, E1);
	auto N2 = Vector3DTools<Real>::UnitCrossProduct(normal, E2);

	auto a0 = Vector3DTools<Real>::DotProduct(N1,E0);
    if (Math<Real>::FAbs(a0) < Math<Real>::GetZeroTolerance())
    {
        return false;
    }

	auto a1 = Vector3DTools<Real>::DotProduct(N2,E1);
	if (Math<Real>::FAbs(a1) < Math<Real>::GetZeroTolerance())
    {
        return false;
    }

	auto a2 = Vector3DTools<Real>::DotProduct(N0,E2);
	if (Math<Real>::FAbs(a2) < Math<Real>::GetZeroTolerance())
    {
        return false;
    }

	auto invA0 = (static_cast<Real>(1))/a0;
	auto invA1 = (static_cast<Real>(1))/a1;
	auto invA2 = (static_cast<Real>(1))/a2;

	auto radius = (static_cast<Real>(1)) / (invA0 + invA1 + invA2);
	auto center = circle.GetRadius()*(invA0*v0 + invA1*v1 + invA2*v2);

	normal.Normalize();
	auto direction0 = N0;
	auto direction1 = Vector3DTools<Real>::CrossProduct(normal, direction0);

	circle = Circle3<Real>{ center, direction0, direction1, normal, radius };

    return true;
}

template <typename Real>
bool Mathematics
	::Inscribe(const Vector3D<Real>& v0, const Vector3D<Real>& v1,  const Vector3D<Real>& v2, const Vector3D<Real>& v3, Sphere3<Real>& sphere)
{
    // Edges.
	auto E10 = v1 - v0;
	auto E20 = v2 - v0;
	auto E30 = v3 - v0;
	auto E21 = v2 - v1;
	auto E31 = v3 - v1;

    // Normals.
	auto N0 = Vector3DTools<Real>::CrossProduct(E31,E21);
	auto N1 = Vector3DTools<Real>::CrossProduct(E20,E30);
	auto N2 = Vector3DTools<Real>::CrossProduct(E30,E10);
	auto N3 = Vector3DTools<Real>::CrossProduct(E10,E20);

    // Normalize the normals.
	if (Math<Real>::FAbs(Vector3DTools<Real>::VectorMagnitude(N0)) < Math<Real>::GetZeroTolerance())
    {
        return false;
    }
	N0.Normalize();
	if (Math<Real>::FAbs(Vector3DTools<Real>::VectorMagnitude(N1)) < Math<Real>::GetZeroTolerance())
    {
        return false;
    }
	N1.Normalize();
	if (Math<Real>::FAbs(Vector3DTools<Real>::VectorMagnitude(N2)) < Math<Real>::GetZeroTolerance())
    {
        return false;
    }
	N2.Normalize();
	if (Math<Real>::FAbs(Vector3DTools<Real>::VectorMagnitude(N3)) < Math<Real>::GetZeroTolerance())
    {
        return false;
    }
	N3.Normalize();

    Real A[3][3] 
    {
		{ N1.GetXCoordinate() - N0.GetXCoordinate(), N1.GetYCoordinate() - N0.GetYCoordinate(), N1.GetZCoordinate() - N0.GetZCoordinate() },
		{ N2.GetXCoordinate() - N0.GetXCoordinate(), N2.GetYCoordinate() - N0.GetYCoordinate(), N2.GetZCoordinate() - N0.GetZCoordinate() },
		{ N3.GetXCoordinate() - N0.GetXCoordinate(), N3.GetYCoordinate() - N0.GetYCoordinate(), N3.GetZCoordinate() - N0.GetZCoordinate() }
    };

    Real B[3] 
    {
        Math<Real>::GetValue(0),
        Math<Real>::GetValue(0),
		-Vector3DTools<Real>::DotProduct(N3,E30)
    };

    Vector3D<Real> solution;

	try
	{
		LinearSystem<Real>().Solve3(A, B, (Real*)&solution);
		sphere.SetSphere(v3 + solution, Math<Real>::FAbs(Vector3DTools<Real>::DotProduct(N0, solution)));

		return true;
	}
	catch (CoreTools::Error&)
	{
		return false;
	}   
}

#endif // MATHEMATICS_CONTAINMENT_CONT_SCRIBE_CIRCLE3_SPHERE3_DETAIL_H