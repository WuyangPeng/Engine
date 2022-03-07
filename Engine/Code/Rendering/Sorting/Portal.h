// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/26 10:31)

#ifndef RENDERING_SORTING_PORTAL_H
#define RENDERING_SORTING_PORTAL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/Plane.h"
#include "Rendering/DataTypes/Transform.h"
#include "CoreTools/ObjectSystems/Object.h" 

namespace Rendering
{
	class ConvexRegion;
	class Culler;

	class  Portal : public CoreTools::Object
	{
	public:
		using ClassType = Portal;
		using ParentType = Object;

	private:
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Portal);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

	public:
		// The portal is a unidirectional connector between two regions.  The
		// vertices of the portal must satisfy the following constraints:
		// 1. They must form a planar simple polygon (numVertices >= 3 is
		//    implied).  The polygon does not have to be convex.
		// 2. They must be counterclockwise ordered when looking through the
		//    portal to the adjacent region.
		// 3. They must be in the model-space coordinates for the region that
		//    contains the portal.

		// Construction and destruction.  Portal accepts responsibility for
		// deleting the input array.  The model vertices must be counterclockwise
		// oriented in the model plane when viewed from the side of the plane to
		// which the plane normal points.
		Portal(int numVertices, Mathematics::APointF* modelVertices, const Mathematics::PlaneF& modelPlane, ConvexRegion* adjacentRegion, bool open);

		  ~Portal();
		  Portal(const Portal&) = default;
		   Portal& operator=(const Portal&) = default;
		    Portal(Portal&&) = default;
		   Portal& operator=(Portal&&) = default;
                    ObjectInterfaceSharedPtr CloneObject() const override;
		// Member access.  The region to which the portal leads.  Portals can be
		// open or closed.
		ConvexRegion* AdjacentRegion;
		bool Open;

	protected:
		// Support for the graph update.
		friend class ConvexRegion;
            void UpdateWorldData(const FloatTransform& worldTransform) noexcept;

		// Support for culling.
		bool ReducedFrustum(const Culler& culler, float reducedFrustum[6]);
		void GetVisibleSet(Culler& culler, bool noCull);

		// Portal vertices and their planes.
		int mNumVertices;
		Mathematics::APointF* mModelVertices;
		Mathematics:: APointF* mWorldVertices;
		Mathematics::PlaneF mModelPlane;
		Mathematics::PlaneF mWorldPlane;
	};
 #include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(Portal);
	CORE_TOOLS_SHARED_PTR_DECLARE( Portal);
	#include STSTEM_WARNING_POP
}

#endif // RENDERING_SORTING_PORTAL_H
