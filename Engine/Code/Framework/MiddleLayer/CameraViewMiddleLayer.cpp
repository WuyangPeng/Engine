// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.3.0.1 (2020/05/21 14:54)

#include "Framework/FrameworkExport.h"

#include "CameraViewMiddleLayer.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Rendering/Renderers/Renderer.h"
#include "Framework/WindowCreate/WindowSize.h"

using std::min;
using std::move;
using namespace std::literals;

Framework::CameraViewMiddleLayer
	::CameraViewMiddleLayer(MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }, m_Multiplier{ 0.0f }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}
 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, CameraViewMiddleLayer)

void Framework::CameraViewMiddleLayer
	::SetCamera(const CameraSmartPointer& camera)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	auto renderer = GetRenderer();

	if (renderer)
	{
		renderer->SetCamera(camera);
	}
}

const Framework::WindowSize Framework::CameraViewMiddleLayer
	::GetWindowSize() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	auto renderer = GetRenderer();

	if (renderer)
	{
		const auto width = renderer->GetWidth();
		const auto height = renderer->GetHeight();

		return WindowSize{ width, height };
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("äÖÈ¾Æ÷²»´æÔÚ£¡"s));
	}
}

bool Framework::CameraViewMiddleLayer
	::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	if (ParentType::Resize(windowDisplay, size))
	{
		const auto width = size.GetWindowWidth();
		const auto height = size.GetWindowHeight();

		const auto minValue = min(height, width);

		if (0 < minValue)
		{
			m_Multiplier = 1.0f / minValue;
		}

		return true;
	}
	else
	{
		return false;
	}
}

float Framework::CameraViewMiddleLayer
	::GetXTrack(int x) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	auto renderer = GetRenderer();

	if (renderer != nullptr)
	{
		const auto width = renderer->GetWidth();

		return (2 * x - width) * m_Multiplier;
	}
	else
	{
		return 0.0f;
	}
}

float Framework::CameraViewMiddleLayer
	::GetYTrack(int y) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	auto renderer = GetRenderer();

	if (renderer != nullptr)
	{
		const auto height = renderer->GetHeight();

		return (2 * (height - 1 - y) - height) * m_Multiplier;
	}
	else
	{
		return 0.0f;
	}
}
