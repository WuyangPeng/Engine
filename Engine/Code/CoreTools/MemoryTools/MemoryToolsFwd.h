// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 16:38)

#ifndef CORE_TOOLS_MEMORY_TOOLS_FWD_H
#define CORE_TOOLS_MEMORY_TOOLS_FWD_H

namespace CoreTools
{
	enum class MD5ContextStatus;

	template <typename T>
	class HeapAllocate;

	class DefaultMemory;
	class MemoryManager;
	class Memory;
	class SmartPointerManager;

	template <typename T>
	class SmartPointerSingle;

	template <typename T>
	class SmartPointer1DArray;

	template <typename T>
	class SmartPointer2DArray;

	template <typename T>
	class SmartPointer3DArray;

	template <typename T>
	class SmartPointer4DArray;

	class MD5Context;
	class MD5;

	class Random;

	template<class T>
	class Pool;

	class BufferPool;

	class Buffer;
	class BufferStream;

	template <typename SubClass>
	struct SubclassSmartPointerTraits;

	template <typename BaseClass>
	class ConstFirstSubclassSmartPointer;

	template <typename BaseClass>
	class FirstSubclassSmartPointer;

	template <typename SubClass, typename BaseClass>
	class ConstSecondSubclassSmartPointer;

	template <typename SubClass, typename BaseClass>
	class SecondSubclassSmartPointer;

	template <typename SubClass, typename BaseClass>
	class ConstThirdSubclassSmartPointer;

	template <typename SubClass, typename BaseClass>
	class ThirdSubclassSmartPointer;

	template <typename SubClass, typename BaseClass>
	class ConstFourthSubclassSmartPointer;

	template <typename SubClass, typename BaseClass>
	class FourthSubclassSmartPointer;

	template <typename SubClass, typename BaseClass>
	class ConstFifthSubclassSmartPointer;

	template <typename SubClass, typename BaseClass>
	class FifthSubclassSmartPointer;

	template <typename SubClass, typename BaseClass>
	class ConstSixthSubclassSmartPointer;

	template <typename SubClass, typename BaseClass>
	class SixthSubclassSmartPointer;

	template <typename SubClass, typename BaseClass>
	class ConstSeventhSubclassSmartPointer;

	template <typename SubClass, typename BaseClass>
	class SeventhSubclassSmartPointer;

	template <typename SubClass, typename BaseClass>
	class ConstEighthSubclassSmartPointer;

	template <typename SubClass, typename BaseClass>
	class EighthSubclassSmartPointer;

	template <typename SubClass, typename BaseClass>
	class ConstNinthSubclassSmartPointer;

	template <typename SubClass, typename BaseClass>
	class NinthSubclassSmartPointer;

	template <typename SubClass, typename BaseClass>
	class ConstTenthSubclassSmartPointer;

	template <typename SubClass, typename BaseClass>
	class TenthSubclassSmartPointer;

	template <typename SubclassSmartPointer>
	class SubclassWeakPointer;
}

#endif // CORE_TOOLS_MEMORY_TOOLS_FWD_H