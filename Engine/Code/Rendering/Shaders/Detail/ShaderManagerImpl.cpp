// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 16:15)

#include "Rendering/RenderingExport.h"

#include "ShaderManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::ShaderManagerImpl
    ::ShaderManagerImpl ()
	:m_VertexShaderProfile{ ShaderFlags::VertexShaderProfile::None },m_PixelShaderProfile{ ShaderFlags::PixelShaderProfile::None }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,ShaderManagerImpl)

void Rendering::ShaderManagerImpl
    ::SetVertexProfile (VertexShaderProfile profile)
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_VertexShaderProfile = profile;
}

Rendering::ShaderManagerImpl::VertexShaderProfile Rendering::ShaderManagerImpl
    ::GetVertexProfile () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_VertexShaderProfile;
}

void Rendering::ShaderManagerImpl
    ::SetPixelProfile (PixelShaderProfile profile)
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_PixelShaderProfile = profile;
}

Rendering::ShaderManagerImpl::PixelShaderProfile Rendering::ShaderManagerImpl
    ::GetPixelProfile () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_PixelShaderProfile;
}