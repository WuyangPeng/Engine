// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:53)

#ifndef MATHEMATICS_INTERSECTION_FIND_CONTACT_SET_DETAIL_H
#define MATHEMATICS_INTERSECTION_FIND_CONTACT_SET_DETAIL_H

#include "FindContactSet.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_FIND_CONTACT_SET_DETAIL)

#include "IntersectorConfigurationDetail.h"
#include "IntersectorUtility3Detail.h"
#include "Mathematics/Objects3D/Box3Detail.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Objects3D/Triangle3Detail.h" 

// FindContactSet<Real>

template <typename Real>
Mathematics::FindContactSet<Real>
	::FindContactSet(const Vector3D<Real> segment[2], const Triangle3<Real>& triangle, int side, const IntersectorConfiguration<Real>& segCfg, const IntersectorConfiguration<Real>& triCfg,
					 const Vector3D<Real>& segVelocity, const Vector3D<Real>& triVelocity, Real tfirst, int& quantity, Vector3D<Real>* P)
{
	// Move the segment to its new position.
	Vector3D<Real> segFinal[2]{ segment[0] + tfirst * segVelocity, segment[1] + tfirst * segVelocity };

	// Move the triangle to its new position.
	Vector3D<Real> triFinal[3]{ triangle.GetVertex(0) + tfirst * triVelocity,
								 triangle.GetVertex(1) + tfirst * triVelocity,
								 triangle.GetVertex(2) + tfirst * triVelocity };

	const int* sIndex = segCfg.mIndex;
	const int* tIndex = triCfg.mIndex;

	if (side == IntersectorConfiguration<Real>::LEFT) // tri on left of seg
	{
		if (segCfg.mMap == IntersectorConfiguration<Real>::m11)
		{
			quantity = 1;
			P[0] = segFinal[sIndex[0]];
		}
		else if (triCfg.mMap == IntersectorConfiguration<Real>::m111 || triCfg.mMap == IntersectorConfiguration<Real>::m21)
		{
			quantity = 1;
			P[0] = triFinal[tIndex[2]];
		}
		else if (triCfg.mMap == IntersectorConfiguration<Real>::m12)
		{
			Vector3D<Real> temp[2];
			temp[0] = triFinal[tIndex[1]];
			temp[1] = triFinal[tIndex[2]];
			SegmentSegment(segFinal, temp, quantity, P);
		}
		else // seg is m2, tri is m3
		{
			ColinearSegmentTriangle(segFinal, triFinal, quantity, P);
		}
	}
	else // seg on left of tri
	{
		if (segCfg.mMap == IntersectorConfiguration<Real>::m11)
		{
			quantity = 1;
			P[0] = segFinal[sIndex[1]];
		}
		else if (triCfg.mMap == IntersectorConfiguration<Real>::m111 || triCfg.mMap == IntersectorConfiguration<Real>::m12)
		{
			quantity = 1;
			P[0] = triFinal[tIndex[0]];
		}
		else if (triCfg.mMap == IntersectorConfiguration<Real>::m21)
		{
			Vector3D<Real> temp[2];
			temp[0] = triFinal[tIndex[0]];
			temp[1] = triFinal[tIndex[1]];
			SegmentSegment(segFinal, temp, quantity, P);
		}
		else // seg is m2, tri is m3
		{
			ColinearSegmentTriangle(segFinal, triFinal, quantity, P);
		}
	}
}

