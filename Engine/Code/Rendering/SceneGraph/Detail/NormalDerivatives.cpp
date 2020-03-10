// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/22 16:25)

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
	// ��ȡ����λ�úͷ���
	auto position0 = m_VertexBufferAccessor.GetPosition<APoint>(firstIndex);
	auto position1 = m_VertexBufferAccessor.GetPosition<APoint>(secondIndex);
	auto position2 = m_VertexBufferAccessor.GetPosition<APoint>(thirdIndex);

	auto normal0 = m_VertexBufferAccessor.GetNormal<AVector>(firstIndex);
	auto normal1 = m_VertexBufferAccessor.GetNormal<AVector>(secondIndex);
	auto normal2 = m_VertexBufferAccessor.GetNormal<AVector>(thirdIndex);
 
	// ����pos0��pos1�ıߣ�Ͷ�䶥�����ƽ��,���������ڷ��ߵĲ
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

	// ����pos0��pos2�ıߣ�Ͷ�䶥�����ƽ��,���������ڷ��ߵĲ
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

	// ���N * N^T ��W * W^TΪ����ֵ�ȶ��ԡ�
	// ��������0 * 0^T ��ӵ�D * W^T,��Ȼ����Ҫ���µ�ʵ�֡�
	// ��������ߵĵ�����
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
 
	auto numVertices = m_VertexBufferAccessor.GetNumVertices();
	for (auto index = 0; index < numVertices; ++index)
	{
		// ͨ��N���� U �� V��
		auto normal  = m_VertexBufferAccessor.GetNormal<AVector>(index);
		const auto aVectorOrthonormalBasis = GenerateComplementBasis(normal);

		auto uNormal = aVectorOrthonormalBasis.GetUVector();
		auto vNormal = aVectorOrthonormalBasis.GetVVector();
		auto wNormal = aVectorOrthonormalBasis.GetWVector();
		
		// ����S = J^T * dN / dX * J .
		// ������S�ǶԳƵ�,����Ϊ���ǹ���dN/dX��
		// ���Ǳ�����΢�������ǵļ���,��ȷ��S�ǶԳƵġ�
		auto symmetric01 = Dot(uNormal, m_DerivativestNormal[index] * vNormal);
		auto symmetric10 = Dot(vNormal, m_DerivativestNormal[index] * uNormal);
		auto symmetricAverage = 0.5f * (symmetric01 + symmetric10);
		float symmetricMat[2][2]  
		{
			{ Dot(uNormal, m_DerivativestNormal[index] * uNormal), symmetricAverage },
			{ symmetricAverage, Dot(vNormal,m_DerivativestNormal[index] * vNormal) }
		};

		// ����S������ֵ(��С���������)��
		auto trace = symmetricMat[0][0] + symmetricMat[1][1];
		auto det = symmetricMat[0][0] * symmetricMat[1][1] - symmetricMat[0][1] * symmetricMat[1][0];
		auto discr = trace * trace - 4.0f * det;
		auto rootDiscr = Mathematics::Mathf::Sqrt(Mathematics::Mathf::FAbs(discr));
		auto minCurvature = 0.5f * (trace - rootDiscr);
		// float maxCurvature = 0.5f * (trace + rootDiscr);

		// ����S����������.
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

