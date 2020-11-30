///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/20 16:10)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_STORAGE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_STORAGE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/Flags/BisectStorageType.h"
#include "Mathematics/NumericalAnalysis/NumericalAnalysisFwd.h"

#include <boost/noncopyable.hpp>
#include <memory>
#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Bisect3Storage final : private boost::noncopyable
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Bisect3Storage<Real>;
        using Bisect3Root = Bisect3Root<Real>;
        using Bisect3RootSharedPtr = std::shared_ptr<Bisect3Root>;
        using Bisect3 = Bisect3<Real>;
        using Bisect3Node = Bisect3Node<Real>;
        using Bisect3NodeSharedPtr = std::shared_ptr<Bisect3Node>;
        using Math = Math<Real>;

    public:
        explicit Bisect3Storage(const Bisect3& bisect) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] bool TestEightCornerValues(Real beginPointX, Real beginPointY, Real beginPointZ, Real endPointX, Real endPointY, Real endPointZ);

        [[nodiscard]] bool TestEdgeValues();

        [[nodiscard]] const Bisect3RootSharedPtr GetBisect3Root() const noexcept;

        void SetStorageValue(Real value0, Real value1, Real value2, Bisect3StorageType type) noexcept;

        void SetStorageValue(const Bisect3NodeSharedPtr& node) noexcept;

        [[nodiscard]] Real GetBeginPointX() const noexcept;
        [[nodiscard]] Real GetBeginPointY() const noexcept;
        [[nodiscard]] Real GetBeginPointZ() const noexcept;
        [[nodiscard]] Real GetEndPointX() const noexcept;
        [[nodiscard]] Real GetEndPointY() const noexcept;
        [[nodiscard]] Real GetEndPointZ() const noexcept;
        [[nodiscard]] Real GetMidpointX() const noexcept;
        [[nodiscard]] Real GetMidpointY() const noexcept;
        [[nodiscard]] Real GetMidpointZ() const noexcept;

        [[nodiscard]] Real GetBeginXBeginYBeginZValue0() const noexcept;
        [[nodiscard]] Real GetEndXBeginYBeginZValue0() const noexcept;
        [[nodiscard]] Real GetBeginXEndYBeginZValue0() const noexcept;
        [[nodiscard]] Real GetEndXEndYBeginZValue0() const noexcept;

        [[nodiscard]] Real GetBeginXBeginYEndZValue0() const noexcept;
        [[nodiscard]] Real GetEndXBeginYEndZValue0() const noexcept;
        [[nodiscard]] Real GetBeginXEndYEndZValue0() const noexcept;
        [[nodiscard]] Real GetEndXEndYEndZValue0() const noexcept;

        [[nodiscard]] Real GetBeginXBeginYBeginZValue1() const noexcept;
        [[nodiscard]] Real GetEndXBeginYBeginZValue1() const noexcept;
        [[nodiscard]] Real GetBeginXEndYBeginZValue1() const noexcept;
        [[nodiscard]] Real GetEndXEndYBeginZValue1() const noexcept;

        [[nodiscard]] Real GetBeginXBeginYEndZValue1() const noexcept;
        [[nodiscard]] Real GetEndXBeginYEndZValue1() const noexcept;
        [[nodiscard]] Real GetBeginXEndYEndZValue1() const noexcept;
        [[nodiscard]] Real GetEndXEndYEndZValue1() const noexcept;

        [[nodiscard]] Real GetBeginXBeginYBeginZValue2() const noexcept;
        [[nodiscard]] Real GetEndXBeginYBeginZValue2() const noexcept;
        [[nodiscard]] Real GetBeginXEndYBeginZValue2() const noexcept;
        [[nodiscard]] Real GetEndXEndYBeginZValue2() const noexcept;

        [[nodiscard]] Real GetBeginXBeginYEndZValue2() const noexcept;
        [[nodiscard]] Real GetEndXBeginYEndZValue2() const noexcept;
        [[nodiscard]] Real GetBeginXEndYEndZValue2() const noexcept;
        [[nodiscard]] Real GetEndXEndYEndZValue2() const noexcept;

        [[nodiscard]] Real GetBeginXBeginYMidZValue0() const noexcept;
        [[nodiscard]] Real GetEndXBeginYMidZValue0() const noexcept;
        [[nodiscard]] Real GetBeginXEndYMidZValue0() const noexcept;
        [[nodiscard]] Real GetEndXEndYMidZValue0() const noexcept;

        [[nodiscard]] Real GetBeginXMidYBeginZValue0() const noexcept;
        [[nodiscard]] Real GetEndXMidYBeginZValue0() const noexcept;
        [[nodiscard]] Real GetBeginXMidYEndZValue0() const noexcept;
        [[nodiscard]] Real GetEndXMidYEndZValue0() const noexcept;

        [[nodiscard]] Real GetMidXBeginYBeginZValue0() const noexcept;
        [[nodiscard]] Real GetMidXEndYBeginZValue0() const noexcept;
        [[nodiscard]] Real GetMidXBeginYEndZValue0() const noexcept;
        [[nodiscard]] Real GetMidXEndYEndZValue0() const noexcept;

        [[nodiscard]] Real GetBeginXBeginYMidZValue1() const noexcept;
        [[nodiscard]] Real GetEndXBeginYMidZValue1() const noexcept;
        [[nodiscard]] Real GetBeginXEndYMidZValue1() const noexcept;
        [[nodiscard]] Real GetEndXEndYMidZValue1() const noexcept;

        [[nodiscard]] Real GetBeginXMidYBeginZValue1() const noexcept;
        [[nodiscard]] Real GetEndXMidYBeginZValue1() const noexcept;
        [[nodiscard]] Real GetBeginXMidYEndZValue1() const noexcept;
        [[nodiscard]] Real GetEndXMidYEndZValue1() const noexcept;

        [[nodiscard]] Real GetMidXBeginYBeginZValue1() const noexcept;
        [[nodiscard]] Real GetMidXEndYBeginZValue1() const noexcept;
        [[nodiscard]] Real GetMidXBeginYEndZValue1() const noexcept;
        [[nodiscard]] Real GetMidXEndYEndZValue1() const noexcept;

        [[nodiscard]] Real GetBeginXBeginYMidZValue2() const noexcept;
        [[nodiscard]] Real GetEndXBeginYMidZValue2() const noexcept;
        [[nodiscard]] Real GetBeginXEndYMidZValue2() const noexcept;
        [[nodiscard]] Real GetEndXEndYMidZValue2() const noexcept;

        [[nodiscard]] Real GetBeginXMidYBeginZValue2() const noexcept;
        [[nodiscard]] Real GetEndXMidYBeginZValue2() const noexcept;
        [[nodiscard]] Real GetBeginXMidYEndZValue2() const noexcept;
        [[nodiscard]] Real GetEndXMidYEndZValue2() const noexcept;

        [[nodiscard]] Real GetMidXBeginYBeginZValue2() const noexcept;
        [[nodiscard]] Real GetMidXEndYBeginZValue2() const noexcept;
        [[nodiscard]] Real GetMidXBeginYEndZValue2() const noexcept;
        [[nodiscard]] Real GetMidXEndYEndZValue2() const noexcept;

        [[nodiscard]] Real GetBeginXMidYMidZValue0() const noexcept;
        [[nodiscard]] Real GetMidXBeginYMidZValue0() const noexcept;
        [[nodiscard]] Real GetMidXMidYBeginZValue0() const noexcept;
        [[nodiscard]] Real GetEndXMidYMidZValue0() const noexcept;
        [[nodiscard]] Real GetMidXEndYMidZValue0() const noexcept;
        [[nodiscard]] Real GetMidXMidYEndZValue0() const noexcept;

        [[nodiscard]] Real GetBeginXMidYMidZValue1() const noexcept;
        [[nodiscard]] Real GetMidXBeginYMidZValue1() const noexcept;
        [[nodiscard]] Real GetMidXMidYBeginZValue1() const noexcept;
        [[nodiscard]] Real GetEndXMidYMidZValue1() const noexcept;
        [[nodiscard]] Real GetMidXEndYMidZValue1() const noexcept;
        [[nodiscard]] Real GetMidXMidYEndZValue1() const noexcept;

        [[nodiscard]] Real GetBeginXMidYMidZValue2() const noexcept;
        [[nodiscard]] Real GetMidXBeginYMidZValue2() const noexcept;
        [[nodiscard]] Real GetMidXMidYBeginZValue2() const noexcept;
        [[nodiscard]] Real GetEndXMidYMidZValue2() const noexcept;
        [[nodiscard]] Real GetMidXEndYMidZValue2() const noexcept;
        [[nodiscard]] Real GetMidXMidYEndZValue2() const noexcept;

        [[nodiscard]] Real GetMidXMidYMidZValue0() const noexcept;
        [[nodiscard]] Real GetMidXMidYMidZValue1() const noexcept;
        [[nodiscard]] Real GetMidXMidYMidZValue2() const noexcept;

    private:
        bool ZeroTest(Real x, Real y, Real z, Bisect3StorageType type);

    private:
        const Bisect3& m_Bisect;

        // 顶点和中点的位置。
        Real m_BeginPointX;
        Real m_EndPointX;
        Real m_MidpointX;
        Real m_BeginPointY;
        Real m_EndPointY;
        Real m_MidpointY;
        Real m_BeginPointZ;
        Real m_EndPointZ;
        Real m_MidpointZ;

        // 顶点
        Real m_BeginXBeginYBeginZ0;
        Real m_EndXBeginYBeginZ0;
        Real m_BeginXEndYBeginZ0;
        Real m_EndXEndYBeginZ0;
        Real m_BeginXBeginYEndZ0;
        Real m_EndXBeginYEndZ0;
        Real m_BeginXEndYEndZ0;
        Real m_EndXEndYEndZ0;
        Real m_BeginXBeginYBeginZ1;
        Real m_EndXBeginYBeginZ1;
        Real m_BeginXEndYBeginZ1;
        Real m_EndXEndYBeginZ1;
        Real m_BeginXBeginYEndZ1;
        Real m_EndXBeginYEndZ1;
        Real m_BeginXEndYEndZ1;
        Real m_EndXEndYEndZ1;
        Real m_BeginXBeginYBeginZ2;
        Real m_EndXBeginYBeginZ2;
        Real m_BeginXEndYBeginZ2;
        Real m_EndXEndYBeginZ2;
        Real m_BeginXBeginYEndZ2;
        Real m_EndXBeginYEndZ2;
        Real m_BeginXEndYEndZ2;
        Real m_EndXEndYEndZ2;

        // 边
        Real m_BeginXBeginYMidZ0;
        Real m_EndXBeginYMidZ0;
        Real m_BeginXEndYMidZ0;
        Real m_EndXEndYMidZ0;

        Real m_BeginXMidYBeginZ0;
        Real m_EndXMidYBeginZ0;
        Real m_BeginXMidYEndZ0;
        Real m_EndXMidYEndZ0;

        Real m_MidXBeginYBeginZ0;
        Real m_MidXEndYBeginZ0;
        Real m_MidXBeginYEndZ0;
        Real m_MidXEndYEndZ0;

        Real m_BeginXBeginYMidZ1;
        Real m_EndXBeginYMidZ1;
        Real m_BeginXEndYMidZ1;
        Real m_EndXEndYMidZ1;

        Real m_BeginXMidYBeginZ1;
        Real m_EndXMidYBeginZ1;
        Real m_BeginXMidYEndZ1;
        Real m_EndXMidYEndZ1;

        Real m_MidXBeginYBeginZ1;
        Real m_MidXEndYBeginZ1;
        Real m_MidXBeginYEndZ1;
        Real m_MidXEndYEndZ1;

        Real m_BeginXBeginYMidZ2;
        Real m_EndXBeginYMidZ2;
        Real m_BeginXEndYMidZ2;
        Real m_EndXEndYMidZ2;

        Real m_BeginXMidYBeginZ2;
        Real m_EndXMidYBeginZ2;
        Real m_BeginXMidYEndZ2;
        Real m_EndXMidYEndZ2;

        Real m_MidXBeginYBeginZ2;
        Real m_MidXEndYBeginZ2;
        Real m_MidXBeginYEndZ2;
        Real m_MidXEndYEndZ2;

        // 面
        Real m_BeginXMidYMidZ0;
        Real m_MidXBeginYMidZ0;
        Real m_MidXMidYBeginZ0;
        Real m_EndXMidYMidZ0;
        Real m_MidXEndYMidZ0;
        Real m_MidXMidYEndZ0;

        Real m_BeginXMidYMidZ1;
        Real m_MidXBeginYMidZ1;
        Real m_MidXMidYBeginZ1;
        Real m_EndXMidYMidZ1;
        Real m_MidXEndYMidZ1;
        Real m_MidXMidYEndZ1;

        Real m_BeginXMidYMidZ2;
        Real m_MidXBeginYMidZ2;
        Real m_MidXMidYBeginZ2;
        Real m_EndXMidYMidZ2;
        Real m_MidXEndYMidZ2;
        Real m_MidXMidYEndZ2;

        // 中心
        Real m_MidXMidYMidZ0;
        Real m_MidXMidYMidZ1;
        Real m_MidXMidYMidZ2;

        Bisect3RootSharedPtr m_Bisect3Root;
    };

    using FloatBisect3Storage = Bisect3Storage<float>;
    using DoubleBisect3Storage = Bisect3Storage<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_STORAGE_H