template <typename Real>
Mathematics::FindContactSet<Real>
	::FindContactSet(const Vector3D<Real> segment[2], const Box3<Real>& box, int side, const IntersectorConfiguration<Real>& segCfg, const IntersectorConfiguration<Real>& boxCfg,
					 const Vector3D<Real>& segVelocity, const Vector3D<Real>& boxVelocity, Real tfirst, int& quantity, Vector3D<Real>* P)
{
	// Move the segment to its new position.
	Vector3D<Real> segFinal[2]{ segment[0] + tfirst * segVelocity,segment[1] + tfirst * segVelocity };

	// Move the box to its new position.
	auto boxFinal = box.GetMove(tfirst, boxVelocity);

	const int* sIndex = segCfg.mIndex;
	const int* bIndex = boxCfg.mIndex;

	if (side == IntersectorConfiguration<Real>::LEFT)
	{
		// box on left of seg
		if (segCfg.mMap == IntersectorConfiguration<Real>::m11)
		{
			quantity = 1;
			P[0] = segFinal[sIndex[0]];
		}
		else if (boxCfg.mMap == IntersectorConfiguration<Real>::m1_1)
		{
			quantity = 1;
			P[0] = GetPointFromIndex(bIndex[7], boxFinal);
		}
		else if (boxCfg.mMap == IntersectorConfiguration<Real>::m2_2)
		{
			// segment-segment intersection
			Vector3D<Real> boxSeg[2];
			boxSeg[0] = GetPointFromIndex(bIndex[6], boxFinal);
			boxSeg[1] = GetPointFromIndex(bIndex[7], boxFinal);
			SegmentSegment(segFinal, boxSeg, quantity, P);
		}
		else // boxCfg.mMap == IntersectorConfiguration<Real>::m44
		{
			// segment-boxface intersection
			Vector3D<Real> boxFace[4];
			boxFace[0] = GetPointFromIndex(bIndex[4], boxFinal);
			boxFace[1] = GetPointFromIndex(bIndex[5], boxFinal);
			boxFace[2] = GetPointFromIndex(bIndex[6], boxFinal);
			boxFace[3] = GetPointFromIndex(bIndex[7], boxFinal);
			CoplanarSegmentRectangle(segFinal, boxFace, quantity, P);
		}
	}
	else // side == RIGHT 
	{
		// box on right of seg
		if (segCfg.mMap == IntersectorConfiguration<Real>::m11)
		{
			quantity = 1;
			P[0] = segFinal[sIndex[1]];
		}
		else if (boxCfg.mMap == IntersectorConfiguration<Real>::m1_1)
		{
			quantity = 1;
			P[0] = GetPointFromIndex(bIndex[0], boxFinal);
		}
		else if (boxCfg.mMap == IntersectorConfiguration<Real>::m2_2)
		{
			// segment-segment intersection
			Vector3D<Real> boxSeg[2];
			boxSeg[0] = GetPointFromIndex(bIndex[0], boxFinal);
			boxSeg[1] = GetPointFromIndex(bIndex[1], boxFinal);
			SegmentSegment(segFinal, boxSeg, quantity, P);
		}
		else // boxCfg.mMap == IntersectorConfiguration<Real>::m44
		{
			// segment-boxface intersection
			Vector3D<Real> boxFace[4];
			boxFace[0] = GetPointFromIndex(bIndex[0], boxFinal);
			boxFace[1] = GetPointFromIndex(bIndex[1], boxFinal);
			boxFace[2] = GetPointFromIndex(bIndex[2], boxFinal);
			boxFace[3] = GetPointFromIndex(bIndex[3], boxFinal);
			CoplanarSegmentRectangle(segFinal, boxFace, quantity, P);
		}
	}
}

