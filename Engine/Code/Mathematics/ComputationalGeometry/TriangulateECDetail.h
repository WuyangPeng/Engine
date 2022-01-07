// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 15:06)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_TRIANGULATE_EC_DETAIL_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_TRIANGULATE_EC_DETAIL_H

#include "TriangulateEC.h"
#include "Mathematics/Query/Query2Filtered.h"
#include "Mathematics/Query/Query2Int64.h"
#include "Mathematics/Query/Query2Integer.h"
#include "Mathematics/Query/Query2Rational.h"  

#include <queue>

template <typename Real>
Mathematics::TriangulateEC<Real>
	::TriangulateEC (const Positions& positions, QueryType queryType, Real epsilon, Indices& triangles)
{
    // No extra elements are needed for triangulating a simple polygon.
    InitializePositions(positions, queryType, epsilon, 0);

    // Triangulate the unindexed polygon.
    auto numVertices = boost::numeric_cast<int>(positions.size());
    const auto* indices = 0;
    InitializeVertices(numVertices, indices);
    DoEarClipping(numVertices, indices, triangles);
}

template <typename Real>
Mathematics::TriangulateEC<Real>
	::TriangulateEC (const Positions& positions, QueryType queryType, Real epsilon, const Indices& polygon, Indices& triangles)
{
    // No extra elements are needed for triangulating a simple polygon.
    InitializePositions(positions, queryType, epsilon, 0);

    // Triangulate the indexed polygon.
	auto numVertices = boost::numeric_cast<int>(positions.size());
    const auto* indices = &polygon[0];
    InitializeVertices(numVertices, indices);
    DoEarClipping(numVertices, indices, triangles);
}

template <typename Real>
Mathematics::TriangulateEC<Real>
	::TriangulateEC (const Positions& positions,QueryType queryType, Real epsilon, const Indices& outer,const Indices& inner, Indices& triangles)
{
    // Two extra elements are needed to duplicate the endpoints of the edge
    // introduced to combine outer and inner polygons.
    InitializePositions(positions, queryType, epsilon, 2);

    // Combine the outer polygon and the inner polygon into a simple polygon
    // by inserting two edges connecting mutually visible vertices, one from
    // the outer polygon and one from the inner polygon.
    int nextElement = (int)positions.size();  // next available element
    IndexMap indexMap;
    Indices combined;
    CombinePolygons(queryType, epsilon, nextElement, outer, inner, indexMap,combined);

    // The combined polygon is now in the format of a simple polygon, albeit
    // one with coincident edges.
	auto numVertices = boost::numeric_cast<int>(positions.size());
    const auto* indices = &combined[0];
    InitializeVertices(numVertices, indices);
    DoEarClipping(numVertices, indices, triangles);

    // Map the duplicate indices back to the original indices.
    RemapIndices(indexMap, triangles);
}

template <typename Real>
Mathematics::TriangulateEC<Real>
	::TriangulateEC (const Positions& positions, QueryType queryType, Real epsilon, const Indices& outer,const IndicesArray& inners, Indices& triangles)
{
    // Two extra elements per inner polygon are needed to duplicate the
    // endpoints of the edges introduced to combine outer and inner polygons.
	auto numInners = boost::numeric_cast<int>(inners.size());
	auto extraElements = 2*numInners;
    InitializePositions(positions, queryType, epsilon, extraElements);

    // Combine the outer polygon and the inner polygons into a simple polygon
    // by inserting two edges per inner polygon connecting mutually visible
    // vertices.
	auto nextElement = boost::numeric_cast<int>(positions.size());
    IndexMap indexMap;
    Indices combined;
    ProcessOuterAndInners(queryType, epsilon, outer, inners, nextElement, indexMap, combined);

    // The combined polygon is now in the format of a simple polygon, albeit
    // with coincident edges.
	auto numVertices = boost::numeric_cast<int>(combined.size());
    const int* indices = &combined[0];
    InitializeVertices(numVertices, indices);
    DoEarClipping(numVertices, indices, triangles);

    // Map the duplicate indices back to the original indices.
    RemapIndices(indexMap, triangles);
}

