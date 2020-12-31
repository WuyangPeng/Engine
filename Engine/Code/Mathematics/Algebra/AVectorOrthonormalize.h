///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/02 17:24)

#ifndef MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMALIZE_H
#define MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMALIZE_H

#include "Mathematics/MathematicsDll.h"

#include "AVector.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AVectorOrthonormalize final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = AVectorOrthonormalize<Real>;
        using Math = Math<Real>;
        using AVector = AVector<Real>;

    public:
        // Gram-Schmidt��������
        // �������޹ص�����U��V��W��������һ�������飨��λ���ȣ��໥��ֱ����
        AVectorOrthonormalize(const AVector& lhs, const AVector& mhs, const AVector& rhs, const Real epsilon = Math::GetZeroTolerance());

        explicit AVectorOrthonormalize(const std::vector<AVector> vectors, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const AVector GetUVector() const noexcept;
        [[nodiscard]] const AVector GetVVector() const noexcept;
        [[nodiscard]] const AVector GetWVector() const noexcept;

    private:
        void Generate();

    private:
        AVector m_UVector;
        AVector m_VVector;
        AVector m_WVector;
        Real m_Epsilon;
    };

    using FloatAVectorOrthonormalize = AVectorOrthonormalize<float>;
    using DoubleAVectorOrthonormalize = AVectorOrthonormalize<double>;
}

#endif  // MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMALIZE_H
