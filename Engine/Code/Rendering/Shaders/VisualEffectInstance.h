///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:44)

#ifndef RENDERING_SHADERS_VISUAL_EFFECT_INSTANCE_H
#define RENDERING_SHADERS_VISUAL_EFFECT_INSTANCE_H

#include "VisualTechnique.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "Rendering/LocalEffects/VisualEffect.h"
#include "Rendering/RenderingDll.h"
#include "Rendering/Shaders/ShaderParameters.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(VisualEffectInstance, VisualEffectInstanceImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE VisualEffectInstance : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(VisualEffectInstance);
        using ParentType = Object;

    public:
        VisualEffectInstance(const VisualEffectSharedPtr& effect, int techniqueIndex);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(VisualEffectInstance);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        // 几何图元绘制过程中这些被Renderer使用。
        NODISCARD ConstVisualEffectSharedPtr GetEffect() const noexcept;
        NODISCARD int GetTechniqueIndex() const noexcept;
        NODISCARD int GetNumPasses() const noexcept;
        NODISCARD ConstVisualPassSharedPtr GetConstPass(int pass) const noexcept;
        NODISCARD ConstShaderParametersSharedPtr GetConstVertexParameters(int pass) const;
        NODISCARD ConstShaderParametersSharedPtr GetConstPixelParameters(int pass) const;

        NODISCARD ShaderParametersSharedPtr GetVertexParameters(int pass);
        NODISCARD ShaderParametersSharedPtr GetPixelParameters(int pass);

        // 这些函数设定常数/纹理。
        // 如果成功，返回值是非负值，并且该索引指向相应的数组。
        // 该指索引可能会传递到Set*函数具有参数“句柄”。
        // 该机制允许您直接通过索引设置，避免使用参数“const std::string& name'Set*函数出现的名字比较。
        int SetVertexConstant(int pass, const std::string& name, const ShaderFloatSharedPtr& shaderFloat);

        int SetPixelConstant(int pass, const std::string& name, const ShaderFloatSharedPtr& shaderFloat);

        int SetVertexTexture(int pass, const std::string& name, const TextureSharedPtr& texture);

        int SetPixelTexture(int pass, const std::string& name, const TextureSharedPtr& texture);

        // “句柄”是上述的Set*函数的返回值。
        void SetVertexConstant(int pass, int handle, const ShaderFloatSharedPtr& shaderFloat);
        void SetPixelConstant(int pass, int handle, const ShaderFloatSharedPtr& shaderFloat);
        void SetVertexTexture(int pass, int handle, const TextureSharedPtr& texture);
        void SetPixelTexture(int pass, int handle, const TextureSharedPtr& texture);

        NODISCARD ConstShaderFloatSharedPtr GetVertexConstant(int pass, const std::string& name) const;
        NODISCARD ConstShaderFloatSharedPtr GetPixelConstant(int pass, const std::string& name) const;
        NODISCARD ConstTextureSharedPtr GetVertexTexture(int pass, const std::string& name) const;
        NODISCARD ConstTextureSharedPtr GetPixelTexture(int pass, const std::string& name) const;

        NODISCARD ConstShaderFloatSharedPtr GetVertexConstant(int pass, int handle) const;
        NODISCARD ConstShaderFloatSharedPtr GetPixelConstant(int pass, int handle) const;
        NODISCARD ConstTextureSharedPtr GetVertexTexture(int pass, int handle) const;
        NODISCARD ConstTextureSharedPtr GetPixelTexture(int pass, int handle) const;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(VisualEffectInstance);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(VisualEffectInstance);
}

#endif  // RENDERING_SHADERS_VISUAL_EFFECT_INSTANCE_H
