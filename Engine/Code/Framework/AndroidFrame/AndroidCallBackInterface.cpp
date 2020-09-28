// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:41)

#include "Framework/FrameworkExport.h"

#include "AndroidCallBackInterface.h"

#include "CoreTools/ClassInvariant/NoexceptDetail.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/Application/Flags/ApplicationTrait.h"

Framework::AndroidCallBackInterface
	::AndroidCallBackInterface(int64_t delta) noexcept
	:m_State{ nullptr }, m_Delta{ delta }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, AndroidCallBackInterface) 

bool Framework::AndroidCallBackInterface
	::PreCreate()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	CoreTools::DoNothing();

	return true;
}

bool Framework::AndroidCallBackInterface
	::Initialize()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	CoreTools::DoNothing();

	return true;
}

void Framework::AndroidCallBackInterface
	::PreIdle()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	CoreTools::DoNothing();
}

void Framework::AndroidCallBackInterface
	::Terminate()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	CoreTools::DoNothing();
}

int Framework::AndroidCallBackInterface
	::GetTerminateKey() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return AndroidApplicationTrait::KeyIdentifiers::sm_KeyTerminate;
}

void Framework::AndroidCallBackInterface
	::InitMessage(AndroidApp* androidApp)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	CoreTools::DoNothing();

	m_State = androidApp;
}

void Framework::AndroidCallBackInterface ::ResizedMessage([[maybe_unused]] AndroidApp* androidApp)
{
	FRAMEWORK_CLASS_IS_VALID_9;

 

	CoreTools::DoNothing();
}

void Framework::AndroidCallBackInterface ::TermMessage([[maybe_unused]] AndroidApp* androidApp)
{
	FRAMEWORK_CLASS_IS_VALID_9;
 

	CoreTools::DoNothing();
}

void Framework::AndroidCallBackInterface ::RedrawNeededMessage([[maybe_unused]] AndroidApp* androidApp)
{
	FRAMEWORK_CLASS_IS_VALID_9;

 

	CoreTools::DoNothing();
}

void Framework::AndroidCallBackInterface ::Display([[maybe_unused]] AndroidApp* androidApp, [[maybe_unused]] int64_t timeDelta)
{
	FRAMEWORK_CLASS_IS_VALID_9;

 

	CoreTools::DoNothing();
}

void Framework::AndroidCallBackInterface ::NotDealCmdMessage([[maybe_unused]] AndroidApp* androidApp)
{
	FRAMEWORK_CLASS_IS_VALID_9;

 

	CoreTools::DoNothing();
}

int Framework::AndroidCallBackInterface ::NotDealInputMessage([[maybe_unused]] AndroidApp* androidApp, [[maybe_unused]] AndroidInputEvent* androidInputEvent)
{
	FRAMEWORK_CLASS_IS_VALID_9;

 

	CoreTools::DoNothing();

	return 0;
}

void Framework::AndroidCallBackInterface ::RectChanged([[maybe_unused]] AndroidApp* androidApp)
{
	FRAMEWORK_CLASS_IS_VALID_9;

 

	CoreTools::DoNothing();
}

int Framework::AndroidCallBackInterface ::KeyDownMessage([[maybe_unused]] AndroidApp* androidApp, [[maybe_unused]] AndroidInputEvent* androidInputEvent)
{
	FRAMEWORK_CLASS_IS_VALID_9;
 

	CoreTools::DoNothing();

	return 0;
}

int Framework::AndroidCallBackInterface ::KeyUpMessage([[maybe_unused]] AndroidApp* androidApp, [[maybe_unused]] AndroidInputEvent* androidInputEvent)
{
	FRAMEWORK_CLASS_IS_VALID_9;

 
 

	CoreTools::DoNothing();

	return 0;
}

int Framework::AndroidCallBackInterface ::ActionDownMessage([[maybe_unused]] AndroidApp* androidApp, [[maybe_unused]] AndroidInputEvent* androidInputEvent)
{
	FRAMEWORK_CLASS_IS_VALID_9;

 
 

	CoreTools::DoNothing();

	return 0;
}

int Framework::AndroidCallBackInterface ::ActionUpMessage([[maybe_unused]] AndroidApp* androidApp, [[maybe_unused]] AndroidInputEvent* androidInputEvent)
{
	FRAMEWORK_CLASS_IS_VALID_9;

 

	CoreTools::DoNothing();

	return 0;
}

int Framework::AndroidCallBackInterface ::ActionMoveMessage([[maybe_unused]] AndroidApp* androidApp, [[maybe_unused]] AndroidInputEvent* androidInputEvent)
{
	FRAMEWORK_CLASS_IS_VALID_9;

 

	CoreTools::DoNothing();

	return 0;
}

System::AndroidApp* Framework::AndroidCallBackInterface
	::GetAndroidApp() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return m_State;
}

int64_t Framework::AndroidCallBackInterface
	::GetDelta() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Delta;
}

 



