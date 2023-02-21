///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 16:24)

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

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_MATHEMATICS_DELAY_COPY_UNSHARED_MACRO_H