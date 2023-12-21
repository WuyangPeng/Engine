/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/22 12:31)

#ifndef RENDERING_SCENE_GRAPH_SUITE_VIEW_VOLUME_TOOL_H
#define RENDERING_SCENE_GRAPH_SUITE_VIEW_VOLUME_TOOL_H

#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/BoundingSphere.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Mathematics/Algebra/Transform.h"

#include <random>

namespace Rendering
{
    class ViewVolumeTool
    {
    public:
        using ClassType = ViewVolumeTool;

        using APoint = Mathematics::APointF;
        using AVector = Mathematics::AVectorF;
        using Matrix = Mathematics::MatrixF;
        using Transform = Mathematics::TransformF;
        using BoundingSphere = Mathematics::BoundingSphereF;

        using AVectorContainer = std::array<AVector, 3>;

    public:
        explicit ViewVolumeTool(uint32_t randomSeed);

        CLASS_INVARIANT_DECLARE;

        NODISCARD APoint ComputePosition();
        NODISCARD AVector ComputeVector();
        void ComputeAxes(float epsilon);
        NODISCARD Matrix ComputeMatrix(float epsilon);
        NODISCARD Transform ComputeTransform(float epsilon);
        NODISCARD BoundingSphere ComputeBoundingSphere();

        NODISCARD AVector GetDirectionVector() const noexcept;
        NODISCARD AVector GetUpVector() const noexcept;
        NODISCARD AVector GetRightVector() const noexcept;
        NODISCARD AVectorContainer GetVector() const noexcept;

        NODISCARD float GetRandomProportion();

    private:
        std::default_random_engine generator;
        std::uniform_real<float> randomDistribution;

        AVector directionVector;
        AVector upVector;
        AVector rightVector;
    };

}

#endif  // RENDERING_SCENE_GRAPH_SUITE_VIEW_VOLUME_TOOL_H