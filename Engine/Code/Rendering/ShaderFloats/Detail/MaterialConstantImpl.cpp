// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/23 17:30)

#include "Rendering/RenderingExport.h"

#include "MaterialConstantImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"

#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::vector;
using std::string;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26418)
Rendering::MaterialConstantImpl
	::MaterialConstantImpl(const MaterialSharedPtr& material) noexcept
	:m_Material{ material }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::MaterialConstantImpl ::MaterialConstantImpl() noexcept
    : m_Material{}
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,MaterialConstantImpl)

const Rendering::ConstMaterialSharedPtr Rendering::MaterialConstantImpl
	::GetMaterial() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;	

	if (m_Material )
		return m_Material ;
	else
		return ConstMaterialSharedPtr{};
}

void Rendering::MaterialConstantImpl ::Load(CoreTools::BufferSource& source)
{
	RENDERING_CLASS_IS_VALID_1;
    source;
	//source.ReadSharedPtr(m_Material);
}

void Rendering::MaterialConstantImpl
	::Save(CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    target;
	//target.WriteSharedPtr(m_Material);
}

int Rendering::MaterialConstantImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return CORE_TOOLS_STREAM_SIZE(m_Material);
}

const CoreTools::ObjectSharedPtr Rendering::MaterialConstantImpl
	::GetObjectByName(const string& name)
{
	RENDERING_CLASS_IS_VALID_1;

	if (m_Material )
		return m_Material->GetObjectByName(name);
	else
		return CoreTools::ObjectSharedPtr{};
}

const vector<CoreTools::ObjectSharedPtr> Rendering::MaterialConstantImpl
	::GetAllObjectsByName(const string& name)
{
	RENDERING_CLASS_IS_VALID_1;

	if (m_Material )
		return m_Material->GetAllObjectsByName(name);
	else
		return vector<CoreTools::ObjectSharedPtr>{};
}

const CoreTools::ConstObjectSharedPtr Rendering::MaterialConstantImpl
	::GetConstObjectByName(const string& name) const 
{
	RENDERING_CLASS_IS_VALID_1;

	if (m_Material )
		return m_Material->GetConstObjectByName(name);
	else
		return CoreTools::ConstObjectSharedPtr{};
}

const vector<CoreTools::ConstObjectSharedPtr> Rendering::MaterialConstantImpl
	::GetAllConstObjectsByName(const string& name) const
{
	RENDERING_CLASS_IS_VALID_1;

	if (m_Material )
		return m_Material->GetAllConstObjectsByName(name);
	else
		return vector<CoreTools::ConstObjectSharedPtr>{};
}

void Rendering::MaterialConstantImpl ::Link(CoreTools::ObjectLink& source)
{
	RENDERING_CLASS_IS_VALID_1;
    source;
	//source.ResolveObjectSharedPtrLink(m_Material);
}

void Rendering::MaterialConstantImpl ::Register(CoreTools::ObjectRegister& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    target;
	//target.RegisterSharedPtr(m_Material);
}

#include STSTEM_WARNING_POP