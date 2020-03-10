// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 17:30)

#include "Rendering/RenderingExport.h"

#include "MaterialConstantImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::vector;
using std::string;

Rendering::MaterialConstantImpl
	::MaterialConstantImpl(const MaterialSmartPointer& material)
	:m_Material{ material }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::MaterialConstantImpl
	::MaterialConstantImpl()
	:m_Material{}
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,MaterialConstantImpl)

const Rendering::ConstMaterialSmartPointer Rendering::MaterialConstantImpl
	::GetMaterial() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;	

	if (m_Material.IsValidPtr())
		return m_Material.PolymorphicCastConstObjectSmartPointer<ConstMaterialSmartPointer>();
	else
		return ConstMaterialSmartPointer{};
}

void Rendering::MaterialConstantImpl
	::Load(BufferSource& source)
{
	RENDERING_CLASS_IS_VALID_1;

	source.ReadSmartPointer(m_Material);
}

void Rendering::MaterialConstantImpl
	::Save(BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	target.WriteSmartPointer(m_Material);
}

int Rendering::MaterialConstantImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return CORE_TOOLS_STREAM_SIZE(m_Material);
}

const CoreTools::ObjectSmartPointer Rendering::MaterialConstantImpl
	::GetObjectByName(const string& name)
{
	RENDERING_CLASS_IS_VALID_1;

	if (m_Material.IsValidPtr())
		return m_Material->GetObjectByName(name);
	else
		return CoreTools::ObjectSmartPointer{};
}

const vector<CoreTools::ObjectSmartPointer> Rendering::MaterialConstantImpl
	::GetAllObjectsByName(const string& name)
{
	RENDERING_CLASS_IS_VALID_1;

	if (m_Material.IsValidPtr())
		return m_Material->GetAllObjectsByName(name);
	else
		return vector<CoreTools::ObjectSmartPointer>{};
}

const CoreTools::ConstObjectSmartPointer Rendering::MaterialConstantImpl
	::GetConstObjectByName(const string& name) const 
{
	RENDERING_CLASS_IS_VALID_1;

	if (m_Material.IsValidPtr())
		return m_Material->GetConstObjectByName(name);
	else
		return CoreTools::ConstObjectSmartPointer{};
}

const vector<CoreTools::ConstObjectSmartPointer> Rendering::MaterialConstantImpl
	::GetAllConstObjectsByName(const string& name) const
{
	RENDERING_CLASS_IS_VALID_1;

	if (m_Material.IsValidPtr())
		return m_Material->GetAllConstObjectsByName(name);
	else
		return vector<CoreTools::ConstObjectSmartPointer>{};
}

void Rendering::MaterialConstantImpl
	::Link( ObjectLink& source )
{
	RENDERING_CLASS_IS_VALID_1;

	source.ResolveObjectSmartPointerLink(m_Material);
}

void Rendering::MaterialConstantImpl
	::Register( ObjectRegister& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	target.RegisterSmartPointer(m_Material);
}

