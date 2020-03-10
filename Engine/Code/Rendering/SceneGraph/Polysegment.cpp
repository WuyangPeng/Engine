// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/22 18:02)

#include "Rendering/RenderingExport.h"

#include "Polysegment.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, Polysegment);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Polysegment);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Polysegment);

Rendering::Polysegment
	::Polysegment(const VertexFormatSmartPointer& vertexformat,const VertexBufferSmartPointer& vertexbuffer,bool contiguous) 
	:ParentType{ contiguous ? VisualPrimitiveType::PolysegmentsContiguous : VisualPrimitiveType::PolysegmentsDisjoint,vertexformat, vertexbuffer,IndexBufferSmartPointer() },
	 m_NumSegments{ 0 }, m_Contiguous{ contiguous }
{
	auto numVertices = vertexbuffer->GetNumElements();
	RENDERING_ASSERTION_1(2 <= numVertices,"Polysegments��������������\n");

	if (m_Contiguous)
	{
		m_NumSegments = numVertices - 1;
	}
	else
	{
		RENDERING_ASSERTION_1((numVertices & 1) == 0, "����Ƭ����Ҫż���Ķ���\n");

		m_NumSegments = numVertices / 2;
	}

	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Polysegment
	::~Polysegment() 
{
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
		auto numVerticesMinus1 = numVertices - 1;
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
		auto numVerticesDivide2 = numVertices / 2;
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
	::GetNumSegments() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_NumSegments;
}


bool Rendering::Polysegment
	::GetContiguous() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Contiguous;
}

Rendering::ControllerInterfaceSmartPointer Rendering::Polysegment
	::Clone() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ControllerInterfaceSmartPointer{ NEW0 ClassType(*this) };
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
    ::Register( CoreTools::ObjectRegister& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	return ParentType::Register(target);	 
}

void Rendering::Polysegment
    ::Save (CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	target.Write(m_NumSegments);
	target.WriteBool(m_Contiguous);
     
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Polysegment
    ::Link (CoreTools::ObjectLink& source)
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
    ::Load (CoreTools::BufferSource& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	source.Read(m_NumSegments);
	m_Contiguous = source.ReadBool();
        
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

 