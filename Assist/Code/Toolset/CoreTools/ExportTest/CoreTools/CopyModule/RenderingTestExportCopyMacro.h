///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.1 (2021/08/12 14:34)

#ifndef EXPORT_TEST_RENDERING_TEST_EXPORT_COPY_MACRO_H
#define EXPORT_TEST_RENDERING_TEST_EXPORT_COPY_MACRO_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

EXPORT_SHARED_PTR(Rendering, RenderingTestExportCopyMacroImpl, RENDERING_DEFAULT_DECLARE);
RENDERING_COPY_EXPORT(RenderingTestExportCopyMacro, RenderingTestExportCopyMacroImpl, COPY_UNSHARED);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RenderingTestExportCopyMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(RenderingTestExportCopyMacro);

    public:
        explicit RenderingTestExportCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_RENDERING_TEST_EXPORT_COPY_MACRO_H