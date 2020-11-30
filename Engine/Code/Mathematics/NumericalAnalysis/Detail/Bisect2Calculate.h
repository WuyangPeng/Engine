///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/19 16:15)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_CALCULATE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_CALCULATE_H

#include "Mathematics/MathematicsDll.h"

#include "Bisect2Storage.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Bisect2Calculate final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Bisect2Calculate<Real>;
        using Bisect2Storage = Bisect2Storage<Real>;
        using Bisect2Node = Bisect2Node<Real>;
        using Bisect2NodeSharedPtr = std::shared_ptr<Bisect2Node>;
        using Bisect2 = Bisect2<Real>;
        using Bisect2Root = Bisect2Root<Real>;
        using Bisect2RootSharedPtr = std::shared_ptr<Bisect2Root>;

    public:
        Bisect2Calculate(const Bisect2& bisect, Real beginPointX, Real beginPointY, Real endPointX, Real endPointY);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Bisect2Root GetRoot() const noexcept;

    private:
        void Calculate(Real beginPointX, Real beginPointY, Real endPointX, Real endPointY);

        [[nodiscard]] bool BisectRecurse(const Bisect2NodeSharedPtr& node);

    private:
        const Bisect2& m_Bisect2;
        int m_Level;
        Bisect2RootSharedPtr m_Bisect2Root;

        // �̶��洢,�Ա����ڵݹ��ջ��ġ�
        Bisect2Storage m_Bisect2Storage;

        // ͼ���ɵݹ������������
        Bisect2NodeSharedPtr m_Graph;
    };

    using FloatBisect2Calculate = Bisect2Calculate<float>;
    using DoubleBisect2Calculate = Bisect2Calculate<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_CALCULATE_H