template <typename Real>
Mathematics::FindContactSet<Real>
	::FindContactSet(const Triangle3<Real>& triangle, const Box3<Real>& box, int side, const IntersectorConfiguration<Real>& triCfg, const IntersectorConfiguration<Real>& boxCfg,
					 const Vector3D<Real>& triVelocity, const Vector3D<Real>& boxVelocity, Real tfirst, int& quantity, Vector3D<Real>* P)
{
	// Move the triangle to its new position.
	Vector3D<Real> triFinal[3]{ triangle.GetVertex(0) + tfirst * triVelocity,triangle.GetVertex(1) + tfirst * triVelocity,triangle.GetVertex(2) + tfirst * triVelocity };

	// Move the box to new its position.
	auto boxFinal = box.GetMove(tfirst, boxVelocity);

	const int* tIndex = triCfg.mIndex;
	const int* bIndex = boxCfg.mIndex;

	if (side == IntersectorConfiguration<Real>::LEFT)
	{
		// box on left of tri
		if (triCfg.mMap == IntersectorConfiguration<Real>::m111 || triCfg.mMap == IntersectorConfiguration<Real>::m12)
		{
			quantity = 1;
			P[0] = triFinal[tIndex[0]];
		}
		else if (boxCfg.mMap == IntersectorConfiguration<Real>::m1_1)
		{
			quantity = 1;
			P[0] = GetPointFromIndex(bIndex[7], boxFinal);
		}
		else if (triCfg.mMap == IntersectorConfiguration<Real>::m21)
		{
			if (boxCfg.mMap == IntersectorConfiguration<Real>::m2_2)
			{
				// triseg-boxseg intersection
				Vector3D<Real> triSeg[2], boxSeg[2];
				triSeg[0] = triFinal[tIndex[0]];
				triSeg[1] = triFinal[tIndex[1]];
				boxSeg[0] = GetPointFromIndex(bIndex[6], boxFinal);
				boxSeg[1] = GetPointFromIndex(bIndex[7], boxFinal);
				SegmentSegment(triSeg, boxSeg, quantity, P);
			}
			else // boxCfg.mMap == IntersectorConfiguration<Real>::m44
			{
				// triseg-boxface intersection
				Vector3D<Real> triSeg[2], boxFace[4];
				triSeg[0] = triFinal[tIndex[0]];
				triSeg[1] = triFinal[tIndex[1]];
				boxFace[0] = GetPointFromIndex(bIndex[4], boxFinal);
				boxFace[1] = GetPointFromIndex(bIndex[5], boxFinal);
				boxFace[2] = GetPointFromIndex(bIndex[6], boxFinal);
				boxFace[3] = GetPointFromIndex(bIndex[7], boxFinal);
				CoplanarSegmentRectangle(triSeg, boxFace, quantity, P);
			}
		}
		else // triCfg.mMap == IntersectorConfiguration<Real>::m3
		{
			if (boxCfg.mMap == IntersectorConfiguration<Real>::m2_2)
			{
				// boxseg-triface intersection
				Vector3D<Real> boxSeg[2];
				boxSeg[0] = GetPointFromIndex(bIndex[6], boxFinal);
				boxSeg[1] = GetPointFromIndex(bIndex[7], boxFinal);
				ColinearSegmentTriangle(boxSeg, triFinal, quantity, P);
			}
			else
			{
				// triface-boxface intersection
				Vector3D<Real> boxFace[4];
				boxFace[0] = GetPointFromIndex(bIndex[4], boxFinal);
				boxFace[1] = GetPointFromIndex(bIndex[5], boxFinal);
				boxFace[2] = GetPointFromIndex(bIndex[6], boxFinal);
				boxFace[3] = GetPointFromIndex(bIndex[7], boxFinal);
				CoplanarTriangleRectangle(triFinal, boxFace, quantity, P);
			}
		}
	}
	else // side == RIGHT 
	{
		// box on right of tri
		if (triCfg.mMap == IntersectorConfiguration<Real>::m111 || triCfg.mMap == IntersectorConfiguration<Real>::m21)
		{
			quantity = 1;
			P[0] = triFinal[tIndex[2]];
		}
		else if (boxCfg.mMap == IntersectorConfiguration<Real>::m1_1)
		{
			quantity = 1;
			P[0] = GetPointFromIndex(bIndex[0], boxFinal);
		}
		else if (triCfg.mMap == IntersectorConfiguration<Real>::m12)
		{
			if (boxCfg.mMap == IntersectorConfiguration<Real>::m2_2)
			{
				// segment-segment intersection
				Vector3D<Real> triSeg[2], boxSeg[2];
				triSeg[0] = triFinal[tIndex[1]];
				triSeg[1] = triFinal[tIndex[2]];
				boxSeg[0] = GetPointFromIndex(bIndex[0], boxFinal);
				boxSeg[1] = GetPointFromIndex(bIndex[1], boxFinal);
				SegmentSegment(triSeg, boxSeg, quantity, P);
			}
			else // boxCfg.mMap == IntersectorConfiguration<Real>::m44
			{
				// triseg-boxface intersection
				Vector3D<Real> triSeg[2], boxFace[4];
				triSeg[0] = triFinal[tIndex[1]];
				triSeg[1] = triFinal[tIndex[2]];
				boxFace[0] = GetPointFromIndex(bIndex[0], boxFinal);
				boxFace[1] = GetPointFromIndex(bIndex[1], boxFinal);
				boxFace[2] = GetPointFromIndex(bIndex[2], boxFinal);
				CoplanarSegmentRectangle(triSeg, boxFace, quantity, P);
			}
		}
		else // triCfg.mMap == IntersectorConfiguration<Real>::m3
		{
			if (boxCfg.mMap == IntersectorConfiguration<Real>::m2_2)
			{
				// boxseg-triface intersection
				Vector3D<Real> boxSeg[2];
				boxSeg[0] = GetPointFromIndex(bIndex[0], boxFinal);
				boxSeg[1] = GetPointFromIndex(bIndex[1], boxFinal);
				ColinearSegmentTriangle(boxSeg, triFinal, quantity, P);
			}
			else
			{
				// triface-boxface intersection
				Vector3D<Real> boxFace[4];
				boxFace[0] = GetPointFromIndex(bIndex[0], boxFinal);
				boxFace[1] = GetPointFromIndex(bIndex[1], boxFinal);
				boxFace[2] = GetPointFromIndex(bIndex[2], boxFinal);
				boxFace[3] = GetPointFromIndex(bIndex[3], boxFinal);
				CoplanarTriangleRectangle(triFinal, boxFace, quantity, P);
			}
		}
	}
}

