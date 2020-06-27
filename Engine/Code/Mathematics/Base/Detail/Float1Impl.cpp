// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 09:41)

#include "Mathematics/MathematicsExport.h"

#include "Float1Impl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

Mathematics::Float1Impl
	::Float1Impl()
	:m_Tuple{}
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::Float1Impl
	::Float1Impl(float value)
	:m_Tuple{ value }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, Float1Impl)

float Mathematics::Float1Impl
	::GetValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return  m_Tuple[0];
}

void Mathematics::Float1Impl
	::SetValue(float value)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[0] = value;
}

