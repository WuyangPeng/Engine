/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 10:25)

#ifndef MATHEMATICS_OBJECTS_3D_POLYHEDRON3_H
#define MATHEMATICS_OBJECTS_3D_POLYHEDRON3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Polyhedron3
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Polyhedron3<Real>;

        using MathType = Math<Real>;

        using Vector3Type = Vector3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using VerticesType = std::vector<Vector3Type>;
        using IndicesType = std::vector<int>;

    public:
        // �����߸���ȷ���������һ���򵥵Ķ�����
        // ����ά��������������ˣ������ཻ�����˽ṹ����
        // �������棬��������۲�ʱ������ʱ��˳��
        //
        // Polyhedron3����һ���������Դ�������ݡ�
        // �����ʹ������ָ�루SmartPointer1DArray�������������顣
        // �������ϣ����ɾ�����飬ʹ���Լ�������ָ������顣
        Polyhedron3(const VerticesType& vertices, const IndicesType& indices);

        virtual ~Polyhedron3() noexcept = default;
        Polyhedron3(const Polyhedron3& rhs) = default;
        Polyhedron3& operator=(const Polyhedron3& rhs) = default;
        Polyhedron3(Polyhedron3&& rhs) noexcept = default;
        Polyhedron3& operator=(Polyhedron3&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

#ifdef OPEN_CLASS_INVARIANT

        NODISCARD bool IndicesIsValid() const noexcept;

#endif  // OPEN_CLASS_INVARIANT

        // ֻ����Ա���ʡ�
        NODISCARD int GetNumVertices() const;
        NODISCARD VerticesType GetVertices() const;
        NODISCARD const Vector3Type& GetVertex(int index) const;
        NODISCARD int GetNumTriangles() const;
        NODISCARD int GetNumIndices() const;  // = 3 * numTriangles
        NODISCARD IndicesType GetIndices() const;
        NODISCARD IndicesType GetTriangle(int index) const;

        // �������޸ġ������߱���ȷ����������Ȼ�Ǽ򵥶����塣
        virtual void SetVertex(int index, const Vector3Type& vertex);

        // �����������������ĸ�����Ϣ��
        NODISCARD Vector3Type ComputeVertexAverage() const;
        NODISCARD Real ComputeSurfaceArea() const;
        NODISCARD Real ComputeVolume() const;

    private:
        constexpr static auto triangleVertexSize = 3;
        constexpr static auto minVerticesSize = 4;

    private:
        VerticesType vertices;
        IndicesType indices;
    };

    using Polyhedron3F = Polyhedron3<float>;
    using Polyhedron3D = Polyhedron3<double>;
}

#endif  // MATHEMATICS_OBJECTS_3D_POLYHEDRON3_H
