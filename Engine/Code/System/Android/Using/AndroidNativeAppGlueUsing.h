// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2019/12/31 15:25)

#ifndef SYSTEM_ANDROID_ANDROID_NATIVE_APPGLUE_TYPEDEF_H
#define SYSTEM_ANDROID_ANDROID_NATIVE_APPGLUE_TYPEDEF_H

#include "System/SystemDll.h"

#ifdef SYSTEM_PLATFORM_ANDROID

namespace System
{
	using AndroidNativeActivity = ANativeActivity;
	using AndroidConfiguration = AConfiguration;
	using AndroidApp = android_app;
	using AndroidPollSource = android_poll_source;
}

#else // !SYSTEM_PLATFORM_ANDROID

#include "AndroidNativeWindowUsing.h"
#include "System/Window/Using/WindowUsing.h"  

#include <memory>

namespace System
{
	class SYSTEM_DEFAULT_DECLARE AndroidNativeActivity
	{

	};

	class SYSTEM_DEFAULT_DECLARE AndroidConfiguration
	{

	};

	struct AndroidApp;
	struct AndroidInputEvent;
	struct AndroidLooper;
	struct AndroidInputQueue;
	struct AndroidNativeWindow;

	struct SYSTEM_DEFAULT_DECLARE AndroidPollSource
	{
	public:
		using ClassType = AndroidPollSource;

	public:
		AndroidPollSource() noexcept;

		void process(struct AndroidApp* androidApp, struct AndroidPollSource* source) noexcept;

	private:
		int id;
		AndroidApp* app;
	};

	template class SYSTEM_DEFAULT_DECLARE std::shared_ptr<AndroidInputQueue>;
	template class SYSTEM_DEFAULT_DECLARE std::shared_ptr<AndroidNativeWindow>;

	struct SYSTEM_DEFAULT_DECLARE AndroidApp
	{
	public:
		using ClassType = AndroidApp;

	public:
		AndroidApp(); 

		AndroidApp(const AndroidApp&) = delete;
		AndroidApp& operator = (const AndroidApp&) = delete;

		using AppCmd = void(*)(struct AndroidApp* app, int cmd);
		using InputEvent = int(*)(struct AndroidApp* app, AndroidInputEvent* event);

		void SetDestroyRequested(int isDestroyRequested) noexcept;
		int GetDestroyRequested() const noexcept;	

		System::WindowHWnd GetRunning() const noexcept;
		void SetRunning(System::WindowHWnd val) noexcept;

		void OnAppCmd(struct AndroidApp* app, int cmd) noexcept;
		void OnInputEvent(struct AndroidApp* app, AndroidInputEvent* event) noexcept;

		void SetOnAppCmd(System::AndroidApp::AppCmd value) noexcept;
		void SetOnInputEvent(System::AndroidApp::InputEvent value) noexcept;

		AndroidNativeWindow* GetAndroidNativeWindow() noexcept
		{
			return window.get();
		}

	private:
		void* userData;
		AndroidNativeActivity* activity;
		AndroidConfiguration* config;
		void* savedState;
		size_t savedStateSize;
		AndroidLooper* looper;  
	public:
		AndroidRect contentRect;
		int activityState;	
		int destroyRequested; 
		int msgread;
		int msgwrite;
		AndroidPollSource cmdPollSource;
		AndroidPollSource inputPollSource;	
	private:
		WindowHWnd running;
	public:
		int stateSaved;
		int destroyed;
		int redrawNeeded;
	private:
		AndroidInputQueue* pendingInputQueue;
		AndroidNativeWindow* pendingWindow;
		AppCmd onAppCmd;
		InputEvent onInputEvent;	
		AndroidRect pendingContentRect;		
		std::shared_ptr<AndroidInputQueue> inputQueue;
		std::shared_ptr<AndroidNativeWindow> window;		
	};
}

#endif // SYSTEM_PLATFORM_ANDROID

#endif // SYSTEM_ANDROID_ANDROID_NATIVE_APPGLUE_TYPEDEF_H
