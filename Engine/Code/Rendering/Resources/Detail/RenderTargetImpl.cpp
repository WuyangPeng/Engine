// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 14:15)

#include "Rendering/RenderingExport.h"

#include "RenderTargetImpl.h"
#include "Rendering/Resources/Texture2D.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"

#include <boost/numeric/conversion/cast.hpp>

using std::string;
using std::vector;

Rendering::RenderTargetImpl
    ::RenderTargetImpl (int numTargets, TextureFormat format,int width, int height,bool hasMipmaps, bool hasDepthStencil)
	:m_ColorTextures{ numTargets }, m_DepthStencilTexture{}, m_HasMipmaps{ hasMipmaps }
{
    RENDERING_ASSERTION_0(0 < numTargets, "目标的数量必须至少为1。\n");

    for (auto i = 0u; i < m_ColorTextures.size(); ++i)
    {
		m_ColorTextures[i].Reset(NEW0 Texture2D{ format, width,height,(hasMipmaps ? 0 : 1),BufferUsage::RenderTarget });
    }

	if (hasDepthStencil)
    {
		m_DepthStencilTexture.Reset(NEW0 Texture2D{ TextureFormat::D24S8,width, height, 1,BufferUsage::DepthStencil });
    }
    
	RENDERING_SELF_CLASS_IS_VALID_4;
}

Rendering::RenderTargetImpl::RenderTargetImpl()
	:m_ColorTextures{ 0 }, m_DepthStencilTexture{}, m_HasMipmaps{ false }
{
	RENDERING_SELF_CLASS_IS_VALID_4;
}

// private
void Rendering::RenderTargetImpl
	::Swap(RenderTargetImpl& rhs)
{
	std::swap(m_ColorTextures, rhs.m_ColorTextures);
	std::swap(m_DepthStencilTexture, rhs.m_DepthStencilTexture);
	std::swap(m_HasMipmaps, rhs.m_HasMipmaps);
}

Rendering::RenderTargetImpl
  ::RenderTargetImpl(const RenderTargetImpl& rhs)
	:m_ColorTextures{ 0 }, m_DepthStencilTexture{}, m_HasMipmaps{ rhs.m_HasMipmaps }
{
	 for (auto i = 0u; i < rhs.m_ColorTextures.size(); ++i)
	 {
		 m_ColorTextures[i].Reset(NEW0 Texture2D(*rhs.m_ColorTextures[i]));
	 }
	 
	 if (!rhs.m_DepthStencilTexture.IsNullPtr())
	 {
		 m_DepthStencilTexture.Reset(NEW0 Texture2D(*rhs.m_DepthStencilTexture));
	 }
	  
	 RENDERING_SELF_CLASS_IS_VALID_4;
}

Rendering::RenderTargetImpl& Rendering::RenderTargetImpl
   ::operator=(const RenderTargetImpl& rhs)
{
	RENDERING_CLASS_IS_VALID_4;

	RenderTargetImpl temp{ rhs };

	 Swap(temp);

	 return *this;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::RenderTargetImpl
    ::IsValid() const noexcept
{
    for (auto i = 0u; i < m_ColorTextures.size(); ++i)
    {
		if (!m_ColorTextures[i].IsNullPtr() && m_ColorTextures[i]->HasMipmaps() != m_HasMipmaps)
		{
			return false;
		}           
    }    
   
	return true;   
}
#endif // OPEN_CLASS_INVARIANT

int Rendering::RenderTargetImpl
    ::GetNumTargets () const
{
	RENDERING_CLASS_IS_VALID_CONST_4;
    
    return boost::numeric_cast<int>(m_ColorTextures.size());
}

Rendering::TextureFormat Rendering::RenderTargetImpl
    ::GetFormat () const
{
	RENDERING_CLASS_IS_VALID_CONST_4;
	RENDERING_ASSERTION_0(!m_ColorTextures.empty(), "m_ColorTextures大小为空。\n");
    
    return m_ColorTextures[0]->GetFormat();
}

int Rendering::RenderTargetImpl
    ::GetWidth () const
{
	RENDERING_CLASS_IS_VALID_CONST_4;
	RENDERING_ASSERTION_0(!m_ColorTextures.empty(), "m_ColorTextures大小为空。\n");
    
    return m_ColorTextures[0]->GetWidth();
}

int Rendering::RenderTargetImpl
    ::GetHeight () const
{
	RENDERING_CLASS_IS_VALID_CONST_4;
	RENDERING_ASSERTION_0(!m_ColorTextures.empty(), "m_ColorTextures大小为空。\n");
    
    return m_ColorTextures[0]->GetHeight();
}

Rendering::RenderTargetImpl::ConstTexture2DSmartPointer Rendering::RenderTargetImpl
    ::GetColorTexture (int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_4;
    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_ColorTextures.size()), "索引错误！\n");
    
	return m_ColorTextures[index].PolymorphicCastConstObjectSmartPointer<ConstTexture2DSmartPointer>();
}

Rendering::RenderTargetImpl::ConstTexture2DSmartPointer Rendering::RenderTargetImpl
       ::GetDepthStencilTexture () const
{
	RENDERING_CLASS_IS_VALID_CONST_4;
    
	return m_DepthStencilTexture.PolymorphicCastConstObjectSmartPointer<ConstTexture2DSmartPointer>();
}

