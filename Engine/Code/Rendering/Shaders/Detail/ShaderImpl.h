/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:01)

#ifndef RENDERING_SHADERS_SHADER_IMPL_H
#define RENDERING_SHADERS_SHADER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
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

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ShaderImpl
    {
    public:
        using ClassType = ShaderImpl;
        using FactoryType = ShaderFactory;

        using MemberLayoutContainer = std::vector<MemberLayout>;
        using TextureSingleSharedPtr = std::shared_ptr<TextureSingle>;
        using SamplerStateSharedPtr = std::shared_ptr<SamplerState>;
        using TextureArraySharedPtr = std::shared_ptr<TextureArray>;
        using SamplerStateSharedPtr = std::shared_ptr<SamplerState>;
        using CompiledCodeContainer = std::vector<uint8_t>;
        using ShaderDataContainer = std::vector<ShaderData>;
        using ShaderDataContainerIter = ShaderDataContainer::iterator;
        using ConstShaderDataContainerIter = ShaderDataContainer::const_iterator;
        using ShaderSharedPtr = std::shared_ptr<ShaderImpl>;

        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using ObjectLink = CoreTools::ObjectLink;
        using ObjectRegister = CoreTools::ObjectRegister;

    public:
        ShaderImpl() noexcept;
        virtual ~ShaderImpl() noexcept = default;
        ShaderImpl(const ShaderImpl& rhs) = default;
        ShaderImpl& operator=(const ShaderImpl& rhs) = default;
        ShaderImpl(ShaderImpl&& rhs) noexcept = default;
        ShaderImpl& operator=(ShaderImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;
        CORE_TOOLS_NAMES_IMPL_DECLARE;

        NODISCARD int Get(const std::string& name) const;

        virtual void Set(const std::string& textureName,
                         const TextureSingleSharedPtr& texture,
                         const std::string& samplerName,
                         const SamplerStateSharedPtr& state) = 0;

        virtual void Set(const std::string& textureName,
                         const TextureArraySharedPtr& texture,
                         const std::string& samplerName,
                         const SamplerStateSharedPtr& state) = 0;

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
        NODISCARD ShaderDataContainer& GetData(int lookup);

        virtual void Load(BufferSource& source);
        virtual void Save(BufferTarget& target) const;
        NODISCARD virtual int GetStreamingSize() const;
        virtual void Link(ObjectLink& source);
        virtual void Register(ObjectRegister& target) const;

        NODISCARD virtual ShaderSharedPtr Clone() const = 0;

        NODISCARD virtual bool IsValid(const ShaderData& goal, const ConstantBuffer* resource) const = 0;
        NODISCARD virtual bool IsValid(const ShaderData& goal, const TextureBuffer* resource) const = 0;
        NODISCARD virtual bool IsValid(const ShaderData& goal, const StructuredBuffer* resource) const = 0;
        NODISCARD virtual bool IsValid(const ShaderData& goal, const RawBuffer* resource) const = 0;
        NODISCARD virtual bool IsValid(const ShaderData& goal, const TextureSingle* resource) const = 0;
        NODISCARD virtual bool IsValid(const ShaderData& goal, const TextureArray* resource) const = 0;
        NODISCARD virtual bool IsValid(const ShaderData& goal, const SamplerState* state) const = 0;

        NODISCARD ConstShaderDataContainerIter GetShaderDataBegin(int index) const;
        NODISCARD ConstShaderDataContainerIter GetShaderDataEnd(int index) const;
        NODISCARD ShaderDataContainerIter GetShaderDataBegin(int index);
        NODISCARD ShaderDataContainerIter GetShaderDataEnd(int index);

        NODISCARD ConstGraphicsObjectSharedPtr GetGraphicsObject(int index, int handle) const;

        template <typename T>
        int Set(const std::string& name, const std::shared_ptr<T>& object);

    protected:
        void SetNumThreads(int x, int y, int z) noexcept;
        void AddLookupData(int index, GraphicsObjectType inType, const std::string& inName, int inBindPoint, int inNumBytes, int inExtra, bool inIsGpuWritable);
        void ResizeConstantBufferLayouts(int size);
        void AddConstantBufferLayouts(int layoutIndex, const MemberLayout& item);
        void ResizeStructuredBufferLayouts(int size);
        void AddStructuredBufferLayouts(int layoutIndex, const MemberLayout& item);
        NODISCARD int GetStructuredBufferCounter(int layoutIndex) const;
        void SortConstantBufferLayouts(int layoutIndex);

    private:
        static constexpr auto numLookupIndices = System::EnumCastUnderlying(ShaderDataLookup::NumLookupIndices);

        using Lookup = std::array<ShaderDataContainer, numLookupIndices>;
        using BufferLayoutContainer = std::vector<BufferLayout>;

    private:
        Lookup lookupData;
        CompiledCodeContainer compiledCode;
        int numXThreads;
        int numYThreads;
        int numZThreads;

        BufferLayoutContainer constantBufferLayouts;
        BufferLayoutContainer textureBufferLayouts;
        BufferLayoutContainer structuredBufferLayouts;
    };
}

#endif  // RENDERING_SHADERS_SHADER_IMPL_H