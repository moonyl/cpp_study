## 한 곳으로 모으기
config.hpp 같은 단일 헤더에서 “감지”만 하고, 나머지 코드에선 MY_COMPILER_MSVC, MY_ARCH_X64 같은 내부 매크로만 쓰자. 유지보수가 쉬워진다.