bool Rendering::RenderTargetImpl
    ::HasMipmaps () const
{
	RENDERING_CLASS_IS_VALID_CONST_4;
    
    return m_HasMipmaps;
}

bool Rendering::RenderTargetImpl
    ::HasDepthStencil () const
{
	RENDERING_CLASS_IS_VALID_CONST_4;
    
    return m_DepthStencilTexture != nullptr;
}

const CoreTools::ObjectSmartPointer Rendering::RenderTargetImpl
    ::GetObjectByName(const string& name)
{
	RENDERING_CLASS_IS_VALID_4;
    
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
    
    return CoreTools::ObjectSmartPointer();
}

const vector<CoreTools::ObjectSmartPointer> Rendering::RenderTargetImpl
    ::GetAllObjectsByName(const string& name)
{
	RENDERING_CLASS_IS_VALID_4;
    
    vector<CoreTools::ObjectSmartPointer> objects;
    
    for (auto i = 0u; i < m_ColorTextures.size(); ++i)
    {
		if (m_ColorTextures[i]->GetName() == name)
		{
			objects.push_back(m_ColorTextures[i]);
		}            
    }
    
    if(m_DepthStencilTexture != nullptr && m_DepthStencilTexture->GetName() == name)
    {
        objects.push_back(m_DepthStencilTexture);
    }
    
    return objects;
}

const CoreTools::ConstObjectSmartPointer Rendering::RenderTargetImpl
    ::GetConstObjectByName(const string& name) const
{
	RENDERING_CLASS_IS_VALID_4;
    
    for (unsigned i = 0; i < m_ColorTextures.size(); ++i)
    {
		if (m_ColorTextures[i]->GetName() == name)
		{
			return m_ColorTextures[i].PolymorphicCastConstObjectSmartPointer<CoreTools::ConstObjectSmartPointer>();
		}
	}
    
	if (m_DepthStencilTexture != nullptr && m_DepthStencilTexture->GetName() == name)
	{
		return m_DepthStencilTexture.PolymorphicCastConstObjectSmartPointer<CoreTools::ConstObjectSmartPointer>();
	}        
    
    return CoreTools::ConstObjectSmartPointer();
}

const vector<CoreTools::ConstObjectSmartPointer> Rendering::RenderTargetImpl
    ::GetAllConstObjectsByName(const string& name) const
{
	RENDERING_CLASS_IS_VALID_4;
    
    vector<CoreTools::ConstObjectSmartPointer> objects;
    
    for (auto i = 0u; i < m_ColorTextures.size(); ++i)
    {
		if (m_ColorTextures[i]->GetName() == name)
		{
			objects.push_back(m_ColorTextures[i].PolymorphicCastConstObjectSmartPointer<CoreTools::ConstObjectSmartPointer>());
		}
	}
    
    if(m_DepthStencilTexture != nullptr && m_DepthStencilTexture->GetName() == name)
    {
        objects.push_back(m_DepthStencilTexture.PolymorphicCastConstObjectSmartPointer<CoreTools::ConstObjectSmartPointer>());
    }
    
    return objects;
}

int Rendering::RenderTargetImpl
    ::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_4;
    
    auto size = CORE_TOOLS_STREAM_SIZE(int());
	size += boost::numeric_cast<int>(m_ColorTextures.size() * CORE_TOOLS_STREAM_SIZE(m_ColorTextures[0]));
    size += CORE_TOOLS_STREAM_SIZE(m_DepthStencilTexture);
    size += CORE_TOOLS_STREAM_SIZE(m_HasMipmaps);
    
    return size;
}

void Rendering::RenderTargetImpl
    ::Save (BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_4;
    
    target.WriteSmartPointerWithNumber(boost::numeric_cast<int>(m_ColorTextures.size()), &m_ColorTextures[0]);
    target.WriteSmartPointer(m_DepthStencilTexture);
    target.WriteBool(m_HasMipmaps);
}

void Rendering::RenderTargetImpl
    ::Load (BufferSource& source)
{
	RENDERING_CLASS_IS_VALID_4;
    
    auto numTargets = 0;
    
    source.Read(numTargets);
    m_ColorTextures.resize(numTargets);
    
    source.ReadSmartPointer(boost::numeric_cast<int>(m_ColorTextures.size()), &m_ColorTextures[0]);
    source.ReadSmartPointer(m_DepthStencilTexture);
    m_HasMipmaps = source.ReadBool();
}

void Rendering::RenderTargetImpl
    ::Link (ObjectLink& source)
{
	RENDERING_CLASS_IS_VALID_4;
    
    for (auto i = 0u; i < m_ColorTextures.size(); ++i)
    {
        source.ResolveObjectSmartPointerLink(m_ColorTextures[i]);
    }
    source.ResolveObjectSmartPointerLink(m_DepthStencilTexture);
}

void Rendering::RenderTargetImpl
    ::Register (ObjectRegister& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_4;
    
    for (auto i = 0u; i < m_ColorTextures.size(); ++i)
    {
        target.RegisterSmartPointer(m_ColorTextures[i]);
    }
    
    target.RegisterSmartPointer(m_DepthStencilTexture);
}

 