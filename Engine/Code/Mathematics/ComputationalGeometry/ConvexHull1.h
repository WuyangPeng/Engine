// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 14:31)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL1_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL1_H

// A fancy class to compute the minimum and maximum of a collection of
// real-valued numbers, but this provides some convenience for ConvexHull2 and
// ConvexHull3 when the input point set has intrinsic dimension smaller than
// the containing space.  The interface of ConvexHull1 is also the model for
// those of ConvexHull2 and ConvexHull3.

#include "Mathematics/MathematicsDll.h"

#include "ConvexHull.h"

namespace Mathematics
{	
	template <typename Real>
	class ConvexHull1 : public ConvexHull<Real>
	{
	public:
		// The input to the constructor is the array of vertices you want to sort.
		// If you want ConvexHull1 to delete the array during destruction, set
		// 'owner' to 'true'.  Otherwise, you own the array and must delete it
		// yourself.  TO DO:  The computation type is currently ignored by this
		// class.  Add support for the various types later.
		ConvexHull1 (int numVertices, Real* vertices, Real epsilon,  bool owner, QueryType queryType);
		virtual ~ConvexHull1 ();
		
		// The input vertex array.
		const Real* GetVertices () const;
		
		// Support for streaming to/from disk.
		explicit ConvexHull1(const System::TChar* filename);
		bool Load (const System::TChar* filename);
		bool Save(const System::TChar* filename) const;
		
	private:
		using ConvexHull<Real>::mNumVertices;
		using ConvexHull<Real>::mDimension;
		using ConvexHull<Real>::mNumSimplices;
		using ConvexHull<Real>::mIndices;
		using ConvexHull<Real>::mEpsilon;
		using ConvexHull<Real>::mOwner;
		
		Real* mVertices;
		
		class SortedVertex
		{
		public:
			Real Value;
			int Index;
			
			bool operator< (const SortedVertex& proj) const
			{
				return Value < proj.Value;
			}
		};
	};
	
	using ConvexHull1f = ConvexHull1<float>;
	using ConvexHull1d = ConvexHull1<double>;
}

#endif // MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL1_H
