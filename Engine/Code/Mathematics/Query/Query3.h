///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/11/30 16:09)

#ifndef MATHEMATICS_QUERY_QUERY3_H
#define MATHEMATICS_QUERY_QUERY3_H

#include "Mathematics/MathematicsDll.h"

#include "QueryBase.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Query3 : public QueryBase
    {
    public:
        using ClassType = Query3<Real>;
        using ParentType = QueryBase;
        using Math = Math<Real>;
        using Vector3D = Vector3D<Real>;
        using VerticesType = std::vector<Vector3D>;

    public:
        // ���ദ�����ѯ��
        explicit Query3(const VerticesType& vertices);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] QueryType GetType() const noexcept override;

        [[nodiscard]] int GetNumVertices() const;
        [[nodiscard]] const Vector3D GetVertice(int index) const;

        // ����һ����ĸ��ּ��ζ���֮��Ĺ�ϵ��ѯ��

        // ����:
        // PlaneQueryType::PositiveSide, ��ƽ�������
        // PlaneQueryType::NegativeSide, ��ƽ��ĸ���
        // PlaneQueryType::OnPlane, ��ƽ����
        [[nodiscard]] virtual PlaneQueryType ToPlane(int index, int v0, int v1, int v2) const;
        [[nodiscard]] virtual PlaneQueryType ToPlane(const Vector3D& testVector, int v0, int v1, int v2) const;

        // ����:
        // TetrahedronQueryType::Outside, ��������
        // TetrahedronQueryType::Inside, ��������
        // TetrahedronQueryType::OnTetrahedron,����������
        [[nodiscard]] virtual TetrahedronQueryType ToTetrahedron(int index, int v0, int v1, int v2, int v3) const;
        [[nodiscard]] virtual TetrahedronQueryType ToTetrahedron(const Vector3D& testVector, int v0, int v1, int v2, int v3) const;

        // ����:
        // Returns:
        // CircumsphereQueryType::Outside, �����������������
        // CircumsphereQueryType::Inside,�����������������
        // CircumsphereQueryType::OnCircumsphere, �����������������
        [[nodiscard]] virtual CircumsphereQueryType ToCircumsphere(int index, int v0, int v1, int v2, int v3) const;
        [[nodiscard]] virtual CircumsphereQueryType ToCircumsphere(const Vector3D& testVector, int v0, int v1, int v2, int v3) const;

    private:
        // �����
        VerticesType m_Vertices;
    };

    using FloatQuery3 = Query3<float>;
    using DoubleQuery3 = Query3<double>;
}

#endif  // MATHEMATICS_QUERY_QUERY3_H
