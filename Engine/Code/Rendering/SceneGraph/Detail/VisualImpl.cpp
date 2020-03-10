// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 17:02)

#include "Rendering/RenderingExport.h"

#include "VisualImpl.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/Shaders/VisualEffectInstance.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"

using std::string;
using std::vector;

Rendering::VisualImpl
    ::VisualImpl(VisualPrimitiveType type)
	:m_VisualData{ type }, m_ModelBound{}, m_Effect{}
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualImpl
	::VisualImpl(VisualPrimitiveType type,const VertexFormatSmartPointer& vertexformat,const VertexBufferSmartPointer& vertexbuffer,const IndexBufferSmartPointer& indexbuffer)
	:m_VisualData{ type,vertexformat,vertexbuffer,indexbuffer }, m_ModelBound{}, m_Effect{}
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VisualImpl)

Rendering::VisualPrimitiveType 
    Rendering::VisualImpl::GetPrimitiveType() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_VisualData.GetPrimitiveType();
}

Rendering::ConstVertexFormatSmartPointer 
	Rendering::VisualImpl::GetConstVertexFormat() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_VisualData.GetConstVertexFormat();
}

const Rendering::ConstVisualEffectInstanceSmartPointer Rendering::VisualImpl
	::GetEffectInstance() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Effect.GetConstSmartPointer();
}

void Rendering::VisualImpl
	::SetEffectInstance(const VisualEffectInstanceSmartPointer& effect)
{
	RENDERING_CLASS_IS_VALID_9;

	m_Effect = effect;
}

Rendering::Bound& Rendering::VisualImpl
	::GetModelBound() 
{
	RENDERING_CLASS_IS_VALID_9;

	return const_cast<Bound&>(static_cast<const ClassType*>(this)->GetModelBound());
}

const Rendering::Bound& Rendering::VisualImpl
	::GetModelBound() const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_ModelBound;
}

Rendering::IndexBufferSmartPointer
	Rendering::VisualImpl
	::GetIndexBuffer()
{
	RENDERING_CLASS_IS_VALID_9;

	return m_VisualData.GetIndexBuffer();
}

Rendering::VertexBufferSmartPointer
	Rendering::VisualImpl
	::GetVertexBuffer()
{
	RENDERING_CLASS_IS_VALID_9;

	return m_VisualData.GetVertexBuffer();
}

Rendering::ConstIndexBufferSmartPointer 
	Rendering::VisualImpl
	::GetConstIndexBuffer() const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_VisualData.GetConstIndexBuffer();
}

void Rendering::VisualImpl
	::SetIndexBuffer(const IndexBufferSmartPointer& indexbuffer)
{
	RENDERING_CLASS_IS_VALID_9;

	m_VisualData.SetIndexBuffer(indexbuffer);
}

Rendering::ConstVertexBufferSmartPointer
	Rendering::VisualImpl
	::GetConstVertexBuffer() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_VisualData.GetConstVertexBuffer();

}

void Rendering::VisualImpl
	::SetVertexBuffer(const VertexBufferSmartPointer& vertexbuffer) 
{
	RENDERING_CLASS_IS_VALID_9;

	m_VisualData.SetVertexBuffer(vertexbuffer);
}

Rendering::VertexFormatSmartPointer	Rendering::VisualImpl
	::GetVertexFormat() 
{
	RENDERING_CLASS_IS_VALID_9;

	return m_VisualData.GetVertexFormat();
}

void Rendering::VisualImpl
	::SetVertexFormat(const VertexFormatSmartPointer& vertexformat)
{
	RENDERING_CLASS_IS_VALID_9;

	m_VisualData.SetVertexFormat(vertexformat);
}

const Rendering::Bound 
	Rendering::VisualImpl
	::GetWorldBound( const Transform& worldTransform )
{
	RENDERING_CLASS_IS_VALID_9;

	return m_ModelBound.TransformBy(worldTransform);
}

void Rendering::VisualImpl
	::UpdateModelBound() 
{
	RENDERING_CLASS_IS_VALID_9;

	if (m_VisualData.IsVertexSmartPointerValid())
	{
		DoUpdateModelBound();
	}	
}

