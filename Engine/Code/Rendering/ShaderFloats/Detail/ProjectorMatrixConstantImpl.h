///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:59)

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
