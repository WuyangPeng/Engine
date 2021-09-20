// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 12:20)

#include "MD5Testing.h"
#include "CoreTools/MemoryTools/MD5.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <array>
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"

using std::string;
using std::array;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, MD5Testing)

void CoreTools::MD5Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MD5Test);
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
void CoreTools::MD5Testing
	::MD5Test()
{
    MD5 md5{ DisableNotThrow::Disable };
	array<uint8_t, 16> digest{};

	ASSERT_EQUAL(md5.MessageDigestAlgorithm5(""), "d41d8cd98f00b204e9800998ecf8427e");
	ASSERT_EQUAL(md5.MessageDigestAlgorithm5("a"), "0cc175b9c0f1b6a831c399e269772661");
	ASSERT_EQUAL(md5.MessageDigestAlgorithm5("abc"), "900150983cd24fb0d6963f7d28e17f72");
	ASSERT_EQUAL(md5.MessageDigestAlgorithm5("message digest"), "f96b697d7cb7938d525a2f31aaf161d0");
	ASSERT_EQUAL(md5.MessageDigestAlgorithm5("abcdefghijklmnopqrstuvwxyz"), "c3fcd3d76192e4007dfb496cca67e13b");
	ASSERT_EQUAL(md5.MessageDigestAlgorithm5("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"), "f29939a25efabaef3b87e2cbfe641315");
	ASSERT_EQUAL(md5.MessageDigestAlgorithm5("8a683566bcc7801226b3d8b0cf35fd97"), "cf2cb5c89c5e5eeebef4a76becddfcfd");
	ASSERT_EQUAL(md5.MessageDigestAlgorithm5("jklmn"), "603f52d844017e83ca267751fee5b61b");

	md5.MessageDigestAlgorithm5(nullptr, 0, digest.data());
	ASSERT_EQUAL(md5.GetHexDigestWithLowercase(digest.data()), "d41d8cd98f00b204e9800998ecf8427e");

	md5.MessageDigestAlgorithm5(reinterpret_cast<const uint8_t*>("a"), 1, digest.data());
	ASSERT_EQUAL(md5.GetHexDigestWithLowercase(digest.data()), "0cc175b9c0f1b6a831c399e269772661");

	md5.MessageDigestAlgorithm5(reinterpret_cast<const uint8_t*>("abc"), 3, digest.data());
	ASSERT_EQUAL(md5.GetHexDigestWithLowercase(digest.data()), "900150983cd24fb0d6963f7d28e17f72");

	md5.MessageDigestAlgorithm5(reinterpret_cast<const uint8_t*>("message digest"), 14, digest.data());
	ASSERT_EQUAL(md5.GetHexDigestWithLowercase(digest.data()), "f96b697d7cb7938d525a2f31aaf161d0");

	md5.MessageDigestAlgorithm5(reinterpret_cast<const uint8_t*>("abcdefghijklmnopqrstuvwxyz"), 26, digest.data());
	ASSERT_EQUAL(md5.GetHexDigestWithLowercase(digest.data()), "c3fcd3d76192e4007dfb496cca67e13b");

	md5.MessageDigestAlgorithm5(reinterpret_cast<const uint8_t*>("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"), 52, digest.data());
	ASSERT_EQUAL(md5.GetHexDigestWithUppercase(digest.data()), "F29939A25EFABAEF3B87E2CBFE641315");

	md5.MessageDigestAlgorithm5(reinterpret_cast<const uint8_t*>("8a683566bcc7801226b3d8b0cf35fd97"), 32, digest.data());
	ASSERT_EQUAL(md5.GetHexDigestWithLowercase(digest.data()), "cf2cb5c89c5e5eeebef4a76becddfcfd");
}
#include STSTEM_WARNING_POP