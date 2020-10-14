// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/23 14:18)

#include "Rendering/RenderingExport.h"

#include "TransformControllerImpl.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include STSTEM_WARNING_PUSH
 
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
Rendering::TransformControllerImpl
	::TransformControllerImpl(const FloatTransform& localTransform) noexcept
	: m_LocalTransform{ localTransform }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,TransformControllerImpl)

void Rendering::TransformControllerImpl ::SetTransform(const FloatTransform& localTransform) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	m_LocalTransform = localTransform;
}

const Rendering::FloatTransform Rendering::TransformControllerImpl ::GetTransform() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_LocalTransform;
}

int Rendering::TransformControllerImpl
	::GetStreamingSize() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return RENDERING_STREAM_SIZE(m_LocalTransform);
}

void Rendering::TransformControllerImpl
	::Save(const CoreTools::BufferTargetSharedPtr& target) const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	target->WriteAggregate(m_LocalTransform);
}

void Rendering::TransformControllerImpl
	::Load(const CoreTools::BufferSourceSharedPtr& source) 
{
	RENDERING_CLASS_IS_VALID_9;

	source->ReadAggregate(m_LocalTransform);
}

void Rendering::TransformControllerImpl
	::SetTranslate(const APoint& translate)
{
	RENDERING_CLASS_IS_VALID_9;

	m_LocalTransform.SetTranslate(translate);
}

void Rendering::TransformControllerImpl
	::SetRotate(const Matrix& rotate) 
{
	RENDERING_CLASS_IS_VALID_9;

	m_LocalTransform.SetRotate(rotate);
}

void Rendering::TransformControllerImpl
	::SetUniformScale(float scale) 
{
	RENDERING_CLASS_IS_VALID_9;

	m_LocalTransform.SetUniformScale(scale);
}

void Rendering::TransformControllerImpl
	::SetScale(const APoint& scale)
{
	RENDERING_CLASS_IS_VALID_9;

	m_LocalTransform.SetScale(scale);
}

void Rendering::TransformControllerImpl
	::SetMatrix(const Matrix& matrix)
{
	RENDERING_CLASS_IS_VALID_9;

	m_LocalTransform.SetMatrix(matrix);
}


#include STSTEM_WARNING_POP