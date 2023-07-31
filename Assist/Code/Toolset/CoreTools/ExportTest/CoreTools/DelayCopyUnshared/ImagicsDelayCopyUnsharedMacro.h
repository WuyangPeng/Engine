///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 14:56)

#ifndef EXPORT_TEST_IMAGICS_DELAY_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_IMAGICS_DELAY_COPY_UNSHARED_MACRO_H

#include "Imagics/ImagicsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"

IMAGICS_DELAY_COPY_UNSHARED_EXPORT_IMPL(ImagicsDelayCopyUnsharedMacro, ImagicsDelayCopyUnsharedMacroImpl);

namespace Imagics
{
    class IMAGICS_DEFAULT_DECLARE ImagicsDelayCopyUnsharedMacro final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(ImagicsDelayCopyUnsharedMacro);

    public:
        explicit ImagicsDelayCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count);

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_IMAGICS_DELAY_COPY_UNSHARED_MACRO_H