/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 09:56)

#ifndef EXPORT_TEST_RENDERING_MACRO_SHARED_H
#define EXPORT_TEST_RENDERING_MACRO_SHARED_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/SharedExportMacro.h"

RENDERING_SHARED_EXPORT_IMPL(RenderingMacroSharedImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RenderingMacroShared final
    {
    public:
        SHARED_TYPE_DECLARE(RenderingMacroShared);

    public:
        explicit RenderingMacroShared(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_RENDERING_MACRO_SHARED_H