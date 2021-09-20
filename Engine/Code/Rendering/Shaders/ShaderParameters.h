// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/24 15:25)

#ifndef RENDERING_SHADERS_SHADER_PARAMETERS_H
#define RENDERING_SHADERS_SHADER_PARAMETERS_H

#include "Rendering/RenderingDll.h"

#include "ShaderBase.h"
#include "CoreTools/Helper/ExportMacro.h"

#include "Rendering/Resources/Texture.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/ShaderFloats/ShaderFloat.h"

 
EXPORT_SHARED_PTR(Rendering, ShaderParametersImpl, RENDERING_DEFAULT_DECLARE);
namespace Rendering
{
    class Spatial;
}

 

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ShaderParameters : public CoreTools::Object
    {
    public:
        void Swap(ShaderParameters& rhs) noexcept;
        
            public:
                TYPE_DECLARE(ShaderParameters);
                using ClassShareType = CoreTools::CopyUnsharedClasses;
                ~ShaderParameters() noexcept;
                ShaderParameters(const ShaderParameters& rhs);
                ShaderParameters& operator=(const ShaderParameters& rhs);
                ShaderParameters(ShaderParameters&& rhs) noexcept;
                ShaderParameters& operator=(ShaderParameters&& rhs) noexcept;
        using ParentType = Object;
        using ConstShaderFloatSharedPtrGather = std::vector<ConstShaderFloatSharedPtr>;
        using ConstTextureSharedPtrGather = std::vector<ConstTextureSharedPtr>;
        using VisualSharedPtr = std::shared_ptr<Visual>;

    public:
        explicit ShaderParameters(const ConstShaderBaseSharedPtr& shader);
        

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ShaderParameters);

        int GetNumConstants() const;
        int GetNumTextures() const;
        const ConstShaderFloatSharedPtrGather GetConstants() const;
        const ConstTextureSharedPtrGather GetTextures() const;

        // ��Щ�����趨����/����
        // ����ɹ�������ֵΪ�Ǹ�ֵ�������ǵ���Ӧ�����е�������
        // ���������ܻᴫ�ݵ�Set*�������в�����handle����
        // �û���������ֱ��ͨ���������ã�
        // ������Set*���������������const std::string& name�������ֱȽϡ�
        int SetConstant(const std::string& name, const ShaderFloatSharedPtr& shaderFloat);
        int SetTexture(const std::string& name, const TextureSharedPtr& texture);

        // ��handle����������Set*�����ķ���ֵ��
        void SetConstant(int handle, const ShaderFloatSharedPtr& shaderFloat);
        void SetTexture(int handle, const TextureSharedPtr& texture);

        const ConstShaderFloatSharedPtr GetConstant(const std::string& name) const;
        const ConstTextureSharedPtr GetTexture(const std::string& name) const;

        // ��handle����������Set*�����ķ���ֵ��
        const ConstShaderFloatSharedPtr GetConstant(int handle) const;
        const ConstTextureSharedPtr GetTexture(int handle) const;
        ObjectInterfaceSharedPtr CloneObject() const override;
        // ������ɫ�������ڻ��Ƶ����ڼ䡣
        void UpdateConstants(const VisualSharedPtr& visual, const CameraSharedPtr& camera);

    private:
        using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(ShaderParameters);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE( ShaderParameters);
}

#endif  // RENDERING_SHADERS_SHADER_PARAMETERS_H
