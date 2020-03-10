// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2019/12/31 15:19)

#ifndef SYSTEM_ANDROID_ANDROID_INPUT_FLAGS_H
#define SYSTEM_ANDROID_ANDROID_INPUT_FLAGS_H

#include "System/Helper/ConfigMacro.h"

#ifdef SYSTEM_PLATFORM_ANDROID

#include <android/input.h>

namespace System
{
	enum class AndroidKeyState
	{
		UnKnown = AKEY_STATE_UNKNOWN,
		Up = AKEY_STATE_UP,
		Down = AKEY_STATE_DOWN,
		Virtual = AKEY_STATE_VIRTUAL,
	};

	enum class AndroidMeta
	{
		None = AMETA_NONE,
		AltOn = AMETA_ALT_ON,
		AltLeftOn = AMETA_ALT_LEFT_ON,
		AltRightOn = AMETA_ALT_RIGHT_ON,
		ShiftOn = AMETA_SHIFT_ON,
		ShiftLeftOn = AMETA_SHIFT_LEFT_ON,
		ShiftRightOn = AMETA_SHIFT_RIGHT_ON,
		SymOn = AMETA_SYM_ON,
		FunctionOn = AMETA_FUNCTION_ON,
		CtrlOn = AMETA_CTRL_ON,
		CtrlLeftOn = AMETA_CTRL_LEFT_ON,
		CtrlRightOn = AMETA_CTRL_RIGHT_ON,
		On = AMETA_META_ON,
		LeftOn = AMETA_META_LEFT_ON,
		RightOn = AMETA_META_RIGHT_ON,
		CapsLockOn = AMETA_CAPS_LOCK_ON,
		NumLockOn = AMETA_NUM_LOCK_ON,
		ScrollLockOn = AMETA_SCROLL_LOCK_ON,
	};

	enum class AndroidInputEventType
	{
		Key = AINPUT_EVENT_TYPE_KEY,
		Motion = AINPUT_EVENT_TYPE_MOTION
	};

	enum class AndroidKeyEventAction
	{
		Down = AKEY_EVENT_ACTION_DOWN,
		Up = AKEY_EVENT_ACTION_UP,
		Multiple = AKEY_EVENT_ACTION_MULTIPLE
	};

	enum class AndroidKeyEvent
	{
		WokeHere = AKEY_EVENT_FLAG_WOKE_HERE,
		SoftKeyboard = AKEY_EVENT_FLAG_SOFT_KEYBOARD,
		KeepTouchMode = AKEY_EVENT_FLAG_KEEP_TOUCH_MODE,
		FromSystem = AKEY_EVENT_FLAG_FROM_SYSTEM,
		EditorAction = AKEY_EVENT_FLAG_EDITOR_ACTION,
		Canceled = AKEY_EVENT_FLAG_CANCELED,
		VirtualHardKey = AKEY_EVENT_FLAG_VIRTUAL_HARD_KEY,
		LongPress = AKEY_EVENT_FLAG_LONG_PRESS,
		CanceledLongPress = AKEY_EVENT_FLAG_CANCELED_LONG_PRESS,
		Tracking = AKEY_EVENT_FLAG_TRACKING,
		Fallback = AKEY_EVENT_FLAG_FALLBACK,
	};

	enum class AndroidMotionEventAction
	{
		Mask = AMOTION_EVENT_ACTION_MASK,
		PointerIndexMask = AMOTION_EVENT_ACTION_POINTER_INDEX_MASK,
		Down = AMOTION_EVENT_ACTION_DOWN,
		Up = AMOTION_EVENT_ACTION_UP,
		Move = AMOTION_EVENT_ACTION_MOVE,
		Cancel = AMOTION_EVENT_ACTION_CANCEL,
		Outside = AMOTION_EVENT_ACTION_OUTSIDE,
		PointerDown = AMOTION_EVENT_ACTION_POINTER_DOWN,
		PointerUp = AMOTION_EVENT_ACTION_POINTER_UP,
		HoverMove = AMOTION_EVENT_ACTION_HOVER_MOVE,
		Scroll = AMOTION_EVENT_ACTION_SCROLL,
		HoverEnter = AMOTION_EVENT_ACTION_HOVER_ENTER,
		HoverExit = AMOTION_EVENT_ACTION_HOVER_EXIT,
	};

	enum class AndroidMotionEvent
	{
		WindowIsObscured = AMOTION_EVENT_FLAG_WINDOW_IS_OBSCURED,
	};

