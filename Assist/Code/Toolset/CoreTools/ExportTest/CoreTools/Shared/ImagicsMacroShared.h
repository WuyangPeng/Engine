///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/02 13:58)

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

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_IMAGICS_MACRO_SHARED_H