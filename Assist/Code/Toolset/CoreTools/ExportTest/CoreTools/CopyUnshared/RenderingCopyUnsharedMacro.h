///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 14:10)

#ifndef EXPORT_TEST_RENDERING_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_RENDERING_COPY_UNSHARED_MACRO_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(RenderingCopyUnsharedMacro, RenderingCopyUnsharedMacroImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RenderingCopyUnsharedMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(RenderingCopyUnsharedMacro);

    public:
        explicit RenderingCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_RENDERING_COPY_UNSHARED_MACRO_H