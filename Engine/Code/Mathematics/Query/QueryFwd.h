// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 09:42)

#ifndef MATHEMATICS_QUERY_FWD_H
#define MATHEMATICS_QUERY_FWD_H

namespace Mathematics
{
	class QuerySortTools;

	template <typename Real>
	class QueryDotTools;

	class QueryBase;

	template <typename Real>
	class Query2;

	template <typename Real>
	class Query2Integer;

	template <typename Real>
	class Query2Int64;

	template <typename Real>
	class Query2Rational;

	template <typename Real>
	class Query2Filtered;

	template <typename Real>
	class Query3;

	template <typename Real>
	class Query3Integer;

	template <typename Real>
	class Query3Int64;

	template <typename Real>
	class Query3Rational;

	template <typename Real>
	class Query3Filtered;

	enum class QueryType;
	enum class LineQueryType;
	enum class TriangleQueryType;
	enum class CircumcircleQueryType;
	enum class PlaneQueryType;
	enum class TetrahedronQueryType;
	enum class CircumsphereQueryType;
}

#endif // MATHEMATICS_QUERY_FWD_H