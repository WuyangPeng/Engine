// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 09:37)

#ifndef FRAMEWORK_WINDOW_CREATE_WINDOW_INSTANCE_PARAMETER_IMPL_H
#define FRAMEWORK_WINDOW_CREATE_WINDOW_INSTANCE_PARAMETER_IMPL_H

#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"

#include <string>

namespace Framework
{
	class WindowInstanceParameterImpl
	{
	public:
		using ClassType = WindowInstanceParameterImpl;
        using HInstance = System::WindowHInstance;

	public:
		WindowInstanceParameterImpl(HInstance hInstance,const System::String& className);		
		
		CLASS_INVARIANT_DECLARE;	

		HInstance GetHInstance() const;
		System::String GetWindowClassName() const;

	private:	
		HInstance m_HInstance;		
		System::String m_ClassName;	
	};
}

#endif // FRAMEWORK_WINDOW_CREATE_WINDOW_INSTANCE_PARAMETER_IMPL_H