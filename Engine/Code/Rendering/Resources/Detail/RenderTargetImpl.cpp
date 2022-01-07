// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/19 14:15)

#include "Rendering/RenderingExport.h"

#include "RenderTargetImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/Resources/Texture2D.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

using std::string;
using std::vector;
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26489)
#include SYSTEM_WARNING_DISABLE(26487)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26418)

#include SYSTEM_WARNING_DISABLE(26415)
Rendering::RenderTargetImpl ::RenderTargetImpl(int numTargets, TextureFormat format, int width, int height, bool hasMipmaps, bool hasDepthStencil)
    : m_ColorTextures{ numTargets }, m_DepthStencilTexture{}, m_HasMipmaps{ hasMipmaps }
{
    RENDERING_ASSERTION_0(0 < numTargets, "目标的数量必须至少为1。\n");

    for (auto i = 0u; i < m_ColorTextures.size(); ++i)
    {
        m_ColorTextures[i] = std::make_shared<Texture2D>(format, width, height, (hasMipmaps ? 0 : 1), BufferUsage::RenderTarget);
    }

    if (hasDepthStencil)
    {
        m_DepthStencilTexture = std::make_shared<Texture2D>(TextureFormat::D24S8, width, height, 1, BufferUsage::DepthStencil);
    }

    RENDERING_SELF_CLASS_IS_VALID_4;
}

Rendering::RenderTargetImpl::RenderTargetImpl()
    : m_ColorTextures{ 0 }, m_DepthStencilTexture{}, m_HasMipmaps{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_4;
}

// private
void Rendering::RenderTargetImpl ::Swap(RenderTargetImpl& rhs) noexcept
{
    std::swap(m_ColorTextures, rhs.m_ColorTextures);
    std::swap(m_DepthStencilTexture, rhs.m_DepthStencilTexture);
    std::swap(m_HasMipmaps, rhs.m_HasMipmaps);
}

Rendering::RenderTargetImpl ::RenderTargetImpl(const RenderTargetImpl& rhs)
    : m_ColorTextures{ 0 }, m_DepthStencilTexture{}, m_HasMipmaps{ rhs.m_HasMipmaps }
{
    for (auto i = 0u; i < rhs.m_ColorTextures.size(); ++i)
    {
        m_ColorTextures[i] = std::make_shared<Texture2D>(*rhs.m_ColorTextures[i]);
    }

    if (rhs.m_DepthStencilTexture)
    {
        m_DepthStencilTexture = std::make_shared<Texture2D>(*rhs.m_DepthStencilTexture);
    }

    RENDERING_SELF_CLASS_IS_VALID_4;
}

Rendering::RenderTargetImpl& Rendering::RenderTargetImpl ::operator=(const RenderTargetImpl& rhs)
{
    RENDERING_CLASS_IS_VALID_4;

    RenderTargetImpl temp{ rhs };

    Swap(temp);

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::RenderTargetImpl ::IsValid() const noexcept
{
    try
    {
        for (auto i = 0u; i < m_ColorTextures.size(); ++i)
        {
            if (m_ColorTextures[i] && m_ColorTextures[i]->HasMipmaps() != m_HasMipmaps)
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

int Rendering::RenderTargetImpl ::GetNumTargets() const
{
    RENDERING_CLASS_IS_VALID_CONST_4;

    return boost::numeric_cast<int>(m_ColorTextures.size());
}

Rendering::TextureFormat Rendering::RenderTargetImpl ::GetFormat() const
{
    RENDERING_CLASS_IS_VALID_CONST_4;
    RENDERING_ASSERTION_0(!m_ColorTextures.empty(), "m_ColorTextures大小为空。\n");

    return m_ColorTextures[0]->GetFormat();
}

int Rendering::RenderTargetImpl ::GetWidth() const
{
    RENDERING_CLASS_IS_VALID_CONST_4;
    RENDERING_ASSERTION_0(!m_ColorTextures.empty(), "m_ColorTextures大小为空。\n");

    return m_ColorTextures[0]->GetWidth();
}

int Rendering::RenderTargetImpl ::GetHeight() const
{
    RENDERING_CLASS_IS_VALID_CONST_4;
    RENDERING_ASSERTION_0(!m_ColorTextures.empty(), "m_ColorTextures大小为空。\n");

    return m_ColorTextures[0]->GetHeight();
}

Rendering::RenderTargetImpl::ConstTexture2DSharedPtr Rendering::RenderTargetImpl ::GetColorTexture(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_4;
    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_ColorTextures.size()), "索引错误！\n");

    return m_ColorTextures[index];
}

Rendering::RenderTargetImpl::ConstTexture2DSharedPtr Rendering::RenderTargetImpl ::GetDepthStencilTexture() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_4;

    return m_DepthStencilTexture;
}

bool Rendering::RenderTargetImpl ::HasMipmaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_4;

    return m_HasMipmaps;
}

