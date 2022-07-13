///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 13:41)

#include "Mathematics/MathematicsExport.h"

#include "MathematicsDelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/DelayCopyUnshared/MathematicsDelayCopyUnsharedMacroImpl.h"

Mathematics::MathematicsDelayCopyUnsharedMacro::MathematicsDelayCopyUnsharedMacro(int count)
    : impl{ count }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, MathematicsDelayCopyUnsharedMacro)

int Mathematics::MathematicsDelayCopyUnsharedMacro::GetCount() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Mathematics::MathematicsDelayCopyUnsharedMacro::SetCount(int count)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

COPY_UNSHARED_CLONE_SELF_DEFINE(Mathematics, MathematicsDelayCopyUnsharedMacro)