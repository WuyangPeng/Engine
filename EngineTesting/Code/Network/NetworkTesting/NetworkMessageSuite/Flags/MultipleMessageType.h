// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 11:40)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MULTIPLE_MESSAGE_TYPE_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MULTIPLE_MESSAGE_TYPE_H 

namespace Network
{
	enum class MultipleMessageField
	{
		Int8 = 0,
		UInt8,
		Int16,
		UInt16,
		Int32,
		UInt32,
		Int64,
		UInt64,
		String,

		Count,
	};
}

#endif // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MULTIPLE_MESSAGE_TYPE_H