template <typename Real>
Mathematics::TriangulateEC<Real>
	::TriangulateEC (const Positions& positions,QueryType queryType, Real epsilon, const Tree* tree, Indices& triangles)
{
    // Two extra elements per inner polygon are needed to duplicate the
    // endpoints of the edges introduced to combine outer and inner polygons.
	auto extraElements = GetExtraElements(tree);
    InitializePositions(positions, queryType, epsilon, extraElements);

	auto nextElement = boost::numeric_cast<int>(positions.size());
    IndexMap indexMap;

    std::queue<const Tree*> treeQueue;
    treeQueue.push(tree);
    while (treeQueue.size() > 0)
    {
        const auto* outerNode = treeQueue.front();
        treeQueue.pop();

		auto numChildren = boost::numeric_cast<int>(outerNode->Child.size());
        int numVertices;
        const int* indices;

        if (numChildren == 0)
        {
            // The outer polygon is a simple polygon (no nested inner
            // polygons).  Triangulate the simple polygon.
            numVertices = (int)outerNode->Polygon.size();
            indices = &outerNode->Polygon[0];
            InitializeVertices(numVertices, indices);
            DoEarClipping(numVertices, indices, triangles);
        }
        else
        {
            // Place the next level of outer polygon nodes on the queue for
            // triangulation.
            std::vector<std::vector<int>*> inners(numChildren);
            for (auto i = 0; i < numChildren; ++i)
            {
                const Tree* innerNode = outerNode->Child[i];
                inners[i] = (std::vector<int>*)&innerNode->Polygon;
                int numGrandChildren = (int)innerNode->Child.size();
                for (auto j = 0; j < numGrandChildren; ++j)
                {
                    treeQueue.push(innerNode->Child[j]);
                }
            }

            // Combine the outer polygon and the inner polygons into a
            // simple polygon by inserting two edges per inner polygon
            // connecting mutually visible vertices.
            Indices combined;
            ProcessOuterAndInners(queryType, epsilon, outerNode->Polygon, inners, nextElement, indexMap, combined);

            // The combined polygon is now in the format of a simple polygon,
            // albeit with coincident edges.
            numVertices = boost::numeric_cast<int>(combined.size());
            indices = &combined[0];
            InitializeVertices(numVertices, indices);
            DoEarClipping(numVertices, indices, triangles);
        }
    }

    // Map the duplicate indices back to the original indices.
    RemapIndices(indexMap, triangles);
}

template <typename Real>
Mathematics::TriangulateEC<Real>
	::~TriangulateEC ()
{
    DELETE0(mQuery);
}

template <typename Real>
void Mathematics::TriangulateEC<Real>
	::InitializePositions (const Positions& positions, QueryType queryType, Real epsilon, int extraElements)
{
    auto numPositions = boost::numeric_cast<int>(positions.size());
    MATHEMATICS_ASSERTION_0(numPositions >= 3, "Must have at least one triangle\n");
	auto numPosExtras = numPositions + extraElements;
    mSPositions.resize(numPosExtras);

    if (queryType == QueryType::Filtered)
    {
        MATHEMATICS_ASSERTION_0(Math<Real>::GetValue(0) <= epsilon && epsilon <= Math::GetValue(1),"Epsilon must be in [0,1]\n");
    }

    Vector2D<Real> minValue, maxValue, range;
    Real scale, rmax;
    int i;

    switch (queryType)
    {
    case QueryType::Int64:
    {
        // Transform the vertices to the square [0,2^{20}]^2.
		auto aabb = Vector2DTools<Real>::ComputeExtremes(positions);
		minValue = aabb.GetMinPoint();
		maxValue = aabb.GetMaxPoint();
      
        range = maxValue - minValue;
        rmax = (range[0] >= range[1] ? range[0] : range[1]);
        scale = ((Real)(1 << 20))/rmax;
        for (i = 0; i < numPositions; ++i)
        {
            mSPositions[i] = (positions[i] - minValue)*scale;
        }

      //  mQuery = NEW0 Query2Int64<Real>(mSPositions);
        return;
    }

    case QueryType::Interger:
    {
        // Transform the vertices to the square [0,2^{24}]^2.
		auto aabb = Vector2DTools<Real>::ComputeExtremes(positions);
		minValue = aabb.GetMinPoint();
		maxValue = aabb.GetMaxPoint();
        range = maxValue - minValue;
        rmax = (range[0] >= range[1] ? range[0] : range[1]);
        scale = ((Real)(1 << 24))/rmax;
        for (i = 0; i < numPositions; ++i)
        {
            mSPositions[i] = (positions[i] - minValue)*scale;
        }

     //   mQuery = NEW0 Query2Integer<Real>(mSPositions);
        return;
    }

    case QueryType::Real:
    {
        // No transformation of the input data.  Make a copy that can be
        // expanded when triangulating polygons with holes.
        for (i = 0; i < numPositions; ++i)
        {
            mSPositions[i] = positions[i];
        }

     //   mQuery = NEW0 Query2<Real>(mSPositions);
        return;
    }

    case QueryType::Rational:
    {
        // No transformation of the input data.  Make a copy that can be
        // expanded when triangulating polygons with holes.
        for (i = 0; i < numPositions; ++i)
        {
            mSPositions[i] = positions[i];
        }

     //   mQuery = NEW0 Query2Rational<Real>(mSPositions);
        return;
    }

    case QueryType::Filtered:
    {
        // No transformation of the input data.  Make a copy that can be
        // expanded when triangulating polygons with holes.
        for (i = 0; i < numPositions; ++i)
        {
            mSPositions[i] = positions[i];
        }

      //  mQuery = NEW0 Query2Filtered<Real>(mSPositions, epsilon);
        return;
    }
    }
}

