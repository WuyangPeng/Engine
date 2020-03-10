// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 10:25)

#include "Rendering/RenderingExport.h"

#include "RendererData.h"
#include "RendererInputData.h"
#include "Detail/RendererDataImpl.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
using std::make_shared;

SINGLETON_MUTEX_DEFINE(Rendering,RendererData);

#define MUTEX_ENTER_GLOBAL CoreTools::ScopedMutex holder{ g_RenderingMutex }

#define MUTEX_ENTER_MEMBER CoreTools::ScopedMutex holder{ *sm_RendererDataMutex }

SINGLETON_INITIALIZE_DEFINE(Rendering,RendererData)

Rendering::RendererData
	::RendererData()
	:m_Impl{ make_shared<ImplType>() }
{
	MUTEX_ENTER_MEMBER;

	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::RendererData
	::~RendererData()
{
	MUTEX_ENTER_MEMBER;

	RENDERING_SELF_CLASS_IS_VALID_1;	
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::RendererData
	::IsValid() const noexcept
{
	MUTEX_ENTER_MEMBER;

	if(m_Impl != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void Rendering::RendererData
	::LoadConfiguration(const string& fileName)
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_Impl->LoadConfiguration(fileName);
    CAMERA_MANAGE_SINGLETON.SetDefaultDepthType(m_Impl->GetRendererType());
    RENDERER_INPUT_DATA_SINGLETON.Rebuild(m_Impl->GetRendererType());
}

void Rendering::RendererData
	::ClearColor()
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->ClearColor();
}

void Rendering::RendererData
	::Resize(int width,int height)
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Resize(width,height);
}

void Rendering::RendererData
	::DrawMessage( int x,int y, const Colour& color,const std::string& message)
{	
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->DrawMessage(x,y,color, message);
}

Rendering::TextureFormat Rendering::RendererData
	::GetColorFormat() const
{
	MUTEX_ENTER_MEMBER;

	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetColorFormat();
}

Rendering::TextureFormat Rendering::RendererData
	::GetDepthStencilFormat() const
{
	MUTEX_ENTER_MEMBER;

	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetDepthStencilFormat();
}

int Rendering::RendererData
	::GetNumMultisamples() const
{
	MUTEX_ENTER_MEMBER;

	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetNumMultisamples();
}

Rendering::RendererData::Colour Rendering::RendererData
	::GetClearColor() const
{
	MUTEX_ENTER_MEMBER;

	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetClearColor();
}

const std::string Rendering::RendererData
	::GetWindowTitle() const
{
	MUTEX_ENTER_MEMBER;

	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetWindowTitle();
}

int Rendering::RendererData
	::GetXPosition() const
{
	MUTEX_ENTER_MEMBER;

	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetXPosition();
}

int Rendering::RendererData
	::GetYPosition() const
{
	MUTEX_ENTER_MEMBER;

	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetYPosition();
}

int Rendering::RendererData
	::GetWidth() const
{
	MUTEX_ENTER_MEMBER;

	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetWidth();
}

int Rendering::RendererData
	::GetHeight() const
{
	MUTEX_ENTER_MEMBER;

	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetHeight();
}

bool Rendering::RendererData
	::IsAllowResize() const
{
	MUTEX_ENTER_MEMBER;

	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->IsAllowResize();
}


