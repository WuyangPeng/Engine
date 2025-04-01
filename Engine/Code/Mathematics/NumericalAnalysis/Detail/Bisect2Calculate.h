/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 13:53)

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

        using Bisect2Type = Bisect2<Real>;
        using Bisect2Root = Bisect2Root<Real>;
        using Bisect2RootSharedPtr = std::shared_ptr<Bisect2Root>;
        using Bisect2StorageType = Bisect2Storage<Real>;
        using Bisect2NodeType = Bisect2Node<Real>;
        using Bisect2NodeSharedPtr = std::shared_ptr<Bisect2NodeType>;

    public:
        Bisect2Calculate(const Bisect2Type& bisect, Real beginPointX, Real beginPointY, Real endPointX, Real endPointY);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Bisect2Root GetRoot() const noexcept;

    private:
        void Calculate(Real beginPointX, Real beginPointY, Real endPointX, Real endPointY);

        NODISCARD bool BisectRecurse(const Bisect2NodeSharedPtr& node);

    private:
        const Bisect2Type& bisect2;
        int level;
        Bisect2RootSharedPtr bisect2Root;

        // �̶��洢,�Ա����ڵݹ��ջ��ġ�
        Bisect2StorageType bisect2Storage;

        // ͼ���ɵݹ������������
        Bisect2NodeSharedPtr graph;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_CALCULATE_H
