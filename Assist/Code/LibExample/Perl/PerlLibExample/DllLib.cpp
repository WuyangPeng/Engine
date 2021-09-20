// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/01 11:14)

#include "LibExample/Perl/PerlLibExample/PerlLibExampleExport.h"

#include "LibExample/Perl/PerlLibExample/PerlLibExample.h" 

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_PERL_LIB_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_PERL_LIB_EXAMPLE_STATIC

	namespace PerlLibExample
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_PERL_LIB_EXAMPLE_STATIC