template <typename Real>
void Mathematics::TriangulateEC<Real>
	::InitializeVertices (int numVertices, const int* indices)
{
    mVertices.clear();
    mVertices.resize(numVertices);
    mCFirst = -1;
    mCLast = -1;
    mRFirst = -1;
    mRLast = -1;
    mEFirst = -1;
    mELast = -1;

    // Create a circular list of the polygon vertices for dynamic removal of
    // vertices.
	auto numVerticesM1 = numVertices - 1;
    int i;
    for (i = 0; i <= numVerticesM1; ++i)
    {
        Vertex& vertex = V(i);
        vertex.Index = (indices ? indices[i] : i);
        vertex.VPrev = (i > 0 ? i-1 : numVerticesM1);
        vertex.VNext = (i < numVerticesM1 ? i+1 : 0);
    }

    // Create a circular list of the polygon vertices for dynamic removal of
    // vertices.  Keep track of two linear sublists, one for the convex
    // vertices and one for the reflex vertices.  This is an O(N) process
    // where N is the number of polygon vertices.
    for (i = 0; i <= numVerticesM1; ++i)
    {
        if (IsConvex(i))
        {
            InsertAfterC(i);
        }
        else
        {
            InsertAfterR(i);
        }
    }
}

template <typename Real>
void Mathematics::TriangulateEC<Real>
	::DoEarClipping (int numVertices, const int* indices, Indices& triangles)
{
    // If the polygon is convex, just create a triangle fan.
    int i;
    if (mRFirst == -1)
    {
        int numVerticesM1 = numVertices - 1;
        if (indices)
        {
            for (i = 1; i < numVerticesM1; ++i)
            {
                triangles.push_back(indices[0]);
                triangles.push_back(indices[i]);
                triangles.push_back(indices[i + 1]);
            }
        }
        else
        {
            for (i = 1; i < numVerticesM1; ++i)
            {
                triangles.push_back(0);
                triangles.push_back(i);
                triangles.push_back(i + 1);
            }
        }
        return;
    }

    // Identify the ears and build a circular list of them.  Let V0, V1, and
    // V2 be consecutive vertices forming a triangle T.  The vertex V1 is an
    // ear if no other vertices of the polygon lie inside T.  Although it is
    // enough to show that V1 is not an ear by finding at least one other
    // vertex inside T, it is sufficient to search only the reflex vertices.
    // This is an O(C*Real) process, where C is the number of convex vertices and
    // Real is the number of reflex vertices with N = C+Real.  The order is O(N^2),
    // for example when C = Real = N/2.
    for (i = mCFirst; i != -1; i = V(i).SNext)
    {
        if (IsEar(i))
        {
            InsertEndE(i);
        }
    }
    V(mEFirst).EPrev = mELast;
    V(mELast).ENext = mEFirst;

    // Remove the ears, one at a time.
	auto bRemoveAnEar = true;
    while (bRemoveAnEar)
    {
        // Add the triangle with the ear to the output list of triangles.
		auto iVPrev = V(mEFirst).VPrev;
		auto iVNext = V(mEFirst).VNext;
        triangles.push_back(V(iVPrev).Index);
        triangles.push_back(V(mEFirst).Index);
        triangles.push_back(V(iVNext).Index);

        // Remove the vertex corresponding to the ear.
        RemoveV(mEFirst);
        if (--numVertices == 3)
        {
            // Only one triangle remains, just remove the ear and copy it.
            mEFirst = RemoveE(mEFirst);
            iVPrev = V(mEFirst).VPrev;
            iVNext = V(mEFirst).VNext;
            triangles.push_back(V(iVPrev).Index);
            triangles.push_back(V(mEFirst).Index);
            triangles.push_back(V(iVNext).Index);
            bRemoveAnEar = false;
            continue;
        }

        // Removal of the ear can cause an adjacent vertex to become an ear
        // or to stop being an ear.
        Vertex& VPrev = V(iVPrev);
        if (VPrev.IsEar)
        {
            if (!IsEar(iVPrev))
            {
                RemoveE(iVPrev);
            }
        }
        else
        {
            bool wasReflex = !VPrev.IsConvex;
            if (IsConvex(iVPrev))
            {
                if (wasReflex)
                {
                    RemoveR(iVPrev);
                }

                if (IsEar(iVPrev))
                {
                    InsertBeforeE(iVPrev);
                }
            }
        }

		auto& VNext = V(iVNext);
        if (VNext.IsEar)
        {
            if (!IsEar(iVNext))
            {
                RemoveE(iVNext);
            }
        }
        else
        {
			auto wasReflex = !VNext.IsConvex;
            if (IsConvex(iVNext))
            {
                if (wasReflex)
                {
                    RemoveR(iVNext);
                }

                if (IsEar(iVNext))
                {
                    InsertAfterE(iVNext);
                }
            }
        }

        // Remove the ear.
        mEFirst = RemoveE(mEFirst);
    }
}

