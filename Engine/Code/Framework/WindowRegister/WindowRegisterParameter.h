// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 10:44)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_PARAMETER_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_PARAMETER_H

#include "Framework/FrameworkDll.h"
 
#include "System/Window/Flags/WindowFlags.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/Window/Flags/WindowClassStyleFlags.h"

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE WindowRegisterParameter
	{
	public:
		using ClassType = WindowRegisterParameter;
		using WindowClassStyleFlags = System::WindowClassStyle;
		using HInstance = System::WindowHInstance;

	public:
		explicit WindowRegisterParameter(HInstance hInstance,  WindowClassStyleFlags styles = System::WindowClassStyle::CommonUse,
										 int windowClassExtra = 0, int windowExtra = 0);		

		CLASS_INVARIANT_DECLARE;

		HInstance GetHInstance() const;
		WindowClassStyleFlags GetStyle() const;
		int GetWindowClassExtra() const;
		int GetWindowExtra() const;		
	
	private:	
		HInstance m_HInstance;	
		WindowClassStyleFlags m_Style;		
		int m_WindowClassExtra;
		int m_WindowExtra;			
	};
}

#endif // FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_PARAMETER_H