///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.4 (2023/03/17 14:18)

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