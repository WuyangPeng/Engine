// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 19:14)

#ifndef CORE_TOOLS_STATE_MACHINE_SUITE_STATE_H
#define CORE_TOOLS_STATE_MACHINE_SUITE_STATE_H

#include <vector>
#include <ctime>

namespace CoreTools
{
	struct Play
	{
	};

	struct OpenClose
	{
	};

	struct CdDetected
	{
            CdDetected(char const*, std::vector<clock_t> const&) noexcept;
	};

	struct Pause
	{
	};

	struct Stop
	{
	};
}

#endif // CORE_TOOLS_STATE_MACHINE_SUITE_STATE_H