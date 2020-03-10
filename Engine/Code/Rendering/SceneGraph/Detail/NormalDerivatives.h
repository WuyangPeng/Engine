// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 19:21)

#ifndef RENDERING_SCENE_GRAPH_NORMAL_DERIVATIVES_H
#define RENDERING_SCENE_GRAPH_NORMAL_DERIVATIVES_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/Matrix.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/APoint.h"
#include "Rendering/Resources/VertexBufferAccessor.h"

#include <vector>

namespace Rendering
{
	class TriangleIndex;

	class RENDERING_HIDDEN_DECLARE NormalDerivatives
	{
	public:
		using ClassType = NormalDerivatives;
		using Matrix = Mathematics::Matrixf;
		using AVector = Mathematics::AVectorf;
		using APoint = Mathematics::APointf;
			
	public:		
		NormalDerivatives(const VertexBufferAccessor& vertexBufferAccessor);

		CLASS_INVARIANT_DECLARE;

		void ComputeEdge(const TriangleIndex& triangleIndex);
		void ComputeNormalDerivativesMatrix();
		void ComputeTangentAndBinormal();

		const AVector GetTangent(int index) const;
		const AVector GetBinormal(int index) const;

	private:
		void ComputeEdge(int firstIndex,int secondIndex,int thirdIndex);

	private:
		VertexBufferAccessor m_VertexBufferAccessor;
		std::vector<Matrix> m_DerivativestNormal;
		std::vector<Matrix> m_ProjectMatrix;
		std::vector<Matrix> m_DifferentMatrix;
		std::vector<AVector> m_Tangent;
		std::vector<AVector> m_Binormal;
	};	 
}

#endif // RENDERING_SCENE_GRAPH_NORMAL_DERIVATIVES_H
