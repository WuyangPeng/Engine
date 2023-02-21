///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 17:16)

#ifndef EXPORT_TEST_RENDERING_PERFORMANCE_UNSHARED_MACRO_H
#define EXPORT_TEST_RENDERING_PERFORMANCE_UNSHARED_MACRO_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

RENDERING_PERFORMANCE_UNSHARED_EXPORT_IMPL(RenderingPerformanceUnsharedMacroImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RenderingPerformanceUnsharedMacro final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(RenderingPerformanceUnsharedMacro);

    public:
        explicit RenderingPerformanceUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_RENDERING_PERFORMANCE_UNSHARED_MACRO_H