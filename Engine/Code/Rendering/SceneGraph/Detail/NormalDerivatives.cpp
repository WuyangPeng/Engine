// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 16:25)

#include "Rendering/RenderingExport.h"

#include "NormalDerivatives.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Rendering/SceneGraph/TriangleIndex.h"
#include "Rendering/Resources/VertexBufferAccessorDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::NormalDerivatives
	::NormalDerivatives(const VertexBufferAccessor& vertexBufferAccessor)
	:m_VertexBufferAccessor{ vertexBufferAccessor },
	 m_DerivativestNormal{ vertexBufferAccessor.GetNumVertices() },
	 m_ProjectMatrix{ vertexBufferAccessor.GetNumVertices() },
	 m_DifferentMatrix{ vertexBufferAccessor.GetNumVertices() },
	 m_Tangent{ vertexBufferAccessor.GetNumVertices() },
	 m_Binormal{ vertexBufferAccessor.GetNumVertices() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::NormalDerivatives
	::IsValid() const noexcept
{
	auto numVertices = static_cast<size_t>(m_VertexBufferAccessor.GetNumVertices());
	if (numVertices == m_DerivativestNormal.size() &&
		m_ProjectMatrix.size() == m_DerivativestNormal.size() &&
		m_Tangent.size() == m_Binormal.size() &&
		numVertices == m_ProjectMatrix.size() &&
		numVertices == m_Tangent.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

void Rendering::NormalDerivatives
	::ComputeEdge(const TriangleIndex& triangleIndex) 
{
	RENDERING_CLASS_IS_VALID_1;

	ComputeEdge(triangleIndex.GetFirstIndex(), triangleIndex.GetSecondIndex(), triangleIndex.GetThirdIndex());
	ComputeEdge(triangleIndex.GetSecondIndex(), triangleIndex.GetThirdIndex(), triangleIndex.GetFirstIndex());
	ComputeEdge(triangleIndex.GetThirdIndex(), triangleIndex.GetFirstIndex(), triangleIndex.GetSecondIndex());
}

// private
void Rendering::NormalDerivatives
	::ComputeEdge(int firstIndex, int secondIndex, int thirdIndex) 
{
	// 获取顶点位置和法线
	auto position0 = m_VertexBufferAccessor.GetPosition<APoint>(firstIndex);
	auto position1 = m_VertexBufferAccessor.GetPosition<APoint>(secondIndex);
	auto position2 = m_VertexBufferAccessor.GetPosition<APoint>(thirdIndex);

	auto normal0 = m_VertexBufferAccessor.GetNormal<AVector>(firstIndex);
	auto normal1 = m_VertexBufferAccessor.GetNormal<AVector>(secondIndex);
	auto normal2 = m_VertexBufferAccessor.GetNormal<AVector>(thirdIndex);
 
	// 计算pos0到pos1的边，投射顶点的切平面,并计算相邻法线的差。
	auto edge = position1 - position0;
	auto project = edge - Dot(edge, normal0) * normal0;
	auto difference = normal1 - normal0;
	for (auto row = 0; row < 3; ++row)
	{
		for (auto col = 0; col < 3; ++col)
		{
			m_ProjectMatrix[firstIndex](row, col) += project[row] * project[col];
			m_DifferentMatrix[firstIndex](row, col) += difference[row] * project[col];
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
			m_ProjectMatrix[firstIndex](row,col) += project[row] * project[col];
			m_DifferentMatrix[firstIndex](row, col) += difference[row] * project[col];
		}	
	}
}

void Rendering::NormalDerivatives
	::ComputeNormalDerivativesMatrix() 
{
	RENDERING_CLASS_IS_VALID_1;

	// 添加N * N^T 到W * W^T为了数值稳定性。
	// 理论上是0 * 0^T 添加到D * W^T,当然不需要更新的实现。
	// 计算矩阵法线的导数。
	auto numVertices = m_VertexBufferAccessor.GetNumVertices();
	for (auto index = 0; index < numVertices; ++index)
	{
		auto normal = m_VertexBufferAccessor.GetNormal<AVector>(index);
		for (auto row = 0; row < 3; ++row)
		{
			for (auto col = 0; col < 3; ++col)
			{
				m_ProjectMatrix[index](row, col) += 0.5f * m_ProjectMatrix[index](row, col) + normal[row] * normal[col];
				m_DifferentMatrix[index](row, col) *= 0.5f;
			}
		}
	 

		m_ProjectMatrix[index].SetColumn(3, APoint::sm_Origin.GetHomogeneousPoint());
		m_DerivativestNormal[index] = m_DifferentMatrix[index] * m_ProjectMatrix[index].Inverse();
	}
}

void Rendering::NormalDerivatives
	::ComputeTangentAndBinormal() 
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
 
	auto numVertices = m_VertexBufferAccessor.GetNumVertices();
	for (auto index = 0; index < numVertices; ++index)
	{
		// 通过N计算 U 和 V。
		auto normal  = m_VertexBufferAccessor.GetNormal<AVector>(index);
		const auto aVectorOrthonormalBasis = GenerateComplementBasis(normal);

		auto uNormal = aVectorOrthonormalBasis.GetUVector();
		auto vNormal = aVectorOrthonormalBasis.GetVVector();
		auto wNormal = aVectorOrthonormalBasis.GetWVector();
		
		// 计算S = J^T * dN / dX * J .
		// 理论上S是对称的,但因为我们估算dN/dX，
		// 我们必须稍微调整我们的计算,以确保S是对称的。
		auto symmetric01 = Dot(uNormal, m_DerivativestNormal[index] * vNormal);
		auto symmetric10 = Dot(vNormal, m_DerivativestNormal[index] * uNormal);
		auto symmetricAverage = 0.5f * (symmetric01 + symmetric10);
		float symmetricMat[2][2]  
		{
			{ Dot(uNormal, m_DerivativestNormal[index] * uNormal), symmetricAverage },
			{ symmetricAverage, Dot(vNormal,m_DerivativestNormal[index] * vNormal) }
		};

		// 计算S的特征值(最小和最大曲率)。
		auto trace = symmetricMat[0][0] + symmetricMat[1][1];
		auto det = symmetricMat[0][0] * symmetricMat[1][1] - symmetricMat[0][1] * symmetricMat[1][0];
		auto discr = trace * trace - 4.0f * det;
		auto rootDiscr = Mathematics::Mathf::Sqrt(Mathematics::Mathf::FAbs(discr));
		auto minCurvature = 0.5f * (trace - rootDiscr);
		// float maxCurvature = 0.5f * (trace + rootDiscr);

		// 计算S的特征向量.
		AVector evec0{ symmetricMat[0][1], minCurvature - symmetricMat[0][0], 0.0f };
		AVector evec1{ minCurvature - symmetricMat[1][1], symmetricMat[1][0], 0.0f };
		AVector tanvec, binvec;
		if (evec0.SquaredLength() >= evec1.SquaredLength())
		{
			evec0.Normalize();
			tanvec = evec0[0] * uNormal + evec0[1] * vNormal;
			binvec = Cross(wNormal,tanvec);
		}
		else
		{
			evec1.Normalize();
			tanvec = evec1[0] * uNormal + evec1[1] * vNormal;
			binvec = Cross(wNormal,tanvec);
		}

		m_Tangent[index] = tanvec;
		m_Binormal[index] = binvec;		 
	}	
}

const Rendering::NormalDerivatives::AVector Rendering::NormalDerivatives
	::GetTangent(int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Tangent[index];
}

const Rendering::NormalDerivatives::AVector Rendering::NormalDerivatives
	::GetBinormal(int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Binormal[index];
}

