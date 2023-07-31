///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 15:40)

#include "Mathematics/MathematicsExport.h"

#include "MathematicsDelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/DelayCopyUnshared/MathematicsDelayCopyUnsharedMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Mathematics, MathematicsDelayCopyUnsharedMacro)

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

const void* Mathematics::MathematicsDelayCopyUnsharedMacro::GetAddress() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}