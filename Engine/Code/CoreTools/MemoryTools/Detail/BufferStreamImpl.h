// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/20 16:39)

#ifndef CORE_TOOLS_MEMORY_TOOLS_BUFER_STREAM_IMPL_H
#define CORE_TOOLS_MEMORY_TOOLS_BUFER_STREAM_IMPL_H

// һ��Buffer���ڴ��ͨ�ÿ顣�����ǲ���ʹ�ã����Ƿ��ص�BufferPool��
// Buffer�������γ��������洢��������ݣ��⽫��һ����һ��Buffer���ʡ�
// BufferStreamShareImpl����в�����ֻ��һ����һ��Buffer�������ϵ�Buffer��

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
		// ��ֹʹ�ó�BufferPool��ķ�ʽ����BufferStreamImpl
		explicit BufferStreamImpl(BufferPool* pool);
		BufferStreamImpl(BufferPool* pool, int minSize);
		~BufferStreamImpl() noexcept;

		BufferStreamImpl(const BufferStreamImpl&) = delete;
		BufferStreamImpl& operator=(const BufferStreamImpl&) = delete;
		BufferStreamImpl(BufferStreamImpl&&) noexcept = delete;
		BufferStreamImpl& operator=(BufferStreamImpl&&) noexcept = delete;

		CLASS_INVARIANT_DECLARE;

		// ��������
		void ResetData();

		int GetOriginalMemoryLength() const noexcept;

		void Append(int minSize);
		void SetDataLength(int newLength);
		void AddDataLength(int length);
		int GetDataLength() const noexcept;
		int GetTotalMemoryLength() const noexcept;
		int GetRemainDataLength() const noexcept;

		// д����
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

		// ������
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

		// ������ʵ���ݵĿ�ʼλ�úͳ���
		int m_StartDataPosition;
		int m_DataLength;

		// ��λ��
		int m_ReadPosition;
		// �ɶ�ȡ���ֽ�
		int m_ReadLength;

		int m_TotalMemoryLength;
	};
}

#endif // CORE_TOOLS_MEMORY_TOOLS_BUFER_STREAM_IMPL_H