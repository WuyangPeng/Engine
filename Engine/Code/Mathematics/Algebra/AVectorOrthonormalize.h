///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 14:40)

#ifndef MATHEMATICS_ALGEBRA_A_VECTOR_ORTHONORMALIZE_H
#define MATHEMATICS_ALGEBRA_A_VECTOR_ORTHONORMALIZE_H

#include "Mathematics/MathematicsDll.h"

#include "AVector.h"
#include "Mathematics/Base/MathDetail.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AVectorOrthonormalize final
    {
    public:
        using ClassType = AVectorOrthonormalize<Real>;

        using MathType = Math<Real>;
        using AVectorType = AVector<Real>;

    public:
        // Gram-Schmidt��������
        // �������޹ص�����U��V��W��������һ�������飨��λ���ȣ��໥��ֱ����
        AVectorOrthonormalize(const AVectorType& uVector, const AVectorType& vVector, const AVectorType& wVector, Real epsilon = MathType::GetZeroTolerance());

        explicit AVectorOrthonormalize(const std::vector<AVectorType> vectors, Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD AVectorType GetUVector() const noexcept;
        NODISCARD AVectorType GetVVector() const noexcept;
        NODISCARD AVectorType GetWVector() const noexcept;

    private:
        void Generate();

    private:
        AVectorType uVector;
        AVectorType vVector;
        AVectorType wVector;
        Real epsilon;
    };

    using AVectorOrthonormalizeF = AVectorOrthonormalize<float>;
    using AVectorOrthonormalizeD = AVectorOrthonormalize<double>;
}

#endif  // MATHEMATICS_ALGEBRA_A_VECTOR_ORTHONORMALIZE_H
