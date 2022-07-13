///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 14:08)

#ifndef EXPORT_TEST_MATHEMATICS_DELAY_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_MATHEMATICS_DELAY_COPY_UNSHARED_MACRO_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"

MATHEMATICS_DELAY_COPY_UNSHARED_EXPORT_IMPL(MathematicsDelayCopyUnsharedMacro, MathematicsDelayCopyUnsharedMacroImpl);

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE MathematicsDelayCopyUnsharedMacro final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(MathematicsDelayCopyUnsharedMacro);

    public:
        explicit MathematicsDelayCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count);

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_MATHEMATICS_DELAY_COPY_UNSHARED_MACRO_H