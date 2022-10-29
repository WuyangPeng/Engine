///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/18 16:27)

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
