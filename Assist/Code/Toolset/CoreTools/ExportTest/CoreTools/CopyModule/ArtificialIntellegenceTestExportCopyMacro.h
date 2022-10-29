///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/17 11:04)

#ifndef EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_TEST_EXPORT_COPY_MACRO_H
#define EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_TEST_EXPORT_COPY_MACRO_H

#include "ArtificialIntellegence/ArtificialIntellegenceDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

EXPORT_SHARED_PTR(ArtificialIntellegence, ArtificialIntellegenceTestExportCopyMacroImpl, ARTIFICIAL_INTELLEGENCE_DEFAULT_DECLARE);
ARTIFICIAL_INTELLEGENCE_COPY_EXPORT(ArtificialIntellegenceTestExportCopyMacro, ArtificialIntellegenceTestExportCopyMacroImpl, COPY_UNSHARED);

namespace ArtificialIntellegence
{
    class ARTIFICIAL_INTELLEGENCE_DEFAULT_DECLARE ArtificialIntellegenceTestExportCopyMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ArtificialIntellegenceTestExportCopyMacro);

    public:
        explicit ArtificialIntellegenceTestExportCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_TEST_EXPORT_COPY_MACRO_H