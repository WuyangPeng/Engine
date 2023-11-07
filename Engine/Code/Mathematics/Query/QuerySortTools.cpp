///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:03)

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

Mathematics::NumericalValueSymbol Mathematics::QuerySortTools::GetSymbol() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetSymbol();
}

int Mathematics::QuerySortTools::GetValue(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetValue(index);
}
