// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 10:03)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRAHEDRON3_TETRAHEDRON3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRAHEDRON3_TETRAHEDRON3_DETAIL_H

#include "StaticFindIntersectorTetrahedron3Tetrahedron3.h"

template <typename Real>
Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3<Real>
	::StaticFindIntersectorTetrahedron3Tetrahedron3 (const Tetrahedron3& tetrahedron0,const Tetrahedron3& tetrahedron1)
	: mTetrahedron0{ tetrahedron0 }, mTetrahedron1{ tetrahedron1 }
{
	Find();
}

template <typename Real>
const Mathematics::Tetrahedron3<Real> Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3<Real>
	::GetTetrahedron0() const
{
    return mTetrahedron0;
}

template <typename Real>
const Mathematics::Tetrahedron3<Real> Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3<Real>
	::GetTetrahedron1() const
{
    return mTetrahedron1;
}

template <typename Real>
void Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3<Real>
	::Find()
{
    // Build planar faces of tetrahedron0.
	auto plane =  mTetrahedron0.GetPlanes();

    // Initial object to clip is tetrahedron1.
    mIntersection.clear();
    mIntersection.push_back(mTetrahedron1);

    // Clip tetrahedron1 against planes of tetrahedron0.
    for (auto i = 0; i < 4; ++i)
    {
        std::vector<Tetrahedron3> inside;
        for (auto j = 0; j < (int)mIntersection.size(); ++j)
        {
            SplitAndDecompose(mIntersection[j], plane[i], inside);
        }
        mIntersection = inside;
    }

	if (mIntersection.size() > 0)
	{
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}

template <typename Real>
const std::vector< Mathematics::Tetrahedron3<Real> > Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3<Real>
	::GetIntersection() const
{
    return mIntersection;
}

template <typename Real>
void  Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3<Real>
	::SplitAndDecompose(Tetrahedron3 tetra, const Plane3& plane,
	std::vector<Tetrahedron3>& inside)
{
    // Determine on which side of the plane the points of the tetrahedron lie.
    Real C[4];
    int i, pos[4], neg[4], zer[4];
    int positive = 0, negative = 0, zero = 0;

    for (i = 0; i < 4; ++i)
    {
        C[i] = plane.DistanceTo(tetra.GetVertex(i));
        if (C[i] > Real{})
        {
            pos[positive++] = i;
        }
        else if (C[i] < Real{})
        {
            neg[negative++] = i;
        }
        else
        {
            zer[zero++] = i;
        }
    }

    // For a split to occur, one of the c_i must be positive and one must
    // be negative.

    if (negative == 0)
    {
        // Tetrahedron is completely on the positive side of plane, full clip.
        return;
    }

    if (positive == 0)
    {
        // Tetrahedron is completely on the negative side of plane.
        inside.push_back(tetra);
        return;
    }

    // Tetrahedron is split by plane.  Determine how it is split and how to
    // decompose the negative-side portion into tetrahedra (6 cases).
    Real w0, w1, invCDiff;
    Vector3D intp[4];

    if (positive == 3)
    {
        // +++-
        for (i = 0; i < positive; ++i)
        {
            invCDiff = ((Real)1)/(C[pos[i]] - C[neg[0]]);
            w0 = -C[neg[0]]*invCDiff;
            w1 = +C[pos[i]]*invCDiff;
            tetra.SetVertex(pos[i], w0*tetra.GetVertex(pos[i]) + w1*tetra.GetVertex(neg[0]));
        }
        inside.push_back(tetra);
    }
    else if (positive == 2)
    {
        if (negative == 2)
        {
            // ++--
            for (i = 0; i < positive; ++i)
            {
                invCDiff = ((Real)1)/(C[pos[i]] - C[neg[0]]);
                w0 = -C[neg[0]]*invCDiff;
                w1 = +C[pos[i]]*invCDiff;
				intp[i] = w0*tetra.GetVertex(pos[i]) + w1*tetra.GetVertex(neg[0]);
            }
            for (i = 0; i < negative; ++i)
            {
                invCDiff = ((Real)1)/(C[pos[i]] - C[neg[1]]);
                w0 = -C[neg[1]]*invCDiff;
                w1 = +C[pos[i]]*invCDiff;
				intp[i + 2] = w0*tetra.GetVertex(pos[i]) + w1*tetra.GetVertex(neg[1]);
            }

            tetra.SetVertex(pos[0], intp[2]);
			tetra.SetVertex(pos[1],intp[1]);
            inside.push_back(tetra);

			inside.push_back(Tetrahedron3{ tetra.GetVertex(neg[1]), intp[3], intp[2], intp[1] });

			inside.push_back(Tetrahedron3{ tetra.GetVertex(neg[0]),  intp[0], intp[1], intp[2] });
        }
        else
        {
            // ++-0
            for (i = 0; i < positive; ++i)
            {
                invCDiff = ((Real)1)/(C[pos[i]] - C[neg[0]]);
                w0 = -C[neg[0]]*invCDiff;
                w1 = +C[pos[i]]*invCDiff;
				tetra.SetVertex(pos[i], w0*tetra.GetVertex(pos[i]) + w1*tetra.GetVertex(neg[0]));
            }
            inside.push_back(tetra);
        }
    }
    else if (positive == 1)
    {
        if (negative == 3)
        {
            // +---
            for (i = 0; i < negative; ++i)
            {
                invCDiff = ((Real)1)/(C[pos[0]] - C[neg[i]]);
                w0 = -C[neg[i]]*invCDiff;
                w1 = +C[pos[0]]*invCDiff;
				intp[i] = w0*tetra.GetVertex(pos[0]) + w1*tetra.GetVertex(neg[i]);
            }

            tetra.SetVertex(pos[0], intp[0]);
            inside.push_back(tetra);

            inside.push_back(Tetrahedron3(intp[0], tetra.GetVertex(neg[1]), tetra.GetVertex(neg[2]), intp[1]));

			inside.push_back(Tetrahedron3(tetra.GetVertex(neg[2]), intp[1], intp[2], intp[0]));
        }
        else if (negative == 2)
        {
            // +--0
            for (i = 0; i < negative; ++i)
            {
                invCDiff = ((Real)1)/(C[pos[0]] - C[neg[i]]);
                w0 = -C[neg[i]]*invCDiff;
                w1 = +C[pos[0]]*invCDiff;
				intp[i] = w0*tetra.GetVertex(pos[0]) + w1*tetra.GetVertex(neg[i]);
            }

            tetra.SetVertex(pos[0], intp[0]);
            inside.push_back(tetra);

            inside.push_back(Tetrahedron3(intp[1], tetra.GetVertex(zer[0]), tetra.GetVertex(neg[1]), intp[0]));
        }
        else
        {
            // +-00
            invCDiff = ((Real)1)/(C[pos[0]] - C[neg[0]]);
            w0 = -C[neg[0]]*invCDiff;
            w1 = +C[pos[0]]*invCDiff;
			tetra.SetVertex(pos[0], w0*tetra.GetVertex(pos[0]) + w1*tetra.GetVertex(neg[0]));
            inside.push_back(tetra);
        }
    }
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRAHEDRON3_TETRAHEDRON3_DETAIL_H