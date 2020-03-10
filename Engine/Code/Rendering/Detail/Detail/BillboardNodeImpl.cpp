// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 10:34)

#include "Rendering/RenderingExport.h"

#include "BillboardNodeImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
using std::vector;

Rendering::BillboardNodeImpl
	::BillboardNodeImpl()
	:m_Camera{}
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}


Rendering::BillboardNodeImpl
	::BillboardNodeImpl(const CameraSmartPointer& camera)
	:m_Camera{ camera }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}
 
CLASS_INVARIANT_STUB_DEFINE(Rendering, BillboardNodeImpl)

int Rendering::BillboardNodeImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto size = CORE_TOOLS_STREAM_SIZE(m_Camera); 

	return size;
}

void Rendering::BillboardNodeImpl
	::Save(CoreTools::BufferTarget& target) const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	
	target.WriteSmartPointer(m_Camera); 
}

void Rendering::BillboardNodeImpl
	::Load(CoreTools::BufferSource& source)
{
	RENDERING_CLASS_IS_VALID_9;
	
	source.ReadSmartPointer(m_Camera); 
}

void Rendering::BillboardNodeImpl
	::Link(CoreTools::ObjectLink& source)
{
	RENDERING_CLASS_IS_VALID_9;	 

	source.ResolveObjectSmartPointerLink(m_Camera); 
}

void Rendering::BillboardNodeImpl
	::Register(CoreTools::ObjectRegister& target) const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	target.RegisterSmartPointer(m_Camera); 
}

const CoreTools::ConstObjectSmartPointer Rendering::BillboardNodeImpl
	::GetConstObjectByName(const string& name) const
{
	RENDERING_CLASS_IS_VALID_9;

	return m_Camera->GetConstObjectByName(name);	
}

const vector<CoreTools::ConstObjectSmartPointer> Rendering::BillboardNodeImpl
	::GetAllConstObjectsByName(const string& name) const
{
	RENDERING_CLASS_IS_VALID_9;

	return m_Camera->GetAllConstObjectsByName(name); 
}

const CoreTools::ObjectSmartPointer Rendering::BillboardNodeImpl
	::GetObjectByName(const string& name)
{
	RENDERING_CLASS_IS_VALID_9;

	return m_Camera->GetObjectByName(name);	
}

const vector<CoreTools::ObjectSmartPointer> Rendering::BillboardNodeImpl
	::GetAllObjectsByName(const string& name)
{
	RENDERING_CLASS_IS_VALID_9;

	return m_Camera->GetAllObjectsByName(name); 
}

void Rendering::BillboardNodeImpl
	::AlignTo(const CameraSmartPointer& camera)
{
	RENDERING_CLASS_IS_VALID_9;

	m_Camera = camera;
}

const Rendering::ConstCameraSmartPointer Rendering::BillboardNodeImpl
	::GetCamera() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Camera.PolymorphicCastConstObjectSmartPointer<ConstCameraSmartPointer>();
}


 