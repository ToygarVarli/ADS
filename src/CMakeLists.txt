set(SOURCES
  AdsDef.cpp
  AdsDevice.cpp
  AdsFile.cpp
  AdsLib.cpp
  ECatAccess.cpp
  Frame.cpp
  LicenseAccess.cpp
  Log.cpp
  RouterAccess.cpp
  RTimeAccess.cpp
  Sockets.cpp
  AdsWrapper.cpp
  RegistryAccess.cpp
  SymbolAccess.cpp

  bhf/ParameterList.cpp

  standalone/AdsLib.cpp
  standalone/AmsConnection.cpp
  standalone/AmsNetId.cpp
  standalone/AmsPort.cpp
  standalone/AmsRouter.cpp
  standalone/NotificationDispatcher.cpp
)

add_library(ads SHARED ${SOURCES})
add_library(ads::ads ALIAS ads)
add_library(adswrapper SHARED AdsWrapper.cpp)

target_include_directories(ads PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
$<INSTALL_INTERFACE:include/ads>)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_link_libraries(ads PUBLIC wsock32)
endif()


if(WIN32 EQUAL 1)
    target_link_libraries(ads PUBLIC ws2_32)
endif()

target_link_libraries(ads PUBLIC Threads::Threads)