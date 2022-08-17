///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/13 15:51)

#ifndef RENDERING_SHADERS_SHADER_PARAMETERS_H
#define RENDERING_SHADERS_SHADER_PARAMETERS_H

#include "Rendering/RenderingDll.h"

#include "ShaderBase.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/ConstObjectAssociated.h"
#include "Rendering/Resources/Textures/Texture.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/ShaderFloats/ShaderFloat.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(ShaderParameters, ShaderParametersImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ShaderParameters : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ShaderParameters);
        using ParentType = Object;
        using ConstShaderFloatSharedPtrGather = std::vector<CoreTools::ConstObjectAssociated<ShaderFloat>>;
        using ConstTextureSharedPtrGather = std::vector<CoreTools::ConstObjectAssociated<Texture>>;
        using VisualSharedPtr = std::shared_ptr<Visual>;

    public:
        explicit ShaderParameters(const ConstShaderBaseSharedPtr& shader);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ShaderParameters);

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
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
        // ������ɫ�������ڻ��Ƶ����ڼ䡣
        void UpdateConstants(const Visual* visual, const Camera* camera);

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(ShaderParameters);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(ShaderParameters);
}

#endif  // RENDERING_SHADERS_SHADER_PARAMETERS_H
