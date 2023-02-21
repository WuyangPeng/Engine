///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/08 15:23)

#ifndef RENDERING_SHADER_FLOATS_PROJECTOR_WORLD_POSITION_CONSTANT_H
#define RENDERING_SHADER_FLOATS_PROJECTOR_WORLD_POSITION_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "ShaderFloat.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/SceneGraph/Projector.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(ProjectorWorldPositionConstant, ProjectorConstantImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ProjectorWorldPositionConstant : public ShaderFloat
    {
    public:
        using ProjectorWorldPositionConstantImpl = ProjectorConstantImpl;
        COPY_UNSHARED_TYPE_DECLARE(ProjectorWorldPositionConstant);
        using ParentType = ShaderFloat;
        using ClassShareType = CoreTools::CopyUnsharedClasses;

    public:
        explicit ProjectorWorldPositionConstant(const ProjectorSharedPtr& projector);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ProjectorWorldPositionConstant);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        void Update(const Visual* visual, const Camera* camera) override;

        void SetNumRegisters(int aNumRegisters) override;

        NODISCARD ConstProjectorSharedPtr GetProjector() const noexcept;

        NODISCARD ShaderFloatSharedPtr Clone() const override;

    private:
        constexpr static auto numRegisters = 1;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(ProjectorWorldPositionConstant);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(ProjectorWorldPositionConstant);
}

#endif  // RENDERING_SHADER_FLOATS_PROJECTOR_WORLD_POSITION_CONSTANT_H
