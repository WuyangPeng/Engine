///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/17 14:31)

#ifndef EXPORT_TEST_MATHEMATICS_NON_COPY_MACRO_H
#define EXPORT_TEST_MATHEMATICS_NON_COPY_MACRO_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

MATHEMATICS_NON_COPY_EXPORT_IMPL(MathematicsNonCopyMacroImpl);

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE MathematicsNonCopyMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(MathematicsNonCopyMacro);

    public:
        explicit MathematicsNonCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_MATHEMATICS_NON_COPY_MACRO_H