// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 10:38)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_NAME_IMPL_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_NAME_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE WindowNameImpl
	{
	public:
		using ClassType = WindowNameImpl;

	public:
		explicit WindowNameImpl(const System::String& className,const System::String& menuName);		

		CLASS_INVARIANT_DECLARE;

		const System::String& GetWindowClassName() const;
		const System::String& GetWindowMenuName() const;		

	private:
		System::String m_ClassName;
		System::String m_MenuName;		
	};
}

#endif // FRAMEWORK_WINDOW_REGISTER_WINDOW_NAME_IMPL_H