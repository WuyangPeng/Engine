// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Resource/Protobuf/Proto/Player.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Resource_2fProtobuf_2fProto_2fPlayer_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Resource_2fProtobuf_2fProto_2fPlayer_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Resource_2fProtobuf_2fProto_2fPlayer_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Resource_2fProtobuf_2fProto_2fPlayer_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Resource_2fProtobuf_2fProto_2fPlayer_2eproto;
namespace Player {
class PlayerRequest;
struct PlayerRequestDefaultTypeInternal;
extern PlayerRequestDefaultTypeInternal _PlayerRequest_default_instance_;
class PlayerResponse;
struct PlayerResponseDefaultTypeInternal;
extern PlayerResponseDefaultTypeInternal _PlayerResponse_default_instance_;
}  // namespace Player
PROTOBUF_NAMESPACE_OPEN
template<> ::Player::PlayerRequest* Arena::CreateMaybeMessage<::Player::PlayerRequest>(Arena*);
template<> ::Player::PlayerResponse* Arena::CreateMaybeMessage<::Player::PlayerResponse>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace Player {

// ===================================================================

class PlayerRequest final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Player.PlayerRequest) */ {
 public:
  inline PlayerRequest() : PlayerRequest(nullptr) {}
  ~PlayerRequest() override;
  explicit PROTOBUF_CONSTEXPR PlayerRequest(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  PlayerRequest(const PlayerRequest& from);
  PlayerRequest(PlayerRequest&& from) noexcept
    : PlayerRequest() {
    *this = ::std::move(from);
  }

  inline PlayerRequest& operator=(const PlayerRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline PlayerRequest& operator=(PlayerRequest&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const PlayerRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const PlayerRequest* internal_default_instance() {
    return reinterpret_cast<const PlayerRequest*>(
               &_PlayerRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(PlayerRequest& a, PlayerRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(PlayerRequest* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PlayerRequest* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  PlayerRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<PlayerRequest>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const PlayerRequest& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const PlayerRequest& from) {
    PlayerRequest::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(PlayerRequest* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Player.PlayerRequest";
  }
  protected:
  explicit PlayerRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kUserIdFieldNumber = 1,
  };
  // int32 user_id = 1;
  void clear_user_id();
  int32_t user_id() const;
  void set_user_id(int32_t value);
  private:
  int32_t _internal_user_id() const;
  void _internal_set_user_id(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:Player.PlayerRequest)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    int32_t user_id_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_Resource_2fProtobuf_2fProto_2fPlayer_2eproto;
};
// -------------------------------------------------------------------

class PlayerResponse final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Player.PlayerResponse) */ {
 public:
  inline PlayerResponse() : PlayerResponse(nullptr) {}
  ~PlayerResponse() override;
  explicit PROTOBUF_CONSTEXPR PlayerResponse(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  PlayerResponse(const PlayerResponse& from);
  PlayerResponse(PlayerResponse&& from) noexcept
    : PlayerResponse() {
    *this = ::std::move(from);
  }

  inline PlayerResponse& operator=(const PlayerResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline PlayerResponse& operator=(PlayerResponse&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const PlayerResponse& default_instance() {
    return *internal_default_instance();
  }
  static inline const PlayerResponse* internal_default_instance() {
    return reinterpret_cast<const PlayerResponse*>(
               &_PlayerResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(PlayerResponse& a, PlayerResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(PlayerResponse* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PlayerResponse* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  PlayerResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<PlayerResponse>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const PlayerResponse& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const PlayerResponse& from) {
    PlayerResponse::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(PlayerResponse* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Player.PlayerResponse";
  }
  protected:
  explicit PlayerResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kUserIdFieldNumber = 1,
  };
  // int32 user_id = 1;
  void clear_user_id();
  int32_t user_id() const;
  void set_user_id(int32_t value);
  private:
  int32_t _internal_user_id() const;
  void _internal_set_user_id(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:Player.PlayerResponse)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    int32_t user_id_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_Resource_2fProtobuf_2fProto_2fPlayer_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// PlayerRequest

// int32 user_id = 1;
inline void PlayerRequest::clear_user_id() {
  _impl_.user_id_ = 0;
}
inline int32_t PlayerRequest::_internal_user_id() const {
  return _impl_.user_id_;
}
inline int32_t PlayerRequest::user_id() const {
  // @@protoc_insertion_point(field_get:Player.PlayerRequest.user_id)
  return _internal_user_id();
}
inline void PlayerRequest::_internal_set_user_id(int32_t value) {
  
  _impl_.user_id_ = value;
}
inline void PlayerRequest::set_user_id(int32_t value) {
  _internal_set_user_id(value);
  // @@protoc_insertion_point(field_set:Player.PlayerRequest.user_id)
}

// -------------------------------------------------------------------

// PlayerResponse

// int32 user_id = 1;
inline void PlayerResponse::clear_user_id() {
  _impl_.user_id_ = 0;
}
inline int32_t PlayerResponse::_internal_user_id() const {
  return _impl_.user_id_;
}
inline int32_t PlayerResponse::user_id() const {
  // @@protoc_insertion_point(field_get:Player.PlayerResponse.user_id)
  return _internal_user_id();
}
inline void PlayerResponse::_internal_set_user_id(int32_t value) {
  
  _impl_.user_id_ = value;
}
inline void PlayerResponse::set_user_id(int32_t value) {
  _internal_set_user_id(value);
  // @@protoc_insertion_point(field_set:Player.PlayerResponse.user_id)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Player

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Resource_2fProtobuf_2fProto_2fPlayer_2eproto
