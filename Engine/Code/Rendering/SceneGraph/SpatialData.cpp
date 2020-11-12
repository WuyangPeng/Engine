// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/22 18:25)

#include "Rendering/RenderingExport.h"

#include "SpatialData.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
Rendering::SpatialData
   ::SpatialData ()
	: m_LocalTransform{},m_WorldTransform{},m_WorldTransformIsCurrent{ false },
	  m_WorldBound{}, m_WorldBoundIsCurrent{ false },m_Culling{ CullingMode::Dynamic }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,SpatialData)

void Rendering::SpatialData
    ::DirectSetWorldTransform(const FloatTransform& transform)
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_WorldTransform = transform;
    m_WorldTransformIsCurrent = true;
}

void Rendering::SpatialData
    ::DirectSetWorldBound(const Bound& bound)
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_WorldBound = bound;
    m_WorldBoundIsCurrent = true;
}

void Rendering::SpatialData
    ::SetLocalTransform(const FloatTransform& transform)
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_LocalTransform = transform;
    m_WorldTransformIsCurrent = false;	 
}
 
void Rendering::SpatialData
    ::SetCullingMode(CullingMode culling)
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_Culling = culling;
}

void Rendering::SpatialData
    ::SetLocalTransformToWorldTransform(const FloatTransform& worldTransform)
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_WorldTransform = worldTransform * m_LocalTransform;
    m_WorldTransformIsCurrent = false;
}

void Rendering::SpatialData
    ::SetLocalTransformToWorldTransform()
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_WorldTransform = m_LocalTransform;
    m_WorldTransformIsCurrent = false;
}

void Rendering::SpatialData
    ::InitWorldBound()
{
    RENDERING_CLASS_IS_VALID_9;
    
	m_WorldBound = Bound{ Mathematics::FloatAPoint::GetOrigin(), 0.0f };
    m_WorldBoundIsCurrent = false;
}

void Rendering::SpatialData
    ::SetWorldBound(const Bound& worldBound)
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_WorldBound.GrowToContain(worldBound);
    m_WorldBoundIsCurrent = false;
}

bool Rendering::SpatialData
    ::GetWorldTransformIsCurrent() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_WorldTransformIsCurrent;
}

bool Rendering::SpatialData
    ::GetWorldBoundIsCurrent() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_WorldBoundIsCurrent;
}

const Rendering::FloatTransform Rendering::SpatialData
    ::GetLocalTransform() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_LocalTransform;
}

const Rendering::FloatTransform Rendering::SpatialData
    ::GetWorldTransform() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_WorldTransform;
}

const Rendering::FloatBound Rendering::SpatialData
    ::GetWorldBound() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_WorldBound;
}

Rendering::CullingMode Rendering::SpatialData
     ::GetCullingMode() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_Culling;
}

void Rendering::SpatialData ::Load(const CoreTools::BufferSourceSharedPtr& source)
{
    source->ReadAggregate(m_LocalTransform);
    source->ReadAggregate(m_WorldTransform);
    m_WorldTransformIsCurrent = source->ReadBool();
    source->ReadAggregate(m_WorldBound);
    m_WorldBoundIsCurrent = source->ReadBool();
    source->ReadEnum(m_Culling);
}

void Rendering::SpatialData
    ::Save( const CoreTools::BufferTargetSharedPtr& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
    
    target->WriteAggregate(m_LocalTransform);
        target->WriteAggregate(m_WorldTransform);
    target->Write(m_WorldTransformIsCurrent);
        target->WriteAggregate(m_WorldBound);
    target->Write(m_WorldBoundIsCurrent);
        target->WriteEnum(m_Culling);
}

int Rendering::SpatialData
    ::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
    
	auto size = RENDERING_STREAM_SIZE(m_LocalTransform);
    size += RENDERING_STREAM_SIZE(m_WorldTransform);
    size += CORE_TOOLS_STREAM_SIZE(m_WorldTransformIsCurrent);
    size += RENDERING_STREAM_SIZE(m_WorldBound);
    size += CORE_TOOLS_STREAM_SIZE(m_WorldBoundIsCurrent);
    size += CORE_TOOLS_STREAM_SIZE(m_Culling);
    
    return size;
}

void Rendering::SpatialData
	::SetLocalTransformTranslate(const APoint& translate)
{
	RENDERING_CLASS_IS_VALID_9;

	m_LocalTransform.SetTranslate(translate);
}

void Rendering::SpatialData
	::SetLocalTransformRotate(const Matrix& rotate) 
{
	RENDERING_CLASS_IS_VALID_9;

	m_LocalTransform.SetRotate(rotate);
}

void Rendering::SpatialData
	::SetWorldTransformOnUpdate( const FloatTransform& transform )
{
	RENDERING_CLASS_IS_VALID_9;

	m_WorldTransform = transform;
}

#include STSTEM_WARNING_POP