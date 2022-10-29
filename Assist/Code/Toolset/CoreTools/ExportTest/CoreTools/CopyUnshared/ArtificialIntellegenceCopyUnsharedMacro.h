///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/17 11:16)

#ifndef EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_COPY_UNSHARED_MACRO_H

#include "ArtificialIntellegence/ArtificialIntellegenceDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

ARTIFICIAL_INTELLEGENCE_COPY_UNSHARED_EXPORT_IMPL(ArtificialIntellegenceCopyUnsharedMacro, ArtificialIntellegenceCopyUnsharedMacroImpl);

namespace ArtificialIntellegence
{
    class ARTIFICIAL_INTELLEGENCE_DEFAULT_DECLARE ArtificialIntellegenceCopyUnsharedMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ArtificialIntellegenceCopyUnsharedMacro);

    public:
        explicit ArtificialIntellegenceCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_COPY_UNSHARED_MACRO_H