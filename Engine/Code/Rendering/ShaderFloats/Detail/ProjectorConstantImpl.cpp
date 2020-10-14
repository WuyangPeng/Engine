// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/23 17:31)


#include "Rendering/RenderingExport.h"

#include "ProjectorConstantImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"

#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::vector;
using std::string;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26440)
Rendering::ProjectorConstantImpl
	::ProjectorConstantImpl(const ProjectorSharedPtr& projector)
	:m_Projector{ projector }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ProjectorConstantImpl
	::ProjectorConstantImpl()
	:m_Projector{}
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ProjectorConstantImpl
	::~ProjectorConstantImpl()
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,ProjectorConstantImpl)

const Rendering::ConstProjectorSharedPtr Rendering::ProjectorConstantImpl
	::GetProjector() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;	

	if (m_Projector )
		return m_Projector ;
	else
		return ConstProjectorSharedPtr{};
}

void Rendering::ProjectorConstantImpl ::Load(const CoreTools::BufferSourceSharedPtr& source)
{
	RENDERING_CLASS_IS_VALID_9;
    source;
	//source.ReadSharedPtr(m_Projector);
}

void Rendering::ProjectorConstantImpl
	::Save(const CoreTools::BufferTargetSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
    target;
	//target.WriteSharedPtr(m_Projector);
}

int Rendering::ProjectorConstantImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return CORE_TOOLS_STREAM_SIZE(m_Projector);
}

const CoreTools::ObjectSharedPtr Rendering::ProjectorConstantImpl
	::GetObjectByName(const string& name)
{
	RENDERING_CLASS_IS_VALID_9;

	if (m_Projector )
		return m_Projector->GetObjectByName(name);
	else
		return CoreTools::ObjectSharedPtr{};
}

const vector<CoreTools::ObjectSharedPtr> Rendering::ProjectorConstantImpl
	::GetAllObjectsByName(const string& name)
{
	RENDERING_CLASS_IS_VALID_9;

	if (m_Projector )
		return m_Projector->GetAllObjectsByName(name);
	else
		return vector<CoreTools::ObjectSharedPtr>{};
}

const CoreTools::ConstObjectSharedPtr Rendering::ProjectorConstantImpl
	::GetConstObjectByName(const string& name) const
{
	RENDERING_CLASS_IS_VALID_9;

	if (m_Projector )
		return m_Projector->GetConstObjectByName(name);
	else
		return CoreTools::ConstObjectSharedPtr{};
}

const vector<CoreTools::ConstObjectSharedPtr> Rendering::ProjectorConstantImpl
	::GetAllConstObjectsByName(const string& name) const
{
	RENDERING_CLASS_IS_VALID_9;

	if (m_Projector )
		return m_Projector->GetAllConstObjectsByName(name);
	else
		return vector<CoreTools::ConstObjectSharedPtr>{};
}

void Rendering::ProjectorConstantImpl ::Link(const CoreTools::ObjectLinkSharedPtr& source)
{
	RENDERING_CLASS_IS_VALID_9;
    source;
	//source.ResolveObjectSharedPtrLink(m_Projector);
}

void Rendering::ProjectorConstantImpl ::Register(const CoreTools::ObjectRegisterSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
    target;
	//target.RegisterSharedPtr(m_Projector);
}


#include STSTEM_WARNING_POP