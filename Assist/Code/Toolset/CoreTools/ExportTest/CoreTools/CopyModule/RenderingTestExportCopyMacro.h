/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 09:26)

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