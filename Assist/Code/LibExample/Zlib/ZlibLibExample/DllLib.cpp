// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/02 15:09)

#include "LibExample/Zlib/ZlibLibExample/ZlibLibExampleExport.h"

#include "LibExample/Zlib/ZlibLibExample/ZlibLibExample.h" 

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_ZLIB_LIB_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_ZLIB_LIB_EXAMPLE_STATIC

	namespace ZlibLibExample
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_ZLIB_LIB_EXAMPLE_STATIC
