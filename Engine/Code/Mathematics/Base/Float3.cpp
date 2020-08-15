// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 09:43)

#include "Mathematics/MathematicsExport.h"

#include "Float3.h"
#include "Detail/Float3Impl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
Mathematics::Float3
	::Float3()
	:m_Impl{ make_shared<ImplType>() }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP
Mathematics::Float3
	::Float3(float firstValue, float secondValue, float thirdValue)
	:m_Impl{ make_shared<ImplType>(firstValue,secondValue,thirdValue) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Mathematics, Float3)

DELAY_COPY_CONSTRUCTION_DEFINE(Mathematics, Float3)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics, Float3, GetFirstValue, float);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics, Float3, GetSecondValue, float);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics, Float3, GetThirdValue, float);

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Mathematics, Float3, SetFirstValue, float, void);
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Mathematics, Float3, SetSecondValue, float, void);
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Mathematics, Float3, SetThirdValue, float, void);