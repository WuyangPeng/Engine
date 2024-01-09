/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 14:05)

#include "Rendering/RenderingExport.h"

#include "DrawTarget.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/NameMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/OpenGLRenderer/Resources/Textures/OpenGLDrawTarget.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"
#include "Rendering/Resources/Detail/Textures/DrawTargetImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, DrawTarget)

CORE_TOOLS_RTTI_DEFINE(Rendering, DrawTarget);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, DrawTarget);
CORE_TOOLS_FACTORY_DEFINE(Rendering, DrawTarget);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, DrawTarget)

    ;

Rendering::DrawTarget::DrawTarget(const std::string& name,
                                  int numRenderTargets,
                                  DataFormatType renderTargetFormat,
                                  int width,
                                  int height,
                                  bool hasRenderTargetMipMaps,
                                  bool createRenderTargetStorage,
                                  DataFormatType depthStencilFormat,
                                  bool createDepthStencilStorage)
    : ParentType{ name },
      impl{ numRenderTargets, renderTargetFormat, width, height, hasRenderTargetMipMaps, createRenderTargetStorage, depthStencilFormat, createDepthStencilStorage }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, DrawTarget)

Rendering::DrawTarget::DrawTarget(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

int Rendering::DrawTarget::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::DrawTarget::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto registerId = ParentType::Register(target);
    if (registerId != 0)
    {
        impl->Register(target);
    }

    return registerId;
}

void Rendering::DrawTarget::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::DrawTarget::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);

    impl->Link(source);
}

void Rendering::DrawTarget::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();
}

void Rendering::DrawTarget::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::DrawTarget::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

Rendering::RendererDrawTargetSharedPtr Rendering::DrawTarget::CreateRendererDrawTarget(RendererTypes rendererTypes, const RendererObjectContainer& renderTargetTextures, const RendererObjectSharedPtr& depthStencilTexture) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    switch (rendererTypes)
    {
        case RendererTypes::OpenGL:
        {
            OpenGLDrawTarget::OpenGLTextureRenderTargetContainer container{};
            for (const auto& renderTargetTexture : renderTargetTextures)
            {
                container.emplace_back(boost::polymorphic_pointer_cast<OpenGLTextureRenderTarget>(renderTargetTexture));
            }

            auto depthStencil = boost::polymorphic_pointer_cast<OpenGLTextureDepthStencil>(depthStencilTexture);

            return std::make_shared<OpenGLDrawTarget>(boost::polymorphic_pointer_cast<const ClassType>(shared_from_this()), container, depthStencil);
        }
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("渲染类型不存在。"s))
        }
    }
}

int Rendering::DrawTarget::GetNumTargets() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNumTargets();
}

Rendering::DataFormatType Rendering::DrawTarget::GetRenderTargetFormat() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetRenderTargetFormat();
}

int Rendering::DrawTarget::GetWidth() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetWidth();
}

int Rendering::DrawTarget::GetHeight() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetHeight();
}

bool Rendering::DrawTarget::HasRenderTargetMipMaps() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->HasRenderTargetMipMaps();
}

Rendering::DataFormatType Rendering::DrawTarget::GetDepthStencilFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetDepthStencilFormat();
}

Rendering::TextureRenderTargetSharedPtr Rendering::DrawTarget::GetRenderTargetTexture(int index)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetRenderTargetTexture(index);
}

Rendering::TextureDepthStencilSharedPtr Rendering::DrawTarget::GetDepthStencilTexture()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetDepthStencilTexture();
}

Rendering::ConstTextureRenderTargetSharedPtr Rendering::DrawTarget::GetRenderTargetTexture(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetRenderTargetTexture(index);
}

Rendering::ConstTextureDepthStencilSharedPtr Rendering::DrawTarget::GetDepthStencilTexture() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetDepthStencilTexture();
}

bool Rendering::DrawTarget::HasDepthStencil() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->HasDepthStencil();
}

void Rendering::DrawTarget::AutoGenerateRenderTargetMipMaps()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->AutoGenerateRenderTargetMipMaps();
}

bool Rendering::DrawTarget::WantAutoGenerateRenderTargetMipMaps() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->WantAutoGenerateRenderTargetMipMaps();
}