///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:41)

#ifndef RENDERING_SHADERS_VISUAL_EFFECT_INSTANCE_IMPL_H
#define RENDERING_SHADERS_VISUAL_EFFECT_INSTANCE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/LocalEffects/VisualEffect.h"
#include "Rendering/Shaders/VisualPass.h"
#include "Rendering/Shaders/ShaderParameters.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE VisualEffectInstanceImpl
    {
    public:
        using ClassType = VisualEffectInstanceImpl;
        using Object = CoreTools::Object;
        using BufferTarget = CoreTools::BufferTarget;
        using BufferSource = CoreTools::BufferSource;
        using ObjectLink = CoreTools::ObjectLink;
        using ObjectRegister = CoreTools::ObjectRegister;

    public:
        VisualEffectInstanceImpl() noexcept;
        VisualEffectInstanceImpl(const VisualEffectSharedPtr& effect, int techniqueIndex);

        VisualEffectInstanceImpl(const VisualEffectInstanceImpl& rhs);
        VisualEffectInstanceImpl& operator=(const VisualEffectInstanceImpl& rhs);
        ~VisualEffectInstanceImpl() noexcept = default;
        VisualEffectInstanceImpl(VisualEffectInstanceImpl&& rhs) noexcept;
        VisualEffectInstanceImpl& operator=(VisualEffectInstanceImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetStreamingSize() const;
        void Save(CoreTools::BufferTarget& target) const;
        void Load(CoreTools::BufferSource& source);
        void Link(ObjectLink& source);
        void Register(CoreTools::ObjectRegister& target) const;

        CORE_TOOLS_NAMES_IMPL_DECLARE;

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
        NODISCARD int SetVertexConstant(int pass, const std::string& name, const ShaderFloatSharedPtr& shaderFloat);

        NODISCARD int SetPixelConstant(int pass, const std::string& name, const ShaderFloatSharedPtr& shaderFloat);

        NODISCARD int SetVertexTexture(int pass, const std::string& name, const TextureSharedPtr& texture);

        NODISCARD int SetPixelTexture(int pass, const std::string& name, const TextureSharedPtr& texture);

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

    private:
        void Swap(VisualEffectInstanceImpl& rhs) noexcept;

    private:
        CoreTools::ObjectAssociated<VisualEffect> visualEffect;
        int techniqueIndex;
        int numPasses;
        std::vector<CoreTools::ObjectAssociated<ShaderParameters>> vertexParameters;
        std::vector<CoreTools::ObjectAssociated<ShaderParameters>> pixelParameters;
    };
}

#endif  // RENDERING_SHADERS_VISUAL_EFFECT_INSTANCE_IMPL_H
