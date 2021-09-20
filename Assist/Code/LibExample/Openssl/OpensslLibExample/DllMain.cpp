// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/01 0:02)

#include "LibExample/Openssl/OpensslLibExample/OpensslLibExampleExport.h"

#include "LibExample/Openssl/OpensslLibExample/OpensslLibExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_OPENSSL_LIB_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(OpensslLibExample);

#else // !BUILDING_OPENSSL_LIB_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(OpensslLibExample);

#endif // !BUILDING_OPENSSL_LIB_EXAMPLE_STATIC
