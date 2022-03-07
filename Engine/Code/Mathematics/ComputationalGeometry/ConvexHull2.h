// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 14:32)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL2_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL2_H

#include "Mathematics/MathematicsDll.h"

#include "ConvexHull.h"
#include "Mathematics/Query/Query2.h" 

namespace Mathematics
{
	template <typename Real>
	class ConvexHull1;

	template <typename Real>
	class ConvexHull2 : public ConvexHull<Real>
	{
	public:
		// The input to the constructor is the array of vertices whose convex hull
		// is required.  If you want ConvexHull2 to delete the vertices during
		// destruction, set bOwner to 'true'.  Otherwise, you own the vertices and
		// must delete them yourself.
		//
		// You have a choice of speed versus accuracy.  The fastest choice is
		// Query::QT_INT64, but it gives up a lot of precision, scaling the points
		// to [0,2^{20}]^3.  The choice Query::QT_INTEGER gives up less precision,
		// scaling the points to [0,2^{24}]^3.  The choice Query::QT_RATIONAL uses
		// exact arithmetic, but is the slowest choice.  The choice Query::QT_REAL
		// uses floating-point arithmetic, but is not robust in all cases.
		ConvexHull2(const std::vector<Vector2<Real> >& vertices, Real epsilon, bool owner, QueryType queryType);
		virtual ~ConvexHull2 ();
		
		// If GetDimension() returns 1, then the points lie on a line.  You must
		// create a ConvexHull1 object using the function provided.
		const Vector2<Real>& GetLineOrigin () const;
		const Vector2<Real>& GetLineDirection () const;
		ConvexHull1<Real>* GetConvexHull1 () const;
		
		// Support for streaming to/from disk.
		explicit ConvexHull2(const System::TChar* filename);
		bool Load(const System::TChar* filename);
		bool Save(const System::TChar* filename) const;
		
	private:
		using ConvexHull<Real>::mQueryType;
		using ConvexHull<Real>::mNumVertices;
		using ConvexHull<Real>::mDimension;
		using ConvexHull<Real>::mNumSimplices;
		using ConvexHull<Real>::mIndices;
		using ConvexHull<Real>::mEpsilon;
		using ConvexHull<Real>::mOwner;
		
		class Edge
		{
		public:
			Edge (int v0, int v1);
			
			int GetSign (int i, const Query2<Real>* query);
			void Insert (Edge* adj0, Edge* adj1);
			void DeleteSelf ();
			void DeleteAll ();
			void GetIndices (int& numIndices, int*& indices);
			
			int V[2];
			Edge* E[2];
			int Sign;
			int Time;
		};
		
		bool Update (Edge*& hull, int i);
		
		// The input points.
		std::vector<Vector2<Real> > mVertices;
		
		// Support for robust queries.
		std::vector<Vector2<Real> > mSVertices;
		Query2<Real>* mQuery;
		
		// The line of containment if the dimension is 1.
		Vector2<Real> m_LineOrigin, m_LineDirection;
	};
	
	using ConvexHull2f = ConvexHull2<float>;
	using ConvexHull2d = ConvexHull2<double>;
}

#endif // MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL2_H
