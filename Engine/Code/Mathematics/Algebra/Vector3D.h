// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.2.5 (2020/03/19 10:17)

// 3D�����������
#ifndef MATHEMATICS_ALGEBRA_VECTOR_3D_H
#define MATHEMATICS_ALGEBRA_VECTOR_3D_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include "Mathematics/Base/MathDetail.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class Vector3D : private boost::additive<Vector3D<Real>,
                                             boost::multiplicative<Vector3D<Real>, Real,
                                                                   boost::totally_ordered<Vector3D<Real>>>>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Vector3D<Real>;
        using Math = Math<Real>;
        using Tuple3 = CoreTools::Tuple<3, Real>;
        using Tuple4 = CoreTools::Tuple<4, Real>;
        using BarycentricCoordinates = BarycentricCoordinates<Real, 4>;
        using ToolsType = Vector3DTools<Real>;

         static constexpr auto sm_PointSize = 3;
           using ArrayType = std::array<Real, sm_PointSize>;

    public:
        Vector3D() noexcept;
        Vector3D(const Tuple3& tuple);
        Vector3D(Real x, Real y, Real z) noexcept;

        Vector3D& operator=(const Tuple3& tuple);

        template <typename RhsType>
        Vector3D(const Vector2D<RhsType>& vector);
        template <typename RhsType>
        Vector3D(const Vector3D<RhsType>& vector);
        template <typename RhsType>
        Vector3D(const Vector4D<RhsType>& vector);

        CLASS_INVARIANT_DECLARE;

        // �������
        Real GetXCoordinate() const;
        Real GetYCoordinate() const;
        Real GetZCoordinate() const;
        bool IsZero(const Real epsilon = Math::GetZeroTolerance()) const;

          void SetCoordinate(const ArrayType& coordinate);
        ArrayType GetCoordinate() const;

        void ZeroOut() noexcept;
        void SetCoordinate(Real x, Real y, Real z);
        void SetXCoordinate(Real x);
        void SetYCoordinate(Real y);
        void SetZCoordinate(Real z);
        void Normalize(const Real epsilon = Math::GetZeroTolerance());

        bool IsNormalize(const Real epsilon = Math::GetZeroTolerance()) const;

        const ClassType operator-() const;
        const Real& operator[](unsigned int index) const;

        Real& operator[](unsigned int index);
        ClassType& operator+=(const ClassType& rhs);
        ClassType& operator-=(const ClassType& rhs);
        ClassType& operator*=(Real rhs);
        ClassType& operator/=(Real rhs);

        // ����Vector3D
        static const Vector3D sm_Zero;  // (0,0,0)
        static const Vector3D sm_UnitX;  // (1,0,0)
        static const Vector3D sm_UnitY;  // (0,1,0)
        static const Vector3D sm_UnitZ;  // (0,0,1)
        static const Vector3D sm_One;  // (1,1,1)

        // ����ڼ������V���������굽������<V0,V1,V2,V3>
        // V = b0 * V0 + b1 * V1 + b2 * V2 + b3 * V3��
        // ����b0 + b1 + b2 + b3 = 1��
        // ���ҽ���{V0��V1��V2, V3}�������޹���ʱ����ֵ����Ч�ġ�
        // ��ֵ�ϣ����� |det[V0 V1 V2 V3]| <= epsilon��
        const BarycentricCoordinates GetBarycentrics(const ClassType& firstVector, const ClassType& secondVector, const ClassType& thirdVector,
                                                     const ClassType& fourthVector, const Real epsilon = Math::GetZeroTolerance()) const;

        const ClassType GetMove(Real t, const ClassType& velocity) const;

    private:
        using Vector3DTools = Vector3DTools<Real>;
        using AlgebraTraits = AlgebraTraits<Real>;

    private:
        Tuple3 m_Tuple;
    };

    using Vector3Df = Vector3D<float>;
    using Vector3Dd = Vector3D<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_3D_H
