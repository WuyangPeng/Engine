// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 14:56)

#include "Framework/FrameworkExport.h"

#include "ViewMiddleLayer.h"
#include "ModelMiddleLayer.h" 
#include "Detail/ViewMiddleLayerImpl.h" 
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  
#include "CoreTools/CharacterString/StringConversion.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"

using std::move;
using std::string;
using std::make_shared;
 #include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
Framework::ViewMiddleLayer
	::ViewMiddleLayer(MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }, m_Impl{ make_shared<ImplType>() }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}
 
Framework::ViewMiddleLayer
	::ViewMiddleLayer(ViewMiddleLayer&& rhs) noexcept
	:ParentType{ move(rhs) }, m_Impl{ move(rhs.m_Impl) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}
 
Framework::ViewMiddleLayer& Framework::ViewMiddleLayer
	::operator=(ViewMiddleLayer&& rhs) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::operator=(move(rhs));

	m_Impl = move(rhs.m_Impl);

	return *this;
}
 
CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Framework, ViewMiddleLayer)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, ViewMiddleLayer, GetRenderer, const Rendering::RendererSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, ViewMiddleLayer, GetRenderer, const Rendering::ConstRendererSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, ViewMiddleLayer, GetClearColor, const Framework::ViewMiddleLayer::Colour);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Framework, ViewMiddleLayer, SetClearColor, Colour,void) 

bool Framework::ViewMiddleLayer
	::PreCreate(const EnvironmentDirectory& environmentDirectory)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::PreCreate(environmentDirectory))
	{
		auto rendererFileName = environmentDirectory.GetDirectory(UpperDirectory::Configuration) + SYSTEM_TEXT("Renderer.json");

		m_Impl->ResetRenderer(CoreTools::StringConversion::StandardConversionMultiByte(rendererFileName));

		return true;
	}
	else
	{
		return false;
	}
}

bool Framework::ViewMiddleLayer
	::Initialize()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Initialize())
	{
		// 设备创建与平台相关的代码在EnterMessageLoop前调用Initialize。
		// 因此此时设备状态可能会修改。

		m_Impl->ClearColorBuffer();

		return true;
	}
	else
	{
		return false;
	}
}

bool Framework::ViewMiddleLayer
	::Paint()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Paint())
	{
		auto modelMiddleLayer = boost::polymorphic_pointer_cast<ModelMiddleLayer>(GetModelMiddleLayer());

		modelMiddleLayer->UpdateFrameCount();

		return true;
	}
	else
	{
		return false;
	}
}

bool Framework::ViewMiddleLayer
	::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Resize(windowDisplay, size))
	{
		m_Impl->Resize(size.GetWindowWidth(), size.GetWindowHeight());

		return true;
	}
	else
	{
		return false;
	}
}

void Framework::ViewMiddleLayer
	::DrawFrameRate(const WindowPoint& point, const Colour& color)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto modelMiddleLayer = boost::polymorphic_pointer_cast<const ModelMiddleLayer>(GetConstModelMiddleLayer());

	auto frameRateMessage = modelMiddleLayer->GetFrameRateMessage();

	m_Impl->DrawFrameRate(point.GetWindowX(), point.GetWindowY(), color, frameRateMessage);
}

bool Framework::ViewMiddleLayer
	::KeyUp(int key, const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::KeyUp(key, point);
}

bool Framework::ViewMiddleLayer
	::KeyDown(int key, const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::KeyDown(key, point);
}

bool Framework::ViewMiddleLayer
	::SpecialKeyUp(int key, const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::SpecialKeyUp(key, point);
}

bool Framework::ViewMiddleLayer
	::SpecialKeyDown(int key, const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::SpecialKeyDown(key, point);
}

bool Framework::ViewMiddleLayer
	::PassiveMotion(const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::PassiveMotion(point);
}

bool Framework::ViewMiddleLayer
	::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::Motion(point, virtualKeys);
}

bool Framework::ViewMiddleLayer
	::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::MouseWheel(delta, point, virtualKeys);
}

bool Framework::ViewMiddleLayer
	::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::MouseClick(button, state, point, virtualKeys);
}
#include STSTEM_WARNING_POP