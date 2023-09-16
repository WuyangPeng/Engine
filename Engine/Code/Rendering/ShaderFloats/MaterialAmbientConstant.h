///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:00)

#ifndef RENDERING_SHADER_FLOATS_MATERIAL_AMBIENT_CONSTANT_CONSTANT_H
#define RENDERING_SHADER_FLOATS_MATERIAL_AMBIENT_CONSTANT_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "MaterialConstant.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE MaterialAmbientConstant : public MaterialConstant
    {
    public:
        using ClassType = MaterialAmbientConstant;
        using ParentType = MaterialConstant;
        using ClassShareType = CoreTools::CopyUnsharedClasses;

    public:
        explicit MaterialAmbientConstant(const MaterialSharedPtr& material);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(MaterialAmbientConstant);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        void Update(const Visual* visual, const Camera* camera) override;

        NODISCARD ShaderFloatSharedPtr Clone() const override;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(MaterialAmbientConstant);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(MaterialAmbientConstant);
}

#endif  // RENDERING_SHADER_FLOATS_MATERIAL_AMBIENT_CONSTANT_CONSTANT_H
