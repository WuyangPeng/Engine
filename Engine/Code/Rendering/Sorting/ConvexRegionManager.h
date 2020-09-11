// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 10:30)

#ifndef RENDERING_SORTING_CONVEX_REGION_MANAGER_H
#define RENDERING_SORTING_CONVEX_REGION_MANAGER_H

#include "Rendering/RenderingDll.h"

#include "BspNode.h"
#include "ConvexRegion.h"
#include "CRMCuller.h"

namespace Rendering
{
	class   ConvexRegionManager : public BspNode
	{
	public:
		using ClassType = ConvexRegionManager;
		using ParentType = BspNode;

	private:	
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(ConvexRegionManager);			                
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE; 

	public:
		// Construction and destruction.  The BSP tree should be built so that
		// the leaf nodes are where the ConvexRegion objects are located.
		ConvexRegionManager();
		ConvexRegionManager(const Mathematics::FloatPlane& modelPlane);
	 

		// The middle child of ConvexRegionManager is where the representation
		// of the outside of the set of regions is stored.  This can be an
		// arbitrary subgraph, not just drawable geometry.
		SpatialSmartPointer AttachOutside(SpatialSmartPointer outside);
		SpatialSmartPointer DetachOutside();
		SpatialSmartPointer GetOutside();

		// Determine region that contains the point.  If the point is outside
		// the set of regions, the return values is null.
		ConvexRegionSmartPointer GetContainingRegion(const Mathematics::FloatAPoint& point);

	protected:
		// Support for culling.
		  void GetVisibleSet(Culler& culler, bool noCull) override;

		CRMCuller mCuller;
	};
 #include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(ConvexRegionManager);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Eighth, ConvexRegionManager);
#include STSTEM_WARNING_POP
}

#endif // RENDERING_SORTING_CONVEX_REGION_MANAGER_H
