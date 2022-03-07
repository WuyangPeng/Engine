///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/07 11:17)

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
        AVectorOrthonormalize(const AVector& uVector, const AVector& vVector, const AVector& wVector, const Real epsilon = Math::GetZeroTolerance());

        explicit AVectorOrthonormalize(const std::vector<AVector> vectors, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD AVector GetUVector() const noexcept;
        NODISCARD AVector GetVVector() const noexcept;
        NODISCARD AVector GetWVector() const noexcept;

    private:
        void Generate();

    private:
        AVector uVector;
        AVector vVector;
        AVector wVector;
        Real epsilon;
    };

    using AVectorOrthonormalizeF = AVectorOrthonormalize<float>;
    using AVectorOrthonormalizeD = AVectorOrthonormalize<double>;
}

#endif  // MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMALIZE_H
