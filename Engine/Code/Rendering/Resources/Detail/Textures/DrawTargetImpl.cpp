/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 14:29)

#include "Rendering/RenderingExport.h"

#include "DrawTargetImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "Rendering/Resources/DataFormat.h"

Rendering::DrawTargetImpl::DrawTargetImpl() noexcept
    : renderTargetTextures{},
      depthStencilTexture{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::DrawTargetImpl::DrawTargetImpl(int numRenderTargets,
                                          DataFormatType renderTargetFormat,
                                          int width,
                                          int height,
                                          bool hasRenderTargetMipMaps,
                                          bool createRenderTargetStorage,
                                          DataFormatType depthStencilFormat,
                                          bool createDepthStencilStorage)
    : renderTargetTextures{},
      depthStencilTexture{}
{
    if (numRenderTargets <= 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("目标数量必须至少为 1。"))
    }

    for (auto i = 0; i < numRenderTargets; ++i)
    {
        renderTargetTextures.emplace_back(std::make_shared<TextureRenderTarget>("renderTargetTextures" + std::to_string(i), renderTargetFormat, width, height, hasRenderTargetMipMaps, createRenderTargetStorage));
    }

    if (depthStencilFormat != DataFormatType::Unknown)
    {
        if (DataFormat::IsDepth(depthStencilFormat))
        {
            depthStencilTexture = TextureDepthStencilObjectAssociated{ std::make_shared<TextureDepthStencil>("depthStencilTexture", depthStencilFormat, width, height, false, createDepthStencilStorage) };
        }
        else
        {
            THROW_EXCEPTION(SYSTEM_TEXT("无效的深度模板格式。"))
        }
    }

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::DrawTargetImpl& Rendering::DrawTargetImpl::operator=(const DrawTargetImpl& rhs)
{
    RENDERING_CLASS_IS_VALID_1;

    auto drawTargetImpl = rhs;

    Swap(drawTargetImpl);

    return *this;
}

Rendering::DrawTargetImpl::DrawTargetImpl(const DrawTargetImpl& rhs)
    : renderTargetTextures{}, depthStencilTexture{}
{
    for (const auto& element : rhs.renderTargetTextures)
    {
        renderTargetTextures.emplace_back(std::make_shared<TextureRenderTarget>(*element.object), element.associated);
    }

    if (rhs.depthStencilTexture.object != nullptr)
    {
        depthStencilTexture = CoreTools::ObjectAssociated{ std::make_shared<TextureDepthStencil>(*rhs.depthStencilTexture.object), rhs.depthStencilTexture.associated };
    }

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::DrawTargetImpl& Rendering::DrawTargetImpl::operator=(DrawTargetImpl&& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    auto drawTargetImpl = std::move(rhs);

    Swap(drawTargetImpl);

    return *this;
}

Rendering::DrawTargetImpl::DrawTargetImpl(DrawTargetImpl&& rhs) noexcept
    : renderTargetTextures{ std::move(rhs.renderTargetTextures) }, depthStencilTexture{ std::move(rhs.depthStencilTexture) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::DrawTargetImpl::Swap(DrawTargetImpl& rhs) noexcept
{
    renderTargetTextures.swap(rhs.renderTargetTextures);
    std::swap(depthStencilTexture, rhs.depthStencilTexture);
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::DrawTargetImpl::IsValid() const noexcept
{
    return depthStencilTexture.object == nullptr || !renderTargetTextures.empty();
}

#endif  // OPEN_CLASS_INVARIANT

Rendering::DataFormatType Rendering::DrawTargetImpl::GetRenderTargetFormat() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return renderTargetTextures.at(0)->GetFormat();
}

int Rendering::DrawTargetImpl::GetWidth() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return renderTargetTextures.at(0)->GetWidth();
}

int Rendering::DrawTargetImpl::GetHeight() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return renderTargetTextures.at(0)->GetHeight();
}

bool Rendering::DrawTargetImpl::HasRenderTargetMipMaps() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return renderTargetTextures.at(0)->HasMipMaps();
}

Rendering::DataFormatType Rendering::DrawTargetImpl::GetDepthStencilFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (depthStencilTexture.object != nullptr)
    {
        return depthStencilTexture->GetFormat();
    }

    return DataFormatType::Unknown;
}

Rendering::ConstTextureDepthStencilSharedPtr Rendering::DrawTargetImpl::GetDepthStencilTexture() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (depthStencilTexture.object != nullptr)
    {
        return depthStencilTexture.object;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效的深度模板格式。"))
    }
}

