///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/17 15:27)

#ifndef EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_TEST_EXPORT_COPY_MACRO_IMPL_H
#define EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_TEST_EXPORT_COPY_MACRO_IMPL_H

#include "ArtificialIntelligence/ArtificialIntelligenceDll.h"

namespace ArtificialIntelligence
{
    class ARTIFICIAL_INTELLIGENCE_HIDDEN_DECLARE ArtificialIntelligenceTestExportCopyMacroImpl final
    {
    public:
        using ClassType = ArtificialIntelligenceTestExportCopyMacroImpl;

    public:
        explicit ArtificialIntelligenceTestExportCopyMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_TEST_EXPORT_COPY_MACRO_IMPL_H