/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/23 09:54)

#ifndef RENDERING_SCENE_GRAPH_SUITE_PROJECTION_MATRIX_TESTING_H
#define RENDERING_SCENE_GRAPH_SUITE_PROJECTION_MATRIX_TESTING_H

#include "Rendering/RenderingTesting/SceneGraphSuite/Detail/ViewVolumeTool.h"
#include "Rendering/RenderingTesting/SceneGraphSuite/SceneGraphTestingBase.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"

#include <gsl/pointers>

namespace Rendering
{
    class ProjectionMatrixTesting final : public SceneGraphTestingBase
    {
    public:
        using ClassType = ProjectionMatrixTesting;
        using ParentType = SceneGraphTestingBase;

    public:
        explicit ProjectionMatrixTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using FrustumTestFunction = void (ClassType::*)(const Matrix& projectionViewMatrix, const Container& frustum, float epsilon);
        using FrustumTestNotNullFunction = gsl::not_null<FrustumTestFunction>;

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void DepthTypeTest(DepthType depthType);
        void DefaultTest(bool isPerspective, DepthType depthType);
        void DefaultFrustumTest(bool isPerspective, DepthType depthType, FrustumTestNotNullFunction frustumTestFunction);
        void SetFrustumTest(bool isPerspective, DepthType depthType, FrustumTestNotNullFunction frustumTestFunction);
        NODISCARD bool ZeroToOnePerspectiveTest();
        NODISCARD bool ZeroToOneNoPerspectiveTest();
        NODISCARD bool MinusOneToOnePerspectiveTest();
        NODISCARD bool MinusOneToOneNoPerspectiveTest();

        void ZeroToOnePerspectiveFrustumTest(const Matrix& projectionViewMatrix, const Container& frustum, float epsilon);
        void ZeroToOneNoPerspectiveFrustumTest(const Matrix& projectionViewMatrix, const Container& frustum, float epsilon);
        void MinusOneToOnePerspectiveFrustumTest(const Matrix& projectionViewMatrix, const Container& frustum, float epsilon);
        void MinusOneToOneNoPerspectiveFrustumTest(const Matrix& projectionViewMatrix, const Container& frustum, float epsilon);

    private:
        MatrixApproximateFunction matrixApproximateFunction;
        ViewVolumeTool viewVolumeTool;
    };
}

#endif  // RENDERING_SCENE_GRAPH_SUITE_PROJECTION_MATRIX_TESTING_H