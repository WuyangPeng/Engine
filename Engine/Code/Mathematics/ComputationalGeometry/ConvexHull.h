// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 14:31)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "Mathematics/Query/QueryBase.h"

namespace Mathematics
{
	template <typename Real>
	class ConvexHull
	{
	public:
		// Abstract base class.
		virtual ~ConvexHull ();
		
		// Member accessors.  For notational purposes in this class documentation,
		// The number of vertices is VQ and the vertex array is V.
		int GetQueryType () const;
		int GetNumVertices () const;
		Real GetEpsilon () const;
		bool GetOwner () const;
		
		// The dimension of the result, call it d.  If n is the dimension of the
		// space of the input points, then 0 <= d <= n.
		int GetDimension () const;
		
		// The interpretations of the return values of these functions depends on
		// the dimension.  Generally, SQ = GetNumSimplices() is the number of
		// simplices in the mesh.  The array I is returned by GetIndices().  
		int GetNumSimplices () const;
		const int* GetIndices () const;
		
		// Dimension d = 0.
		//   SQ = 1
		//   I  = null (use index zero for vertices)
		
		// Dimension d = 1.
		//   SQ = 2
		//   I = array of two indices
		// The segment has end points
		//   vertex[0] = V[I[0]]
		//   vertex[1] = V[I[1]]
		
		// Dimension d = 2.
		//   SQ = number of convex polygon edges
		//   I  = array of indices into V that represent the convex polygon edges
		//        (SQ total elements)
		// The i-th edge has vertices
		//   vertex[0] = V[I[i]]
		//   vertex[1] = V[I[(i+1) % SQ]]
		
		// Dimension d = 3.
		//   SQ = number of convex polyhedron triangular faces
		//   I  = array of 3-tuples of indices into V that represent the
		//        triangles (3*SQ total elements)
		// The i-th face has vertices
		//   vertex[0] = V[I[3*i+0]]
		//   vertex[1] = V[I[3*i+1]]
		//   vertex[2] = V[I[3*i+2]]
		
	protected:
		// Abstract base class.  The number of vertices to be processed is
		// 'numVertices'.  The value of 'epsilon' is a tolerance used for
		// determining the intrinsic dimension of the input set of vertices.
		// Ownership of the input points to the constructors for the derived
		// classes may be transferred to this class.  If you want the input
		// vertices to be deleted by this class, set 'owner' to 'true';
		// otherwise, you own the array and must delete it yourself.
		ConvexHull(int numVertices, Real epsilon, bool owner, QueryType queryType);
		
		// Support for streaming to/from disk.
		bool Load(CoreTools::ReadFileManager& inFile);
		bool Save(CoreTools::WriteFileManager& outFile) const;
		
		QueryType mQueryType;
		int mNumVertices;
		int mDimension;
		int mNumSimplices;
		int* mIndices;
		Real mEpsilon;
		bool mOwner;
	};
	
	using ConvexHullf = ConvexHull<float>;
	using ConvexHulld = ConvexHull<double>;
}

#endif // MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL_H
