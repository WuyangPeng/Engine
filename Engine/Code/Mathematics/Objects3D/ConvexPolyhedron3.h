///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/18 11:18)

#ifndef MATHEMATICS_OBJECTS3D_CONVEX_POLYHEDRON3_H
#define MATHEMATICS_OBJECTS3D_CONVEX_POLYHEDRON3_H

#include "Mathematics/MathematicsDll.h"

#include "Plane3.h"
#include "Polyhedron3.h"
#include "Mathematics/Base/MathDetail.h"

#include <set>
#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class ConvexPolyhedron3Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<ConvexPolyhedron3Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<ConvexPolyhedron3Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<ConvexPolyhedron3Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE ConvexPolyhedron3 : public Polyhedron3<Real>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ConvexPolyhedron3Impl = ConvexPolyhedron3Impl<Real>;
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(ConvexPolyhedron3, DESTRUCTOR_DEFAULT);

        using ParentType = Polyhedron3<Real>;
        using Math = Math<Real>;
        using Plane3 = Plane3<Real>;

        // ��Plane��ʾDot(N,X) = c��
        // N��ʾ��λ���������ƽ�档
        // c��ʾƽ��ĳ�����
        // X��ƽ���ϵ�����㡣
        using PlaneContainerType = std::vector<Plane3>;
        using TrianglesType = std::set<int>;

        using Vector3D = ParentType::Vector3D;
        using Vector3DTools = ParentType::Vector3DTools;
        using VerticesType = ParentType::VerticesType;
        using IndicesType = ParentType::IndicesType;

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
        [[nodiscard]] const PlaneContainerType GetPlanes() const;
        [[nodiscard]] const Plane3& GetPlane(int index) const;

        // �������޸ġ������߱���ȷ������������͹�����塣
        // ֻҪ���޸ľ����ܶ�Ķ���󣬵���UpdatePlanes()��
        // ���о���SetVertex���޸ģ�
        // UpdatePlanes����ĸ��£�ֻ���޸ĵĹ���Ķ���������ν��С�
        void SetVertex(int index, const Vector3D& vertex) override;
        void UpdatePlanes();
        [[nodiscard]] bool IsUpdatePlanes() const noexcept;

        // ����͹�ԡ�
        // ��������������ö�����������֤ÿ����Ķ�����Ķ��㶼��ƽ��ķǸ��ࡣ
        // ���ž������ʱ������һ��������һ��ƽ�棨����͹���ķ���ʱ��
        // ���з��ŵľ�������d < 0����ֵ���������������ȷ͹�Բ��ԣ�
        // ����һ��С�ĸ���ֵt����ͨ���ú�����
        // ����������£�������Ի���d < t < 0��
        [[nodiscard]] bool IsConvex(Real threshold = -Math::GetZeroTolerance()) const;

        // ���ڶ�����Ĳ��ԣ��ڵ��ƽ����棬��n������֮���ѯִ�У�ΪO(n)�㷨��
        // �ⲻ�������㷨���ɽ�����BSP�㷨��������ࡣ����һ��O(log n)���㷨��
        [[nodiscard]] bool Contains(const Vector3D& point, Real threshold = -Math::GetZeroTolerance()) const;

    private:
        void InitPlanes();

        // ֧�ֵ�ƽ��ĸ�Ч���¡�
        // set�洢��Щ�޸Ĺ����������ε�������
        void UpdatePlane(int index, const Vector3D& average);

    private:
        IMPL_TYPE_DECLARE(ConvexPolyhedron3);
    };

    using FloatConvexPolyhedron3 = ConvexPolyhedron3<float>;
    using DoubleConvexPolyhedron3 = ConvexPolyhedron3<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_CONVEX_POLYHEDRON3_H
