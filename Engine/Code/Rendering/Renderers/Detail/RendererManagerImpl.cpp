// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/29 10:03)

#include "Rendering/RenderingExport.h"

#include "RendererManagerImpl.h"
#include "Rendering/Renderers/Renderer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;

Rendering::RendererManagerImpl
	::RendererManagerImpl()
	: m_Renderers() 
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,RendererManagerImpl)

void Rendering::RendererManagerImpl
    ::Insert( RendererPtr ptr )
{
	RENDERING_CLASS_IS_VALID_9;

	m_Renderers.insert(ptr);
}

void Rendering::RendererManagerImpl
	::Erase( RendererPtr ptr )
{
	RENDERING_CLASS_IS_VALID_9;

	m_Renderers.erase(ptr);
}

void Rendering::RendererManagerImpl
	::BindAll( VertexFormatConstPtr vertexFormat )
{
	RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
		(*iter)->Bind(vertexFormat);
    }
}


void Rendering::RendererManagerImpl
	::BindAll( VertexBufferConstPtr vertexBuffer )
{
	RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
        (*iter)->Bind(vertexBuffer);
    }
}

void Rendering::RendererManagerImpl
	::BindAll( IndexBufferConstPtr indexBuffer )
{
	RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
        (*iter)->Bind(indexBuffer);
    }
}

void Rendering::RendererManagerImpl
	::BindAll( Texture1DConstPtr texture )
{
	RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
        (*iter)->Bind(texture);
    }
}

void Rendering::RendererManagerImpl
	::BindAll( Texture2DConstPtr texture )
{
	RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
        (*iter)->Bind(texture);
    }
}

void Rendering::RendererManagerImpl
	::BindAll( Texture3DConstPtr texture )
{
	RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
        (*iter)->Bind(texture);
    }
}

void Rendering::RendererManagerImpl
	::BindAll( TextureCubeConstPtr texture )
{
	RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
        (*iter)->Bind(texture);
    }
}

void Rendering::RendererManagerImpl
	::BindAll( RenderTargetConstPtr renderTarget )
{
	RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
        (*iter)->Bind(renderTarget);
    }
}

void Rendering::RendererManagerImpl
	::BindAll( VertexShaderConstPtr vertexShader )
{
	RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
		vertexShader;
//         auto renderer = *iter;
// 
// 		if (renderer)
// 		{
// 			renderer->Bind(vertexShader);
// 		}            
    }
}

void Rendering::RendererManagerImpl
	::BindAll( PixelShaderConstPtr pixelShader )
{
	RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
		pixelShader;
//         RendererSharedPtr renderer = iter->lock();
// 
//         if(renderer)
//             renderer->Bind(pixelShader);
    }
}

void Rendering::RendererManagerImpl
	::UnbindAll( VertexFormatConstPtr vertexFormat )
{
	RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {   
        (*iter)->Unbind(vertexFormat);
    }
}


void Rendering::RendererManagerImpl
	::UnbindAll( VertexBufferConstPtr vertexBuffer )
{
	RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
        (*iter)->Unbind(vertexBuffer);
    }
}

void Rendering::RendererManagerImpl
	::UnbindAll( IndexBufferConstPtr indexBuffer )
{
	RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
        (*iter)->Unbind(indexBuffer);
    }
}

void Rendering::RendererManagerImpl
	::UnbindAll( Texture1DConstPtr texture )
{
	RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
         (*iter)->Unbind(texture);
    }
}

void Rendering::RendererManagerImpl
	::UnbindAll( Texture2DConstPtr texture )
{
	RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
         (*iter)->Unbind(texture);
    }
}

void Rendering::RendererManagerImpl
	::UnbindAll( Texture3DConstPtr texture )
{
	RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
         (*iter)->Unbind(texture);
    }
}

void Rendering::RendererManagerImpl
	::UnbindAll( TextureCubeConstPtr texture )
{
	RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
         (*iter)->Unbind(texture);
    }
}

void Rendering::RendererManagerImpl
	::UnbindAll( RenderTargetConstPtr renderTarget )
{
	RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
        (*iter)->Unbind(renderTarget);
    }
}

void Rendering::RendererManagerImpl
	::UnbindAll( VertexShaderConstPtr vertexShader )
{
	RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
		vertexShader;
//         RendererSharedPtr renderer = iter->lock();
// 
//         if(renderer)
//             renderer->Unbind(vertexShader);
    }
}

void Rendering::RendererManagerImpl
	::UnbindAll( PixelShaderConstPtr pixelShader )
{
	RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
		pixelShader;
//         RendererSharedPtr renderer = iter->lock();
// 
//         if(renderer)
//             renderer->Unbind(pixelShader);
    }
}

void Rendering::RendererManagerImpl
	::UpdateAll( VertexBufferConstPtr vertexBuffer )
{
	RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
        (*iter)->Update(vertexBuffer);
    }
}

void Rendering::RendererManagerImpl
	::UpdateAll( IndexBufferConstPtr indexBuffer )
{
	RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
        (*iter)->Update(indexBuffer);
    }
}

void Rendering::RendererManagerImpl
	::UpdateAll( Texture1DConstPtr texture, int level )
{
	RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
        (*iter)->Update(texture, level);
    }
}

void Rendering::RendererManagerImpl
	::UpdateAll( Texture2DConstPtr texture, int level )
{
	RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
        (*iter)->Update(texture, level);
    }
}

void Rendering::RendererManagerImpl
	::UpdateAll( Texture3DConstPtr texture, int level )
{
	RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
        (*iter)->Update(texture, level);
    }
}

void Rendering::RendererManagerImpl
	::UpdateAll( TextureCubeConstPtr texture, int face, int level )
{
	RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
        (*iter)->Update(texture,face, level);
    }
}

 
 