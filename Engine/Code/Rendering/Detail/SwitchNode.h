// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 10:30)

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
		virtual ~SwitchNode ();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(SwitchNode); 
	
		void SetActiveChild (int activeChild);
		int GetActiveChild () const;
		void DisableAllChildren ();

		virtual ControllerInterfaceSmartPointer Clone() const override;

		virtual const PickRecordContainer ExecuteRecursive(const APoint& origin,const AVector& direction, float tMin, float tMax) const override;
	 
	protected:
		 virtual void GetVisibleSet (Culler& culler, bool noCull) override;
		 
	private:
		 int m_ActiveChild;
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(SwitchNode);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Seventh, SwitchNode); 
}

#endif // RENDERING_DETAIL_SWITCH_NODE_H
