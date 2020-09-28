// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.1.1.0 (2020/05/02 13:36)

#include "CoreTools/CoreToolsExport.h"

#include "DirectoryImpl.h" 
#include "System/Window/WindowSystem.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h" 

#include <array>

using std::array;

CoreTools::DirectoryImpl
	::DirectoryImpl(const String& directoryName)
	:m_DirectoryName{ }
{
	array<System::TChar, System::g_MaxPath> systemCurrentDirectory{ };
	const auto result = System::GetSystemCurrentDirectory(System::g_MaxPath, systemCurrentDirectory.data());
	if (0 < result && directoryName != systemCurrentDirectory.data())
	{
		m_DirectoryName = systemCurrentDirectory.data();
            [[maybe_unused]] const auto result2 = System::SetSystemCurrentDirectory(directoryName.c_str());
	}
}

CoreTools::DirectoryImpl
	::~DirectoryImpl()
{
	if (!m_DirectoryName.empty())
	{
            [[maybe_unused]] const auto result2 = System::SetSystemCurrentDirectory(m_DirectoryName.c_str());
	}
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::DirectoryImpl
	::IsValid() const noexcept
{
	 
		return true;
 
}
#endif // OPEN_CLASS_INVARIANT
 