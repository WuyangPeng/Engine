///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/12 13:39)

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

        // 这些函数设定常理/纹理。
        // 如果成功，返回值为非负值，并且是到相应的阵列的索引。
        // 该索引可能会传递到Set*函数具有参数“handle”。
        // 该机制允许您直接通过索引设置，
        // 避免与Set*函数出现与参数“const std::string& name”的名字比较。
        NODISCARD int SetConstant(const std::string& name, const ShaderFloatSharedPtr& shaderFloat);
        NODISCARD int SetTexture(const std::string& name, const TextureSharedPtr& texture);

        // “handle”是上述的Set*函数的返回值。
        void SetConstant(int handle, const ShaderFloatSharedPtr& shaderFloat);
        void SetTexture(int handle, const TextureSharedPtr& texture);

        NODISCARD ConstShaderFloatSharedPtr GetConstant(const std::string& name) const;
        NODISCARD ConstTextureSharedPtr GetTexture(const std::string& name) const;

        // “handle”是上述的Set*函数的返回值。
        NODISCARD ConstShaderFloatSharedPtr GetConstant(int handle) const;
        NODISCARD ConstTextureSharedPtr GetTexture(int handle) const;

        // 更新着色器常量在绘制调用期间。
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
