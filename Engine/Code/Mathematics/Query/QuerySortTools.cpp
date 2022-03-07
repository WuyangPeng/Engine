///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/17 15:55)

#include "Mathematics/MathematicsExport.h"

#include "QuerySortTools.h"
#include "Detail/QuerySortToolsImpl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Mathematics::QuerySortTools ::QuerySortTools(int value0, int value1)
    : impl{ value0, value1 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

Mathematics::QuerySortTools ::QuerySortTools(int value0, int value1, int value2)
    : impl{ value0, value1, value2 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

Mathematics::QuerySortTools ::QuerySortTools(int value0, int value1, int value2, int value3)
    : impl{ value0, value1, value2, value3 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, QuerySortTools)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Mathematics, QuerySortTools, GetSymbol, Mathematics::NumericalValueSymbol)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Mathematics, QuerySortTools, GetValue, int, int)
