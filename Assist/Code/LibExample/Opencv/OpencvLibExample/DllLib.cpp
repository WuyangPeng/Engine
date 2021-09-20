// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/02 13:56)

#include "LibExample/Opencv/OpencvLibExample/OpencvLibExampleExport.h"

#include "LibExample/Opencv/OpencvLibExample/OpencvLibExample.h" 

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_OPENCV_LIB_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_OPENCV_LIB_EXAMPLE_STATIC

	namespace OpencvLibExample
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_OPENCV_LIB_EXAMPLE_STATIC
