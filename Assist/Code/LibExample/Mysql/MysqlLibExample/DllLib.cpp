// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/01 1:54)

#include "LibExample/Mysql/MysqlLibExample/MysqlLibExampleExport.h"

#include "LibExample/Mysql/MysqlLibExample/MysqlLibExample.h" 

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_MYSQL_LIB_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_MYSQL_LIB_EXAMPLE_STATIC

	namespace MysqlLibExample
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_MYSQL_LIB_EXAMPLE_STATIC
