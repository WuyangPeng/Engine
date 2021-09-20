// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/24 15:25)

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

        // 这些函数设定常理/纹理。
        // 如果成功，返回值为非负值，并且是到相应的阵列的索引。
        // 该索引可能会传递到Set*函数具有参数“handle”。
        // 该机制允许您直接通过索引设置，
        // 避免与Set*函数出现与参数“const std::string& name”的名字比较。
        int SetConstant(const std::string& name, const ShaderFloatSharedPtr& shaderFloat);
        int SetTexture(const std::string& name, const TextureSharedPtr& texture);

        // “handle”是上述的Set*函数的返回值。
        void SetConstant(int handle, const ShaderFloatSharedPtr& shaderFloat);
        void SetTexture(int handle, const TextureSharedPtr& texture);

        const ConstShaderFloatSharedPtr GetConstant(const std::string& name) const;
        const ConstTextureSharedPtr GetTexture(const std::string& name) const;

        // “handle”是上述的Set*函数的返回值。
        const ConstShaderFloatSharedPtr GetConstant(int handle) const;
        const ConstTextureSharedPtr GetTexture(int handle) const;
        ObjectInterfaceSharedPtr CloneObject() const override;
        // 更新着色器常量在绘制调用期间。
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
