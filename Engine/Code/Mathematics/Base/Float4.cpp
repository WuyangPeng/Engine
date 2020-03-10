// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/03 19:42)

#include "Mathematics/MathematicsExport.h"

#include "Float4.h"
#include "Detail/Float4Impl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

using std::make_shared;

Mathematics::Float4
	::Float4()
	:m_Impl{ make_shared<ImplType>() }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

Mathematics::Float4
	::Float4 (float firstValue,float secondValue,
	          float thirdValue,float fourValue)
	:m_Impl{ make_shared<ImplType>(firstValue,secondValue,thirdValue,fourValue) } 
{
  	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Mathematics,Float4)

DELAY_COPY_CONSTRUCTION_DEFINE(Mathematics,Float4)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics,Float4,GetFirstValue,float);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics,Float4,GetSecondValue,float);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics,Float4,GetThirdValue,float);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics,Float4,GetFourthValue,float);

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Mathematics,Float4,SetFirstValue,float,void);
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Mathematics,Float4,SetSecondValue,float,void);
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Mathematics,Float4,SetThirdValue,float,void);
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Mathematics,Float4,SetFourthValue,float,void);