// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/25 16:06)

#include "Rendering/RenderingExport.h"

#include "Float2ArrayImpl.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26415)
Rendering::Float2ArrayImpl
	::Float2ArrayImpl( const Float2Vector& elements )
	:m_Elements{ elements }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Float2ArrayImpl
	::Float2ArrayImpl() noexcept
	:m_Elements{}
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, Float2ArrayImpl) 

void Rendering::Float2ArrayImpl ::Load(const CoreTools::BufferSourceSharedPtr& source)
{
	RENDERING_CLASS_IS_VALID_9;

	source->ReadAggregateContainer(m_Elements);
}

void Rendering::Float2ArrayImpl
	::Save( const CoreTools::BufferTargetSharedPtr& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	
	target->WriteAggregateContainerWithNumber(m_Elements);	
}

int Rendering::Float2ArrayImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	
	return MATHEMATICS_STREAM_SIZE(m_Elements);
}

int Rendering::Float2ArrayImpl
	::GetNumElements() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_Elements.size());
}

const Rendering::Float2ArrayImpl::Float2* Rendering::Float2ArrayImpl
	::GetData() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return &m_Elements[0];
}

const Rendering::Float2ArrayImpl::Float2& Rendering::Float2ArrayImpl
	::operator[]( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Elements.size()), "ÎÞÐ§Ë÷Òý£¡\n");

	return m_Elements[index];
}

Rendering::Float2ArrayImpl::Float2& Rendering::Float2ArrayImpl
	::operator[]( int index )
{
	RENDERING_CLASS_IS_VALID_9;

	return OPERATOR_SQUARE_BRACKETS(Float2, index);
}

#include STSTEM_WARNING_POP