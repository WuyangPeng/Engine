/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.6 (2024/02/22 09:44)

#ifndef MATHEMATICS_OBJECTS_2D_ALGEBRA_POLYGON2_H
#define MATHEMATICS_OBJECTS_2D_ALGEBRA_POLYGON2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector2.h"

#include <set>

namespace Mathematics::Algebra
{
    /// Polygon2�����ʾһ���򵥵Ķ���Σ�
    /// û���ظ��Ķ��㣬�պϵģ�ÿ�����������������߹������ڲ��ߵ�û�����ཻ��
    /// ������ء�������԰����ȶ�����������ĵ����ĵ㣬��������ؾ�����������Ķ������Ρ�
    /// ��ˣ�����Ա����ȷ��ֻҪ���������ڶ���ص��κ�Polygon2���󣬶���ؾ�һֱ���ڡ�
    /// ����ζ��������Ϊ��numIndices�������ұ�����ڻ����3��
    /// ��indexes���������ö�����еĵ㣬��Щ���Ƕ���ε�һ���֣����ұ�����С�numIndices��ΨһԪ�ء�
    /// ����εı��ǡ�����ء��ĳɶ�������
    ///   edge[0] = (indices[0], indices[1])
    ///   :
    ///   edge[numIndices-2] = (indices[numIndices-2], indices[numIndices-1])
    ///   edge[numIndices-1] = (indices[numIndices-1], indices[0])
    /// ����ԱӦȷ��������Ǽ򵥵ġ����۶������˳ʱ�뷽������ʱ�뷽�򣬼��β�ѯ������Ч�ġ�
    ///
    /// ע�����ṩ�Ƚ����������ȶ���ε�����ܸ��ӣ���Ŀǰ��û���ô���
    /// ����ؿ��Բ�ͬ������Ҳ��ƥ�䣬���������õĶ������ƥ�䡣
    /// ��ʹʹ�ù�����أ�����Ҳ���ԡ���ת��������ص�����ͬ�Ķ���Σ������ݽṹ��ƥ�䡣
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class Polygon2
    {
    public:
        using ClassType = Polygon2;

        using Vector2 = Vector2<Real>;
        using VertexPool = std::vector<Vector2>;
        using VertexPoolSharedPtr = std::shared_ptr<VertexPool>;
        using VertexPoolWeakPtr = std::weak_ptr<VertexPool>;

        using VerticesType = std::set<int>;
        using IndicesType = std::vector<int>;

        using Math = Math<Real>;

    public:
        /// ���쵱'numIndices' >= 3�ҡ�vertexPool���͡�indices����Ϊ��ʱ�����캯���ɹ���
        /// ���ǲ��������������Ƿ�����Ч������Ԫ�ء�
        /// �����ɡ���������ɣ��������ơ�����ء���
        /// ������캯��ʧ�ܣ����׳��쳣��
        Polygon2(const VertexPoolSharedPtr& vertexPool,
                 int numIndices,
                 const IndicesType& indices,
                 bool counterClockwise);

        CLASS_INVARIANT_DECLARE;

        /// ��Ա���ʡ�
        NODISCARD VertexPoolSharedPtr GetVertexPool() const;
        NODISCARD VerticesType GetVertices() const;
        NODISCARD IndicesType GetIndices() const;
        NODISCARD bool CounterClockwise() const noexcept;

        /// ���β�ѯ��
        NODISCARD Vector2 ComputeVertexAverage() const;

        NODISCARD Real ComputePerimeterLength() const;

        NODISCARD Real ComputeArea() const;

        /// �򵥶�����ڱߵ��ڲ��㴦û�����ཻ��
        /// �ò�����һ����Աߵ��꾡��ȫ���ཻ���ԣ�
        /// ���ھ��д�������Ķ������˵Ч�ʵ��¡�
        /// �ṩһ����Ч���㷨�����㷨ʹ����RectangleManager.h���㷨��
        NODISCARD bool IsSimple() const;

        /// ͹�������ָ������֮��ĽǶ�С�ڻ����pi���ȵļ򵥶���Ρ�
        NODISCARD bool IsConvex() const;

    private:
        /// ��Щ���þ���ǰ��������
        /// ��vertexPool��Ϊnull����indices.size.size() > 3��
        /// �㷨�ĺ���������ʵ�֡�
        NODISCARD bool IsSimpleInternal() const;

        NODISCARD bool IsConvexInternal() const;

    private:
        VertexPoolWeakPtr vertexPool;
        VerticesType vertices;
        IndicesType indices;
        bool counterClockwise;
    };

}

#endif  // MATHEMATICS_OBJECTS_2D_ALGEBRA_POLYGON2_H
