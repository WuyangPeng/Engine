// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 18:02)

#include "Rendering/RenderingExport.h"

#include "Polysegment.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)

CORE_TOOLS_RTTI_DEFINE(Rendering, Polysegment);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Polysegment);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Polysegment);

Rendering::Polysegment
	::Polysegment(const VertexFormatSharedPtr& vertexformat,const VertexBufferSharedPtr& vertexbuffer,bool contiguous) 
	:ParentType{ contiguous ? VisualPrimitiveType::PolysegmentsContiguous : VisualPrimitiveType::PolysegmentsDisjoint,vertexformat, vertexbuffer,IndexBufferSharedPtr() },
	 m_NumSegments{ 0 }, m_Contiguous{ contiguous }
{
    const auto numVertices = vertexbuffer->GetNumElements();
	RENDERING_ASSERTION_1(2 <= numVertices,"Polysegments必须至少有两点\n");

	if (m_Contiguous)
	{
		m_NumSegments = numVertices - 1;
	}
	else
	{
		RENDERING_ASSERTION_1((numVertices & 1) == 0, "分离片段需要偶数的顶点\n");

		m_NumSegments = numVertices / 2;
	}

	RENDERING_SELF_CLASS_IS_VALID_1;

	 
}

   

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::Polysegment
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && 0 <= m_NumSegments)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT


int Rendering::Polysegment
	::GetMaxNumSegments() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto numVertices = GetConstVertexBuffer()->GetNumElements();
	return m_Contiguous ? numVertices - 1 : numVertices / 2;
}

void Rendering::Polysegment
	::SetNumSegments(int numSegments)
{
	RENDERING_CLASS_IS_VALID_1;

	auto numVertices = GetConstVertexBuffer()->GetNumElements();
	if (m_Contiguous)
	{
            const auto numVerticesMinus1 = numVertices - 1;
		if (0 <= numSegments && numSegments <= numVerticesMinus1)
		{
			m_NumSegments = numSegments;
		}
		else
		{
			m_NumSegments = numVerticesMinus1;
		}
	}
	else
	{
            const auto numVerticesDivide2 = numVertices / 2;
		if (0 <= numSegments && numSegments <= numVerticesDivide2)
		{
			m_NumSegments = numSegments;
		}
		else
		{
			m_NumSegments = numVerticesDivide2;
		}
	}
}

int Rendering::Polysegment
	::GetNumSegments() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_NumSegments;
}


bool Rendering::Polysegment ::GetContiguous() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Contiguous;
}

Rendering::ControllerInterfaceSharedPtr Rendering::Polysegment
	::Clone() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ControllerInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

Rendering::Polysegment
	::Polysegment(LoadConstructor value)
	:ParentType{ value },m_NumSegments{ 0 },m_Contiguous{ false }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Polysegment
    ::GetStreamingSize () const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = ParentType::GetStreamingSize();
    
	size += CORE_TOOLS_STREAM_SIZE(m_NumSegments);
	size += CORE_TOOLS_STREAM_SIZE(m_Contiguous);

	return size;
}

uint64_t Rendering::Polysegment
    ::Register( const CoreTools::ObjectRegisterSharedPtr& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	return ParentType::Register(target);	 
}

void Rendering::Polysegment
    ::Save (const CoreTools::BufferTargetSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	target->Write(m_NumSegments);
	target->Write(m_Contiguous);
     
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Polysegment
    ::Link (const CoreTools::ObjectLinkSharedPtr& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	ParentType::Link(source);	
}

void Rendering::Polysegment
    ::PostLink ()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	ParentType::PostLink();     
}

void Rendering::Polysegment
    ::Load (const CoreTools::BufferSourceSharedPtr& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	source->Read(m_NumSegments);
	m_Contiguous = source->ReadBool();
        
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::Polysegment::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

 #include STSTEM_WARNING_POP