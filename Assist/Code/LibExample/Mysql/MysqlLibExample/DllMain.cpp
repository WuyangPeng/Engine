// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/01 1:54)

#include "LibExample/Mysql/MysqlLibExample/MysqlLibExampleExport.h"

#include "LibExample/Mysql/MysqlLibExample/MysqlLibExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_MYSQL_LIB_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(MysqlLibExample);

#else // !BUILDING_MYSQL_LIB_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(MysqlLibExample);

#endif // !BUILDING_MYSQL_LIB_EXAMPLE_STATIC
