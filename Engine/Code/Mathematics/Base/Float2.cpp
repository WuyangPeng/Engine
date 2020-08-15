// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 09:42)

#include "Mathematics/MathematicsExport.h"

#include "Float2.h"
#include "Detail/Float2Impl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
Mathematics::Float2
	::Float2()
	:m_Impl{ make_shared<ImplType>() }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}
#include  STSTEM_WARNING_POP
Mathematics::Float2
	::Float2(float firstValue, float secondValue)
	:m_Impl{ make_shared<ImplType>(firstValue,secondValue) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Mathematics, Float2)

DELAY_COPY_CONSTRUCTION_DEFINE(Mathematics, Float2)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics, Float2, GetFirstValue, float);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics, Float2, GetSecondValue, float);

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Mathematics, Float2, SetFirstValue, float, void);
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Mathematics, Float2, SetSecondValue, float, void);