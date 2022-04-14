///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/01 16:00)

#ifndef RENDERING_SCENE_GRAPH_NORMAL_DERIVATIVES_H
#define RENDERING_SCENE_GRAPH_NORMAL_DERIVATIVES_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/Resources/VertexBufferAccessor.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE NormalDerivatives
    {
    public:
        using ClassType = NormalDerivatives;
        using Matrix = Mathematics::MatrixF;
        using AVector = Mathematics::AVectorF;
        using APoint = Mathematics::APointF;

    public:
        NormalDerivatives(const VertexBufferAccessor& vertexBufferAccessor);

        CLASS_INVARIANT_DECLARE;

        void ComputeEdge(const TriangleIndex& triangleIndex);
        void ComputeNormalDerivativesMatrix();
        void ComputeTangentAndBinormal();

        NODISCARD AVector GetTangent(int index) const;
        NODISCARD AVector GetBinormal(int index) const;

    private:
        void ComputeEdge(int firstIndex, int secondIndex, int thirdIndex);

    private:
        VertexBufferAccessor vertexBufferAccessor;
        std::vector<Matrix> derivativestNormal;
        std::vector<Matrix> projectMatrix;
        std::vector<Matrix> differentMatrix;
        std::vector<AVector> tangent;
        std::vector<AVector> binormal;
    };
}

#endif  // RENDERING_SCENE_GRAPH_NORMAL_DERIVATIVES_H
