// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 13:09)

#include "Framework/FrameworkExport.h"

#include "ViewMiddleLayer.h"
#include "Detail/ViewMiddleLayerImpl.h" 
#include "ModelMiddleLayer.h" 
#include "MiddleLayerInterfaceDetail.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/FileManager/Environment.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowCreate/WindowPoint.h"
 
using std::string;

Framework::ViewMiddleLayer
	::ViewMiddleLayer()
	:ParentType{},m_Impl(new ImplType)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::ViewMiddleLayer
	::~ViewMiddleLayer()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Framework, ViewMiddleLayer)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, ViewMiddleLayer, GetRenderer, const Rendering::RendererSmartPointer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, ViewMiddleLayer, GetConstRenderer, const Rendering::ConstRendererSmartPointer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, ViewMiddleLayer, GetClearColor, const Framework::ViewMiddleLayer::Colour);

bool Framework::ViewMiddleLayer
	::PreCreate()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if(ParentType::PreCreate())
	{
		System::String rendererFileName = ENVIRONMENT_SINGLETON.GetConfigurationPath() + SYSTEM_TEXT("Renderer.json");

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

 	if(ParentType::Initialize())
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

void Framework::ViewMiddleLayer
	::PreIdle()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::PreIdle();
}

void Framework::ViewMiddleLayer
	::Terminate()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::Terminate();
}

bool Framework::ViewMiddleLayer
	::Paint()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Paint())
	{
		ModelMiddleLayerSmartPointer modelMiddleLayer = GetSmartPointer<ModelMiddleLayerSmartPointer>(this, &ClassType::GetModelMiddleLayer);

		if (modelMiddleLayer.IsValidPtr())
		{
			modelMiddleLayer->UpdateFrameCount();
		}

		return true;
	}		
	else
	{
		return false;
	}		
}

bool Framework::ViewMiddleLayer
	::Create()
{	
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if(ParentType::Create())
		return true;
	else
		return false;
}

bool Framework::ViewMiddleLayer
	::Destroy()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if(ParentType::Destroy())
		return true;
	else
		return false;
}

bool Framework::ViewMiddleLayer
	::Idle( int64_t timeDelta )
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Idle(timeDelta))
		return true;			
	else	
		return false;			
}

bool Framework::ViewMiddleLayer
	::Resize( WindowDisplayFlags type, const WindowSize& size )
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	 
 	if(ParentType::Resize(type,size))
	{
		m_Impl->Resize(size.GetWindowWidth(),size.GetWindowHeight());

		return true;
	}
	else
	{
		return false;
	}
}

void Framework::ViewMiddleLayer
	::DrawFrameRate( const WindowPoint& point,  const Colour& color)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ConstModelMiddleLayerSmartPointer modelMiddleLayer = GetConstSmartPointer<ConstModelMiddleLayerSmartPointer>(this, &ClassType::GetConstModelMiddleLayer);
  
	if(modelMiddleLayer.IsValidPtr())
	{
		string frameRateMessage = modelMiddleLayer->GetFrameRateMessage();

		m_Impl->DrawFrameRate(point.GetWindowX(), point.GetWindowY(), color, frameRateMessage);
	}                          
}

 

