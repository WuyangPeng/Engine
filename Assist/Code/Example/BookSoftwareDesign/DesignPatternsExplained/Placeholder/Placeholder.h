// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.3.0 (2020/03/24 23:25)

#ifndef DESIGN_PATTERNS_EXPLAINED_PLACEHOLDER_PLACEHOLDER_H
#define DESIGN_PATTERNS_EXPLAINED_PLACEHOLDER_PLACEHOLDER_H

#include "Example/BookSoftwareDesign/DesignPatternsExplained/DesignPatternsExplainedDll.h" 

#include "CoreTools/Helper/ExportMacro.h" 

namespace DesignPatternsExplained
{
	 class DESIGN_PATTERNS_EXPLAINED_DEFAULT_DECLARE Placeholder
	 {
	 public:
		 using ClassType = Placeholder;

	 public:
		 CLASS_INVARIANT_DECLARE;

	 public:
		 Placeholder() noexcept;	 
	 };	
}

#endif // DESIGN_PATTERNS_EXPLAINED_PLACEHOLDER_PLACEHOLDER_H
