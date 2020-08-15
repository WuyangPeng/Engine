// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 09:41)

#include "Mathematics/MathematicsExport.h"

#include "Float2Impl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

Mathematics::Float2Impl
	::Float2Impl() noexcept
	:m_Tuple{}
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::Float2Impl
	::Float2Impl(float firstValue, float secondValue) noexcept
	:m_Tuple{ firstValue,secondValue }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, Float2Impl)

float Mathematics::Float2Impl
	::GetFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[0];
}

float Mathematics::Float2Impl
	::GetSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[1];
}

void Mathematics::Float2Impl
	::SetFirstValue(float value)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[0] = value;
}

void Mathematics::Float2Impl
	::SetSecondValue(float value)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[1] = value;
}

