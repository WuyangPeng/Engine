///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/20 14:20)

#ifndef RENDERING_SHADERS_SHADER_H
#define RENDERING_SHADERS_SHADER_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/Base/GraphicsObject.h"
#include "Rendering/OpenGLRenderer/Flags/ReferenceType.h"
#include "Rendering/OpenGLRenderer/GLSL/GLSLReflection.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/Buffers/MemberLayout.h"
#include "Rendering/Resources/Detail/Buffers/BufferLayout.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/Shaders/Flags/ShaderDataLookup.h"
#include "Rendering/Shaders/ShaderData.h"
#include "Rendering/Shaders/ShadersInternalFwd.h"
#include "Rendering/State/StateFwd.h"

#include <array>
#include <string>
#include <vector>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Shader, ShaderImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Shader : public GraphicsObject
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Shader);
        using ParentType = GraphicsObject;
        using MemberLayoutContainer = std::vector<MemberLayout>;
        using TextureSingleSharedPtr = std::shared_ptr<TextureSingle>;
        using SamplerStateSharedPtr = std::shared_ptr<SamplerState>;
        using TextureArraySharedPtr = std::shared_ptr<TextureArray>;
        using SamplerStateSharedPtr = std::shared_ptr<SamplerState>;
        using CompiledCodeContainer = std::vector<uint8_t>;
        using ShaderDataContainer = std::vector<ShaderData>;
        using ConstShaderDataContainerIter = ShaderDataContainer::const_iterator;
        using ShaderDataContainerIter = ShaderDataContainer::iterator;

    public:
        Shader(GraphicsObjectType graphicsObjectType, RendererTypes rendererTypes, const GLSLReflection& reflector, ReferenceType referenceType);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Shader);

        NODISCARD int Get(const std::string& name) const;

        void Set(const std::string& textureName,
                 const TextureSingleSharedPtr& texture,
                 const std::string& samplerName,
                 const SamplerStateSharedPtr& state);

        void Set(const std::string& textureName,
                 const TextureArraySharedPtr& texture,
                 const std::string& samplerName,
                 const SamplerStateSharedPtr& state);

        NODISCARD int GetConstantBufferSize(int handle) const;
        NODISCARD int GetConstantBufferSize(const std::string& name) const;
        NODISCARD int GetTextureBufferSize(int handle) const;
        NODISCARD int GetTextureBufferSize(const std::string& name) const;
        NODISCARD int GetStructuredBufferSize(int handle) const;
        NODISCARD int GetStructuredBufferSize(const std::string& name) const;

        NODISCARD MemberLayoutContainer GetConstantBufferLayout(int handle) const;
        NODISCARD MemberLayoutContainer GetConstantBufferLayout(const std::string& name) const;
        NODISCARD MemberLayoutContainer GetTextureBufferLayout(int handle) const;
        NODISCARD MemberLayoutContainer GetTextureBufferLayout(const std::string& name) const;
        NODISCARD MemberLayoutContainer GetStructuredBufferLayout(int handle) const;
        NODISCARD MemberLayoutContainer GetStructuredBufferLayout(const std::string& name) const;

        NODISCARD int GetNumXThreads() const noexcept;
        NODISCARD int GetNumYThreads() const noexcept;
        NODISCARD int GetNumZThreads() const noexcept;

        NODISCARD CompiledCodeContainer GetCompiledCode() const;
        NODISCARD ShaderDataContainer GetData(int lookup) const;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD bool IsValid(const ShaderData& goal, const ConstantBuffer* resource) const;
        NODISCARD bool IsValid(const ShaderData& goal, const TextureBuffer* resource) const;
        NODISCARD bool IsValid(const ShaderData& goal, const StructuredBuffer* resource) const;
        NODISCARD bool IsValid(const ShaderData& goal, const RawBuffer* resource) const;
        NODISCARD bool IsValid(const ShaderData& goal, const TextureSingle* resource) const;
        NODISCARD bool IsValid(const ShaderData& goal, const TextureArray* resource) const;
        NODISCARD bool IsValid(const ShaderData& goal, const SamplerState* state) const;

        NODISCARD ConstShaderDataContainerIter GetShaderDataBegin(int index) const;
        NODISCARD ConstShaderDataContainerIter GetShaderDataEnd(int index) const;
        NODISCARD ShaderDataContainerIter GetShaderDataBegin(int index);
        NODISCARD ShaderDataContainerIter GetShaderDataEnd(int index);

        NODISCARD ConstGraphicsObjectSharedPtr GetGraphicsObject(int index, int handle) const;

        template <typename T>
        int Set(const std::string& name, const std::shared_ptr<T>& object);

        template <typename T>
        NODISCARD std::shared_ptr<const T> Get(const std::string& name) const;

        template <typename T>
        void Set(int handle, const std::shared_ptr<T>& object);

        template <typename T>
        std::shared_ptr<const T> Get(int handle) const;

        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(Shader);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Shader);
}

#endif  // RENDERING_SHADERS_SHADER_H