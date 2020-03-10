// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 19:36)

#include "Mathematics/MathematicsExport.h"

#include "Float4Impl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

Mathematics::Float4Impl	
	::Float4Impl ()
	:m_Tuple{}
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::Float4Impl
	::Float4Impl (float firstValue,float secondValue,float thirdValue,float fourValue)
	:m_Tuple{ firstValue,secondValue,thirdValue,fourValue }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics,Float4Impl)

float Mathematics::Float4Impl
	::GetFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return  m_Tuple[0];
}

float Mathematics::Float4Impl
	::GetSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return  m_Tuple[1];
}

float Mathematics::Float4Impl
	::GetThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return  m_Tuple[2];
}

float Mathematics::Float4Impl
	::GetFourthValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return  m_Tuple[3];
}

void Mathematics::Float4Impl
	::SetFirstValue( float value )
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[0] = value;
}

void Mathematics::Float4Impl
	::SetSecondValue( float value )
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[1] = value;
}

void Mathematics::Float4Impl
	::SetThirdValue( float value )
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[2] = value;
}

void Mathematics::Float4Impl
	::SetFourthValue( float value )
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[3] = value;
}