// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.4 (2019/08/01 13:08)

#include "Framework/FrameworkExport.h"

#include "ModelMiddleLayer.h" 
#include "Detail/ModelMiddleLayerImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "System/Helper/UnusedMacro.h"

using std::string;

Framework::ModelMiddleLayer
	::ModelMiddleLayer()
	:ParentType{}, m_Impl(new ImplType)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::ModelMiddleLayer
	::~ModelMiddleLayer()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Framework,ModelMiddleLayer) 

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, ModelMiddleLayer, ResetTime, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, ModelMiddleLayer, GetFrameRateMessage, string)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, ModelMiddleLayer, MeasureTime, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, ModelMiddleLayer, UpdateFrameCount, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, ModelMiddleLayer, GetFrameRate, double)

bool Framework::ModelMiddleLayer
	::PreCreate()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if(ParentType::PreCreate())
		return true;
	else
		return false;
}

bool Framework::ModelMiddleLayer
	::Initialize()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if(ParentType::Initialize())
		return true;
	else
		return false;
}

void Framework::ModelMiddleLayer
	::PreIdle()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::PreIdle();
}

void Framework::ModelMiddleLayer
	::Terminate()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::Terminate();
}

bool Framework::ModelMiddleLayer
	::Create()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if(ParentType::Create())
		return true;
	else
		return false;
}

bool Framework::ModelMiddleLayer
	::Destroy()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if(ParentType::Destroy())
		return true;
	else
		return false;
}

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

