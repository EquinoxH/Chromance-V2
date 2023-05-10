cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(chromance C CXX ASM)
set(CMAKE_C STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(chromance
chromance.h
    chromance.cpp
    colours.h
    colours.cpp
    debugTools.h
    debugTools.cpp
    hub.h
    hub.cpp
    main.h
    main.cpp
    myNetwork.cpp
    myNetwork.h
    myRandom.h
    myRandom.cpp
    neopixel.h
    neopixel.cpp
    profileIncludes.h
    profileManager.h
    profileManager.cpp
    utils.h
    utils.cpp

    shapes/dot/dot.h
    shapes/dot/dot.cpp
    shapes/segment/segment.h
    shapes/segment/segment.cpp
    shapes/trail/trail.h
    shapes/trail/trail.cpp
    shapes/slowTrail/slowTrail.h
    shapes/slowTrail/slowTrail.cpp
    shapes/doubleTrail/doubleTrail.h
    shapes/doubleTrail/doubleTrail.cpp

    profiles/aurora/aurora.h
    profiles/aurora/aurora.cpp
    profiles/blossom/blossom.h
    profiles/blossom/blossom.cpp
    profiles/clouds/clouds.h
    profiles/clouds/clouds.cpp
    profiles/embers/embers.h
    profiles/embers/embers.cpp
    profiles/fastRGB/fastRGB.h
    profiles/fastRGB/fastRGB.cpp
    profiles/fireflies/fireflies.h
    profiles/fireflies/fireflies.cpp
    profiles/fireworks/fireworks.h
    profiles/fireworks/fireworks.cpp
    profiles/flower/flower.h
    profiles/flower/flower.cpp
    profiles/heart/heart.h
    profiles/heart/heart.cpp
    profiles/meteor/meteor.h
    profiles/meteor/meteor.cpp
    profiles/meteorStorm/meteorStorm.h
    profiles/meteorStorm/meteorStorm.cpp
    profiles/pulse/pulse.h
    profiles/pulse/pulse.cpp
    profiles/purpleRain/purpleRain.h
    profiles/purpleRain/purpleRain.cpp
    profiles/rainbow/rainbow.h
    profiles/rainbow/rainbow.cpp
    profiles/rainfall/rainfall.h
    profiles/rainfall/rainfall.cpp
    profiles/rgb/rgb.h
    profiles/rgb/rgb.cpp
    profiles/snowfall/snowfall.h
    profiles/snowfall/snowfall.cpp

    profiles/shapeTest/shapeTest.h
    profiles/shapeTest/shapeTest.cpp
)
pico_enable_stdio_usb(chromance 1)
pico_enable_stdio_uart(chromance 0)
pico_add_extra_outputs(chromance)
target_include_directories(chromance PRIVATE ${CMAKE_CURRENT_LIST_DIR} )
target_link_libraries(chromance pico_cyw43_arch_lwip_threadsafe_background pico_stdlib)
