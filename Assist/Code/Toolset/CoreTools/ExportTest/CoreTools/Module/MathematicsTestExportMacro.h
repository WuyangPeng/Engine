/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:50)

#ifndef EXPORT_TEST_MATHEMATICS_TEST_EXPORT_MACRO_H
#define EXPORT_TEST_MATHEMATICS_TEST_EXPORT_MACRO_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

EXPORT_SHARED_PTR(Mathematics, MathematicsTestExportMacroImpl, MATHEMATICS_DEFAULT_DECLARE);
MATHEMATICS_EXPORT(MathematicsTestExportMacroImpl, NON_COPY);
MATHEMATICS_EXPORT_UNIQUE_PTR(MathematicsTestExportMacro);

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE MathematicsTestExportMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(MathematicsTestExportMacro);

    public:
        explicit MathematicsTestExportMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_MATHEMATICS_TEST_EXPORT_MACRO_H