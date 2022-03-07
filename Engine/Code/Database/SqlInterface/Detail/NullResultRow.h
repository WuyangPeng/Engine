///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/25 13:58)

#ifndef DATABASE_SQL_INTERFACE_NULL_DOC_RESULT_H
#define DATABASE_SQL_INTERFACE_NULL_DOC_RESULT_H

#include "Database/DatabaseDll.h"

#include "ResultRowImpl.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE NullResultRow final : public ResultRowImpl
    {
    public:
        using ClassType = NullResultRow;
        using ParentType = ResultRowImpl;

    public:
        explicit NullResultRow(const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetColCount() const noexcept final;

        void Print(MAYBE_UNUSED std::ostream& os) const noexcept final;
    };
}

#endif  // DATABASE_SQL_INTERFACE_NULL_DOC_RESULT_H
