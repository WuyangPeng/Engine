///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:44)

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

        // ����ͼԪ���ƹ�������Щ��Rendererʹ�á�
        NODISCARD ConstVisualEffectSharedPtr GetEffect() const noexcept;
        NODISCARD int GetTechniqueIndex() const noexcept;
        NODISCARD int GetNumPasses() const noexcept;
        NODISCARD ConstVisualPassSharedPtr GetConstPass(int pass) const noexcept;
        NODISCARD ConstShaderParametersSharedPtr GetConstVertexParameters(int pass) const;
        NODISCARD ConstShaderParametersSharedPtr GetConstPixelParameters(int pass) const;

        NODISCARD ShaderParametersSharedPtr GetVertexParameters(int pass);
        NODISCARD ShaderParametersSharedPtr GetPixelParameters(int pass);

        // ��Щ�����趨����/����
        // ����ɹ�������ֵ�ǷǸ�ֵ�����Ҹ�����ָ����Ӧ�����顣
        // ��ָ�������ܻᴫ�ݵ�Set*�������в������������
        // �û���������ֱ��ͨ���������ã�����ʹ�ò�����const std::string& name'Set*�������ֵ����ֱȽϡ�
        int SetVertexConstant(int pass, const std::string& name, const ShaderFloatSharedPtr& shaderFloat);

        int SetPixelConstant(int pass, const std::string& name, const ShaderFloatSharedPtr& shaderFloat);

        int SetVertexTexture(int pass, const std::string& name, const TextureSharedPtr& texture);

        int SetPixelTexture(int pass, const std::string& name, const TextureSharedPtr& texture);

        // ���������������Set*�����ķ���ֵ��
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
