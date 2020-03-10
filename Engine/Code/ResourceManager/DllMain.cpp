// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/17 10:24)

#include "ResourceManager/ResourceManagerExport.h"

#include "ResourceManager/ResourceManagerFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
 
#ifndef BUILDING_RESOURCE_MANAGER_STATIC

	DLL_MAIN_FUNCTION(ResourceManager);
	
#else // !BUILDING_RESOURCE_MANAGER_STATIC

	CORE_TOOLS_MUTEX_INIT(ResourceManager);

#endif // !BUILDING_RESOURCE_MANAGER_STATIC