	enum class AndroidMotionEventEdge
	{
		None = AMOTION_EVENT_EDGE_FLAG_NONE,
		Top = AMOTION_EVENT_EDGE_FLAG_TOP,
		Bottom = AMOTION_EVENT_EDGE_FLAG_BOTTOM,
		Left = AMOTION_EVENT_EDGE_FLAG_LEFT,
		Right = AMOTION_EVENT_EDGE_FLAG_RIGHT
	};

	enum class AndroidMotionEventAxis
	{
		X = AMOTION_EVENT_AXIS_X,
		Y = AMOTION_EVENT_AXIS_Y,
		Pressure = AMOTION_EVENT_AXIS_PRESSURE,
		Size = AMOTION_EVENT_AXIS_SIZE,
		TouchMajor = AMOTION_EVENT_AXIS_TOUCH_MAJOR,
		TouchMinor = AMOTION_EVENT_AXIS_TOUCH_MINOR,
		ToolMajor = AMOTION_EVENT_AXIS_TOOL_MAJOR,
		ToolMinor = AMOTION_EVENT_AXIS_TOOL_MINOR,
		Orientation = AMOTION_EVENT_AXIS_ORIENTATION,
		VScroll = AMOTION_EVENT_AXIS_VSCROLL,
		HScroll = AMOTION_EVENT_AXIS_HSCROLL,
		Z = AMOTION_EVENT_AXIS_Z,
		RX = AMOTION_EVENT_AXIS_RX,
		RY = AMOTION_EVENT_AXIS_RY,
		RZ = AMOTION_EVENT_AXIS_RZ,
		HatX = AMOTION_EVENT_AXIS_HAT_X,
		HatY = AMOTION_EVENT_AXIS_HAT_Y,
		LTrigger = AMOTION_EVENT_AXIS_LTRIGGER,
		RTrigger = AMOTION_EVENT_AXIS_RTRIGGER,
		Throttle = AMOTION_EVENT_AXIS_THROTTLE,
		Rudder = AMOTION_EVENT_AXIS_RUDDER,
		Wheel = AMOTION_EVENT_AXIS_WHEEL,
		Gas = AMOTION_EVENT_AXIS_GAS,
		Brake = AMOTION_EVENT_AXIS_BRAKE,
		Distance = AMOTION_EVENT_AXIS_DISTANCE,
		Tilt = AMOTION_EVENT_AXIS_TILT,
		Generic1 = AMOTION_EVENT_AXIS_GENERIC_1,
		Generic2 = AMOTION_EVENT_AXIS_GENERIC_2,
		Generic3 = AMOTION_EVENT_AXIS_GENERIC_3,
		Generic4 = AMOTION_EVENT_AXIS_GENERIC_4,
		Generic5 = AMOTION_EVENT_AXIS_GENERIC_5,
		Generic6 = AMOTION_EVENT_AXIS_GENERIC_6,
		Generic7 = AMOTION_EVENT_AXIS_GENERIC_7,
		Generic8 = AMOTION_EVENT_AXIS_GENERIC_8,
		Generic9 = AMOTION_EVENT_AXIS_GENERIC_9,
		Generic10 = AMOTION_EVENT_AXIS_GENERIC_10,
		Generic11 = AMOTION_EVENT_AXIS_GENERIC_11,
		Generic12 = AMOTION_EVENT_AXIS_GENERIC_12,
		Generic13 = AMOTION_EVENT_AXIS_GENERIC_13,
		Generic14 = AMOTION_EVENT_AXIS_GENERIC_14,
		Generic15 = AMOTION_EVENT_AXIS_GENERIC_15,
		Generic16 = AMOTION_EVENT_AXIS_GENERIC_16,
	};

	enum class AndroidMotionEventButton
	{
		Primary = AMOTION_EVENT_BUTTON_PRIMARY,
		Secondary = AMOTION_EVENT_BUTTON_SECONDARY,
		Tertiary = AMOTION_EVENT_BUTTON_TERTIARY,
		Back = AMOTION_EVENT_BUTTON_BACK,
		Forward = AMOTION_EVENT_BUTTON_FORWARD,
	};

	enum class AndroidMotionEventTool
	{
		Unknown = AMOTION_EVENT_TOOL_TYPE_UNKNOWN,
		Finger = AMOTION_EVENT_TOOL_TYPE_FINGER,
		Stylus = AMOTION_EVENT_TOOL_TYPE_STYLUS,
		Mouse = AMOTION_EVENT_TOOL_TYPE_MOUSE,
		Eraser = AMOTION_EVENT_TOOL_TYPE_ERASER,
	};

