// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 10:35)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_LITERAL_CAST_H
#define CORE_TOOLS_TEMPLATE_TOOLS_LITERAL_CAST_H 

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	template<typename T, int64_t V>
	class LiteralCast
	{
	public:
		using ClassType = LiteralCast<T, V>;

	private:
		static void Constranints();

	public:
		~LiteralCast();

		CLASS_INVARIANT_DECLARE;

		operator T () const;
	};

	template<int64_t V>
	class LiteralCast<uint64_t, V>
	{
	public:
		using ClassType = LiteralCast<uint64_t, V>;

	private:
		CLASS_INVARIANT_DECLARE;

	public:
		operator uint64_t () const;
	};

	template<int64_t V>
	class LiteralCast<int64_t, V>
	{
	public:
		using ClassType = LiteralCast<int64_t, V>;

	private:
		CLASS_INVARIANT_DECLARE;

	public:
		operator int64_t () const;
	};
}

#endif //  CORE_TOOLS_TEMPLATE_TOOLS_LITERAL_CAST_H

