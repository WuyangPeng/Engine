// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/23 17:29)

#include "Rendering/RenderingExport.h"

#include "LightConstantImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"

#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::vector;
using std::string;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26418)
Rendering::LightConstantImpl
	::LightConstantImpl(const LightSharedPtr& light)
	:m_Light{ light }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::LightConstantImpl
	::LightConstantImpl()
	:m_Light{}
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,LightConstantImpl)

const Rendering::ConstLightSharedPtr Rendering::LightConstantImpl
	::GetLight() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;	

	if (m_Light )
		return m_Light ;
	else
		return ConstLightSharedPtr{};
}

void Rendering::LightConstantImpl
	::Load(const CoreTools::BufferSourceSharedPtr& source)
{
	RENDERING_CLASS_IS_VALID_1;
    source;
    //	source.ReadSharedPtr(m_Light);
}

void Rendering::LightConstantImpl
	::Save(const CoreTools::BufferTargetSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    target;
	//target.WriteSharedPtr(m_Light);
}

int Rendering::LightConstantImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return CORE_TOOLS_STREAM_SIZE(m_Light);
}

const CoreTools::ObjectSharedPtr Rendering::LightConstantImpl
	::GetObjectByName(const string& name)
{
	RENDERING_CLASS_IS_VALID_1;

	if (m_Light )
		return m_Light->GetObjectByName(name);
	else
		return CoreTools::ObjectSharedPtr{};
}

const vector<CoreTools::ObjectSharedPtr> Rendering::LightConstantImpl
	::GetAllObjectsByName(const string& name)
{
	RENDERING_CLASS_IS_VALID_1;

	if (m_Light )
		return m_Light->GetAllObjectsByName(name);
	else
		return vector<CoreTools::ObjectSharedPtr>{};
}

const CoreTools::ConstObjectSharedPtr Rendering::LightConstantImpl
	::GetConstObjectByName(const string& name) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	if (m_Light )
		return m_Light->GetConstObjectByName(name);
	else
		return CoreTools::ConstObjectSharedPtr{};
}

const vector<CoreTools::ConstObjectSharedPtr> Rendering::LightConstantImpl
	::GetAllConstObjectsByName(const string& name) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	if (m_Light )
		return m_Light->GetAllConstObjectsByName(name);
	else
		return vector<CoreTools::ConstObjectSharedPtr>{};
}

void Rendering::LightConstantImpl ::Link(const CoreTools::ObjectLinkSharedPtr& source)
{
	RENDERING_CLASS_IS_VALID_1;
    source;
    //	source.ResolveObjectSharedPtrLink(m_Light);
}

void Rendering::LightConstantImpl ::Register(const CoreTools::ObjectRegisterSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    target;
    //	target.RegisterSharedPtr(m_Light);
}

#include STSTEM_WARNING_POP