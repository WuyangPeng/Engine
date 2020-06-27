// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 09:41)

#include "Mathematics/MathematicsExport.h"

#include "Float3Impl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

Mathematics::Float3Impl
	::Float3Impl()
	:m_Tuple{}
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::Float3Impl
	::Float3Impl(float firstValue, float secondValue, float thirdValue)
	:m_Tuple{ firstValue,secondValue,thirdValue }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, Float3Impl)

float Mathematics::Float3Impl
	::GetFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return  m_Tuple[0];
}

float Mathematics::Float3Impl
	::GetSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return  m_Tuple[1];
}

float Mathematics::Float3Impl
	::GetThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return  m_Tuple[2];
}

void Mathematics::Float3Impl
	::SetFirstValue(float value)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[0] = value;
}

void Mathematics::Float3Impl
	::SetSecondValue(float value)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[1] = value;
}

void Mathematics::Float3Impl
	::SetThirdValue(float value)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[2] = value;
}

