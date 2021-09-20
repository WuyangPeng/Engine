// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 17:15)

#ifndef CORE_TOOLS_HANDLE_MANAGER_SUITE_RESOURCE_HANDLE_TEST_DATA_H
#define CORE_TOOLS_HANDLE_MANAGER_SUITE_RESOURCE_HANDLE_TEST_DATA_H

#include "CoreTools/Helper/UserMacro.h"

#include <string>

namespace CoreTools
{
	class HandleManagerTestData
	{
	public:
		using ClassType = HandleManagerTestData;

	public:
		explicit HandleManagerTestData(const std::string& name);

		CLASS_INVARIANT_DECLARE;

		void Reset() noexcept;
		void Reset(const std::string& name);

	private:
		std::string m_Name;
	};
}

#endif // CORE_TOOLS_HANDLE_MANAGER_SUITE_RESOURCE_HANDLE_TEST_DATA_H