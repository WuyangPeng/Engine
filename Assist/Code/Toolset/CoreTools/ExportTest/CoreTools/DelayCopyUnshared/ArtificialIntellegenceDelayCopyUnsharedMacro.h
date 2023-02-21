///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 16:23)

#ifndef EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_DELAY_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_DELAY_COPY_UNSHARED_MACRO_H

#include "ArtificialIntellegence/ArtificialIntellegenceDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"

ARTIFICIAL_INTELLEGENCE_DELAY_COPY_UNSHARED_EXPORT_IMPL(ArtificialIntellegenceDelayCopyUnsharedMacro, ArtificialIntellegenceDelayCopyUnsharedMacroImpl);

namespace ArtificialIntellegence
{
    class ARTIFICIAL_INTELLEGENCE_DEFAULT_DECLARE ArtificialIntellegenceDelayCopyUnsharedMacro final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(ArtificialIntellegenceDelayCopyUnsharedMacro);

    public:
        explicit ArtificialIntellegenceDelayCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count);

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_DELAY_COPY_UNSHARED_MACRO_H