// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/01 10:22)

#include "LibExample/MysqlConnectorCpp/MysqlConnectorCppLibExample/MysqlConnectorCppLibExampleExport.h"

#include "LibExample/MysqlConnectorCpp/MysqlConnectorCppLibExample/MysqlConnectorCppLibExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_MYSQL_CONNECTOR_CPP_LIB_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(MysqlConnectorCppLibExample);

#else // !BUILDING_MYSQL_CONNECTOR_CPP_LIB_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(MysqlConnectorCppLibExample);

#endif // !BUILDING_MYSQL_CONNECTOR_CPP_LIB_EXAMPLE_STATIC
