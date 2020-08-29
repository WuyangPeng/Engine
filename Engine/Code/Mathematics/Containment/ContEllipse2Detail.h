// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 16:30)

#ifndef MATHEMATICS_CONTAINMENT_CONT_ELLIPSE2_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_ELLIPSE2_DETAIL_H

#include "ContEllipse2.h"
#include "Mathematics/Approximation/GaussPointsFit2.h"

template <typename Real>
Mathematics::Ellipse2<Real> Mathematics
	::ContEllipse (const std::vector<Vector2D<Real> >& points)
{
    // Fit the points with a Gaussian distribution.  The covariance matrix
    // is M = D[0]*U[0]*U[0]^T+D[1]*U[1]*U[1]^T, where D[0] and D[1] are the
    // eigenvalues and U[0] and U[1] are corresponding unit-length
    // eigenvectors.
	auto box = GaussPointsFit2<Real>(points).GetBox2();
	Real diag[2]{ box.GetFirstExtent(),box.GetSecondExtent() };
	Vector2D<Real> axis[2]{  box.GetFirstAxis(),box.GetSecondAxis()};

    // If either eigenvalue is nonpositive, adjust the D[] values so that
    // we actually build an ellipse.
    for (auto i = 0; i < 2; ++i)
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

    // Grow the ellipse, while retaining its shape determined by the
    // covariance matrix, to enclose all the input points.  The quadratic form
    // that is used for the ellipse construction is
    //
    //   Q(X) = (X-C)^T*M*(X-C)
    //        = (X-C)^T*(U[0]*U[0]^T/D[0]+U[1]*U[1]^T/D[1])*(X-C)
    //        = Dot(U[0],X-C)^2/D[0] + Dot(U[1],X-C)^2/D[1]
    //
    // If the maximum value of Q(X[i]) for all input points is V^2, then a
    // bounding ellipse is Q(X) = V^2 since Q(X[i]) <= V^2 for all i.

	auto maxValue = Math<Real>::GetValue(0);
    for (auto i = 0u; i < points.size(); ++i)
    {
		auto diff = points[i] - box.GetCenter();
        Real dot[2]{ Vector2DTools<Real>::DotProduct(axis[0],diff), 
			         Vector2DTools<Real>::DotProduct(axis[1],diff) };
		auto value = dot[0]*dot[0]/diag[0] + dot[1]*dot[1]/diag[1];
        if (value > maxValue)
        {
            maxValue = value;
        }
    }

    // Arrange for quadratic to satisfy Q(X) <= 1.
    for (auto i = 0u; i < 2; ++i)
    {
        diag[i] *= maxValue;
    }

	auto center = box.GetCenter();
	Vector2D<Real> ellipseAxis[2];
	Real extent[2];

	for (auto i = 0u; i < 2; ++i)
	{
		ellipseAxis[i] = axis[i];
		extent[i] = Math<Real>::Sqrt(diag[i]);
	}

	Ellipse2<Real> ellipse{ center,ellipseAxis[0],ellipseAxis[1],extent[0],extent[1] };
   
    return ellipse;
}

template <typename Real>
void Mathematics
	::ProjectEllipse (const Ellipse2<Real>& ellipse, const Line2<Real>& line,Real& smin, Real& smax)
{
    // Center of projection interval.
	auto center = Vector2DTools<Real>::DotProduct(line.GetDirection(),ellipse.GetCenter() - line.GetOrigin());

    // Radius of projection interval.
    Real tmp[2] { ellipse.GetExtent0()*(Vector2DTools<Real>::DotProduct(line.GetDirection(),ellipse.GetAxis0())),
			      ellipse.GetExtent1()*(Vector2DTools<Real>::DotProduct(line.GetDirection(),ellipse.GetAxis1())) };
	auto rSqr = tmp[0]*tmp[0] + tmp[1]*tmp[1];
	auto radius = Math<Real>::Sqrt(rSqr);

    smin = center - radius;
    smax = center + radius;
}

template <typename Real>
const Mathematics::Ellipse2<Real> Mathematics
	::MergeEllipses (const Ellipse2<Real>& ellipse0,const Ellipse2<Real>& ellipse1)
{
    // Compute the average of the input centers.
	auto center = (Real{0.5})*(ellipse0.GetCenter() + ellipse1.GetCenter());
	Vector2D<Real> axis[2];

    // Bounding ellipse orientation is average of input orientations.
    if (Vector2DTools<Real>::DotProduct(ellipse0.GetAxis0(),ellipse1.GetAxis0()) >= Math<Real>::GetValue(0))
    {
        axis[0] = (Real{0.5})*(ellipse0.GetAxis0() + ellipse1.GetAxis0());
        axis[0].Normalize();
    }
    else
    {
        axis[0] = (Real{0.5})*(ellipse0.GetAxis0() - ellipse1.GetAxis0());
        axis[0].Normalize();
    }
    axis[1] = -Vector2DTools<Real>::GetPerp(axis[0]); 

	Real extent[2];

    // Project the input ellipses onto the axes obtained by the average
    // of the orientations and that go through the center obtained by the
    // average of the centers.
    for (auto i = 0; i < 2; ++i)
    {
        // Projection axis.
		Line2<Real> line{ center, axis[i] };

        // Project ellipsoids onto the axis.
        Real min0, max0, min1, max1;
        ProjectEllipse(ellipse0, line, min0, max0);
        ProjectEllipse(ellipse1, line, min1, max1);

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

	Ellipse2<Real> merge{ center,axis[0],axis[1],extent[0],extent[1] };

    return merge;
}

#endif // MATHEMATICS_CONTAINMENT_CONT_ELLIPSE2_DETAIL_H