// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/20 16:39)

#ifndef CORE_TOOLS_MEMORY_TOOLS_BUFER_STREAM_IMPL_H
#define CORE_TOOLS_MEMORY_TOOLS_BUFER_STREAM_IMPL_H

// 一个Buffer是内存的通用块。当它们不再使用，他们返回到BufferPool。
// Buffer还可以形成链表来存储更多的数据，这将比一个单一的Buffer合适。
// BufferStreamShareImpl类具有操作上只是一个单一的Buffer或链表上的Buffer。

#include "CoreTools/CoreToolsDll.h"
#include "CoreTools/MemoryTools/MemoryToolsFwd.h"

#include <boost/noncopyable.hpp>
#include <vector>
#include <string>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE BufferStreamImpl : private boost::noncopyable
	{
	public:
		using ClassType = BufferStreamImpl;

	public:
		// 禁止使用除BufferPool外的方式创建BufferStreamImpl
		explicit BufferStreamImpl(BufferPool* pool);
		BufferStreamImpl(BufferPool* pool, int minSize);
		~BufferStreamImpl() noexcept;

		BufferStreamImpl(const BufferStreamImpl&) = delete;
		BufferStreamImpl& operator=(const BufferStreamImpl&) = delete;
		BufferStreamImpl(BufferStreamImpl&&) noexcept = delete;
		BufferStreamImpl& operator=(BufferStreamImpl&&) noexcept = delete;

		CLASS_INVARIANT_DECLARE;

		// 基本操作
		void ResetData();

		int GetOriginalMemoryLength() const noexcept;

		void Append(int minSize);
		void SetDataLength(int newLength);
		void AddDataLength(int length);
		int GetDataLength() const noexcept;
		int GetTotalMemoryLength() const noexcept;
		int GetRemainDataLength() const noexcept;

		// 写数据
		void AdvanceDataStartPosition(int length);

		void Set(int index, uint32_t data);
		void Set(int index, int32_t data);
		void Set(int index, uint16_t data);
		void Set(int index, int16_t data);
		void Set(int index, uint8_t data);
		void Set(int index, int8_t data);
		void Set(int index, bool data);
		void Set(int index, const uint8_t* buffer, int bufferLength);

		void Add(uint32_t data);
		void Add(int32_t data);
		void Add(uint16_t data);
		void Add(int16_t data);
		void Add(uint8_t data);
		void Add(int8_t data);
		void Add(bool data);
		void AddString(const std::string& data);
		void AddTerminatedString(const std::string& data);
		void Add(const uint8_t* buffer, int bufferLength);

		// 读数据
		void InitRead() noexcept;
		void InitRead(int totalLength);

		int GetReadableLength() const noexcept;
		int GetReadPosition() const noexcept;

		void SetReadPosition(int position);

		uint32_t ReadUInt32();
		int32_t ReadInt32();
		uint16_t ReadUInt16();
		int16_t ReadInt16();
		uint8_t ReadUInt8();
		int8_t ReadInt8();
		bool ReadBool();

		void Read(uint8_t* buffer, int bufferLength);

		uint32_t PeekUInt32();
		int32_t PeekInt32();
		uint16_t PeekUInt16();
		int16_t PeekInt16();
		uint8_t PeekUInt8();
		int8_t PeekInt8();
		bool PeekBool();

		void Peek(uint8_t* buffer, int bufferLength);

	private:
		void Release();
		void AppendBuffer(int minSize);
		void DoAppendBuffer(int minSize);
		void DoAppendBuffer(int minSize, int appendTime);
		void ExceedAppend();
		int DoSet(Buffer* ptr, int position, const uint8_t* buffer, int copyBufferLength);
		int DoPeek(const Buffer* ptr, int position, uint8_t* buffer, int copyBufferLength);

	private:
		using BufferContainer = std::vector<Buffer*>;

	private:
		BufferPool* m_Pool;
		int m_OriginalMemoryLength;
		BufferContainer m_Buffer;

		// 跟踪真实数据的开始位置和长度
		int m_StartDataPosition;
		int m_DataLength;

		// 读位置
		int m_ReadPosition;
		// 可读取的字节
		int m_ReadLength;

		int m_TotalMemoryLength;
	};
}

#endif // CORE_TOOLS_MEMORY_TOOLS_BUFER_STREAM_IMPL_H