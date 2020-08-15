// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 16:46)

#ifndef RENDERING_SHADER_FLOATS_PROJECTOR_MATRIX_CONSTANT_IMPL_H
#define RENDERING_SHADER_FLOATS_PROJECTOR_MATRIX_CONSTANT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "ProjectorConstantImpl.h"
#include "Mathematics/Algebra/Matrix.h"

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE ProjectorMatrixConstantImpl : public ProjectorConstantImpl
	{
	public:
		using ClassType = ProjectorMatrixConstantImpl;
		using ParentType = ProjectorConstantImpl;
		using Matrix = Mathematics::Matrixf;
 
	public: 
		ProjectorMatrixConstantImpl(const ProjectorSmartPointer& projector,bool biased, int biasScaleMatrixIndex);
		ProjectorMatrixConstantImpl();
 

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
	
		  void Load(BufferSource& source) override;
		  void Save(BufferTarget& target) const override;
		  int GetStreamingSize() const override;

		const Matrix GetProjectionViewWorldMatrix(const Matrix& projectionViewWorldMatrix) const;
   
	private:
		bool m_Biased;
		int m_BiasScaleMatrixIndex;
	};
}

#endif // RENDERING_SHADER_FLOATS_PROJECTOR_MATRIX_CONSTANT_IMPL_H
