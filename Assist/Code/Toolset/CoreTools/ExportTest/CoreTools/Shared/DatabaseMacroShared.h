///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 17:02)

#ifndef EXPORT_TEST_DATABASE_MACRO_SHARED_H
#define EXPORT_TEST_DATABASE_MACRO_SHARED_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/SharedExportMacro.h"

DATABASE_SHARED_EXPORT_IMPL(DatabaseMacroSharedImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE DatabaseMacroShared final
    {
    public:
        SHARED_TYPE_DECLARE(DatabaseMacroShared);

    public:
        explicit DatabaseMacroShared(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_DATABASE_MACRO_SHARED_H