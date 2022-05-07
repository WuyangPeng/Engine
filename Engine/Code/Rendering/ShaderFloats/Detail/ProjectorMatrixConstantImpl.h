///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/07 18:12)

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
        using Matrix = Mathematics::MatrixF;

    public:
        ProjectorMatrixConstantImpl(const ProjectorSharedPtr& projector, bool biased, int biasScaleMatrixIndex) noexcept;
        ProjectorMatrixConstantImpl() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Load(CoreTools::BufferSource& source) override;
        void Save(CoreTools::BufferTarget& target) const override;
        NODISCARD int GetStreamingSize() const noexcept override;

        NODISCARD Matrix GetProjectionViewWorldMatrix(const Matrix& projectionViewWorldMatrix) const;

    private:
        bool biased;
        int32_t biasScaleMatrixIndex;
    };
}

#endif  // RENDERING_SHADER_FLOATS_PROJECTOR_MATRIX_CONSTANT_IMPL_H