Rendering::TextureDepthStencilSharedPtr Rendering::DrawTargetImpl::GetDepthStencilTexture()
{
    RENDERING_CLASS_IS_VALID_1;

    return const_pointer_cast<TextureDepthStencil>(static_cast<const ClassType&>(*this).GetDepthStencilTexture());
}

Rendering::ConstTextureRenderTargetSharedPtr Rendering::DrawTargetImpl::GetRenderTargetTexture(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return renderTargetTextures.at(index).object;
}

Rendering::TextureRenderTargetSharedPtr Rendering::DrawTargetImpl::GetRenderTargetTexture(int index)
{
    RENDERING_CLASS_IS_VALID_1;

    return const_pointer_cast<TextureRenderTarget>(static_cast<const ClassType&>(*this).GetRenderTargetTexture(index));
}

bool Rendering::DrawTargetImpl::HasDepthStencil() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return depthStencilTexture.object != nullptr;
}

void Rendering::DrawTargetImpl::AutoGenerateRenderTargetMipMaps()
{
    RENDERING_CLASS_IS_VALID_1;

    if (HasRenderTargetMipMaps())
    {
        for (auto& texture : renderTargetTextures)
        {
            texture->AutoGenerateMipMaps();
        }
    }
}

bool Rendering::DrawTargetImpl::WantAutoGenerateRenderTargetMipMaps() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return renderTargetTextures.at(0)->WantAutoGenerateMipMaps();
}

int Rendering::DrawTargetImpl::GetNumTargets() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(renderTargetTextures.size());
}

CoreTools::ObjectSharedPtr Rendering::DrawTargetImpl::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    for (const auto& colorTexture : renderTargetTextures)
    {
        if (colorTexture.object->GetName() == name)
        {
            return colorTexture.object;
        }
    }

    if (depthStencilTexture.object != nullptr && depthStencilTexture.object->GetName() == name)
    {
        return depthStencilTexture.object;
    }

    return CoreTools::Object::GetNullObject();
}

Rendering::DrawTargetImpl::ObjectSharedPtrContainer Rendering::DrawTargetImpl::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    ObjectSharedPtrContainer objects{};

    for (const auto& colorTexture : renderTargetTextures)
    {
        if (colorTexture.object->GetName() == name)
        {
            objects.emplace_back(colorTexture.object);
        }
    }

    if (depthStencilTexture.object != nullptr && depthStencilTexture.object->GetName() == name)
    {
        objects.emplace_back(depthStencilTexture.object);
    }

    return objects;
}

CoreTools::ConstObjectSharedPtr Rendering::DrawTargetImpl::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_1;

    for (const auto& colorTexture : renderTargetTextures)
    {
        if (colorTexture.object->GetName() == name)
        {
            return colorTexture.object;
        }
    }

    if (depthStencilTexture.object != nullptr && depthStencilTexture.object->GetName() == name)
    {
        return depthStencilTexture.object;
    }

    return CoreTools::Object::GetNullObject();
}

Rendering::DrawTargetImpl::ConstObjectSharedPtrContainer Rendering::DrawTargetImpl::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_1;

    ConstObjectSharedPtrContainer objects{};

    for (const auto& colorTexture : renderTargetTextures)
    {
        if (colorTexture.object->GetName() == name)
        {
            objects.emplace_back(colorTexture.object);
        }
    }

    if (depthStencilTexture.object != nullptr && depthStencilTexture.object->GetName() == name)
    {
        objects.emplace_back(depthStencilTexture.object);
    }

    return objects;
}

int Rendering::DrawTargetImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = CoreTools::GetStreamSize(renderTargetTextures);

    size += CoreTools::GetStreamSize(depthStencilTexture);

    return size;
}

void Rendering::DrawTargetImpl::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.WriteObjectAssociatedContainerWithNumber(renderTargetTextures);
    target.WriteObjectAssociated(depthStencilTexture);
}

void Rendering::DrawTargetImpl::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.ReadObjectAssociatedContainer(renderTargetTextures);
    source.ReadObjectAssociated(depthStencilTexture);
}

void Rendering::DrawTargetImpl::Link(ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.ResolveLinkContainer(renderTargetTextures);
    source.ResolveLink(depthStencilTexture);
}

void Rendering::DrawTargetImpl::Register(ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.RegisterContainer(renderTargetTextures);
    target.Register(depthStencilTexture);
}
