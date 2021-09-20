///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 17:02)

#ifndef EXPORT_TEST_MATHEMATICS_MACRO_SHARED_H
#define EXPORT_TEST_MATHEMATICS_MACRO_SHARED_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/SharedExportMacro.h"

MATHEMATICS_SHARED_EXPORT_IMPL(MathematicsMacroSharedImpl);

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE MathematicsMacroShared final
    {
    public:
        SHARED_TYPE_DECLARE(MathematicsMacroShared);

    public:
        explicit MathematicsMacroShared(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_MATHEMATICS_MACRO_SHARED_H