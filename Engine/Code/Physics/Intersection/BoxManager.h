// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 16:56)

#ifndef PHYSICS_INTERSECTION_BOX_MANAGER_H
#define PHYSICS_INTERSECTION_BOX_MANAGER_H

#include "Physics/PhysicsDll.h"

#include "Mathematics/Meshes/EdgeKey.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox3.h"

#include <set>
#include <vector>

namespace Physics
{
	template <typename Real>
	class BoxManager
	{
	public:
		using AxesAlignBoundingBox3D = Mathematics::AxesAlignBoundingBox3<Real>;
		using EdgeKey = Mathematics::EdgeKey;

	public:
		// Construction and destruction.
		explicit BoxManager(std::vector<AxesAlignBoundingBox3D>& boxes);
		~BoxManager();

		// This function is called by the constructor and does the sort-and-sweep
		// to initialize the update system.  However, if you add or remove items
		// from the array of boxes after the constructor call, you will need
		// to call this function once before you start the multiple calls of the
		// update function.
		void Initialize();

		// After the system is initialized, you can move the boxes using this
		// function.  It is not enough to modify the input array of boxes
		// since the endpoint values stored internally by this class must also
		// change.  You can also retrieve the current rectangles information.
		void SetBox(int i, const AxesAlignBoundingBox3D& box);
		void GetBox(int i, AxesAlignBoundingBox3D& box) const;

		// When you are finished moving boxes, call this function to determine
		// the overlapping boxes.  An incremental update is applied to determine
		// the new set of overlapping boxes.
		void Update();

		// If (i,j) is in the overlap set, then box i and box j are
		// overlapping.  The indices are those for the the input array.  The
		// set elements (i,j) are stored so that i < j.
		const std::set<EdgeKey>& GetOverlap() const;

	private:
		class Endpoint
		{
		public:
			Real Value; // endpoint value
			int Type;   // '0' if interval min, '1' if interval max.
			int Index;  // index of interval containing this endpoint

			// Support for sorting of endpoints.
			bool operator< (const Endpoint& endpoint) const;
		};

		void InsertionSort(std::vector<Endpoint>& endPoint, std::vector<int>& lookup);

		std::vector<AxesAlignBoundingBox3D>* mBoxes;
		std::vector<Endpoint> mXEndpoints, mYEndpoints, mZEndpoints;
		std::set<EdgeKey> mOverlap;

		// The intervals are indexed 0 <= i < n.  The endpoint array has 2*n
		// entries.  The original 2*n interval values are ordered as b[0], e[0],
		// b[1], e[1], ..., b[n-1], e[n-1].  When the endpoint array is sorted,
		// the mapping between interval values and endpoints is lost.  In order
		// to modify interval values that are stored in the endpoint array, we
		// need to maintain the mapping.  This is done by the following lookup
		// table of 2*n entries.  The value mLookup[2*i] is the index of b[i]
		// in the endpoint array.  The value mLookup[2*i+1] is the index of
		// e[i] in the endpoint array.
		std::vector<int> mXLookup, mYLookup, mZLookup;
	};

	using BoxManagerf = BoxManager<float>;
	using BoxManagerd = BoxManager<double>;
}

#endif // PHYSICS_INTERSECTION_BOX_MANAGER_H
