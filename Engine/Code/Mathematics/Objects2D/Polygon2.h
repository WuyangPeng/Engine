/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 11:17)

#ifndef MATHEMATICS_OBJECTS_2D_POLYGON2_H
#define MATHEMATICS_OBJECTS_2D_POLYGON2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Algebra/Vector2Tools.h"

namespace Mathematics
{
    template <typename Real>
    class Polygon2
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Polygon2;

        using MathType = Math<Real>;
        using Vector2Type = Vector2<Real>;
        using Vector2ToolsType = Vector2Tools<Real>;
        using VerticesType = std::vector<Vector2Type>;

    public:
        // ���÷�����ȷ������������ʱ�룬����һ���򵥵Ķ���Ρ�
        explicit Polygon2(const VerticesType& vertices);

        virtual ~Polygon2() noexcept = default;
        Polygon2(const Polygon2& rhs) = default;
        Polygon2& operator=(const Polygon2& rhs) = default;
        Polygon2(Polygon2&& rhs) noexcept = default;
        Polygon2& operator=(Polygon2&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // ֻ����Ա���ʡ�
        NODISCARD int GetNumVertices() const;
        NODISCARD const VerticesType& GetVertices() const noexcept;
        NODISCARD const Vector2Type& GetVertex(int index) const;

        // �������޸ġ������߱���ȷ���������Ȼ�Ǽ򵥶���Ρ�
        virtual void SetVertex(int index, const Vector2Type& vertex);

        // ���������������εĸ�����Ϣ��
        NODISCARD Vector2Type ComputeVertexAverage() const noexcept(gAssert < 1 || gMathematicsAssert < 1);
        NODISCARD Real ComputePerimeterLength() const;
        NODISCARD Real ComputeArea() const;

    private:
        static constexpr auto minSize = 4;

    private:
        VerticesType vertices;
    };

    using Polygon2F = Polygon2<float>;
    using Polygon2D = Polygon2<double>;
}

#endif  // MATHEMATICS_OBJECTS_2D_POLYGON2_H
