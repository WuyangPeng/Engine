// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 10:30)

#ifndef RENDERING_SORTING_CONVEX_REGION_H
#define RENDERING_SORTING_CONVEX_REGION_H

#include "Rendering/RenderingDll.h"

#include "Rendering/SceneGraph/Node.h"

namespace Rendering
{
	class Portal;

	class   ConvexRegion : public Node
	{
	public:
		using ClassType = ConvexRegion;
		using ParentType = Node;

	private:
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ConvexRegion);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

	public:
		// Construction and destruction.  ConvexRegion accepts responsibility
		// for deleting the input array of Portal*.
		ConvexRegion(int numPortals, Portal** portals);
		  ~ConvexRegion();
		  ConvexRegion(const ConvexRegion&) = default;
		  ConvexRegion& operator=(const ConvexRegion&) = default;
		   ConvexRegion( ConvexRegion&&) = default;
		  ConvexRegion& operator=( ConvexRegion&&) = default;

		// Portal access.
		  int GetNumPortals() const noexcept;
		  Portal* GetPortal(int i) const noexcept;

	protected:
		// Support for the geometric update.
		  bool UpdateWorldData(double applicationTime) override;

		// Portals of the region (these are not set up to be shared).
		int mNumPortals;
		Portal** mPortals;

		// For region graph traversal.
		bool mVisited;

	public:
		// Culling.  ConvexRegionManager starts the region graph traversal
		// with the region containing the camera position.  Portal continues the
		// traversal.  Should you decide not to use a convex region manager and
		// track which region the eyepoint is in using your own system, you will
		// need to make sure the convex region that contains the camera position
		// is the first one visited during a depth-first traversal of the scene.
		  void GetVisibleSet(Culler& culler, bool noCull) override;
	};
 
  #include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(ConvexRegion);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Seventh, ConvexRegion);
#include STSTEM_WARNING_POP
}

#endif // RENDERING_SORTING_CONVEX_REGION_H
