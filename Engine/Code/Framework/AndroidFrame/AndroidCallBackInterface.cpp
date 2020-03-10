// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:25)

#include "Framework/FrameworkExport.h"

#include "AndroidCallBackInterface.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/Application/ApplicationTrait.h"
#include "System/Helper/UnusedMacro.h"

Framework::AndroidCallBackInterface
	::AndroidCallBackInterface()
	:m_State(nullptr)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::AndroidCallBackInterface
	::~AndroidCallBackInterface()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework,AndroidCallBackInterface)

bool Framework::AndroidCallBackInterface
	::PreCreate()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return true;
}

bool Framework::AndroidCallBackInterface
	::Initialize()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return true;
}

void Framework::AndroidCallBackInterface
	::PreIdle()
{
	FRAMEWORK_CLASS_IS_VALID_9;
}

void Framework::AndroidCallBackInterface
	::Terminate()
{
	FRAMEWORK_CLASS_IS_VALID_9;
}

unsigned char Framework::AndroidCallBackInterface
	::GetTerminateKey() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return static_cast<unsigned char>
		   (AndroidApplicationTrait::KeyIdentifiers::sm_KeyTerminate);
}

void Framework::AndroidCallBackInterface
	::InitMessage( struct AndroidApp* state )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_State = state;
}

void Framework::AndroidCallBackInterface
	::ResizedMessage( struct AndroidApp* state )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(state);
}

void Framework::AndroidCallBackInterface
	::TermMessage( struct AndroidApp* state )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(state);
}

void Framework::AndroidCallBackInterface
	::RedrawNeededMessage( struct AndroidApp* state )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(state);
}

void Framework::AndroidCallBackInterface
	::Display( struct AndroidApp* state ,int64_t timeDelta )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(state);
	SYSTEM_UNUSED_ARG(timeDelta);
}

void Framework::AndroidCallBackInterface
	::NotDealCmdMessage( struct AndroidApp* state )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(state);
}

int Framework::AndroidCallBackInterface
	::NotDealInputMessage(struct AndroidApp* state,
	                      AndroidInputEvent* event)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(state);
	SYSTEM_UNUSED_ARG(event);

	return 0;
}

void Framework::AndroidCallBackInterface
	::RectChanged( struct AndroidApp* state )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(state);
}

int Framework::AndroidCallBackInterface
	::KeyDownMessage( struct AndroidApp* state, AndroidInputEvent* event )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(state);
	SYSTEM_UNUSED_ARG(event);

	return 0;
}

int Framework::AndroidCallBackInterface
	::KeyUpMessage( struct AndroidApp* state, AndroidInputEvent* event )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(state);
	SYSTEM_UNUSED_ARG(event);

	return 0;
}

int Framework::AndroidCallBackInterface
	::ActionDownMessage( struct AndroidApp* state, AndroidInputEvent* event )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(state);
	SYSTEM_UNUSED_ARG(event);

	return 0;
}

int Framework::AndroidCallBackInterface
	::ActionUpMessage( struct AndroidApp* state, AndroidInputEvent* event )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(state);
	SYSTEM_UNUSED_ARG(event);

	return 0;
}

int Framework::AndroidCallBackInterface
	::ActionMoveMessage( struct AndroidApp* state, AndroidInputEvent* event )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(state);
	SYSTEM_UNUSED_ARG(event);

	return 0;
}

System::AndroidApp* Framework::AndroidCallBackInterface
	::GetAndroidApp()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return m_State;
}






