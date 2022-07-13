///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 14:02)

#ifndef EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_TEST_EXPORT_MACRO_H
#define EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_TEST_EXPORT_MACRO_H

#include "ArtificialIntellegence/ArtificialIntellegenceDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

EXPORT_SHARED_PTR(ArtificialIntellegence, ArtificialIntellegenceTestExportMacroImpl, ARTIFICIAL_INTELLEGENCE_DEFAULT_DECLARE);
ARTIFICIAL_INTELLEGENCE_EXPORT(ArtificialIntellegenceTestExportMacroImpl, NON_COPY);
ARTIFICIAL_INTELLEGENCE_EXPORT_UNIQUE_PTR(ArtificialIntellegenceTestExportMacro);

namespace ArtificialIntellegence
{
    class ARTIFICIAL_INTELLEGENCE_DEFAULT_DECLARE ArtificialIntellegenceTestExportMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(ArtificialIntellegenceTestExportMacro);

    public:
        explicit ArtificialIntellegenceTestExportMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_TEST_EXPORT_MACRO_H