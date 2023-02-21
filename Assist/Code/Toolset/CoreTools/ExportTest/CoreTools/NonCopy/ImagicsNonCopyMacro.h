///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 17:14)

#ifndef EXPORT_TEST_IMAGICS_NON_COPY_MACRO_H
#define EXPORT_TEST_IMAGICS_NON_COPY_MACRO_H

#include "Imagics/ImagicsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

IMAGICS_NON_COPY_EXPORT_IMPL(ImagicsNonCopyMacroImpl);

namespace Imagics
{
    class IMAGICS_DEFAULT_DECLARE ImagicsNonCopyMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(ImagicsNonCopyMacro);

    public:
        explicit ImagicsNonCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_IMAGICS_NON_COPY_MACRO_H