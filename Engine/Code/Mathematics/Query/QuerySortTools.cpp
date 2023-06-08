///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 17:09)

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
