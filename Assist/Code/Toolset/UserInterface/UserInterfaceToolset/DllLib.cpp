// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/08 21:34)

#include "Toolset/UserInterface/UserInterfaceToolset/UserInterfaceToolsetExport.h"

#include "Toolset/UserInterface/UserInterfaceToolset/UserInterfaceToolset.h"

#include "CoreTools/CoreToolsLib.h"
#include "UserInterface/UserInterfaceLib.h"

#ifndef BUILDING_USER_INTERFACE_STATIC

	#include "DllLib.h"

#else // BUILDING_USER_INTERFACE_STATIC

	namespace UserInterfaceToolset
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_USER_INTERFACE_STATIC
