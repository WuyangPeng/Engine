// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/17 14:42)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY3_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY3_H

#include "Mathematics/MathematicsDll.h"

#include "Delaunay1.h" 
#include "Delaunay2.h"
#include "Mathematics/Query/QueryBase.h"
#include "Mathematics/Meshes/TSManifoldMesh.h"

namespace Mathematics
{
	template <typename Real>
	class Delaunay3 : public Delaunay<Real>
	{
	public:
		// The input to the constructor is the array of vertices whose Delaunay
		// tetrahedralization is required.  If you want Delaunay3 to delete the
		// vertices during destruction, set bOwner to 'true'.  Otherwise, you
		// own the vertices and must delete them yourself.  Before using this
		// class, you should "clean" your input points by removing duplicates.
		//
		// You have a choice of speed versus accuracy.  The fastest choice is
		// Query::QT_INT64, but it gives up a lot of precision, scaling the points
		// to [0,2^{10}]^3.  The choice Query::QT_INTEGER gives up less precision,
		// scaling the points to [0,2^{20}]^3.  The choice Query::QT_RATIONAL uses
		// exact arithmetic, but is the slowest choice.  The choice Query::QT_REAL
		// uses floating-point arithmetic, but is not robust in all cases.

		Delaunay3 (const std::vector<Vector3D<Real> >& vertices, Real epsilon,bool owner, QueryType queryType);
		virtual ~Delaunay3 ();
		
		// The input vertex array.
		const Vector3D<Real>* GetVertices () const;
		
		// The number of unique vertices processed.
		int GetNumUniqueVertices () const;
		
		// If GetDimension() returns 1, then the points lie on a line.  You must
		// create a Delaunay1 object using the function provided.
		const Vector3D<Real>& GetLineOrigin () const;
		const Vector3D<Real>& GetLineDirection () const;
		Delaunay1<Real>* GetDelaunay1 () const;

		// If GetDimension() returns 2, then the points lie on a plane.  The plane
		// has two direction vectors (inputs 0 or 1).  You must create a Delaunay2
		// object using the function provided.
		const Vector3D<Real>& GetPlaneOrigin () const;
		const Vector3D<Real>& GetPlaneDirection (int i) const;
		Delaunay2<Real>* GetDelaunay2 () const;

		// Locate those tetrahedra faces that do not share other tetrahedra.
		// The returned quantity is the number of triangles in the hull.  The
		// returned array has 3*quantity indices, each triple representing a
		// triangle.  The triangles are counterclockwise ordered when viewed
		// from outside the hull.  The return value is 'true' iff the dimension
		// is 3.
		bool GetHull (int& numTriangles, int*& indices) const;

		// Support for searching the tetrahedralization for a tetrahedron that
		// contains a point.  If there is a containing tetrahedron, the returned
		// value is a tetrahedron index i with 0 <= i < numTriangles.  If there is
		// not a containing tetrahedron, -1 is returned.
		int GetContainingTetrahedron (const Vector3D<Real>& p) const;

		// If GetContainingTetrahedron returns a nonnegative value, the path of
		// tetrahedra searched for the containing tetrahedra is stored in an
		// array.  The last index of the array is returned by GetPathLast; it is
		// one less than the number of array elements.  The array itself is
		// returned by GetPath.
		int GetPathLast () const;
		const int* GetPath () const;

		// If GetContainingTetrahedron returns -1, the path of tetrahedra
		// searched may be obtained by GetPathLast and GetPath.  The input point
		// is outside a face of the last tetrahedron in the path.  This function
		// returns the vertex indices <v0,v1,v2> of the face, listed in
		// counterclockwise order relative to the convex hull of the data points
		// as viewed by an outside observer.  The final output is the index of the
		// vertex v3 opposite the face.  The return value of the function is the
		// index of the quadruple of vertex indices; the value is 0, 1, 2, or 3.
		int GetLastFace (int& v0, int& v1, int& v2, int& v3) const;

		// Get the vertices for tetrahedron i.  The function returns 'true' if i
		// is a valid tetrahedron index, in which case the vertices are valid.
		// Otherwise, the function returns 'false' and the vertices are invalid.
		bool GetVertexSet (int i, Vector3D<Real> vertices[4]) const;

		// Get the vertex indices for tetrahedron i.  The function returns 'true'
		// if i is a valid tetrahedron index, in which case the vertices are
		// valid.  Otherwise, the function returns 'false' and the vertices are
		// invalid.
		bool GetIndexSet (int i, int indices[4]) const;

		// Get the indices for tetrahedra adjacent to tetrahedron i.  The function
		// returns 'true' if i is a valid tetrahedron index, in which case the
		// adjacencies are valid.  Otherwise, the function returns 'false' and
		// the adjacencies are invalid.
		bool GetAdjacentSet (int i, int adjacencies[4]) const;

		// Compute the barycentric coordinates of P with respect to tetrahedron i.
		// The function returns 'true' if i is a valid tetrahedron index, in which
		// case the coordinates are valid.  Otherwise, the function returns
		// 'false' and the coordinate array is invalid.
		bool GetBarycentricSet (int i, const Vector3D<Real>& p, Real bary[4]) const;

		// Support for streaming to/from disk.
		Delaunay3 (const System::TChar* filename);
		bool Load (const System::TChar* filename);
		bool Save (const System::TChar* filename) const;

	private:
		using Delaunay<Real>::mQueryType;
		using Delaunay<Real>::mNumVertices;
		using Delaunay<Real>::mDimension;
		using Delaunay<Real>::mNumSimplices;
		using Delaunay<Real>::mIndices;
		using Delaunay<Real>::mAdjacencies;
		using Delaunay<Real>::mEpsilon;
		using Delaunay<Real>::mOwner;

		typedef TSManifoldMesh::Tetrahedron Tetrahedron;

		bool GetContainingTetrahedron (int i, Tetrahedron*& tetra) const;

		void GetAndRemoveInsertionPolyhedron (int i,std::set<Tetrahedron*>& candidates, std::set<TriangleKey>& boundary);

		void Update (int i);

		// The input vertices.
		std::vector<Vector3D<Real> > mVertices;

		// The number of unique vertices processed.
		int mNumUniqueVertices;

		// The scaled input vertices.  This array and supporting data structures
		// are for robust calculations.
		std::vector<Vector3D<Real> > mSVertices;
		Query3<Real>* mQuery;
		Vector3D<Real> mMin;
		Real mScale;
		
		// The current tetrahedralization.
		TSManifoldMesh mTetraMesh;
		
		// The line of containment if the dimension is 1.
		Vector3D<Real> m_LineOrigin, m_LineDirection;
		
		// The plane of containment if the dimension is 2.
		Vector3D<Real> mPlaneOrigin, mPlaneDirection[2];
		
		// Store the path of tetrahedra visited in a GetContainingTetrahedron
		// function call.
		mutable int mPathLast;
		mutable int* mPath;

		// If a query point is not in the convex hull of the input points, the
		// point is outside a face of the last tetrahedron in the search path.
		// These are the vertex indices for that face.
		mutable int mLastFaceV0, mLastFaceV1, mLastFaceV2;
		mutable int mLastFaceOpposite, mLastFaceOppositeIndex;
	};

	using Delaunay3f = Delaunay3<float>;
	using Delaunay3d = Delaunay3<double>;
}

#endif // MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY3_H
