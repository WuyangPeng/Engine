/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/22 16:50)

#ifndef RENDERING_SCENE_GRAPH_SUITE_SCENE_GRAPH_TESTING_BASE_H
#define RENDERING_SCENE_GRAPH_SUITE_SCENE_GRAPH_TESTING_BASE_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Mathematics/Algebra/Transform.h"
#include "Rendering/SceneGraph/Flags/CameraFlags.h"

namespace Rendering
{
    class SceneGraphTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = SceneGraphTestingBase;
        using ParentType = UnitTest;

    public:
        explicit SceneGraphTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        using APoint = Mathematics::APointF;
        using AVector = Mathematics::AVectorF;
        using Matrix = Mathematics::MatrixF;
        using Transform = Mathematics::TransformF;

        using APointApproximateFunction = bool (*)(const APoint& lhs, const APoint& rhs, float epsilon) noexcept;
        using AVectorApproximateFunction = bool (*)(const AVector& lhs, const AVector& rhs, float epsilon) noexcept;
        using MatrixApproximateFunction = bool (*)(const Matrix& lhs, const Matrix& rhs, float epsilon);
        using TransformApproximateFunction = bool (*)(const Transform& lhs, const Transform& rhs, float epsilon);

        using Container = std::array<float, System::EnumCastUnderlying(ViewFrustum::Quantity) + 3>;

    protected:
        NODISCARD static Container GetFrustum(float upFieldOfViewDegrees, float aspectRatio, float directionMin, float directionMax) noexcept;
    };
}

#endif  // RENDERING_SCENE_GRAPH_SUITE_SCENE_GRAPH_TESTING_BASE_H