/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 09:35)

#ifndef EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_DELAY_COPY_UNSHARED_MACRO_IMPL_H
#define EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_DELAY_COPY_UNSHARED_MACRO_IMPL_H

#include "ArtificialIntelligence/ArtificialIntelligenceDll.h"

namespace ArtificialIntelligence
{
    class ARTIFICIAL_INTELLIGENCE_HIDDEN_DECLARE ArtificialIntelligenceDelayCopyUnsharedMacroImpl final
    {
    public:
        using ClassType = ArtificialIntelligenceDelayCopyUnsharedMacroImpl;

    public:
        explicit ArtificialIntelligenceDelayCopyUnsharedMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_DELAY_COPY_UNSHARED_MACRO_IMPL_H