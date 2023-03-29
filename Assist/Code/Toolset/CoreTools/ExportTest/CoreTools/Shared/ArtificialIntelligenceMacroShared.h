///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/17 14:19)

#ifndef EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_MACRO_SHARED_H
#define EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_MACRO_SHARED_H

#include "ArtificialIntelligence/ArtificialIntelligenceDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/SharedExportMacro.h"

ARTIFICIAL_INTELLIGENCE_SHARED_EXPORT_IMPL(ArtificialIntelligenceMacroSharedImpl);

namespace ArtificialIntelligence
{
    class ARTIFICIAL_INTELLIGENCE_DEFAULT_DECLARE ArtificialIntelligenceMacroShared final
    {
    public:
        SHARED_TYPE_DECLARE(ArtificialIntelligenceMacroShared);

    public:
        explicit ArtificialIntelligenceMacroShared(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_MACRO_SHARED_H