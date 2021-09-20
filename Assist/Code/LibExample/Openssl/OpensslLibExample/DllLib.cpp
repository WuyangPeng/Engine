// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/01 0:02)

#include "LibExample/Openssl/OpensslLibExample/OpensslLibExampleExport.h"

#include "LibExample/Openssl/OpensslLibExample/OpensslLibExample.h" 

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_OPENSSL_LIB_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_OPENSSL_LIB_EXAMPLE_STATIC

	namespace OpensslLibExample
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_OPENSSL_LIB_EXAMPLE_STATIC
