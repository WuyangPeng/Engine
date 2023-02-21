///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 16:06)

#ifndef EXPORT_TEST_MATHEMATICS_TEST_EXPORT_COPY_MACRO_H
#define EXPORT_TEST_MATHEMATICS_TEST_EXPORT_COPY_MACRO_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

EXPORT_SHARED_PTR(Mathematics, MathematicsTestExportCopyMacroImpl, MATHEMATICS_DEFAULT_DECLARE);
MATHEMATICS_COPY_EXPORT(MathematicsTestExportCopyMacro, MathematicsTestExportCopyMacroImpl, COPY_UNSHARED);

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE MathematicsTestExportCopyMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(MathematicsTestExportCopyMacro);

    public:
        explicit MathematicsTestExportCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_MATHEMATICS_TEST_EXPORT_COPY_MACRO_H