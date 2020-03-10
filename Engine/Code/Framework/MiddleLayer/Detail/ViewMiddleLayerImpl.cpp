// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.4 (2019/08/01 13:06)

#include "Framework/FrameworkExport.h"

#include "ViewMiddleLayerImpl.h" 
#include "Rendering/Renderers/Renderer.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"

using std::string;

Framework::ViewMiddleLayerImpl
	::ViewMiddleLayerImpl()
	:m_Renderer()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
} 
 
CLASS_INVARIANT_STUB_DEFINE(Framework, ViewMiddleLayerImpl)

void Framework::ViewMiddleLayerImpl
	::Resize(int width, int height)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_Renderer.IsValidPtr())
	{
		m_Renderer->Resize(width, height);
	}
}

void Framework::ViewMiddleLayerImpl
	::DrawFrameRate(int x, int y, const Colour& color, const string& message)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_Renderer.IsValidPtr())
	{
		m_Renderer->DrawMessage(x,y, color, message);
	} 
}

void Framework::ViewMiddleLayerImpl
	::ResetRenderer(const string& fileName)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_Renderer.Reset(NEW0 Renderer(fileName));
}

void Framework::ViewMiddleLayerImpl
	::ClearColorBuffer()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_Renderer.IsValidPtr())
	{
		m_Renderer->ClearColorBuffer();
	}
}

const Framework::ViewMiddleLayerImpl::RendererSmartPointer Framework::ViewMiddleLayerImpl
	::GetRenderer()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return m_Renderer;
}

const Framework::ViewMiddleLayerImpl::ConstRendererSmartPointer Framework::ViewMiddleLayerImpl
	::GetConstRenderer() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Renderer;
}

const Framework::ViewMiddleLayerImpl::Colour Framework::ViewMiddleLayerImpl
	::GetClearColor() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	if (m_Renderer.IsValidPtr())
	{
		return m_Renderer->GetClearColor();
	}
	else
	{
		return Colour();
	}
}

