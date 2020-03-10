// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 09:35)

#include "Rendering/RenderingExport.h"

#include "RendererDataImpl.h"
#include "AnalysisRendererManager.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Renderers/RendererBasis.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;
using boost::property_tree::ptree_error;

Rendering::RendererDataImpl
	::RendererDataImpl()
	:m_Renderer{ make_shared<Renderer>(Rendering::RendererTypes::Default,RendererBasis()) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::RendererDataImpl
	::~RendererDataImpl()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::RendererDataImpl
	::IsValid() const noexcept
{
    if(m_Renderer != nullptr)
        return true;
    else
        return false;
}
#endif // OPEN_CLASS_INVARIANT

void Rendering::RendererDataImpl
    ::LoadConfiguration(const std::string& fileName)
{
	RENDERING_CLASS_IS_VALID_1;

	try
	{
		AnalysisRendererManager manager{ fileName };
	    m_Renderer = manager.GetRendererPtr();
	}
	catch (ptree_error& error)
	{
		LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
			<< error.what()
			<< CoreTools::LogAppenderIOManageSign::TriggerAssert;	
	}

}

void Rendering::RendererDataImpl
    ::ClearColor()
{
	RENDERING_CLASS_IS_VALID_1;

	m_Renderer->ClearColorBuffer();
}

void Rendering::RendererDataImpl
	::Resize( int width,int height )
{
	RENDERING_CLASS_IS_VALID_1;

	m_Renderer->Resize(width,height);
}

void Rendering::RendererDataImpl
	::DrawMessage( int x,int y,const Colour& color,const std::string& message)
{
	RENDERING_CLASS_IS_VALID_1;

  	m_Renderer->Draw(x, y,color, message);
}

Rendering::TextureFormat Rendering::RendererDataImpl
	::GetColorFormat() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Renderer->GetColorFormat();
}

Rendering::TextureFormat Rendering::RendererDataImpl
	::GetDepthStencilFormat() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Renderer->GetDepthStencilFormat();
}

int Rendering::RendererDataImpl
	::GetNumMultisamples() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Renderer->GetNumMultisamples();
}

Rendering::Colour<float> Rendering::RendererDataImpl
	::GetClearColor() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Renderer->GetClearColor();
}

const std::string Rendering::RendererDataImpl
	::GetWindowTitle() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ""; 
}

int Rendering::RendererDataImpl
	::GetXPosition () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return 1024; 
}

int Rendering::RendererDataImpl
	::GetYPosition () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return 768; 
}

int Rendering::RendererDataImpl
	::GetWidth () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Renderer->GetWidth();
}

int Rendering::RendererDataImpl
	::GetHeight () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Renderer->GetHeight();
}

bool Rendering::RendererDataImpl
	::IsAllowResize() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return true; 
}

Rendering::RendererTypes Rendering::RendererDataImpl
	::GetRendererType() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Renderer->GetRendererType();
}	
