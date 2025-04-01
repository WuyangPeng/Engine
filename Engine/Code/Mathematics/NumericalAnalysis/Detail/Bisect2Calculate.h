/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:53)

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

        // 固定存储,以避免在递归堆栈损耗。
        Bisect2StorageType bisect2Storage;

        // 图，由递归程序来构建。
        Bisect2NodeSharedPtr graph;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_CALCULATE_H
