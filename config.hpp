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
