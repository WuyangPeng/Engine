// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.1.0.1 (2020/04/22 15:57)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_NAME_IMPL_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_NAME_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE WindowNameImpl
	{
	public:
		using ClassType = WindowNameImpl;
		using String = System::String;

	public:
		explicit WindowNameImpl(const String& className,const String& menuName);		

		CLASS_INVARIANT_DECLARE;

		const String GetWindowClassName() const;
		const String GetWindowMenuName() const;		

	private:
		String m_ClassName;
		String m_MenuName;		
	};
}

#endif // FRAMEWORK_WINDOW_REGISTER_WINDOW_NAME_IMPL_H