template <typename Real>
Mathematics::FindContactSet<Real>
	::FindContactSet(const Box3<Real>& box0, const Box3<Real>& box1, int side, const IntersectorConfiguration<Real>& box0Cfg, const IntersectorConfiguration<Real>& box1Cfg,
					 const Vector3D<Real>& box0Velocity, const Vector3D<Real>& box1Velocity, Real tfirst, int& quantity, Vector3D<Real>* P)
{
	// Move the boxes to their new positions.
	Box3<Real> box0Final{ box0.GetCenter() + tfirst * box0Velocity,box0.GetFirstAxis(),box0.GetSecondAxis(),box0.GetThirdAxis(),box0.GetFirstExtent(),box0.GetSecondExtent(),box0.GetThirdExtent() };
	Box3<Real> box1Final{ box1.GetCenter() + tfirst * box1Velocity,box1.GetFirstAxis(),box1.GetSecondAxis(),box1.GetThirdAxis(),box1.GetFirstExtent(),box1.GetSecondExtent(),box1.GetThirdExtent() };

	const int* b0Index = box0Cfg.mIndex;
	const int* b1Index = box1Cfg.mIndex;

	if (side == IntersectorConfiguration<Real>::LEFT)
	{
		// box1 on left of box0
		if (box0Cfg.mMap == IntersectorConfiguration<Real>::m1_1)
		{
			quantity = 1;
			P[0] = GetPointFromIndex(b0Index[0], box0Final);
		}
		else if (box1Cfg.mMap == IntersectorConfiguration<Real>::m1_1)
		{
			quantity = 1;
			P[0] = GetPointFromIndex(b1Index[7], box1Final);
		}
		else if (box0Cfg.mMap == IntersectorConfiguration<Real>::m2_2)
		{
			if (box1Cfg.mMap == IntersectorConfiguration<Real>::m2_2)
			{
				// box0edge-box1edge intersection
				Vector3D<Real> edge0[2], edge1[2];
				edge0[0] = GetPointFromIndex(b0Index[0], box0Final);
				edge0[1] = GetPointFromIndex(b0Index[1], box0Final);
				edge1[0] = GetPointFromIndex(b1Index[6], box1Final);
				edge1[1] = GetPointFromIndex(b1Index[7], box1Final);
				SegmentSegment(edge0, edge1, quantity, P);
			}
			else // box1Cfg.mMap == IntersectorConfiguration<Real>::m44
			{
				// box0edge-box1face intersection
				Vector3D<Real> edge0[2], face1[4];
				edge0[0] = GetPointFromIndex(b0Index[0], box0Final);
				edge0[1] = GetPointFromIndex(b0Index[1], box0Final);
				face1[0] = GetPointFromIndex(b1Index[4], box1Final);
				face1[1] = GetPointFromIndex(b1Index[5], box1Final);
				face1[2] = GetPointFromIndex(b1Index[6], box1Final);
				face1[3] = GetPointFromIndex(b1Index[7], box1Final);
				CoplanarSegmentRectangle(edge0, face1, quantity, P);
			}
		}
		else // box0Cfg.mMap == IntersectorConfiguration<Real>::m44
		{
			if (box1Cfg.mMap == IntersectorConfiguration<Real>::m2_2)
			{
				// box0face-box1edge intersection
				Vector3D<Real> face0[4], edge1[2];
				face0[0] = GetPointFromIndex(b0Index[0], box0Final);
				face0[1] = GetPointFromIndex(b0Index[1], box0Final);
				face0[2] = GetPointFromIndex(b0Index[2], box0Final);
				face0[3] = GetPointFromIndex(b0Index[3], box0Final);
				edge1[0] = GetPointFromIndex(b1Index[6], box1Final);
				edge1[1] = GetPointFromIndex(b1Index[7], box1Final);
				CoplanarSegmentRectangle(edge1, face0, quantity, P);
			}
			else
			{
				// box0face-box1face intersection
				Vector3D<Real> face0[4], face1[4];
				face0[0] = GetPointFromIndex(b0Index[0], box0Final);
				face0[1] = GetPointFromIndex(b0Index[1], box0Final);
				face0[2] = GetPointFromIndex(b0Index[2], box0Final);
				face0[3] = GetPointFromIndex(b0Index[3], box0Final);
				face1[0] = GetPointFromIndex(b1Index[4], box1Final);
				face1[1] = GetPointFromIndex(b1Index[5], box1Final);
				face1[2] = GetPointFromIndex(b1Index[6], box1Final);
				face1[3] = GetPointFromIndex(b1Index[7], box1Final);
				CoplanarRectangleRectangle(face0, face1, quantity, P);
			}
		}
	}
	else // side == RIGHT 
	{
		// box1 on right of box0
		if (box0Cfg.mMap == IntersectorConfiguration<Real>::m1_1)
		{
			quantity = 1;
			P[0] = GetPointFromIndex(b0Index[7], box0Final);
		}
		else if (box1Cfg.mMap == IntersectorConfiguration<Real>::m1_1)
		{
			quantity = 1;
			P[0] = GetPointFromIndex(b1Index[0], box1Final);
		}
		else if (box0Cfg.mMap == IntersectorConfiguration<Real>::m2_2)
		{
			if (box1Cfg.mMap == IntersectorConfiguration<Real>::m2_2)
			{
				// box0edge-box1edge intersection
				Vector3D<Real> edge0[2], edge1[2];
				edge0[0] = GetPointFromIndex(b0Index[6], box0Final);
				edge0[1] = GetPointFromIndex(b0Index[7], box0Final);
				edge1[0] = GetPointFromIndex(b1Index[0], box1Final);
				edge1[1] = GetPointFromIndex(b1Index[1], box1Final);
				SegmentSegment(edge0, edge1, quantity, P);
			}
			else // box1Cfg.mMap == IntersectorConfiguration<Real>::m44
			{
				// box0edge-box1face intersection
				Vector3D<Real> edge0[2], face1[4];
				edge0[0] = GetPointFromIndex(b0Index[6], box0Final);
				edge0[1] = GetPointFromIndex(b0Index[7], box0Final);
				face1[0] = GetPointFromIndex(b1Index[0], box1Final);
				face1[1] = GetPointFromIndex(b1Index[1], box1Final);
				face1[2] = GetPointFromIndex(b1Index[2], box1Final);
				face1[3] = GetPointFromIndex(b1Index[3], box1Final);
				CoplanarSegmentRectangle(edge0, face1, quantity, P);
			}
		}
		else // box0Cfg.mMap == IntersectorConfiguration<Real>::m44
		{
			if (box1Cfg.mMap == IntersectorConfiguration<Real>::m2_2)
			{
				// box0face-box1edge intersection
				Vector3D<Real> face0[4], edge1[2];
				face0[0] = GetPointFromIndex(b0Index[4], box0Final);
				face0[1] = GetPointFromIndex(b0Index[5], box0Final);
				face0[2] = GetPointFromIndex(b0Index[6], box0Final);
				face0[3] = GetPointFromIndex(b0Index[7], box0Final);
				edge1[0] = GetPointFromIndex(b1Index[0], box1Final);
				edge1[1] = GetPointFromIndex(b1Index[1], box1Final);
				CoplanarSegmentRectangle(edge1, face0, quantity, P);
			}
			else // box1Cfg.mMap == IntersectorConfiguration<Real>::m44
			{
				// box0face-box1face intersection
				Vector3D<Real> face0[4], face1[4];
				face0[0] = GetPointFromIndex(b0Index[4], box0Final);
				face0[1] = GetPointFromIndex(b0Index[5], box0Final);
				face0[2] = GetPointFromIndex(b0Index[6], box0Final);
				face0[3] = GetPointFromIndex(b0Index[7], box0Final);
				face1[0] = GetPointFromIndex(b1Index[0], box1Final);
				face1[1] = GetPointFromIndex(b1Index[1], box1Final);
				face1[2] = GetPointFromIndex(b1Index[2], box1Final);
				face1[3] = GetPointFromIndex(b1Index[3], box1Final);
				CoplanarRectangleRectangle(face0, face1, quantity, P);
			}
		}
	}
}

