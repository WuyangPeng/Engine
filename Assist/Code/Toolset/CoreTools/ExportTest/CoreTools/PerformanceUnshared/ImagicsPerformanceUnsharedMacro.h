///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/17 14:23)

#ifndef EXPORT_TEST_IMAGICS_PERFORMANCE_UNSHARED_MACRO_H
#define EXPORT_TEST_IMAGICS_PERFORMANCE_UNSHARED_MACRO_H

#include "Imagics/ImagicsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

IMAGICS_PERFORMANCE_UNSHARED_EXPORT_IMPL(ImagicsPerformanceUnsharedMacroImpl);

namespace Imagics
{
    class IMAGICS_DEFAULT_DECLARE ImagicsPerformanceUnsharedMacro final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(ImagicsPerformanceUnsharedMacro);

    public:
        explicit ImagicsPerformanceUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_IMAGICS_PERFORMANCE_UNSHARED_MACRO_H