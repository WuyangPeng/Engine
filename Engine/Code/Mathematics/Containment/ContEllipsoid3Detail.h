// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 16:32)

#ifndef MATHEMATICS_CONTAINMENT_CONT_ELLIPSOID3_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_ELLIPSOID3_DETAIL_H

#include "ContEllipsoid3.h"
#include "Mathematics/Algebra/Quaternion.h"
#include "Mathematics/Approximation/GaussPointsFit3.h"

template <typename Real>
Mathematics::Ellipsoid3<Real> Mathematics
	::ContEllipsoid (const std::vector<Vector3D<Real> >& points)
{
    // Fit the points with a Gaussian distribution.  The covariance matrix
    // is M = D[0]*U[0]*U[0]^T+D[1]*U[1]*U[1]^T+D[2]*U[2]*U[2]^T where D[0],
    // D[1], and D[2] are the eigenvalues and U[0], U[1], and U[2] are
    // corresponding unit-length eigenvectors.
    auto box = GaussPointsFit3<Real>(points).GetBox3();
	Real diag[3]{ box.GetExtent(0),box.GetExtent(1),box.GetExtent(2) };
    Vector3D<Real> axis[3]{ box.GetAxis(0),box.GetAxis(1),box.GetAxis(2) };

    // If either eigenvalue is nonpositive, adjust the D[] values so that
    // we actually build an ellipse.
    for (auto i = 0; i < 3; ++i)
    {
        if (diag[i] < Math<Real>::GetValue(0))
        {
            diag[i] = -diag[i];
        }
        if (diag[i] < Math<Real>::GetZeroTolerance())
        {
            diag[i] = Math<Real>::GetZeroTolerance();
        }
    }

    // Grow the ellipsoid, while retaining its shape determined by the
    // covariance matrix, to enclose all the input points.  The quadratic form
    // that is used for the ellipsoid construction is
    //
    //   Q(X) = (X-C)^T*M*(X-C)
    //        = (X-C)^T*(sum_{j=0}^2 U[j]*U[j]^T/D[j])*(X-C)
    //        = sum_{j=0}^2 Dot(U[i],X-C)^2/D[j]
    //
    // If the maximum value of Q(X[i]) for all input points is V^2, then a
    // bounding ellipsoid is Q(X) = V^2 since Q(X[i]) <= V^2 for all i.

	auto maxValue = Math<Real>::GetValue(0);
    for (auto i = 0u; i < points.size(); ++i)
    {
		auto diff = points[i] - box.GetCenter();
        Real dot[3] { Vector3DTools<Real>::DotProduct(axis[0],diff),
					  Vector3DTools<Real>::DotProduct(axis[1],diff),
					  Vector3DTools<Real>::DotProduct(axis[2],diff) };

		auto value = dot[0]*dot[0]/diag[0] + dot[1]*dot[1]/diag[1] + dot[2]*dot[2]/diag[2];

        if (value > maxValue)
        {
            maxValue = value;
        }
    }

    // Arrange for quadratic to satisfy Q(X) <= 1.
    for (auto i = 0u; i < 3; ++i)
    {
        diag[i] *= maxValue;
    }

	Ellipsoid3<Real> ellipsoid{ box.GetCenter(),axis[0],axis[1],axis[2],
								Math<Real>::Sqrt(diag[0]),Math<Real>::Sqrt(diag[1]),
								Math<Real>::Sqrt(diag[2]) };

    return ellipsoid;
}

template <typename Real>
void Mathematics
	::ProjectEllipsoid (const Ellipsoid3<Real>& ellipsoid, const Line3<Real>& line, Real& smin, Real& smax)
{
    // Center of projection interval.
	auto center = Vector3DTools<Real>::DotProduct(line.GetDirection(),ellipsoid.GetCenter() - line.GetOrigin());

    // Radius of projection interval.
    Real tmp[3] { ellipsoid.GetExtent0()*(Vector3DTools<Real>::DotProduct(line.GetDirection(),ellipsoid.GetAxis0())),
				  ellipsoid.GetExtent1()*(Vector3DTools<Real>::DotProduct(line.GetDirection(),ellipsoid.GetAxis1())),
				  ellipsoid.GetExtent2()*(Vector3DTools<Real>::DotProduct(line.GetDirection(),ellipsoid.GetAxis2())) };
	auto rSqr = tmp[0]*tmp[0] + tmp[1]*tmp[1] + tmp[2]*tmp[2];
	auto radius = Math<Real>::Sqrt(rSqr);

    smin = center - radius;
    smax = center + radius;
}

template <typename Real>
const Mathematics::Ellipsoid3<Real>  Mathematics
	::MergeEllipsoids (const Ellipsoid3<Real>& ellipsoid0, const Ellipsoid3<Real>& ellipsoid1)
{
    // compute the average of the input centers
	auto center = (Real{0.5})*(ellipsoid0.GetCenter() + ellipsoid1.GetCenter());

    // bounding ellipsoid orientation is average of input orientations
	std::vector<Vector3D<Real> > rotationColumn0;
	rotationColumn0.push_back(ellipsoid0.GetAxis0());
	rotationColumn0.push_back(ellipsoid0.GetAxis1());
	rotationColumn0.push_back(ellipsoid0.GetAxis2());

	std::vector<Vector3D<Real> > rotationColumn1;
	rotationColumn1.push_back(ellipsoid1.GetAxis0());
	rotationColumn1.push_back(ellipsoid1.GetAxis1());
	rotationColumn1.push_back(ellipsoid1.GetAxis2());

	Quaternion<Real> q0{ rotationColumn0 };
	Quaternion<Real> q1{ rotationColumn1 };
    if (Dot(q0,q1) < Math<Real>::GetValue(0))
    {
        q1 = -q1;
    }
	auto q = q0 + q1;
    q = Math<Real>::InvSqrt(Dot(q,q))*q;
	auto matrix = q.ToRotationMatrix();

	Vector3D<Real> axis[3]{ Vector3D<Real>{matrix[0][0],matrix[0][1],matrix[0][2]},
							Vector3D<Real>{matrix[1][0],matrix[1][1],matrix[1][2]},
							Vector3D<Real>{matrix[2][0],matrix[2][1],matrix[2][2]} };

	Real extent[3];

    // Project the input ellipsoids onto the axes obtained by the average
    // of the orientations and that go through the center obtained by the
    // average of the centers.
    for (auto i = 0; i < 3; ++i)
    {
        // Projection axis.
		Line3<Real> line{ center, axis[i] };

        // Project ellipsoids onto the axis.
        Real min0, max0, min1, max1;
        ProjectEllipsoid(ellipsoid0, line, min0, max0);
        ProjectEllipsoid(ellipsoid1, line, min1, max1);

        // Determine the smallest interval containing the projected
        // intervals.
		auto maxIntr = (max0 >= max1 ? max0 : max1);
		auto minIntr = (min0 <= min1 ? min0 : min1);

        // Update the average center to be the center of the bounding box
        // defined by the projected intervals.
        center += line.GetDirection()*((Real{0.5})*(minIntr + maxIntr));

        // Compute the extents of the box based on the new center.
        extent[i] = (Real{0.5})*(maxIntr - minIntr);
    }

	Ellipsoid3<Real> merge{ center,axis[0],axis[1],axis[2],extent[0],extent[1],extent[2] };

    return merge;
}

#endif // MATHEMATICS_CONTAINMENT_CONT_ELLIPSOID3_DETAIL_H