///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/17 16:17)

#ifndef MATHEMATICS_QUERY_QUERY_TYPE_H
#define MATHEMATICS_QUERY_QUERY_TYPE_H

namespace Mathematics
{
    // ����ʱ������Ϣ��
    enum class QueryType
    {
        Int64,
        Interger,
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
