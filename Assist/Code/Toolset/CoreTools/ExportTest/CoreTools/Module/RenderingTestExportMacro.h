/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:50)

#ifndef EXPORT_TEST_RENDERING_TEST_EXPORT_MACRO_H
#define EXPORT_TEST_RENDERING_TEST_EXPORT_MACRO_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

EXPORT_SHARED_PTR(Rendering, RenderingTestExportMacroImpl, RENDERING_DEFAULT_DECLARE);
RENDERING_EXPORT(RenderingTestExportMacroImpl, NON_COPY);
RENDERING_EXPORT_UNIQUE_PTR(RenderingTestExportMacro);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RenderingTestExportMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(RenderingTestExportMacro);

    public:
        explicit RenderingTestExportMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_RENDERING_TEST_EXPORT_MACRO_H