// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 14:32)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL3_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL3_H

#include "Mathematics/MathematicsDll.h"

#include "ConvexHull1.h"
#include "ConvexHull2.h"
#include "Mathematics/Query/Query3.h" 

namespace Mathematics
{
	template <typename Real>
	class ConvexHull3 : public ConvexHull<Real>
	{
	public:
		// The input to the constructor is the array of vertices whose convex hull
		// is required.  If you want ConvexHull3 to delete the vertices during
		// destruction, set bOwner to 'true'.  Otherwise, you own the vertices and
		// must delete them yourself.
		//
		// You have a choice of speed versus accuracy.  The fastest choice is
		// Query::QT_INT64, but it gives up a lot of precision, scaling the points
		// to [0,2^{20}]^3.  The choice Query::QT_INTEGER gives up less precision,
		// scaling the points to [0,2^{24}]^3.  The choice Query::QT_RATIONAL uses
		// exact arithmetic, but is the slowest choice.  The choice Query::QT_REAL
		// uses floating-point arithmetic, but is not robust in all cases.
		ConvexHull3 (const std::vector<Vector3D<Real> >& vertices, Real epsilon, bool bOwner, QueryType eQueryType);
		virtual ~ConvexHull3 ();
		
		// If GetDimension() returns 1, then the points lie on a line.  You must
		// create a ConvexHull1 object using the function provided.
		const Vector3D<Real>& GetLineOrigin () const;
		const Vector3D<Real>& GetLineDirection () const;
		ConvexHull1<Real>* GetConvexHull1 () const;
		
		// If GetDimension() returns 2, then the points lie on a plane.  The plane
		// has two direction vectors (inputs 0 or 1).  You must create a
		// ConvexHull2 object using the function provided.
		const Vector3D<Real>& GetPlaneOrigin () const;
		const Vector3D<Real>& GetPlaneDirection (int i) const;
		ConvexHull2<Real>* GetConvexHull2 () const;
		
		// Support for streaming to/from disk.
		ConvexHull3 (const System::TChar* filename);
		bool Load (const System::TChar* filename);
		bool Save (const System::TChar* filename) const;
		
	private:
		using ConvexHull<Real>::mQueryType;
		using ConvexHull<Real>::mNumVertices;
		using ConvexHull<Real>::mDimension;
		using ConvexHull<Real>::mNumSimplices;
		using ConvexHull<Real>::mIndices;  
		using ConvexHull<Real>::mEpsilon;
		using ConvexHull<Real>::mOwner;
		
		class Triangle
		{
		public:
			Triangle (int v0, int v1, int v2);
			
			int GetSign (int i, const Query3<Real>* query);
			void AttachTo (Triangle* adj0, Triangle* adj1, Triangle* adj2);
			int DetachFrom (int adjIndex, Triangle* adj);
			
			int V[3];
			Triangle* Adj[3];
			int Sign;
			int Time;
			bool OnStack;
		};
		
		bool Update (int i);
		void ExtractIndices ();
		void DeleteHull ();
		
		// The input points.
		std::vector<Vector3D<Real> > mVertices;
		
		// Support for robust queries.
		std::vector<Vector3D<Real> > mSVertices;
		Query3<Real>* mQuery;
		
		// The line of containment if the dimension is 1.
		Vector3D<Real> mLineOrigin, mLineDirection;
		
		// The plane of containment if the dimension is 2.
		Vector3D<Real> mPlaneOrigin, mPlaneDirection[2];
		
		// The current hull.
		std::set<Triangle*> mHull;
		
		class TerminatorData
		{
		public:
			TerminatorData (int v0 = -1, int v1 = -1, int nullIndex = -1,Triangle* tri = 0);
			
			int V[2];
			int NullIndex;
			Triangle* T;
		};
	};
	
	using ConvexHull3f = ConvexHull3<float>;
	using ConvexHull3d = ConvexHull3<double>;
}

#endif // MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL3_H
