// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 14:33)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY1_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY1_H

// A fancy class to sort a collection of real-valued numbers, but this
// provides some convenience for Delaunay2 and Delaunay3 when the input point
// set has intrinsic dimension smaller than the containing space.  The
// interface of Delaunay1 is also the model for those of Delaunay2 and
// Delaunay3.

#include "Mathematics/MathematicsDll.h"

#include "Delaunay.h"

namespace Mathematics
{
	template <typename Real>
	class Delaunay1 : public Delaunay<Real>
	{
	public:
		// The input to the constructor is the array of vertices you want to sort.
		// If you want Delaunay1 to delete the array during destruction, set
		// 'owner' to 'true'.  Otherwise, you own the array and must delete it
		// yourself.  TO DO:  The query type is curretly ignored by this class.
		// Add support for the various types later.
		Delaunay1 (int numVertices, Real* vertices, Real epsilon,  bool owner,QueryType queryType);
		virtual ~Delaunay1 ();
		
		// The input vertex array.
		const Real* GetVertices () const;
		
		// The functions listed here are valid only for dimension 1.
		
		// The convex hull of the vertices is an interval.  This function returns
		// the indices of the vertices that form the interval.  The return value
		// is 'true' iff the dimension is 1.
		bool GetHull (int hull[2]);
		
		// Support for searching the sorted vertices for a interval that contains
		// P.  If there is a containing interval, the returned value is a index i
		// into the GetIndices() array with 0 <= i < GetSimplexQuantity().  If
		// there is not a containing segment, -1 is returned.
		int GetContainingSegment (const Real p) const;
		
		// Get the vertices for segment i.  The function returns 'true' if i is a
		// valid segment index, in which case the vertices are valid.  Otherwise,
		// the function returns 'false' and the vertices are invalid.
		bool GetVertexSet (int i, Real vertices[2]) const;
		
		// Get the vertex indices for segment i.  The function returns 'true' if
		// i is a valid segment index, in which case the vertices are valid.
		// Otherwise, the function returns 'false' and the vertices are invalid.
		bool GetIndexSet (int i, int indices[2]) const;
		
		// Get the indices for segments adjacent to segment i.  The function
		// returns 'true' if i is a valid segment index, in which case the
		// adjacencies are valid.  Otherwise, the function returns 'false' and
		// the adjacencies are invalid.
		bool GetAdjacentSet (int i, int adjacencies[2]) const;
		
		// Compute the barycentric coordinates of P with respect to segment i.
		// The function returns 'true' if i is a valid segment index, in which
		// case the coordinates are valid.  Otherwise, the function returns
		// 'false' and the coordinate array is invalid.
		bool GetBarycentricSet (int i, const Real p, Real bary[2]) const;
		
		// Support for streaming to/from disk.
		Delaunay1 (const System::TChar* filename);
		bool Load(const System::TChar* filename);
		bool Save(const System::TChar* filename) const;
		
	private:
		using Delaunay<Real>::mNumVertices;
		using Delaunay<Real>::mDimension;
		using Delaunay<Real>::mNumSimplices;
		using Delaunay<Real>::mIndices;
		using Delaunay<Real>::mAdjacencies;
		using Delaunay<Real>::mEpsilon;
		using Delaunay<Real>::mOwner;
		
		class SortedVertex
		{
		public:
			Real Value;
			int Index;
			
			inline bool operator< (const SortedVertex& vertex) const
			{
				return Value < vertex.Value;
			}
		};
		
		Real* mVertices;
	};
	
	using Delaunay1f = Delaunay1<float>;
	using Delaunay1d = Delaunay1<double>;
}

#endif // MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY1_H
