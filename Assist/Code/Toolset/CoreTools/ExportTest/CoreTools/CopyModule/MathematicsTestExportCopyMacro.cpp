/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:57)

#include "Mathematics/MathematicsExport.h"

#include "MathematicsTestExportCopyMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyModule/MathematicsTestExportCopyMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Mathematics, MathematicsTestExportCopyMacro)

Mathematics::MathematicsTestExportCopyMacro::MathematicsTestExportCopyMacro(int count)
    : impl{ count }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, MathematicsTestExportCopyMacro)

int Mathematics::MathematicsTestExportCopyMacro::GetCount() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Mathematics::MathematicsTestExportCopyMacro::SetCount(int count) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    impl->SetCount(count);
}
