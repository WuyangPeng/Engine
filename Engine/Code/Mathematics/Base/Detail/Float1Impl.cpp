// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/03 19:33)

#include "Mathematics/MathematicsExport.h"

#include "Float1Impl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

Mathematics::Float1Impl	
	::Float1Impl ()
	:m_Tuple{}
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::Float1Impl
	::Float1Impl (float value)
	:m_Tuple(value)
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
CLASS_INVARIANT_STUB_DEFINE(Mathematics,Float1Impl)
#endif // OPEN_CLASS_INVARIANT

float Mathematics::Float1Impl
	::GetValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return  m_Tuple[0];
}

void Mathematics::Float1Impl
	::SetValue( float value )
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[0] = value;
}

