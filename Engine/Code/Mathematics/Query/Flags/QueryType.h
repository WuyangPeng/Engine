/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 23:35)

#ifndef MATHEMATICS_QUERY_QUERY_TYPE_H
#define MATHEMATICS_QUERY_QUERY_TYPE_H

namespace Mathematics
{
    // 运行时类型信息。
    enum class QueryType
    {
        Int64,
        Integer,
        Rational,
        Real,
        Filtered,
    };

    enum class LineQueryType
    {
        Right = 1,
        Left = -1,
        OnLine = 0,
    };

    enum class TriangleQueryType
    {
        Outside = 1,
        Inside = -1,
        OnTriangle = 0,
    };

    enum class CircumcircleQueryType
    {
        Outside = 1,
        Inside = -1,
        OnCircumcircle = 0,
    };

    enum class PlaneQueryType
    {
        PositiveSide = 1,
        NegativeSide = -1,
        OnPlane = 0,
    };

    enum class TetrahedronQueryType
    {
        Outside = 1,
        Inside = -1,
        OnTetrahedron = 0,
    };

    enum class CircumsphereQueryType
    {
        Outside = 1,
        Inside = -1,
        OnCircumsphere = 0,
    };
}

#endif  // MATHEMATICS_QUERY_QUERY_TYPE_H
