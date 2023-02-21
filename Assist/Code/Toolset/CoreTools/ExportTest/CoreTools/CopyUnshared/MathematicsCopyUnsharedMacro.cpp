///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 18:54)

#include "Mathematics/MathematicsExport.h"

#include "MathematicsCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyUnshared/MathematicsCopyUnsharedMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Mathematics, MathematicsCopyUnsharedMacro)

Mathematics::MathematicsCopyUnsharedMacro::MathematicsCopyUnsharedMacro(int count)
    : impl{ count }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, MathematicsCopyUnsharedMacro)

int Mathematics::MathematicsCopyUnsharedMacro::GetCount() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Mathematics::MathematicsCopyUnsharedMacro::SetCount(int count) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* Mathematics::MathematicsCopyUnsharedMacro::GetAddress() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}