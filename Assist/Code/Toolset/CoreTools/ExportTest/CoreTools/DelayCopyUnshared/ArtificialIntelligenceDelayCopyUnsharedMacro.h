///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 14:55)

#ifndef EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_DELAY_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_DELAY_COPY_UNSHARED_MACRO_H

#include "ArtificialIntelligence/ArtificialIntelligenceDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"

ARTIFICIAL_INTELLIGENCE_DELAY_COPY_UNSHARED_EXPORT_IMPL(ArtificialIntelligenceDelayCopyUnsharedMacro, ArtificialIntelligenceDelayCopyUnsharedMacroImpl);

namespace ArtificialIntelligence
{
    class ARTIFICIAL_INTELLIGENCE_DEFAULT_DECLARE ArtificialIntelligenceDelayCopyUnsharedMacro final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(ArtificialIntelligenceDelayCopyUnsharedMacro);

    public:
        explicit ArtificialIntelligenceDelayCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count);

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_DELAY_COPY_UNSHARED_MACRO_H