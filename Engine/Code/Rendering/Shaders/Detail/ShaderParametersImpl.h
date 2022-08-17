///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/12 13:39)

#ifndef RENDERING_SHADERS_SHADER_PARAMETERS_IMPL_H
#define RENDERING_SHADERS_SHADER_PARAMETERS_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/ConstObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/Resources/Textures/Texture.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Visual.h"
#include "Rendering/ShaderFloats/ShaderFloat.h"
#include "Rendering/Shaders/ShaderBase.h"

#include <string>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ShaderParametersImpl
    {
    public:
        using ClassType = ShaderParametersImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using ObjectRegister = CoreTools::ObjectRegister;
        using ObjectLink = CoreTools::ObjectLink;
        using Object = CoreTools::Object;
        using ShaderFloatSharedPtrGather = std::vector<CoreTools::ObjectAssociated<ShaderFloat>>;
        using TextureSharedPtrGather = std::vector<CoreTools::ObjectAssociated<Texture>>;
        using ConstShaderFloatSharedPtrGather = std::vector<CoreTools::ConstObjectAssociated<ShaderFloat>>;
        using ConstTextureSharedPtrGather = std::vector<CoreTools::ConstObjectAssociated<Texture>>;

    public:
        ShaderParametersImpl() noexcept;
        explicit ShaderParametersImpl(const ConstShaderBaseSharedPtr& shaderBase);

        ~ShaderParametersImpl() noexcept = default;
        ShaderParametersImpl(const ShaderParametersImpl& rhs);
        ShaderParametersImpl& operator=(const ShaderParametersImpl& rhs);
        ShaderParametersImpl(ShaderParametersImpl&& rhs) noexcept;
        ShaderParametersImpl& operator=(ShaderParametersImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;
        void Link(CoreTools::ObjectLink& source);
        void Register(CoreTools::ObjectRegister& target) const;

        CORE_TOOLS_NAMES_IMPL_DECLARE;

        NODISCARD int GetNumConstants() const;
        NODISCARD int GetNumTextures() const;
        NODISCARD ConstShaderFloatSharedPtrGather GetConstants() const;
        NODISCARD ConstTextureSharedPtrGather GetTextures() const;

        // ��Щ�����趨����/����
        // ����ɹ�������ֵΪ�Ǹ�ֵ�������ǵ���Ӧ�����е�������
        // ���������ܻᴫ�ݵ�Set*�������в�����handle����
        // �û���������ֱ��ͨ���������ã�
        // ������Set*���������������const std::string& name�������ֱȽϡ�
        NODISCARD int SetConstant(const std::string& name, const ShaderFloatSharedPtr& shaderFloat);
        NODISCARD int SetTexture(const std::string& name, const TextureSharedPtr& texture);

        // ��handle����������Set*�����ķ���ֵ��
        void SetConstant(int handle, const ShaderFloatSharedPtr& shaderFloat);
        void SetTexture(int handle, const TextureSharedPtr& texture);

        NODISCARD ConstShaderFloatSharedPtr GetConstant(const std::string& name) const;
        NODISCARD ConstTextureSharedPtr GetTexture(const std::string& name) const;

        // ��handle����������Set*�����ķ���ֵ��
        NODISCARD ConstShaderFloatSharedPtr GetConstant(int handle) const;
        NODISCARD ConstTextureSharedPtr GetTexture(int handle) const;

        // ������ɫ�������ڻ��Ƶ����ڼ䡣
        void UpdateConstants(const Visual* visual, const Camera* camera);

    private:
        void Swap(ShaderParametersImpl& rhs) noexcept;

    private:
        CoreTools::ConstObjectAssociated<ShaderBase> shader;
        ShaderFloatSharedPtrGather constants;
        TextureSharedPtrGather textures;
    };
}

#endif  // RENDERING_SHADERS_SHADER_PARAMETERS_IMPL_H