template <typename Real>
int Mathematics::TriangulateEC<Real>
	::TriangleQuery (const Vector2D<Real>& position, QueryType queryType, Real epsilon, const Vector2D<Real> triangle[3]) const
{
	std::vector<Vector2D<Real> > triangleVec;
	triangleVec.push_back(triangle[0]);
	triangleVec.push_back(triangle[1]);
	triangleVec.push_back(triangle[2]);

    switch (queryType)
    {
    case QueryType::Int64:
        return System::EnumCastUnderlying(Query2Int64<Real>(triangleVec).ToTriangle(position, 0, 1, 2));

    case QueryType::Interger:
        return System::EnumCastUnderlying(Query2Integer<Real>(triangleVec).ToTriangle(position, 0, 1, 2));

    case QueryType::Real:
        return System::EnumCastUnderlying(Query2<Real>(triangleVec).ToTriangle(position, 0, 1, 2));

    case QueryType::Rational:
        return System::EnumCastUnderlying(Query2Rational<Real>(triangleVec).ToTriangle(position, 0, 1, 2));

    case QueryType::Filtered:
        return System::EnumCastUnderlying(Query2Filtered<Real>(triangleVec,epsilon).ToTriangle(position, 0, 1, 2));
    }

    return 1;
}

template <typename Real>
void Mathematics::TriangulateEC<Real>
	::CombinePolygons (QueryType queryType, Real epsilon, int nextElement, const Indices& outer,
                       const Indices& inner, IndexMap& indexMap, Indices& combined)
{
	auto numOuterVertices = boost::numeric_cast<int>(outer.size());
	auto numInnerVertices = (int)inner.size();

    // Locate the inner-polygon vertex of maximum x-value, call this vertex M.
    Real xmax = mSPositions[inner[0]][0];
    int xmaxIndex = 0;
    int i;
    for (i = 1; i < numInnerVertices; ++i)
    {
        Real x = mSPositions[inner[i]][0];
        if (x > xmax)
        {
            xmax = x;
            xmaxIndex = i;
        }
    }
	auto M = mSPositions[inner[xmaxIndex]];

    // Find the edge whose intersection Intr with the ray M+t*(1,0) minimizes
    // the ray parameter t >= 0.
	Vector2D<Real> intr{ Math<Real>::sm_MaxReal, M[1] };
    int v0min = -1, v1min = -1, endMin = -1;
    int i0, i1;
	auto s = Math<Real>::sm_MaxReal;
	auto t = Math<Real>::sm_MaxReal;
    for (i0 = numOuterVertices - 1, i1 = 0; i1 < numOuterVertices; i0 = i1++)
    {
        // Only consider edges for which the first vertex is below (or on)
        // the ray and the second vertex is above (or on) the ray.
		auto diff0 = mSPositions[outer[i0]] - M;
        if (diff0[1] > Math<Real>::GetValue(0))
        {
            continue;
        }
		auto diff1 = mSPositions[outer[i1]] - M;
        if (diff1[1] < Math<Real>::GetValue(0))
        {
            continue;
        }

        // At this time, diff0.y <= 0 and diff1.y >= 0.
        int currentEndMin = -1;
        if (diff0[1] < Math<Real>::GetValue(0))
        {
            if (diff1[1] > Math<Real>::GetValue(0))
            {
                // The intersection of the edge and ray occurs at an interior
                // edge point.
                s = diff0[1]/(diff0[1] - diff1[1]);
                t = diff0[0] + s*(diff1[0] - diff0[0]);
            }
            else  // diff1.y == 0
            {
                // The vertex Outer[i1] is the intersection of the edge and
                // the ray.
                t = diff1[0];
                currentEndMin = i1;
            }
        }
        else  // diff0.y == 0
        {
            if (diff1[1] > Math<Real>::GetValue(0))
            {
                // The vertex Outer[i0] is the intersection of the edge and
                // the ray;
                t = diff0[0];
                currentEndMin = i0;
            }
            else  // diff1.y == 0
            {
                if (diff0[0] < diff1[0])
                {
                    t = diff0[0];
                    currentEndMin = i0;
                }
                else
                {
                    t = diff1[0];
                    currentEndMin = i1;
                }
            }
        }

        if (Math<Real>::GetValue(0) <= t && t < intr[0])
        {
            intr[0] = t;
            v0min = i0;
            v1min = i1;
            if (currentEndMin == -1)
            {
                // The current closest point is an edge-interior point.
                endMin = -1;
            }
            else
            {
                // The current closest point is a vertex.
                endMin = currentEndMin;
            }
        }
        else if (t == intr[0])
        {
            // The current closest point is a vertex shared by multiple edges;
            // thus, endMin and currentMin refer to the same point.
            MATHEMATICS_ASSERTION_0(endMin != -1 && currentEndMin != -1, "Unexpected condition\n");

            // We need to select the edge closest to M.  The previous closest
            // edge is <outer[v0min],outer[v1min]>.  The current candidate is
            // <outer[i0],outer[i1]>.
			auto shared = mSPositions[outer[i1]];
            
            // For the previous closest edge, endMin refers to a vertex of
            // the edge.  Get the index of the other vertex.
			auto other = (endMin == v0min ? v1min : v0min);

            // The new edge is closer if the other vertex of the old edge is
            // left-of the new edge.
            diff0 = mSPositions[outer[i0]] - shared;
            diff1 = mSPositions[outer[other]] - shared;
			auto dotperp = Vector2DTools<Real>::DotPerp(diff0,diff1);
            if (dotperp > Math<Real>::GetValue(0))
            {
                // The new edge is closer to M.
                v0min = i0;
                v1min = i1;
                endMin = currentEndMin;
            }
        }
    }

    // The intersection intr[0] stored only the t-value of the ray.  The
    // actual point is (mx,my)+t*(1,0), so intr[0] must be adjusted.
    intr[0] += M[0];

    int maxCosIndex;
    if (endMin == -1)
    {
        // If you reach this assert, there is a good chance that you have two
        // inner polygons that share a vertex or an edge.
        MATHEMATICS_ASSERTION_0(v0min >= 0 && v1min >= 0, "Unexpected condition\n");

        // Select one of Outer[v0min] and Outer[v1min] that has an x-value
        // larger than M.x, call this vertex P.  The triangle <M,I,P> must
        // contain an outer-polygon vertex that is visible to M, which is
        // possibly P itself.
        Vector2D<Real> sTriangle[3];  // <P,M,I> or <P,I,M>
        int pIndex;
        if (mSPositions[outer[v0min]][0] > mSPositions[outer[v1min]][0])
        {
            sTriangle[0] = mSPositions[outer[v0min]];
            sTriangle[1] = intr;
            sTriangle[2] = M;
            pIndex = v0min;
        }
        else
        {
            sTriangle[0] = mSPositions[outer[v1min]];
            sTriangle[1] = M;
            sTriangle[2] = intr;
            pIndex = v1min;
        }

        // If any outer-polygon vertices other than P are inside the triangle
        // <M,I,P>, then at least one of these vertices must be a reflex
        // vertex.  It is sufficient to locate the reflex vertex Real (if any)
        // in <M,I,P> that minimizes the angle between Real-M and (1,0).  The
        // data member mQuery is used for the reflex query.
		auto diff = sTriangle[0] - M;
		auto maxSqrLen = Vector2DTools<Real>::VectorMagnitudeSquared(diff);
		auto maxCos = diff[0]*diff[0]/maxSqrLen;
        maxCosIndex = pIndex;
        for (i = 0; i < numOuterVertices; ++i)
        {
            if (i == pIndex)
            {
                continue;
            }

			auto curr = outer[i];
			auto prev = outer[(i + numOuterVertices - 1) % numOuterVertices];
			auto next = outer[(i + 1) % numOuterVertices];
            if (System::EnumCastUnderlying(mQuery->ToLine(curr, prev, next)) <= 0  &&  TriangleQuery(mSPositions[curr], queryType, epsilon, sTriangle) <= 0)
            {
                // The vertex is reflex and inside the <M,I,P> triangle.
                diff = mSPositions[curr] - M;
				auto sqrLen = Vector2DTools<Real>::VectorMagnitudeSquared(diff);
				auto cs = diff[0]*diff[0]/sqrLen;
                if (cs > maxCos)
                {
                    // The reflex vertex forms a smaller angle with the
                    // positive x-axis, so it becomes the new visible
                    // candidate.
                    maxSqrLen = sqrLen;
                    maxCos = cs;
                    maxCosIndex = i;
                }
                else if (cs == maxCos && sqrLen < maxSqrLen)
                {
                    // The reflex vertex has angle equal to the current
                    // minimum but the length is smaller, so it becomes the
                    // new visible candidate.
                    maxSqrLen = sqrLen;
                    maxCosIndex = i;
                }
            }
        }
    }
    else
    {
        maxCosIndex = endMin;
    }

    // The visible vertices are Position[Inner[xmaxIndex]] and
    // Position[Outer[maxCosIndex]].  Two coincident edges with these
    // endpoints are inserted to connect the outer and inner polygons into a
    // simple polygon.  Each of the two Position[] values must be duplicated,
    // because the original might be convex (or reflex) and the duplicate is
    // reflex (or convex).  The ear-clipping algorithm needs to distinguish
    // between them.
    combined.resize(numOuterVertices + numInnerVertices + 2);
    int cIndex = 0;
    for (i = 0; i <= maxCosIndex; ++i, ++cIndex)
    {
        combined[cIndex] = outer[i];
    }

    for (i = 0; i < numInnerVertices; ++i, ++cIndex)
    {
		auto j = (xmaxIndex + i) % numInnerVertices;
        combined[cIndex] = inner[j];
    }

	auto innerIndex = inner[xmaxIndex];
    mSPositions[nextElement] = mSPositions[innerIndex];
    combined[cIndex] = nextElement;
	auto iter = indexMap.find(innerIndex);
    if (iter != indexMap.end())
    {
        innerIndex = iter->second;
    }
    indexMap[nextElement] = innerIndex;
    ++cIndex;
    ++nextElement;

	auto outerIndex = outer[maxCosIndex];
    mSPositions[nextElement] = mSPositions[outerIndex];
    combined[cIndex] = nextElement;
    iter = indexMap.find(outerIndex);
    if (iter != indexMap.end())
    {
        outerIndex = iter->second;
    }
    indexMap[nextElement] = outerIndex;
    ++cIndex;
    ++nextElement;

    for (i = maxCosIndex + 1; i < numOuterVertices; ++i, ++cIndex)
    {
        combined[cIndex] = outer[i];
    }
}

