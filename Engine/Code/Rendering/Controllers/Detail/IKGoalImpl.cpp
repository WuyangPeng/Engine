// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/23 13:46)

#include "Rendering/RenderingExport.h"

#include "IKGoalImpl.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ClassInvariant/Noexcept.h"

using std::string;
using std::vector;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26415)
Rendering::IKGoalImpl
	::IKGoalImpl(const SpatialSmartPointer& target,const SpatialSmartPointer& effector,float weight) noexcept
	:m_Target{ target }, m_Effector{ effector }, m_Weight{ weight }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::IKGoalImpl ::IKGoalImpl() noexcept
    : m_Target{}, m_Effector{}, m_Weight{ 1.0f }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
CLASS_INVARIANT_STUB_DEFINE(Rendering,IKGoalImpl)
#endif // OPEN_CLASS_INVARIANT	

int Rendering::IKGoalImpl ::GetStreamingSize() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto size = CORE_TOOLS_STREAM_SIZE(m_Weight);
	size += CORE_TOOLS_STREAM_SIZE(m_Target);
	size += CORE_TOOLS_STREAM_SIZE(m_Effector);

	return size;
}

void Rendering::IKGoalImpl
	::Save(const CoreTools::BufferTargetSharedPtr& target) const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	target->Write(m_Weight);
	//target.WriteSmartPointer(m_Target);
	//target.WriteSmartPointer(m_Effector);
}

void Rendering::IKGoalImpl
	::Load(CoreTools::BufferSource& source)
{
	RENDERING_CLASS_IS_VALID_9;

	source.Read(m_Weight);
	//source.ReadSmartPointer(m_Target);
	//source.ReadSmartPointer(m_Effector);
}

void Rendering::IKGoalImpl
	::Link(CoreTools::ObjectLink& source)
{
	RENDERING_CLASS_IS_VALID_9;	
	CoreTools::DoNothing();
	source;
	//source.ResolveObjectSmartPointerLink(m_Target);
	//source.ResolveObjectSmartPointerLink(m_Effector);
}

void Rendering::IKGoalImpl
	::Register(const CoreTools::ObjectRegisterSharedPtr& target) const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;
    target;
    CoreTools::DoNothing();
	//target.RegisterSmartPointer(m_Target);
	//target.RegisterSmartPointer(m_Effector);
}

const Rendering::ConstSpatialSmartPointer Rendering::IKGoalImpl
	::GetTarget() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Target;
}

const Rendering::ConstSpatialSmartPointer Rendering::IKGoalImpl ::GetEffector() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Effector;
}

const Rendering::IKGoalImpl::APoint Rendering::IKGoalImpl
	::GetTargetPosition() const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Target->GetWorldTransform().GetTranslate();
}

const Rendering::IKGoalImpl::APoint Rendering::IKGoalImpl
	::GetEffectorPosition() const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Effector->GetWorldTransform().GetTranslate();
}

void Rendering::IKGoalImpl ::SetWeight(float weight) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	m_Weight = weight;
}

float Rendering::IKGoalImpl ::GetWeight() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Weight;
}

const CoreTools::ObjectSmartPointer Rendering::IKGoalImpl
	::GetObjectByName(const string& name) 
{
	RENDERING_CLASS_IS_VALID_9;

	auto targetObject = m_Target->GetObjectByName(name);

	if (targetObject != nullptr)
	{
		return targetObject;
	}		
	else
	{
		auto effectorObject = m_Effector->GetObjectByName(name);
		if (effectorObject != nullptr)
			return effectorObject;
		else
			return CoreTools::ObjectSmartPointer{};
	}		
}

const vector<CoreTools::ObjectSmartPointer> Rendering::IKGoalImpl
	::GetAllObjectsByName(const string& name)
{
	RENDERING_CLASS_IS_VALID_9;

	auto objects = m_Target->GetAllObjectsByName(name);
	auto effectorObject = m_Effector->GetAllObjectsByName(name);

	objects.insert(objects.end(), effectorObject.begin(), effectorObject.end());

	return objects;
}

const CoreTools::ConstObjectSmartPointer Rendering::IKGoalImpl
	::GetConstObjectByName(const string& name) const 
{
	RENDERING_CLASS_IS_VALID_9;

	auto targetObject = m_Target->GetConstObjectByName(name);

	if (targetObject != nullptr)
	{
		return targetObject;
	}		
	else
	{
		auto effectorObject = m_Effector->GetConstObjectByName(name);
		if (effectorObject != nullptr)
			return effectorObject;
		else
			return CoreTools::ConstObjectSmartPointer{};
	}		
}

const vector<CoreTools::ConstObjectSmartPointer> Rendering::IKGoalImpl
	::GetAllConstObjectsByName(const string& name) const
{
	RENDERING_CLASS_IS_VALID_9;

	auto objects = m_Target->GetAllConstObjectsByName(name);
	auto effectorObject = m_Effector->GetAllConstObjectsByName(name);

	objects.insert(objects.end(), effectorObject.begin(), effectorObject.end());

	return objects;
}
#include STSTEM_WARNING_POP