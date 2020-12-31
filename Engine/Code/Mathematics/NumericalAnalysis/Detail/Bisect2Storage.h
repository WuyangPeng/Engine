///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 15:54)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_STORAGE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_STORAGE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/NumericalAnalysis/Flags/BisectStorageType.h"
#include "Mathematics/NumericalAnalysis/NumericalAnalysisFwd.h"

#include <boost/noncopyable.hpp>
#include <type_traits>

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
        using Math = Math<Real>;
        using Bisect2 = Bisect2<Real>;
        using Bisect2Node = Bisect2Node<Real>;
        using Bisect2NodeSharedPtr = std::shared_ptr<Bisect2Node>;

    public:
        explicit Bisect2Storage(const Bisect2& bisect) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] bool TestFourCornerValues(Real beginPointX, Real beginPointY, Real endPointX, Real endPointY);

        [[nodiscard]] bool TestEdgeValues();

        [[nodiscard]] const Bisect2RootSharedPtr GetBisect2Root() const noexcept;

        void SetStorageValue(Real value0, Real value1, Bisect2StorageType type) noexcept;

        void SetStorageValue(const Bisect2NodeSharedPtr& node) noexcept;

        [[nodiscard]] Real GetBeginPointX() const noexcept;
        [[nodiscard]] Real GetBeginPointY() const noexcept;
        [[nodiscard]] Real GetEndPointX() const noexcept;
        [[nodiscard]] Real GetEndPointY() const noexcept;
        [[nodiscard]] Real GetMidpointX() const noexcept;
        [[nodiscard]] Real GetMidpointY() const noexcept;

        [[nodiscard]] Real GetBeginXAndBeginYValue0() const noexcept;
        [[nodiscard]] Real GetEndXAndBeginYValue0() const noexcept;
        [[nodiscard]] Real GetBeginXAndEndYValue0() const noexcept;
        [[nodiscard]] Real GetEndXAndEndYValue0() const noexcept;

        [[nodiscard]] Real GetBeginXAndMidYValue0() const noexcept;
        [[nodiscard]] Real GetEndXAndMidYValue0() const noexcept;
        [[nodiscard]] Real GetMidXAndBeginYValue0() const noexcept;
        [[nodiscard]] Real GetMidXAndEndYValue0() const noexcept;
        [[nodiscard]] Real GetMidXAndMidYValue0() const noexcept;

        [[nodiscard]] Real GetBeginXAndBeginYValue1() const noexcept;
        [[nodiscard]] Real GetEndXAndBeginYValue1() const noexcept;
        [[nodiscard]] Real GetBeginXAndEndYValue1() const noexcept;
        [[nodiscard]] Real GetEndXAndEndYValue1() const noexcept;

        [[nodiscard]] Real GetBeginXAndMidYValue1() const noexcept;
        [[nodiscard]] Real GetEndXAndMidYValue1() const noexcept;
        [[nodiscard]] Real GetMidXAndBeginYValue1() const noexcept;
        [[nodiscard]] Real GetMidXAndEndYValue1() const noexcept;
        [[nodiscard]] Real GetMidXAndMidYValue1() const noexcept;

    private:
        bool ZeroTest(Real x, Real y, Bisect2StorageType type);

    private:
        const Bisect2& m_Bisect;

        // 固定存储,以避免在递归中的堆栈损耗。
        Real m_BeginPointX;
        Real m_BeginPointY;
        Real m_EndPointX;
        Real m_EndPointY;
        Real m_MidpointX;
        Real m_MidpointY;

        Real m_BeginXAndBeginY0;
        Real m_EndXAndBeginY0;
        Real m_BeginXAndEndY0;
        Real m_EndXAndEndY0;

        Real m_BeginXAndMidY0;
        Real m_EndXAndMidY0;
        Real m_MidXAndBeginY0;
        Real m_MidXAndEndY0;
        Real m_MidXAndMidY0;

        Real m_BeginXAndBeginY1;
        Real m_EndXAndBeginY1;
        Real m_BeginXAndEndY1;
        Real m_EndXAndEndY1;

        Real m_BeginXAndMidY1;
        Real m_EndXAndMidY1;
        Real m_MidXAndBeginY1;
        Real m_MidXAndEndY1;
        Real m_MidXAndMidY1;

        Bisect2RootSharedPtr m_Bisect2Root;
    };

    using FloatBisect2Storage = Bisect2Storage<float>;
    using DoubleBisect2Storage = Bisect2Storage<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_STORAGE_H
