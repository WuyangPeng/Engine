// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 19:38)

#include "Mathematics/MathematicsExport.h"

#include "Float1.h"
#include "Detail/Float1Impl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

using std::make_shared;

Mathematics::Float1
	::Float1()
	:m_Impl{ make_shared<ImplType>() }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

Mathematics::Float1
	::Float1 (float value)
	:m_Impl{ make_shared<ImplType>(value) }
{
  	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Mathematics,Float1)

DELAY_COPY_CONSTRUCTION_DEFINE(Mathematics,Float1)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics,Float1,GetValue,float)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Mathematics,Float1,SetValue,float,void)