template <typename Real>
void Mathematics::FindContactSet<Real>
	::ColinearSegments(const Vector3D<Real> segment0[2], const Vector3D<Real> segment1[2], int& quantity, Vector3D<Real>* P)
{
	// The potential intersection is initialized to segment0 and clipped
	// against segment1.
	quantity = 2;
	for (auto i = 0; i < 2; ++i)
	{
		P[i] = segment0[i];
	}

	// point 0
	auto V = segment1[1] - segment1[0];
	auto c = Vector3DTools<Real>::DotProduct(V, segment1[0]);
	ClipConvexPolygonAgainstPlane(V, c, quantity, P);

	// point 1
	V = -V;
	c = Vector3DTools<Real>::DotProduct(V, segment1[1]);
	ClipConvexPolygonAgainstPlane(V, c, quantity, P);
}

template <typename Real>
void Mathematics::FindContactSet<Real>
	::SegmentThroughPlane(const Vector3D<Real> segment[2], const Vector3D<Real>& planeOrigin, const Vector3D<Real>& planeNormal, int& quantity, Vector3D<Real>* P)
{
	quantity = 1;

	auto u = Vector3DTools<Real>::DotProduct(planeNormal, planeOrigin);
	auto v0 = Vector3DTools<Real>::DotProduct(planeNormal, segment[0]);
	auto v1 = Vector3DTools<Real>::DotProduct(planeNormal, segment[1]);

	// Now that there it has been reduced to a 1-dimensional problem via
	// projection, it becomes easy to find the ratio along V that V 
	// intersects with U.
	auto ratio = (u - v0) / (v1 - v0);
	P[0] = segment[0] + ratio * (segment[1] - segment[0]);
}

