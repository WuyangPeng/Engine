///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/17 11:18)

#ifndef EXPORT_TEST_SCRIPT_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_SCRIPT_COPY_UNSHARED_MACRO_H

#include "Script/ScriptDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

SCRIPT_COPY_UNSHARED_EXPORT_IMPL(ScriptCopyUnsharedMacro, ScriptCopyUnsharedMacroImpl);

namespace Script
{
    class SCRIPT_DEFAULT_DECLARE ScriptCopyUnsharedMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ScriptCopyUnsharedMacro);

    public:
        explicit ScriptCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_SCRIPT_COPY_UNSHARED_MACRO_H