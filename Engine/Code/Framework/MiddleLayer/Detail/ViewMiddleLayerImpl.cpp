// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:53)

#include "Framework/FrameworkExport.h"

#include "ViewMiddleLayerImpl.h" 
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 
#include "Rendering/Renderers/Renderer.h" 

using std::move;
using std::string;
using std::make_shared;
using std::const_pointer_cast;
using namespace std::literals;

Framework::ViewMiddleLayerImpl ::ViewMiddleLayerImpl(MAYBE_UNUSED int count) noexcept
    : m_Renderer{}
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::ViewMiddleLayerImpl
	::ViewMiddleLayerImpl(ViewMiddleLayerImpl&& rhs) noexcept
	:m_Renderer{ move(rhs.m_Renderer) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::ViewMiddleLayerImpl& Framework::ViewMiddleLayerImpl
	::operator=(ViewMiddleLayerImpl&& rhs) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_Renderer = move(rhs.m_Renderer);

	return *this;
}

void Framework::ViewMiddleLayerImpl
	::ResetRenderer(const string& fileName)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;

	m_Renderer = make_shared<Renderer>(fileName);
	m_Renderer->Init();
}

CLASS_INVARIANT_STUB_DEFINE(Framework, ViewMiddleLayerImpl)

void Framework::ViewMiddleLayerImpl
	::Resize(int width, int height)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_Renderer)
	{
		m_Renderer->Resize(width, height);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("‰÷»æ∆˜Œ¥≥ı ºªØ£°"s));
	}
}

void Framework::ViewMiddleLayerImpl
	::DrawFrameRate(int x, int y, const Colour& color, const string& message)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_Renderer)
	{
		if (m_Renderer->PreDraw())
		{
			m_Renderer->Draw(x, y, color, message);
			m_Renderer->PostDraw();
		}
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("‰÷»æ∆˜Œ¥≥ı ºªØ£°"s));
	}
}

void Framework::ViewMiddleLayerImpl
	::ClearColorBuffer()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_Renderer)
	{
		m_Renderer->ClearColorBuffer();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("‰÷»æ∆˜Œ¥≥ı ºªØ£°"s));
	}
}

const Framework::ViewMiddleLayerImpl::RendererSharedPtr Framework::ViewMiddleLayerImpl
	::GetRenderer() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26473)   
	return const_pointer_cast<Renderer>(static_cast<const ClassType*>(this)->GetRenderer());
#include STSTEM_WARNING_POP
}

const Framework::ViewMiddleLayerImpl::ConstRendererSharedPtr Framework::ViewMiddleLayerImpl
	::GetRenderer() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Renderer;
}

const Framework::ViewMiddleLayerImpl::Colour Framework::ViewMiddleLayerImpl
	::GetClearColor() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	if (m_Renderer)
	{
		return m_Renderer->GetClearColor();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("‰÷»æ∆˜Œ¥≥ı ºªØ£°"s));
	}
}

void Framework::ViewMiddleLayerImpl
	::SetClearColor(const Colour& colour)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_Renderer)
	{
		return m_Renderer->SetClearColor(colour);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("‰÷»æ∆˜Œ¥≥ı ºªØ£°"s));
	}
}