	enum class AndroidInputSourceClass
	{
		Mask = AINPUT_SOURCE_CLASS_MASK,

		None = AINPUT_SOURCE_CLASS_NONE,
		Button = AINPUT_SOURCE_CLASS_BUTTON,
		Pointer = AINPUT_SOURCE_CLASS_POINTER,
		Navigation = AINPUT_SOURCE_CLASS_NAVIGATION,
		Position = AINPUT_SOURCE_CLASS_POSITION,
		Joystick = AINPUT_SOURCE_CLASS_JOYSTICK,
	};

	enum class AndroidInputSource : uint32_t
	{
		Unknown = AINPUT_SOURCE_UNKNOWN,

		Keyborad = AINPUT_SOURCE_KEYBOARD,
		Dpad = AINPUT_SOURCE_DPAD,
		Gamepad = AINPUT_SOURCE_GAMEPAD,
		Touchscreen = AINPUT_SOURCE_TOUCHSCREEN,
		Mouse = AINPUT_SOURCE_MOUSE,
		Stylus = AINPUT_SOURCE_STYLUS,
		Trackball = AINPUT_SOURCE_TRACKBALL,
		Touchpad = AINPUT_SOURCE_TOUCHPAD,
		Navigation = AINPUT_SOURCE_TOUCH_NAVIGATION,
		Joystick = AINPUT_SOURCE_JOYSTICK,

		Any = AINPUT_SOURCE_ANY,
	};

	enum class AndroidInputKeyboard
	{
		None = AINPUT_KEYBOARD_TYPE_NONE,
		NonAlphabetic = AINPUT_KEYBOARD_TYPE_NON_ALPHABETIC,
		Alphabetic = AINPUT_KEYBOARD_TYPE_ALPHABETIC,
	};
}

#elif defined(SYSTEM_PLATFORM_WIN32)

#include "System/EnumOperator/EnumCastDetail.h"
#include "System/Window/Flags/WindowMessagesFlags.h"
#include "System/Android/Flags/AndroidKeyCodesFlags.h"

namespace System
{
	enum class AndroidKeyState
	{
		UnKnown = -1,
		Up = 0,
		Down = 1,
		Virtual = 2,
	};

	enum class AndroidMeta
	{
		None = 0,
		AltOn = 0x02,
		AltLeftOn = 0x10,
		AltRightOn = 0x20,
		ShiftOn = 0x01,
		ShiftLeftOn = 0x40,
		ShiftRightOn = 0x80,
		SymOn = 0x04,
		FunctionOn = 0x08,
		CtrlOn = 0x1000,
		CtrlLeftOn = 0x2000,
		CtrlRightOn = 0x4000,
		On = 0x10000,
		LeftOn = 0x20000,
		RightOn = 0x40000,
		CapsLockOn = 0x100000,
		NumLockOn = 0x200000,
		ScrollLockOn = 0x400000,
	};

	enum class AndroidInputEventType
	{
		Key = 1,
		Motion = 2
	};

	enum class AndroidKeyEventAction
	{
		Down = EnumCastUnderlying(WindowMessages::KeyDown),
		Up = EnumCastUnderlying(WindowMessages::KeyUp),
		Multiple = 2
	};

	enum class AndroidKeyEvent
	{
		WokeHere = 0x1,
		SoftKeyboard = 0x2,
		KeepTouchMode = 0x4,
		FromSystem = 0x8,
		EditorAction = 0x10,
		Canceled = 0x20,
		VirtualHardKey = 0x40,
		LongPress = 0x80,
		CanceledLongPress = 0x100,
		Tracking = 0x200,
		Fallback = 0x400,
	};

	enum class AndroidMotionEventAction
	{
		Mask = 0xff,
		PointerIndexMask = 0xff00,
		Down = EnumCastUnderlying(WindowMessages::LButtonDown),
		Up = EnumCastUnderlying(WindowMessages::LButtonUp),
		Move = EnumCastUnderlying(WindowMessages::MouseMove),
		Cancel = -3,
		Outside = -4,
		PointerDown = -5,
		PointerUp = -6,
		HoverMove = -7,
		Scroll = -8,
		HoverEnter = -9,
		HoverExit = -10,
	};

	enum class AndroidMotionEvent
	{
		WindowIsObscured = 0x1,
	};

