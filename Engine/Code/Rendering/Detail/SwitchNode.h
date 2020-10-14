// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 10:30)

#ifndef RENDERING_DETAIL_SWITCH_NODE_H
#define RENDERING_DETAIL_SWITCH_NODE_H

#include "Rendering/SceneGraph/Node.h"
#include "Flags/SwitchNodeType.h"

namespace Rendering
{	
	class RENDERING_DEFAULT_DECLARE SwitchNode : public Node
	{
	public:
		using ClassType = SwitchNode;
		using ParentType = Node;
		using ClassShareType = CoreTools::CopyUnsharedClasses;

	public:
		SwitchNode (); 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(SwitchNode); 
	
		void SetActiveChild (int activeChild);
		int GetActiveChild () const noexcept;
		void DisableAllChildren () noexcept;

		 ControllerInterfaceSharedPtr Clone() const override;
                ObjectInterfaceSharedPtr CloneObject() const override;
		 const PickRecordContainer ExecuteRecursive(const APoint& origin,const AVector& direction, float tMin, float tMax) const override;
	 
	protected:
		  void GetVisibleSet (Culler& culler, bool noCull) override;
		 
	private:
		 int m_ActiveChild;
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(SwitchNode);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( SwitchNode); 
}

#endif // RENDERING_DETAIL_SWITCH_NODE_H
