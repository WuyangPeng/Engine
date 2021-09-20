// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/09/30 10:36)

#include "LibExample/Boost/BoostLibExample/BoostLibExampleExport.h"

#include "LibExample/Boost/BoostLibExample/BoostLibExample.h" 

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_BOOST_LIB_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_BOOST_LIB_EXAMPLE_STATIC

	namespace BoostLibExample
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_BOOST_LIB_EXAMPLE_STATIC
