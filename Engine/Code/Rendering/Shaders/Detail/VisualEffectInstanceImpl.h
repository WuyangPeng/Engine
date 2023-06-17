///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:41)

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
        NODISCARD int SetVertexConstant(int pass, const std::string& name, const ShaderFloatSharedPtr& shaderFloat);

        NODISCARD int SetPixelConstant(int pass, const std::string& name, const ShaderFloatSharedPtr& shaderFloat);

        NODISCARD int SetVertexTexture(int pass, const std::string& name, const TextureSharedPtr& texture);

        NODISCARD int SetPixelTexture(int pass, const std::string& name, const TextureSharedPtr& texture);

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
