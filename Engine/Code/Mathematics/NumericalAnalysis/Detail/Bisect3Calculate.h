///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/14 13:49)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_CALCULATE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_CALCULATE_H

#include "Mathematics/MathematicsDll.h"

#include "Bisect3Storage.h"
#include "Mathematics/NumericalAnalysis/Bisect3Root.h"
#include "Mathematics/NumericalAnalysis/NumericalAnalysisFwd.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Bisect3Calculate final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Bisect3Calculate<Real>;
        using Bisect3Storage = Bisect3Storage<Real>;
        using Bisect3Node = Bisect3Node<Real>;
        using Bisect3NodeSharedPtr = std::shared_ptr<Bisect3Node>;
        using Bisect3Root = Bisect3Root<Real>;
        using Bisect3RootSharedPtr = std::shared_ptr<Bisect3Root>;
        using Bisect3 = Bisect3<Real>;

    public:
        Bisect3Calculate(const Bisect3& bisect,
                         Real beginPointX,
                         Real beginPointY,
                         Real beginPointZ,
                         Real endPointX,
                         Real endPointY,
                         Real endPointZ);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Bisect3Root GetRoot() const noexcept;

    private:
        void Calculate(Real beginPointX,
                       Real beginPointY,
                       Real beginPointZ,
                       Real endPointX,
                       Real endPointY,
                       Real endPointZ);

        NODISCARD bool BisectRecurse(const Bisect3NodeSharedPtr& node);

        void BuildLeftLowerInside(const Bisect3NodeSharedPtr& node);
        void BuildRightLowerInside(const Bisect3NodeSharedPtr& node);
        void BuildLeftUpperInside(const Bisect3NodeSharedPtr& node);
        void BuildRightUpperInside(const Bisect3NodeSharedPtr& node);
        void BuildLeftLowerOutside(const Bisect3NodeSharedPtr& node);
        void BuildRightLowerOutside(const Bisect3NodeSharedPtr& node);
        void BuildLeftUpperOutside(const Bisect3NodeSharedPtr& node);
        void BuildRightUpperOutside(const Bisect3NodeSharedPtr& node);

    private:
        const Bisect3& bisect3;
        int level;
        Bisect3RootSharedPtr bisect3Root;

        // 固定存储,以避免在递归堆栈损耗。
        Bisect3Storage bisect3Storage;

        // 图，由递归程序来构建。
        Bisect3NodeSharedPtr graph;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_CALCULATE_H
