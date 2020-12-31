// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:56)

#include "Framework/FrameworkExport.h"

#include "RenderingManagerInterface.h"
#include "Flags/RenderingMiddleLayerFlags.h"
#include "Detail/ViewMiddleLayerImpl.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"

using std::make_shared;
 
Framework::RenderingManagerInterface
	::RenderingManagerInterface(MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }, m_Impl{ make_shared<ImplType>(System::EnumCastUnderlying(RenderingMiddleLayer::Count)) },
	 m_ViewMiddleLayer{ make_shared<ViewMiddleLayerImpl>() }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
} 

#ifdef OPEN_CLASS_INVARIANT
bool Framework::RenderingManagerInterface
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && m_Impl != nullptr && m_ViewMiddleLayer != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT
 
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Rendering, System)

bool Framework::RenderingManagerInterface
	::PreCreate(const EnvironmentDirectory& environmentDirectory)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::PreCreate(environmentDirectory))
	{
		auto rendererFileName = environmentDirectory.GetDirectory(UpperDirectory::Configuration) + SYSTEM_TEXT("Renderer.json");

		m_ViewMiddleLayer->ResetRenderer(CoreTools::StringConversion::StandardConversionMultiByte(rendererFileName));

		return true;
	}		
	else
	{
		return false;
	}		
}

bool Framework::RenderingManagerInterface
	::Initialize() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Initialize())
	{
		m_ViewMiddleLayer->ClearColorBuffer();

		return true;
	}		
	else
	{
		return false;
	}		
}

bool Framework::RenderingManagerInterface
	::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Resize(windowDisplay, size))
	{
		m_ViewMiddleLayer->Resize(size.GetWindowWidth(), size.GetWindowHeight());

		return true;
	}
	else
	{
		return false;
	}
}

bool Framework::RenderingManagerInterface
	::KeyUp(int key, const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::KeyUp(key, point);
}

bool Framework::RenderingManagerInterface
	::KeyDown(int key, const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::KeyDown(key, point);
}

bool Framework::RenderingManagerInterface
	::SpecialKeyUp(int key, const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::SpecialKeyUp(key, point);
}

bool Framework::RenderingManagerInterface
	::SpecialKeyDown(int key, const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::SpecialKeyDown(key, point);
}

bool Framework::RenderingManagerInterface
	::PassiveMotion(const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::PassiveMotion(point);
}

bool Framework::RenderingManagerInterface
	::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::Motion(point, virtualKeys);
}

bool Framework::RenderingManagerInterface
	::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::MouseWheel(delta, point, virtualKeys);
}

bool Framework::RenderingManagerInterface
	::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::MouseClick(button, state, point, virtualKeys);
}

const Rendering::RendererSharedPtr Framework::RenderingManagerInterface
	::GetRenderer() noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_ViewMiddleLayer->GetRenderer();
}

const Rendering::ConstRendererSharedPtr Framework::RenderingManagerInterface
	::GetRenderer() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_ViewMiddleLayer->GetRenderer();
}

