///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 17:17)

#ifndef EXPORT_TEST_IMAGICS_MACRO_SHARED_H
#define EXPORT_TEST_IMAGICS_MACRO_SHARED_H

#include "Imagics/ImagicsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/SharedExportMacro.h"

IMAGICS_SHARED_EXPORT_IMPL(ImagicsMacroSharedImpl);

namespace Imagics
{
    class IMAGICS_DEFAULT_DECLARE ImagicsMacroShared final
    {
    public:
        SHARED_TYPE_DECLARE(ImagicsMacroShared);

    public:
        explicit ImagicsMacroShared(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_IMAGICS_MACRO_SHARED_H