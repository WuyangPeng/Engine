// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/25 16:07)

#include "Rendering/RenderingExport.h"

#include "FloatArrayImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
Rendering::FloatArrayImpl
	::FloatArrayImpl( const FloatVector& elements )
	:m_Elements{ elements }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::FloatArrayImpl
	::FloatArrayImpl() noexcept
	:m_Elements{}
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,FloatArrayImpl)

void Rendering::FloatArrayImpl ::Load(const CoreTools::BufferSourceSharedPtr& source)
{
	RENDERING_CLASS_IS_VALID_9;

	source->Read(m_Elements);
}

void Rendering::FloatArrayImpl
	::Save( const CoreTools::BufferTargetSharedPtr& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	target->WriteContainerWithNumber(m_Elements);
}

int Rendering::FloatArrayImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return CORE_TOOLS_STREAM_SIZE(m_Elements); 
}

int Rendering::FloatArrayImpl
	::GetNumElements() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_Elements.size());
}

const float* Rendering::FloatArrayImpl
	::GetData() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return &m_Elements[0];
}

const float& Rendering::FloatArrayImpl
	::operator[]( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Elements.size()), "ÎÞÐ§Ë÷Òý£¡\n");

	return m_Elements[index];
}

float& Rendering::FloatArrayImpl
	::operator[]( int index )
{
	RENDERING_CLASS_IS_VALID_9;

	return OPERATOR_SQUARE_BRACKETS(float,index);
}

#include STSTEM_WARNING_POP