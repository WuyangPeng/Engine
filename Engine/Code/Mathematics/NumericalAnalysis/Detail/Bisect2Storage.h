/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:53)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_STORAGE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_STORAGE_H

#include "Mathematics/MathematicsDll.h"

#include "Bisect2Node.h"
#include "Mathematics/Base/BaseFwd.h"
#include "Mathematics/NumericalAnalysis/Flags/BisectStorageType.h"
#include "Mathematics/NumericalAnalysis/NumericalAnalysisFwd.h"

#include <boost/noncopyable.hpp>
#include <memory>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Bisect2Storage final : private boost::noncopyable
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Bisect2Storage<Real>;

        using Bisect2Root = Bisect2Root<Real>;
        using Bisect2RootSharedPtr = std::shared_ptr<Bisect2Root>;
        using MathType = Math<Real>;
        using Bisect2 = Bisect2<Real>;
        using Bisect2Node = Bisect2Node<Real>;
        using Bisect2NodeSharedPtr = std::shared_ptr<Bisect2Node>;

    public:
        explicit Bisect2Storage(const Bisect2& bisect) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool TestFourCornerValues(Real beginX, Real beginY, Real endX, Real endY);

        NODISCARD bool TestEdgeValues();

        NODISCARD Bisect2RootSharedPtr GetBisect2Root() const noexcept;

        void SetStorageValue(Real value0, Real value1, Bisect2StorageType type) noexcept;

        void SetStorageValue(const Bisect2NodeSharedPtr& node) noexcept;

        NODISCARD Real GetBeginPointX() const noexcept;
        NODISCARD Real GetBeginPointY() const noexcept;
        NODISCARD Real GetEndPointX() const noexcept;
        NODISCARD Real GetEndPointY() const noexcept;
        NODISCARD Real GetMidpointX() const noexcept;
        NODISCARD Real GetMidpointY() const noexcept;

        NODISCARD Real GetBeginXAndBeginYValue0() const noexcept;
        NODISCARD Real GetEndXAndBeginYValue0() const noexcept;
        NODISCARD Real GetBeginXAndEndYValue0() const noexcept;
        NODISCARD Real GetEndXAndEndYValue0() const noexcept;

        NODISCARD Real GetBeginXAndMidYValue0() const noexcept;
        NODISCARD Real GetEndXAndMidYValue0() const noexcept;
        NODISCARD Real GetMidXAndBeginYValue0() const noexcept;
        NODISCARD Real GetMidXAndEndYValue0() const noexcept;
        NODISCARD Real GetMidXAndMidYValue0() const noexcept;

        NODISCARD Real GetBeginXAndBeginYValue1() const noexcept;
        NODISCARD Real GetEndXAndBeginYValue1() const noexcept;
        NODISCARD Real GetBeginXAndEndYValue1() const noexcept;
        NODISCARD Real GetEndXAndEndYValue1() const noexcept;

        NODISCARD Real GetBeginXAndMidYValue1() const noexcept;
        NODISCARD Real GetEndXAndMidYValue1() const noexcept;
        NODISCARD Real GetMidXAndBeginYValue1() const noexcept;
        NODISCARD Real GetMidXAndEndYValue1() const noexcept;
        NODISCARD Real GetMidXAndMidYValue1() const noexcept;

    private:
        bool ZeroTest(Real x, Real y, Bisect2StorageType type);

    private:
        const Bisect2& bisect;

        // 固定存储,以避免在递归中的堆栈损耗。
        Real beginPointX;
        Real beginPointY;
        Real endPointX;
        Real endPointY;
        Real midpointX;
        Real midpointY;

        Real beginXAndBeginY0;
        Real endXAndBeginY0;
        Real beginXAndEndY0;
        Real endXAndEndY0;

        Real beginXAndMidY0;
        Real endXAndMidY0;
        Real midXAndBeginY0;
        Real midXAndEndY0;
        Real midXAndMidY0;

        Real beginXAndBeginY1;
        Real endXAndBeginY1;
        Real beginXAndEndY1;
        Real endXAndEndY1;

        Real beginXAndMidY1;
        Real endXAndMidY1;
        Real midXAndBeginY1;
        Real midXAndEndY1;
        Real midXAndMidY1;

        Bisect2RootSharedPtr bisect2Root;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_STORAGE_H