template <typename Real>
void Mathematics::TriangulateEC<Real>
	::ProcessOuterAndInners (QueryType queryType, Real epsilon, const Indices& outer, const IndicesArray& inners,int& nextElement, IndexMap& indexMap, Indices& combined)
{
    // Sort the inner polygons based on maximum x-values.
    auto numInners = boost::numeric_cast<int>(inners.size());
    std::vector<std::pair<Real,int> > pairs(numInners);
    int i;
    for (i = 0; i < numInners; ++i)
    {
        const auto& inner = *inners[i];
		auto numVertices = boost::numeric_cast<int>(inner.size());
        Real xmax = mSPositions[inner[0]][0];
        for (auto j = 1; j < numVertices; ++j)
        {
			auto x = mSPositions[inner[j]][0];
            if (x > xmax)
            {
                xmax = x;
            }
        }
        pairs[i].first = xmax;
        pairs[i].second = i;
    }
    std::sort(pairs.begin(),pairs.end());

    // Merge the inner polygons with the outer polygon.
	auto currentOuter = outer;
    for (i = numInners - 1; i >= 0; --i)
    {
        const auto& inner = *inners[pairs[i].second];
        Indices currentCombined;
        CombinePolygons(queryType, epsilon, nextElement, currentOuter, inner, indexMap, currentCombined);
        currentOuter = currentCombined;
        nextElement += 2;
    }

    for (auto i = 0u; i <  currentOuter.size(); ++i)
    {
        combined.push_back(currentOuter[i]);
    }
}

