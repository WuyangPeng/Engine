// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/20 16:40)

#ifndef CORE_TOOLS_MEMORY_TOOLS_BUFER_STREAM_H
#define CORE_TOOLS_MEMORY_TOOLS_BUFER_STREAM_H

// һ��Buffer���ڴ��ͨ�ÿ顣�����ǲ���ʹ�ã����Ƿ��ص�BufferPool��
// Buffer�������γ��������洢��������ݣ��⽫��һ����һ��Buffer���ʡ�
// BufferStream����в�����ֻ��һ����һ��Buffer�������ϵ�Buffer��

#include "CoreTools/CoreToolsDll.h"

#include "MemoryToolsFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(BufferStreamImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE BufferStream : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(BufferStream);

	public:
		// ��ֹʹ�ó�BufferPool��ķ�ʽ����BufferStreamShare
		explicit BufferStream(BufferPool* pool);
		BufferStream(BufferPool* pool, int minSize);

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
		IMPL_TYPE_DECLARE(BufferStream);
	};
}

#endif // CORE_TOOLS_MEMORY_TOOLS_BUFER_STREAM_H