template <typename Real>
void Mathematics::FindContactSet<Real>
	::SegmentSegment(const Vector3D<Real> segment0[2], const Vector3D<Real> segment1[2], int& quantity, Vector3D<Real>* P)
{
	auto dir0 = segment0[1] - segment0[0];
	auto dir1 = segment1[1] - segment1[0];
	auto normal = Vector3DTools<Real>::CrossProduct(dir0, dir1);

	// The comparison is sin(kDir0,kDir1) < epsilon.
	auto sqrLen0 = Vector3DTools<Real>::VectorMagnitudeSquared(dir0);
	auto sqrLen1 = Vector3DTools<Real>::VectorMagnitudeSquared(dir1);
	auto sqrLenN = Vector3DTools<Real>::VectorMagnitudeSquared(normal);
	if (sqrLenN < Math<Real>::sm_ZeroTolerance*sqrLen0*sqrLen1)
	{
		ColinearSegments(segment0, segment1, quantity, P);
	}
	else
	{
		SegmentThroughPlane(segment1, segment0[0], Vector3DTools<Real>::CrossProduct(normal, segment0[1] - segment0[0]), quantity, P);
	}
}

template <typename Real>
void Mathematics::FindContactSet<Real>
	::ColinearSegmentTriangle(const Vector3D<Real> segment[2], const Vector3D<Real> triangle[3], int& quantity, Vector3D<Real>* P)
{
	// The potential intersection is initialized to the line segment and then
	// clipped against the three sides of the tri
	quantity = 2;
	int i;
	for (i = 0; i < 2; ++i)
	{
		P[i] = segment[i];
	}

	Vector3D<Real> side[3]{ triangle[1] - triangle[0], triangle[2] - triangle[1], triangle[0] - triangle[2] };

	auto normal = Vector3DTools<Real>::CrossProduct(side[0], side[1]);
	for (i = 0; i < 3; ++i)
	{
		// Normal pointing inside the triangle.
		auto sideN = Vector3DTools<Real>::CrossProduct(normal, side[i]);
		auto constant = Vector3DTools<Real>::DotProduct(sideN, triangle[i]);
		ClipConvexPolygonAgainstPlane(sideN, constant, quantity, P);
	}
}