	enum class AndroidMotionEventEdge
	{
		None = 0,
		Top = 0x01,
		Bottom = 0x02,
		Left = 0x04,
		Right = 0x08
	};

	enum class AndroidMotionEventAxis
	{
		X = 0,
		Y = 1,
		Pressure = 2,
		Size = 3,
		TouchMajor = 4,
		TouchMinor = 5,
		ToolMajor = 6,
		ToolMinor = 7,
		Orientation = 8,
		VScroll = 9,
		HScroll = 10,
		Z = 11,
		RX = 12,
		RY = 13,
		RZ = 14,
		HatX = 15,
		HatY = 16,
		LTrigger = 17,
		RTrigger = 18,
		Throttle = 19,
		Rudder = 20,
		Wheel = 21,
		Gas = 22,
		Brake = 23,
		Distance = 24,
		Tilt = 25,
		Generic1 = 32,
		Generic2 = 33,
		Generic3 = 34,
		Generic4 = 35,
		Generic5 = 36,
		Generic6 = 37,
		Generic7 = 38,
		Generic8 = 39,
		Generic9 = 40,
		Generic10 = 41,
		Generic11 = 42,
		Generic12 = 43,
		Generic13 = 44,
		Generic14 = 45,
		Generic15 = 46,
		Generic16 = 47,
	};

	enum class AndroidMotionEventButton
	{
		Primary = 1 << 0,
		Secondary = 1 << 1,
		Tertiary = 1 << 2,
		Back = 1 << 3,
		Forward = 1 << 4,
	};

	enum class AndroidMotionEventTool
	{
		Unknown = 0,
		Finger = 1,
		Stylus = 2,
		Mouse = 3,
		Eraser = 4,
	};

	enum class AndroidInputSourceClass
	{
		Mask = 0x000000ff,

		None = 0x00000000,
		Button = 0x00000001,
		Pointer = 0x00000002,
		Navigation = 0x00000004,
		Position = 0x00000008,
		Joystick = 0x00000010,
	};

	enum class AndroidInputSource : uint32_t
	{
		Unknown = 0x00000000,

		Keyborad = 0x00000100 | EnumCastUnderlying(AndroidInputSourceClass::Button),
		Dpad = 0x00000200 | EnumCastUnderlying(AndroidInputSourceClass::Button),
		Gamepad = 0x00000400 | EnumCastUnderlying(AndroidInputSourceClass::Button),
		Touchscreen = 0x00001000 | EnumCastUnderlying(AndroidInputSourceClass::Pointer),
		Mouse = 0x00002000 | EnumCastUnderlying(AndroidInputSourceClass::Pointer),
		Stylus = 0x00004000 | EnumCastUnderlying(AndroidInputSourceClass::Pointer),
		Trackball = 0x00010000 | EnumCastUnderlying(AndroidInputSourceClass::Navigation),
		Touchpad = 0x00100000 | EnumCastUnderlying(AndroidInputSourceClass::Position),
		Navigation = 0x00200000 | EnumCastUnderlying(AndroidInputSourceClass::None),
		Joystick = 0x01000000 | EnumCastUnderlying(AndroidInputSourceClass::Joystick),

		Any = 0xffffff00,
	};

	enum class AndroidInputKeyboard
	{
		None = 0,
		NonAlphabetic = 1,
		Alphabetic = 2,
	};
}

#else // !SYSTEM_PLATFORM_ANDROID && !SYSTEM_PLATFORM_WIN32

#include "System/EnumOperator/EnumCastDetail.h"

namespace System
{
	enum class AndroidKeyState
	{
		UnKnown = -1,
		Up = 0,
		Down = 1,
		Virtual = 2,
	};

	enum class AndroidMeta
	{
		None = 0,
		AltOn = 0x02,
		AltLeftOn = 0x10,
		AltRightOn = 0x20,
		ShiftOn = 0x01,
		ShiftLeftOn = 0x40,
		ShiftRightOn = 0x80,
		SymOn = 0x04,
		FunctionOn = 0x08,
		CtrlOn = 0x1000,
		CtrlLeftOn = 0x2000,
		CtrlRightOn = 0x4000,
		On = 0x10000,
		LeftOn = 0x20000,
		RightOn = 0x40000,
		CapsLockOn = 0x100000,
		NumLockOn = 0x200000,
		ScrollLockOn = 0x400000,
	};

	enum class AndroidInputEventType
	{
		Key = 1,
		Motion = 2
	};

	enum class AndroidKeyEventAction
	{
		Down = 0,
		Up = 1,
		Multiple = 2
	};

