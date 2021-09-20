///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 17:01)

#ifndef EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_MACRO_SHARED_H
#define EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_MACRO_SHARED_H

#include "ArtificialIntellegence/ArtificialIntellegenceDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/SharedExportMacro.h"

ARTIFICIAL_INTELLEGENCE_SHARED_EXPORT_IMPL(ArtificialIntellegenceMacroSharedImpl);

namespace ArtificialIntellegence
{
    class ARTIFICIAL_INTELLEGENCE_DEFAULT_DECLARE ArtificialIntellegenceMacroShared final
    {
    public:
        SHARED_TYPE_DECLARE(ArtificialIntellegenceMacroShared);

    public:
        explicit ArtificialIntellegenceMacroShared(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_MACRO_SHARED_H