///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:00)

#ifndef RENDERING_SHADER_FLOATS_PROJECTOR_MATRIX_CONSTANT_H
#define RENDERING_SHADER_FLOATS_PROJECTOR_MATRIX_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "ShaderFloat.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/SceneGraph/Projector.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(ProjectorMatrixConstant, ProjectorMatrixConstantImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ProjectorMatrixConstant : public ShaderFloat
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ProjectorMatrixConstant);
        using ParentType = ShaderFloat;

    public:
        // 设置biasScaleMatrixIndex为0矩阵映射 y' = (1 - y) / 2。
        // 设置biasScaleMatrixIndex为1矩阵映射 y' = (1 + y) / 2。
        ProjectorMatrixConstant(const ProjectorSharedPtr& projector, bool biased, int biasScaleMatrixIndex);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ProjectorMatrixConstant);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        void Update(const Visual* visual, const Camera* camera) override;

        void SetNumRegisters(int aNumRegisters) override;

        NODISCARD ConstProjectorSharedPtr GetProjector() const noexcept;

        NODISCARD ShaderFloatSharedPtr Clone() const override;

    private:
        constexpr static auto numRegisters = 4;

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(ProjectorMatrixConstant);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(ProjectorMatrixConstant);
}

#endif  // RENDERING_SHADER_FLOATS_PROJECTOR_MATRIX_CONSTANT_H
