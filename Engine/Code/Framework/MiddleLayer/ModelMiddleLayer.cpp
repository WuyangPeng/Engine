// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:55)

#include "Framework/FrameworkExport.h"

#include "ModelMiddleLayer.h" 
#include "Detail/ModelMiddleLayerImpl.h"
#include "Flags/MiddleLayerPlatformFlags.h" 
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::move;
using std::string;
using std::make_shared;

namespace Framework
{
	constexpr auto g_DefaultMaxTimer = 30;
}

Framework::ModelMiddleLayer
	::ModelMiddleLayer(MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }, m_Impl{ make_shared<ImplType>(g_DefaultMaxTimer) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::ModelMiddleLayer
	::ModelMiddleLayer(ModelMiddleLayer&& rhs) noexcept
	:ParentType{ move(rhs) }, m_Impl{ move(rhs.m_Impl) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::ModelMiddleLayer& Framework::ModelMiddleLayer
	::operator=(ModelMiddleLayer&& rhs) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::operator=(move(rhs));

	m_Impl = move(rhs.m_Impl);

	return *this;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Framework, ModelMiddleLayer)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, ModelMiddleLayer, GetFrameRate, double)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, ModelMiddleLayer, GetFrameRateMessage, string)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, ModelMiddleLayer, ResetTime, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, ModelMiddleLayer, MeasureTime, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, ModelMiddleLayer, UpdateFrameCount, void)

bool Framework::ModelMiddleLayer
	::Idle(int64_t timeDelta)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Idle(timeDelta))
	{
		m_Impl->MeasureTime();

		return true;
	}
	else
	{
		return false;
	}
}

bool Framework::ModelMiddleLayer
	::Paint()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::Paint();
}

bool Framework::ModelMiddleLayer
	::Move(const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::Move(point);
}

bool Framework::ModelMiddleLayer
	::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::Resize(windowDisplay,size);
}

bool Framework::ModelMiddleLayer
	::KeyUp(int key, const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::KeyUp(key, point);
}

bool Framework::ModelMiddleLayer
	::KeyDown(int key, const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::KeyDown(key, point);
}

bool Framework::ModelMiddleLayer
	::SpecialKeyUp(int key, const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::SpecialKeyUp(key, point);
}

bool Framework::ModelMiddleLayer
	::SpecialKeyDown(int key, const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::SpecialKeyDown(key, point);
}

bool Framework::ModelMiddleLayer
	::PassiveMotion(const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::PassiveMotion(point);
}

bool Framework::ModelMiddleLayer
	::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::Motion(point, virtualKeys);
}

bool Framework::ModelMiddleLayer
	::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::MouseWheel(delta, point, virtualKeys);
}

bool Framework::ModelMiddleLayer
	::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::MouseClick(button, state, point, virtualKeys);
}

