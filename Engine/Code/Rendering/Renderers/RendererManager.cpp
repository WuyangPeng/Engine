// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.3 (2019/07/29 10:30)

#include "Rendering/RenderingExport.h"

#include "RendererManager.h"
#include "Detail/RendererManagerImpl.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
using std::make_shared;
using std::make_unique;

SINGLETON_GET_PTR_DEFINE(Rendering, RendererManager);

Rendering::RendererManager::RendererManagerUniquePtr Rendering::RendererManager
::sm_RendererManager{ };

void Rendering::RendererManager
::Create()
{
	sm_RendererManager = make_unique<Rendering::RendererManager>(RendererManagerCreate::Init);
}

void Rendering::RendererManager
::Destroy() noexcept
{
	sm_RendererManager.reset();
}

Rendering::RendererManager
::RendererManager(RendererManagerCreate rendererManagerCreate)
	:m_Impl{ make_shared<ImplType>() }
{
	SYSTEM_UNUSED_ARG(rendererManagerCreate);

	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering, RendererManager)

int64_t Rendering::RendererManager
    ::Insert( RendererPtr ptr )
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Insert(ptr);
}

bool Rendering::RendererManager
	::Erase(int64_t rendererID)
{
	 SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Erase(rendererID);
}

void Rendering::RendererManager
	::BindAll( VertexFormatConstPtr vertexFormat )
{
	 SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->BindAll(vertexFormat);
}


void Rendering::RendererManager
	::BindAll( VertexBufferConstPtr vertexBuffer )
{
	 SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->BindAll(vertexBuffer);
}

void Rendering::RendererManager
	::BindAll( IndexBufferConstPtr indexBuffer )
{
	 SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->BindAll(indexBuffer);
}


void Rendering::RendererManager
	::BindAll( Texture1DConstPtr texture )
{
	 SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->BindAll(texture);
}

void Rendering::RendererManager
	::BindAll( Texture2DConstPtr texture )
{
	 SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->BindAll(texture);
}

void Rendering::RendererManager
	::BindAll( Texture3DConstPtr texture )
{
	 SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->BindAll(texture);
}

void Rendering::RendererManager
	::BindAll( TextureCubeConstPtr texture )
{
	 SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->BindAll(texture);
}

void Rendering::RendererManager
	::BindAll( RenderTargetConstPtr renderTarget )
{
	 SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->BindAll(renderTarget);
}

void Rendering::RendererManager
	::BindAll( VertexShaderConstPtr vertexShader )
{
	 SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->BindAll(vertexShader);
}

void Rendering::RendererManager
	::BindAll( PixelShaderConstPtr pixelShader )
{
	 SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->BindAll(pixelShader);
}

void Rendering::RendererManager
	::UnbindAll( VertexFormatConstPtr vertexFormat )
{
	 SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->UnbindAll(vertexFormat);
}


void Rendering::RendererManager
	::UnbindAll( VertexBufferConstPtr vertexBuffer )
{
	 SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->UnbindAll(vertexBuffer);
}

void Rendering::RendererManager
	::UnbindAll( IndexBufferConstPtr indexBuffer )
{
	 SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->UnbindAll(indexBuffer);
}

void Rendering::RendererManager
	::UnbindAll( Texture1DConstPtr texture )
{
	 SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->UnbindAll(texture);
}

void Rendering::RendererManager
	::UnbindAll( Texture2DConstPtr texture )
{
	 SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->UnbindAll(texture);
}

void Rendering::RendererManager
	::UnbindAll( Texture3DConstPtr texture )
{
	 SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->UnbindAll(texture);
}

void Rendering::RendererManager
	::UnbindAll( TextureCubeConstPtr texture )
{
	 SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->UnbindAll(texture);
}

void Rendering::RendererManager
	::UnbindAll( RenderTargetConstPtr renderTarget )
{
	 SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->UnbindAll(renderTarget);
}

void Rendering::RendererManager
	::UnbindAll( VertexShaderConstPtr vertexShader )
{
	 SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->UnbindAll(vertexShader);
}

void Rendering::RendererManager
	::UnbindAll( PixelShaderConstPtr pixelShader )
{
	 SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->UnbindAll(pixelShader);
}

void Rendering::RendererManager
	::UpdateAll( VertexBufferConstPtr vertexBuffer )
{
	 SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->UpdateAll(vertexBuffer);
}

void Rendering::RendererManager
	::UpdateAll( IndexBufferConstPtr indexBuffer )
{
	 SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->UpdateAll(indexBuffer);
}

void Rendering::RendererManager
	::UpdateAll( Texture1DConstPtr texture, int level )
{
	 SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->UpdateAll(texture, level);
}

void Rendering::RendererManager
	::UpdateAll( Texture2DConstPtr texture, int level )
{
	 SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->UpdateAll(texture, level);
}

void Rendering::RendererManager
	::UpdateAll( Texture3DConstPtr texture, int level )
{
	 SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->UpdateAll(texture, level);
}

void Rendering::RendererManager
	::UpdateAll( TextureCubeConstPtr texture, int face, int level )
{
	 SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->UpdateAll(texture, face,level);
}

 
 