template <typename Real>
void Mathematics::TriangulateEC<Real>
	::RemapIndices (const IndexMap& indexMap,  Indices& triangles) const
{
    // The triangulation includes indices to the duplicated outer and inner
    // vertices.  These indices must be mapped back to the original ones.
    const auto numTriangles = boost::numeric_cast<int>(triangles.size());
    for (auto i = 0; i < numTriangles; ++i)
    {
		auto iter = indexMap.find(triangles[i]);
        if (iter != indexMap.end())
        {
            triangles[i] = iter->second;
        }
    }
}



// Vertex list handling

template <typename Real>
typename Mathematics::TriangulateEC<Real>::Vertex& Mathematics::TriangulateEC<Real>
	::V (int i)
{
    return mVertices[i];
}

template <typename Real>
bool Mathematics::TriangulateEC<Real>
	::IsConvex (int i)
{
	auto& vertex = V(i);
	auto curr = vertex.Index;
	auto prev = V(vertex.VPrev).Index;
	auto next = V(vertex.VNext).Index;
    vertex.IsConvex = (System::EnumCastUnderlying(mQuery->ToLine(curr, prev, next)) > 0);
    return vertex.IsConvex;
}

template <typename Real>
bool Mathematics::TriangulateEC<Real>
	::IsEar (int i)
{
	auto& vertex = V(i);

    if (mRFirst == -1)
    {
        // The remaining polygon is convex.
        vertex.IsEar = true;
        return true;
    }

    // Search the reflex vertices and test if any are in the triangle
    // <V[prev],V[curr],V[next]>.
	auto prev = V(vertex.VPrev).Index;
	auto curr = vertex.Index;
	auto next = V(vertex.VNext).Index;
    vertex.IsEar = true;
    for (auto j = mRFirst; j != -1; j = V(j).SNext)
    {
        // Check if the test vertex is already one of the triangle vertices.
        if (j == vertex.VPrev || j == i || j == vertex.VNext)
        {
            continue;
        }

        // V[j] has been ruled out as one of the original vertices of the
        // triangle <V[prev],V[curr],V[next]>.  When triangulating polygons
        // with holes, V[j] might be a duplicated vertex, in which case it
        // does not affect the earness of V[curr].
		auto test = V(j).Index;
        if (mSPositions[test] == mSPositions[prev]  ||  mSPositions[test] == mSPositions[curr]  ||  mSPositions[test] == mSPositions[next])
        {
            continue;
        }

        // Test if the vertex is inside or on the triangle.  When it is, it
        // causes V[curr] not to be an ear.
        if (System::EnumCastUnderlying(mQuery->ToTriangle(test, prev, curr, next)) <= 0)
        {
            vertex.IsEar = false;
            break;
        }
    }

    return vertex.IsEar;
}

