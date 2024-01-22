/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:53)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_STORAGE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_STORAGE_H

#include "Mathematics/MathematicsDll.h"

#include "Bisect3Node.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/Flags/BisectStorageType.h"
#include "Mathematics/NumericalAnalysis/NumericalAnalysisFwd.h"

#include <boost/noncopyable.hpp>
#include <memory>

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

        NODISCARD bool TestEightCornerValues(Real beginX, Real beginY, Real beginZ, Real endX, Real endY, Real endZ);

        NODISCARD bool TestEdgeValues();

        NODISCARD Bisect3RootSharedPtr GetBisect3Root() const noexcept;

        void SetStorageValue(Real value0, Real value1, Real value2, Bisect3StorageType type) noexcept;

        void SetStorageValue(const Bisect3NodeSharedPtr& node) noexcept;

        NODISCARD Real GetBeginPointX() const noexcept;
        NODISCARD Real GetBeginPointY() const noexcept;
        NODISCARD Real GetBeginPointZ() const noexcept;
        NODISCARD Real GetEndPointX() const noexcept;
        NODISCARD Real GetEndPointY() const noexcept;
        NODISCARD Real GetEndPointZ() const noexcept;
        NODISCARD Real GetMidpointX() const noexcept;
        NODISCARD Real GetMidpointY() const noexcept;
        NODISCARD Real GetMidpointZ() const noexcept;

        NODISCARD Real GetBeginXBeginYBeginZValue0() const noexcept;
        NODISCARD Real GetEndXBeginYBeginZValue0() const noexcept;
        NODISCARD Real GetBeginXEndYBeginZValue0() const noexcept;
        NODISCARD Real GetEndXEndYBeginZValue0() const noexcept;

        NODISCARD Real GetBeginXBeginYEndZValue0() const noexcept;
        NODISCARD Real GetEndXBeginYEndZValue0() const noexcept;
        NODISCARD Real GetBeginXEndYEndZValue0() const noexcept;
        NODISCARD Real GetEndXEndYEndZValue0() const noexcept;

        NODISCARD Real GetBeginXBeginYBeginZValue1() const noexcept;
        NODISCARD Real GetEndXBeginYBeginZValue1() const noexcept;
        NODISCARD Real GetBeginXEndYBeginZValue1() const noexcept;
        NODISCARD Real GetEndXEndYBeginZValue1() const noexcept;

        NODISCARD Real GetBeginXBeginYEndZValue1() const noexcept;
        NODISCARD Real GetEndXBeginYEndZValue1() const noexcept;
        NODISCARD Real GetBeginXEndYEndZValue1() const noexcept;
        NODISCARD Real GetEndXEndYEndZValue1() const noexcept;

        NODISCARD Real GetBeginXBeginYBeginZValue2() const noexcept;
        NODISCARD Real GetEndXBeginYBeginZValue2() const noexcept;
        NODISCARD Real GetBeginXEndYBeginZValue2() const noexcept;
        NODISCARD Real GetEndXEndYBeginZValue2() const noexcept;

        NODISCARD Real GetBeginXBeginYEndZValue2() const noexcept;
        NODISCARD Real GetEndXBeginYEndZValue2() const noexcept;
        NODISCARD Real GetBeginXEndYEndZValue2() const noexcept;
        NODISCARD Real GetEndXEndYEndZValue2() const noexcept;

        NODISCARD Real GetBeginXBeginYMidZValue0() const noexcept;
        NODISCARD Real GetEndXBeginYMidZValue0() const noexcept;
        NODISCARD Real GetBeginXEndYMidZValue0() const noexcept;
        NODISCARD Real GetEndXEndYMidZValue0() const noexcept;

        NODISCARD Real GetBeginXMidYBeginZValue0() const noexcept;
        NODISCARD Real GetEndXMidYBeginZValue0() const noexcept;
        NODISCARD Real GetBeginXMidYEndZValue0() const noexcept;
        NODISCARD Real GetEndXMidYEndZValue0() const noexcept;

        NODISCARD Real GetMidXBeginYBeginZValue0() const noexcept;
        NODISCARD Real GetMidXEndYBeginZValue0() const noexcept;
        NODISCARD Real GetMidXBeginYEndZValue0() const noexcept;
        NODISCARD Real GetMidXEndYEndZValue0() const noexcept;

        NODISCARD Real GetBeginXBeginYMidZValue1() const noexcept;
        NODISCARD Real GetEndXBeginYMidZValue1() const noexcept;
        NODISCARD Real GetBeginXEndYMidZValue1() const noexcept;
        NODISCARD Real GetEndXEndYMidZValue1() const noexcept;

        NODISCARD Real GetBeginXMidYBeginZValue1() const noexcept;
        NODISCARD Real GetEndXMidYBeginZValue1() const noexcept;
        NODISCARD Real GetBeginXMidYEndZValue1() const noexcept;
        NODISCARD Real GetEndXMidYEndZValue1() const noexcept;

        NODISCARD Real GetMidXBeginYBeginZValue1() const noexcept;
        NODISCARD Real GetMidXEndYBeginZValue1() const noexcept;
        NODISCARD Real GetMidXBeginYEndZValue1() const noexcept;
        NODISCARD Real GetMidXEndYEndZValue1() const noexcept;

        NODISCARD Real GetBeginXBeginYMidZValue2() const noexcept;
        NODISCARD Real GetEndXBeginYMidZValue2() const noexcept;
        NODISCARD Real GetBeginXEndYMidZValue2() const noexcept;
        NODISCARD Real GetEndXEndYMidZValue2() const noexcept;

        NODISCARD Real GetBeginXMidYBeginZValue2() const noexcept;
        NODISCARD Real GetEndXMidYBeginZValue2() const noexcept;
        NODISCARD Real GetBeginXMidYEndZValue2() const noexcept;
        NODISCARD Real GetEndXMidYEndZValue2() const noexcept;

        NODISCARD Real GetMidXBeginYBeginZValue2() const noexcept;
        NODISCARD Real GetMidXEndYBeginZValue2() const noexcept;
        NODISCARD Real GetMidXBeginYEndZValue2() const noexcept;
        NODISCARD Real GetMidXEndYEndZValue2() const noexcept;

        NODISCARD Real GetBeginXMidYMidZValue0() const noexcept;
        NODISCARD Real GetMidXBeginYMidZValue0() const noexcept;
        NODISCARD Real GetMidXMidYBeginZValue0() const noexcept;
        NODISCARD Real GetEndXMidYMidZValue0() const noexcept;
        NODISCARD Real GetMidXEndYMidZValue0() const noexcept;
        NODISCARD Real GetMidXMidYEndZValue0() const noexcept;

        NODISCARD Real GetBeginXMidYMidZValue1() const noexcept;
        NODISCARD Real GetMidXBeginYMidZValue1() const noexcept;
        NODISCARD Real GetMidXMidYBeginZValue1() const noexcept;
        NODISCARD Real GetEndXMidYMidZValue1() const noexcept;
        NODISCARD Real GetMidXEndYMidZValue1() const noexcept;
        NODISCARD Real GetMidXMidYEndZValue1() const noexcept;

        NODISCARD Real GetBeginXMidYMidZValue2() const noexcept;
        NODISCARD Real GetMidXBeginYMidZValue2() const noexcept;
        NODISCARD Real GetMidXMidYBeginZValue2() const noexcept;
        NODISCARD Real GetEndXMidYMidZValue2() const noexcept;
        NODISCARD Real GetMidXEndYMidZValue2() const noexcept;
        NODISCARD Real GetMidXMidYEndZValue2() const noexcept;

        NODISCARD Real GetMidXMidYMidZValue0() const noexcept;
        NODISCARD Real GetMidXMidYMidZValue1() const noexcept;
        NODISCARD Real GetMidXMidYMidZValue2() const noexcept;

    private:
        bool ZeroTest(Real x, Real y, Real z, Bisect3StorageType type);

    private:
        const Bisect3& bisect;

        // 顶点和中点的位置。
        Real beginPointX;
        Real endPointX;
        Real midpointX;
        Real beginPointY;
        Real endPointY;
        Real midpointY;
        Real beginPointZ;
        Real endPointZ;
        Real midpointZ;

        // 顶点
        Real beginXBeginYBeginZ0;
        Real endXBeginYBeginZ0;
        Real beginXEndYBeginZ0;
        Real endXEndYBeginZ0;
        Real beginXBeginYEndZ0;
        Real endXBeginYEndZ0;
        Real beginXEndYEndZ0;
        Real endXEndYEndZ0;
        Real beginXBeginYBeginZ1;
        Real endXBeginYBeginZ1;
        Real beginXEndYBeginZ1;
        Real endXEndYBeginZ1;
        Real beginXBeginYEndZ1;
        Real endXBeginYEndZ1;
        Real beginXEndYEndZ1;
        Real endXEndYEndZ1;
        Real beginXBeginYBeginZ2;
        Real endXBeginYBeginZ2;
        Real beginXEndYBeginZ2;
        Real endXEndYBeginZ2;
        Real beginXBeginYEndZ2;
        Real endXBeginYEndZ2;
        Real beginXEndYEndZ2;
        Real endXEndYEndZ2;

        // 边
        Real beginXBeginYMidZ0;
        Real endXBeginYMidZ0;
        Real beginXEndYMidZ0;
        Real endXEndYMidZ0;

        Real beginXMidYBeginZ0;
        Real endXMidYBeginZ0;
        Real beginXMidYEndZ0;
        Real endXMidYEndZ0;

        Real midXBeginYBeginZ0;
        Real midXEndYBeginZ0;
        Real midXBeginYEndZ0;
        Real midXEndYEndZ0;

        Real beginXBeginYMidZ1;
        Real endXBeginYMidZ1;
        Real beginXEndYMidZ1;
        Real endXEndYMidZ1;

        Real beginXMidYBeginZ1;
        Real endXMidYBeginZ1;
        Real beginXMidYEndZ1;
        Real endXMidYEndZ1;

        Real midXBeginYBeginZ1;
        Real midXEndYBeginZ1;
        Real midXBeginYEndZ1;
        Real midXEndYEndZ1;

        Real beginXBeginYMidZ2;
        Real endXBeginYMidZ2;
        Real beginXEndYMidZ2;
        Real endXEndYMidZ2;

        Real beginXMidYBeginZ2;
        Real endXMidYBeginZ2;
        Real beginXMidYEndZ2;
        Real endXMidYEndZ2;

        Real midXBeginYBeginZ2;
        Real midXEndYBeginZ2;
        Real midXBeginYEndZ2;
        Real midXEndYEndZ2;

        // 面
        Real beginXMidYMidZ0;
        Real midXBeginYMidZ0;
        Real midXMidYBeginZ0;
        Real endXMidYMidZ0;
        Real midXEndYMidZ0;
        Real midXMidYEndZ0;

        Real beginXMidYMidZ1;
        Real midXBeginYMidZ1;
        Real midXMidYBeginZ1;
        Real endXMidYMidZ1;
        Real midXEndYMidZ1;
        Real midXMidYEndZ1;

        Real beginXMidYMidZ2;
        Real midXBeginYMidZ2;
        Real midXMidYBeginZ2;
        Real endXMidYMidZ2;
        Real midXEndYMidZ2;
        Real midXMidYEndZ2;

        // 中心
        Real midXMidYMidZ0;
        Real midXMidYMidZ1;
        Real midXMidYMidZ2;

        Bisect3RootSharedPtr bisect3Root;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_STORAGE_H
