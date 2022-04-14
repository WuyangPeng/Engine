///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 15:06)

#include "Rendering/RenderingExport.h"

#include "RenderTargetImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/Resources/Texture2D.h"

using std::string;
using std::vector;

Rendering::RenderTargetImpl::RenderTargetImpl(int numTargets, TextureFormat format, int width, int height, bool hasMipmaps, bool hasDepthStencil)
    : colorTextures{},
      depthStencilTexture{ hasDepthStencil ? CoreTools::ObjectAssociated{ std::make_shared<Texture2D>(TextureFormat::D24S8, width, height, 1, BufferUsage::DepthStencil) } : CoreTools::ObjectAssociated<Texture2D>{} },
      hasMipmaps{ hasMipmaps }
{
    RENDERING_ASSERTION_0(0 < numTargets, "目标的数量必须至少为1。\n");

    for (auto i = 0; i < numTargets; ++i)
    {
        colorTextures.emplace_back(CoreTools::ObjectAssociated{ std::make_shared<Texture2D>(format, width, height, (hasMipmaps ? 0 : 1), BufferUsage::RenderTarget) });
    }

    RENDERING_SELF_CLASS_IS_VALID_4;
}

Rendering::RenderTargetImpl::RenderTargetImpl() noexcept
    : colorTextures{}, depthStencilTexture{}, hasMipmaps{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_4;
}

// private
void Rendering::RenderTargetImpl::Swap(RenderTargetImpl& rhs) noexcept
{
    std::swap(colorTextures, rhs.colorTextures);
    std::swap(depthStencilTexture, rhs.depthStencilTexture);
    std::swap(hasMipmaps, rhs.hasMipmaps);
}

Rendering::RenderTargetImpl::RenderTargetImpl(const RenderTargetImpl& rhs)
    : colorTextures{ 0 }, depthStencilTexture{}, hasMipmaps{ rhs.hasMipmaps }
{
    for (auto i = 0u; i < rhs.colorTextures.size(); ++i)
    {
        colorTextures.at(i) = CoreTools::ObjectAssociated{ std::make_shared<Texture2D>(*rhs.colorTextures.at(i).object), rhs.colorTextures.at(i).associated };
    }

    if (rhs.depthStencilTexture.object != nullptr)
    {
        depthStencilTexture = CoreTools::ObjectAssociated{ std::make_shared<Texture2D>(*rhs.depthStencilTexture.object), rhs.depthStencilTexture.associated };
    }

    RENDERING_SELF_CLASS_IS_VALID_4;
}

Rendering::RenderTargetImpl& Rendering::RenderTargetImpl::operator=(const RenderTargetImpl& rhs)
{
    RENDERING_CLASS_IS_VALID_4;

    RenderTargetImpl temp{ rhs };

    Swap(temp);

    return *this;
}

Rendering::RenderTargetImpl& Rendering::RenderTargetImpl::operator=(RenderTargetImpl&& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_4;

    RenderTargetImpl temp{ std::move(rhs) };

    Swap(temp);

    return *this;
}

