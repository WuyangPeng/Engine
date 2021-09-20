// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 15:28)

#ifndef CORE_TOOLS_TESTING_BUFFERIO_TESTING_H
#define CORE_TOOLS_TESTING_BUFFERIO_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

#include <vector>

namespace CoreTools
{
	class BufferIOTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(BufferIOTesting);

	private:
		void MainTest();
		void ReadBufferIOTest();
		void WriteBufferIOTest();

		void ReadBufferIOBasisTest() noexcept; 
		void ReadBufferIOReadTest() noexcept;
		void WriteBufferIOBasisTest();
		void WriteBufferIOWriteTest();

		void DoRunUnitTest() override;

	private:
		using CharVector = std::vector<char>;

	private:
		CharVector m_Buffer;
	};
}

#endif // CORE_TOOLS_TESTING_BUFFERIO_TESTING_H