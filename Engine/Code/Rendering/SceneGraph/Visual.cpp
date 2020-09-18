// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 18:40)

#include "Rendering/RenderingExport.h"

#include "Visual.h"
#include "Detail/VisualImpl.h"
#include "Culler.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::string;
using std::vector;
using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering, Visual);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Visual);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, Visual);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, Visual);

Rendering::Visual
    ::Visual(VisualPrimitiveType type)
	:ParentType{}, m_Impl{ make_shared<ImplType>(type) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Visual
	::Visual(VisualPrimitiveType type, const VertexFormatSmartPointer& vertexformat, const VertexBufferSmartPointer& vertexbuffer,const IndexBufferSmartPointer& indexbuffer)
	:ParentType{}, m_Impl{ make_shared<ImplType>(type, vertexformat, vertexbuffer, indexbuffer) }
{
	UpdateModelSpace(VisualUpdateType::ModelBoundOnly);

	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Visual
	::~Visual()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Visual
	::Visual(const Visual& rhs)
	:ParentType(rhs), m_Impl{ make_shared<ImplType>(rhs.GetPrimitiveType()) }
{
	CloneData(rhs);

	UpdateModelSpace(VisualUpdateType::ModelBoundOnly);

	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Visual& Rendering::Visual
	::operator =(const Visual& rhs)
{
	RENDERING_CLASS_IS_VALID_1;

	ParentType::operator =(rhs);

	m_Impl = make_shared<ImplType>(rhs.GetPrimitiveType());

	CloneData(rhs);

	UpdateModelSpace(VisualUpdateType::ModelBoundOnly);

	return *this;
}

// private
void Rendering::Visual
	::CloneData( const Visual& rhs )
{
	CloneVertexFormat(rhs);
	CloneVertexBuffer(rhs);
	CloneIndexBuffer(rhs);
}

// private
void Rendering::Visual
	::CloneVertexFormat( const Visual &rhs )
{
	auto vertexFormat = rhs.GetConstVertexFormat();	

	if(vertexFormat)
		SetVertexFormat(vertexFormat->Clone());
	else
		SetVertexFormat(VertexFormatSmartPointer{});
}

// private
void Rendering::Visual
	::CloneVertexBuffer( const Visual &rhs )
{
	auto vertexBuffer = rhs.GetConstVertexBuffer();

	if(vertexBuffer)
		SetVertexBuffer(vertexBuffer->Clone());
	else
		SetVertexBuffer(VertexBufferSmartPointer{});
}

// private
void Rendering::Visual
	::CloneIndexBuffer( const Visual &rhs )
{
	auto indexBuffer = rhs.GetConstIndexBuffer();

	if(indexBuffer)
		SetIndexBuffer(indexBuffer->Clone());
	else
		SetIndexBuffer(IndexBufferSmartPointer{});
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, Visual) 

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Visual,GetPrimitiveType,Rendering::VisualPrimitiveType)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Visual,GetConstVertexFormat,Rendering::ConstVertexFormatSmartPointer)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Visual,GetVertexFormat,Rendering::VertexFormatSmartPointer)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Visual,SetVertexFormat,VertexFormatSmartPointer,void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Visual, GetConstVertexBuffer,Rendering::ConstVertexBufferSmartPointer)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Visual,GetVertexBuffer,Rendering::VertexBufferSmartPointer)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Visual,SetVertexBuffer,VertexBufferSmartPointer,void)
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Visual,GetConstIndexBuffer,Rendering::ConstIndexBufferSmartPointer)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Visual,GetIndexBuffer,Rendering::IndexBufferSmartPointer)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Visual,SetIndexBuffer,IndexBufferSmartPointer,void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Visual, GetConstEffectInstance,const Rendering::ConstVisualEffectInstanceSmartPointer)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, Visual, SetEffectInstance, VisualEffectInstanceSmartPointer, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Visual, GetEffectInstance, const Rendering::VisualEffectInstanceSmartPointer)
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Visual, GetModelBound, const Rendering::FloatBound&)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Visual, GetModelBound, Rendering::FloatBound&)

void Rendering::Visual
	::UpdateModelSpace(VisualUpdateType type)
{
	UpdateModelBound();

	SYSTEM_UNUSED_ARG(type);
}  

void Rendering::Visual
	::UpdateWorldBound()
{	
	auto worldTransform = GetWorldTransform();
    const auto worldBound = m_Impl->GetWorldBound(worldTransform);

	BoundGrowToContain(worldBound);
}

void Rendering::Visual
	::UpdateModelBound()
{
	m_Impl->UpdateModelBound();
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Visual,ComputeBounding, vector<APoint>,void)

void Rendering::Visual
	::GetVisibleSet(Culler& culler, bool noCull)
{		 
	if (SMART_POINTER_SINGLETON.IsSmartPointer(this))
	{
		culler.Insert(VisualSmartPointer{ this });
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("子类智能指针不存在。"s));
	}

	SYSTEM_UNUSED_ARG(noCull);
}

Rendering::ConstVisualSmartPointer Rendering::Visual
	::GetSmartPointer() const
{
	if (SMART_POINTER_SINGLETON.IsSmartPointer(this))
	{
		return ConstVisualSmartPointer{ this };
	}		
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("子类智能指针不存在。"s));
	}		
}

Rendering::Visual
	::Visual(LoadConstructor value)
	:ParentType{ value }, m_Impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Visual
    ::GetStreamingSize () const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    auto size = ParentType::GetStreamingSize();
    
    size += m_Impl->GetStreamingSize();  
    
    return size;
}

uint64_t Rendering::Visual
    ::Register( const CoreTools::ObjectRegisterSharedPtr& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
const	auto uniqueID = ParentType::Register(target);
    
	if (uniqueID != 0)
	{
		m_Impl->Register(target);
	}

    return uniqueID;
}

void Rendering::Visual
    ::Save (const CoreTools::BufferTargetSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	m_Impl->Save(target);    
     
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Visual
    ::Link (CoreTools::ObjectLink& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	ParentType::Link(source);
    
	m_Impl->Link(source);
}

void Rendering::Visual
    ::PostLink ()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	ParentType::PostLink();     
}

void Rendering::Visual
    ::Load (CoreTools::BufferSource& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	m_Impl->Load(source);
        
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}


#include STSTEM_WARNING_POP