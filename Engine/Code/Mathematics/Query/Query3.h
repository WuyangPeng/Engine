///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/17 16:37)

#ifndef MATHEMATICS_QUERY_QUERY3_H
#define MATHEMATICS_QUERY_QUERY3_H

#include "Mathematics/MathematicsDll.h"

#include "QueryBase.h"
#include "Mathematics/Algebra/Vector3.h"

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
        using Vector3 = Vector3<Real>;
        using VerticesType = std::vector<Vector3>;

    public:
        // ���ദ�����ѯ��
        explicit Query3(const VerticesType& vertices);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD QueryType GetType() const noexcept override;

        NODISCARD int GetNumVertices() const;
        NODISCARD const Vector3 GetVertice(int index) const;

        // ����һ����ĸ��ּ��ζ���֮��Ĺ�ϵ��ѯ��

        // ����:
        // PlaneQueryType::PositiveSide, ��ƽ�������
        // PlaneQueryType::NegativeSide, ��ƽ��ĸ���
        // PlaneQueryType::OnPlane, ��ƽ����
        NODISCARD virtual PlaneQueryType ToPlane(int index, int v0, int v1, int v2) const;
        NODISCARD virtual PlaneQueryType ToPlane(const Vector3& testVector, int v0, int v1, int v2) const;

        // ����:
        // TetrahedronQueryType::Outside, ��������
        // TetrahedronQueryType::Inside, ��������
        // TetrahedronQueryType::OnTetrahedron,����������
        NODISCARD virtual TetrahedronQueryType ToTetrahedron(int index, int v0, int v1, int v2, int v3) const;
        NODISCARD virtual TetrahedronQueryType ToTetrahedron(const Vector3& testVector, int v0, int v1, int v2, int v3) const;

        // ����:
        // Returns:
        // CircumsphereQueryType::Outside, �����������������
        // CircumsphereQueryType::Inside,�����������������
        // CircumsphereQueryType::OnCircumsphere, �����������������
        NODISCARD virtual CircumsphereQueryType ToCircumsphere(int index, int v0, int v1, int v2, int v3) const;
        NODISCARD virtual CircumsphereQueryType ToCircumsphere(const Vector3& testVector, int v0, int v1, int v2, int v3) const;

    private:
        // �����
        VerticesType vertices;
    };

    using Query3F = Query3<float>;
    using Query3D = Query3<double>;
}

#endif  // MATHEMATICS_QUERY_QUERY3_H
