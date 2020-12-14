///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/11/30 13:14)

#ifndef MATHEMATICS_QUERY_QUERY_H
#define MATHEMATICS_QUERY_QUERY_H

#include "Mathematics/MathematicsDll.h"

#include "Flags/QueryType.h"

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE QueryBase
    {
    public:
        using ClassType = QueryBase;

    public:
        QueryBase() noexcept = default;
        virtual ~QueryBase() noexcept = default;

        QueryBase(const QueryBase& rhs) = default;
        QueryBase& operator=(const QueryBase& rhs) = default;
        QueryBase(QueryBase&& rhs) noexcept = default;
        QueryBase& operator=(QueryBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] virtual QueryType GetType() const noexcept = 0;
    };
}

#endif  // MATHEMATICS_QUERY_QUERY_H
