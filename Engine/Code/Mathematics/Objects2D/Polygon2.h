///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/13 14:09)

#ifndef MATHEMATICS_OBJECTS2D_POLYGON2_H
#define MATHEMATICS_OBJECTS2D_POLYGON2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Vector2DTools.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class Polygon2Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Polygon2Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Polygon2Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Polygon2Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Polygon2
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using Polygon2Impl = Polygon2Impl<Real>;
        COPY_UNSHARE_CLASSES_BASE_TYPE_DECLARE(Polygon2, DESTRUCTOR_DEFAULT);

        using Math = Math<Real>;
        using Vector2D = Vector2D<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using VerticesType = std::vector<Vector2D>;

    public:
        // ���÷�����ȷ������������ʱ�룬����һ���򵥵Ķ���Ρ�
        explicit Polygon2(const VerticesType& vertices);

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // ֻ����Ա���ʡ�
        [[nodiscard]] int GetNumVertices() const;
        [[nodiscard]] const VerticesType& GetVertices() const noexcept;
        [[nodiscard]] const Vector2D& GetVertex(int index) const;

        // �������޸ġ������߱���ȷ���������Ȼ�Ǽ򵥶���Ρ�
        virtual void SetVertex(int index, const Vector2D& vertex);

        // ���������������εĸ�����Ϣ��
        [[nodiscard]] const Vector2D ComputeVertexAverage() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] Real ComputePerimeterLength() const;
        [[nodiscard]] Real ComputeArea() const;

    private:
        IMPL_TYPE_DECLARE(Polygon2);
    };

    using FloatPolygon2 = Polygon2<float>;
    using DoublePolygon2 = Polygon2<double>;
}

#endif  // MATHEMATICS_OBJECTS2D_POLYGON2_H