template <typename Real>
void Mathematics::TriangulateEC<Real>
	::InsertAfterC (int i)
{
    if (mCFirst == -1)
    {
        // add first convex vertex
        mCFirst = i;
    }
    else
    {
        V(mCLast).SNext = i;
        V(i).SPrev = mCLast;
    }
    mCLast = i;
}

template <typename Real>
void Mathematics::TriangulateEC<Real>
	::InsertAfterR (int i)
{
    if (mRFirst == -1)
    {
        // add first reflex vertex
        mRFirst = i;
    }
    else
    {
        V(mRLast).SNext = i;
        V(i).SPrev = mRLast;
    }
    mRLast = i;
}

template <typename Real>
void Mathematics::TriangulateEC<Real>
	::InsertEndE (int i)
{
    if (mEFirst == -1)
    {
        // add first ear
        mEFirst = i;
        mELast = i;
    }
    V(mELast).ENext = i;
    V(i).EPrev = mELast;
    mELast = i;
}

template <typename Real>
void Mathematics::TriangulateEC<Real>
	::InsertAfterE (int i)
{
	auto& first = V(mEFirst);
    int currENext = first.ENext;
	auto& vertex = V(i);
    vertex.EPrev = mEFirst;
    vertex.ENext = currENext;
    first.ENext = i;
    V(currENext).EPrev = i;
}

