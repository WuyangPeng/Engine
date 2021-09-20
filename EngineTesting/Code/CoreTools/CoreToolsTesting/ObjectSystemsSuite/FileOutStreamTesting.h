// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 13:34)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_FILE_OUT_STREAM_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_FILE_OUT_STREAM_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class FileOutStreamTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(FileOutStreamTesting);

	private:
		std::string GetTopLevelContent() const;
		std::string GetAligningString(const std::string& original) const;
		std::string GetNullObjectContent(int uniqueID, const std::string& rttiTypeName) const;

		void MainTest();
                void WriteNullObjectTest() noexcept;

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_FILE_OUT_STREAM_TESTING_H