template <typename Real>
void Mathematics::FindContactSet<Real>
	::CoplanarSegmentRectangle(const Vector3D<Real> segment[2], const Vector3D<Real> rectangle[4], int& quantity, Vector3D<Real>* P)
{
	// The potential intersection is initialized to the line segment and then
	// clipped against the four sides of the rect
	quantity = 2;
	for (auto i = 0; i < 2; ++i)
	{
		P[i] = segment[i];
	}

	for (auto i0 = 3, i1 = 0; i1 < 4; i0 = i1++)
	{
		auto normal = rectangle[i1] - rectangle[i0];
		auto constant = Vector3DTools<Real>::DotProduct(normal, rectangle[i0]);
		ClipConvexPolygonAgainstPlane(normal, constant, quantity, P);
	}
}

template <typename Real>
void Mathematics::FindContactSet<Real>
	::CoplanarTriangleRectangle(const Vector3D<Real> triangle[3], const Vector3D<Real> rectangle[4], int& quantity, Vector3D<Real>* P)
{
	// The potential intersection is initialized to the triangle, and then
	// clipped against the sides of the box
	quantity = 3;
	for (auto i = 0; i < 3; ++i)
	{
		P[i] = triangle[i];
	}

	for (auto i0 = 3, i1 = 0; i1 < 4; i0 = i1++)
	{
		auto normal = rectangle[i1] - rectangle[i0];
		auto constant = Vector3DTools<Real>::DotProduct(normal, rectangle[i0]);
		ClipConvexPolygonAgainstPlane(normal, constant, quantity, P);
	}
}

template <typename Real>
void Mathematics::FindContactSet<Real>
	::CoplanarRectangleRectangle(const Vector3D<Real> rectangle0[4], const Vector3D<Real> rectangle1[4], int& quantity, Vector3D<Real>* P)
{
	// The potential intersection is initialized to face 0, and then clipped
	// against the four sides of face 1.
	quantity = 4;
	for (auto i = 0; i < 4; ++i)
	{
		P[i] = rectangle0[i];
	}

	for (auto i0 = 3, i1 = 0; i1 < 4; i0 = i1++)
	{
		auto normal = rectangle1[i1] - rectangle1[i0];
		auto constant = Vector3DTools<Real>::DotProduct(normal, rectangle1[i0]);
		ClipConvexPolygonAgainstPlane(normal, constant, quantity, P);
	}
}
#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_FIND_CONTACT_SET_DETAIL)

#endif // MATHEMATICS_INTERSECTION_FIND_CONTACT_SET_DETAIL_H
