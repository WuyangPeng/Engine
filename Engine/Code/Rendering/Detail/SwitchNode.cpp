// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 11:05)

#include "Rendering/RenderingExport.h"

#include "SwitchNode.h"
#include "Flags/SwitchNodeType.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "Rendering/DataTypes/BoundDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486) 
#include SYSTEM_WARNING_DISABLE(26455)
CORE_TOOLS_RTTI_DEFINE(Rendering, SwitchNode);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, SwitchNode);
CORE_TOOLS_FACTORY_DEFINE(Rendering, SwitchNode); 

Rendering::SwitchNode
	::SwitchNode ()
	:ParentType{}, m_ActiveChild{ System::EnumCastUnderlying(SwitchNodeType::InvalidChild) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}
 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,SwitchNode)

void Rendering::SwitchNode
	::GetVisibleSet (Culler& culler, bool noCull)
{
	if (m_ActiveChild != System::EnumCastUnderlying(SwitchNodeType::InvalidChild))
    {
		// 所有视觉对象在活跃的子树中，添加到可见组。
		auto child = GetChild(m_ActiveChild);
		if (child)
		{
			child->OnGetVisibleSet(culler, noCull);
		}
    }    
}

Rendering::ControllerInterfaceSharedPtr Rendering::SwitchNode
	::Clone() const 
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
	return ControllerInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

Rendering::SwitchNode
    ::SwitchNode (LoadConstructor value)
	:ParentType{ value }, m_ActiveChild{ System::EnumCastUnderlying(SwitchNodeType::InvalidChild) }
{    
	RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::SwitchNode
	::SetActiveChild(int activeChild)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(activeChild == System::EnumCastUnderlying(SwitchNodeType::InvalidChild) || activeChild < GetNumChildren(),"指定的活跃子节点无效\n");

	m_ActiveChild = activeChild;
}

int Rendering::SwitchNode
	::GetActiveChild() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_ActiveChild;
}

void Rendering::SwitchNode
	::DisableAllChildren() noexcept
{
	RENDERING_CLASS_IS_VALID_1;

	m_ActiveChild = System::EnumCastUnderlying(SwitchNodeType::InvalidChild);
}

int Rendering::SwitchNode
    ::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = ParentType::GetStreamingSize();
    
	size += CORE_TOOLS_STREAM_SIZE(m_ActiveChild);
    
	return size;
}

uint64_t Rendering::SwitchNode ::Register(CoreTools::ObjectRegister& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	return ParentType::Register(target);	
}

void Rendering::SwitchNode
    ::Save (CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	target.Write(m_ActiveChild);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::SwitchNode
    ::Link (CoreTools::ObjectLink& source)
{
	;
    
	ParentType::Link(source);
}

void Rendering::SwitchNode
    ::PostLink ()
{
	;
    
	ParentType::PostLink();
}

void Rendering::SwitchNode
    ::Load (CoreTools::BufferSource& source)
{
	;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	source.Read(m_ActiveChild);
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

const Rendering::PickRecordContainer Rendering::SwitchNode
	::ExecuteRecursive(const APoint& origin, const AVector& direction, float tMin, float tMax) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	PickRecordContainer container;

	const auto activeChild = GetActiveChild();
	if (activeChild != System::EnumCastUnderlying(SwitchNodeType::InvalidChild))
	{
		if (GetWorldBound().TestIntersection(origin, direction, tMin, tMax))
		{
			auto child = GetConstChild(activeChild);
			if (child)
			{
				auto childContainer = child->ExecuteRecursive(origin, direction, tMin, tMax);

				container.InsertPickRecord(childContainer);
			}
		}
	}

	return container;
}

CoreTools::ObjectInterface::ObjectInterfaceSharedPtr Rendering::SwitchNode::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

  #include STSTEM_WARNING_POP
