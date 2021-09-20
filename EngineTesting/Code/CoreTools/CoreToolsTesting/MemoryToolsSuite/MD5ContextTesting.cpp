// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 12:20)

#include "MD5ContextTesting.h"
#include "CoreTools/MemoryTools/MD5.h"
#include "CoreTools/MemoryTools/MD5Context.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <array>
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"

using std::array;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, MD5ContextTesting)

void CoreTools::MD5ContextTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MD5Test);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
void CoreTools::MD5ContextTesting
	::MD5Test()
{
    MD5Context context{ DisableNotThrow::Disable };
	array<uint8_t, 16> digest{};

	context.MD5Init();

	context.MD5Update(reinterpret_cast<const uint8_t*>("a"), 1);

	context.MD5Final(digest.data());

	ASSERT_EQUAL(MD5::GetHexDigestWithLowercase(digest.data()), "0cc175b9c0f1b6a831c399e269772661");

	context.MD5Init();

	context.MD5Update(reinterpret_cast<const uint8_t*>("a"), 1);
	context.MD5Update(reinterpret_cast<const uint8_t*>("bc"), 2);

	context.MD5Final(digest.data());

	ASSERT_EQUAL(MD5::GetHexDigestWithLowercase(digest.data()), "900150983cd24fb0d6963f7d28e17f72");

	context.MD5Init();

	context.MD5Update(reinterpret_cast<const uint8_t*>("message"), 7);
	context.MD5Update(reinterpret_cast<const uint8_t*>(" "), 1);
	context.MD5Update(reinterpret_cast<const uint8_t*>("digest"), 6);

	context.MD5Final(digest.data());

	ASSERT_EQUAL(MD5::GetHexDigestWithLowercase(digest.data()), "f96b697d7cb7938d525a2f31aaf161d0");

	context.MD5Init();

	context.MD5Update(reinterpret_cast<const uint8_t*>("abcdefghijklmnopqrstuvwxyz"), 26);

	context.MD5Final(digest.data());

	ASSERT_EQUAL(MD5::GetHexDigestWithLowercase(digest.data()), "c3fcd3d76192e4007dfb496cca67e13b");

	context.MD5Init();

	context.MD5Update(reinterpret_cast<const uint8_t*>("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), 26);
	context.MD5Update(reinterpret_cast<const uint8_t*>("abcdefghijklmnopqrstuvwxyz"), 26);

	context.MD5Final(digest.data());

	ASSERT_EQUAL(MD5::GetHexDigestWithLowercase(digest.data()), "f29939a25efabaef3b87e2cbfe641315");
}
#include STSTEM_WARNING_POP