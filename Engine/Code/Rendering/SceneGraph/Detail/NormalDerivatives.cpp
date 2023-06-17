///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:13)

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
    // ��ȡ����λ�úͷ���
    const auto position0 = APoint{};
    const auto position1 = APoint{};
    const auto position2 = APoint{};

    const auto normal0 = AVector{};
    const auto normal1 = AVector{};
    const auto normal2 = AVector{};

    // ����pos0��pos1�ıߣ�Ͷ�䶥�����ƽ��,���������ڷ��ߵĲ
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

    // ����pos0��pos2�ıߣ�Ͷ�䶥�����ƽ��,���������ڷ��ߵĲ
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

    // ���N * N^T ��W * W^TΪ����ֵ�ȶ��ԡ�
    // ��������0 * 0^T ��ӵ�D * W^T,��Ȼ����Ҫ���µ�ʵ�֡�
    // ��������ߵĵ�����
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

    // ���N��һ������ĵ�λ���ȷ���,
    // ��U��V��λ�������� {U, V, N}��һ����׼�������ϡ�
    // �������J =[U | V],һ��3��2���������U��V ��
    // ����J ^ TΪ����ת��,��һ��2��3����
    // ��dN / dX��ʾ�����һ�׵������ߵ���������
    // ģ�;�����
    //   S = (J^T * J)^{-1} * J^T * dN / dX * J = J^T * dN / dX * J
    // �����ϱ�-1��ʾ�����(��ʽ����JΪ������������)
    // ����S ��2��2����
    // ��������S������ֵ��
    // ���k��һ�������ʺ�W��2��1���Ӧ����������,Ȼ��S * W = k * W(���ݶ���)��
    // ��Ӧ��3��1�������Ķ����Ϊk��������,��J * W��
    // ��С�����ʵ�������洢�������ߡ���������ʵ�������洢����˫���ߡ�

    constexpr auto numVertices = 10;
    for (auto index = 0; index < numVertices; ++index)
    {
        // ͨ��N���� U �� V��
        const auto normal = AVector{};
        const auto aVectorOrthonormalBasis = GenerateComplementBasis(normal);

        const auto uNormal = aVectorOrthonormalBasis.GetUVector();
        const auto vNormal = aVectorOrthonormalBasis.GetVVector();
        const auto wNormal = aVectorOrthonormalBasis.GetWVector();

        // ����S = J^T * dN / dX * J .
        // ������S�ǶԳƵ�,����Ϊ���ǹ���dN/dX��
        // ���Ǳ�����΢�������ǵļ���,��ȷ��S�ǶԳƵġ�
        auto symmetric01 = Dot(uNormal, derivativestNormal.at(index) * vNormal);
        auto symmetric10 = Dot(vNormal, derivativestNormal.at(index) * uNormal);
        const auto symmetricAverage = 0.5f * (symmetric01 + symmetric10);
        const float symmetricMat[2][2]{
            { Dot(uNormal, derivativestNormal.at(index) * uNormal), symmetricAverage },
            { symmetricAverage, Dot(vNormal, derivativestNormal.at(index) * vNormal) }
        };

        // ����S������ֵ(��С���������)��
        const auto trace = symmetricMat[0][0] + symmetricMat[1][1];
        const auto det = symmetricMat[0][0] * symmetricMat[1][1] - symmetricMat[0][1] * symmetricMat[1][0];
        const auto discr = trace * trace - 4.0f * det;
        auto rootDiscr = Mathematics::MathF::Sqrt(Mathematics::MathF::FAbs(discr));
        const auto minCurvature = 0.5f * (trace - rootDiscr);
        // float maxCurvature = 0.5f * (trace + rootDiscr);

        // ����S����������.
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
