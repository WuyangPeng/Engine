// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 15:32)

#include "BufferIOTesting.h"
#include "CoreTools/FileManager/ReadBufferIO.h"
#include "CoreTools/FileManager/WriteBufferIO.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <string>

using std::vector;
using std::string;
using std::ostream;
using namespace std::literals;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
namespace CoreTools
{
	const string g_BufferIOContent{ "BufferIO Testing Text"s };
}
#include STSTEM_WARNING_POP
CoreTools::BufferIOTesting
	::BufferIOTesting(const OStreamShared& osPtr)
	:ParentType{ osPtr }, m_Buffer(g_BufferIOContent.size() + sizeof(int))
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

 CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, BufferIOTesting)
void CoreTools::BufferIOTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::BufferIOTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(WriteBufferIOTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ReadBufferIOTest);
}

// WriteBufferIO≤‚ ‘
void CoreTools::BufferIOTesting
	::WriteBufferIOTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(WriteBufferIOBasisTest);
	ASSERT_NOT_THROW_EXCEPTION_0(WriteBufferIOWriteTest);
}

void CoreTools::BufferIOTesting
	::WriteBufferIOBasisTest()
{
	const auto size = boost::numeric_cast<int>(m_Buffer.size());
	WriteBufferIO writeBuffer{ size  };

 
	ASSERT_EQUAL(writeBuffer.GetBytesTotal(), size);
	ASSERT_EQUAL(writeBuffer.GetBytesProcessed(), 0);

	writeBuffer.IncrementBytesProcessed(size / 2);

 
	ASSERT_EQUAL(writeBuffer.GetBytesTotal(), size);
	ASSERT_EQUAL(writeBuffer.GetBytesProcessed(), size / 2);
}

void CoreTools::BufferIOTesting
	::WriteBufferIOWriteTest()
{
	WriteBufferIO writeBuffer{ boost::numeric_cast<int>(m_Buffer.size())  };
	const auto size = g_BufferIOContent.size();

	writeBuffer.Write(sizeof(uint32_t), &size);

	ASSERT_EQUAL(boost::numeric_cast<uint32_t>(writeBuffer.GetBytesProcessed()), sizeof(uint32_t));

	vector<char> content{ g_BufferIOContent.begin(), g_BufferIOContent.end() };

	writeBuffer.Write(sizeof(char), size, content.data());

	ASSERT_EQUAL(writeBuffer.GetBytesProcessed(), writeBuffer.GetBytesTotal());
}

// ReadBufferIO≤‚ ‘
void CoreTools::BufferIOTesting
	::ReadBufferIOTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ReadBufferIOBasisTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ReadBufferIOReadTest);
}

void CoreTools::BufferIOTesting
	::ReadBufferIOBasisTest() noexcept
{
	 
}

void CoreTools::BufferIOTesting ::ReadBufferIOReadTest() noexcept
{
	 
}









