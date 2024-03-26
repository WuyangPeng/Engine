/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 09:51)

#ifndef EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_NON_COPY_MACRO_H
#define EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_NON_COPY_MACRO_H

#include "ArtificialIntelligence/ArtificialIntelligenceDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

ARTIFICIAL_INTELLIGENCE_NON_COPY_EXPORT_IMPL(ArtificialIntelligenceNonCopyMacroImpl);

namespace ArtificialIntelligence
{
    class ARTIFICIAL_INTELLIGENCE_DEFAULT_DECLARE ArtificialIntelligenceNonCopyMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(ArtificialIntelligenceNonCopyMacro);

    public:
        explicit ArtificialIntelligenceNonCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_NON_COPY_MACRO_H