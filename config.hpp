#pragma once

// 컴파일러
#if defined(_MSC_VER)
  #define MY_COMPILER_MSVC 1
#elif defined(__clang__)
  #define MY_COMPILER_CLANG 1
#elif defined(__GNUG__)
  #define MY_COMPILER_GCC 1
#else
  #define MY_COMPILER_UNKNOWN 1
#endif

// 아키텍처
#if defined(_M_X64) || defined(__amd64__)
  #define MY_ARCH_X64 1
#elif defined(_M_IX86) || defined(__i386__)
  #define MY_ARCH_X86 1
#elif defined(_M_ARM) || defined(__arm__)
  #define MY_ARCH_ARM 1
#else
  #define MY_ARCH_UNKNOWN 1
#endif

// 표준 버전
#if __cplusplus >= 202002L
  #define MY_CPP20_OR_LATER 1
#elif __cplusplus >= 201703L
  #define MY_CPP17 1
#else
  #define MY_CPP_OLDER 1
#endif

// 구성(툴체인 통일)
#if defined(_DEBUG) || defined(DEBUG)
  #define MY_DEBUG 1
#else
  #define MY_RELEASE 1
#endif


// 안전한 검사 도우미
#if !defined(HAS_INCLUDE)
  #if defined(__has_include)
    #define HAS_INCLUDE(header) __has_include(header)
  #else
    #define HAS_INCLUDE(header) 0
  #endif
#endif

#if !defined(HAS_ATTR)
  #if defined(__has_cpp_attribute)
    #define HAS_ATTR(x) __has_cpp_attribute(x)
  #else
    #define HAS_ATTR(x) 0
  #endif
#endif

// 속성 래퍼 (예: deprecated)
#if HAS_ATTR(deprecated)
  #define ATTR_DEPRECATED(msg) [[deprecated(msg)]]
#else
  #define ATTR_DEPRECATED(msg)
#endif

// 기능 테스트 매크로 기반 래퍼 (예: consteval 폴백)
#ifdef __cpp_consteval
  #define MY_CONSTEVAL consteval
#else
  #define MY_CONSTEVAL constexpr
#endif

// 표준 라이브러리 헤더 가용성 따라 분기(예: optional)
#if HAS_INCLUDE(<version>)
  #include <version>   // __cpp_lib_xxx 매크로를 쓰려면 가능하면 포함
#endif

#if HAS_INCLUDE(<optional>)
  #include <optional>
  template<class T> using optional_t = std::optional<T>;
#else
  #include "myoptional.h"
  template<class T> using optional_t = my::optional<T>;
#endif
