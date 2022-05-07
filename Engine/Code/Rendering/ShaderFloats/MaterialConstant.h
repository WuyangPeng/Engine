///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/08 14:40)

#ifndef RENDERING_SHADER_FLOATS_MATERIAL_CONSTANT_H
#define RENDERING_SHADER_FLOATS_MATERIAL_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "ShaderFloat.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/SceneGraph/Material.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(MaterialConstant, MaterialConstantImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE MaterialConstant : public ShaderFloat
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(MaterialConstant);
        using ParentType = ShaderFloat;

    public:
        explicit MaterialConstant(const MaterialSharedPtr& Material);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(MaterialConstant);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        void Update(const Visual* visual, const Camera* camera) = 0;

        void SetNumRegisters(int aNumRegisters) override;

        NODISCARD ConstMaterialSharedPtr GetMaterial() const noexcept;

    private:
        constexpr static auto numRegisters = 1;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(MaterialConstant);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(MaterialConstant);
}

#endif  // RENDERING_SHADER_FLOATS_MATERIAL_CONSTANT_H
