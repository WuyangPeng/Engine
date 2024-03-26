/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 09:52)

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