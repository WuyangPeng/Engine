///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/17 15:31)

#ifndef EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_COPY_UNSHARED_MACRO_H

#include "ArtificialIntelligence/ArtificialIntelligenceDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

ARTIFICIAL_INTELLIGENCE_COPY_UNSHARED_EXPORT_IMPL(ArtificialIntelligenceCopyUnsharedMacro, ArtificialIntelligenceCopyUnsharedMacroImpl);

namespace ArtificialIntelligence
{
    class ARTIFICIAL_INTELLIGENCE_DEFAULT_DECLARE ArtificialIntelligenceCopyUnsharedMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ArtificialIntelligenceCopyUnsharedMacro);

    public:
        explicit ArtificialIntelligenceCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_COPY_UNSHARED_MACRO_H