template <typename Real>
void Mathematics::TriangulateEC<Real>
	::InsertBeforeE (int i)
{
	auto& first = V(mEFirst);
    int currEPrev = first.EPrev;
	auto& vertex = V(i);
    vertex.EPrev = currEPrev;
    vertex.ENext = mEFirst;
    first.EPrev = i;
    V(currEPrev).ENext = i;
}

template <typename Real>
void Mathematics::TriangulateEC<Real>
	::RemoveV (int i)
{
	auto currVPrev = V(i).VPrev;
	auto currVNext = V(i).VNext;
    V(currVPrev).VNext = currVNext;
    V(currVNext).VPrev = currVPrev;
}

template <typename Real>
int Mathematics::TriangulateEC<Real>
	::RemoveE (int i)
{
	auto currEPrev = V(i).EPrev;
	auto currENext = V(i).ENext;
    V(currEPrev).ENext = currENext;
    V(currENext).EPrev = currEPrev;
    return currENext;
}

template <typename Real>
void Mathematics::TriangulateEC<Real>
	::RemoveR (int i)
{
    MATHEMATICS_ASSERTION_0(mRFirst != -1 && mRLast != -1, "Reflex vertices must exist\n");

    if (i == mRFirst)
    {
        mRFirst = V(i).SNext;
        if (mRFirst != -1)
        {
            V(mRFirst).SPrev = -1;
        }
        V(i).SNext = -1;
    }
    else if (i == mRLast)
    {
        mRLast = V(i).SPrev;
        if (mRLast != -1)
        {
            V(mRLast).SNext = -1;
        }
        V(i).SPrev = -1;
    }
    else
    {
		auto currSPrev = V(i).SPrev;
		auto currSNext = V(i).SNext;
        V(currSPrev).SNext = currSNext;
        V(currSNext).SPrev = currSPrev;
        V(i).SNext = -1;
        V(i).SPrev = -1;
    }
}



// Tree support.

template <typename Real>
void Mathematics::TriangulateEC<Real>
	::Delete (Tree*& root)
{
    if (root)
    {
        std::queue<Tree*> treeQueue;
        treeQueue.push(root);

        while (treeQueue.size() > 0)
        {
			auto tree = treeQueue.front();
            treeQueue.pop();
            const auto numChildren = (int)tree->Child.size();
            for (int i = 0; i < numChildren; ++i)
            {
               treeQueue.push(tree->Child[i]);
            }
            DELETE0(tree);
        }

        root = 0;
    }
}

template <typename Real>
int Mathematics::TriangulateEC<Real>
	::GetExtraElements (const Tree* tree)
{
	auto extraElements = 0;

    std::queue<const Tree*> treeQueue;
    treeQueue.push(tree);
    while (treeQueue.size() > 0)
    {
        const Tree* root = treeQueue.front();
        treeQueue.pop();
        const auto numChildren = boost::numeric_cast<int>(root->Child.size());
        extraElements += 2*numChildren;

        for (auto i = 0; i < numChildren; ++i)
        {
            const Tree* child = root->Child[i];
            const auto numGrandChildren = boost::numeric_cast<int>(child->Child.size());
            for (int j = 0; j < numGrandChildren; ++j)
            {
                treeQueue.push(child->Child[j]);
            }
        }
    }

    return extraElements;
}

template <typename Real>
Mathematics::TriangulateEC<Real>::Vertex
	::Vertex ()
	:Index{ -1 },IsConvex{ false },IsEar{ false },  VPrev{ -1 },VNext{ -1 }, SPrev{ -1 }, SNext{ -1 }, EPrev{ -1 }, ENext{ -1 }
{
}


#endif // MATHEMATICS_COMPUTATIONAL_GEOMETRY_TRIANGULATE_EC_DETAIL_H