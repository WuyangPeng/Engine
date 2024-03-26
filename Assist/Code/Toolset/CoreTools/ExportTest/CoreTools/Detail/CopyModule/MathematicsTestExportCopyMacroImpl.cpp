/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 10:04)

#include "Mathematics/MathematicsExport.h"

#include "MathematicsTestExportCopyMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

Mathematics::MathematicsTestExportCopyMacroImpl::MathematicsTestExportCopyMacroImpl(int count) noexcept
    : count{ count }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, MathematicsTestExportCopyMacroImpl)

int Mathematics::MathematicsTestExportCopyMacroImpl::GetCount() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return count;
}

void Mathematics::MathematicsTestExportCopyMacroImpl::SetCount(int aCount) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    count = aCount;
}
