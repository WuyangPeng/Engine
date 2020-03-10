// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 10:40)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_FWD_H
#define CORE_TOOLS_TEMPLATE_TOOLS_FWD_H

namespace CoreTools
{
	template <typename T>
	struct MustBePod;

	template <typename T>
	struct MustBePodOrVoid;

	template <typename T1, typename T2>
	struct MustBeSameSize;

	template <typename T>
	struct MustBeSubscriptable;

	template <typename T>
	struct MustBeSubscriptableAsDecayablePointer;

	template <typename Derive, typename Base>
	struct MustHaveBase;

	template<unsigned N>
	struct Factorial;

	uint32_t RecursiveFactorial(uint32_t integer) noexcept;
	uint32_t NonRecursiveFactorial(uint32_t integer) noexcept;

	template<unsigned N>
	struct Fibonacci;

	uint32_t RecursiveFibonacci(uint32_t integer) noexcept;
	uint32_t NonRecursiveFibonacci(uint32_t integer) noexcept;

	template <class T>
	struct ParamType;

	template<double& Radian, int MaxTerms>
	struct RecursiveSine;

	template <double& Radian>
	struct NonrecursiveSine;

	template <double& Radian>
	struct NonrecursiveCosine;

	template <double& Radian>
	struct NonrecursiveTangent;

	namespace TrigonometricFunction
	{
		double SineSeries(double radian, int index, int maxTerms) noexcept;
		double RecursiveSine(double radian) noexcept;
		double NonRecursiveSine(double radian) noexcept;
	}

	template <class T>
	class PtrLess;

	template <class T>
	class PtrGreater;

	template<bool Constant, typename Lhs, typename Rhs>
	class IfThenElse;

	template <int N, int Low, int High>
	class SqrtFirstAlgorithm;

	template <int N, int Low, int High>
	class SqrtSecondAlgorithm;

	template <int N, int I>
	class SqrtThirdAlgorithm;

	template <int N, int I>
	class SqrtFourthAlgorithm;

	template<int N>
	class Pow3;

	template <typename T>
	class ExplicitCast;

	template <typename T>
	class SimpleIncrementer;

	template <typename T>
	class SimpleDecrementer;

	template< typename T, typename Aquire, typename Release>
	class IncrementScope;

	template<typename T>
	T* GetAddress(T& t) noexcept;

	template< typename T, int64_t V>
	class LiteralCast;

	template <typename T>
	class ReferenceCast;

	template <typename T>
	class ValueScope;

	template<typename T0, typename T1, typename T2>
	struct Tiny;

	struct TinyNone;
	struct TinyTag;

	template<typename Tiny, typename Pos>
	struct TinyIterator;

	template<typename T, int N>
	struct TinyAt;

	template<typename T0, typename T1, typename T2>
	struct TinySize;

	template<typename TinyType, typename T, int N>
	struct TinyPushBack;

	template<typename T>
	struct CheckNotFull;

	template<typename T>
	struct CheckNotEmpty;

	template<typename TinyType, typename T, int N>
	struct TinyInsert;

	template<typename T0, typename T1, typename T2>
	struct TinyPopFront;

	template<typename T0, typename T1, typename T2>
	struct TinyPopBack;

	template<typename TinyType, int N>
	struct TinyErase;

	template<typename Tiny, typename Pos>
	struct TinyHasItem;

	template<typename Tiny, int F, int L>
	struct TinyEraseRange;
}

#endif // CORE_TOOLS_TEMPLATE_TOOLS_FWD_H