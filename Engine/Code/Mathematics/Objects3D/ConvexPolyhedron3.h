/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 10:26)

#ifndef MATHEMATICS_OBJECTS_3D_CONVEX_POLYHEDRON3_H
#define MATHEMATICS_OBJECTS_3D_CONVEX_POLYHEDRON3_H

#include "Mathematics/MathematicsDll.h"

#include "Plane3.h"
#include "Polyhedron3.h"
#include "Mathematics/Base/MathDetail.h"

#include <set>

namespace Mathematics
{
    template <typename Real>
    class ConvexPolyhedron3 final : public Polyhedron3<Real>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ConvexPolyhedron3<Real>;
        using ParentType = Polyhedron3<Real>;

        using Math = Math<Real>;
        using Plane3 = Plane3<Real>;

        // ��Plane��ʾDot(N,X) = c��
        // N��ʾ��λ���������ƽ�档
        // c��ʾƽ��ĳ�����
        // X��ƽ���ϵ�����㡣
        using PlaneContainerType = std::vector<Plane3>;
        using TrianglesType = std::set<int>;

        using Vector3 = typename ParentType::Vector3;
        using Vector3Tools = typename ParentType::Vector3Tools;
        using VerticesType = typename ParentType::VerticesType;
        using IndicesType = typename ParentType::IndicesType;

    public:
        // �����߸���ȷ���������һ��͹�����塣
        // ����������۲�ʱ�������ε�����뱣����ʱ��˳��
        //
        // Polyhedron3����һ���������Դ�������ݡ�
        // �����ʹ������ָ�루SmartPointer1DArray�������������顣
        // �������ϣ����ɾ�����飬ʹ���Լ�������ָ������顣
        //
        // ConvexPolyhedron3�洢���������������ƽ�档ƽ�淨����ָʾ��
        // ��ƽ����Ա����캯���ṩ��������ǲ�ͨ���������ݣ���planes��Ϊ�գ������Զ��������ǡ�
        ConvexPolyhedron3(const VerticesType& vertices, const IndicesType& indices, const PlaneContainerType& planes);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // ֻ����Ա���ʡ�
        NODISCARD PlaneContainerType GetPlanes() const;
        NODISCARD const Plane3& GetPlane(int index) const;

        // �������޸ġ������߱���ȷ������������͹�����塣
        // ֻҪ���޸ľ����ܶ�Ķ���󣬵���UpdatePlanes()��
        // ���о���SetVertex���޸ģ�
        // UpdatePlanes����ĸ��£�ֻ���޸ĵĹ���Ķ���������ν��С�
        void SetVertex(int index, const Vector3& vertex) override;
        void UpdatePlanes();
        NODISCARD bool IsUpdatePlanes() const noexcept;

        // ����͹�ԡ�
        // ��������������ö�����������֤ÿ����Ķ�����Ķ��㶼��ƽ��ķǸ��ࡣ
        // ���ž������ʱ������һ��������һ��ƽ�棨����͹���ķ���ʱ��
        // ���з��ŵľ�������d < 0����ֵ���������������ȷ͹�Բ��ԣ�
        // ����һ��С�ĸ���ֵt����ͨ���ú�����
        // ����������£�������Ի���d < t < 0��
        NODISCARD bool IsConvex(Real threshold = -Math::GetZeroTolerance()) const;

        // ���ڶ�����Ĳ��ԣ��ڵ��ƽ����棬��n������֮���ѯִ�У�ΪO(n)�㷨��
        // �ⲻ�������㷨���ɽ�����BSP�㷨��������ࡣ����һ��O(log n)���㷨��
        NODISCARD bool Contains(const Vector3& point, Real threshold = -Math::GetZeroTolerance()) const;

    private:
        void InitPlanes();

        // ֧�ֵ�ƽ��ĸ�Ч���¡�
        // set�洢��Щ�޸Ĺ����������ε�������
        void UpdatePlane(int index, const Vector3& average);

    private:
        // 	��������������ε�������
        PlaneContainerType planes;

        // Ҫ��UpdatePlane����Ĺ���������
        TrianglesType sharingTriangles;
    };

    using ConvexPolyhedron3F = ConvexPolyhedron3<float>;
    using ConvexPolyhedron3D = ConvexPolyhedron3<double>;
}

#endif  // MATHEMATICS_OBJECTS_3D_CONVEX_POLYHEDRON3_H
