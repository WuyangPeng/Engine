// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 16:39)

#ifndef MATHEMATICS_CONTAINMENT_CONT_LOZENGE3_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_LOZENGE3_DETAIL_H

#include "ContLozenge3.h"
#include "Mathematics/Approximation/GaussPointsFit3.h"
#include "Mathematics/Distance/Distance3D/DistancePoint3Line3.h" 
#include "Mathematics/Distance/Distance3D/DistancePoint3Rectangle3.h" 

template <typename Real>
Mathematics::Lozenge3<Real> Mathematics
	::ContLozenge (const std::vector<Vector3D<Real> >& points)
{
    // Fit with Gaussian.  Axis(0) corresponds to the smallest eigenvalue.
	auto box = GaussPointsFit3<Real>(points).GetBox3();

	auto diff = points[0] - box.GetCenter();
	auto wMin = Vector3DTools<Real>::DotProduct(box.GetAxis(0),diff);
	auto wMax = wMin;
    Real w;
   
	for (auto i = 1u; i < points.size(); ++i)
    {
		diff = points[i] - box.GetCenter();
		w = Vector3DTools<Real>::DotProduct(box.GetAxis(0),diff);
        if (w < wMin)
        {
            wMin = w;
        }
        else if (w > wMax)
        {
            wMax = w;
        }
    }

	auto radius = (Real{0.5})*(wMax - wMin);
	auto rSqr = radius*radius;
	auto newCenter = box.GetCenter() + ((Real{0.5})*(wMax + wMin))*box.GetAxis(0);
	box = Box3<Real>{ newCenter, box.GetAxis0(), box.GetAxis1(), box.GetAxis2(),
					  box.GetFirstExtent(), box.GetSecondExtent(), box.GetThirdExtent() };

	auto aMin = Math<Real>::sm_MaxReal;
	auto aMax = -aMin;
	auto bMin = Math<Real>::sm_MaxReal;
	auto bMax = -bMin;
	auto discr, radical, u, v, test;
	for (auto i = 0u; i < points.size(); ++i)
    {
        diff = points[i] - box.GetCenter();
        u = Vector3DTools<Real>::DotProduct(box.GetAxis(2),diff);
		v = Vector3DTools<Real>::DotProduct(box.GetAxis(1), diff);
		w = Vector3DTools<Real>::DotProduct(box.GetAxis(0), diff);
        discr = rSqr - w*w;
        radical = Math<Real>::Sqrt(Math<Real>::FAbs(discr));

        test = u + radical;
        if (test < aMin)
        {
            aMin = test;
        }

        test = u - radical;
        if (test > aMax)
        {
            aMax = test;
        }

        test = v + radical;
        if (test < bMin)
        {
            bMin = test;
        }

        test = v - radical;
        if (test > bMax)
        {
            bMax = test;
        }
    }

    // The enclosing region might be a capsule or a sphere.
    if (aMin >= aMax)
    {
        test = (Real{0.5})*(aMin + aMax);
        aMin = test;
        aMax = test;
    }
    if (bMin >= bMax)
    {
        test = (Real{0.5})*(bMin + bMax);
        bMin = test;
        bMax = test;
    }

    // Make correction for points inside mitered corner but outside quarter
    // sphere.
	for (unsigned i = 0; i < points.size(); ++i)
    {
        diff = points[i] - box.GetCenter();
		u = Vector2DTools<Real>::DotProduct(box.GetAxis(2),diff);
		v = Vector2DTools<Real>::DotProduct(box.GetAxis(1),diff);

        Real* aExtreme = 0;
        Real* bExtreme = 0;

        if (u > aMax)
        {
            if (v > bMax)
            {
                aExtreme = &aMax;
                bExtreme = &bMax;
            }
            else if (v < bMin)
            {
                aExtreme = &aMax;
                bExtreme = &bMin;
            }
        }
        else if (u < aMin)
        {
            if (v > bMax)
            {
                aExtreme = &aMin;
                bExtreme = &bMax;
            }
            else if (v < bMin)
            {
                aExtreme = &aMin;
                bExtreme = &bMin;
            }
        }

        if (aExtreme)
        {
			auto deltaU = u - *aExtreme;
			auto deltaV = v - *bExtreme;
			auto deltaSumSqr = deltaU*deltaU + deltaV*deltaV;
			w = Vector2DTools<Real>::DotProduct(box.GetAxis(0),diff);
			auto wSqr = w*w;
            test = deltaSumSqr + wSqr;
            if (test > rSqr)
            {
                discr = (rSqr - wSqr)/deltaSumSqr;
                Real t = -Math<Real>::Sqrt(Math<Real>::FAbs(discr));
                *aExtreme = u + t*deltaU;
                *bExtreme = v + t*deltaV;
            }
        }
    }

	Vector3D<Real> center;
	Vector3D<Real> axis[2]{ box.GetAxis(2), box.GetAxis(1) };
	Real extent[2];

	if (aMin < aMax)
	{
		if (bMin < bMax)
		{
			// Container is a lozenge.
			center = box.GetCenter() + aMin*box.GetAxis(2) + bMin*box.GetAxis(1);
			extent[0] = (Real{0.5})*(aMax - aMin);
			extent[1] = (Real{0.5})*(bMax - bMin);
		}
		else
		{
			// Container is a capsule.
			center = box.GetCenter() + aMin*box.GetAxis(2) + ((Real{0.5})*(bMin + bMax))*box.GetAxis(1);
			extent[0] = (Real{0.5})*(aMax - aMin);
			extent[1] = Math<Real>::GetValue(0);
		}
	}
	else
	{
		if (bMin < bMax)
		{
			// Container is a capsule.
			center = box.GetCenter() + bMin*box.GetAxis(1) + ((Real{0.5})*(aMin + aMax))*box.GetAxis(2);
			extent[0] = Math<Real>::GetValue(0);
			extent[1] = (Real{0.5})*(bMax - bMin);
		}
		else
		{
			// Container is a sphere.
			center = box.GetCenter() +
				((Real{0.5})*(aMin + aMax))*box.GetAxis(2) +
				((Real{0.5})*(bMin + bMax))*box.GetAxis(1);
			extent[0] = Math<Real>::GetValue(0);
			extent[1] = Math<Real>::GetValue(0);
		}
	}
	Rectangle3<Real> rectangle{ center,axis[0],axis[1],extent[0],extent[1] };
	Lozenge3<Real> lozenge{ rectangle,radius };

    return lozenge;
}

template <typename Real>
bool Mathematics
	::InLozenge (const Vector3D<Real>& point, const Lozenge3<Real>& lozenge)
{
	auto dist = DistancePoint3Rectangle3<Real>(point, lozenge.GetRectangle()).Get().GetDistance();
    return dist <= lozenge.GetRadius();
}

#endif // MATHEMATICS_CONTAINMENT_CONT_LOZENGE3_DETAIL_H