/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:54)

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