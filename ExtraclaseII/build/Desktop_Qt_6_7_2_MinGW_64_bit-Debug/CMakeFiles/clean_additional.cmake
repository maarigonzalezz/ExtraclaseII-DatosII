# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ExtraclaseII_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ExtraclaseII_autogen.dir\\ParseCache.txt"
  "ExtraclaseII_autogen"
  )
endif()