Rendering::RenderTargetImpl::RenderTargetImpl(RenderTargetImpl&& rhs) noexcept
    : colorTextures{ std::move(rhs.colorTextures) }, depthStencilTexture{ std::move(rhs.depthStencilTexture) }, hasMipmaps{ std::move(rhs.hasMipmaps) }
{
    RENDERING_SELF_CLASS_IS_VALID_4;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::RenderTargetImpl::IsValid() const noexcept
{
    try
    {
        for (const auto& colorTexture : colorTextures)
        {
            if (colorTexture.object && colorTexture.object->HasMipmaps() != hasMipmaps)
            {
                return false;
            }
        }

        return true;
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

int Rendering::RenderTargetImpl::GetNumTargets() const
{
    RENDERING_CLASS_IS_VALID_CONST_4;

    return boost::numeric_cast<int>(colorTextures.size());
}

Rendering::TextureFormat Rendering::RenderTargetImpl::GetFormat() const
{
    RENDERING_CLASS_IS_VALID_CONST_4;
    RENDERING_ASSERTION_0(!colorTextures.empty(), "m_ColorTextures大小为空。\n");

    return colorTextures.at(0).object->GetFormat();
}

int Rendering::RenderTargetImpl::GetWidth() const
{
    RENDERING_CLASS_IS_VALID_CONST_4;
    RENDERING_ASSERTION_0(!colorTextures.empty(), "m_ColorTextures大小为空。\n");

    return colorTextures.at(0).object->GetWidth();
}

int Rendering::RenderTargetImpl::GetHeight() const
{
    RENDERING_CLASS_IS_VALID_CONST_4;
    RENDERING_ASSERTION_0(!colorTextures.empty(), "m_ColorTextures大小为空。\n");

    return colorTextures.at(0).object->GetHeight();
}

Rendering::RenderTargetImpl::ConstTexture2DSharedPtr Rendering::RenderTargetImpl::GetColorTexture(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_4;
    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(colorTextures.size()), "索引错误！\n");

    return colorTextures.at(index).object;
}

Rendering::RenderTargetImpl::ConstTexture2DSharedPtr Rendering::RenderTargetImpl::GetDepthStencilTexture() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_4;

    return depthStencilTexture.object;
}

bool Rendering::RenderTargetImpl::HasMipmaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_4;

    return hasMipmaps;
}

bool Rendering::RenderTargetImpl::HasDepthStencil() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_4;

    return depthStencilTexture.object != nullptr;
}

CoreTools::ObjectSharedPtr Rendering::RenderTargetImpl::GetObjectByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_4;

    for (const auto& colorTexture : colorTextures)
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

    return CoreTools::ObjectSharedPtr{};
}

vector<CoreTools::ObjectSharedPtr> Rendering::RenderTargetImpl::GetAllObjectsByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_4;

    vector<CoreTools::ObjectSharedPtr> objects{};

    for (const auto& colorTexture : colorTextures)
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

CoreTools::ConstObjectSharedPtr Rendering::RenderTargetImpl::GetConstObjectByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_4;

    for (const auto& colorTexture : colorTextures)
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

    return CoreTools::ConstObjectSharedPtr{};
}

vector<CoreTools::ConstObjectSharedPtr> Rendering::RenderTargetImpl::GetAllConstObjectsByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_4;

    vector<CoreTools::ConstObjectSharedPtr> objects{};

    for (const auto& colorTexture : colorTextures)
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

int Rendering::RenderTargetImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_4;

    auto size = CORE_TOOLS_STREAM_SIZE(int{});
    size += boost::numeric_cast<int32_t>(colorTextures.size() * CORE_TOOLS_STREAM_SIZE(colorTextures.at(0).object));
    size += CORE_TOOLS_STREAM_SIZE(depthStencilTexture.object);
    size += CORE_TOOLS_STREAM_SIZE(hasMipmaps);

    return size;
}

void Rendering::RenderTargetImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_4;

    target.WriteObjectAssociatedContainerWithNumber(colorTextures);
    target.WriteObjectAssociated(depthStencilTexture);
    target.Write(hasMipmaps);
}

void Rendering::RenderTargetImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_4;

    int32_t numTargets{};

    source.Read(numTargets);
    colorTextures.resize(numTargets);

    source.ReadObjectAssociatedContainer(numTargets, colorTextures);
    source.ReadObjectAssociated(depthStencilTexture);
    hasMipmaps = source.ReadBool();
}

void Rendering::RenderTargetImpl::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_4;

    source.ResolveLinkContainer(colorTextures);
    source.ResolveLink(depthStencilTexture);
}

void Rendering::RenderTargetImpl::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_4;

    target.RegisterContainer(colorTextures);
    target.Register(depthStencilTexture);
}
