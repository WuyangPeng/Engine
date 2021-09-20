// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/01 11:14)

#include "LibExample/Perl/PerlLibExample/PerlLibExampleExport.h"

#include "LibExample/Perl/PerlLibExample/PerlLibExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_PERL_LIB_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(PerlLibExample);

#else // !BUILDING_PERL_LIB_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(PerlLibExample);

#endif // !BUILDING_PERL_LIB_EXAMPLE_STATIC
