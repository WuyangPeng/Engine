///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:13)

#include "Rendering/RenderingExport.h"

#include "NormalDerivatives.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Rendering/SceneGraph/TriangleIndex.h"

#include <gsl/util>

Rendering::NormalDerivatives::NormalDerivatives(const VertexBuffer& vertexBufferAccessor)
    : vertexBufferAccessor{ vertexBufferAccessor },
      derivativestNormal{ vertexBufferAccessor.GetElementSize() },
      projectMatrix{ vertexBufferAccessor.GetElementSize() },
      differentMatrix{ vertexBufferAccessor.GetElementSize() },
      tangent{ vertexBufferAccessor.GetElementSize() },
      binormal{ vertexBufferAccessor.GetElementSize() }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::NormalDerivatives::IsValid() const noexcept
{
    const auto numVertices = gsl::narrow_cast<size_t>(vertexBufferAccessor.GetElementSize());

    if (numVertices == derivativestNormal.size() &&
        projectMatrix.size() == derivativestNormal.size() &&
        tangent.size() == binormal.size() &&
        numVertices == projectMatrix.size() &&
        numVertices == tangent.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::NormalDerivatives::ComputeEdge(const TriangleIndex& triangleIndex)
{
    RENDERING_CLASS_IS_VALID_1;

    ComputeEdge(triangleIndex.GetFirstIndex(), triangleIndex.GetSecondIndex(), triangleIndex.GetThirdIndex());
    ComputeEdge(triangleIndex.GetSecondIndex(), triangleIndex.GetThirdIndex(), triangleIndex.GetFirstIndex());
    ComputeEdge(triangleIndex.GetThirdIndex(), triangleIndex.GetFirstIndex(), triangleIndex.GetSecondIndex());
}

// private
void Rendering::NormalDerivatives::ComputeEdge(int firstIndex, MAYBE_UNUSED int secondIndex, MAYBE_UNUSED int thirdIndex)
{
    // 获取顶点位置和法线
    const auto position0 = APoint{};
    const auto position1 = APoint{};
    const auto position2 = APoint{};

    const auto normal0 = AVector{};
    const auto normal1 = AVector{};
    const auto normal2 = AVector{};

    // 计算pos0到pos1的边，投射顶点的切平面,并计算相邻法线的差。
    auto edge = position1 - position0;
    auto project = edge - Dot(edge, normal0) * normal0;
    auto difference = normal1 - normal0;
    for (auto row = 0; row < 3; ++row)
    {
        for (auto col = 0; col < 3; ++col)
        {
            projectMatrix.at(firstIndex)(row, col) += project[row] * project[col];
            differentMatrix.at(firstIndex)(row, col) += difference[row] * project[col];
        }
    }

    // 计算pos0到pos2的边，投射顶点的切平面,并计算相邻法线的差。
    edge = position2 - position0;
    project = edge - Dot(edge, normal0) * normal0;
    difference = normal2 - normal0;
    for (auto row = 0; row < 3; ++row)
    {
        for (auto col = 0; col < 3; ++col)
        {
            projectMatrix.at(firstIndex)(row, col) += project[row] * project[col];
            differentMatrix.at(firstIndex)(row, col) += difference[row] * project[col];
        }
    }
}

void Rendering::NormalDerivatives::ComputeNormalDerivativesMatrix()
{
    RENDERING_CLASS_IS_VALID_1;

    // 添加N * N^T 到W * W^T为了数值稳定性。
    // 理论上是0 * 0^T 添加到D * W^T,当然不需要更新的实现。
    // 计算矩阵法线的导数。
    constexpr auto numVertices = 10;
    for (auto index = 0; index < numVertices; ++index)
    {
        auto normal = AVector{};
        for (auto row = 0; row < 3; ++row)
        {
            for (auto col = 0; col < 3; ++col)
            {
                projectMatrix.at(index)(row, col) += 0.5f * projectMatrix.at(index)(row, col) + normal[row] * normal[col];
                differentMatrix.at(index)(row, col) *= 0.5f;
            }
        }

        projectMatrix.at(index).SetColumn(3, Mathematics::APointF::GetOrigin().GetHomogeneousPoint());
        derivativestNormal.at(index) = differentMatrix.at(index) * projectMatrix.at(index).Inverse();
    }
}

void Rendering::NormalDerivatives::ComputeTangentAndBinormal()
{
    RENDERING_CLASS_IS_VALID_1;

    // 如果N是一个顶点的单位长度法线,
    // 让U和V单位长度切线 {U, V, N}是一个标准正交集合。
    // 定义矩阵J =[U | V],一个3×2矩阵的列是U和V 。
    // 定义J ^ T为它的转置,是一个2×3矩阵。
    // 让dN / dX表示矩阵的一阶导数法线的向量场。
    // 模型矩阵是
    //   S = (J^T * J)^{-1} * J^T * dN / dX * J = J^T * dN / dX * J
    // 这里上标-1表示逆矩阵。(公式允许J为非正交向量。)
    // 矩阵S 是2×2矩阵。
    // 主曲率是S的特征值。
    // 如果k是一个主曲率和W是2×1相对应的特征向量,然后S * W = k * W(根据定义)。
    // 相应的3×1切向量的顶点称为k的主方向,是J * W。
    // 最小主曲率的主方向存储网格切线。最大主曲率的主方向存储网格双切线。

    constexpr auto numVertices = 10;
    for (auto index = 0; index < numVertices; ++index)
    {
        // 通过N计算 U 和 V。
        const auto normal = AVector{};
        const auto aVectorOrthonormalBasis = GenerateComplementBasis(normal);

        const auto uNormal = aVectorOrthonormalBasis.GetUVector();
        const auto vNormal = aVectorOrthonormalBasis.GetVVector();
        const auto wNormal = aVectorOrthonormalBasis.GetWVector();

        // 计算S = J^T * dN / dX * J .
        // 理论上S是对称的,但因为我们估算dN/dX，
        // 我们必须稍微调整我们的计算,以确保S是对称的。
        auto symmetric01 = Dot(uNormal, derivativestNormal.at(index) * vNormal);
        auto symmetric10 = Dot(vNormal, derivativestNormal.at(index) * uNormal);
        const auto symmetricAverage = 0.5f * (symmetric01 + symmetric10);
        const float symmetricMat[2][2]{
            { Dot(uNormal, derivativestNormal.at(index) * uNormal), symmetricAverage },
            { symmetricAverage, Dot(vNormal, derivativestNormal.at(index) * vNormal) }
        };

        // 计算S的特征值(最小和最大曲率)。
        const auto trace = symmetricMat[0][0] + symmetricMat[1][1];
        const auto det = symmetricMat[0][0] * symmetricMat[1][1] - symmetricMat[0][1] * symmetricMat[1][0];
        const auto discr = trace * trace - 4.0f * det;
        auto rootDiscr = Mathematics::MathF::Sqrt(Mathematics::MathF::FAbs(discr));
        const auto minCurvature = 0.5f * (trace - rootDiscr);
        // float maxCurvature = 0.5f * (trace + rootDiscr);

        // 计算S的特征向量.
        AVector evec0{ symmetricMat[0][1], minCurvature - symmetricMat[0][0], 0.0f };
        AVector evec1{ minCurvature - symmetricMat[1][1], symmetricMat[1][0], 0.0f };
        AVector tanvec, binvec;
        if (evec0.SquaredLength() >= evec1.SquaredLength())
        {
            evec0.Normalize();
            tanvec = evec0[0] * uNormal + evec0[1] * vNormal;
            binvec = Cross(wNormal, tanvec);
        }
        else
        {
            evec1.Normalize();
            tanvec = evec1[0] * uNormal + evec1[1] * vNormal;
            binvec = Cross(wNormal, tanvec);
        }

        tangent.at(index) = tanvec;
        binormal.at(index) = binvec;
    }
}

Rendering::NormalDerivatives::AVector Rendering::NormalDerivatives::GetTangent(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return tangent.at(index);
}

Rendering::NormalDerivatives::AVector Rendering::NormalDerivatives::GetBinormal(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return binormal.at(index);
}
