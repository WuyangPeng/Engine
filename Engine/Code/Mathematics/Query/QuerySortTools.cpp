// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 09:56)

#include "Mathematics/MathematicsExport.h"

#include "QuerySortTools.h"
#include "Detail/QuerySortToolsImpl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

Mathematics::QuerySortTools
	::QuerySortTools(int firstValue, int secondValue)
	:m_Impl{ make_shared<ImplType>(firstValue,secondValue) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

Mathematics::QuerySortTools
	::QuerySortTools(int firstValue, int secondValue,int thirdValue)
	:m_Impl{ make_shared<ImplType>(firstValue,secondValue,thirdValue) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

Mathematics::QuerySortTools
	::QuerySortTools(int firstValue, int secondValue,int thirdValue, int fourthValue)
	:m_Impl{ make_shared<ImplType>(firstValue,secondValue,thirdValue,fourthValue) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}


CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Mathematics, QuerySortTools)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics,QuerySortTools,GetSymbol, Mathematics::NumericalValueSymbol)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Mathematics,QuerySortTools,GetValue, int,int)
