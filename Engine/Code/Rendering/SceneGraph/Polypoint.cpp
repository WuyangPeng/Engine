// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/22 17:56)

#include "Rendering/RenderingExport.h"

#include "Polypoint.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
CORE_TOOLS_RTTI_DEFINE(Rendering, Polypoint);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Polypoint);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Polypoint);

Rendering::Polypoint
	::Polypoint(const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer)
	:ParentType{ VisualPrimitiveType::Polypoint,vertexformat, vertexbuffer,IndexBufferSharedPtr() }, m_NumPoints{ vertexbuffer->GetNumElements() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

 

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::Polypoint
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && 0 <= m_NumPoints)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

int Rendering::Polypoint
	::GetMaxNumPoints() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return GetConstVertexBuffer()->GetNumElements();
}

void Rendering::Polypoint
	::SetNumPoints(int numPoints)
{
	;

const	auto numVertices = GetMaxNumPoints();
    if (0 <= numPoints && numPoints <= numVertices)
    {
        m_NumPoints = numPoints;
    }
    else
    {
		m_NumPoints = numVertices;
    }
}

int Rendering::Polypoint
	::GetNumPoints() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_NumPoints;
}
 
Rendering::Polypoint
	::Polypoint(LoadConstructor value)
	:ParentType{ value }, m_NumPoints{ 0 }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Polypoint
    ::GetStreamingSize () const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    auto size = ParentType::GetStreamingSize();
    
	size += CORE_TOOLS_STREAM_SIZE(m_NumPoints);

	return size;
}

uint64_t Rendering::Polypoint
    ::Register( CoreTools::ObjectRegister& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	return ParentType::Register(target);	 
}

void Rendering::Polypoint
    ::Save (CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	target.Write(m_NumPoints);
     
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Polypoint
    ::Link (CoreTools::ObjectLink& source)
{
	;
    
	ParentType::Link(source);	
}

void Rendering::Polypoint
    ::PostLink ()
{
	;
    
	ParentType::PostLink();     
}

void Rendering::Polypoint
    ::Load (CoreTools::BufferSource& source)
{
	;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	source.Read(m_NumPoints);
        
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::ControllerInterfaceSharedPtr Rendering::Polypoint
	::Clone() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ControllerInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

CoreTools::ObjectInterfaceSharedPtr Rendering::Polypoint::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP