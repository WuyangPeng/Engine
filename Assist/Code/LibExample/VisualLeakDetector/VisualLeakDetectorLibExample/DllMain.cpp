// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/02 14:28)

#include "LibExample/VisualLeakDetector/VisualLeakDetectorLibExample/VisualLeakDetectorLibExampleExport.h"

#include "LibExample/VisualLeakDetector/VisualLeakDetectorLibExample/VisualLeakDetectorLibExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_VISUAL_LEAK_DETECTOR_LIB_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(VisualLeakDetectorLibExample);

#else // !BUILDING_VISUAL_LEAK_DETECTOR_LIB_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(VisualLeakDetectorLibExample);

#endif // !BUILDING_VISUAL_LEAK_DETECTOR_LIB_EXAMPLE_STATIC
