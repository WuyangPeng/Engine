///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 17:08)

#ifndef MATHEMATICS_QUERY_FWD_H
#define MATHEMATICS_QUERY_FWD_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
    class QuerySortTools;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE QueryDotTools;

    class QueryBase;

    template <typename Real>
    class Query2;

    template <typename Real>
    class Query2Integer;

    template <typename Real>
    class Query2Int64;

    template <typename Real>
    class Query2Rational;

    template <typename Real>
    class Query2Filtered;

    template <typename Real>
    class Query3;

    template <typename Real>
    class Query3Integer;

    template <typename Real>
    class Query3Int64;

    template <typename Real>
    class Query3Rational;

    template <typename Real>
    class Query3Filtered;

    enum class QueryType;
    enum class LineQueryType;
    enum class TriangleQueryType;
    enum class CircumcircleQueryType;
    enum class PlaneQueryType;
    enum class TetrahedronQueryType;
    enum class CircumsphereQueryType;
}

#endif  // MATHEMATICS_QUERY_FWD_H