	enum class AndroidKeyEvent
	{
		WokeHere = 0x1,
		SoftKeyboard = 0x2,
		KeepTouchMode = 0x4,
		FromSystem = 0x8,
		EditorAction = 0x10,
		Canceled = 0x20,
		VirtualHardKey = 0x40,
		LongPress = 0x80,
		CanceledLongPress = 0x100,
		Tracking = 0x200,
		Fallback = 0x400,
	};

	enum class AndroidMotionEventAction
	{
		Mask = 0xff,
		PointerIndexMask = 0xff00,
		Down = 0,
		Up = 1,
		Move = 2,
		Cancel = 3,
		Outside = 4,
		PointerDown = 5,
		PointerUp = 6,
		HoverMove = 7,
		Scroll = 8,
		HoverEnter = 9,
		HoverExit = 10,
	};

	enum class AndroidMotionEvent
	{
		WindowIsObscured = 0x1,
	};

	enum class AndroidMotionEventEdge
	{
		None = 0,
		Top = 0x01,
		Bottom = 0x02,
		Left = 0x04,
		Right = 0x08
	};

	enum class AndroidMotionEventAxis
	{
		X = 0,
		Y = 1,
		Pressure = 2,
		Size = 3,
		TouchMajor = 4,
		TouchMinor = 5,
		ToolMajor = 6,
		ToolMinor = 7,
		Orientation = 8,
		VScroll = 9,
		HScroll = 10,
		Z = 11,
		RX = 12,
		RY = 13,
		RZ = 14,
		HatX = 15,
		HatY = 16,
		LTrigger = 17,
		RTrigger = 18,
		Throttle = 19,
		Rudder = 20,
		Wheel = 21,
		Gas = 22,
		Brake = 23,
		Distance = 24,
		Tilt = 25,
		Generic1 = 32,
		Generic2 = 33,
		Generic3 = 34,
		Generic4 = 35,
		Generic5 = 36,
		Generic6 = 37,
		Generic7 = 38,
		Generic8 = 39,
		Generic9 = 40,
		Generic10 = 41,
		Generic11 = 42,
		Generic12 = 43,
		Generic13 = 44,
		Generic14 = 45,
		Generic15 = 46,
		Generic16 = 47,
	};

	enum class AndroidMotionEventButton
	{
		Primary = 1 << 0,
		Secondary = 1 << 1,
		Tertiary = 1 << 2,
		Back = 1 << 3,
		Forward = 1 << 4,
	};

	enum class AndroidMotionEventTool
	{
		Unknown = 0,
		Finger = 1,
		Stylus = 2,
		Mouse = 3,
		Eraser = 4,
	};

	enum class AndroidInputSourceClass
	{
		Mask = 0x000000ff,

		None = 0x00000000,
		Button = 0x00000001,
		Pointer = 0x00000002,
		Navigation = 0x00000004,
		Position = 0x00000008,
		Joystick = 0x00000010,
	};

	enum class AndroidInputSource : uint32_t
	{
		Unknown = 0x00000000,

		Keyborad = 0x00000100 | EnumCastUnderlying(AndroidInputSourceClass::Button),
		Dpad = 0x00000200 | EnumCastUnderlying(AndroidInputSourceClass::Button),
		Gamepad = 0x00000400 | EnumCastUnderlying(AndroidInputSourceClass::Button),
		Touchscreen = 0x00001000 | EnumCastUnderlying(AndroidInputSourceClass::Pointer),
		Mouse = 0x00002000 | EnumCastUnderlying(AndroidInputSourceClass::Pointer),
		Stylus = 0x00004000 | EnumCastUnderlying(AndroidInputSourceClass::Pointer),
		Trackball = 0x00010000 | EnumCastUnderlying(AndroidInputSourceClass::Navigation),
		Touchpad = 0x00100000 | EnumCastUnderlying(AndroidInputSourceClass::Position),
		Navigation = 0x00200000 | EnumCastUnderlying(AndroidInputSourceClass::None),
		Joystick = 0x01000000 | EnumCastUnderlying(AndroidInputSourceClass::Joystick),

		Any = 0xffffff00,
	};

	enum class AndroidInputKeyboard
	{
		None = 0,
		NonAlphabetic = 1,
		Alphabetic = 2,
	};
}

#endif // SYSTEM_PLATFORM_ANDROID

#endif // SYSTEM_ANDROID_ANDROID_INPUT_FLAGS_H
