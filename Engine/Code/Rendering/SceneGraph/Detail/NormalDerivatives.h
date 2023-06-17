///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:07)

#ifndef RENDERING_SCENE_GRAPH_NORMAL_DERIVATIVES_H
#define RENDERING_SCENE_GRAPH_NORMAL_DERIVATIVES_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"
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
        NormalDerivatives(const VertexBuffer& vertexBufferAccessor);

        CLASS_INVARIANT_DECLARE;

        void ComputeEdge(const TriangleIndex& triangleIndex);
        void ComputeNormalDerivativesMatrix();
        void ComputeTangentAndBinormal();

        NODISCARD AVector GetTangent(int index) const;
        NODISCARD AVector GetBinormal(int index) const;

    private:
        void ComputeEdge(int firstIndex, int secondIndex, int thirdIndex);

    private:
        VertexBuffer vertexBufferAccessor;
        std::vector<Matrix> derivativestNormal;
        std::vector<Matrix> projectMatrix;
        std::vector<Matrix> differentMatrix;
        std::vector<AVector> tangent;
        std::vector<AVector> binormal;
    };
}

#endif  // RENDERING_SCENE_GRAPH_NORMAL_DERIVATIVES_H