bool Rendering::RenderTargetImpl ::HasDepthStencil() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_4;

    return m_DepthStencilTexture != nullptr;
}

CoreTools::ObjectSharedPtr Rendering::RenderTargetImpl ::GetObjectByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_4;
    CoreTools::DisableNoexcept();
    for (auto i = 0u; i < m_ColorTextures.size(); ++i)
    {
        if (m_ColorTextures[i]->GetName() == name)
        {
            return m_ColorTextures[i];
        }
    }

    if (m_DepthStencilTexture != nullptr && m_DepthStencilTexture->GetName() == name)
    {
        return m_DepthStencilTexture;
    }

    return CoreTools::ObjectSharedPtr();
}

vector<CoreTools::ObjectSharedPtr> Rendering::RenderTargetImpl ::GetAllObjectsByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_4;
    CoreTools::DisableNoexcept();
    vector<CoreTools::ObjectSharedPtr> objects;

    for (auto i = 0u; i < m_ColorTextures.size(); ++i)
    {
        if (m_ColorTextures[i]->GetName() == name)
        {
            objects.push_back(m_ColorTextures[i]);
        }
    }

    if (m_DepthStencilTexture != nullptr && m_DepthStencilTexture->GetName() == name)
    {
        objects.push_back(m_DepthStencilTexture);
    }

    return objects;
}

CoreTools::ConstObjectSharedPtr Rendering::RenderTargetImpl ::GetConstObjectByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_4;
    CoreTools::DisableNoexcept();
    for (unsigned i = 0; i < m_ColorTextures.size(); ++i)
    {
        if (m_ColorTextures[i]->GetName() == name)
        {
            return m_ColorTextures[i];
        }
    }

    if (m_DepthStencilTexture != nullptr && m_DepthStencilTexture->GetName() == name)
    {
        return m_DepthStencilTexture;
    }

    return CoreTools::ConstObjectSharedPtr();
}

vector<CoreTools::ConstObjectSharedPtr> Rendering::RenderTargetImpl ::GetAllConstObjectsByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_4;
    CoreTools::DisableNoexcept();
    vector<CoreTools::ConstObjectSharedPtr> objects;

    for (auto i = 0u; i < m_ColorTextures.size(); ++i)
    {
        if (m_ColorTextures[i]->GetName() == name)
        {
            objects.push_back(m_ColorTextures[i]);
        }
    }

    if (m_DepthStencilTexture != nullptr && m_DepthStencilTexture->GetName() == name)
    {
        objects.push_back(m_DepthStencilTexture);
    }

    return objects;
}

int Rendering::RenderTargetImpl ::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_4;

    auto size = CORE_TOOLS_STREAM_SIZE(int());
    size += boost::numeric_cast<int>(m_ColorTextures.size() * CORE_TOOLS_STREAM_SIZE(m_ColorTextures[0]));
    size += CORE_TOOLS_STREAM_SIZE(m_DepthStencilTexture);
    size += CORE_TOOLS_STREAM_SIZE(m_HasMipmaps);

    return size;
}

void Rendering::RenderTargetImpl ::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_4;

    //   target.WriteSharedPtrWithNumber(boost::numeric_cast<int>(m_ColorTextures.size()), &m_ColorTextures[0]);
    //   target.WriteSharedPtr(m_DepthStencilTexture);
    target.Write(m_HasMipmaps);
}

void Rendering::RenderTargetImpl ::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_4;

    auto numTargets = 0;

    source.Read(numTargets);
    m_ColorTextures.resize(numTargets);

    //source.ReadSharedPtr(boost::numeric_cast<int>(m_ColorTextures.size()), &m_ColorTextures[0]);
    // source.ReadSharedPtr(m_DepthStencilTexture);
    m_HasMipmaps = source.ReadBool();
}

void Rendering::RenderTargetImpl ::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_4;
    CoreTools::DisableNoexcept();
    source;
    for (auto i = 0u; i < m_ColorTextures.size(); ++i)
    {
        //source.ResolveObjectSharedPtrLink(m_ColorTextures[i]);
    }
    // source.ResolveObjectSharedPtrLink(m_DepthStencilTexture);
}

void Rendering::RenderTargetImpl ::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_4;
    CoreTools::DisableNoexcept();
    target;
    for (auto i = 0u; i < m_ColorTextures.size(); ++i)
    {
        // target.RegisterSharedPtr(m_ColorTextures[i]);
    }

    // target.RegisterSharedPtr(m_DepthStencilTexture);
}

#include STSTEM_WARNING_POP