///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/18 0:03)

#ifndef EXPORT_TEST_DATABASE_NON_COPY_MACRO_H
#define EXPORT_TEST_DATABASE_NON_COPY_MACRO_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

DATABASE_NON_COPY_EXPORT_IMPL(DatabaseNonCopyMacroImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE DatabaseNonCopyMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(DatabaseNonCopyMacro);

    public:
        explicit DatabaseNonCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_DATABASE_NON_COPY_MACRO_H