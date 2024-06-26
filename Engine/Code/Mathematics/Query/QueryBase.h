/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 23:39)

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

        QueryBase(const QueryBase& rhs) noexcept = default;
        QueryBase& operator=(const QueryBase& rhs) noexcept = default;
        QueryBase(QueryBase&& rhs) noexcept = default;
        QueryBase& operator=(QueryBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual QueryType GetType() const noexcept = 0;
    };
}

#endif  // MATHEMATICS_QUERY_QUERY_H
