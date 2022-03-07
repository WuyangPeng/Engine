// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 10:29)

#ifndef RENDERING_SORTING_BSP_NODE_H
#define RENDERING_SORTING_BSP_NODE_H

#include "Rendering/RenderingDll.h"
 #include "Mathematics/Algebra/AVectorDetail.h"
#include "Rendering/SceneGraph/Node.h"
#include "Mathematics/Algebra/Plane.h"

namespace Rendering
{
	class  BspNode : public Node
	{
	public:
		using ClassType = BspNode;
		using ParentType = Node;

	private:
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(BspNode); 

	public:
		// Construction and destruction.  The base class Node has *three* children
		// and is not allowed to grow.  The first and last children (indices 0 and
		// 2) are the "positive" and "negative" children of the binary tree.  The
		// positive child corresponds to the positive side of the separating
		// plane.  The negative child corresponds to the negative side of the
		// separating plane.  The middle child slot is where additional geometry
		// may be attached such as the triangles that are coplanar with the
		// separating plane.
		BspNode();
		BspNode(const Mathematics::PlaneF& modelPlane);
		 

		// These methods should be used instead of the attach/detach methods in
		// the Node base class.
		SpatialSharedPtr AttachPositiveChild(SpatialSharedPtr child);
		SpatialSharedPtr AttachCoplanarChild(SpatialSharedPtr child);
		SpatialSharedPtr AttachNegativeChild(SpatialSharedPtr child);
		 SpatialSharedPtr DetachPositiveChild();
		 SpatialSharedPtr DetachCoplanarChild();
		 SpatialSharedPtr DetachNegativeChild();
		 SpatialSharedPtr GetPositiveChild();
		 SpatialSharedPtr GetCoplanarChild();
		 SpatialSharedPtr GetNegativeChild();

		// Member access.
		 Mathematics::PlaneF ModelPlane;
                 const Mathematics::PlaneF& GetWorldPlane() const noexcept;

		// Determine the portion of the scene that contains the point.
		 SpatialSharedPtr GetContainingNode(const Mathematics::APointF& point);
                 ObjectInterfaceSharedPtr CloneObject() const override;
	protected:
		// Support for the geometric update. 
		  bool UpdateWorldData(double applicationTime) override;

		// Support for hierarchical culling.
		  void GetVisibleSet(Culler& culler, bool noCull) override;

		Mathematics::PlaneF mWorldPlane;
	};
 #include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(BspNode);
	CORE_TOOLS_SHARED_PTR_DECLARE( BspNode);
	#include STSTEM_WARNING_POP
}

#endif // RENDERING_SORTING_BSP_NODE_H
