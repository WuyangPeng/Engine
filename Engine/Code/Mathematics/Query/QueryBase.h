// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 09:52)

#ifndef MATHEMATICS_QUERY_QUERY_H
#define MATHEMATICS_QUERY_QUERY_H

#include "Mathematics/MathematicsDll.h"

#include "Flags/QueryType.h"

namespace Mathematics
{
	class MATHEMATICS_DEFAULT_DECLARE QueryBase
	{
	public:
		using ClassType = QueryBase;

	public:
		QueryBase() noexcept;
		virtual ~QueryBase();
		
		QueryBase(const QueryBase&) = default;
		 QueryBase& operator=(const QueryBase&) = default;
		 QueryBase(QueryBase&&) = default;
		 QueryBase& operator=(QueryBase&&) = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual QueryType GetType() const = 0;
	};
}

#endif // MATHEMATICS_QUERY_QUERY_H