void Rendering::VisualImpl
	::ComputeBounding(const vector<APoint>& positions)
{
	RENDERING_CLASS_IS_VALID_9;

	m_ModelBound.ComputeFromData(positions);
}

void Rendering::VisualImpl
	::DoUpdateModelBound()
{
	auto numVertices = m_VisualData.GetVertexBufferNumElements();
	auto stride = m_VisualData.GetVertexFormatStride();
	auto data = m_VisualData.GetVertexBufferReadOnlyData();
	auto positionOffset = m_VisualData.GetPositionOffset();

	m_ModelBound.ComputeFromData(numVertices, stride, data + positionOffset);
}

void Rendering::VisualImpl
	::Load(BufferSource& source)
{
	RENDERING_CLASS_IS_VALID_9;

	m_VisualData.Load(source);
	source.ReadAggregate(m_ModelBound);
	source.ReadSmartPointer(m_Effect);
}

void Rendering::VisualImpl
	::Save(BufferTarget& target) const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	m_VisualData.Save(target);
	target.WriteAggregate(m_ModelBound); 
	target.WriteSmartPointer(m_Effect);
}

int Rendering::VisualImpl
	::GetStreamingSize() const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto size = m_VisualData.GetStreamingSize();

	size += RENDERING_STREAM_SIZE(m_ModelBound); 
	size += CORE_TOOLS_STREAM_SIZE(m_Effect);

	return size;
}

void Rendering::VisualImpl
	::Register(ObjectRegister& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	m_VisualData.Register(target);
	target.RegisterSmartPointer(m_Effect);
}

void Rendering::VisualImpl
	::Link(ObjectLink& source)
{
	RENDERING_CLASS_IS_VALID_9;	

	m_VisualData.Link(source);
	source.ResolveObjectSmartPointerLink(m_Effect);
}

const CoreTools::ObjectSmartPointer Rendering::VisualImpl
	::GetObjectByName(const string& name) 
{
	RENDERING_CLASS_IS_VALID_9;

	auto object = m_VisualData.GetObjectByName(name);
	if (object != nullptr)
		return object;	 

	object = m_Effect->GetObjectByName(name);
	if (object != nullptr)
		return object;
	else
		return CoreTools::ObjectSmartPointer{};
}

const vector<CoreTools::ObjectSmartPointer> Rendering::VisualImpl
	::GetAllObjectsByName(const string& name)
{
	RENDERING_CLASS_IS_VALID_9;

	auto visualDataObjects = m_VisualData.GetAllObjectsByName(name);
	auto effectObjects = m_Effect->GetAllObjectsByName(name);

	vector<CoreTools::ObjectSmartPointer> entirelyObjects;

	entirelyObjects.insert(entirelyObjects.end(),visualDataObjects.begin(),visualDataObjects.end());	 

	entirelyObjects.insert(entirelyObjects.end(),effectObjects.begin(), effectObjects.end());

	return entirelyObjects;
}

const CoreTools::ConstObjectSmartPointer Rendering::VisualImpl
	::GetConstObjectByName(const string& name) const 
{
	RENDERING_CLASS_IS_VALID_9;

	auto object = m_VisualData.GetConstObjectByName(name);
	if (object != nullptr)
		return object;	 

	object = m_Effect->GetConstObjectByName(name);
	if (object != nullptr)
		return object;
	else
		return CoreTools::ConstObjectSmartPointer{};
}

const vector<CoreTools::ConstObjectSmartPointer> Rendering::VisualImpl
	::GetAllConstObjectsByName(const string& name) const
{
	RENDERING_CLASS_IS_VALID_9;

	auto visualDataObjects = m_VisualData.GetAllConstObjectsByName(name);
	auto effectObjects = m_Effect->GetAllConstObjectsByName(name);

	vector<CoreTools::ConstObjectSmartPointer> entirelyObjects;

	entirelyObjects.insert(entirelyObjects.end(),visualDataObjects.begin(),visualDataObjects.end());	 

	entirelyObjects.insert(entirelyObjects.end(),effectObjects.begin(),effectObjects.end());

	return entirelyObjects;
}

